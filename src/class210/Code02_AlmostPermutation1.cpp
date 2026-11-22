// Source: src/class210/Code02_AlmostPermutation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_AlmostPermutation1 {
  inline static int MAXN = 201;
  inline static int MAXM = 6001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static Array<int> low = make_array<int>(MAXN);
  inline static Array<int> high = make_array<int>(MAXN);
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
  Code02_AlmostPermutation1() {}
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
    bool negCycle = Code02_AlmostPermutation1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code02_AlmostPermutation1::dijkstra(s);
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
      Code02_AlmostPermutation1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int len = in.nextInt();
    int q = in.nextInt();
    (n = jshl(len, 1));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    for (int i = 1; (i <= len); (i++)) {
      (low[i] = 1);
      (high[i] = len);
    }
    {
      int k = 1;
      int op = {};
      int l = {};
      int r = {};
      int v = {};
      for (; (k <= q); (k++)) {
        (op = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        (v = in.nextInt());
        for (int i = l; (i <= r); (i++)) {
          if ((op == 1)) {
            (low[i] = jmax(low[i], v));
          } else {
            (high[i] = jmin(high[i], v));
          }
        }
      }
    }
    for (int i = 1; (i <= len); (i++)) {
      Code02_AlmostPermutation1::addEdge(s, i, 1, 0);
      Code02_AlmostPermutation1::addEdge(i, s, 0, 0);
      for (int v = low[i]; (v <= high[i]); (v++)) {
        Code02_AlmostPermutation1::addEdge(i, (len + v), 1, 0);
        Code02_AlmostPermutation1::addEdge((len + v), i, 0, 0);
      }
    }
    for (int v = 1; (v <= len); (v++)) {
      for (int k = 1; (k <= len); (k++)) {
        int c = ((2 * k) - 1);
        Code02_AlmostPermutation1::addEdge((len + v), t, 1, c);
        Code02_AlmostPermutation1::addEdge(t, (len + v), 0, (-c));
      }
    }
    Code02_AlmostPermutation1::ssp(s, t);
    int ans = ((maxflow == len) ? mincost : (-1));
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_AlmostPermutation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 近似排列，java版
// 测试链接 : https://www.luogu.com.cn/problem/CF863F
// 测试链接 : https://codeforces.com/problemset/problem/863/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
