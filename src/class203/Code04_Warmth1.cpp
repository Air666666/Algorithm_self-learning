// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6664
// https://uoj.ac/problem/274

// Source: src/class203/Code04_Warmth1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Warmth1 {
  inline static int MAXN = 400001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> et = make_array<int>(MAXN);
  inline static Array<int> el = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static Array<int> mintEdge = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Warmth1() {}
  static void up(int x) {
    int e = ((x <= n) ? 0 : (x - n));
    (sum[x] = ((sum[ls[x]] + sum[rs[x]]) + el[e]));
    (mintEdge[x] = e);
    if ((et[mintEdge[ls[x]]] < et[mintEdge[x]])) {
      (mintEdge[x] = mintEdge[ls[x]]);
    }
    if ((et[mintEdge[rs[x]]] < et[mintEdge[x]])) {
      (mintEdge[x] = mintEdge[rs[x]]);
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
      Code04_Warmth1::reverse(ls[x]);
      Code04_Warmth1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code04_Warmth1::lr(x) == 0)) {
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
    if ((!Code04_Warmth1::isroot(f))) {
      if ((Code04_Warmth1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code04_Warmth1::up(f);
    Code04_Warmth1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code04_Warmth1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code04_Warmth1::down(sta[(siz--)]);
    }
    while ((!Code04_Warmth1::isroot(x))) {
      int f = fa[x];
      if ((!Code04_Warmth1::isroot(f))) {
        if ([&]() {
              auto jleft = Code04_Warmth1::lr(x);
              auto jright = Code04_Warmth1::lr(f);
              return (jleft == jright);
            }()) {
          Code04_Warmth1::rotate(f);
        } else {
          Code04_Warmth1::rotate(x);
        }
      }
      Code04_Warmth1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code04_Warmth1::splay(x);
      (rs[x] = y);
      Code04_Warmth1::up(x);
    }
  }
  static void makeroot(int x) {
    Code04_Warmth1::access(x);
    Code04_Warmth1::splay(x);
    Code04_Warmth1::reverse(x);
  }
  static int findroot(int x) {
    Code04_Warmth1::access(x);
    Code04_Warmth1::splay(x);
    Code04_Warmth1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code04_Warmth1::down(x);
    }
    Code04_Warmth1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code04_Warmth1::makeroot(x);
    Code04_Warmth1::access(y);
    Code04_Warmth1::splay(y);
  }
  static void link(int x, int y) {
    Code04_Warmth1::makeroot(x);
    if ((Code04_Warmth1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code04_Warmth1::makeroot(x);
    if (((((Code04_Warmth1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code04_Warmth1::up(x);
    }
  }
  static void addEdge(int e) {
    int x = ex[e];
    int y = ey[e];
    Code04_Warmth1::makeroot(x);
    if ((Code04_Warmth1::findroot(y) != x)) {
      Code04_Warmth1::link(x, (n + e));
      Code04_Warmth1::link(y, (n + e));
    } else {
      Code04_Warmth1::split(x, y);
      int p = mintEdge[y];
      if ((et[e] > et[p])) {
        Code04_Warmth1::cut(ex[p], (n + p));
        Code04_Warmth1::cut(ey[p], (n + p));
        Code04_Warmth1::link(x, (n + e));
        Code04_Warmth1::link(y, (n + e));
      }
    }
  }
  static void change(int e, int l) {
    Code04_Warmth1::splay((n + e));
    (el[e] = l);
    Code04_Warmth1::up((n + e));
  }
  static int query(int x, int y) {
    Code04_Warmth1::makeroot(x);
    if ((Code04_Warmth1::findroot(y) != x)) {
      return (-1);
    }
    Code04_Warmth1::split(x, y);
    return sum[y];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (et[0] = INF);
    String op = {};
    int e = {};
    int x = {};
    int y = {};
    int t = {};
    int l = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextString());
      if (op.equals(String(u"find"))) {
        (e = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        (t = in.nextInt());
        (l = in.nextInt());
        (e++);
        (x++);
        (y++);
        (ex[e] = x);
        (ey[e] = y);
        (et[e] = t);
        (el[e] = l);
        Code04_Warmth1::addEdge(e);
      } else if (op.equals(String(u"move"))) {
        (x = in.nextInt());
        (y = in.nextInt());
        (x++);
        (y++);
        out.println(Code04_Warmth1::query(x, y));
      } else {
        (e = in.nextInt());
        (l = in.nextInt());
        (e++);
        Code04_Warmth1::change(e, l);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Warmth1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 温暖会指引我们前行，java版
// 一共n个地点，地点之间的道路是无向边，每条道路有温度和长度两种权值
// 初始时没有任何道路，之后出现的所有道路，温度互不相同
// 对于点x到点y的每一条路径，将路径上的道路按温度升序排列，形成该路径的温度序列
// 温度序列字典序最大的路径叫做最佳路径，因为道路温度互不相同，所以最佳路径唯一
// 接下来有m条操作，操作类型有三种，具体格式如下
// find e x y t l : 建立编号为e的边，端点x和y、温度t、长度l，编号保证唯一
// move x y       : 打印点x到点y最佳路径的长度总和，如果不连通打印-1
// change e l     : 编号为e的道路长度修改为l，该道路保证已经建立
// 1 <= n <= 10^5    1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6664
// 测试链接 : https://uoj.ac/problem/274
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 辅助splay
        // sumLen[x]表示以x为根的辅助splay中，边长累加和
        // minEdge[x]表示以x为根的辅助splay中，温度最低的边的编号
        // 读写工具类
*/
