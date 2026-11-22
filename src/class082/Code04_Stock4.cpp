// Source: src/class082/Code04_Stock4.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Stock4 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Stock4() {}
  static int free(Array<int> prices) {
    int ans = 0;
    for (int i = 1; (i < prices.length); (i++)) {
      (ans += jmax((prices[i] - prices[(i - 1)]), 0));
    }
    return ans;
  }
  static int maxProfit1(int k, Array<int> prices) {
    int n = prices.length;
    if ((k >= jdiv(n, 2))) {
      return Code04_Stock4::free(prices);
    }
    Array<Array<int>> dp = make_array<int>((k + 1), n);
    for (int i = 1; (i <= k); (i++)) {
      for (int j = 1; (j < n); (j++)) {
        (dp[i][j] = dp[i][(j - 1)]);
        for (int p = 0; (p < j); (p++)) {
          (dp[i][j] =
               jmax(dp[i][j], ((dp[(i - 1)][p] + prices[j]) - prices[p])));
        }
      }
    }
    return dp[k][(n - 1)];
  }
  static int maxProfit2(int k, Array<int> prices) {
    int n = prices.length;
    if ((k >= jdiv(n, 2))) {
      return Code04_Stock4::free(prices);
    }
    Array<Array<int>> dp = make_array<int>((k + 1), n);
    {
      int i = 1;
      int best = {};
      for (; (i <= k); (i++)) {
        (best = (dp[(i - 1)][0] - prices[0]));
        for (int j = 1; (j < n); (j++)) {
          (dp[i][j] = jmax(dp[i][(j - 1)], (best + prices[j])));
          (best = jmax(best, (dp[(i - 1)][j] - prices[j])));
        }
      }
    }
    return dp[k][(n - 1)];
  }
  static int maxProfit3(int k, Array<int> prices) {
    int n = prices.length;
    if ((k >= jdiv(n, 2))) {
      return Code04_Stock4::free(prices);
    }
    Array<int> dp = make_array<int>(n);
    {
      int i = 1;
      int best = {};
      int tmp = {};
      for (; (i <= k); (i++)) {
        (best = (dp[0] - prices[0]));
        for (int j = 1; (j < n); (j++)) {
          (tmp = dp[j]);
          (dp[j] = jmax(dp[(j - 1)], (best + prices[j])));
          (best = jmax(best, (tmp - prices[j])));
        }
      }
    }
    return dp[(n - 1)];
  }
};

/* Original teaching comments:
// 买卖股票的最佳时机 IV
// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i
天的价格
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易
// 也就是说，你最多可以买 k 次，卖 k 次
// 注意：你不能同时参与多笔交易，你必须在再次购买前出售掉之前的股票
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
        // 就是股票问题2
                        // 这是一个剪枝
                        // 如果k >= n / 2，那么代表所有上坡都可以抓到
                        // 所有上坡都可以抓到 == 交易次数无限，所以回到股票问题2
                        // 这是一个剪枝
                        // 如果k >= n / 2，那么代表所有上坡都可以抓到
                        // 所有上坡都可以抓到 == 交易次数无限，所以回到股票问题2
                                // 用best变量替代了枚举行为
        // 对方法2进行空间压缩的版本
                        // 这是一个剪枝
                        // 如果k >= n / 2，那么代表所有上坡都可以抓到
                        // 所有上坡都可以抓到 == 交易次数无限，所以回到股票问题2
*/
