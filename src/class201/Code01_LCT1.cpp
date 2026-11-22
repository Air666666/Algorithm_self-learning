// Source: src/class201/Code01_LCT1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LCT1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> xorsum = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LCT1() {}
  static void up(int x) {
    (xorsum[x] = ((xorsum[ls[x]] ^ xorsum[rs[x]]) ^ arr[x]));
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
      Code01_LCT1::reverse(ls[x]);
      Code01_LCT1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code01_LCT1::lr(x) == 0)) {
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
    if ((!Code01_LCT1::isroot(f))) {
      if ((Code01_LCT1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code01_LCT1::up(f);
    Code01_LCT1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code01_LCT1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code01_LCT1::down(sta[(siz--)]);
    }
    while ((!Code01_LCT1::isroot(x))) {
      int f = fa[x];
      if ((!Code01_LCT1::isroot(f))) {
        if ([&]() {
              auto jleft = Code01_LCT1::lr(x);
              auto jright = Code01_LCT1::lr(f);
              return (jleft == jright);
            }()) {
          Code01_LCT1::rotate(f);
        } else {
          Code01_LCT1::rotate(x);
        }
      }
      Code01_LCT1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code01_LCT1::splay(x);
      (rs[x] = y);
      Code01_LCT1::up(x);
    }
  }
  static void makeroot(int x) {
    Code01_LCT1::access(x);
    Code01_LCT1::splay(x);
    Code01_LCT1::reverse(x);
  }
  static int findroot(int x) {
    Code01_LCT1::access(x);
    Code01_LCT1::splay(x);
    Code01_LCT1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code01_LCT1::down(x);
    }
    Code01_LCT1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code01_LCT1::makeroot(x);
    Code01_LCT1::access(y);
    Code01_LCT1::splay(y);
  }
  static void link(int x, int y) {
    Code01_LCT1::makeroot(x);
    if ((Code01_LCT1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code01_LCT1::makeroot(x);
    if (((((Code01_LCT1::findroot(y) == x) && (fa[y] == x)) && (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code01_LCT1::up(x);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
      (xorsum[i] = arr[i]);
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 0)) {
          Code01_LCT1::split(x, y);
          out.println(xorsum[y]);
        } else if ((op == 1)) {
          Code01_LCT1::link(x, y);
        } else if ((op == 2)) {
          Code01_LCT1::cut(x, y);
        } else {
          Code01_LCT1::splay(x);
          (arr[x] = y);
          Code01_LCT1::up(x);
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
  Code01_LCT1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// LCT模版题，java版
// 一共n个点，每个点给定点权，一共m条操作，操作类型如下
// 操作 0 x y : 查询点x到点y的路径上，所有点权的异或和，保证x和y连通
// 操作 1 x y : 点x和点y之间增加直接边，如果x和y已经连通则忽略
// 操作 2 x y : 删除点x和点y之间的直接边，如果不存在这条直接边则忽略
// 操作 3 x y : 点x的点权变成y
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3690
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 既保存辅助splay内，每个节点的父节点
        // 也保存沿虚边向上跳到的原树父节点，认父不认子
        // 翻转操作的懒更新标记
        // 提根之前，先处理沿途的翻转标记，准备一个栈记录沿途节点
        // 本题需要异或和
        // 不同题目实现不同的up方法
        // 判断节点x是不是辅助splay的顶部节点
        // x不是辅助splay的顶部节点才能调用，返回x是其父的哪侧儿子
        // 翻转以x为根的辅助splay，交换左右儿子，打上翻转标记
        // 处理翻转懒更新
        // x向上旋转
        // x提到辅助splay的顶部
        // 打通当前原树根到x的路径，使其成为一条实链
        // 让x变成原树的根，不改变连通方式
        // 建立根到x的实链，根变成辅助splay的顶，返回x所在原树的根
        //
点x到点y的路径暴露出来，这条路径成为一条实链，组成一棵以y为顶部的辅助splay树
        // 原树中连接x和y，如果原本连通则忽略
        // 原树中切断x和y之间的直接边，没有直接边则忽略
        // 读写工具类
*/
