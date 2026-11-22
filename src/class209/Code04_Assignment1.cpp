// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4014

// Source: src/class209/Code04_Assignment1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Assignment1 {
  inline static int MAXN = 301;
  inline static int MAXM = 20001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> cost = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> flow = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static JDeque<int> que = JDeque<int>();
  inline static Array<int> h = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return jcompare(a[0], b[0]); });
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static int maxflow = {};
  inline static int mincost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Assignment1() {}
  static void addEdge(int u, int v, int w, int c) {
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
      {
        int e = head[u];
        int v = {};
        int w = {};
        int c = {};
        for (; (e > 0); (e = nxt[e])) {
          (v = to[e]);
          (w = weight[e]);
          (c = cost[e]);
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
    heap.add(Array<int>{0, s});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int d = cur[0];
      int u = cur[1];
      if ((!vis[u])) {
        (vis[u] = true);
        {
          int e = head[u];
          int v = {};
          int w = {};
          int c = {};
          for (; (e > 0); (e = nxt[e])) {
            (v = to[e]);
            (w = weight[e]);
            (c = ((cost[e] + h[u]) - h[v]));
            if ((((w > 0) && (!vis[v])) && (dist[v] > (d + c)))) {
              (dist[v] = (dist[u] + c));
              (flow[v] = jmin(w, flow[u]));
              (pre[v] = e);
              heap.add(Array<int>{dist[v], v});
            }
          }
        }
      }
    }
  }
  static bool ssp(int s, int t) {
    bool negCycle = Code04_Assignment1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code04_Assignment1::dijkstra(s);
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
      Code04_Assignment1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int k = in.nextInt();
    (n = (k + k));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    for (int i = 1; (i <= k); (i++)) {
      Code04_Assignment1::addEdge(s, i, 1, 0);
      Code04_Assignment1::addEdge(i, s, 0, 0);
    }
    for (int j = 1; (j <= k); (j++)) {
      Code04_Assignment1::addEdge((k + j), t, 1, 0);
      Code04_Assignment1::addEdge(t, (k + j), 0, 0);
    }
    {
      int i = 1;
      int c = {};
      for (; (i <= k); (i++)) {
        for (int j = 1; (j <= k); (j++)) {
          (c = in.nextInt());
          Code04_Assignment1::addEdge(i, (k + j), INF, c);
          Code04_Assignment1::addEdge((k + j), i, 0, (-c));
        }
      }
    }
    Code04_Assignment1::ssp(s, t);
    int ans1 = mincost;
    for (int e = 2; (e <= cntg); (e += 2)) {
      (weight[e] += weight[(e ^ 1)]);
      (weight[(e ^ 1)] = 0);
      (cost[e] = (-cost[e]));
      (cost[(e ^ 1)] = (-cost[(e ^ 1)]));
    }
    Code04_Assignment1::ssp(s, t);
    int ans2 = (-mincost);
    out.println(ans1);
    out.println(ans2);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Assignment1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分配问题，java版
// 给定正整数n，表示有n个人、n件工作
// 每人恰好做一件工作，每件工作恰好分配给一个人
// 给定c[i][j]，表示第i号人做第j号工作产生的效益
// 打印最小总效益和最大总效益
// 1 <= n <= 50
// 0 <= c[i][j] <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P4014
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
