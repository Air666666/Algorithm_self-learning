// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3705

// Source: src/class210/Code07_Prom1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Prom1 {
  inline static int MAXN = 301;
  inline static int MAXM = 20001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int k = {};
  inline static int n = {};
  inline static int s = {};
  inline static int t = {};
  inline static Array<Array<int>> a = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> b = make_array<int>(MAXN, MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<i64> weight = make_array<i64>(jshl(MAXM, 1));
  inline static Array<double> cost = make_array<double>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<i64> flow = make_array<i64>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static JDeque<int> que = JDeque<int>();
  inline static Array<double> h = make_array<double>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static JHeap<Array<double>> heap = JHeap<Array<double>>(
      [](Array<double> a, Array<double> b) { return jcompare(a[0], b[0]); });
  inline static Array<double> dist = make_array<double>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static i64 maxflow = {};
  inline static double mincost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Prom1() {}
  static void addEdge(int u, int v, i64 w, double c) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (cost[cntg] = c);
    (head[u] = cntg);
  }
  static bool spfa(int s) {
    for (int i = 1; (i <= n); (i++)) {
      (h[i] = INF);
      (update[i] = 0);
      (enter[i] = false);
    }
    (h[s] = 0);
    (update[s] = 1);
    (enter[s] = true);
    que.clear();
    que.offer(s);
    while ((!que.isEmpty())) {
      int u = que.poll();
      (enter[u] = false);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        i64 w = weight[e];
        double c = cost[e];
        if (((w > 0) && (h[v] > (h[u] + c)))) {
          (h[v] = (h[u] + c));
          if ((!enter[v])) {
            if (((++update[v]) > n)) {
              return true;
            }
            que.offer(v);
            (enter[v] = true);
          }
        }
      }
    }
    return false;
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
    heap.add(Array<double>{static_cast<double>(0), static_cast<double>(s)});
    while ((!heap.isEmpty())) {
      Array<double> cur = heap.poll();
      double d = cur[0];
      int u = static_cast<int>(cur[1]);
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          i64 w = weight[e];
          double c = ((cost[e] + h[u]) - h[v]);
          if ((((w > 0) && (!vis[v])) && (dist[v] > (d + c)))) {
            (dist[v] = (dist[u] + c));
            (flow[v] = jmin(w, flow[u]));
            (pre[v] = e);
            heap.add(Array<double>{static_cast<double>(dist[v]),
                                   static_cast<double>(v)});
          }
        }
      }
    }
  }
  static bool ssp(int s, int t) {
    bool negCycle = Code07_Prom1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = 0);
    (mincost = 0);
    Code07_Prom1::dijkstra(s);
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
      Code07_Prom1::dijkstra(s);
    }
    return false;
  }
  static bool check(double x) {
    j::fill(head, 1, (n + 1), 0);
    (cntg = 1);
    for (int i = 1; (i <= k); (i++)) {
      Code07_Prom1::addEdge(s, i, 1, 0);
      Code07_Prom1::addEdge(i, s, 0, 0);
      Code07_Prom1::addEdge((k + i), t, 1, 0);
      Code07_Prom1::addEdge(t, (k + i), 0, 0);
      for (int j = 1; (j <= k); (j++)) {
        double c = (a[i][j] - (x * b[i][j]));
        Code07_Prom1::addEdge(i, (k + j), 1, (-c));
        Code07_Prom1::addEdge((k + j), i, 0, c);
      }
    }
    Code07_Prom1::ssp(s, t);
    return (mincost <= 0);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (k = in.nextInt());
    for (int i = 1; (i <= k); (i++)) {
      for (int j = 1; (j <= k); (j++)) {
        (a[i][j] = in.nextInt());
      }
    }
    for (int i = 1; (i <= k); (i++)) {
      for (int j = 1; (j <= k); (j++)) {
        (b[i][j] = in.nextInt());
      }
    }
    (n = jshl(k, 1));
    (s = (++n));
    (t = (++n));
    double l = 0;
    double r = 10000;
    for (int i = 1; (i <= 60); (i++)) {
      double x = jdiv((l + r), 2);
      if (Code07_Prom1::check(x)) {
        (l = x);
      } else {
        (r = x);
      }
    }
    out.printf(String(u"%.6f\n"), l);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Prom1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 新生舞会，java版
// 测试链接 : https://www.luogu.com.cn/problem/P3705
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
