// Source: src/class210/Code05_NapkinPlan1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_NapkinPlan1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 12001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static Array<int> need = make_array<int>(MAXN);
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
  Code05_NapkinPlan1() {}
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
    bool negCycle = Code05_NapkinPlan1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code05_NapkinPlan1::dijkstra(s);
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
      Code05_NapkinPlan1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int days = in.nextInt();
    (n = jshl(days, 1));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    i64 total = 0;
    for (int i = 1; (i <= days); (i++)) {
      (need[i] = in.nextInt());
      (total += need[i]);
    }
    int buy = in.nextInt();
    int fastDays = in.nextInt();
    int fastCost = in.nextInt();
    int slowDays = in.nextInt();
    int slowCost = in.nextInt();
    for (int i = 1; (i <= days); (i++)) {
      int dirty = i;
      int clean = (days + i);
      Code05_NapkinPlan1::addEdge(s, dirty, need[i], 0);
      Code05_NapkinPlan1::addEdge(dirty, s, 0, 0);
      Code05_NapkinPlan1::addEdge(s, clean, need[i], buy);
      Code05_NapkinPlan1::addEdge(clean, s, 0, (-buy));
      Code05_NapkinPlan1::addEdge(clean, t, need[i], 0);
      Code05_NapkinPlan1::addEdge(t, clean, 0, 0);
      if ((i < days)) {
        Code05_NapkinPlan1::addEdge(dirty, (dirty + 1), total, 0);
        Code05_NapkinPlan1::addEdge((dirty + 1), dirty, 0, 0);
      }
      if ((fastDays <= (days - i))) {
        int back = (i + fastDays);
        Code05_NapkinPlan1::addEdge(dirty, (days + back), need[back], fastCost);
        Code05_NapkinPlan1::addEdge((days + back), dirty, 0, (-fastCost));
      }
      if ((slowDays <= (days - i))) {
        int back = (i + slowDays);
        Code05_NapkinPlan1::addEdge(dirty, (days + back), need[back], slowCost);
        Code05_NapkinPlan1::addEdge((days + back), dirty, 0, (-slowCost));
      }
    }
    Code05_NapkinPlan1::ssp(s, t);
    out.println(mincost);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_NapkinPlan1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 餐巾计划，java版
// 测试链接 : https://www.luogu.com.cn/problem/P1251
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 第i天用完后，有need[i]块脏餐巾可供后续使用
                        // 第i天购买新餐巾，最多只需买当天的需求量
                        // 满足第i天的需求，最大流时，每天的这条边都恰好流满
                        //
脏餐巾可以免费留到明天，连续走多条这样的边就能延期送洗
                        // 第i天送快洗，第i+fastDays天可用
                        // 第 i 天送慢洗，第 i + slowDays 天可用
        // 读写工具类
*/
