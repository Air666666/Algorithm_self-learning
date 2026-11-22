// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2173

// Source: src/class201/Code07_Network1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Network1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int C = {};
  inline static int q = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> maxv = make_array<int>(MAXN);
  inline static Array<int> nodeDegree = make_array<int>(MAXN);
  inline static JMap<i64, int> edgeColor = JMap<i64, int>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Network1() {}
  static void up(int x) {
    (maxv[x] = jmax(jmax(maxv[ls[x]], maxv[rs[x]]), arr[x]));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void reverse(int x) {
    if ((x != 0)) {
      int tmp = ls[x];
      (ls[x] = rs[x]);
      (rs[x] = tmp);
      (rev[x] = (!rev[x]));
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code07_Network1::reverse(ls[x]);
      Code07_Network1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code07_Network1::lr(x) == 0)) {
      (ls[f] = rs[x]);
      if ((ls[f] != 0)) {
        (fa[ls[f]] = f);
      }
      (rs[x] = f);
    } else {
      (rs[f] = ls[x]);
      if ((rs[f] != 0)) {
        (fa[rs[f]] = f);
      }
      (ls[x] = f);
    }
    if ((!Code07_Network1::isroot(f))) {
      if ((Code07_Network1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code07_Network1::up(f);
    Code07_Network1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code07_Network1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code07_Network1::down(sta[(siz--)]);
    }
    while ((!Code07_Network1::isroot(x))) {
      int f = fa[x];
      if ((!Code07_Network1::isroot(f))) {
        if ([&]() {
              auto jleft = Code07_Network1::lr(x);
              auto jright = Code07_Network1::lr(f);
              return (jleft == jright);
            }()) {
          Code07_Network1::rotate(f);
        } else {
          Code07_Network1::rotate(x);
        }
      }
      Code07_Network1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code07_Network1::splay(x);
      (rs[x] = y);
      Code07_Network1::up(x);
    }
  }
  static void makeroot(int x) {
    Code07_Network1::access(x);
    Code07_Network1::splay(x);
    Code07_Network1::reverse(x);
  }
  static int findroot(int x) {
    Code07_Network1::access(x);
    Code07_Network1::splay(x);
    Code07_Network1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code07_Network1::down(x);
    }
    Code07_Network1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code07_Network1::makeroot(x);
    Code07_Network1::access(y);
    Code07_Network1::splay(y);
  }
  static void link(int x, int y) {
    Code07_Network1::makeroot(x);
    if ((Code07_Network1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code07_Network1::makeroot(x);
    if (((((Code07_Network1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code07_Network1::up(x);
    }
  }
  static int node(int c, int x) { return ((c * n) + x); }
  static i64 edge(int x, int y) {
    int a = jmin(x, y);
    int b = jmax(x, y);
    return (jshl((1LL * a), 32) | b);
  }
  static void connect(int c, int x, int y) {
    int u = Code07_Network1::node(c, x);
    int v = Code07_Network1::node(c, y);
    (nodeDegree[u]++);
    (nodeDegree[v]++);
    Code07_Network1::link(u, v);
    edgeColor.put(Code07_Network1::edge(x, y), c);
  }
  static void disconnect(int c, int x, int y) {
    int u = Code07_Network1::node(c, x);
    int v = Code07_Network1::node(c, y);
    (nodeDegree[u]--);
    (nodeDegree[v]--);
    Code07_Network1::cut(u, v);
    edgeColor.remove(Code07_Network1::edge(x, y));
  }
  static void updateNode(int x, int v) {
    for (int c = 0; (c < C); (c++)) {
      int cur = Code07_Network1::node(c, x);
      Code07_Network1::splay(cur);
      (arr[cur] = v);
      Code07_Network1::up(cur);
    }
  }
  static int updateEdge(int x, int y, int c) {
    Box<int> pre = edgeColor.get(Code07_Network1::edge(x, y));
    if ((pre == nullptr)) {
      return 3;
    }
    int p = pre;
    if ((p == c)) {
      return 4;
    }
    if (((nodeDegree[Code07_Network1::node(c, x)] >= 2) ||
         (nodeDegree[Code07_Network1::node(c, y)] >= 2))) {
      return 1;
    }
    if ([&]() {
          auto jleft = Code07_Network1::findroot(Code07_Network1::node(c, x));
          auto jright = Code07_Network1::findroot(Code07_Network1::node(c, y));
          return (jleft == jright);
        }()) {
      return 2;
    }
    Code07_Network1::disconnect(p, x, y);
    Code07_Network1::connect(c, x, y);
    return 4;
  }
  static int query(int c, int x, int y) {
    int u = Code07_Network1::node(c, x);
    int v = Code07_Network1::node(c, y);
    if ([&]() {
          auto jleft = Code07_Network1::findroot(u);
          auto jright = Code07_Network1::findroot(v);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    Code07_Network1::split(u, v);
    return maxv[v];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (C = in.nextInt());
    (q = in.nextInt());
    {
      int i = 1;
      int v = {};
      for (; (i <= n); (i++)) {
        (v = in.nextInt());
        for (int c = 0; (c < C); (c++)) {
          int cur = Code07_Network1::node(c, i);
          (arr[cur] = v);
          (maxv[cur] = v);
        }
      }
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      int c = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (c = in.nextInt());
        Code07_Network1::connect(c, x, y);
      }
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int c = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        if ((op == 0)) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code07_Network1::updateNode(x, y);
        } else if ((op == 1)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (c = in.nextInt());
          int ans = Code07_Network1::updateEdge(x, y, c);
          if ((ans == 1)) {
            out.println(String(u"Error 1."));
          }
          if ((ans == 2)) {
            out.println(String(u"Error 2."));
          }
          if ((ans == 3)) {
            out.println(String(u"No such edge."));
          }
          if ((ans == 4)) {
            out.println(String(u"Success."));
          }
        } else {
          (c = in.nextInt());
          (x = in.nextInt());
          (y = in.nextInt());
          out.println(Code07_Network1::query(c, x, y));
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Network1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 网络，java版
// 无向图中有n个点，点有点权，有m条边，边有颜色，颜色总数量为C，颜色的数值0 ~
C-1
// 无向图保证没有重边和自环，并且始终满足如下两个性质
// 性质1，对于任意节点连出去的边中，相同颜色的边不超过两条
// 性质2，图中不存在同色的环，指相同颜色的边构成的环
// 一共有q条操作，类型如下
// 操作 0 x y   : 点x的点权变成y
// 操作 2 c x y : 颜色c的边构成的图中，打印x到y路径上的点权最大值，不连通打印-1
// 操作 1 x y c : 点x到点y的直接边，颜色改成c，下面是具体说明
// 若修改后不满足性质1，不修改边的颜色，打印 "Error 1.”
// 若修改后不满足性质2，不修改边的颜色，打印 "Error 2."
// 若同时不满足性质1和性质2，优先打印 "Error 1."
// 若不存在直接边，不修改边的颜色，打印 "No such edge."
// 若上述情况都没出现，那么修改边的颜色，打印 "Success."
// 1 <= n <= 10^4
// C <= 10
// 1 <= m、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2173
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
