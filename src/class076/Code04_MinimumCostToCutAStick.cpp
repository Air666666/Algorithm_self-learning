// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/

// Source: src/class076/Code04_MinimumCostToCutAStick.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MinimumCostToCutAStick {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MinimumCostToCutAStick() {}
  static int minCost1(int n, Array<int> cuts) {
    int m = cuts.length;
    j::sort(cuts);
    Array<int> arr = make_array<int>((m + 2));
    (arr[0] = 0);
    for (int i = 1; (i <= m); (i++)) {
      (arr[i] = cuts[(i - 1)]);
    }
    (arr[(m + 1)] = n);
    Array<Array<int>> dp = make_array<int>((m + 2), (m + 2));
    for (int i = 1; (i <= m); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code04_MinimumCostToCutAStick::f(arr, 1, m, dp);
  }
  static int f(Array<int> arr, int l, int r, Array<Array<int>> dp) {
    if ((l > r)) {
      return 0;
    }
    if ((l == r)) {
      return (arr[(r + 1)] - arr[(l - 1)]);
    }
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = std::numeric_limits<int>::max();
    for (int k = l; (k <= r); (k++)) {
      (ans = jmin(ans, [&]() {
         auto jleft = Code04_MinimumCostToCutAStick::f(arr, l, (k - 1), dp);
         auto jright = Code04_MinimumCostToCutAStick::f(arr, (k + 1), r, dp);
         return (jleft + jright);
       }()));
    }
    (ans += (arr[(r + 1)] - arr[(l - 1)]));
    (dp[l][r] = ans);
    return ans;
  }
  static int minCost2(int n, Array<int> cuts) {
    int m = cuts.length;
    j::sort(cuts);
    Array<int> arr = make_array<int>((m + 2));
    (arr[0] = 0);
    for (int i = 1; (i <= m); (i++)) {
      (arr[i] = cuts[(i - 1)]);
    }
    (arr[(m + 1)] = n);
    Array<Array<int>> dp = make_array<int>((m + 2), (m + 2));
    for (int i = 1; (i <= m); (i++)) {
      (dp[i][i] = (arr[(i + 1)] - arr[(i - 1)]));
    }
    {
      int l = (m - 1);
      int next = {};
      for (; (l >= 1); (l--)) {
        for (int r = (l + 1); (r <= m); (r++)) {
          (next = std::numeric_limits<int>::max());
          for (int k = l; (k <= r); (k++)) {
            (next = jmin(next, (dp[l][(k - 1)] + dp[(k + 1)][r])));
          }
          (dp[l][r] = ((arr[(r + 1)] - arr[(l - 1)]) + next));
        }
      }
    }
    return dp[1][m];
  }
};

/* Original teaching comments:
// 切棍子的最小成本
// 有一根长度为n个单位的木棍，棍上从0到n标记了若干位置
// 给你一个整数数组cuts，其中cuts[i]表示你需要将棍子切开的位置
// 你可以按顺序完成切割，也可以根据需要更改切割的顺序
// 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和
// 对棍子进行切割将会把一根木棍分成两根较小的木棍
// 这两根木棍的长度和就是切割前木棍的长度
// 返回切棍子的最小总成本
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/
        // 记忆化搜索
        // 切点[l....r]，决定一个顺序
        // 让切点都切完，总代价最小
        // 严格位置依赖的动态规划
*/
