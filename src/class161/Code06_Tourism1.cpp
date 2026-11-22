// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3976

// Source: src/class161/Code06_Tourism1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Tourism1 {
  inline static int MAXN = 50001;
  inline static int INF = 1000000001;
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
  inline static Array<int> max = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> min = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> lprofit = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> rprofit = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> addTag = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Tourism1() {}
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
          Code06_Tourism1::dfs1(v, u);
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
    Code06_Tourism1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code06_Tourism1::dfs2(v, v);
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
    Code06_Tourism1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code06_Tourism1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code06_Tourism1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code06_Tourism1::push(to[edge], first, (-1));
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
    Code06_Tourism1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code06_Tourism1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (seg[cntd] = first);
        if ((son[first] == 0)) {
          continue;
        }
        Code06_Tourism1::push(first, second, (-2));
        Code06_Tourism1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code06_Tourism1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code06_Tourism1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    int l = jshl(i, 1);
    int r = (jshl(i, 1) | 1);
    (max[i] = jmax(max[l], max[r]));
    (min[i] = jmin(min[l], min[r]));
    (lprofit[i] = jmax(jmax(lprofit[l], lprofit[r]), (max[r] - min[l])));
    (rprofit[i] = jmax(jmax(rprofit[l], rprofit[r]), (max[l] - min[r])));
  }
  static void lazy(int i, int v) {
    (max[i] += v);
    (min[i] += v);
    (addTag[i] += v);
  }
  static void down(int i) {
    if ((addTag[i] != 0)) {
      Code06_Tourism1::lazy(jshl(i, 1), addTag[i]);
      Code06_Tourism1::lazy((jshl(i, 1) | 1), addTag[i]);
      (addTag[i] = 0);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (max[i] = (min[i] = arr[seg[l]]));
    } else {
      int mid = jdiv((l + r), 2);
      Code06_Tourism1::build(l, mid, jshl(i, 1));
      Code06_Tourism1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code06_Tourism1::up(i);
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_Tourism1::lazy(i, jobv);
    } else {
      Code06_Tourism1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code06_Tourism1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_Tourism1::add(jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code06_Tourism1::up(i);
    }
  }
  static void merge(Array<int> ans, int rmax, int rmin, int rlpro, int rrpro) {
    int lmax = ans[0];
    int lmin = ans[1];
    int llpro = ans[2];
    int lrpro = ans[3];
    (ans[0] = jmax(lmax, rmax));
    (ans[1] = jmin(lmin, rmin));
    (ans[2] = jmax(jmax(llpro, rlpro), (rmax - lmin)));
    (ans[3] = jmax(jmax(lrpro, rrpro), (lmax - rmin)));
  }
  static void query(Array<int> ans, int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_Tourism1::merge(ans, max[i], min[i], lprofit[i], rprofit[i]);
    } else {
      Code06_Tourism1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code06_Tourism1::query(ans, jobl, jobr, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_Tourism1::query(ans, jobl, jobr, (mid + 1), r, (jshl(i, 1) | 1));
      }
    }
  }
  static void query(Array<int> ans, int jobl, int jobr) {
    (ans[0] = (-INF));
    (ans[1] = INF);
    (ans[2] = 0);
    (ans[3] = 0);
    Code06_Tourism1::query(ans, jobl, jobr, 1, n, 1);
  }
  static void clone(Array<int> a, Array<int> b) {
    (a[0] = b[0]);
    (a[1] = b[1]);
    (a[2] = b[2]);
    (a[3] = b[3]);
  }
  static int compute(int x, int y, int v) {
    int tmpx = x;
    int tmpy = y;
    Array<int> xpath = Array<int>{(-INF), INF, 0, 0};
    Array<int> ypath = Array<int>{(-INF), INF, 0, 0};
    Array<int> cur = make_array<int>(4);
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code06_Tourism1::query(cur, dfn[top[y]], dfn[y]);
        Code06_Tourism1::merge(cur, ypath[0], ypath[1], ypath[2], ypath[3]);
        Code06_Tourism1::clone(ypath, cur);
        (y = fa[top[y]]);
      } else {
        Code06_Tourism1::query(cur, dfn[top[x]], dfn[x]);
        Code06_Tourism1::merge(cur, xpath[0], xpath[1], xpath[2], xpath[3]);
        Code06_Tourism1::clone(xpath, cur);
        (x = fa[top[x]]);
      }
    }
    if ((dep[x] <= dep[y])) {
      Code06_Tourism1::query(cur, dfn[x], dfn[y]);
      Code06_Tourism1::merge(cur, ypath[0], ypath[1], ypath[2], ypath[3]);
      Code06_Tourism1::clone(ypath, cur);
    } else {
      Code06_Tourism1::query(cur, dfn[y], dfn[x]);
      Code06_Tourism1::merge(cur, xpath[0], xpath[1], xpath[2], xpath[3]);
      Code06_Tourism1::clone(xpath, cur);
    }
    int ans = jmax(jmax(xpath[3], ypath[2]), (ypath[0] - xpath[1]));
    (x = tmpx);
    (y = tmpy);
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code06_Tourism1::add(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code06_Tourism1::add(dfn[top[x]], dfn[x], v, 1, n, 1);
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
      return Code06_Tourism1::add(jargument_0, jargument_1, jargument_2,
                                  jargument_3, jargument_4, jargument_5);
    }();
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code06_Tourism1::addEdge(u, v);
        Code06_Tourism1::addEdge(v, u);
      }
    }
    Code06_Tourism1::dfs3();
    Code06_Tourism1::dfs4();
    Code06_Tourism1::build(1, n, 1);
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int x = {};
      int y = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (x = static_cast<int>(in.nval));
        in.nextToken();
        (y = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        out.println(Code06_Tourism1::compute(x, y, v));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Tourism1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旅游，java版
// 一共有n个城市，给定n-1条边，城市连成一棵树，每个城市给定初始的宝石价格
// 一共有m条操作，操作类型如下
// 操作 x y v : 城市x到城市y的最短路途中，你可以选择一城买入宝石
//              继续行进的过程中，再选一城卖出宝石，以此获得利润
//              打印你能获得的最大利润，如果为负数，打印0
//              当你结束旅途后，沿途所有城市的宝石价格增加v
// 1 <= n、m <= 5 * 10^4
// 0 <= 任何时候的宝石价格 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3976
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 线段树范围增加的懒更新信息
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // ans[0] : 线段树更左侧部分的max
        // ans[1] : 线段树更左侧部分的min
        // ans[2] : 线段树更左侧部分的lprofit
        // ans[3] : 线段树更左侧部分的rprofit
        // rmax : 线段树更右侧部分的max
        // rmin : 线段树更右侧部分的min
        // rlpro : 线段树更右侧部分的lprofit
        // rrpro : 线段树更右侧部分的rprofit
        //
左侧部分和右侧部分的信息整合在一起得到整个范围的max、min、lprofit、rprofit
        // ans[0] : 线段树更左侧部分的max
        // ans[1] : 线段树更左侧部分的min
        // ans[2] : 线段树更左侧部分的lprofit
        // ans[3] : 线段树更左侧部分的rprofit
        // 随着线段树查询的展开，会有更右部分的信息整合进ans，最终整合出整体信息
*/
