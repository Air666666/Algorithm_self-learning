// Source: src/class082/Code06_Stack6.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Stack6 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Stack6() {}
  static int maxProfit1(Array<int> prices) {
    int n = prices.length;
    if ((n < 2)) {
      return 0;
    }
    Array<int> prepare = make_array<int>(n);
    Array<int> done = make_array<int>(n);
    (prepare[1] = jmax((-prices[0]), (-prices[1])));
    (done[1] = jmax(0, (prices[1] - prices[0])));
    for (int i = 2; (i < n); (i++)) {
      (done[i] = jmax(done[(i - 1)], (prepare[(i - 1)] + prices[i])));
      (prepare[i] = jmax(prepare[(i - 1)], (done[(i - 2)] - prices[i])));
    }
    return done[(n - 1)];
  }
  static int maxProfit2(Array<int> prices) {
    int n = prices.length;
    if ((n < 2)) {
      return 0;
    }
    int prepare = jmax((-prices[0]), (-prices[1]));
    int done2 = 0;
    int done1 = jmax(0, (prices[1] - prices[0]));
    {
      int i = 2;
      int curDone = {};
      for (; (i < n); (i++)) {
        (curDone = jmax(done1, (prepare + prices[i])));
        (prepare = jmax(prepare, (done2 - prices[i])));
        (done2 = done1);
        (done1 = curDone);
      }
    }
    return done1;
  }
};

/* Original teaching comments:
// 买卖股票的最佳时机含冷冻期
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格
// 设计一个算法计算出最大利润
// 在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
// 测试链接 :
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
                // prepare[i] :
0...i范围上，可以做无限次交易，获得收益的同时一定要扣掉一次购买，所有情况中的最好情况
                // done[i] : 0...i范围上，可以做无限次交易，能获得的最大收益
        // 只是把方法1做了变量滚动更新(空间压缩)
        // 并没有新的东西
                // prepare : prepare[i-1]
                // done2 : done[i-2]
                // done1 : done[i-1]
                        // curDone : done[i]
                        // prepare : prepare[i-1] -> prepare[i]
*/
