// Source: src/class210/Code06_MultisetIntervals1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MultisetIntervals1 {
  inline static int MAXN = 2001;
  inline static int MAXM = 2001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static Array<int> l = make_array<int>(MAXN);
  inline static Array<int> r = make_array<int>(MAXN);
  inline static Array<int> sortv = make_array<int>(jshl(MAXN, 1));
  inline static int cntv = {};
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
  Code06_MultisetIntervals1() {}
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
    bool negCycle = Code06_MultisetIntervals1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code06_MultisetIntervals1::dijkstra(s);
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
      Code06_MultisetIntervals1::dijkstra(s);
    }
    return false;
  }
  static void build(int intervals) {
    for (int i = 1; (i <= intervals); (i++)) {
      (sortv[(++cntv)] = l[i]);
      (sortv[(++cntv)] = r[i]);
    }
    j::sort(sortv, 1, (cntv + 1));
    int len = 1;
    for (int i = 2; (i <= cntv); (i++)) {
      if ((sortv[len] != sortv[i])) {
        (sortv[(++len)] = sortv[i]);
      }
    }
    (cntv = len);
  }
  static int kth(int num) {
    int l = 1;
    int r = cntv;
    int mid = {};
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if ((sortv[mid] == num)) {
        return mid;
      } else if ((sortv[mid] < num)) {
        (l = (mid + 1));
      } else {
        (r = (mid - 1));
      }
    }
    return (-1);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int intervals = in.nextInt();
    int k = in.nextInt();
    for (int i = 1; (i <= intervals); (i++)) {
      (l[i] = in.nextInt());
      (r[i] = in.nextInt());
    }
    Code06_MultisetIntervals1::build(intervals);
    (n = cntv);
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    Code06_MultisetIntervals1::addEdge(s, 1, k, 0);
    Code06_MultisetIntervals1::addEdge(1, s, 0, 0);
    Code06_MultisetIntervals1::addEdge(cntv, t, k, 0);
    Code06_MultisetIntervals1::addEdge(t, cntv, 0, 0);
    for (int i = 1; (i < cntv); (i++)) {
      Code06_MultisetIntervals1::addEdge(i, (i + 1), k, 0);
      Code06_MultisetIntervals1::addEdge((i + 1), i, 0, 0);
    }
    for (int i = 1; (i <= intervals); (i++)) {
      int u = Code06_MultisetIntervals1::kth(l[i]);
      int v = Code06_MultisetIntervals1::kth(r[i]);
      int c = (r[i] - l[i]);
      Code06_MultisetIntervals1::addEdge(u, v, 1, (-c));
      Code06_MultisetIntervals1::addEdge(v, u, 0, c);
    }
    Code06_MultisetIntervals1::ssp(s, t);
    out.println((-mincost));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_MultisetIntervals1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长k可重区间集，java版
// 测试链接 : https://www.luogu.com.cn/problem/P3358
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 最多送k单位流，每单位流对应一组互不重叠的区间
                // 沿数轴向右走，不选区间时费用为0
                // 每个输入区间单独连一条容量为1的边，即使端点相同也分别连边
        // 读写工具类
*/
