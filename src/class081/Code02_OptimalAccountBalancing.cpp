// Source: src/class081/Code02_OptimalAccountBalancing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_OptimalAccountBalancing {
  inline static int MAXN = 13;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_OptimalAccountBalancing() {}
  static int minTransfers(Array<Array<int>> transactions) {
    Array<int> debt = Code02_OptimalAccountBalancing::debts(transactions);
    int n = debt.length;
    Array<int> dp = make_array<int>(jshl(1, n));
    j::fill(dp, (-1));
    return (n - Code02_OptimalAccountBalancing::f(debt, (jshl(1, n) - 1), 0, n,
                                                  dp));
  }
  static Array<int> debts(Array<Array<int>> transactions) {
    Array<int> help = make_array<int>(MAXN);
    for (Array<int> tran : transactions) {
      (help[tran[0]] -= tran[2]);
      (help[tran[1]] += tran[2]);
    }
    int n = 0;
    for (int num : help) {
      if ((num != 0)) {
        (n++);
      }
    }
    Array<int> debt = make_array<int>(n);
    int index = 0;
    for (int num : help) {
      if ((num != 0)) {
        (debt[(index++)] = num);
      }
    }
    return debt;
  }
  static int f(Array<int> debt, int set, int sum, int n, Array<int> dp) {
    if ((dp[set] != (-1))) {
      return dp[set];
    }
    int ans = 0;
    if (((set & (set - 1)) != 0)) {
      if ((sum == 0)) {
        for (int i = 0; (i < n); (i++)) {
          if (((set & jshl(1, i)) != 0)) {
            (ans = (Code02_OptimalAccountBalancing::f(debt, (set ^ jshl(1, i)),
                                                      (sum - debt[i]), n, dp) +
                    1));
            break;
          }
        }
      } else {
        for (int i = 0; (i < n); (i++)) {
          if (((set & jshl(1, i)) != 0)) {
            (ans = jmax(ans,
                        Code02_OptimalAccountBalancing::f(
                            debt, (set ^ jshl(1, i)), (sum - debt[i]), n, dp)));
          }
        }
      }
    }
    (dp[set] = ans);
    return ans;
  }
};

/* Original teaching comments:
// 最优账单平衡
// 给你一个表示交易的数组 transactions
// 其中 transactions[i] = [fromi, toi, amounti]
// 表示 ID = fromi 的人给 ID = toi 的人共计 amounti
// 请你计算并返回还清所有债务的最小交易笔数
// 测试链接 : https://leetcode.cn/problems/optimal-account-balancing/
        // 题目说了人员编号的最大范围：0 ~ 12
                // 加工出来的debt数组中一定不含有0
                                                //
找到任何一个元素，去除这个元素
                                                // 剩下的集合进行尝试，返回值 +
1
                                                //
然后不需要再尝试下一个元素了，因为答案一定是一样的
                                                // 所以直接break
*/
