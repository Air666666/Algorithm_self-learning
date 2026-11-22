// Source: src/class204/Code01_GreatIntegration1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GreatIntegration1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> vir = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GreatIntegration1() {}
  static void up(int x) {
    (sum[x] = (((sum[ls[x]] + sum[rs[x]]) + vir[x]) + 1));
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
      Code01_GreatIntegration1::reverse(ls[x]);
      Code01_GreatIntegration1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code01_GreatIntegration1::lr(x) == 0)) {
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
    if ((!Code01_GreatIntegration1::isroot(f))) {
      if ((Code01_GreatIntegration1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code01_GreatIntegration1::up(f);
    Code01_GreatIntegration1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code01_GreatIntegration1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code01_GreatIntegration1::down(sta[(siz--)]);
    }
    while ((!Code01_GreatIntegration1::isroot(x))) {
      int f = fa[x];
      if ((!Code01_GreatIntegration1::isroot(f))) {
        if ([&]() {
              auto jleft = Code01_GreatIntegration1::lr(x);
              auto jright = Code01_GreatIntegration1::lr(f);
              return (jleft == jright);
            }()) {
          Code01_GreatIntegration1::rotate(f);
        } else {
          Code01_GreatIntegration1::rotate(x);
        }
      }
      Code01_GreatIntegration1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code01_GreatIntegration1::splay(x);
      (vir[x] += sum[rs[x]]);
      (vir[x] -= sum[y]);
      (rs[x] = y);
      Code01_GreatIntegration1::up(x);
    }
  }
  static void makeroot(int x) {
    Code01_GreatIntegration1::access(x);
    Code01_GreatIntegration1::splay(x);
    Code01_GreatIntegration1::reverse(x);
  }
  static int findroot(int x) {
    Code01_GreatIntegration1::access(x);
    Code01_GreatIntegration1::splay(x);
    Code01_GreatIntegration1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code01_GreatIntegration1::down(x);
    }
    Code01_GreatIntegration1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code01_GreatIntegration1::makeroot(x);
    Code01_GreatIntegration1::access(y);
    Code01_GreatIntegration1::splay(y);
  }
  static void link(int x, int y) {
    Code01_GreatIntegration1::makeroot(x);
    if ((Code01_GreatIntegration1::findroot(y) != x)) {
      Code01_GreatIntegration1::access(y);
      Code01_GreatIntegration1::splay(y);
      (fa[x] = y);
      (vir[y] += sum[x]);
      Code01_GreatIntegration1::up(y);
    }
  }
  static void cut(int x, int y) {
    Code01_GreatIntegration1::makeroot(x);
    if (((((Code01_GreatIntegration1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code01_GreatIntegration1::up(x);
    }
  }
  static i64 query(int x, int y) {
    Code01_GreatIntegration1::cut(x, y);
    Code01_GreatIntegration1::makeroot(x);
    int sizx = sum[x];
    Code01_GreatIntegration1::makeroot(y);
    int sizy = sum[y];
    Code01_GreatIntegration1::link(x, y);
    return ((1LL * sizx) * sizy);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (sum[i] = 1);
    }
    for (int i = 1; (i <= q); (i++)) {
      jchar op = in.nextChar();
      int x = in.nextInt();
      int y = in.nextInt();
      if ((op == u'A')) {
        Code01_GreatIntegration1::link(x, y);
      } else {
        out.println(Code01_GreatIntegration1::query(x, y));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_GreatIntegration1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 大融合，java版
// 本题就是讲解166，题目5，讲了线段树分治的解法，这里用lct的解法
// 一共有n个点，一共有q条操作，每条操作是如下两种类型中的一种
// 操作 A x y : 点x和点y之间连一条边，保证之前x和y是不联通的
// 操作 Q x y : 打印点x和点y之间这条边的负载，保证x和y之间有一条边
// 边负载定义为，这条边两侧端点各自连通区大小的乘积
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4219
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // vir[x]表示x所有虚子树的大小总和
        // sum[x]表示以x为根的辅助splay中，汇总所有节点的数量
        // 包括x自己、x的所有虚子树大小、左右儿子的贡献
        // 汇总贡献
        // 原右儿子由实儿子变成虚儿子，加入贡献
        // 新右儿子由虚儿子变成实儿子，删除贡献
        // 连接x和y，x和y成为各自树的头，然后x作为y的虚儿子
        // cut方法和lct模版代码完全一样，但是注意
        // 判断x和y之间是否存在直接边，如果判定成立
        // 此时x和y之间的边已经是实边，所以删除该边不需要修改vir
        // 临时删除询问边
        // 将两个端点分别作为各自原树的根，得到各自连通块的大小
        // 然后恢复询问边
        // 读写工具类
*/
