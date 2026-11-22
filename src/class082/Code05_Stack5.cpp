// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Source: src/class082/Code05_Stack5.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Stack5 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Stack5() {}
  static int maxProfit(Array<int> prices, int fee) {
    int prepare = ((-prices[0]) - fee);
    int done = 0;
    for (int i = 1; (i < prices.length); (i++)) {
      (done = jmax(done, (prepare + prices[i])));
      (prepare = jmax(prepare, ((done - prices[i]) - fee)));
    }
    return done;
  }
};

/* Original teaching comments:
// 买卖股票的最佳时机含手续费
// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格
// 整数 fee 代表了交易股票的手续费用
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费
// 如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值
//
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费
// 测试链接 :
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
                // prepare :
交易次数无限制情况下，获得收益的同时扣掉了一次购买和手续费之后，最好的情况
                // done : 交易次数无限制情况下，能获得的最大收益
*/
