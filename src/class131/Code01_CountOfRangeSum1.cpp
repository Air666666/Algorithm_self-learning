// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/count-of-range-sum/

// Source: src/class131/Code01_CountOfRangeSum1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CountOfRangeSum1 {
  inline static int MAXN = 100001;
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> help = make_array<i64>(MAXN);
  inline static int low = {};
  inline static int up = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CountOfRangeSum1() {}
  static int countRangeSum(Array<int> nums, int lower, int upper) {
    int n = nums.length;
    (sum[0] = nums[0]);
    for (int i = 1; (i < n); (i++)) {
      (sum[i] = (sum[(i - 1)] + nums[i]));
    }
    (low = lower);
    (up = upper);
    return Code01_CountOfRangeSum1::f(0, (n - 1));
  }
  static int f(int l, int r) {
    if ((l == r)) {
      return (((low <= sum[l]) && (sum[l] <= up)) ? 1 : 0);
    }
    int m = jdiv((l + r), 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code01_CountOfRangeSum1::f(l, m);
        auto jright = Code01_CountOfRangeSum1::f((m + 1), r);
        return (jleft + jright);
      }();
      auto jright = Code01_CountOfRangeSum1::merge(l, m, r);
      return (jleft + jright);
    }();
  }
  static int merge(int l, int m, int r) {
    int ans = 0;
    int wl = l;
    int wr = l;
    i64 max = {};
    i64 min = {};
    for (int i = (m + 1); (i <= r); (i++)) {
      (max = (sum[i] - low));
      (min = (sum[i] - up));
      while (((wr <= m) && (sum[wr] <= max))) {
        (wr++);
      }
      while (((wl <= m) && (sum[wl] < min))) {
        (wl++);
      }
      (ans += (wr - wl));
    }
    int p1 = l;
    int p2 = (m + 1);
    int i = l;
    while (((p1 <= m) && (p2 <= r))) {
      (help[(i++)] = ((sum[p1] <= sum[p2]) ? sum[(p1++)] : sum[(p2++)]));
    }
    while ((p1 <= m)) {
      (help[(i++)] = sum[(p1++)]);
    }
    while ((p2 <= r)) {
      (help[(i++)] = sum[(p2++)]);
    }
    for ((i = l); (i <= r); (i++)) {
      (sum[i] = help[i]);
    }
    return ans;
  }
};

/* Original teaching comments:
// 达标子数组的个数
// 给定一个长度为n的数组nums，给定两个整数lower和upper
// 子数组达标的条件是累加和在[lower, upper]范围上
// 返回nums中有多少个达标子数组
// 1 <= n <= 10^5
// nums[i]可能是任意整数
// -10^5 <= lower <= upper <= +10^5
// 测试链接 : https://leetcode.cn/problems/count-of-range-sum/
        // 归并分治的解法，理解难度稍高，需要先掌握讲解022 - 归并分治
                // 归并分治的统计过程
                        // 有效窗口是[wl,wr)，左闭右开
                // 正常排序的合并过程
*/
