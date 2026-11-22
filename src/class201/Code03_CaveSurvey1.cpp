// Source: src/class201/Code03_CaveSurvey1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CaveSurvey1 {
  inline static int MAXN = 10001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CaveSurvey1() {}
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
      Code03_CaveSurvey1::reverse(ls[x]);
      Code03_CaveSurvey1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code03_CaveSurvey1::lr(x) == 0)) {
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
    if ((!Code03_CaveSurvey1::isroot(f))) {
      if ((Code03_CaveSurvey1::lr(f) == 0)) {
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
    for (int y = x; (!Code03_CaveSurvey1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code03_CaveSurvey1::down(sta[(siz--)]);
    }
    while ((!Code03_CaveSurvey1::isroot(x))) {
      int f = fa[x];
      if ((!Code03_CaveSurvey1::isroot(f))) {
        if ([&]() {
              auto jleft = Code03_CaveSurvey1::lr(x);
              auto jright = Code03_CaveSurvey1::lr(f);
              return (jleft == jright);
            }()) {
          Code03_CaveSurvey1::rotate(f);
        } else {
          Code03_CaveSurvey1::rotate(x);
        }
      }
      Code03_CaveSurvey1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code03_CaveSurvey1::splay(x);
      (rs[x] = y);
    }
  }
  static void makeroot(int x) {
    Code03_CaveSurvey1::access(x);
    Code03_CaveSurvey1::splay(x);
    Code03_CaveSurvey1::reverse(x);
  }
  static int findroot(int x) {
    Code03_CaveSurvey1::access(x);
    Code03_CaveSurvey1::splay(x);
    Code03_CaveSurvey1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code03_CaveSurvey1::down(x);
    }
    Code03_CaveSurvey1::splay(x);
    return x;
  }
  static void link(int x, int y) {
    Code03_CaveSurvey1::makeroot(x);
    if ((Code03_CaveSurvey1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code03_CaveSurvey1::makeroot(x);
    if (((((Code03_CaveSurvey1::findroot(y) == x) && (fa[y] == x)) &&
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
      for (; (i <= m); (i++)) {
        String op = in.nextString();
        (x = in.nextInt());
        (y = in.nextInt());
        if (op.equals(String(u"Connect"))) {
          Code03_CaveSurvey1::link(x, y);
        } else if (op.equals(String(u"Destroy"))) {
          Code03_CaveSurvey1::cut(x, y);
        } else {
          if ([&]() {
                auto jleft = Code03_CaveSurvey1::findroot(x);
                auto jright = Code03_CaveSurvey1::findroot(y);
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
  Code03_CaveSurvey1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 洞穴勘测，java版
// 一共n个点，初始时没有任何边，任意时刻图都是森林，一共m条操作，类型如下
// 操作 Connect x y : 点x和点y之间增加直接边，保证原来不存在这条直接边
// 操作 Destroy x y : 删除点x和点y之间的直接边，保证原来存在这条直接边
// 操作 Query x y   : 查询点x和点y之间是否连通，打印 Yes 或 No
// 1 <= n <= 10^4
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2147
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
