// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3203

// Source: src/class201/Code06_Bounce1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Bounce1 {
  inline static int MAXN = 200002;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> force = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Bounce1() {}
  static void up(int x) { (siz[x] = ((siz[ls[x]] + siz[rs[x]]) + 1)); }
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
      Code06_Bounce1::reverse(ls[x]);
      Code06_Bounce1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code06_Bounce1::lr(x) == 0)) {
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
    if ((!Code06_Bounce1::isroot(f))) {
      if ((Code06_Bounce1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code06_Bounce1::up(f);
    Code06_Bounce1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code06_Bounce1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code06_Bounce1::down(sta[(siz--)]);
    }
    while ((!Code06_Bounce1::isroot(x))) {
      int f = fa[x];
      if ((!Code06_Bounce1::isroot(f))) {
        if ([&]() {
              auto jleft = Code06_Bounce1::lr(x);
              auto jright = Code06_Bounce1::lr(f);
              return (jleft == jright);
            }()) {
          Code06_Bounce1::rotate(f);
        } else {
          Code06_Bounce1::rotate(x);
        }
      }
      Code06_Bounce1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code06_Bounce1::splay(x);
      (rs[x] = y);
      Code06_Bounce1::up(x);
    }
  }
  static void makeroot(int x) {
    Code06_Bounce1::access(x);
    Code06_Bounce1::splay(x);
    Code06_Bounce1::reverse(x);
  }
  static int findroot(int x) {
    Code06_Bounce1::access(x);
    Code06_Bounce1::splay(x);
    Code06_Bounce1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code06_Bounce1::down(x);
    }
    Code06_Bounce1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code06_Bounce1::makeroot(x);
    Code06_Bounce1::access(y);
    Code06_Bounce1::splay(y);
  }
  static void link(int x, int y) {
    Code06_Bounce1::makeroot(x);
    if ((Code06_Bounce1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code06_Bounce1::makeroot(x);
    if (((((Code06_Bounce1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code06_Bounce1::up(x);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int x = 1; (x <= (n + 1)); (x++)) {
      (siz[x] = 1);
    }
    for (int x = 1; (x <= n); (x++)) {
      (force[x] = in.nextInt());
      Code06_Bounce1::link(x, jmin((x + force[x]), (n + 1)));
    }
    (m = in.nextInt());
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (x++);
        if ((op == 1)) {
          Code06_Bounce1::split(x, (n + 1));
          out.println((siz[(n + 1)] - 1));
        } else {
          (y = in.nextInt());
          Code06_Bounce1::cut(x, jmin((x + force[x]), (n + 1)));
          (force[x] = y);
          Code06_Bounce1::link(x, jmin((x + force[x]), (n + 1)));
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
  Code06_Bounce1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 弹飞绵羊，java版
// 一共n个装置，编号0~n-1，从左到右摆成一条直线
// 每个装置给定弹力f，比如3号装置弹力为5，则从3号装置可以向右跳到8号装置
// 如果跳到的位置 >= n，也就是不存在这个装置，则认为被弹飞
// 一共m条操作，操作类型如下
// 操作 1 x   : 查询从x号装置出发，跳几次会弹飞
// 操作 2 x y : x号装置的弹力修改成y
// 1 <= n <= 2 * 10^5
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3203
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 节点数量
        // 读写工具类
*/
