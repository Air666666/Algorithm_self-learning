// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1501

// Source: src/class202/Code01_DynamicAddMul1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DynamicAddMul1 {
  inline static int MAXN = 100001;
  inline static int MOD = 51061;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<i64> arr = make_array<i64>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> mulTag = make_array<i64>(MAXN);
  inline static Array<i64> addTag = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DynamicAddMul1() {}
  static void up(int x) {
    (siz[x] = ((siz[ls[x]] + siz[rs[x]]) + 1));
    (sum[x] = jrem(((sum[ls[x]] + sum[rs[x]]) + arr[x]), MOD));
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
  static void effect(int x, i64 mul, i64 add) {
    if ((x != 0)) {
      (arr[x] = jrem(((arr[x] * mul) + add), MOD));
      (sum[x] = jrem(((sum[x] * mul) + (siz[x] * add)), MOD));
      (mulTag[x] = jrem((mulTag[x] * mul), MOD));
      (addTag[x] = jrem(((addTag[x] * mul) + add), MOD));
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code01_DynamicAddMul1::reverse(ls[x]);
      Code01_DynamicAddMul1::reverse(rs[x]);
      (rev[x] = false);
    }
    if (((mulTag[x] != 1) || (addTag[x] != 0))) {
      Code01_DynamicAddMul1::effect(ls[x], mulTag[x], addTag[x]);
      Code01_DynamicAddMul1::effect(rs[x], mulTag[x], addTag[x]);
      (mulTag[x] = 1);
      (addTag[x] = 0);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code01_DynamicAddMul1::lr(x) == 0)) {
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
    if ((!Code01_DynamicAddMul1::isroot(f))) {
      if ((Code01_DynamicAddMul1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code01_DynamicAddMul1::up(f);
    Code01_DynamicAddMul1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code01_DynamicAddMul1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code01_DynamicAddMul1::down(sta[(siz--)]);
    }
    while ((!Code01_DynamicAddMul1::isroot(x))) {
      int f = fa[x];
      if ((!Code01_DynamicAddMul1::isroot(f))) {
        if ([&]() {
              auto jleft = Code01_DynamicAddMul1::lr(x);
              auto jright = Code01_DynamicAddMul1::lr(f);
              return (jleft == jright);
            }()) {
          Code01_DynamicAddMul1::rotate(f);
        } else {
          Code01_DynamicAddMul1::rotate(x);
        }
      }
      Code01_DynamicAddMul1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code01_DynamicAddMul1::splay(x);
      (rs[x] = y);
      Code01_DynamicAddMul1::up(x);
    }
  }
  static void makeroot(int x) {
    Code01_DynamicAddMul1::access(x);
    Code01_DynamicAddMul1::splay(x);
    Code01_DynamicAddMul1::reverse(x);
  }
  static int findroot(int x) {
    Code01_DynamicAddMul1::access(x);
    Code01_DynamicAddMul1::splay(x);
    Code01_DynamicAddMul1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code01_DynamicAddMul1::down(x);
    }
    Code01_DynamicAddMul1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code01_DynamicAddMul1::makeroot(x);
    Code01_DynamicAddMul1::access(y);
    Code01_DynamicAddMul1::splay(y);
  }
  static void link(int x, int y) {
    Code01_DynamicAddMul1::makeroot(x);
    if ((Code01_DynamicAddMul1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code01_DynamicAddMul1::makeroot(x);
    if (((((Code01_DynamicAddMul1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code01_DynamicAddMul1::up(x);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (siz[i] = 1);
      (arr[i] = 1);
      (sum[i] = 1);
      (mulTag[i] = 1);
      (addTag[i] = 0);
    }
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i < n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        Code01_DynamicAddMul1::link(x, y);
      }
    }
    String op = {};
    int x = {};
    int y = {};
    int z = {};
    int a = {};
    int b = {};
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextString());
      if (op.equals(String(u"+"))) {
        (x = in.nextInt());
        (y = in.nextInt());
        (z = in.nextInt());
        (z %= MOD);
        Code01_DynamicAddMul1::split(x, y);
        Code01_DynamicAddMul1::effect(y, 1, z);
      } else if (op.equals(String(u"*"))) {
        (x = in.nextInt());
        (y = in.nextInt());
        (z = in.nextInt());
        (z %= MOD);
        Code01_DynamicAddMul1::split(x, y);
        Code01_DynamicAddMul1::effect(y, z, 0);
      } else if (op.equals(String(u"-"))) {
        (x = in.nextInt());
        (y = in.nextInt());
        (a = in.nextInt());
        (b = in.nextInt());
        Code01_DynamicAddMul1::cut(x, y);
        Code01_DynamicAddMul1::link(a, b);
      } else {
        (x = in.nextInt());
        (y = in.nextInt());
        Code01_DynamicAddMul1::split(x, y);
        out.println(sum[y]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DynamicAddMul1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 动态树的加和乘，java版
// 一共有n个点、n-1条边，每个点的初始点权都是1，所有节点组成一棵树
// 接下来有q条操作，操作类型有四种，格式如下
// 操作 + x y z   : x到y的路径上，点的权值都加上z，z是非负整数
// 操作 * x y z   : x到y的路径上，点的权值都乘上z，z是非负整数
// 操作 - x y a b : 删除原边(x,y)，加入新边(a,b)，操作后仍然是一棵树
// 操作 / x y     : x到y的路径上，查询点权累加和，对 51061 取模
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1501
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
