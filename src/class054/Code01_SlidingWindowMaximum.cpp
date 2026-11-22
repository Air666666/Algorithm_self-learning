// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/sliding-window-maximum/

// Source: src/class054/Code01_SlidingWindowMaximum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SlidingWindowMaximum {
  inline static int MAXN = 100001;
  inline static Array<int> deque = make_array<int>(MAXN);
  inline static int h = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SlidingWindowMaximum() {}
  static Array<int> maxSlidingWindow(Array<int> arr, int k) {
    (h = (t = 0));
    int n = arr.length;
    for (int i = 0; (i < (k - 1)); (i++)) {
      while (((h < t) && (arr[deque[(t - 1)]] <= arr[i]))) {
        (t--);
      }
      (deque[(t++)] = i);
    }
    int m = ((n - k) + 1);
    Array<int> ans = make_array<int>(m);
    {
      int l = 0;
      int r = (k - 1);
      for (; (l < m); (l++), (r++)) {
        while (((h < t) && (arr[deque[(t - 1)]] <= arr[r]))) {
          (t--);
        }
        (deque[(t++)] = r);
        (ans[l] = arr[deque[h]]);
        if ((deque[h] == l)) {
          (h++);
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 滑动窗口最大值（单调队列经典用法模版）
// 给你一个整数数组 nums，有一个大小为 k
的滑动窗口从数组的最左侧移动到数组的最右侧
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 测试链接 : https://leetcode.cn/problems/sliding-window-maximum/
                // 先形成长度为k-1的窗口
                        // 大 -> 小
                // 当前窗口k-1长度
                        // 少一个，要让r位置的数进来
                        // 收集答案
                        // l位置的数出去
*/
