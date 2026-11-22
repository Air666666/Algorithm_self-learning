// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3950

// Source: src/class201/Code04_Conflict1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Conflict1 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> cutx = make_array<int>(MAXN);
  inline static Array<int> cuty = make_array<int>(MAXN);
  inline static int cutc = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Conflict1() {}
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
      Code04_Conflict1::reverse(ls[x]);
      Code04_Conflict1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code04_Conflict1::lr(x) == 0)) {
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
    if ((!Code04_Conflict1::isroot(f))) {
      if ((Code04_Conflict1::lr(f) == 0)) {
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
    for (int y = x; (!Code04_Conflict1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code04_Conflict1::down(sta[(siz--)]);
    }
    while ((!Code04_Conflict1::isroot(x))) {
      int f = fa[x];
      if ((!Code04_Conflict1::isroot(f))) {
        if ([&]() {
              auto jleft = Code04_Conflict1::lr(x);
              auto jright = Code04_Conflict1::lr(f);
              return (jleft == jright);
            }()) {
          Code04_Conflict1::rotate(f);
        } else {
          Code04_Conflict1::rotate(x);
        }
      }
      Code04_Conflict1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code04_Conflict1::splay(x);
      (rs[x] = y);
    }
  }
  static void makeroot(int x) {
    Code04_Conflict1::access(x);
    Code04_Conflict1::splay(x);
    Code04_Conflict1::reverse(x);
  }
  static int findroot(int x) {
    Code04_Conflict1::access(x);
    Code04_Conflict1::splay(x);
    Code04_Conflict1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code04_Conflict1::down(x);
    }
    Code04_Conflict1::splay(x);
    return x;
  }
  static void link(int x, int y) {
    Code04_Conflict1::makeroot(x);
    if ((Code04_Conflict1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code04_Conflict1::makeroot(x);
    if (((((Code04_Conflict1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i < n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code04_Conflict1::link(x, y);
      }
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        String op = in.nextString();
        if (op.equals(String(u"C"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code04_Conflict1::cut(x, y);
          (cutx[(++cutc)] = x);
          (cuty[cutc] = y);
        } else if (op.equals(String(u"U"))) {
          (x = in.nextInt());
          Code04_Conflict1::link(cutx[x], cuty[x]);
        } else {
          (x = in.nextInt());
          (y = in.nextInt());
          if ([&]() {
                auto jleft = Code04_Conflict1::findroot(x);
                auto jright = Code04_Conflict1::findroot(y);
                return (jleft == jright);
              }()) {
            out.println(String(u"Yes"));
          } else {
            out.println(String(u"No"));
          }
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
  Code04_Conflict1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 部落冲突，java版
// 一共n个点，给定n-1条边，所有点组成一棵树，一共m条操作，类型如下
// 操作 C x y : x和y在树中相邻，之前未开战，现在开战，x和y的直接边变成不可通行
//              每条C操作代表一次战争事件，战争事件从1开始编号，每次编号自增
// 操作 U x   : 第x号战争事件结束，对应的直接边变为可通行，保证战争不会重复结束
// 操作 Q x y : 查询点x和点y之间是否连通，打印 Yes 或 No
// 1 <= n、m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3950
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
