// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/

// Source: src/class122/Code03_MinimizePriceOfTrips2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimizePriceOfTrips2 {
  inline static int MAXN = 51;
  inline static int MAXM = 101;
  inline static Array<int> price = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> headEdge = make_array<int>(MAXN);
  inline static Array<int> edgeNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeTo = make_array<int>(jshl(MAXN, 1));
  inline static int tcnt = {};
  inline static Array<int> headQuery = make_array<int>(MAXN);
  inline static Array<int> queryNext = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryTo = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryIndex = make_array<int>(jshl(MAXM, 1));
  inline static int qcnt = {};
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> unionfind = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXM);
  inline static int no = {};
  inline static int yes = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimizePriceOfTrips2() {}
  static int minimumTotalPrice(int n, Array<Array<int>> es, Array<int> ps,
                               Array<Array<int>> ts) {
    Code03_MinimizePriceOfTrips2::build(n);
    {
      int i = 0;
      int j = 1;
      for (; (i < n); (i++), (j++)) {
        (price[j] = ps[i]);
      }
    }
    for (Array<int> edge : es) {
      Code03_MinimizePriceOfTrips2::addEdge((edge[0] + 1), (edge[1] + 1));
      Code03_MinimizePriceOfTrips2::addEdge((edge[1] + 1), (edge[0] + 1));
    }
    int m = ts.length;
    {
      int i = 0;
      int j = 1;
      for (; (i < m); (i++), (j++)) {
        Code03_MinimizePriceOfTrips2::addQuery((ts[i][0] + 1), (ts[i][1] + 1),
                                               j);
        Code03_MinimizePriceOfTrips2::addQuery((ts[i][1] + 1), (ts[i][0] + 1),
                                               j);
      }
    }
    Code03_MinimizePriceOfTrips2::tarjan(1, 0);
    {
      int i = 0;
      int j = 1;
      int u = {};
      int v = {};
      int lca = {};
      int lcafather = {};
      for (; (i < m); (i++), (j++)) {
        (u = (ts[i][0] + 1));
        (v = (ts[i][1] + 1));
        (lca = ans[j]);
        (lcafather = father[lca]);
        (num[u]++);
        (num[v]++);
        (num[lca]--);
        (num[lcafather]--);
      }
    }
    Code03_MinimizePriceOfTrips2::dfs(1, 0);
    Code03_MinimizePriceOfTrips2::dp(1, 0);
    return jmin(no, yes);
  }
  static void build(int n) {
    j::fill(num, 1, (n + 1), 0);
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 1, (n + 1), 0);
    j::fill(headQuery, 1, (n + 1), 0);
    j::fill(visited, 1, (n + 1), false);
    for (int i = 1; (i <= n); (i++)) {
      (unionfind[i] = i);
    }
  }
  static void addEdge(int u, int v) {
    (edgeNext[tcnt] = headEdge[u]);
    (edgeTo[tcnt] = v);
    (headEdge[u] = (tcnt++));
  }
  static void addQuery(int u, int v, int i) {
    (queryNext[qcnt] = headQuery[u]);
    (queryTo[qcnt] = v);
    (queryIndex[qcnt] = i);
    (headQuery[u] = (qcnt++));
  }
  static int find(int i) {
    if ((i != unionfind[i])) {
      (unionfind[i] = Code03_MinimizePriceOfTrips2::find(unionfind[i]));
    }
    return unionfind[i];
  }
  static void tarjan(int u, int f) {
    (visited[u] = true);
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code03_MinimizePriceOfTrips2::tarjan(v, u);
        }
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (ans[queryIndex[e]] = Code03_MinimizePriceOfTrips2::find(v));
        }
      }
    }
    (unionfind[u] = f);
    (father[u] = f);
  }
  static void dfs(int u, int f) {
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code03_MinimizePriceOfTrips2::dfs(v, u);
        }
      }
    }
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          (num[u] += num[v]);
        }
      }
    }
  }
  static void dp(int u, int f) {
    int n = (price[u] * num[u]);
    int y = (jdiv(price[u], 2) * num[u]);
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code03_MinimizePriceOfTrips2::dp(v, u);
          (n += jmin(no, yes));
          (y += no);
        }
      }
    }
    (no = n);
    (yes = y);
  }
};

/* Original teaching comments:
// 最小化旅行的价格总和(tarjan方法求lca)
// 有n个节点形成一棵树，每个节点上有点权，再给定很多路径
// 每条路径有开始点和结束点，路径代价就是从开始点到结束点的点权和
// 所有路径的代价总和就是旅行的价格总和
// 你可以选择把某些点的点权减少一半，来降低旅行的价格总和
// 但是要求选择的点不能相邻
// 返回旅行的价格总和最少能是多少
// 测试链接 :
https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/
        // 题目给定点的编号从0号点开始，代码中调整成从1号点开始
*/
