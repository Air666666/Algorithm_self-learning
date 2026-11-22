// Source: src/class204/Code06_NewBarns1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_NewBarns1 {
  inline static int MAXN = 100001;
  inline static int q = {};
  inline static int cntn = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> diameter = make_array<int>(MAXN);
  inline static Array<int> dl = make_array<int>(MAXN);
  inline static Array<int> dr = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_NewBarns1() {}
  static int find(int x) {
    if ((father[x] != x)) {
      (father[x] = Code06_NewBarns1::find(father[x]));
    }
    return father[x];
  }
  static void up(int x) { (siz[x] = ((siz[ls[x]] + siz[rs[x]]) + 1)); }
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
      Code06_NewBarns1::reverse(ls[x]);
      Code06_NewBarns1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code06_NewBarns1::lr(x) == 0)) {
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
    if ((!Code06_NewBarns1::isroot(f))) {
      if ((Code06_NewBarns1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code06_NewBarns1::up(f);
    Code06_NewBarns1::up(x);
  }
  static void splay(int x) {
    int size = 0;
    (sta[(++size)] = x);
    for (int y = x; (!Code06_NewBarns1::isroot(y)); (y = fa[y])) {
      (sta[(++size)] = fa[y]);
    }
    while ((size != 0)) {
      Code06_NewBarns1::down(sta[(size--)]);
    }
    while ((!Code06_NewBarns1::isroot(x))) {
      int f = fa[x];
      if ((!Code06_NewBarns1::isroot(f))) {
        if ([&]() {
              auto jleft = Code06_NewBarns1::lr(x);
              auto jright = Code06_NewBarns1::lr(f);
              return (jleft == jright);
            }()) {
          Code06_NewBarns1::rotate(f);
        } else {
          Code06_NewBarns1::rotate(x);
        }
      }
      Code06_NewBarns1::rotate(x);
    }
    Code06_NewBarns1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code06_NewBarns1::splay(x);
      (rs[x] = y);
      Code06_NewBarns1::up(x);
    }
  }
  static void makeroot(int x) {
    Code06_NewBarns1::access(x);
    Code06_NewBarns1::splay(x);
    Code06_NewBarns1::reverse(x);
  }
  static int findroot(int x) {
    Code06_NewBarns1::access(x);
    Code06_NewBarns1::splay(x);
    Code06_NewBarns1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code06_NewBarns1::down(x);
    }
    Code06_NewBarns1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code06_NewBarns1::makeroot(x);
    Code06_NewBarns1::access(y);
    Code06_NewBarns1::splay(y);
  }
  static void link(int x, int y) {
    Code06_NewBarns1::makeroot(x);
    if ((Code06_NewBarns1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static int getDist(int x, int y) {
    Code06_NewBarns1::split(x, y);
    return (siz[y] - 1);
  }
  static void build(int p) {
    int x = (++cntn);
    (siz[x] = 1);
    (father[x] = x);
    (dl[x] = x);
    (dr[x] = x);
    (diameter[x] = 0);
    if ((p != (-1))) {
      int root = Code06_NewBarns1::find(p);
      int a = dl[root];
      int b = dr[root];
      int best = diameter[root];
      int bestl = a;
      int bestr = b;
      Code06_NewBarns1::link(x, p);
      int dista = Code06_NewBarns1::getDist(x, a);
      if ((dista > best)) {
        (best = dista);
        (bestl = x);
        (bestr = a);
      }
      int distb = Code06_NewBarns1::getDist(x, b);
      if ((distb > best)) {
        (best = distb);
        (bestl = x);
        (bestr = b);
      }
      (father[x] = root);
      (dl[root] = bestl);
      (dr[root] = bestr);
      (diameter[root] = best);
    }
  }
  static int query(int x) {
    int fx = Code06_NewBarns1::find(x);
    return [&]() {
      auto jargument_0 = Code06_NewBarns1::getDist(x, dl[fx]);
      auto jargument_1 = Code06_NewBarns1::getDist(x, dr[fx]);
      return jmax(jargument_0, jargument_1);
    }();
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (q = in.nextInt());
    String op = {};
    int x = {};
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextString());
      (x = in.nextInt());
      if (op.equals(String(u"B"))) {
        Code06_NewBarns1::build(x);
      } else {
        out.println(Code06_NewBarns1::query(x));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_NewBarns1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 查询最远距离，java版
// 初始没有节点，接下来有q条操作，操作类型如下
// 操作 B p : 新建一个节点，并与节点p连接，如果p为-1则新建一个独立节点
// 操作 Q x : 打印节点x到所在连通块中最远节点的距离
// 1 <= q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4271
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // siz[x]表示以x为根的辅助splay的节点数量
        // 节点数量-1是实链的边的数量，方便查出距离
        // 并查集维护连通性，连通块先查代表节点root
        // diameter[root]就是连通块的直径长度
        // dl[root]和dr[root]就是连通块的直径端点
        // 节点数量-1就是边的数量
                // 初始时，新节点是独立的连通块
                        // 得到原连通块的直径端点和直径长度
                        // 新的直径可能就是老的直径
                        // 或者新节点x与旧直径的某个端点组成的路径
        // 某点在树中的最远点，一定是直径的两个端点的其中之一
        // 读写工具类
*/
