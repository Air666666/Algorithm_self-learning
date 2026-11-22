// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/sum-of-subarray-minimums/

// Source: src/class052/Code03_SumOfSubarrayMinimums.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SumOfSubarrayMinimums {
  inline static int MOD = 1000000007;
  inline static int MAXN = 30001;
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SumOfSubarrayMinimums() {}
  static int sumSubarrayMins(Array<int> arr) {
    i64 ans = 0;
    (r = 0);
    for (int i = 0; (i < arr.length); (i++)) {
      while (((r > 0) && (arr[stack[(r - 1)]] >= arr[i]))) {
        int cur = stack[(--r)];
        int left = ((r == 0) ? (-1) : stack[(r - 1)]);
        (ans = jrem(
             (ans + ((static_cast<i64>((cur - left)) * (i - cur)) * arr[cur])),
             MOD));
      }
      (stack[(r++)] = i);
    }
    while ((r > 0)) {
      int cur = stack[(--r)];
      int left = ((r == 0) ? (-1) : stack[(r - 1)]);
      (ans =
           jrem((ans + ((static_cast<i64>((cur - left)) * (arr.length - cur)) *
                        arr[cur])),
                MOD));
    }
    return static_cast<int>(ans);
  }
};

/* Original teaching comments:
// 子数组的最小值之和
// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr
的每个（连续）子数组。
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/
                // 注意课上讲的相等情况的修正
*/
