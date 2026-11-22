// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/SP16549
// https://www.spoj.com/problems/QTREE6/

// Source: src/class204/Code02_QTREE6_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_QTREE6_1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> parent = make_array<int>(MAXN);
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> vir = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_QTREE6_1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void up(int x) {
    (sum[x] = (((sum[ls[x]] + sum[rs[x]]) + vir[x]) + val[x]));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code02_QTREE6_1::lr(x) == 0)) {
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
    if ((!Code02_QTREE6_1::isroot(f))) {
      if ((Code02_QTREE6_1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code02_QTREE6_1::up(f);
    Code02_QTREE6_1::up(x);
  }
  static void splay(int x) {
    while ((!Code02_QTREE6_1::isroot(x))) {
      int f = fa[x];
      if ((!Code02_QTREE6_1::isroot(f))) {
        if ([&]() {
              auto jleft = Code02_QTREE6_1::lr(x);
              auto jright = Code02_QTREE6_1::lr(f);
              return (jleft == jright);
            }()) {
          Code02_QTREE6_1::rotate(f);
        } else {
          Code02_QTREE6_1::rotate(x);
        }
      }
      Code02_QTREE6_1::rotate(x);
    }
    Code02_QTREE6_1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code02_QTREE6_1::splay(x);
      (vir[x] += sum[rs[x]]);
      (vir[x] -= sum[y]);
      (rs[x] = y);
      Code02_QTREE6_1::up(x);
    }
  }
  static int findroot(int x) {
    Code02_QTREE6_1::access(x);
    Code02_QTREE6_1::splay(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
    }
    Code02_QTREE6_1::splay(x);
    return x;
  }
  static void link(int x, int f) {
    if ((f == 0)) {
      return;
    }
    Code02_QTREE6_1::access(f);
    Code02_QTREE6_1::splay(f);
    Code02_QTREE6_1::splay(x);
    (fa[x] = f);
    (vir[f] += sum[x]);
    Code02_QTREE6_1::up(f);
  }
  static void cut(int x, int f) {
    Code02_QTREE6_1::access(x);
    Code02_QTREE6_1::splay(x);
    if ((f != 0)) {
      int left = ls[x];
      (fa[left] = 0);
      (ls[x] = 0);
      Code02_QTREE6_1::up(x);
    }
  }
  static int query(int x) {
    int xs = ((val[x] == 1) ? x : (x + n));
    int ys = Code02_QTREE6_1::findroot(xs);
    return ((val[ys] == 1) ? sum[ys] : sum[rs[ys]]);
  }
  static void reverseColor(int x) {
    int pre = ((val[x] == 1) ? x : (x + n));
    int cur = ((pre <= n) ? (pre + n) : (pre - n));
    Code02_QTREE6_1::cut(pre, parent[pre]);
    (val[pre] = 0);
    (val[cur] = 1);
    Code02_QTREE6_1::link(cur, parent[cur]);
  }
  static void dfs(int u, int f) {
    if ((f != 0)) {
      (parent[u] = f);
      (parent[(u + n)] = (f + n));
    }
    (val[u] = (sum[u] = 1));
    for (int e = head[u]; (e != 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != f)) {
        Code02_QTREE6_1::dfs(v, u);
        Code02_QTREE6_1::link(v, u);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code02_QTREE6_1::addEdge(u, v);
        Code02_QTREE6_1::addEdge(v, u);
      }
    }
    Code02_QTREE6_1::dfs(1, 0);
    (q = in.nextInt());
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        if ((op == 0)) {
          out.println(Code02_QTREE6_1::query(x));
        } else {
          Code02_QTREE6_1::reverseColor(x);
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
  Code02_QTREE6_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// QTREE6，java版
// 给定一棵n个节点的树，每个节点有黑白两种颜色，初始所有节点都是黑色
// 接下来有q条操作，操作类型如下
// 操作 0 x : 打印节点x所在的同色连通块大小
// 操作 1 x : 翻转节点x的颜色
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP16549
// 测试链接 : https://www.spoj.com/problems/QTREE6/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原树
        // 节点x有黑白两个状态，x是黑状态，x+n是白状态
        // 两套颜色的森林共用一套LCT，彼此独立
        // 原树固定以1为根，每个状态节点都有同一颜色系统中的固定父亲
        // parent[x]表示黑色状态节点x的固定父亲
        // parent[x+n]表示白色状态节点x+n的固定父亲
        // 节点x有黑白两个状态，分别是x和x+n，有效状态只有一个
        // vir[x]表示状态节点x的虚子树的点权累加和
        // sum[x]表示以x为根的辅助splay中，汇总所有点权累加和
        // 包括x自己的贡献、x的所有虚子树的贡献、左右儿子的贡献
        // 注意修正虚子树贡献
        // 原树形态固定，连接父边(x, f)，x是子，f是父
        // 连接后x作为f的虚儿子
        // 原树形态固定，删除父边(x, f)，x是子，f是父
                // 得到x的状态xs，顶部节点的状态ys
                // 如果顶部节点和x同色，返回整体sum，如果不同色，返回右儿子sum
                // 老颜色的lct中要断边，新颜色的lct中要连边
                // 黑白的状态节点，各自记录父亲
                // 节点初始都是黑色，黑色状态点才有贡献
        // 读写工具类
*/
