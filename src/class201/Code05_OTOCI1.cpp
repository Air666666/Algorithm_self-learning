// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4312

// Source: src/class201/Code05_OTOCI1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_OTOCI1 {
  inline static int MAXN = 30001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_OTOCI1() {}
  static void up(int x) { (sum[x] = ((sum[ls[x]] + sum[rs[x]]) + arr[x])); }
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
      Code05_OTOCI1::reverse(ls[x]);
      Code05_OTOCI1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code05_OTOCI1::lr(x) == 0)) {
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
    if ((!Code05_OTOCI1::isroot(f))) {
      if ((Code05_OTOCI1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code05_OTOCI1::up(f);
    Code05_OTOCI1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code05_OTOCI1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code05_OTOCI1::down(sta[(siz--)]);
    }
    while ((!Code05_OTOCI1::isroot(x))) {
      int f = fa[x];
      if ((!Code05_OTOCI1::isroot(f))) {
        if ([&]() {
              auto jleft = Code05_OTOCI1::lr(x);
              auto jright = Code05_OTOCI1::lr(f);
              return (jleft == jright);
            }()) {
          Code05_OTOCI1::rotate(f);
        } else {
          Code05_OTOCI1::rotate(x);
        }
      }
      Code05_OTOCI1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code05_OTOCI1::splay(x);
      (rs[x] = y);
      Code05_OTOCI1::up(x);
    }
  }
  static void makeroot(int x) {
    Code05_OTOCI1::access(x);
    Code05_OTOCI1::splay(x);
    Code05_OTOCI1::reverse(x);
  }
  static int findroot(int x) {
    Code05_OTOCI1::access(x);
    Code05_OTOCI1::splay(x);
    Code05_OTOCI1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code05_OTOCI1::down(x);
    }
    Code05_OTOCI1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code05_OTOCI1::makeroot(x);
    Code05_OTOCI1::access(y);
    Code05_OTOCI1::splay(y);
  }
  static void link(int x, int y) {
    Code05_OTOCI1::makeroot(x);
    if ((Code05_OTOCI1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code05_OTOCI1::makeroot(x);
    if (((((Code05_OTOCI1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code05_OTOCI1::up(x);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
      (sum[i] = arr[i]);
    }
    (m = in.nextInt());
    String op = {};
    int x = {};
    int y = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextString());
      (x = in.nextInt());
      (y = in.nextInt());
      if (op.equals(String(u"bridge"))) {
        if ([&]() {
              auto jleft = Code05_OTOCI1::findroot(x);
              auto jright = Code05_OTOCI1::findroot(y);
              return (jleft == jright);
            }()) {
          out.println(String(u"no"));
        } else {
          out.println(String(u"yes"));
          Code05_OTOCI1::link(x, y);
        }
      } else if (op.equals(String(u"penguins"))) {
        Code05_OTOCI1::splay(x);
        (arr[x] = y);
        Code05_OTOCI1::up(x);
      } else {
        if ([&]() {
              auto jleft = Code05_OTOCI1::findroot(x);
              auto jright = Code05_OTOCI1::findroot(y);
              return (jleft != jright);
            }()) {
          out.println(String(u"impossible"));
        } else {
          Code05_OTOCI1::split(x, y);
          out.println(sum[y]);
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
  Code05_OTOCI1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 群岛，java版
// 一共n个点，每个点有点权，初始时没有边，一共m条操作，类型如下
// 操作 bridge x y    : 如果x和y已经连通，打印no，表示不需要连边
//                      如果x和y不连通，打印yes，然后增加无向边
// 操作 penguins x y  : x的点权变成y
// 操作 excursion x y : 如果x和y不连通，打印impossible
//                      如果x和y连通，打印路径的点权累加和
// 1 <= n <= 3 * 10^4
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4312
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 点权和
        // 汇总点权和
        // 读写工具类
*/
