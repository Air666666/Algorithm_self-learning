// Source: src/class203/Code01_WaterManager1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_WaterManager1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> ew = make_array<int>(MAXN);
  inline static Array<int> qop = make_array<int>(MAXN);
  inline static Array<int> qx = make_array<int>(MAXN);
  inline static Array<int> qy = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<bool> deleted = make_array<bool>(MAXN);
  inline static JMap<i64, int> edgeMap = JMap<i64, int>();
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> maxEdge = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_WaterManager1() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code01_WaterManager1::find(father[x]));
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
    Code01_WaterManager1::sort(l, j);
    Code01_WaterManager1::sort(i, r);
  }
  static void up(int x) {
    (maxEdge[x] = ((x <= n) ? 0 : (x - n)));
    if ((ew[maxEdge[ls[x]]] > ew[maxEdge[x]])) {
      (maxEdge[x] = maxEdge[ls[x]]);
    }
    if ((ew[maxEdge[rs[x]]] > ew[maxEdge[x]])) {
      (maxEdge[x] = maxEdge[rs[x]]);
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
      Code01_WaterManager1::reverse(ls[x]);
      Code01_WaterManager1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code01_WaterManager1::lr(x) == 0)) {
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
    if ((!Code01_WaterManager1::isroot(f))) {
      if ((Code01_WaterManager1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code01_WaterManager1::up(f);
    Code01_WaterManager1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code01_WaterManager1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code01_WaterManager1::down(sta[(siz--)]);
    }
    while ((!Code01_WaterManager1::isroot(x))) {
      int f = fa[x];
      if ((!Code01_WaterManager1::isroot(f))) {
        if ([&]() {
              auto jleft = Code01_WaterManager1::lr(x);
              auto jright = Code01_WaterManager1::lr(f);
              return (jleft == jright);
            }()) {
          Code01_WaterManager1::rotate(f);
        } else {
          Code01_WaterManager1::rotate(x);
        }
      }
      Code01_WaterManager1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code01_WaterManager1::splay(x);
      (rs[x] = y);
      Code01_WaterManager1::up(x);
    }
  }
  static void makeroot(int x) {
    Code01_WaterManager1::access(x);
    Code01_WaterManager1::splay(x);
    Code01_WaterManager1::reverse(x);
  }
  static int findroot(int x) {
    Code01_WaterManager1::access(x);
    Code01_WaterManager1::splay(x);
    Code01_WaterManager1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code01_WaterManager1::down(x);
    }
    Code01_WaterManager1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code01_WaterManager1::makeroot(x);
    Code01_WaterManager1::access(y);
    Code01_WaterManager1::splay(y);
  }
  static void link(int x, int y) {
    Code01_WaterManager1::makeroot(x);
    if ((Code01_WaterManager1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code01_WaterManager1::makeroot(x);
    if (((((Code01_WaterManager1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code01_WaterManager1::up(x);
    }
  }
  static i64 key(int x, int y) {
    int a = jmin(x, y);
    int b = jmax(x, y);
    return (jshl(static_cast<i64>(a), 32) | b);
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    Code01_WaterManager1::sort(1, m);
    for (int i = 1; (i <= m); (i++)) {
      edgeMap.put(Code01_WaterManager1::key(ex[i], ey[i]), i);
    }
    for (int i = 1; (i <= q); (i++)) {
      if ((qop[i] == 2)) {
        (deleted[edgeMap.get(Code01_WaterManager1::key(qx[i], qy[i]))] = true);
      }
    }
    int edgeCnt = 0;
    for (int i = 1; ((i <= m) && (edgeCnt != (n - 1))); (i++)) {
      if ((!deleted[i])) {
        int x = ex[i];
        int y = ey[i];
        int fx = Code01_WaterManager1::find(x);
        int fy = Code01_WaterManager1::find(y);
        if ((fx != fy)) {
          (father[fx] = fy);
          Code01_WaterManager1::link(x, (n + i));
          Code01_WaterManager1::link(y, (n + i));
          (edgeCnt++);
        }
      }
    }
  }
  static void addEdge(int e) {
    Code01_WaterManager1::split(ex[e], ey[e]);
    int maxe = maxEdge[ey[e]];
    if ((ew[e] < ew[maxe])) {
      Code01_WaterManager1::cut(ex[maxe], (n + maxe));
      Code01_WaterManager1::cut(ey[maxe], (n + maxe));
      Code01_WaterManager1::link(ex[e], (n + e));
      Code01_WaterManager1::link(ey[e], (n + e));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (ex[i] = in.nextInt());
      (ey[i] = in.nextInt());
      (ew[i] = in.nextInt());
    }
    for (int i = 1; (i <= q); (i++)) {
      (qop[i] = in.nextInt());
      (qx[i] = in.nextInt());
      (qy[i] = in.nextInt());
    }
    Code01_WaterManager1::prepare();
    for (int i = q; (i >= 1); (i--)) {
      if ((qop[i] == 1)) {
        Code01_WaterManager1::split(qx[i], qy[i]);
        (ans[i] = ew[maxEdge[qy[i]]]);
      } else {
        Code01_WaterManager1::addEdge(
            edgeMap.get(Code01_WaterManager1::key(qx[i], qy[i])));
      }
    }
    for (int i = 1; (i <= q); (i++)) {
      if ((qop[i] == 1)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_WaterManager1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 水管局长，java版
// 一共n个点、m条无向边，给定每条边的两个端点和边权
// 接下来有q条操作，每条操作是如下两种类型中的一种
// 操作 1 x y : 打印点x到点y的所有路径中，最大边权的最小值
// 操作 2 x y : 删除点x和点y之间的直接边，该边一定存在
// 题目保证任何时刻图都连通，并且无重边无自环
// 1 <= n <= 10^3
// 1 <= m、q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4172
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集
        // 时光倒流加边
        // 辅助splay
        // maxEdge[x]表示以x为根的辅助splay中，权值最大的边的编号
        // 手撸双指针快排，根据边权从小到大排序
        // 读写工具类
*/
