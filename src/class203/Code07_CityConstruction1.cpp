// Source: src/class203/Code07_CityConstruction1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_CityConstruction1 {
  inline static int MAXN = 200001;
  inline static int MAXQ = 50001;
  inline static int MAXT = 4000001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> ew = make_array<int>(MAXN);
  inline static int cnte = {};
  inline static Array<int> changeEdge = make_array<int>(MAXQ);
  inline static Array<int> endTime = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(jshl(MAXQ, 2));
  inline static Array<int> nxt = make_array<int>(MAXT);
  inline static Array<int> to = make_array<int>(MAXT);
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> maxEdge = make_array<int>(MAXN);
  inline static Array<int> rollbackEdge = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> rollbackType = make_array<int>(jshl(MAXN, 1));
  inline static int opsize = {};
  inline static i64 mstSum = {};
  inline static Array<i64> ans = make_array<i64>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_CityConstruction1() {}
  static void rangeAddEdge(int i, int e) {
    (nxt[(++cntg)] = head[i]);
    (to[cntg] = e);
    (head[i] = cntg);
  }
  static void add(int jobl, int jobr, int jobe, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code07_CityConstruction1::rangeAddEdge(i, jobe);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code07_CityConstruction1::add(jobl, jobr, jobe, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code07_CityConstruction1::add(jobl, jobr, jobe, (mid + 1), r,
                                      (jshl(i, 1) | 1));
      }
    }
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
      Code07_CityConstruction1::reverse(ls[x]);
      Code07_CityConstruction1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code07_CityConstruction1::lr(x) == 0)) {
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
    if ((!Code07_CityConstruction1::isroot(f))) {
      if ((Code07_CityConstruction1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code07_CityConstruction1::up(f);
    Code07_CityConstruction1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code07_CityConstruction1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code07_CityConstruction1::down(sta[(siz--)]);
    }
    while ((!Code07_CityConstruction1::isroot(x))) {
      int f = fa[x];
      if ((!Code07_CityConstruction1::isroot(f))) {
        if ([&]() {
              auto jleft = Code07_CityConstruction1::lr(x);
              auto jright = Code07_CityConstruction1::lr(f);
              return (jleft == jright);
            }()) {
          Code07_CityConstruction1::rotate(f);
        } else {
          Code07_CityConstruction1::rotate(x);
        }
      }
      Code07_CityConstruction1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code07_CityConstruction1::splay(x);
      (rs[x] = y);
      Code07_CityConstruction1::up(x);
    }
  }
  static void makeroot(int x) {
    Code07_CityConstruction1::access(x);
    Code07_CityConstruction1::splay(x);
    Code07_CityConstruction1::reverse(x);
  }
  static int findroot(int x) {
    Code07_CityConstruction1::access(x);
    Code07_CityConstruction1::splay(x);
    Code07_CityConstruction1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code07_CityConstruction1::down(x);
    }
    Code07_CityConstruction1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code07_CityConstruction1::makeroot(x);
    Code07_CityConstruction1::access(y);
    Code07_CityConstruction1::splay(y);
  }
  static void link(int x, int y) {
    Code07_CityConstruction1::makeroot(x);
    if ((Code07_CityConstruction1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code07_CityConstruction1::makeroot(x);
    if (((((Code07_CityConstruction1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code07_CityConstruction1::up(x);
    }
  }
  static void backup(int edge, int type) {
    (rollbackEdge[(++opsize)] = edge);
    (rollbackType[opsize] = type);
  }
  static void addEdge(int e) {
    int x = ex[e];
    int y = ey[e];
    Code07_CityConstruction1::makeroot(x);
    if ((Code07_CityConstruction1::findroot(y) != x)) {
      Code07_CityConstruction1::link(x, (n + e));
      Code07_CityConstruction1::link(y, (n + e));
      Code07_CityConstruction1::backup(e, 1);
      (mstSum += ew[e]);
    } else {
      Code07_CityConstruction1::split(x, y);
      int pre = maxEdge[y];
      if ((ew[pre] > ew[e])) {
        Code07_CityConstruction1::cut(ex[pre], (n + pre));
        Code07_CityConstruction1::cut(ey[pre], (n + pre));
        Code07_CityConstruction1::backup(pre, 2);
        (mstSum -= ew[pre]);
        Code07_CityConstruction1::link(x, (n + e));
        Code07_CityConstruction1::link(y, (n + e));
        Code07_CityConstruction1::backup(e, 1);
        (mstSum += ew[e]);
      }
    }
  }
  static void undo() {
    int e = rollbackEdge[opsize];
    int t = rollbackType[(opsize--)];
    if ((t == 1)) {
      Code07_CityConstruction1::cut(ex[e], (n + e));
      Code07_CityConstruction1::cut(ey[e], (n + e));
      (mstSum -= ew[e]);
    } else {
      Code07_CityConstruction1::link(ex[e], (n + e));
      Code07_CityConstruction1::link(ey[e], (n + e));
      (mstSum += ew[e]);
    }
  }
  static void dfs(int l, int r, int i) {
    int tmp = opsize;
    for (int k = head[i]; (k != 0); (k = nxt[k])) {
      Code07_CityConstruction1::addEdge(to[k]);
    }
    if ((l == r)) {
      (ans[l] = mstSum);
    } else {
      int mid = jshr((l + r), 1);
      Code07_CityConstruction1::dfs(l, mid, jshl(i, 1));
      Code07_CityConstruction1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    while ((opsize > tmp)) {
      Code07_CityConstruction1::undo();
    }
  }
  static void prepare() {
    for (int i = 1; (i <= m); (i++)) {
      (endTime[i] = (q + 1));
    }
    for (int i = q; (i >= 1); (i--)) {
      int e = changeEdge[i];
      Code07_CityConstruction1::add(i, (endTime[e] - 1), (m + i), 1, q, 1);
      (endTime[e] = i);
    }
    for (int i = 1; (i <= m); (i++)) {
      if ((endTime[i] > 1)) {
        Code07_CityConstruction1::add(1, (endTime[i] - 1), i, 1, q, 1);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (cnte = m);
    for (int i = 1; (i <= m); (i++)) {
      (ex[i] = in.nextInt());
      (ey[i] = in.nextInt());
      (ew[i] = in.nextInt());
    }
    for (int i = 1; (i <= q); (i++)) {
      int e = in.nextInt();
      int w = in.nextInt();
      (changeEdge[i] = e);
      (ex[(++cnte)] = ex[e]);
      (ey[cnte] = ey[e]);
      (ew[cnte] = w);
    }
    Code07_CityConstruction1::prepare();
    Code07_CityConstruction1::dfs(1, q, 1);
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_CityConstruction1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 城市建设，java版
// 一共n个点、m条无向边，边有边权，编号1~m，图保证连通
// 接下来有q次修改，格式 e w，代表第e条边的边权修改为w
// 每次修改之后，打印当前图的最小生成树边权和
// 1 <= n <= 2 * 10^4
// 1 <= m、q <= 5 * 10^4
// 0 <= 边权 <= 5 * 10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3206
// 提交以下的code，提交时请把类名改成"Main"
// 本题卡常数时间，java的实现会有部分测试用例超时
// 想通过用C++实现，本节课Code07_CityConstruction2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/
