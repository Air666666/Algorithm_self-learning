// Source: src/class122/Code05_TransportPlan1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TransportPlan1 {
  inline static int MAXN = 300001;
  inline static int MAXM = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> headEdge = make_array<int>(MAXN);
  inline static Array<int> edgeNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeTo = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeWeight = make_array<int>(jshl(MAXN, 1));
  inline static int tcnt = {};
  inline static Array<int> headQuery = make_array<int>(MAXN);
  inline static Array<int> queryNext = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryTo = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> queryIndex = make_array<int>(jshl(MAXM, 1));
  inline static int qcnt = {};
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> unionfind = make_array<int>(MAXN);
  inline static Array<int> quesu = make_array<int>(MAXM);
  inline static Array<int> quesv = make_array<int>(MAXM);
  inline static Array<int> distance = make_array<int>(MAXN);
  inline static Array<int> lca = make_array<int>(MAXM);
  inline static Array<int> cost = make_array<int>(MAXM);
  inline static int maxCost = {};
  inline static int atLeast = {};
  inline static int beyond = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TransportPlan1() {}
  static void build() {
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 1, (n + 1), 0);
    j::fill(headQuery, 1, (n + 1), 0);
    j::fill(visited, 1, (n + 1), false);
    for (int i = 1; (i <= n); (i++)) {
      (unionfind[i] = i);
    }
    (maxCost = 0);
  }
  static void addEdge(int u, int v, int w) {
    (edgeNext[tcnt] = headEdge[u]);
    (edgeTo[tcnt] = v);
    (edgeWeight[tcnt] = w);
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
      (unionfind[i] = Code05_TransportPlan1::find(unionfind[i]));
    }
    return unionfind[i];
  }
  static void tarjan(int u, int f, int w) {
    (visited[u] = true);
    (distance[u] = (distance[f] + w));
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code05_TransportPlan1::tarjan(v, u, edgeWeight[e]);
        }
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      int i = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (i = queryIndex[e]);
          (lca[i] = Code05_TransportPlan1::find(v));
          (cost[i] = ((distance[u] + distance[v]) - (2 * distance[lca[i]])));
          (maxCost = jmax(maxCost, cost[i]));
        }
      }
    }
    (unionfind[u] = f);
  }
  static bool f(int limit) {
    (atLeast = (maxCost - limit));
    j::fill(num, 1, (n + 1), 0);
    (beyond = 0);
    for (int i = 1; (i <= m); (i++)) {
      if ((cost[i] > limit)) {
        (num[quesu[i]]++);
        (num[quesv[i]]++);
        (num[lca[i]] -= 2);
        (beyond++);
      }
    }
    return ((beyond == 0) || Code05_TransportPlan1::dfs(1, 0, 0));
  }
  static bool dfs(int u, int f, int w) {
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          if (Code05_TransportPlan1::dfs(v, u, edgeWeight[e])) {
            return true;
          }
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
    return ((num[u] == beyond) && (w >= atLeast));
  }
  static int compute() {
    Code05_TransportPlan1::tarjan(1, 0, 0);
    int l = 0;
    int r = maxCost;
    int mid = {};
    int ans = 0;
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if (Code05_TransportPlan1::f(mid)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code05_TransportPlan1::build();
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        in.nextToken();
        (w = static_cast<int>(in.nval));
        Code05_TransportPlan1::addEdge(u, v, w);
        Code05_TransportPlan1::addEdge(v, u, w);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (quesu[i] = u);
        (quesv[i] = v);
        Code05_TransportPlan1::addQuery(u, v, i);
        Code05_TransportPlan1::addQuery(v, u, i);
      }
    }
    out.println(Code05_TransportPlan1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_TransportPlan1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 运输计划，java递归版
// 有n个节点，给定n-1条边使其连接成一棵树，每条边有正数边权
// 给定很多运输计划，每个运输计划(a,b)表示从a去往b
// 每个运输计划的代价就是沿途边权和，运输计划之间完全互不干扰
// 你只能选择一条边，将其边权变成0
// 你的目的是让所有运输计划代价的最大值尽量小
// 返回所有运输计划代价的最大值最小能是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2680
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// 本节课Code05_TransportPlan3文件就是C++的实现
        // num[i] : i节点和其父节点的边，有多少代价>=limit的运输计划用到
        // 链式前向星建图需要
        // tarjan算法需要
        // distance[i] : 头节点到i号点的距离，tarjan算法过程中更新
        // lca[i] : 第i号运输计划的两端点lca，tarjan算法过程中更新
        // cost[i] : 第i号运输计划代价是多少，tarjan算法过程中更新
        // 所有运输计划的最大代价，tarjan算法过程中更新
        // 只能把一条边的权值变成0
        // 还要求每个运输计划的代价都要<=limit
        // 返回能不能做到
        // 至少要减少多少边权
        // 超过要求的运输计划有几个
*/
