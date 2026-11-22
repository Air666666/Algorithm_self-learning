// Source: src/class161/Code05_Coloring1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Coloring1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> seg = make_array<int>(MAXN);
  inline static int cntd = 0;
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> lcolor = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> rcolor = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Coloring1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code05_Coloring1::dfs1(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    (dfn[u] = (++cntd));
    (seg[cntd] = u);
    if ((son[u] == 0)) {
      return;
    }
    Code05_Coloring1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code05_Coloring1::dfs2(v, v);
        }
      }
    }
  }
  static void push(int fir, int sec, int edg) {
    (fse[stacksize][0] = fir);
    (fse[stacksize][1] = sec);
    (fse[stacksize][2] = edg);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (first = fse[stacksize][0]);
    (second = fse[stacksize][1]);
    (edge = fse[stacksize][2]);
  }
  static void dfs3() {
    (stacksize = 0);
    Code05_Coloring1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code05_Coloring1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_Coloring1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code05_Coloring1::push(to[edge], first, (-1));
        }
      } else {
        {
          int e = head[first];
          int v = {};
          for (; (e > 0); (e = next[e])) {
            (v = to[e]);
            if ((v != second)) {
              (siz[first] += siz[v]);
              if (((son[first] == 0) || (siz[son[first]] < siz[v]))) {
                (son[first] = v);
              }
            }
          }
        }
      }
    }
  }
  static void dfs4() {
    (stacksize = 0);
    Code05_Coloring1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code05_Coloring1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (seg[cntd] = first);
        if ((son[first] == 0)) {
          continue;
        }
        Code05_Coloring1::push(first, second, (-2));
        Code05_Coloring1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code05_Coloring1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code05_Coloring1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    if ((rcolor[jshl(i, 1)] == lcolor[(jshl(i, 1) | 1)])) {
      (sum[i]--);
    }
    (lcolor[i] = lcolor[jshl(i, 1)]);
    (rcolor[i] = rcolor[(jshl(i, 1) | 1)]);
  }
  static void lazy(int i, int v) {
    (sum[i] = 1);
    (lcolor[i] = v);
    (rcolor[i] = v);
    (change[i] = v);
  }
  static void down(int i) {
    if ((change[i] != 0)) {
      Code05_Coloring1::lazy(jshl(i, 1), change[i]);
      Code05_Coloring1::lazy((jshl(i, 1) | 1), change[i]);
      (change[i] = 0);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = 1);
      (lcolor[i] = arr[seg[l]]);
      (rcolor[i] = arr[seg[l]]);
    } else {
      int mid = jdiv((l + r), 2);
      Code05_Coloring1::build(l, mid, jshl(i, 1));
      Code05_Coloring1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code05_Coloring1::up(i);
    }
  }
  static void update(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_Coloring1::lazy(i, jobv);
    } else {
      Code05_Coloring1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code05_Coloring1::update(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code05_Coloring1::update(jobl, jobr, jobv, (mid + 1), r,
                                 (jshl(i, 1) | 1));
      }
      Code05_Coloring1::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    Code05_Coloring1::down(i);
    int mid = jdiv((l + r), 2);
    if ((jobr <= mid)) {
      return Code05_Coloring1::query(jobl, jobr, l, mid, jshl(i, 1));
    } else if ((jobl > mid)) {
      return Code05_Coloring1::query(jobl, jobr, (mid + 1), r,
                                     (jshl(i, 1) | 1));
    } else {
      int ans = [&]() {
        auto jleft = Code05_Coloring1::query(jobl, jobr, l, mid, jshl(i, 1));
        auto jright =
            Code05_Coloring1::query(jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1));
        return (jleft + jright);
      }();
      if ((rcolor[jshl(i, 1)] == lcolor[(jshl(i, 1) | 1)])) {
        (ans--);
      }
      return ans;
    }
  }
  static int pointColor(int jobi, int l, int r, int i) {
    if ((l == r)) {
      return lcolor[i];
    }
    Code05_Coloring1::down(i);
    int mid = jdiv((l + r), 2);
    if ((jobi <= mid)) {
      return Code05_Coloring1::pointColor(jobi, l, mid, jshl(i, 1));
    } else {
      return Code05_Coloring1::pointColor(jobi, (mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void pathUpdate(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code05_Coloring1::update(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code05_Coloring1::update(dfn[top[x]], dfn[x], v, 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = jmin(dfn[x], dfn[y]);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = v;
      auto jargument_3 = 1;
      auto jargument_4 = n;
      auto jargument_5 = 1;
      return Code05_Coloring1::update(jargument_0, jargument_1, jargument_2,
                                      jargument_3, jargument_4, jargument_5);
    }();
  }
  static int pathColors(int x, int y) {
    int ans = 0;
    int sonc = {};
    int fac = {};
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans += Code05_Coloring1::query(dfn[top[y]], dfn[y], 1, n, 1));
        (sonc = Code05_Coloring1::pointColor(dfn[top[y]], 1, n, 1));
        (fac = Code05_Coloring1::pointColor(dfn[fa[top[y]]], 1, n, 1));
        (y = fa[top[y]]);
      } else {
        (ans += Code05_Coloring1::query(dfn[top[x]], dfn[x], 1, n, 1));
        (sonc = Code05_Coloring1::pointColor(dfn[top[x]], 1, n, 1));
        (fac = Code05_Coloring1::pointColor(dfn[fa[top[x]]], 1, n, 1));
        (x = fa[top[x]]);
      }
      if ((sonc == fac)) {
        (ans--);
      }
    }
    (ans += [&]() {
      auto jargument_0 = jmin(dfn[x], dfn[y]);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = 1;
      auto jargument_3 = n;
      auto jargument_4 = 1;
      return Code05_Coloring1::query(jargument_0, jargument_1, jargument_2,
                                     jargument_3, jargument_4);
    }());
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = io.nextInt());
        (v = io.nextInt());
        Code05_Coloring1::addEdge(u, v);
        Code05_Coloring1::addEdge(v, u);
      }
    }
    Code05_Coloring1::dfs3();
    Code05_Coloring1::dfs4();
    Code05_Coloring1::build(1, n, 1);
    String op = {};
    int x = {};
    int y = {};
    int z = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = io.next());
      (x = io.nextInt());
      (y = io.nextInt());
      if (op.equals(String(u"C"))) {
        (z = io.nextInt());
        Code05_Coloring1::pathUpdate(x, y, z);
      } else {
        io.println(Code05_Coloring1::pathColors(x, y));
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Coloring1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 染色，java版
// 一共有n个节点，给定n-1条边，节点连成一棵树，每个节点给定初始颜色值
// 连续相同颜色被认为是一段，变化了就认为是另一段
// 比如，112221，有三个颜色段，分别为 11、222、1
// 一共有m条操作，每种操作是如下2种类型中的一种
// 操作 C x y z : x到y的路径上，每个节点的颜色都改为z
// 操作 Q x y   : x到y的路径上，打印有几个颜色段
// 1 <= n、m <= 10^5
// 1 <= 任何时候的颜色值 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2486
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // change是线段树的懒更新信息
        // change[i] == 0 代表没有懒更新信息
        // change[i] != 0 代表颜色重置为change[i]
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 查询单点颜色，jobi为节点的dfn序号
        // 读写工具类
*/
