// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4332

// Source: src/class202/Code03_TrigeminalTree1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TrigeminalTree1 {
  inline static int MAXN = 500001;
  inline static int MAXT = (MAXN * 3);
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> parent = make_array<int>(MAXT);
  inline static Array<int> que = make_array<int>(MAXT);
  inline static Array<int> degree = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> cnt = make_array<int>(MAXN);
  inline static Array<int> sig = make_array<int>(MAXT);
  inline static Array<int> stop1 = make_array<int>(MAXN);
  inline static Array<int> stop2 = make_array<int>(MAXN);
  inline static Array<bool> tag = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TrigeminalTree1() {}
  static void up(int x) {
    (stop1[x] = stop1[rs[x]]);
    if (((stop1[x] == 0) && (cnt[x] != 1))) {
      (stop1[x] = x);
    }
    if ((stop1[x] == 0)) {
      (stop1[x] = stop1[ls[x]]);
    }
    (stop2[x] = stop2[rs[x]]);
    if (((stop2[x] == 0) && (cnt[x] != 2))) {
      (stop2[x] = x);
    }
    if ((stop2[x] == 0)) {
      (stop2[x] = stop2[ls[x]]);
    }
  }
  static void effect(int x) {
    if ((x != 0)) {
      (cnt[x] ^= 3);
      int tmp = stop1[x];
      (stop1[x] = stop2[x]);
      (stop2[x] = tmp);
      (tag[x] = (!tag[x]));
    }
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void down(int x) {
    if (tag[x]) {
      Code03_TrigeminalTree1::effect(ls[x]);
      Code03_TrigeminalTree1::effect(rs[x]);
      (tag[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code03_TrigeminalTree1::lr(x) == 0)) {
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
    if ((!Code03_TrigeminalTree1::isroot(f))) {
      if ((Code03_TrigeminalTree1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code03_TrigeminalTree1::up(f);
    Code03_TrigeminalTree1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code03_TrigeminalTree1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code03_TrigeminalTree1::down(sta[(siz--)]);
    }
    while ((!Code03_TrigeminalTree1::isroot(x))) {
      int f = fa[x];
      if ((!Code03_TrigeminalTree1::isroot(f))) {
        if ([&]() {
              auto jleft = Code03_TrigeminalTree1::lr(x);
              auto jright = Code03_TrigeminalTree1::lr(f);
              return (jleft == jright);
            }()) {
          Code03_TrigeminalTree1::rotate(f);
        } else {
          Code03_TrigeminalTree1::rotate(x);
        }
      }
      Code03_TrigeminalTree1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code03_TrigeminalTree1::splay(x);
      (rs[x] = y);
      Code03_TrigeminalTree1::up(x);
    }
  }
  static void change(int x) {
    (sig[x] ^= 1);
    int delta = ((sig[x] == 1) ? 1 : (-1));
    (x = parent[x]);
    Code03_TrigeminalTree1::access(x);
    Code03_TrigeminalTree1::splay(x);
    int stop = ((delta == 1) ? stop1[x] : stop2[x]);
    if ((stop != 0)) {
      Code03_TrigeminalTree1::splay(stop);
      Code03_TrigeminalTree1::effect(rs[stop]);
      (cnt[stop] += delta);
      Code03_TrigeminalTree1::up(stop);
    } else {
      Code03_TrigeminalTree1::effect(x);
      (ans ^= 1);
    }
  }
  static int get01(int x) {
    if ((x <= n)) {
      return ((cnt[x] <= 1) ? 0 : 1);
    } else {
      return sig[x];
    }
  }
  static void topo() {
    for (int i = 1; (i <= n); (i++)) {
      (degree[i] = 3);
    }
    int l = 1;
    int r = 0;
    for (int i = (n + 1); (i <= ((3 * n) + 1)); (i++)) {
      (que[(++r)] = i);
    }
    while ((l <= r)) {
      int x = que[(l++)];
      if ((x <= n)) {
        Code03_TrigeminalTree1::up(x);
      }
      int p = parent[x];
      if ((p != 0)) {
        (cnt[p] += Code03_TrigeminalTree1::get01(x));
        if (((--degree[p]) == 0)) {
          (que[(++r)] = p);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        for (int j = 1; (j <= 3); (j++)) {
          (x = in.nextInt());
          (parent[x] = i);
          if ((x <= n)) {
            (fa[x] = i);
          }
        }
      }
    }
    for (int i = (n + 1); (i <= ((3 * n) + 1)); (i++)) {
      (sig[i] = in.nextInt());
    }
    Code03_TrigeminalTree1::topo();
    (ans = Code03_TrigeminalTree1::get01(1));
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        Code03_TrigeminalTree1::change(x);
        out.println(ans);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TrigeminalTree1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 三叉神经树，java版
// 节点有两种类型，细胞节点编号范围[1, n]，信号节点编号范围[n+1, 3*n+1]
// 每个信号节点没有儿子节点，每个细胞节点固定有三个儿子节点
// 给定每个细胞节点的三个儿子节点编号，每个儿子可能是细胞节点，或者信号节点
// 每个信号节点拥有自身的值，是0或者1，初始值会给定，该值向上输出给父节点
// 每个细胞节点没有自身的值，根据三个儿子的信号，决定向上的输出
// 三个儿子节点中，1多就向上输出1，0多就向上输出0，也是向上输出给父节点
// 一共q条操作，每次给定一个信号节点的编号，表示它的值发生了翻转
// 题目保证1号节点是整棵树的根，每次操作执行完，都打印1号节点的输出
// 1 <= n、q <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4332
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原树的父节点
        // 拓扑排序，设置节点的初始输出
        // 辅助splay
        // cnt[i]，细胞节点i的儿子中，输出为1的儿子数量，范围0~3
        // sig[i]，信号节点i的值，范围0~1
        // x所在的实链中，从下往上第一个cnt != 1的节点，当外部输入从0变1时
        // 从下往上一路连续的cnt == 1的节点都改变输出，最终停在stop1[x]
        // x所在的实链中，从下往上第一个cnt != 2的节点，当外部输入从1变0时
        // 从下往上一路连续的cnt == 2的节点都改变输出，最终停在stop2[x]
        // 本题没有左右孩子的翻转，但是有传导状态的翻转，tag就表示这个
        // 1号节点的输出
        // 传导状态翻转，只作用在连续传导段上
        // 要么连续一段，全是cnt == 1，变成cnt == 2
        // 要么连续一段，全是cnt == 2，变成cnt == 1
        // 只涉及这两种场景，不会有其他的cnt值
        // 读写工具类
*/
