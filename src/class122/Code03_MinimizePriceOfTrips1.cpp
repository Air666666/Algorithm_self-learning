// Source: src/class122/Code03_MinimizePriceOfTrips1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimizePriceOfTrips1 {
  inline static int MAXN = 51;
  inline static int LIMIT = 6;
  inline static int power = {};
  inline static Array<int> price = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static int no = {};
  inline static int yes = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimizePriceOfTrips1() {}
  static int minimumTotalPrice(int n, Array<Array<int>> es, Array<int> ps,
                               Array<Array<int>> ts) {
    Code03_MinimizePriceOfTrips1::build(n);
    {
      int i = 0;
      int j = 1;
      for (; (i < n); (i++), (j++)) {
        (price[j] = ps[i]);
      }
    }
    for (Array<int> edge : es) {
      Code03_MinimizePriceOfTrips1::addEdge((edge[0] + 1), (edge[1] + 1));
      Code03_MinimizePriceOfTrips1::addEdge((edge[1] + 1), (edge[0] + 1));
    }
    Code03_MinimizePriceOfTrips1::dfs1(1, 0);
    int u = {};
    int v = {};
    int lca = {};
    int lcafather = {};
    for (Array<int> trip : ts) {
      (u = (trip[0] + 1));
      (v = (trip[1] + 1));
      (lca = Code03_MinimizePriceOfTrips1::lca(u, v));
      (lcafather = stjump[lca][0]);
      (num[u]++);
      (num[v]++);
      (num[lca]--);
      (num[lcafather]--);
    }
    Code03_MinimizePriceOfTrips1::dfs2(1, 0);
    Code03_MinimizePriceOfTrips1::dp(1, 0);
    return jmin(no, yes);
  }
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build(int n) {
    (power = Code03_MinimizePriceOfTrips1::log2(n));
    j::fill(num, 1, (n + 1), 0);
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    (deep[u] = (deep[f] + 1));
    (stjump[u][0] = f);
    for (int p = 1; (p <= power); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code03_MinimizePriceOfTrips1::dfs1(to[e], u);
      }
    }
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void dfs2(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code03_MinimizePriceOfTrips1::dfs2(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
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
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code03_MinimizePriceOfTrips1::dp(v, u);
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
// 最小化旅行的价格总和(倍增方法求lca)
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
