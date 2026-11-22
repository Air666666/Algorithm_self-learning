// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4180

// Source: src/class203/Code05_StrictSecondMinimum3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_StrictSecondMinimum3 {
  inline static int MAXN = 400001;
  inline static int MAXM = 300001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> ex = make_array<int>(MAXM);
  inline static Array<int> ey = make_array<int>(MAXM);
  inline static Array<int> ew = make_array<int>(MAXM);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> max1 = make_array<int>(MAXN);
  inline static Array<int> max2 = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_StrictSecondMinimum3() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code05_StrictSecondMinimum3::find(father[x]));
    }
    return father[x];
  }
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
    Code05_StrictSecondMinimum3::sort(l, j);
    Code05_StrictSecondMinimum3::sort(i, r);
  }
  static void up(int x) {
    int l = ls[x];
    int lmax1 = max1[l];
    int lmax2 = max2[l];
    int r = rs[x];
    int rmax1 = max1[r];
    int rmax2 = max2[r];
    if ((lmax1 > rmax1)) {
      (max1[x] = lmax1);
      (max2[x] = jmax(rmax1, lmax2));
    } else if ((rmax1 > lmax1)) {
      (max1[x] = rmax1);
      (max2[x] = jmax(lmax1, rmax2));
    } else {
      (max1[x] = lmax1);
      (max2[x] = jmax(lmax2, rmax2));
    }
    int v = ((x <= n) ? (-INF) : ew[(x - n)]);
    if ((v > max1[x])) {
      (max2[x] = max1[x]);
      (max1[x] = v);
    } else if (((v < max1[x]) && (v > max2[x]))) {
      (max2[x] = v);
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
      Code05_StrictSecondMinimum3::reverse(ls[x]);
      Code05_StrictSecondMinimum3::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code05_StrictSecondMinimum3::lr(x) == 0)) {
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
    if ((!Code05_StrictSecondMinimum3::isroot(f))) {
      if ((Code05_StrictSecondMinimum3::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code05_StrictSecondMinimum3::up(f);
    Code05_StrictSecondMinimum3::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code05_StrictSecondMinimum3::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code05_StrictSecondMinimum3::down(sta[(siz--)]);
    }
    while ((!Code05_StrictSecondMinimum3::isroot(x))) {
      int f = fa[x];
      if ((!Code05_StrictSecondMinimum3::isroot(f))) {
        if ([&]() {
              auto jleft = Code05_StrictSecondMinimum3::lr(x);
              auto jright = Code05_StrictSecondMinimum3::lr(f);
              return (jleft == jright);
            }()) {
          Code05_StrictSecondMinimum3::rotate(f);
        } else {
          Code05_StrictSecondMinimum3::rotate(x);
        }
      }
      Code05_StrictSecondMinimum3::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code05_StrictSecondMinimum3::splay(x);
      (rs[x] = y);
      Code05_StrictSecondMinimum3::up(x);
    }
  }
  static void makeroot(int x) {
    Code05_StrictSecondMinimum3::access(x);
    Code05_StrictSecondMinimum3::splay(x);
    Code05_StrictSecondMinimum3::reverse(x);
  }
  static void split(int x, int y) {
    Code05_StrictSecondMinimum3::makeroot(x);
    Code05_StrictSecondMinimum3::access(y);
    Code05_StrictSecondMinimum3::splay(y);
  }
  static void link(int x, int y) {
    Code05_StrictSecondMinimum3::makeroot(x);
    (fa[x] = y);
  }
  static i64 compute() {
    Code05_StrictSecondMinimum3::sort(1, m);
    i64 sum = 0;
    int minAdd = INF;
    for (int i = 1; (i <= m); (i++)) {
      int x = ex[i];
      int y = ey[i];
      int w = ew[i];
      if ((x != y)) {
        int fx = Code05_StrictSecondMinimum3::find(x);
        int fy = Code05_StrictSecondMinimum3::find(y);
        if ((fx != fy)) {
          (father[fx] = fy);
          (max1[(n + i)] = w);
          (max2[(n + i)] = (-INF));
          Code05_StrictSecondMinimum3::link(x, (n + i));
          Code05_StrictSecondMinimum3::link(y, (n + i));
          (sum += w);
        } else {
          Code05_StrictSecondMinimum3::split(x, y);
          int v1 = max1[y];
          int v2 = max2[y];
          if ((w > v1)) {
            (minAdd = jmin(minAdd, (w - v1)));
          } else if (((w == v1) && (v2 != (-INF)))) {
            (minAdd = jmin(minAdd, (w - v2)));
          }
        }
      }
    }
    return (sum + minAdd);
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
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    for (int i = 0; (i <= n); (i++)) {
      (max1[i] = (max2[i] = (-INF)));
    }
    out.println(Code05_StrictSecondMinimum3::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_StrictSecondMinimum3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 严格次小生成树，并查集判断连通性，java版
// 一共n个点、m条无向边，每条边有边权，图中可能存在自环
// 严格次小生成树的边权和，必须严格大于最小生成树的边权和
// 题目保证严格次小生成树一定存在，打印其边权和
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 0 <= 边权 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4180
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集检查连通性，优化常数时间，否则java的实现会被卡常
        // 保证x和y不连通，所以逻辑化简了
        // 读写工具类
*/
