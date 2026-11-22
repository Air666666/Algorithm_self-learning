// Source: src/class209/Code03_Transport1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Transport1 {
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
  Code03_Transport1() {}
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
    bool negCycle = Code03_Transport1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code03_Transport1::dijkstra(s);
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
      Code03_Transport1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int a = in.nextInt();
    int b = in.nextInt();
    (n = (a + b));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    {
      int i = 1;
      int w = {};
      for (; (i <= a); (i++)) {
        (w = in.nextInt());
        Code03_Transport1::addEdge(s, i, w, 0);
        Code03_Transport1::addEdge(i, s, 0, 0);
      }
    }
    {
      int j = 1;
      int w = {};
      for (; (j <= b); (j++)) {
        (w = in.nextInt());
        Code03_Transport1::addEdge((a + j), t, w, 0);
        Code03_Transport1::addEdge(t, (a + j), 0, 0);
      }
    }
    {
      int i = 1;
      int c = {};
      for (; (i <= a); (i++)) {
        for (int j = 1; (j <= b); (j++)) {
          (c = in.nextInt());
          Code03_Transport1::addEdge(i, (a + j), INF, c);
          Code03_Transport1::addEdge((a + j), i, 0, (-c));
        }
      }
    }
    Code03_Transport1::ssp(s, t);
    int ans1 = mincost;
    for (int e = 2; (e <= cntg); (e += 2)) {
      (weight[e] += weight[(e ^ 1)]);
      (weight[(e ^ 1)] = 0);
      (cost[e] = (-cost[e]));
      (cost[(e ^ 1)] = (-cost[(e ^ 1)]));
    }
    Code03_Transport1::ssp(s, t);
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
  Code03_Transport1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 运输问题，java版
// 一共有a个仓库，每个仓库给定库存量，一共有b个商店，每个商店给定需求量
// 给定c[i][j]，表示从仓库i向商店j运输1单位货物的费用
// 题目保证所有仓库的库存量之和等于所有商店的需求量之和
// 将所有货物运送到商店，并恰好满足每个商店的需求
// 打印最小运输费用和最大运输费用
// 1 <= a、b <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P4015
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 超级源点s向仓库连边
                // 商店向超级汇点t连边
                // 仓库向商店连边，设置单位费用
                // 最小费用的求解
                // 每条边的单位费用取相反数，最小费用模版求解最大费用
                        // 恢复初始正向边的剩余容量
                // 最大费用的求解
                // 结果取相反数才是真实的最大费用
        // 读写工具类
*/
