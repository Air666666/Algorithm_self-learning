// Source: src/class209/Code01_SSP_SPFA_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SSP_SPFA_1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 50001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> cost = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> flow = make_array<int>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static JDeque<int> que = JDeque<int>();
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static int maxflow = {};
  inline static int mincost = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SSP_SPFA_1() {}
  static void addEdge(int u, int v, int w, int c) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (cost[cntg] = c);
    (head[u] = cntg);
  }
  static bool spfa(int s) {
    for (int i = 1; (i <= n); (i++)) {
      (dist[i] = INF);
      (update[i] = 0);
      (enter[i] = false);
      (flow[i] = (-1));
    }
    (dist[s] = 0);
    (update[s] = 1);
    (enter[s] = true);
    (flow[s] = INF);
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
          if (((w > 0) && (dist[v] > (dist[u] + c)))) {
            (dist[v] = (dist[u] + c));
            (flow[v] = jmin(w, flow[u]));
            (pre[v] = e);
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
  static bool ssp(int s, int t) {
    bool negCycle = Code01_SSP_SPFA_1::spfa(s);
    if (negCycle) {
      return true;
    }
    (maxflow = (mincost = 0));
    while ((flow[t] != (-1))) {
      (maxflow += flow[t]);
      for (int u = t; (u != s); (u = to[(pre[u] ^ 1)])) {
        (weight[pre[u]] -= flow[t]);
        (weight[(pre[u] ^ 1)] += flow[t]);
        (mincost += (flow[t] * cost[pre[u]]));
      }
      Code01_SSP_SPFA_1::spfa(s);
    }
    return false;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    int s = in.nextInt();
    int t = in.nextInt();
    (cntg = 1);
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      int c = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        (c = in.nextInt());
        Code01_SSP_SPFA_1::addEdge(u, v, w, c);
        Code01_SSP_SPFA_1::addEdge(v, u, 0, (-c));
      }
    }
    if (Code01_SSP_SPFA_1::ssp(s, t)) {
      out.println((-1));
    } else {
      out.println(((maxflow + String(u" ")) + mincost));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_SSP_SPFA_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 费用流简单模版，SSP + SPFA，java版
// 一共n个点、m条有向边，给定源点s、汇点t
// 每条有向边给定起点u、终点v、容量w、单位费用c
// 单位费用表示，该边每通过1单位流量，产生c的费用
// 求从s到t的最大流，并在流量最大的前提下，使总费用最小
// 打印最大流数值，以及该最大流对应的最小费用
// 1 <= n <= 5 * 10^3
// 1 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P3381
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // weight代表剩余容量、cost代表单位费用
        // ssp算法，单路增广，所需的瓶颈流量和前驱边
        // ssp算法，计算费用最小的增广路，spfa算法
        // 返回是否发现从s可达的负费用环
        // 返回是否发现从s可达的负费用环
        // 如果初始时没有负费用环，那么后续每次增广都没有，课上解释了
        // 读写工具类
*/
