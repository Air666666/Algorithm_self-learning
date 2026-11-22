// Source: src/class210/Code04_AirRoute1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_AirRoute1 {
  inline static int MAXN = 201;
  inline static int MAXM = 5001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static Array<String> name = make_array<String>(MAXN);
  inline static JMap<String, int> id = JMap<String, int>();
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int siz = {};
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
  Code04_AirRoute1() {}
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
    bool negCycle = Code04_AirRoute1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code04_AirRoute1::dijkstra(s);
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
      Code04_AirRoute1::dijkstra(s);
    }
    return false;
  }
  static void getPath(int cities) {
    int u = 1;
    (siz = 0);
    (ans[(++siz)] = u);
    while ((u != cities)) {
      for (int e = head[(cities + u)]; (e > 0); (e = nxt[e])) {
        if (((cost[e] == (-1)) && (weight[(e ^ 1)] > 0))) {
          (weight[(e ^ 1)]--);
          (weight[e]++);
          (u = to[e]);
          (ans[(++siz)] = u);
          break;
        }
      }
    }
    while ((u != 1)) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        if (((cost[e] == 1) && (weight[e] > 0))) {
          (u = (to[e] - cities));
          (ans[(++siz)] = u);
          break;
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int cities = in.nextInt();
    int flights = in.nextInt();
    (n = jshl(cities, 1));
    int s = 1;
    int t = n;
    (cntg = 1);
    for (int i = 1; (i <= cities); (i++)) {
      (name[i] = in.nextString());
      id.put(name[i], i);
      int cap = (((i == 1) || (i == cities)) ? 2 : 1);
      Code04_AirRoute1::addEdge(i, (cities + i), cap, 0);
      Code04_AirRoute1::addEdge((cities + i), i, 0, 0);
    }
    for (int i = 1; (i <= flights); (i++)) {
      int a = id.get(in.nextString());
      int b = id.get(in.nextString());
      int u = jmin(a, b);
      int v = jmax(a, b);
      Code04_AirRoute1::addEdge((cities + u), v, 2, (-1));
      Code04_AirRoute1::addEdge(v, (cities + u), 0, 1);
    }
    Code04_AirRoute1::ssp(s, t);
    if ((maxflow != 2)) {
      out.println(String(u"No Solution!"));
    } else {
      out.println((-mincost));
      Code04_AirRoute1::getPath(cities);
      for (int i = 1; (i <= siz); (i++)) {
        out.println(name[ans[i]]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_AirRoute1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 航空路线，java版
// 测试链接 : https://www.luogu.com.cn/problem/P2770
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 去程，从当前城市的出点找正向航线，取走一单位流
                // 返程，从当前城市的入点找反向航线，沿剩下的一单位流向西走
        // 读写工具类
*/
