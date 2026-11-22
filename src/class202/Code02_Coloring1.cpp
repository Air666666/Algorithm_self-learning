// Source: src/class202/Code02_Coloring1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Coloring1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> colorAns = make_array<int>(MAXN);
  inline static Array<int> lcolor = make_array<int>(MAXN);
  inline static Array<int> rcolor = make_array<int>(MAXN);
  inline static Array<int> colorTag = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Coloring1() {}
  static void up(int x) {
    (lcolor[x] = ((ls[x] == 0) ? arr[x] : lcolor[ls[x]]));
    (rcolor[x] = ((rs[x] == 0) ? arr[x] : rcolor[rs[x]]));
    (colorAns[x] = ((colorAns[ls[x]] + colorAns[rs[x]]) + 1));
    if (((ls[x] != 0) && (rcolor[ls[x]] == arr[x]))) {
      (colorAns[x]--);
    }
    if (((rs[x] != 0) && (arr[x] == lcolor[rs[x]]))) {
      (colorAns[x]--);
    }
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void reverse(int x) {
    if ((x != 0)) {
      int tmp = ls[x];
      (ls[x] = rs[x]);
      (rs[x] = tmp);
      (tmp = lcolor[x]);
      (lcolor[x] = rcolor[x]);
      (rcolor[x] = tmp);
      (rev[x] = (!rev[x]));
    }
  }
  static void effect(int x, int c) {
    if ((x != 0)) {
      (arr[x] = c);
      (lcolor[x] = c);
      (rcolor[x] = c);
      (colorAns[x] = 1);
      (colorTag[x] = c);
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code02_Coloring1::reverse(ls[x]);
      Code02_Coloring1::reverse(rs[x]);
      (rev[x] = false);
    }
    if ((colorTag[x] != 0)) {
      Code02_Coloring1::effect(ls[x], colorTag[x]);
      Code02_Coloring1::effect(rs[x], colorTag[x]);
      (colorTag[x] = 0);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code02_Coloring1::lr(x) == 0)) {
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
    if ((!Code02_Coloring1::isroot(f))) {
      if ((Code02_Coloring1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code02_Coloring1::up(f);
    Code02_Coloring1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code02_Coloring1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code02_Coloring1::down(sta[(siz--)]);
    }
    while ((!Code02_Coloring1::isroot(x))) {
      int f = fa[x];
      if ((!Code02_Coloring1::isroot(f))) {
        if ([&]() {
              auto jleft = Code02_Coloring1::lr(x);
              auto jright = Code02_Coloring1::lr(f);
              return (jleft == jright);
            }()) {
          Code02_Coloring1::rotate(f);
        } else {
          Code02_Coloring1::rotate(x);
        }
      }
      Code02_Coloring1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code02_Coloring1::splay(x);
      (rs[x] = y);
      Code02_Coloring1::up(x);
    }
  }
  static void makeroot(int x) {
    Code02_Coloring1::access(x);
    Code02_Coloring1::splay(x);
    Code02_Coloring1::reverse(x);
  }
  static int findroot(int x) {
    Code02_Coloring1::access(x);
    Code02_Coloring1::splay(x);
    Code02_Coloring1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code02_Coloring1::down(x);
    }
    Code02_Coloring1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code02_Coloring1::makeroot(x);
    Code02_Coloring1::access(y);
    Code02_Coloring1::splay(y);
  }
  static void link(int x, int y) {
    Code02_Coloring1::makeroot(x);
    if ((Code02_Coloring1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
      (lcolor[i] = arr[i]);
      (rcolor[i] = arr[i]);
      (colorAns[i] = 1);
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i < n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code02_Coloring1::link(x, y);
      }
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      int c = {};
      for (; (i <= m); (i++)) {
        String op = in.nextString();
        if (op.equals(String(u"C"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          (c = in.nextInt());
          Code02_Coloring1::split(x, y);
          Code02_Coloring1::effect(y, c);
        } else {
          (x = in.nextInt());
          (y = in.nextInt());
          Code02_Coloring1::split(x, y);
          out.println(colorAns[y]);
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
  Code02_Coloring1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 染色，java版
// 本题就是讲解161，题目5，讲了树链剖分的解法，这里用lct的解法
// 一共有n个节点，给定n-1条边，节点连成一棵树，每个节点给定初始颜色值
// 连续相同颜色被认为是一段，变化了就认为是另一段
// 比如，112221，有三个颜色段，分别为 11、222、1
// 一共有m条操作，每种操作是如下2种类型中的一种
// 操作 C x y z : x到y的路径上，每个节点的颜色都改为z
// 操作 Q x y   : x到y的路径上，打印有几个颜色段
// 1 <= n、m <= 10^5
// 1 <= 任何时候的颜色值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2486
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 修改颜色的懒更新信息
        // 读写工具类
*/
