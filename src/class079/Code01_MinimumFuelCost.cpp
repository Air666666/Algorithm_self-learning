// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/

// Source: src/class079/Code01_MinimumFuelCost.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumFuelCost {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumFuelCost() {}
  static i64 minimumFuelCost(Array<Array<int>> roads, int seats) {
    int n = (roads.length + 1);
    JList<JList<int>> graph = JList<JList<int>>();
    for (int i = 0; (i < n); (i++)) {
      graph.add(JList<int>());
    }
    for (Array<int> r : roads) {
      graph.get(r[0]).add(r[1]);
      graph.get(r[1]).add(r[0]);
    }
    Array<int> size = make_array<int>(n);
    Array<i64> cost = make_array<i64>(n);
    Code01_MinimumFuelCost::f(graph, seats, 0, (-1), size, cost);
    return cost[0];
  }
  static void f(JList<JList<int>> graph, int seats, int u, int p,
                Array<int> size, Array<i64> cost) {
    (size[u] = 1);
    for (int v : graph.get(u)) {
      if ((v != p)) {
        Code01_MinimumFuelCost::f(graph, seats, v, u, size, cost);
        (size[u] += size[v]);
        (cost[u] += cost[v]);
        (cost[u] += jdiv(((size[v] + seats) - 1), seats));
      }
    }
  }
};

/* Original teaching comments:
// 到达首都的最少油耗
// 给你一棵 n 个节点的树（一个无向、连通、无环图）
// 每个节点表示一个城市，编号从 0 到 n - 1 ，且恰好有 n - 1 条路
// 0 是首都。给你一个二维整数数组 roads
// 其中 roads[i] = [ai, bi] ，表示城市 ai 和 bi 之间有一条 双向路
// 每个城市里有一个代表，他们都要去首都参加一个会议
// 每座城市里有一辆车。给你一个整数 seats 表示每辆车里面座位的数目
// 城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车
// 相邻城市之间一辆车的油耗是一升汽油
// 请你返回到达首都最少需要多少升汽油
// 测试链接 :
https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/
        // 根据图，当前来到u，u的父节点是p
        // 遍历完成后，请填好size[u]、cost[u]
                                // a/b向上取整，可以写成(a+b-1)/b
                                // (size[v]+seats-1) / seats = size[v] / seats
向上取整
*/
