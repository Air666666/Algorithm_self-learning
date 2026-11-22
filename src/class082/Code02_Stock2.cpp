// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

// Source: src/class082/Code02_Stock2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Stock2 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Stock2() {}
  static int maxProfit(Array<int> prices) {
    int ans = 0;
    for (int i = 1; (i < prices.length); (i++)) {
      (ans += jmax((prices[i] - prices[(i - 1)]), 0));
    }
    return ans;
  }
};

/* Original teaching comments:
// 买卖股票的最佳时机 II
// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格
// 在每一天，你可以决定是否购买和/或出售股票
// 你在任何时候 最多 只能持有 一股 股票
// 你也可以先购买，然后在 同一天 出售
// 返回 你能获得的 最大 利润
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
*/
