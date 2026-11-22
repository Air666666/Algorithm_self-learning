// Source: src/class202/Code07_Flight1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Flight1 {
  inline static int MAXN = 30001;
  inline static int MAXM = 100001;
  inline static int MAXQ = 40001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> ex = make_array<int>(MAXM);
  inline static Array<int> ey = make_array<int>(MAXM);
  inline static Array<int> qop = make_array<int>(MAXQ);
  inline static Array<int> qx = make_array<int>(MAXQ);
  inline static Array<int> qy = make_array<int>(MAXQ);
  inline static Array<int> queryAns = make_array<int>(MAXQ);
  inline static int queryCnt = {};
  inline static Array<bool> deleted = make_array<bool>(MAXM);
  inline static JMap<i64, int> edgeMap = JMap<i64, int>();
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> ebcc = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Flight1() {}
  static int find(int x) {
    if ((x != father[x])) {
      (father[x] = Code07_Flight1::find(father[x]));
    }
    return father[x];
  }
  static void up(int x) { (ebcc[x] = ((ebcc[ls[x]] + ebcc[rs[x]]) + 1)); }
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
      Code07_Flight1::reverse(ls[x]);
      Code07_Flight1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code07_Flight1::lr(x) == 0)) {
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
    if ((!Code07_Flight1::isroot(f))) {
      if ((Code07_Flight1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code07_Flight1::up(f);
    Code07_Flight1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code07_Flight1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code07_Flight1::down(sta[(siz--)]);
    }
    while ((!Code07_Flight1::isroot(x))) {
      int f = fa[x];
      if ((!Code07_Flight1::isroot(f))) {
        if ([&]() {
              auto jleft = Code07_Flight1::lr(x);
              auto jright = Code07_Flight1::lr(f);
              return (jleft == jright);
            }()) {
          Code07_Flight1::rotate(f);
        } else {
          Code07_Flight1::rotate(x);
        }
      }
      Code07_Flight1::rotate(x);
    }
  }
  static void access(int x) {
    (x = Code07_Flight1::find(x));
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code07_Flight1::splay(x);
      (rs[x] = y);
      Code07_Flight1::up(x);
      (fa[x] = Code07_Flight1::find(fa[x]));
    }
  }
  static void makeroot(int x) {
    Code07_Flight1::access(x);
    Code07_Flight1::splay(x);
    Code07_Flight1::reverse(x);
  }
  static int findroot(int x) {
    Code07_Flight1::access(x);
    Code07_Flight1::splay(x);
    Code07_Flight1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code07_Flight1::down(x);
    }
    Code07_Flight1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code07_Flight1::makeroot(x);
    Code07_Flight1::access(y);
    Code07_Flight1::splay(y);
  }
  static void condense(int x, int root) {
    if ((x != 0)) {
      (father[x] = root);
      Code07_Flight1::condense(ls[x], root);
      Code07_Flight1::condense(rs[x], root);
    }
  }
  static void link(int x, int y) {
    (x = Code07_Flight1::find(x));
    (y = Code07_Flight1::find(y));
    if ((x == y)) {
      return;
    }
    Code07_Flight1::makeroot(x);
    if ((Code07_Flight1::findroot(y) != x)) {
      (fa[x] = y);
    } else {
      Code07_Flight1::condense(rs[x], x);
      (rs[x] = 0);
      Code07_Flight1::up(x);
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
      (ebcc[i] = 1);
    }
    for (int i = 1; (i <= m); (i++)) {
      edgeMap.put(Code07_Flight1::key(ex[i], ey[i]), i);
    }
    for (int i = 1; (i <= q); (i++)) {
      if ((qop[i] == 0)) {
        (deleted[edgeMap.get(Code07_Flight1::key(qx[i], qy[i]))] = true);
      } else {
        (queryCnt++);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((!deleted[i])) {
        Code07_Flight1::link(ex[i], ey[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (ex[i] = in.nextInt());
      (ey[i] = in.nextInt());
    }
    int op = in.nextInt();
    while ((op != (-1))) {
      (qop[(++q)] = op);
      (qx[q] = in.nextInt());
      (qy[q] = in.nextInt());
      (op = in.nextInt());
    }
    Code07_Flight1::prepare();
    {
      int i = q;
      int j = queryCnt;
      for (; (i >= 1); (i--)) {
        int x = Code07_Flight1::find(qx[i]);
        int y = Code07_Flight1::find(qy[i]);
        if ((qop[i] == 0)) {
          Code07_Flight1::link(x, y);
        } else {
          if ((x == y)) {
            (queryAns[(j--)] = 0);
          } else {
            Code07_Flight1::split(x, y);
            (queryAns[(j--)] = (ebcc[y] - 1));
          }
        }
      }
    }
    for (int i = 1; (i <= queryCnt); (i++)) {
      out.println(queryAns[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Flight1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 航线规划，java版
// 一共有n个点，m条无向边，任何时刻图连通，没有重边
// 一共有q条操作，操作有两种类型，具体格式如下
// 操作 0 x y : 删除点x和点y之间的直接边
// 操作 1 x y : 查询点x和点y之间有多少条必经边
// 1 <= n <= 3 * 10^4
// 1 <= m <= 10^5
// 1 <= q <= 4 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2542
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 并查集，维护每个点归属的边双连通分量
        // 辅助splay
        // ebcc[x]表示以x为根的辅助splay，有多少个边双连通分量
        // 读写工具类
*/
