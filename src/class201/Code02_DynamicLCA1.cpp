// Source: src/class201/Code02_DynamicLCA1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DynamicLCA1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DynamicLCA1() {}
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code02_DynamicLCA1::lr(x) == 0)) {
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
    if ((!Code02_DynamicLCA1::isroot(f))) {
      if ((Code02_DynamicLCA1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
  }
  static void splay(int x) {
    while ((!Code02_DynamicLCA1::isroot(x))) {
      int f = fa[x];
      if ((!Code02_DynamicLCA1::isroot(f))) {
        if ([&]() {
              auto jleft = Code02_DynamicLCA1::lr(x);
              auto jright = Code02_DynamicLCA1::lr(f);
              return (jleft == jright);
            }()) {
          Code02_DynamicLCA1::rotate(f);
        } else {
          Code02_DynamicLCA1::rotate(x);
        }
      }
      Code02_DynamicLCA1::rotate(x);
    }
  }
  static int access(int x) {
    int ans = 0;
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code02_DynamicLCA1::splay(x);
      (rs[x] = y);
      (ans = x);
    }
    return ans;
  }
  static void makeson(int x, int y) {
    Code02_DynamicLCA1::access(x);
    Code02_DynamicLCA1::splay(x);
    (fa[x] = y);
  }
  static void cutfa(int x) {
    Code02_DynamicLCA1::access(x);
    Code02_DynamicLCA1::splay(x);
    (fa[ls[x]] = 0);
    (ls[x] = 0);
  }
  static int lca(int x, int y) {
    if ((x == y)) {
      return x;
    }
    Code02_DynamicLCA1::access(x);
    return Code02_DynamicLCA1::access(y);
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
        if (op.equals(String(u"link"))) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code02_DynamicLCA1::makeson(x, y);
        } else if (op.equals(String(u"cut"))) {
          (x = in.nextInt());
          Code02_DynamicLCA1::cutfa(x);
        } else {
          (x = in.nextInt());
          (y = in.nextInt());
          out.println(Code02_DynamicLCA1::lca(x, y));
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
  Code02_DynamicLCA1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 动态树LCA，java版
// 一共n个点，初始时每个点各自是一棵单点有根树，一共m条操作，操作类型如下
// 操作 link x y : 让点x成为点y的儿子，保证x是所在树的根，并且x和y不连通
// 操作 cut x    : 删除点x和它父亲节点之间的直接边，保证x不是根
// 操作 lca x y  : 查询点x和点y的最低公共祖先，保证x和y在同一棵树中
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP8791
// 测试链接 : https://www.spoj.com/problems/DYNALCA/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 返回最后一次接上的点
        // 让x成为y的孩子，保证x是所在树的根，并且x和y不连通
        // 切断x和原树父亲之间的边，保证x不是根
        // 第二次的返回值就是lca
        // 读写工具类
*/
