// Source: src/class200/Code06_CactusShortestPaths1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_CactusShortestPaths1 {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(MAXN);
  inline static Array<int> to1 = make_array<int>(MAXN);
  inline static Array<int> weight1 = make_array<int>(MAXN);
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(MAXN);
  inline static Array<int> to2 = make_array<int>(MAXN);
  inline static Array<int> weight2 = make_array<int>(MAXN);
  inline static int cnt2 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int stasiz = {};
  inline static Array<int> fromWeight = make_array<int>(MAXN);
  inline static Array<int> cycleLen = make_array<int>(MAXN);
  inline static Array<int> cycleSum = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> len = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_CactusShortestPaths1() {}
  static void addEdge1(int u, int v, int w) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, int w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static void cycleLink(int u, int v) {
    (cntn++);
    (cycleSum[cntn] = fromWeight[u]);
    Code06_CactusShortestPaths1::addEdge2(u, cntn, 0);
    int tmp = stasiz;
    int pop = {};
    do {
      (pop = sta[(tmp--)]);
      (cycleLen[pop] = cycleSum[cntn]);
      (cycleSum[cntn] += fromWeight[pop]);
    } while ((pop != v));
    do {
      (pop = sta[(stasiz--)]);
      Code06_CactusShortestPaths1::addEdge2(
          cntn, pop, jmin(cycleLen[pop], (cycleSum[cntn] - cycleLen[pop])));
    } while ((pop != v));
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++stasiz)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to1[e];
      int w = weight1[e];
      if ((dfn[v] == 0)) {
        Code06_CactusShortestPaths1::tarjan(v, e);
        (fromWeight[v] = w);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (stasiz--);
          Code06_CactusShortestPaths1::addEdge2(u, v, w);
        } else {
          Code06_CactusShortestPaths1::cycleLink(u, v);
        }
      } else if ((dfn[v] < dfn[u])) {
        (fromWeight[v] = w);
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void dfs1(int u, int f, int l) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    (len[u] = l);
    {
      int e = head2[u];
      int v = {};
      for (; (e > 0); (e = next2[e])) {
        (v = to2[e]);
        if ((v != f)) {
          Code06_CactusShortestPaths1::dfs1(v, u, (len[u] + weight2[e]));
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] != 0)) {
      Code06_CactusShortestPaths1::dfs2(son[u], t);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if (((v != fa[u]) && (v != son[u]))) {
        Code06_CactusShortestPaths1::dfs2(v, v);
      }
    }
  }
  static int lca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
  }
  static int find(int x, int square) {
    int pre = 0;
    while ((top[x] != top[square])) {
      (pre = top[x]);
      (x = fa[pre]);
    }
    return ((x == square) ? pre : son[square]);
  }
  static int query(int x, int y) {
    int ans = 0;
    int xylca = Code06_CactusShortestPaths1::lca(x, y);
    if ((xylca <= n)) {
      (ans = ((len[x] + len[y]) - jshl(len[xylca], 1)));
    } else {
      int fx = Code06_CactusShortestPaths1::find(x, xylca);
      int fy = Code06_CactusShortestPaths1::find(y, xylca);
      (ans = (((len[x] + len[y]) - len[fx]) - len[fy]));
      int small = jmin(cycleLen[fx], cycleLen[fy]);
      int big = jmax(cycleLen[fx], cycleLen[fy]);
      (ans += jmin((big - small), (cycleSum[xylca] - (big - small))));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (cntn = n);
    (cnt1 = 1);
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code06_CactusShortestPaths1::addEdge1(u, v, w);
        Code06_CactusShortestPaths1::addEdge1(v, u, w);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code06_CactusShortestPaths1::tarjan(i, 0);
      }
    }
    Code06_CactusShortestPaths1::dfs1(1, 0, 0);
    Code06_CactusShortestPaths1::dfs2(1, 1);
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        out.println(Code06_CactusShortestPaths1::query(x, y));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_CactusShortestPaths1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌最短路，java版
// 给定n个点、m条边的仙人掌图，每条边有边权，没有自环，没有重边
// 一共q条查询，每条查询格式为 x y，查询点x和点y之间的最短路距离
// 1 <= n、q <= 10^4
// 1 <= m <= 2 * 10^4
// 1 <= 边权 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5236
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原图
        // 圆方树，单向边
        // tarjan算法求圆方树
        // 环的信息
        // 树链剖分
        // len[u] : 圆方树上从头节点到u的长度
                        // 因为是单向边，所以不用判断 v != f，但这里保留模版写法
                        // 因为是单向边，所以不用判断 v !=
fa[u]，但这里保留模版写法
        // 读写工具类
*/
