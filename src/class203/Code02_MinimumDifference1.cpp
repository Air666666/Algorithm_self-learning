// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4234

// Source: src/class203/Code02_MinimumDifference1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MinimumDifference1 {
  inline static int MAXN = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> ew = make_array<int>(MAXN);
  inline static Array<bool> removed = make_array<bool>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> minEdge = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MinimumDifference1() {}
  static void sort(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = ew[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((ew[i] < pivot))
        (i++);
      while ((ew[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = ex[i]);
        (ex[i] = ex[j]);
        (ex[j] = tmp);
        (tmp = ey[i]);
        (ey[i] = ey[j]);
        (ey[j] = tmp);
        (tmp = ew[i]);
        (ew[i] = ew[j]);
        (ew[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code02_MinimumDifference1::sort(l, j);
    Code02_MinimumDifference1::sort(i, r);
  }
  static void up(int x) {
    int cur = ((x <= n) ? 0 : (x - n));
    int l = minEdge[ls[x]];
    int r = minEdge[rs[x]];
    if (((cur == 0) || ((l != 0) && (l < cur)))) {
      (cur = l);
    }
    if (((cur == 0) || ((r != 0) && (r < cur)))) {
      (cur = r);
    }
    (minEdge[x] = cur);
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
      Code02_MinimumDifference1::reverse(ls[x]);
      Code02_MinimumDifference1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code02_MinimumDifference1::lr(x) == 0)) {
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
    if ((!Code02_MinimumDifference1::isroot(f))) {
      if ((Code02_MinimumDifference1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code02_MinimumDifference1::up(f);
    Code02_MinimumDifference1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code02_MinimumDifference1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code02_MinimumDifference1::down(sta[(siz--)]);
    }
    while ((!Code02_MinimumDifference1::isroot(x))) {
      int f = fa[x];
      if ((!Code02_MinimumDifference1::isroot(f))) {
        if ([&]() {
              auto jleft = Code02_MinimumDifference1::lr(x);
              auto jright = Code02_MinimumDifference1::lr(f);
              return (jleft == jright);
            }()) {
          Code02_MinimumDifference1::rotate(f);
        } else {
          Code02_MinimumDifference1::rotate(x);
        }
      }
      Code02_MinimumDifference1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code02_MinimumDifference1::splay(x);
      (rs[x] = y);
      Code02_MinimumDifference1::up(x);
    }
  }
  static void makeroot(int x) {
    Code02_MinimumDifference1::access(x);
    Code02_MinimumDifference1::splay(x);
    Code02_MinimumDifference1::reverse(x);
  }
  static int findroot(int x) {
    Code02_MinimumDifference1::access(x);
    Code02_MinimumDifference1::splay(x);
    Code02_MinimumDifference1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code02_MinimumDifference1::down(x);
    }
    Code02_MinimumDifference1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code02_MinimumDifference1::makeroot(x);
    Code02_MinimumDifference1::access(y);
    Code02_MinimumDifference1::splay(y);
  }
  static void link(int x, int y) {
    Code02_MinimumDifference1::makeroot(x);
    if ((Code02_MinimumDifference1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code02_MinimumDifference1::makeroot(x);
    if (((((Code02_MinimumDifference1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code02_MinimumDifference1::up(x);
    }
  }
  static int compute() {
    Code02_MinimumDifference1::sort(1, m);
    int edgeCnt = 0;
    int first = 1;
    int ans = std::numeric_limits<int>::max();
    for (int i = 1; (i <= m); (i++)) {
      int x = ex[i];
      int y = ey[i];
      if ((x == y)) {
        (removed[i] = true);
      } else {
        Code02_MinimumDifference1::makeroot(x);
        if ((Code02_MinimumDifference1::findroot(y) != x)) {
          Code02_MinimumDifference1::link(x, (n + i));
          Code02_MinimumDifference1::link(y, (n + i));
          (edgeCnt++);
        } else {
          Code02_MinimumDifference1::split(x, y);
          int pre = minEdge[y];
          Code02_MinimumDifference1::cut(ex[pre], (n + pre));
          Code02_MinimumDifference1::cut(ey[pre], (n + pre));
          Code02_MinimumDifference1::link(x, (n + i));
          Code02_MinimumDifference1::link(y, (n + i));
          (removed[pre] = true);
        }
      }
      while (removed[first]) {
        (first++);
      }
      if ((edgeCnt == (n - 1))) {
        (ans = jmin(ans, (ew[i] - ew[first])));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (ex[i] = in.nextInt());
      (ey[i] = in.nextInt());
      (ew[i] = in.nextInt());
    }
    out.println(Code02_MinimumDifference1::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MinimumDifference1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最小差值生成树，java版
// 一共n个点、m条无向边，给定每条边的两个端点和边权
// 题目保证图连通，图中可能存在自环，选择一棵生成树
// 希望树中最大边权减去最小边权的值尽量小，打印该值
// 1 <= n <= 5 * 10^4
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4234
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // removed[i]表示第i条边是否被淘汰
        // 辅助splay
        // minEdge[x]表示以x为根的辅助splay中，编号最小的边
        // 因为按照权值从小到大排序，所以编号最小就是边权最小
        // 手撸双指针快排，根据边权从小到大排序
        // 读写工具类
*/
