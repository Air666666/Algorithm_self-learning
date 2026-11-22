// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4722

// Source: src/class208/Code04_HLPP1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_HLPP1 {
  inline static int MAXN = 1201;
  inline static int MAXM = 120001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> limit = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<i64> excess = make_array<i64>(MAXN);
  inline static Array<int> dis = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> gap = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> bucket = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> nextActive = make_array<int>(MAXN);
  inline static int highest = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_HLPP1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (limit[cntg] = w);
    (head[u] = cntg);
  }
  static void addActive(int u) {
    (highest = jmax(highest, dis[u]));
    (nextActive[u] = bucket[dis[u]]);
    (bucket[dis[u]] = u);
  }
  static void pushFlow(int u, int v, int e, i64 k) {
    (excess[u] -= k);
    (excess[v] += k);
    (limit[e] -= k);
    (limit[(e ^ 1)] += k);
  }
  static void bfs(int t) {
    for (int i = 1; (i <= n); (i++)) {
      (dis[i] = (n + 1));
      (cur[i] = head[i]);
    }
    (dis[t] = 0);
    int l = 1;
    int r = 0;
    (que[(++r)] = t);
    while ((l <= r)) {
      int u = que[(l++)];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if (((dis[v] == (n + 1)) && (limit[(e ^ 1)] > 0))) {
          (dis[v] = (dis[u] + 1));
          (que[(++r)] = v);
        }
      }
    }
  }
  static void relabel(int u) {
    int h = dis[u];
    if ((gap[h] == 1)) {
      for (int i = 1; (i <= n); (i++)) {
        if (((dis[i] >= h) && (dis[i] < n))) {
          (gap[dis[i]]--);
          (dis[i] = (n + 1));
          (gap[dis[i]]++);
          (cur[i] = head[i]);
        }
      }
    } else {
      int lowest = (jshl(n, 1) - 1);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if (((u != v) && (limit[e] > 0))) {
          (lowest = jmin(lowest, dis[v]));
        }
      }
      (gap[h]--);
      (dis[u] = (lowest + 1));
      (gap[dis[u]]++);
      (cur[u] = head[u]);
    }
  }
  static void discharge(int s, int t) {
    int u = bucket[highest];
    (bucket[highest] = nextActive[u]);
    int e = cur[u];
    while ((excess[u] > 0)) {
      (cur[u] = e);
      if ((e > 0)) {
        int v = to[e];
        int lim = limit[e];
        if (((dis[u] == (dis[v] + 1)) && (lim > 0))) {
          if ((((v != s) && (v != t)) && (excess[v] == 0))) {
            Code04_HLPP1::addActive(v);
          }
          Code04_HLPP1::pushFlow(u, v, e, jmin(excess[u], lim));
        }
        (e = nxt[e]);
      } else {
        Code04_HLPP1::relabel(u);
        (e = cur[u]);
      }
    }
  }
  static i64 maxflow(int s, int t) {
    Code04_HLPP1::bfs(t);
    if ((dis[s] == (n + 1))) {
      return 0;
    }
    (dis[s] = n);
    for (int i = 1; (i <= n); (i++)) {
      (gap[dis[i]]++);
    }
    for (int e = head[s]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dis[v] < n)) {
        Code04_HLPP1::pushFlow(s, v, e, limit[e]);
      }
    }
    for (int i = 0; (i <= jshl(n, 1)); (i++)) {
      (bucket[i] = 0);
    }
    (highest = (-1));
    for (int i = 1; (i <= n); (i++)) {
      if ((((i != s) && (i != t)) && (excess[i] > 0))) {
        Code04_HLPP1::addActive(i);
      }
    }
    while ((highest >= 0)) {
      if ((bucket[highest] == 0)) {
        (highest--);
      } else {
        Code04_HLPP1::discharge(s, t);
      }
    }
    return excess[t];
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
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code04_HLPP1::addEdge(u, v, w);
        Code04_HLPP1::addEdge(v, u, 0);
      }
    }
    i64 ans = Code04_HLPP1::maxflow(s, t);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_HLPP1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// HLPP算法，java版
// 图中一共n个点，m条有向边，给定源点s和汇点t
// 给定每条有向边的起点、终点、容量
// 计算源点s到汇点t的网络最大流
// 1 <= n <= 1200
// 1 <= m <= 120000
// 边的容量为非负整数
// 测试链接 : https://www.luogu.com.cn/problem/P4722
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 出现计数从1到0，必是向汇点推流的阶段
                        // 触发gap优化，标号在[h, n-1]的所有点，改标号为n+1
                        // 这些点一定包含u，但是一定不包含源点和汇点
                        // 没有出现旧标号层的计数从1变为0，那么提升u的标号即可
                        // 新标号 = 可用邻居的最小标号 + 1
                                // 有边可用继续尝试
                                // 无边可用提高标号
        // 读写工具类
*/
