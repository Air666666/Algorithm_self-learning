// Source: src/class210/Code08_Collecting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Collecting1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 1000001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static int sccCnt = {};
  inline static Array<i64> prefix = make_array<i64>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<i64> weight = make_array<i64>(jshl(MAXM, 1));
  inline static Array<i64> cost = make_array<i64>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<i64> flow = make_array<i64>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static JDeque<int> que = JDeque<int>();
  inline static Array<i64> h = make_array<i64>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static JHeap<Array<i64>> heap = JHeap<Array<i64>>(
      [](Array<i64> a, Array<i64> b) { return jcompare(a[0], b[0]); });
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static i64 maxflow = {};
  inline static i64 mincost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Collecting1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void addEdge(int u, int v, i64 w, i64 c) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (cost[cntg] = c);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code08_Collecting1::tarjan(v);
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
        (sum[sccCnt] += arr[pop]);
      } while ((pop != u));
    }
  }
  static void condense(int s, int t) {
    j::fill(head, 1, (n + 1), 0);
    (cntg = 1);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (prefix[i] = (prefix[(i - 1)] + sum[i]));
    }
    int start = belong[1];
    i64 c = (prefix[sccCnt] - prefix[start]);
    Code08_Collecting1::addEdge(s, start, k, c);
    Code08_Collecting1::addEdge(start, s, 0, (-c));
    for (int i = 1; (i <= sccCnt); (i++)) {
      int out = (i + sccCnt);
      Code08_Collecting1::addEdge(i, out, 1, 0);
      Code08_Collecting1::addEdge(out, i, 0, 0);
      Code08_Collecting1::addEdge(i, out, k, sum[i]);
      Code08_Collecting1::addEdge(out, i, 0, (-sum[i]));
      (c = prefix[(i - 1)]);
      Code08_Collecting1::addEdge(out, t, k, c);
      Code08_Collecting1::addEdge(t, out, 0, (-c));
    }
    for (int i = 1; (i <= m); (i++)) {
      int u = belong[a[i]];
      int v = belong[b[i]];
      if ((u != v)) {
        (c = (prefix[(u - 1)] - prefix[v]));
        Code08_Collecting1::addEdge((u + sccCnt), v, k, c);
        Code08_Collecting1::addEdge(v, (u + sccCnt), 0, (-c));
      }
    }
  }
  static void dijkstra(int s) {
    for (int i = 1; (i <= n); (i++)) {
      (dist[i] = INF);
      (flow[i] = (-1));
      (vis[i] = false);
    }
    (flow[s] = INF);
    (dist[s] = 0);
    heap.clear();
    heap.add(Array<i64>{0, s});
    while ((!heap.isEmpty())) {
      Array<i64> cur = heap.poll();
      i64 d = cur[0];
      int u = static_cast<int>(cur[1]);
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          i64 w = weight[e];
          i64 c = ((cost[e] + h[u]) - h[v]);
          if ((((w > 0) && (!vis[v])) && (dist[v] > (d + c)))) {
            (dist[v] = (dist[u] + c));
            (flow[v] = jmin(w, flow[u]));
            (pre[v] = e);
            heap.add(Array<i64>{dist[v], v});
          }
        }
      }
    }
  }
  static bool ssp(int s, int t) {
    (maxflow = (mincost = 0));
    Code08_Collecting1::dijkstra(s);
    while ((flow[t] != (-1))) {
      (maxflow += flow[t]);
      for (int u = t; (u != s); (u = to[(pre[u] ^ 1)])) {
        (weight[pre[u]] -= flow[t]);
        (weight[(pre[u] ^ 1)] += flow[t]);
        (mincost += (flow[t] * cost[pre[u]]));
      }
      for (int i = 1; (i <= n); (i++)) {
        if ((dist[i] != INF)) {
          (h[i] += dist[i]);
        }
      }
      Code08_Collecting1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code08_Collecting1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code08_Collecting1::tarjan(i);
      }
    }
    (n = jshl(sccCnt, 1));
    int s = (++n);
    int t = (++n);
    Code08_Collecting1::condense(s, t);
    Code08_Collecting1::ssp(s, t);
    out.println(((k * prefix[sccCnt]) - mincost));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Collecting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 收集，java版
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc214_h
// 测试链接 : https://atcoder.jp/contests/abc214/tasks/abc214_h
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // tarjan算法求解强连通分量和缩点
        // 强连通分量的点权和
        // 强连通分量点权和的前缀和
        // 原图和费用流图，使用同一套链式前向星
                // 清空然后建立费用流图
                        // 第一个经过分量i的人取走全部物品，损失为0
                        // 后来的人仍可经过，每人少拿sum[i]个物品
                        // 在分量i停下，跳过编号1到i-1的分量
                                // 跨分量边满足 u >
v，从u走到v，跳过编号v+1到u-1的分量
        // 初始有容量的边，费用都是非负的，可以跳过spfa，不然会超时
                // 分量i的入点为i，出点为i+sccCnt
                // 每人先计入所有物品，再减去跳过和重复经过分量造成的总损失
        // 读写工具类
*/
