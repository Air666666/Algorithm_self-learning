// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

// Source: src/class082/Code01_Stock1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Stock1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Stock1() {}
  static int maxProfit(Array<int> prices) {
    int ans = 0;
    {
      int i = 1;
      int min = prices[0];
      for (; (i < prices.length); (i++)) {
        (min = jmin(min, prices[i]));
        (ans = jmax(ans, (prices[i] - min)));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 买卖股票的最佳时机
// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票
// 设计一个算法来计算你所能获取的最大利润
// 返回你可以从这笔交易中获取的最大利润
// 如果你不能获取任何利润，返回 0
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
                        // min : 0...i范围上的最小值
*/
