// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/cheapest-flights-within-k-stops/

// Source: src/class065/Code03_BellmanFord.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_BellmanFord {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_BellmanFord() {}
  static int findCheapestPrice(int n, Array<Array<int>> flights, int start,
                               int target, int k) {
    Array<int> cur = make_array<int>(n);
    j::fill(cur, std::numeric_limits<int>::max());
    (cur[start] = 0);
    for (int i = 0; (i <= k); (i++)) {
      Array<int> next = j::copyOf(cur, n);
      for (Array<int> edge : flights) {
        if ((cur[edge[0]] != std::numeric_limits<int>::max())) {
          (next[edge[1]] = jmin(next[edge[1]], (cur[edge[0]] + edge[2])));
        }
      }
      (cur = next);
    }
    return ((cur[target] == std::numeric_limits<int>::max()) ? (-1)
                                                             : cur[target]);
  }
};

/* Original teaching comments:
// Bellman-Ford算法应用（不是模版）
// k站中转内最便宜的航班
// 有 n 个城市通过一些航班连接。给你一个数组 flights
// 其中 flights[i] = [fromi, toi, pricei]
// 表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
// 现在给定所有的城市和航班，以及出发城市 src 和目的地
dst，你的任务是找到出一条最多经过 k 站中转的路线
// 使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出
-1。
// 测试链接 : https://leetcode.cn/problems/cheapest-flights-within-k-stops/
        // Bellman-Ford算法
        // 针对此题改写了松弛逻辑，课上讲了细节
                                // a -> b , w
*/
