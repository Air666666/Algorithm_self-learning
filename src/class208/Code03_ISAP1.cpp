// Source: src/class208/Code03_ISAP1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ISAP1 {
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
  inline static Array<int> dis = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  inline static Array<int> cur = make_array<int>(MAXN);
  inline static Array<int> gap = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ISAP1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (limit[cntg] = w);
    (head[u] = cntg);
  }
  static void bfs(int t) {
    (gap[0] = 0);
    for (int i = 1; (i <= n); (i++)) {
      (gap[i] = 0);
      (dis[i] = n);
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
        if (((dis[v] == n) && (limit[(e ^ 1)] > 0))) {
          (dis[v] = (dis[u] + 1));
          (que[(++r)] = v);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (gap[dis[i]]++);
    }
  }
  static i64 dfs(int u, i64 rest, int s, int t) {
    if ((u == t)) {
      return rest;
    }
    i64 flow = 0;
    for (int e = cur[u]; ((e > 0) && (rest > 0)); (e = nxt[e])) {
      (cur[u] = e);
      int v = to[e];
      int lim = limit[e];
      if (((dis[u] == (dis[v] + 1)) && (lim > 0))) {
        i64 k = Code03_ISAP1::dfs(v, jmin(rest, lim), s, t);
        (flow += k);
        (rest -= k);
        (limit[e] -= k);
        (limit[(e ^ 1)] += k);
        if ((dis[s] == n)) {
          return flow;
        }
      }
    }
    if ((rest > 0)) {
      if (((--gap[dis[u]]) > 0)) {
        int lowest = (n - 1);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          if (((u != v) && (limit[e] > 0))) {
            (lowest = jmin(lowest, dis[v]));
          }
        }
        if (((u != s) && (flow > 0))) {
          (lowest = jmin(lowest, (dis[u] + 1)));
        }
        (dis[u] = (lowest + 1));
        (gap[dis[u]]++);
        (cur[u] = head[u]);
      } else {
        (dis[s] = n);
      }
    }
    return flow;
  }
  static i64 maxflow(int s, int t) {
    i64 ans = 0;
    Code03_ISAP1::bfs(t);
    while ((dis[s] != n)) {
      (ans += Code03_ISAP1::dfs(s, INF, s, t));
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
        Code03_ISAP1::addEdge(u, v, w);
        Code03_ISAP1::addEdge(v, u, 0);
      }
    }
    i64 ans = Code03_ISAP1::maxflow(s, t);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_ISAP1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// ISAP算法，java版
// 图中一共n个点，m条有向边，给定源点s和汇点t
// 给定每条有向边的起点、终点、容量
// 计算源点s到汇点t的网络最大流
// 1 <= n <= 200
// 1 <= m <= 5000
// 边的容量为非负整数
// 测试链接 : https://www.luogu.com.cn/problem/P3376
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                                // 隐蔽的坑点
                                //
非源点u在dfs中，有父节点，父节点标号为dis[u]+1
                                // 如果flow >
0，那么dfs返回后，才会增加u指向父节点的剩余容量
                                //
调整剩余容量是回到父节点之后才完成的，所以此时重标号，需要考虑这种情况
                                // 防止可用节点，没有考虑父节点的情况
        // 读写工具类
*/
