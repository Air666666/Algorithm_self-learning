// Source: src/class119/Code03_QueryPathMinimumChangesToSame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_QueryPathMinimumChangesToSame {
  inline static int MAXN = 10001;
  inline static int MAXM = 20001;
  inline static int MAXW = 26;
  inline static Array<int> headEdge = make_array<int>(MAXN);
  inline static Array<int> edgeNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeTo = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeValue = make_array<int>(jshl(MAXN, 1));
  inline static int tcnt = {};
  inline static Array<Array<int>> weightCnt = make_array<int>(MAXN, (MAXW + 1));
  inline static Array<int> headQuery = make_array<int>(MAXN);
  inline static Array<int> queryNext = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryTo = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryIndex = make_array<int>(jshl(MAXM, 1));
  inline static int qcnt = {};
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> lca = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_QueryPathMinimumChangesToSame() {}
  static Array<int> minOperationsQueries(int n, Array<Array<int>> edges,
                                         Array<Array<int>> queries) {
    Code03_QueryPathMinimumChangesToSame::build(n);
    for (Array<int> edge : edges) {
      Code03_QueryPathMinimumChangesToSame::addEdge(edge[0], edge[1], edge[2]);
      Code03_QueryPathMinimumChangesToSame::addEdge(edge[1], edge[0], edge[2]);
    }
    Code03_QueryPathMinimumChangesToSame::dfs(0, 0, (-1));
    int m = queries.length;
    for (int i = 0; (i < m); (i++)) {
      Code03_QueryPathMinimumChangesToSame::addQuery(queries[i][0],
                                                     queries[i][1], i);
      Code03_QueryPathMinimumChangesToSame::addQuery(queries[i][1],
                                                     queries[i][0], i);
    }
    Code03_QueryPathMinimumChangesToSame::tarjan(0, (-1));
    Array<int> ans = make_array<int>(m);
    {
      int i = 0;
      int a = {};
      int b = {};
      int c = {};
      for (; (i < m); (i++)) {
        (a = queries[i][0]);
        (b = queries[i][1]);
        (c = lca[i]);
        int allCnt = 0;
        int maxCnt = 0;
        {
          int w = 1;
          int wcnt = {};
          for (; (w <= MAXW); (w++)) {
            (wcnt =
                 ((weightCnt[a][w] + weightCnt[b][w]) - (2 * weightCnt[c][w])));
            (maxCnt = jmax(maxCnt, wcnt));
            (allCnt += wcnt);
          }
        }
        (ans[i] = (allCnt - maxCnt));
      }
    }
    return ans;
  }
  static void build(int n) {
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 0, n, 0);
    j::fill(headQuery, 0, n, 0);
    j::fill(visited, 0, n, false);
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
    }
  }
  static void addEdge(int u, int v, int w) {
    (edgeNext[tcnt] = headEdge[u]);
    (edgeTo[tcnt] = v);
    (edgeValue[tcnt] = w);
    (headEdge[u] = (tcnt++));
  }
  static void dfs(int u, int w, int f) {
    if ((u == 0)) {
      j::fill(weightCnt[u], 0);
    } else {
      for (int i = 1; (i <= MAXW); (i++)) {
        (weightCnt[u][i] = weightCnt[f][i]);
      }
      (weightCnt[u][w]++);
    }
    for (int e = headEdge[u]; (e != 0); (e = edgeNext[e])) {
      if ((edgeTo[e] != f)) {
        Code03_QueryPathMinimumChangesToSame::dfs(edgeTo[e], edgeValue[e], u);
      }
    }
  }
  static void addQuery(int u, int v, int i) {
    (queryNext[qcnt] = headQuery[u]);
    (queryTo[qcnt] = v);
    (queryIndex[qcnt] = i);
    (headQuery[u] = (qcnt++));
  }
  static void tarjan(int u, int f) {
    (visited[u] = true);
    for (int e = headEdge[u]; (e != 0); (e = edgeNext[e])) {
      if ((edgeTo[e] != f)) {
        Code03_QueryPathMinimumChangesToSame::tarjan(edgeTo[e], u);
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (lca[queryIndex[e]] = Code03_QueryPathMinimumChangesToSame::find(v));
        }
      }
    }
    (father[u] = f);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_QueryPathMinimumChangesToSame::find(father[i]));
    }
    return father[i];
  }
};

/* Original teaching comments:
// 边权相等的最小修改次数
// 一棵树有n个节点，编号0 ~ n-1，每条边(u,v,w)表示从u到v有一条权重为w的边
//
一共有m条查询，每条查询(a,b)表示，a到b的最短路径中把所有边变成一种值需要修改几条边
// 返回每条查询的查询结果
// 1 <= n <= 10^4
// 1 <= m <= 2 * 10^4
// 0 <= u、v、a、b < n
// 1 <= w <= 26
// 测试链接 :
https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/
        // 链式前向星建图
        // weightCnt[i][w] : 从头节点到i的路径中，权值为w的边有几条
        // 以下所有的结构都是为了tarjan算法做准备
                // 从头节点到每个节点的边权值词频统计
                // 得到每个查询的最低公共祖先
        // 当前来到u节点，父亲节点f，从f到u权重为w
        // 统计从头节点到u节点，每种权值的边有多少条
        // 信息存放在weightCnt[u][1..26]里
        // tarjan算法批量查询两点的最低公共祖先
*/
