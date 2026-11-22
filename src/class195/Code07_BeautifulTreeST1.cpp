// Source: src/class195/Code07_BeautifulTreeST1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_BeautifulTreeST1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 41);
  inline static int MAXE = (MAXN * 201);
  inline static int MAXP = 17;
  inline static int MAXK = (MAXN * MAXP);
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
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> stjump = make_array<int>(MAXK);
  inline static int cntd = {};
  inline static Array<int> stout = make_array<int>(MAXK);
  inline static Array<int> stin = make_array<int>(MAXK);
  inline static int cntt = {};
  inline static Array<int> que = make_array<int>(MAXT);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_BeautifulTreeST1() {}
  static int idx(int u, int p) { return ((u * MAXP) + p); }
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
  static void build(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (dfn[u] = (++cntd));
    (siz[u] = 1);
    (stjump[Code07_BeautifulTreeST1::idx(u, 0)] = fa);
    (stout[Code07_BeautifulTreeST1::idx(u, 0)] = (++cntt));
    Code07_BeautifulTreeST1::addEdge2(u, cntt);
    Code07_BeautifulTreeST1::addEdge2(fa, cntt);
    (stin[Code07_BeautifulTreeST1::idx(u, 0)] = (++cntt));
    Code07_BeautifulTreeST1::addEdge2(cntt, u);
    Code07_BeautifulTreeST1::addEdge2(cntt, fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[Code07_BeautifulTreeST1::idx(u, p)] =
           stjump[Code07_BeautifulTreeST1::idx(
               stjump[Code07_BeautifulTreeST1::idx(u, (p - 1))], (p - 1))]);
      (stout[Code07_BeautifulTreeST1::idx(u, p)] = (++cntt));
      Code07_BeautifulTreeST1::addEdge2(
          stout[Code07_BeautifulTreeST1::idx(u, (p - 1))], cntt);
      Code07_BeautifulTreeST1::addEdge2(
          stout[Code07_BeautifulTreeST1::idx(
              stjump[Code07_BeautifulTreeST1::idx(u, (p - 1))], (p - 1))],
          cntt);
      (stin[Code07_BeautifulTreeST1::idx(u, p)] = (++cntt));
      Code07_BeautifulTreeST1::addEdge2(
          cntt, stin[Code07_BeautifulTreeST1::idx(u, (p - 1))]);
      Code07_BeautifulTreeST1::addEdge2(
          cntt,
          stin[Code07_BeautifulTreeST1::idx(
              stjump[Code07_BeautifulTreeST1::idx(u, (p - 1))], (p - 1))]);
    }
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if ((v != fa)) {
        Code07_BeautifulTreeST1::build(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static bool isAncestor(int a, int b) {
    return ((dfn[a] <= dfn[b]) && (dfn[b] < (dfn[a] + siz[a])));
  }
  static int kthAncestor(int x, int k) {
    for (int p = 0; (p < MAXP); (p++)) {
      if (((jshr(k, p) & 1) != 0)) {
        (x = stjump[Code07_BeautifulTreeST1::idx(x, p)]);
      }
    }
    return x;
  }
  static int nearest(int x, int y) {
    if (Code07_BeautifulTreeST1::isAncestor(y, x)) {
      return Code07_BeautifulTreeST1::kthAncestor(x, ((dep[x] - dep[y]) - 1));
    } else {
      return stjump[Code07_BeautifulTreeST1::idx(y, 0)];
    }
  }
  static void pathOut(int x, int y, int c) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    Code07_BeautifulTreeST1::addEdge2(y, c);
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[Code07_BeautifulTreeST1::idx(x, p)]] >= dep[y])) {
        Code07_BeautifulTreeST1::addEdge2(
            stout[Code07_BeautifulTreeST1::idx(x, p)], c);
        (x = stjump[Code07_BeautifulTreeST1::idx(x, p)]);
      }
    }
    if ((x == y)) {
      return;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ([&]() {
            auto jleft = stjump[Code07_BeautifulTreeST1::idx(x, p)];
            auto jright = stjump[Code07_BeautifulTreeST1::idx(y, p)];
            return (jleft != jright);
          }()) {
        Code07_BeautifulTreeST1::addEdge2(
            stout[Code07_BeautifulTreeST1::idx(x, p)], c);
        Code07_BeautifulTreeST1::addEdge2(
            stout[Code07_BeautifulTreeST1::idx(y, p)], c);
        (x = stjump[Code07_BeautifulTreeST1::idx(x, p)]);
        (y = stjump[Code07_BeautifulTreeST1::idx(y, p)]);
      }
    }
    Code07_BeautifulTreeST1::addEdge2(stout[Code07_BeautifulTreeST1::idx(x, 0)],
                                      c);
  }
  static void pathIn(int x, int y, int c) {
    if ((dep[x] < dep[y])) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    Code07_BeautifulTreeST1::addEdge2(c, y);
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[Code07_BeautifulTreeST1::idx(x, p)]] >= dep[y])) {
        Code07_BeautifulTreeST1::addEdge2(
            c, stin[Code07_BeautifulTreeST1::idx(x, p)]);
        (x = stjump[Code07_BeautifulTreeST1::idx(x, p)]);
      }
    }
    if ((x == y)) {
      return;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ([&]() {
            auto jleft = stjump[Code07_BeautifulTreeST1::idx(x, p)];
            auto jright = stjump[Code07_BeautifulTreeST1::idx(y, p)];
            return (jleft != jright);
          }()) {
        Code07_BeautifulTreeST1::addEdge2(
            c, stin[Code07_BeautifulTreeST1::idx(x, p)]);
        Code07_BeautifulTreeST1::addEdge2(
            c, stin[Code07_BeautifulTreeST1::idx(y, p)]);
        (x = stjump[Code07_BeautifulTreeST1::idx(x, p)]);
        (y = stjump[Code07_BeautifulTreeST1::idx(y, p)]);
      }
    }
    Code07_BeautifulTreeST1::addEdge2(c,
                                      stin[Code07_BeautifulTreeST1::idx(x, 0)]);
  }
  static void pathMin(int a, int b, int c) {
    if ((a != c)) {
      Code07_BeautifulTreeST1::pathIn(a, Code07_BeautifulTreeST1::nearest(a, c),
                                      c);
    }
    if ((b != c)) {
      Code07_BeautifulTreeST1::pathIn(b, Code07_BeautifulTreeST1::nearest(b, c),
                                      c);
    }
  }
  static void pathMax(int a, int b, int c) {
    if ((a != c)) {
      Code07_BeautifulTreeST1::pathOut(
          a, Code07_BeautifulTreeST1::nearest(a, c), c);
    }
    if ((b != c)) {
      Code07_BeautifulTreeST1::pathOut(
          b, Code07_BeautifulTreeST1::nearest(b, c), c);
    }
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
        (ans[u] = (++val));
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
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code07_BeautifulTreeST1::addEdge1(u, v);
        Code07_BeautifulTreeST1::addEdge1(v, u);
      }
    }
    Code07_BeautifulTreeST1::build(1, 1);
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
        if ((op == 1)) {
          Code07_BeautifulTreeST1::pathMin(a, b, c);
        } else {
          Code07_BeautifulTreeST1::pathMax(a, b, c);
        }
      }
    }
    bool check = Code07_BeautifulTreeST1::topo();
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
  Code07_BeautifulTreeST1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 美丽的树，倍增优化建图，java版
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
        // 原树
        // 关系图
        // 树上倍增
        // 倍增优化建图，出表和入表
        // 拓扑排序
        // 读写工具类
*/
