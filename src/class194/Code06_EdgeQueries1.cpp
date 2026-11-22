// Source: src/class194/Code06_EdgeQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_EdgeQueries1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXM, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> next2 = make_array<int>(jshl(MAXM, 2));
  inline static Array<int> to2 = make_array<int>(jshl(MAXM, 2));
  inline static int cnt2 = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> dep = make_array<int>(jshl(MAXN, 1));
  inline static Array<Array<int>> stjump = make_array<int>(jshl(MAXN, 1), MAXP);
  inline static Array<int> edgeCnt = make_array<int>(jshl(MAXN, 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_EdgeQueries1() {}
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (head2[u] = cnt2);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((dfn[v] == 0)) {
        Code06_EdgeQueries1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          (cntn++);
          Code06_EdgeQueries1::addEdge2(cntn, u);
          Code06_EdgeQueries1::addEdge2(u, cntn);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            Code06_EdgeQueries1::addEdge2(cntn, pop);
            Code06_EdgeQueries1::addEdge2(pop, cntn);
          } while ((pop != v));
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code06_EdgeQueries1::dfs(v, u);
      }
    }
  }
  static int getLca(int x, int y) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[x][p]] >= dep[y])) {
        (x = stjump[x][p]);
      }
    }
    if ((x == y)) {
      return x;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[x][p] != stjump[y][p])) {
        (x = stjump[x][p]);
        (y = stjump[y][p]);
      }
    }
    return stjump[x][0];
  }
  static void dfsCnt(int u, int fa) {
    (edgeCnt[u] += edgeCnt[fa]);
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code06_EdgeQueries1::dfsCnt(v, u);
      }
    }
  }
  static void buildEdgeCnt() {
    for (int i = 1; (i <= m); (i++)) {
      int fa = stjump[a[i]][0];
      int fb = stjump[b[i]][0];
      if (((fa == fb) || (stjump[fa][0] == b[i]))) {
        (edgeCnt[fa]++);
      } else {
        (edgeCnt[fb]++);
      }
    }
    for (int i = (n + 1); (i <= cntn); (i++)) {
      if ((edgeCnt[i] == 1)) {
        (edgeCnt[i] = 0);
      }
    }
    Code06_EdgeQueries1::dfsCnt(1, 0);
  }
  static int query(int x, int y) {
    int xylca = Code06_EdgeQueries1::getLca(x, y);
    int lcafa = stjump[xylca][0];
    return (((edgeCnt[x] + edgeCnt[y]) - edgeCnt[xylca]) - edgeCnt[lcafa]);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntn = n);
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code06_EdgeQueries1::addEdge1(a[i], b[i]);
      Code06_EdgeQueries1::addEdge1(b[i], a[i]);
    }
    Code06_EdgeQueries1::tarjan(1);
    Code06_EdgeQueries1::dfs(1, 0);
    Code06_EdgeQueries1::buildEdgeCnt();
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        out.println(Code06_EdgeQueries1::query(x, y));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_EdgeQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边的查询，java版
// 给定一张无向图，一共n个点、m条边，所有点保证连通
// 一共q条查询，格式 x y，含义如下
// 所有从x到y的简单路径上出现的边中，统计有多少条边满足
// 如果移除该边，x和y仍然可以互相到达，打印这个数量
// 1 <= n、m、q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1763F
// 测试链接 : https://codeforces.com/problemset/problem/1763/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
