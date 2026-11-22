// Source: src/class128/Code06_MarblesInBags.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MarblesInBags {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MarblesInBags() {}
  static i64 putMarbles(Array<int> weights, int k) {
    int n = weights.length;
    Array<i64> split = make_array<i64>((n - 1));
    for (int i = 1; (i < n); (i++)) {
      (split[(i - 1)] = (static_cast<i64>(weights[(i - 1)]) + weights[i]));
    }
    j::sort(split);
    i64 small = 0;
    i64 big = 0;
    {
      int i = 0;
      int j = (n - 2);
      int p = 1;
      for (; (p < k); (i++), (j--), (p++)) {
        (small += split[i]);
        (big += split[j]);
      }
    }
    return (big - small);
  }
};

/* Original teaching comments:
// 将珠子放进背包中
// 给定一个长度为n的数组weights，背包一共有k个
// 其中weights[i]是第i个珠子的重量
// 请你按照如下规则将所有的珠子放进k个背包
// 1，没有背包是空的
// 2，如果第i个珠子和第j个珠子在同一个背包里，那么i到j所有珠子都要在这个背包里
// 一个背包如果包含i到j的所有珠子，这个背包的价格是weights[i]+weights[j]
// 一个珠子分配方案的分数，是所有k个背包的价格之和
// 请返回所有分配方案中，最大分数与最小分数的差值为多少
// 1 <= n, k <= 10^5
// 测试链接 : https://leetcode.cn/problems/put-marbles-in-bags/
*/
