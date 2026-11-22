// Source: src/class202/Code05_Alliance1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Alliance1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static int p = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> nodeCnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Alliance1() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code05_Alliance1::find(father[x]));
    }
    return father[x];
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
      Code05_Alliance1::reverse(ls[x]);
      Code05_Alliance1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code05_Alliance1::lr(x) == 0)) {
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
    if ((!Code05_Alliance1::isroot(f))) {
      if ((Code05_Alliance1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code05_Alliance1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code05_Alliance1::down(sta[(siz--)]);
    }
    while ((!Code05_Alliance1::isroot(x))) {
      int f = fa[x];
      if ((!Code05_Alliance1::isroot(f))) {
        if ([&]() {
              auto jleft = Code05_Alliance1::lr(x);
              auto jright = Code05_Alliance1::lr(f);
              return (jleft == jright);
            }()) {
          Code05_Alliance1::rotate(f);
        } else {
          Code05_Alliance1::rotate(x);
        }
      }
      Code05_Alliance1::rotate(x);
    }
  }
  static void access(int x) {
    (x = Code05_Alliance1::find(x));
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code05_Alliance1::splay(x);
      (rs[x] = y);
      (fa[x] = Code05_Alliance1::find(fa[x]));
    }
  }
  static void makeroot(int x) {
    Code05_Alliance1::access(x);
    Code05_Alliance1::splay(x);
    Code05_Alliance1::reverse(x);
  }
  static int findroot(int x) {
    Code05_Alliance1::access(x);
    Code05_Alliance1::splay(x);
    Code05_Alliance1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code05_Alliance1::down(x);
    }
    Code05_Alliance1::splay(x);
    return x;
  }
  static void condense(int x, int root) {
    if ((x != 0)) {
      (father[x] = root);
      (nodeCnt[root] += nodeCnt[x]);
      Code05_Alliance1::condense(ls[x], root);
      Code05_Alliance1::condense(rs[x], root);
    }
  }
  static int link(int x, int y) {
    (x = Code05_Alliance1::find(x));
    (y = Code05_Alliance1::find(y));
    if ((x == y)) {
      return nodeCnt[x];
    }
    Code05_Alliance1::makeroot(x);
    if ((Code05_Alliance1::findroot(y) != x)) {
      (fa[x] = y);
      return (-1);
    } else {
      Code05_Alliance1::condense(rs[x], x);
      (rs[x] = 0);
      return nodeCnt[x];
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (p = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (nodeCnt[i] = 1);
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code05_Alliance1::link(x, y);
      }
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= p); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        int ans = Code05_Alliance1::link(x, y);
        if ((ans == (-1))) {
          out.println(String(u"No"));
        } else {
          out.println(ans);
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
  Code05_Alliance1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 星球联盟，java版
// 一共有n个点、m条无向边，接下来依次加入p条无向边
// 如果两个点属于同一个联盟，必须存在一条环形线路经过这两个点
// 等价地说，两个点之间存在两条没有公共边的路径，也就是在同一个边双连通分量中
// 每次加入一条新边(x,y)，加入之后判断点x和点y是否属于同一个联盟
// 如果不属于同一个联盟，打印"No"
// 如果属于同一个联盟，打印这个联盟里的节点数
// 1 <= n、m、p <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P10657
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // nodeCnt[x]表示x代表的边双连通分量中，有多少个原图节点
        // 如果两点不连通就连接，如果连通，说明形成环，缩成一个边双
        // 如果不连通就返回-1，否则返回边双的节点数量
        // 读写工具类
*/
