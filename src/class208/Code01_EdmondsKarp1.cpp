// Source: src/class208/Code01_EdmondsKarp1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_EdmondsKarp1 {
  inline static int MAXN = 201;
  inline static int MAXM = 5001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> limit = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<i64> flow = make_array<i64>(MAXN);
  inline static Array<int> pre = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_EdmondsKarp1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (limit[cntg] = w);
    (head[u] = cntg);
  }
  static void bfs(int s, int t) {
    j::fill(flow, 1, (n + 1), (-1));
    (flow[s] = INF);
    int l = 1;
    int r = 0;
    (que[(++r)] = s);
    while ((l <= r)) {
      int u = que[(l++)];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        int lim = limit[e];
        if (((lim > 0) && (flow[v] == (-1)))) {
          (flow[v] = jmin(flow[u], lim));
          (pre[v] = e);
          if ((v == t)) {
            return;
          }
          (que[(++r)] = v);
        }
      }
    }
  }
  static i64 maxflow(int s, int t) {
    i64 ans = 0;
    Code01_EdmondsKarp1::bfs(s, t);
    while ((flow[t] != (-1))) {
      (ans += flow[t]);
      for (int u = t; (u != s); (u = to[(pre[u] ^ 1)])) {
        (limit[pre[u]] -= flow[t]);
        (limit[(pre[u] ^ 1)] += flow[t]);
      }
      Code01_EdmondsKarp1::bfs(s, t);
    }
    return ans;
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
        Code01_EdmondsKarp1::addEdge(u, v, w);
        Code01_EdmondsKarp1::addEdge(v, u, 0);
      }
    }
    i64 ans = Code01_EdmondsKarp1::maxflow(s, t);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_EdmondsKarp1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Edmonds-Karp算法，java版
// 图中一共n个点，m条有向边，给定源点s和汇点t
// 给定每条有向边的起点、终点、容量
// 计算源点s到汇点t的网络最大流
// 1 <= n <= 200
// 1 <= m <= 5000
// 边的容量为非负整数
// 测试链接 : https://www.luogu.com.cn/problem/P3376
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
