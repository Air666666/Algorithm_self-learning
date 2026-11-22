// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3038

// Source: src/class162/Code01_GrassPlanting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GrassPlanting1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
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
  inline static int cntd = 0;
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> addTag = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GrassPlanting1() {}
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
          Code01_GrassPlanting1::dfs1(v, u);
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
    if ((son[u] == 0)) {
      return;
    }
    Code01_GrassPlanting1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_GrassPlanting1::dfs2(v, v);
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
    Code01_GrassPlanting1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code01_GrassPlanting1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code01_GrassPlanting1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code01_GrassPlanting1::push(to[edge], first, (-1));
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
    Code01_GrassPlanting1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code01_GrassPlanting1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        if ((son[first] == 0)) {
          continue;
        }
        Code01_GrassPlanting1::push(first, second, (-2));
        Code01_GrassPlanting1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code01_GrassPlanting1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code01_GrassPlanting1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
  }
  static void lazy(int i, int v, int n) {
    (sum[i] += (v * n));
    (addTag[i] += v);
  }
  static void down(int i, int ln, int rn) {
    if ((addTag[i] != 0)) {
      Code01_GrassPlanting1::lazy(jshl(i, 1), addTag[i], ln);
      Code01_GrassPlanting1::lazy((jshl(i, 1) | 1), addTag[i], rn);
      (addTag[i] = 0);
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_GrassPlanting1::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jdiv((l + r), 2);
      Code01_GrassPlanting1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_GrassPlanting1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_GrassPlanting1::add(jobl, jobr, jobv, (mid + 1), r,
                                   (jshl(i, 1) | 1));
      }
      Code01_GrassPlanting1::up(i);
    }
  }
  static int query(int jobi, int l, int r, int i) {
    if ((l == r)) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    Code01_GrassPlanting1::down(i, ((mid - l) + 1), (r - mid));
    if ((jobi <= mid)) {
      return Code01_GrassPlanting1::query(jobi, l, mid, jshl(i, 1));
    } else {
      return Code01_GrassPlanting1::query(jobi, (mid + 1), r, (jshl(i, 1) | 1));
    }
  }
  static void pathAdd(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code01_GrassPlanting1::add(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code01_GrassPlanting1::add(dfn[top[x]], dfn[x], v, 1, n, 1);
        (x = fa[top[x]]);
      }
    }
    [&]() {
      auto jargument_0 = (jmin(dfn[x], dfn[y]) + 1);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = v;
      auto jargument_3 = 1;
      auto jargument_4 = n;
      auto jargument_5 = 1;
      return Code01_GrassPlanting1::add(jargument_0, jargument_1, jargument_2,
                                        jargument_3, jargument_4, jargument_5);
    }();
  }
  static int edgeQuery(int x, int y) {
    int down = jmax(dfn[x], dfn[y]);
    return Code01_GrassPlanting1::query(down, 1, n, 1);
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    (m = io.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = io.nextInt());
        (v = io.nextInt());
        Code01_GrassPlanting1::addEdge(u, v);
        Code01_GrassPlanting1::addEdge(v, u);
      }
    }
    Code01_GrassPlanting1::dfs3();
    Code01_GrassPlanting1::dfs4();
    String op = {};
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = io.next());
        (x = io.nextInt());
        (y = io.nextInt());
        if (op.equals(String(u"P"))) {
          Code01_GrassPlanting1::pathAdd(x, y, 1);
        } else {
          io.println(Code01_GrassPlanting1::edgeQuery(x, y));
        }
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_GrassPlanting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边权转化为点权的模版题，java版
// 一共有n个节点，给定n-1条边，节点连成一棵树，初始时所有边的权值为0
// 一共有m条操作，每条操作是如下2种类型中的一种
// 操作 P x y : x到y的路径上，每条边的权值增加1
// 操作 Q x y : x和y保证是直接连接的，查询他们之间的边权
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3038
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 重链剖分
        // 线段树
        // dfs1的迭代版
        // dfs2的迭代版
        // 范围增加
        // 单点查询
        // x到y的路径上，每条边的边权变成下方点的点权
        // 每条边的边权增加v，就是若干点的点权增加v
        // 但是要注意！x和y的最低公共祖先，不能增加点权！
                // x和y的最低公共祖先，点权不增加！
        // 返回x和y之间这条边的边权
        // 读写工具类
*/
