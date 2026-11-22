// Source: src/class130/Code06_SumOfTotalStrength.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_SumOfTotalStrength {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_SumOfTotalStrength() {}
  static int totalStrength(Array<int> arr) {
    int n = arr.length;
    int pre = jrem(arr[0], MOD);
    Array<int> sumsum = make_array<int>(n);
    (sumsum[0] = pre);
    for (int i = 1; (i < n); (i++)) {
      (pre = jrem((pre + arr[i]), MOD));
      (sumsum[i] = jrem((sumsum[(i - 1)] + pre), MOD));
    }
    Array<int> stack = make_array<int>(n);
    int size = 0;
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      while (((size > 0) && (arr[stack[(size - 1)]] >= arr[i]))) {
        int m = stack[(--size)];
        int l = ((size > 0) ? stack[(size - 1)] : (-1));
        (ans =
             jrem((ans + Code06_SumOfTotalStrength::sum(arr, sumsum, l, m, i)),
                  MOD));
      }
      (stack[(size++)] = i);
    }
    while ((size > 0)) {
      int m = stack[(--size)];
      int l = ((size > 0) ? stack[(size - 1)] : (-1));
      (ans = jrem((ans + Code06_SumOfTotalStrength::sum(arr, sumsum, l, m, n)),
                  MOD));
    }
    return ans;
  }
  static int sum(Array<int> arr, Array<int> sumsum, int l, int m, int r) {
    i64 left = sumsum[(r - 1)];
    if (((m - 1) >= 0)) {
      (left = jrem(((left - sumsum[(m - 1)]) + MOD), MOD));
    }
    (left = jrem((left * (m - l)), MOD));
    i64 right = 0;
    if (((m - 1) >= 0)) {
      (right = jrem((right + sumsum[(m - 1)]), MOD));
    }
    if (((l - 1) >= 0)) {
      (right = jrem(((right - sumsum[(l - 1)]) + MOD), MOD));
    }
    (right = jrem((right * (r - m)), MOD));
    return static_cast<int>(
        jrem((jrem(((left - right) + MOD), MOD) * arr[m]), MOD));
  }
};

/* Original teaching comments:
// 巫师力量和
// 题目可以简化为如下的描述
// 给定一个长度为n的数组arr，下标从0开始
// 任何一个子数组的指标为，子数组累加和 * 子数组中最小值
// 返回arr中所有子数组指标的累加和，答案对 1000000007 取模
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^9
// 测试链接 : https://leetcode.cn/problems/sum-of-total-strength-of-wizards/
*/
