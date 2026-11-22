// Source: src/class210/Code09_Communication1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_Communication1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 50001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int k = {};
  inline static int n = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> idx = make_array<int>(MAXN);
  inline static Array<int> tmp = make_array<int>(MAXN);
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
  Code09_Communication1() {}
  static void addEdge(int u, int v, i64 w, i64 c) {
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
        i64 c = cost[e];
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
    bool negCycle = Code09_Communication1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code09_Communication1::dijkstra(s);
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
      Code09_Communication1::dijkstra(s);
    }
    return false;
  }
  static void merge(int l, int mid, int r) {
    int p1 = l;
    int p2 = (mid + 1);
    int ti = 0;
    while (((p1 <= mid) && (p2 <= r))) {
      if ((arr[idx[p1]] <= arr[idx[p2]])) {
        (tmp[(++ti)] = idx[(p1++)]);
      } else {
        (tmp[(++ti)] = idx[(p2++)]);
      }
    }
    while ((p1 <= mid)) {
      (tmp[(++ti)] = idx[(p1++)]);
    }
    while ((p2 <= r)) {
      (tmp[(++ti)] = idx[(p2++)]);
    }
    int last = arr[tmp[1]];
    int cur = (++n);
    {
      int i = l;
      int j = 1;
      for (; (i <= r); (i++), (j++)) {
        int u = tmp[j];
        if ((arr[u] != last)) {
          int pre = cur;
          (cur = (++n));
          i64 c = (static_cast<i64>(arr[u]) - last);
          Code09_Communication1::addEdge(pre, cur, k, c);
          Code09_Communication1::addEdge(cur, pre, 0, (-c));
          Code09_Communication1::addEdge(cur, pre, k, c);
          Code09_Communication1::addEdge(pre, cur, 0, (-c));
          (last = arr[u]);
        }
        if ((u > mid)) {
          Code09_Communication1::addEdge(u, cur, 1, 0);
          Code09_Communication1::addEdge(cur, u, 0, 0);
        } else {
          Code09_Communication1::addEdge(cur, (k + u), 1, 0);
          Code09_Communication1::addEdge((k + u), cur, 0, 0);
        }
        (idx[i] = u);
      }
    }
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code09_Communication1::cdq(l, mid);
    Code09_Communication1::cdq((mid + 1), r);
    Code09_Communication1::merge(l, mid, r);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (k = in.nextInt());
    int w = in.nextInt();
    (n = jshl(k, 1));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    for (int i = 1; (i <= k); (i++)) {
      (arr[i] = in.nextInt());
      (idx[i] = i);
      Code09_Communication1::addEdge(s, i, 1, 0);
      Code09_Communication1::addEdge(i, s, 0, 0);
      Code09_Communication1::addEdge(i, t, 1, w);
      Code09_Communication1::addEdge(t, i, 0, (-w));
      Code09_Communication1::addEdge((k + i), t, 1, 0);
      Code09_Communication1::addEdge(t, (k + i), 0, 0);
    }
    Code09_Communication1::cdq(1, k);
    Code09_Communication1::ssp(s, t);
    out.println(mincost);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_Communication1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 通信，java版
// 测试链接 : https://www.luogu.com.cn/problem/P5331
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // tmp已按频段排好序，先建第一个频段的虚点
                                //
相邻频段之间双向通行，每个方向各有一条残量反向边
                        // 按原下标判断，右半区进链，左半区出链
        // 读写工具类
*/
