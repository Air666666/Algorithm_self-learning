// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/profitable-schemes/

// Source: src/class069/Code02_ProfitableSchemes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ProfitableSchemes {
  inline static int mod = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ProfitableSchemes() {}
  static int profitableSchemes1(int n, int minProfit, Array<int> group,
                                Array<int> profit) {
    return Code02_ProfitableSchemes::f1(group, profit, 0, n, minProfit);
  }
  static int f1(Array<int> g, Array<int> p, int i, int r, int s) {
    if ((r <= 0)) {
      return ((s <= 0) ? 1 : 0);
    }
    if ((i == g.length)) {
      return ((s <= 0) ? 1 : 0);
    }
    int p1 = Code02_ProfitableSchemes::f1(g, p, (i + 1), r, s);
    int p2 = 0;
    if ((g[i] <= r)) {
      (p2 =
           Code02_ProfitableSchemes::f1(g, p, (i + 1), (r - g[i]), (s - p[i])));
    }
    return (p1 + p2);
  }
  static int profitableSchemes2(int n, int minProfit, Array<int> group,
                                Array<int> profit) {
    int m = group.length;
    Array<Array<Array<int>>> dp = make_array<int>(m, (n + 1), (minProfit + 1));
    for (int a = 0; (a < m); (a++)) {
      for (int b = 0; (b <= n); (b++)) {
        for (int c = 0; (c <= minProfit); (c++)) {
          (dp[a][b][c] = (-1));
        }
      }
    }
    return Code02_ProfitableSchemes::f2(group, profit, 0, n, minProfit, dp);
  }
  static int f2(Array<int> g, Array<int> p, int i, int r, int s,
                Array<Array<Array<int>>> dp) {
    if ((r <= 0)) {
      return ((s == 0) ? 1 : 0);
    }
    if ((i == g.length)) {
      return ((s == 0) ? 1 : 0);
    }
    if ((dp[i][r][s] != (-1))) {
      return dp[i][r][s];
    }
    int p1 = Code02_ProfitableSchemes::f2(g, p, (i + 1), r, s, dp);
    int p2 = 0;
    if ((g[i] <= r)) {
      (p2 = Code02_ProfitableSchemes::f2(g, p, (i + 1), (r - g[i]),
                                         jmax(0, (s - p[i])), dp));
    }
    int ans = jrem((p1 + p2), mod);
    (dp[i][r][s] = ans);
    return ans;
  }
  static int profitableSchemes3(int n, int minProfit, Array<int> group,
                                Array<int> profit) {
    Array<Array<int>> dp = make_array<int>((n + 1), (minProfit + 1));
    for (int r = 0; (r <= n); (r++)) {
      (dp[r][0] = 1);
    }
    int m = group.length;
    for (int i = (m - 1); (i >= 0); (i--)) {
      for (int r = n; (r >= 0); (r--)) {
        for (int s = minProfit; (s >= 0); (s--)) {
          int p1 = dp[r][s];
          int p2 =
              ((group[i] <= r) ? dp[(r - group[i])][jmax(0, (s - profit[i]))]
                               : 0);
          (dp[r][s] = jrem((p1 + p2), mod));
        }
      }
    }
    return dp[n][minProfit];
  }
};

/* Original teaching comments:
// 盈利计划(多维费用背包)
// 集团里有 n 名员工，他们可以完成各种各样的工作创造利润
// 第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与
// 如果成员参与了其中一项工作，就不能参与另一项工作
// 工作的任何至少产生 minProfit 利润的子集称为 盈利计划
// 并且工作的成员总数最多为 n
// 有多少种计划可以选择？因为答案很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/profitable-schemes/
        // n : 员工的额度，不能超
        // p : 利润的额度，不能少
        // group[i] : i号项目需要几个人
        // profit[i] : i号项目产生的利润
        // 返回能做到员工不能超过n，利润不能少于p的计划有多少个
        // i : 来到i号工作
        // r : 员工额度还有r人，如果r<=0说明已经没法再选择工作了
        // s : 利润还有s才能达标，如果s<=0说明之前的选择已经让利润达标了
        // 返回 : i.... r、s，有多少种方案
                        // 人已经耗尽了，之前可能选了一些工作
                // r > 0
                        // 工作耗尽了，之前可能选了一些工作
                // 不要当前工作
                // 要做当前工作
                // i = 没有工作的时候，i == g.length
*/
