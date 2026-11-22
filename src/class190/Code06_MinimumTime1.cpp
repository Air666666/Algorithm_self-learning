// Source: src/class190/Code06_MinimumTime1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MinimumTime1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 1000001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> val = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> x, Array<int> y) { return (x[1] - y[1]); });
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MinimumTime1() {}
  static void push(int u, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code06_MinimumTime1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code06_MinimumTime1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_MinimumTime1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code06_MinimumTime1::push(u, 0, e);
          Code06_MinimumTime1::push(v, (-1), (-1));
        } else {
          Code06_MinimumTime1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
          } while ((pop != u));
        }
      }
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((((scc1 > 0) && (scc2 > 0)) && (scc1 != scc2))) {
        Code06_MinimumTime1::addEdge(scc1, scc2, val[i]);
      }
    }
  }
  static int dijkstra() {
    for (int i = 1; (i <= sccCnt); (i++)) {
      (dist[i] = INF);
      (vis[i] = false);
    }
    (dist[belong[1]] = 0);
    heap.add(Array<int>{belong[1], 0});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int u = cur[0];
      int d = cur[1];
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          int w = weight[e];
          if (((!vis[v]) && (dist[v] > (d + w)))) {
            (dist[v] = (d + w));
            heap.add(Array<int>{v, dist[v]});
          }
        }
      }
    }
    return dist[belong[n]];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      (val[i] = in.nextInt());
      Code06_MinimumTime1::addEdge(a[i], b[i], val[i]);
    }
    Code06_MinimumTime1::tarjan2(1);
    if ((belong[n] == 0)) {
      out.println((-1));
    } else {
      Code06_MinimumTime1::condense();
      int ans = Code06_MinimumTime1::dijkstra();
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_MinimumTime1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 缩点最短路，java版
// 给定一张n个点，m条边的有向图，每条边有非负边权
// 如果两点属同一个强连通分量，认为彼此到达的代价为0
// 找到从1号点到n号点的路径，打印最小的边权累加和，如果不能到达打印-1
// 1 <= n <= 2 * 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P2169
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                // tarjan1(1);
        // 读写工具类
*/
