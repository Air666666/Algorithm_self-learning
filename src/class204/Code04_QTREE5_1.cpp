// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/SP2939
// https://www.spoj.com/problems/QTREE5/

// Source: src/class204/Code04_QTREE5_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_QTREE5_1 {
  inline static int MAXN = 100001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> lm = make_array<int>(MAXN);
  inline static Array<int> rm = make_array<int>(MAXN);
  inline static JMap<int, JTreeMap<int, int>> vir =
      JMap<int, JTreeMap<int, int>>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_QTREE5_1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void insert(int x, int v) {
    if ((!vir.containsKey(x))) {
      vir.put(x, JTreeMap<int, int>());
    }
    vir.get(x).put(v, (vir.get(x).getOrDefault(v, 0) + 1));
  }
  static void remove(int x, int v) {
    int cnt = vir.get(x).get(v);
    if ((cnt == 1)) {
      vir.get(x).remove(v);
    } else {
      vir.get(x).put(v, (cnt - 1));
    }
  }
  static int getmin(int x) {
    if (((!vir.containsKey(x)) || vir.get(x).isEmpty())) {
      return INF;
    }
    return vir.get(x).firstKey();
  }
  static void up(int x) {
    (siz[x] = ((siz[ls[x]] + siz[rs[x]]) + 1));
    int l1 = lm[ls[x]];
    int l2 =
        (siz[ls[x]] + ((color[x] == 1) ? 0 : (Code04_QTREE5_1::getmin(x) + 1)));
    int l3 = ((siz[ls[x]] + 1) + lm[rs[x]]);
    (lm[x] = jmin(l1, jmin(l2, l3)));
    int r1 = rm[rs[x]];
    int r2 =
        (siz[rs[x]] + ((color[x] == 1) ? 0 : (Code04_QTREE5_1::getmin(x) + 1)));
    int r3 = ((siz[rs[x]] + 1) + rm[ls[x]]);
    (rm[x] = jmin(r1, jmin(r2, r3)));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code04_QTREE5_1::lr(x) == 0)) {
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
    if ((!Code04_QTREE5_1::isroot(f))) {
      if ((Code04_QTREE5_1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code04_QTREE5_1::up(f);
    Code04_QTREE5_1::up(x);
  }
  static void splay(int x) {
    while ((!Code04_QTREE5_1::isroot(x))) {
      int f = fa[x];
      if ((!Code04_QTREE5_1::isroot(f))) {
        if ([&]() {
              auto jleft = Code04_QTREE5_1::lr(x);
              auto jright = Code04_QTREE5_1::lr(f);
              return (jleft == jright);
            }()) {
          Code04_QTREE5_1::rotate(f);
        } else {
          Code04_QTREE5_1::rotate(x);
        }
      }
      Code04_QTREE5_1::rotate(x);
    }
    Code04_QTREE5_1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code04_QTREE5_1::splay(x);
      if ((rs[x] != 0)) {
        Code04_QTREE5_1::insert(x, lm[rs[x]]);
      }
      if ((y != 0)) {
        Code04_QTREE5_1::remove(x, lm[y]);
      }
      (rs[x] = y);
      Code04_QTREE5_1::up(x);
    }
  }
  static void reverseColor(int x) {
    Code04_QTREE5_1::access(x);
    Code04_QTREE5_1::splay(x);
    (color[x] ^= 1);
    Code04_QTREE5_1::up(x);
  }
  static int query(int x) {
    Code04_QTREE5_1::access(x);
    Code04_QTREE5_1::splay(x);
    return ((rm[x] == INF) ? (-1) : rm[x]);
  }
  static void dfs(int u, int f) {
    (fa[u] = f);
    (siz[u] = 1);
    (lm[u] = (rm[u] = INF));
    for (int e = head[u]; (e != 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != f)) {
        Code04_QTREE5_1::dfs(v, u);
        Code04_QTREE5_1::insert(u, lm[v]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (lm[0] = (rm[0] = INF));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code04_QTREE5_1::addEdge(u, v);
        Code04_QTREE5_1::addEdge(v, u);
      }
    }
    Code04_QTREE5_1::dfs(1, 0);
    (q = in.nextInt());
    {
      int i = 1;
      int op = {};
      int x = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        if ((op == 0)) {
          Code04_QTREE5_1::reverseColor(x);
        } else {
          out.println(Code04_QTREE5_1::query(x));
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
  Code04_QTREE5_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// QTREE5，java版
// 给定一棵n个节点的树，每个节点有黑白两种颜色，初始所有节点都是黑色
// 接下来有q条操作，操作类型如下
// 操作 0 x : 翻转节点x的颜色
// 操作 1 x : 打印节点x到最近白色节点的距离，不存在白色节点打印-1
// 1 <= n、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/SP2939
// 测试链接 : https://www.spoj.com/problems/QTREE5/
// 提交以下的code，提交时请把类名改成"Main"
// 本题卡常数时间，java的实现无法通过，手撸有序表也会超时
// 想通过用C++实现，本节课Code04_QTREE5_2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 节点颜色
        //
siz[x]表示以x为根的辅助splay节点数量，也就是实链节点数，不包括虚子树节点
        //
lm[x]表示以x为根的辅助splay中，从深度最小的节点出发，也就是实链顶点，到最近白色节点的距离
        //
rm[x]表示以x为根的辅助splay中，从深度最大的节点出发，也就是实链底点，到最近白色节点的距离
        // 节点x的有序表，记录每个虚儿子，各自去往下方，最近白点的距离和次数
        // 表中最小值+1，就是从x进入虚子树后，到最近白点的距离
        // 课上重点图解了决策过程
                // access(x)之后，x是当前辅助splay中，深度最大的节点
                // 所以rm[x]就是x到最近白点的距离
                                // 初始认为不存在实链，每个v都是u的虚儿子
        // 读写工具类
*/
