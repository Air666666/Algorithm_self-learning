// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

// Source: src/class054/Code02_LongestSubarrayAbsoluteLimit.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LongestSubarrayAbsoluteLimit {
  inline static int MAXN = 100001;
  inline static Array<int> maxDeque = make_array<int>(MAXN);
  inline static Array<int> minDeque = make_array<int>(MAXN);
  inline static int maxh = {};
  inline static int maxt = {};
  inline static int minh = {};
  inline static int mint = {};
  inline static Array<int> arr = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LongestSubarrayAbsoluteLimit() {}
  static int longestSubarray(Array<int> nums, int limit) {
    (maxh = (maxt = (minh = (mint = 0))));
    (arr = nums);
    int n = arr.length;
    int ans = 0;
    {
      int l = 0;
      int r = 0;
      for (; (l < n); (l++)) {
        while (((r < n) &&
                Code02_LongestSubarrayAbsoluteLimit::ok(limit, nums[r]))) {
          Code02_LongestSubarrayAbsoluteLimit::push((r++));
        }
        (ans = jmax(ans, (r - l)));
        Code02_LongestSubarrayAbsoluteLimit::pop(l);
      }
    }
    return ans;
  }
  static bool ok(int limit, int number) {
    int max = ((maxh < maxt) ? jmax(arr[maxDeque[maxh]], number) : number);
    int min = ((minh < mint) ? jmin(arr[minDeque[minh]], number) : number);
    return ((max - min) <= limit);
  }
  static void push(int r) {
    while (((maxh < maxt) && (arr[maxDeque[(maxt - 1)]] <= arr[r]))) {
      (maxt--);
    }
    (maxDeque[(maxt++)] = r);
    while (((minh < mint) && (arr[minDeque[(mint - 1)]] >= arr[r]))) {
      (mint--);
    }
    (minDeque[(mint++)] = r);
  }
  static void pop(int l) {
    if (((maxh < maxt) && (maxDeque[maxh] == l))) {
      (maxh++);
    }
    if (((minh < mint) && (minDeque[minh] == l))) {
      (minh++);
    }
  }
};

/* Original teaching comments:
// 绝对差不超过限制的最长连续子数组
// 给你一个整数数组 nums ，和一个表示限制的整数 limit
// 请你返回最长连续子数组的长度
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
// 如果不存在满足条件的子数组，则返回 0
// 测试链接 :
https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
        // 窗口内最大值的更新结构（单调队列）
        // 窗口内最小值的更新结构（单调队列）
                        // [l,r)，r永远是没有进入窗口的、下一个数所在的位置
                        //
从while出来的时候，[l,r)是l开头的子数组能向右延伸的最大范围
        // 判断如果加入数字number，窗口最大值 - 窗口最小值是否依然 <= limit
        // 依然 <= limit，返回true
        // 不再 <= limit，返回false
                // max : 如果number进来，新窗口的最大值
                // min : 如果number进来，新窗口的最小值
        //
r位置的数字进入窗口，修改窗口内最大值的更新结构、修改窗口内最小值的更新结构
        // 窗口要吐出l位置的数了！检查过期！
*/
