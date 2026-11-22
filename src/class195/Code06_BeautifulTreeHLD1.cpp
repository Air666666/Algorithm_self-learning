// Source: src/class195/Code06_BeautifulTreeHLD1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_BeautifulTreeHLD1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 10);
  inline static int MAXE = (MAXN * 50);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head1 = make_array<int>(MAXN);
  inline static Array<int> next1 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt1 = {};
  inline static Array<int> indegree = make_array<int>(MAXT);
  inline static Array<int> head2 = make_array<int>(MAXT);
  inline static Array<int> next2 = make_array<int>(MAXE);
  inline static Array<int> to2 = make_array<int>(MAXE);
  inline static int cnt2 = {};
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int rootOut = {};
  inline static int rootIn = {};
  inline static int cntt = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> que = make_array<int>(MAXT);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_BeautifulTreeHLD1() {}
  static void addEdge1(int u, int v) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v) {
    (indegree[v]++);
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (head2[u] = cnt2);
  }
  static int buildOut(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code06_BeautifulTreeHLD1::buildOut(l, mid));
      (rs[rt] = Code06_BeautifulTreeHLD1::buildOut((mid + 1), r));
      Code06_BeautifulTreeHLD1::addEdge2(ls[rt], rt);
      Code06_BeautifulTreeHLD1::addEdge2(rs[rt], rt);
    }
    return rt;
  }
  static int buildIn(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code06_BeautifulTreeHLD1::buildIn(l, mid));
      (rs[rt] = Code06_BeautifulTreeHLD1::buildIn((mid + 1), r));
      Code06_BeautifulTreeHLD1::addEdge2(rt, ls[rt]);
      Code06_BeautifulTreeHLD1::addEdge2(rt, rs[rt]);
    }
    return rt;
  }
  static void xToRange(int jobx, int jobl, int jobr, int l, int r, int i) {
    if ((jobl > jobr)) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      Code06_BeautifulTreeHLD1::addEdge2(jobx, i);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code06_BeautifulTreeHLD1::xToRange(jobx, jobl, jobr, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code06_BeautifulTreeHLD1::xToRange(jobx, jobl, jobr, (mid + 1), r,
                                           rs[i]);
      }
    }
  }
  static void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if ((jobl > jobr)) {
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      Code06_BeautifulTreeHLD1::addEdge2(i, jobx);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code06_BeautifulTreeHLD1::rangeToX(jobl, jobr, jobx, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code06_BeautifulTreeHLD1::rangeToX(jobl, jobr, jobx, (mid + 1), r,
                                           rs[i]);
      }
    }
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head1[u];
      int v = {};
      for (; (e > 0); (e = next1[e])) {
        (v = to1[e]);
        if ((v != f)) {
          Code06_BeautifulTreeHLD1::dfs1(v, u);
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
    (dfn[u] = (++cntd));
    (seg[cntd] = u);
    if ((son[u] == 0)) {
      return;
    }
    Code06_BeautifulTreeHLD1::dfs2(son[u], t);
    {
      int e = head1[u];
      int v = {};
      for (; (e > 0); (e = next1[e])) {
        (v = to1[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code06_BeautifulTreeHLD1::dfs2(v, v);
        }
      }
    }
  }
  static void pathSet(int op, int x, int y, int z) {
    if ((op == 1)) {
      if (((x <= z) && (z <= y))) {
        Code06_BeautifulTreeHLD1::xToRange(z, x, (z - 1), 1, n, rootIn);
        Code06_BeautifulTreeHLD1::xToRange(z, (z + 1), y, 1, n, rootIn);
      } else {
        Code06_BeautifulTreeHLD1::xToRange(z, x, y, 1, n, rootIn);
      }
    } else {
      if (((x <= z) && (z <= y))) {
        Code06_BeautifulTreeHLD1::rangeToX(x, (z - 1), z, 1, n, rootOut);
        Code06_BeautifulTreeHLD1::rangeToX((z + 1), y, z, 1, n, rootOut);
      } else {
        Code06_BeautifulTreeHLD1::rangeToX(x, y, z, 1, n, rootOut);
      }
    }
  }
  static void link(int op, int a, int b, int c) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] < dep[top[b]])) {
        int tmp = a;
        (a = b);
        (b = tmp);
      }
      Code06_BeautifulTreeHLD1::pathSet(op, dfn[top[a]], dfn[a], dfn[c]);
      (a = fa[top[a]]);
    }
    [&]() {
      auto jargument_0 = op;
      auto jargument_1 = jmin(dfn[a], dfn[b]);
      auto jargument_2 = jmax(dfn[a], dfn[b]);
      auto jargument_3 = dfn[c];
      return Code06_BeautifulTreeHLD1::pathSet(jargument_0, jargument_1,
                                               jargument_2, jargument_3);
    }();
  }
  static bool topo() {
    int qi = 1;
    int qsiz = 0;
    for (int i = 1; (i <= cntt); (i++)) {
      if ((indegree[i] == 0)) {
        (que[(++qsiz)] = i);
      }
    }
    int val = 0;
    while ((qi <= qsiz)) {
      int u = que[(qi++)];
      if ((u <= n)) {
        (ans[seg[u]] = (++val));
      }
      for (int e = head2[u]; (e > 0); (e = next2[e])) {
        int v = to2[e];
        if (((--indegree[v]) == 0)) {
          (que[(++qsiz)] = v);
        }
      }
    }
    return (qsiz == cntt);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntt = n);
    (rootOut = Code06_BeautifulTreeHLD1::buildOut(1, n));
    (rootIn = Code06_BeautifulTreeHLD1::buildIn(1, n));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code06_BeautifulTreeHLD1::addEdge1(u, v);
        Code06_BeautifulTreeHLD1::addEdge1(v, u);
      }
    }
    Code06_BeautifulTreeHLD1::dfs1(1, 0);
    Code06_BeautifulTreeHLD1::dfs2(1, 1);
    {
      int i = 1;
      int op = {};
      int a = {};
      int b = {};
      int c = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        Code06_BeautifulTreeHLD1::link(op, a, b, c);
      }
    }
    bool check = Code06_BeautifulTreeHLD1::topo();
    if (check) {
      for (int i = 1; (i <= n); (i++)) {
        out.print(ans[i]);
        out.print(String(u" "));
      }
    } else {
      out.println((-1));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_BeautifulTreeHLD1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 美丽的树，树剖优化建图，java版
// 一共n个节点，给定n-1条无向边，所有节点组成一棵树，1号节点是根
// 你需要给每个节点赋值，但是不能破坏如下的m条关系，关系的格式如下
// 关系 1 a b c :
节点a到节点b的路径上，值最小的节点必须是节点c，输入保证c一定在路径上
// 关系 2 a b c :
节点a到节点b的路径上，值最大的节点必须是节点c，输入保证c一定在路径上
// 如果存在赋值方案，并且这些值是1到n的一个排列，打印一种方案即可，否则打印-1
// 2 <= n、m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1904F
// 测试链接 : https://codeforces.com/problemset/problem/1904/F
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原始的树
        // 关系图，x -> y，x的值严格小于y
        // 线段树优化建图，出树和入树
        // 树链剖分
        // 拓扑排序
        // 读写工具类
*/
