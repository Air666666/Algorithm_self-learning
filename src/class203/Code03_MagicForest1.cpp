// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2387

// Source: src/class203/Code03_MagicForest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MagicForest1 {
  inline static int MAXN = 200001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> ea = make_array<int>(MAXN);
  inline static Array<int> eb = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> maxaEdge = make_array<int>(MAXN);
  inline static Array<int> maxbEdge = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MagicForest1() {}
  static void sort(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = ea[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((ea[i] < pivot))
        (i++);
      while ((ea[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = ex[i]);
        (ex[i] = ex[j]);
        (ex[j] = tmp);
        (tmp = ey[i]);
        (ey[i] = ey[j]);
        (ey[j] = tmp);
        (tmp = ea[i]);
        (ea[i] = ea[j]);
        (ea[j] = tmp);
        (tmp = eb[i]);
        (eb[i] = eb[j]);
        (eb[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code03_MagicForest1::sort(l, j);
    Code03_MagicForest1::sort(i, r);
  }
  static void up(int x) {
    (maxaEdge[x] = ((x <= n) ? 0 : (x - n)));
    if ((ea[maxaEdge[ls[x]]] > ea[maxaEdge[x]])) {
      (maxaEdge[x] = maxaEdge[ls[x]]);
    }
    if ((ea[maxaEdge[rs[x]]] > ea[maxaEdge[x]])) {
      (maxaEdge[x] = maxaEdge[rs[x]]);
    }
    (maxbEdge[x] = ((x <= n) ? 0 : (x - n)));
    if ((eb[maxbEdge[ls[x]]] > eb[maxbEdge[x]])) {
      (maxbEdge[x] = maxbEdge[ls[x]]);
    }
    if ((eb[maxbEdge[rs[x]]] > eb[maxbEdge[x]])) {
      (maxbEdge[x] = maxbEdge[rs[x]]);
    }
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
      Code03_MagicForest1::reverse(ls[x]);
      Code03_MagicForest1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code03_MagicForest1::lr(x) == 0)) {
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
    if ((!Code03_MagicForest1::isroot(f))) {
      if ((Code03_MagicForest1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code03_MagicForest1::up(f);
    Code03_MagicForest1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code03_MagicForest1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code03_MagicForest1::down(sta[(siz--)]);
    }
    while ((!Code03_MagicForest1::isroot(x))) {
      int f = fa[x];
      if ((!Code03_MagicForest1::isroot(f))) {
        if ([&]() {
              auto jleft = Code03_MagicForest1::lr(x);
              auto jright = Code03_MagicForest1::lr(f);
              return (jleft == jright);
            }()) {
          Code03_MagicForest1::rotate(f);
        } else {
          Code03_MagicForest1::rotate(x);
        }
      }
      Code03_MagicForest1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code03_MagicForest1::splay(x);
      (rs[x] = y);
      Code03_MagicForest1::up(x);
    }
  }
  static void makeroot(int x) {
    Code03_MagicForest1::access(x);
    Code03_MagicForest1::splay(x);
    Code03_MagicForest1::reverse(x);
  }
  static int findroot(int x) {
    Code03_MagicForest1::access(x);
    Code03_MagicForest1::splay(x);
    Code03_MagicForest1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code03_MagicForest1::down(x);
    }
    Code03_MagicForest1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code03_MagicForest1::makeroot(x);
    Code03_MagicForest1::access(y);
    Code03_MagicForest1::splay(y);
  }
  static void link(int x, int y) {
    Code03_MagicForest1::makeroot(x);
    if ((Code03_MagicForest1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code03_MagicForest1::makeroot(x);
    if (((((Code03_MagicForest1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code03_MagicForest1::up(x);
    }
  }
  static int compute() {
    Code03_MagicForest1::sort(1, m);
    int ans = INF;
    for (int i = 1; (i <= m); (i++)) {
      int x = ex[i];
      int y = ey[i];
      if ((x != y)) {
        Code03_MagicForest1::makeroot(x);
        if ((Code03_MagicForest1::findroot(y) != x)) {
          Code03_MagicForest1::link(x, (n + i));
          Code03_MagicForest1::link(y, (n + i));
        } else {
          Code03_MagicForest1::split(x, y);
          int pre = maxbEdge[y];
          if ((eb[i] < eb[pre])) {
            Code03_MagicForest1::cut(ex[pre], (n + pre));
            Code03_MagicForest1::cut(ey[pre], (n + pre));
            Code03_MagicForest1::link(x, (n + i));
            Code03_MagicForest1::link(y, (n + i));
          }
        }
      }
      Code03_MagicForest1::makeroot(1);
      if ((Code03_MagicForest1::findroot(n) == 1)) {
        Code03_MagicForest1::split(1, n);
        (ans = jmin(ans, (ea[maxaEdge[n]] + eb[maxbEdge[n]])));
      }
    }
    return ((ans == INF) ? (-1) : ans);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (ex[i] = in.nextInt());
      (ey[i] = in.nextInt());
      (ea[i] = in.nextInt());
      (eb[i] = in.nextInt());
    }
    int ans = Code03_MagicForest1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_MagicForest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 魔法森林，java版
// 无向图有n个点、m条边，每条边有a、b两种权值，可能存在重边和自环
// 定义路径的代价为，路径上最大的a + 路径上最大的b
// 选择1号点到n号点的路径，打印路径代价的最小值，无法到达打印-1
// 2 <= n <= 5 * 10^4
// 0 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2387
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // maxaEdge[x]表示以x为根的辅助splay中，最大a权值的边的编号
        // maxbEdge[x]表示以x为根的辅助splay中，最大b权值的边的编号
        // 手撸双指针快排，根据a权值从小到大排序
        // 读写工具类
*/
