// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/AT_abc247_g
// https://atcoder.jp/contests/abc247/tasks/abc247_g

// Source: src/class209/Code06_DreamTeam1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_DreamTeam1 {
  inline static int MAXN = 401;
  inline static int MAXM = 40001;
  inline static int OFFSET = 150;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
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
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_DreamTeam1() {}
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
    bool negCycle = Code06_DreamTeam1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    Code06_DreamTeam1::dijkstra(s);
    while ((flow[t] != (-1))) {
      (maxflow += flow[t]);
      for (int u = t; (u != s); (u = to[(pre[u] ^ 1)])) {
        (weight[pre[u]] -= flow[t]);
        (weight[(pre[u] ^ 1)] += flow[t]);
        (mincost += (flow[t] * cost[pre[u]]));
      }
      (ans[static_cast<int>(maxflow)] = (-mincost));
      for (int i = 1; (i <= n); (i++)) {
        if ((dist[i] != INF)) {
          (h[i] += dist[i]);
        }
      }
      Code06_DreamTeam1::dijkstra(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = jshl(OFFSET, 1));
    int s = (++n);
    int t = (++n);
    (cntg = 1);
    for (int i = 1; (i <= OFFSET); (i++)) {
      Code06_DreamTeam1::addEdge(s, i, 1, 0);
      Code06_DreamTeam1::addEdge(i, s, 0, 0);
      Code06_DreamTeam1::addEdge((i + OFFSET), t, 1, 0);
      Code06_DreamTeam1::addEdge(t, (i + OFFSET), 0, 0);
    }
    int k = in.nextInt();
    {
      int i = 1;
      int u = {};
      int v = {};
      int c = {};
      for (; (i <= k); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (c = in.nextInt());
        Code06_DreamTeam1::addEdge(u, (v + OFFSET), 1, (-c));
        Code06_DreamTeam1::addEdge((v + OFFSET), u, 0, c);
      }
    }
    Code06_DreamTeam1::ssp(s, t);
    out.println(maxflow);
    for (int i = 1; (i <= maxflow); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_DreamTeam1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 梦之队，java版
// 一共有k个人，第i个人所属大学为a[i]，擅长领域为b[i]，实力为c[i]
// 从中选出一些人组成队伍，要求任意两人的所属大学不同，擅长领域也不同
// 满足要求的情况下，计算队伍最多能选几个人，假设该值是q，打印该值
// 接下来q行，对于每个i = 1、2、...、q，打印恰好选出i个人时，队伍最大总实力
// 1 <= k <= 3 * 10^4
// 1 <= a[i]、b[i] <= 150
// 1 <= c[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc247_g
// 测试链接 : https://atcoder.jp/contests/abc247/tasks/abc247_g
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 每次增广，流量稳定加1，记录对应的最大总实力
                        // 单位费用设置成相反数，转化成求解最大费用
        // 读写工具类
*/
