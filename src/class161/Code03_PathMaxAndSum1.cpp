// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2590

// Source: src/class161/Code03_PathMaxAndSum1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PathMaxAndSum1 {
  inline static int MAXN = 30001;
  inline static int INF = 10000001;
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
  inline static Array<int> sum = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PathMaxAndSum1() {}
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
          Code03_PathMaxAndSum1::dfs1(v, u);
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
    Code03_PathMaxAndSum1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code03_PathMaxAndSum1::dfs2(v, v);
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
    Code03_PathMaxAndSum1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_PathMaxAndSum1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code03_PathMaxAndSum1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code03_PathMaxAndSum1::push(to[edge], first, (-1));
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
    Code03_PathMaxAndSum1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code03_PathMaxAndSum1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (seg[cntd] = first);
        if ((son[first] == 0)) {
          continue;
        }
        Code03_PathMaxAndSum1::push(first, second, (-2));
        Code03_PathMaxAndSum1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code03_PathMaxAndSum1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code03_PathMaxAndSum1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (sum[i] = (sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]));
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = arr[seg[l]]));
    } else {
      int mid = jdiv((l + r), 2);
      Code03_PathMaxAndSum1::build(l, mid, jshl(i, 1));
      Code03_PathMaxAndSum1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code03_PathMaxAndSum1::up(i);
    }
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = (max[i] = jobv));
    } else {
      int mid = jdiv((l + r), 2);
      if ((jobi <= mid)) {
        Code03_PathMaxAndSum1::update(jobi, jobv, l, mid, jshl(i, 1));
      } else {
        Code03_PathMaxAndSum1::update(jobi, jobv, (mid + 1), r,
                                      (jshl(i, 1) | 1));
      }
      Code03_PathMaxAndSum1::up(i);
    }
  }
  static int queryMax(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    int mid = jdiv((l + r), 2);
    int ans = (-INF);
    if ((jobl <= mid)) {
      (ans = jmax(ans, Code03_PathMaxAndSum1::queryMax(jobl, jobr, l, mid,
                                                       jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmax(ans, Code03_PathMaxAndSum1::queryMax(jobl, jobr, (mid + 1), r,
                                                       (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static int querySum(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code03_PathMaxAndSum1::querySum(jobl, jobr, l, mid, jshl(i, 1)));
    }
    if ((jobr > mid)) {
      (ans += Code03_PathMaxAndSum1::querySum(jobl, jobr, (mid + 1), r,
                                              (jshl(i, 1) | 1)));
    }
    return ans;
  }
  static void pointUpdate(int u, int v) {
    Code03_PathMaxAndSum1::update(dfn[u], v, 1, n, 1);
  }
  static int pathMax(int x, int y) {
    int ans = (-INF);
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans = jmax(ans, Code03_PathMaxAndSum1::queryMax(dfn[top[y]], dfn[y], 1,
                                                         n, 1)));
        (y = fa[top[y]]);
      } else {
        (ans = jmax(ans, Code03_PathMaxAndSum1::queryMax(dfn[top[x]], dfn[x], 1,
                                                         n, 1)));
        (x = fa[top[x]]);
      }
    }
    (ans = jmax(ans, [&]() {
       auto jargument_0 = jmin(dfn[x], dfn[y]);
       auto jargument_1 = jmax(dfn[x], dfn[y]);
       auto jargument_2 = 1;
       auto jargument_3 = n;
       auto jargument_4 = 1;
       return Code03_PathMaxAndSum1::queryMax(
           jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
     }()));
    return ans;
  }
  static int pathSum(int x, int y) {
    int ans = 0;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans += Code03_PathMaxAndSum1::querySum(dfn[top[y]], dfn[y], 1, n, 1));
        (y = fa[top[y]]);
      } else {
        (ans += Code03_PathMaxAndSum1::querySum(dfn[top[x]], dfn[x], 1, n, 1));
        (x = fa[top[x]]);
      }
    }
    (ans += [&]() {
      auto jargument_0 = jmin(dfn[x], dfn[y]);
      auto jargument_1 = jmax(dfn[x], dfn[y]);
      auto jargument_2 = 1;
      auto jargument_3 = n;
      auto jargument_4 = 1;
      return Code03_PathMaxAndSum1::querySum(
          jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
    }());
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (n = io.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = io.nextInt());
        (v = io.nextInt());
        Code03_PathMaxAndSum1::addEdge(u, v);
        Code03_PathMaxAndSum1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = io.nextInt());
    }
    Code03_PathMaxAndSum1::dfs3();
    Code03_PathMaxAndSum1::dfs4();
    Code03_PathMaxAndSum1::build(1, n, 1);
    (m = io.nextInt());
    String op = {};
    int x = {};
    int y = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = io.next());
      (x = io.nextInt());
      (y = io.nextInt());
      if (op.equals(String(u"CHANGE"))) {
        Code03_PathMaxAndSum1::pointUpdate(x, y);
      } else if (op.equals(String(u"QMAX"))) {
        io.println(Code03_PathMaxAndSum1::pathMax(x, y));
      } else {
        io.println(Code03_PathMaxAndSum1::pathSum(x, y));
      }
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PathMaxAndSum1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径最大值与累加和，java版
// 一共有n个节点，给定n-1条边，节点连成一棵树，每个节点给定权值
// 一共有m条操作，每种操作是如下3种类型中的一种
// 操作 CHANGE x y : x的权值修改为y
// 操作 QMAX x y   : x到y的路径上，打印节点值的最大值
// 操作 QSUM x y   : x到y的路径上，打印节点值的累加和
// 1 <= n <= 3 * 10^4
// 0 <= m <= 2 * 10^5
// -30000 <= 节点权值 <= +30000
// 测试链接 : https://www.luogu.com.cn/problem/P2590
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 读写工具类
*/
