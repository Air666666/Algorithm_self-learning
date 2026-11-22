// Source: src/class161/Code07_FarAway1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_FarAway1 {
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
  inline static Array<int> min = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> change = make_array<int>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_FarAway1() {}
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
          Code07_FarAway1::dfs1(v, u);
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
    Code07_FarAway1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code07_FarAway1::dfs2(v, v);
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
    Code07_FarAway1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code07_FarAway1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code07_FarAway1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code07_FarAway1::push(to[edge], first, (-1));
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
    Code07_FarAway1::push(1, 1, (-1));
    while ((stacksize > 0)) {
      Code07_FarAway1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (seg[cntd] = first);
        if ((son[first] == 0)) {
          continue;
        }
        Code07_FarAway1::push(first, second, (-2));
        Code07_FarAway1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code07_FarAway1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code07_FarAway1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (min[i] = jmin(min[jshl(i, 1)], min[(jshl(i, 1) | 1)]));
  }
  static void lazy(int i, int v) {
    (min[i] = v);
    (change[i] = v);
  }
  static void down(int i) {
    if ((change[i] != 0)) {
      Code07_FarAway1::lazy(jshl(i, 1), change[i]);
      Code07_FarAway1::lazy((jshl(i, 1) | 1), change[i]);
      (change[i] = 0);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (min[i] = arr[seg[l]]);
    } else {
      int mid = jdiv((l + r), 2);
      Code07_FarAway1::build(l, mid, jshl(i, 1));
      Code07_FarAway1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code07_FarAway1::up(i);
    }
  }
  static void update(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code07_FarAway1::lazy(i, jobv);
    } else {
      Code07_FarAway1::down(i);
      int mid = jdiv((l + r), 2);
      if ((jobl <= mid)) {
        Code07_FarAway1::update(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code07_FarAway1::update(jobl, jobr, jobv, (mid + 1), r,
                                (jshl(i, 1) | 1));
      }
      Code07_FarAway1::up(i);
    }
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return min[i];
    }
    Code07_FarAway1::down(i);
    int mid = jdiv((l + r), 2);
    int ans = std::numeric_limits<int>::max();
    if ((jobl <= mid)) {
      (ans = jmin(ans, Code07_FarAway1::query(jobl, jobr, l, mid, jshl(i, 1))));
    }
    if ((jobr > mid)) {
      (ans = jmin(ans, Code07_FarAway1::query(jobl, jobr, (mid + 1), r,
                                              (jshl(i, 1) | 1))));
    }
    return ans;
  }
  static void pathUpdate(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code07_FarAway1::update(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code07_FarAway1::update(dfn[top[x]], dfn[x], v, 1, n, 1);
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
      return Code07_FarAway1::update(jargument_0, jargument_1, jargument_2,
                                     jargument_3, jargument_4, jargument_5);
    }();
  }
  static int findSon(int root, int u) {
    while ((top[root] != top[u])) {
      if ((fa[top[root]] == u)) {
        return top[root];
      }
      (root = fa[top[root]]);
    }
    return son[u];
  }
  static int treeQuery(int root, int u) {
    if ((root == u)) {
      return min[1];
    } else if (((dfn[root] < dfn[u]) || ((dfn[u] + siz[u]) <= dfn[root]))) {
      return Code07_FarAway1::query(dfn[u], ((dfn[u] + siz[u]) - 1), 1, n, 1);
    } else {
      int uson = Code07_FarAway1::findSon(root, u);
      int ans = Code07_FarAway1::query(1, (dfn[uson] - 1), 1, n, 1);
      if (((dfn[uson] + siz[uson]) <= n)) {
        (ans = jmin(
             ans, Code07_FarAway1::query((dfn[uson] + siz[uson]), n, 1, n, 1)));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code07_FarAway1::addEdge(u, v);
        Code07_FarAway1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    Code07_FarAway1::dfs3();
    Code07_FarAway1::dfs4();
    Code07_FarAway1::build(1, n, 1);
    in.nextToken();
    int root = static_cast<int>(in.nval);
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (root = static_cast<int>(in.nval));
        } else if ((op == 2)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code07_FarAway1::pathUpdate(x, y, v);
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          out.println(Code07_FarAway1::treeQuery(root, x));
        }
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
  Code07_FarAway1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 遥远的国度，java版
//
一共有n个节点，给定n-1条边，节点连成一棵树，给定树的初始头节点，给定每个点的点权
// 一共有m条操作，每种操作是如下3种类型中的一种
// 操作 1 x     : 树的头节点变成x，整棵树需要重新组织
// 操作 2 x y v : x到y的路径上，所有节点的值改成v
// 操作 3 x     : 在当前树的状态下，打印u的子树中的最小值
// 1 <= n、m <= 10^5
// 任何时候节点值一定是正数
// 测试链接 : https://www.luogu.com.cn/problem/P3979
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 重置操作的懒更新信息
        // 因为题目说了，任何时候节点值一定是正数
        // change[i] == 0，表示没有重置懒更新
        // change[i] != 0，表示范围内的数字修改为change[i]
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 已知root一定在u的子树上
        // 找到u哪个儿子的子树里有root，返回那个儿子的编号
        // 假设树的头节点变成root，在当前树的状态下，查询u的子树中的最小值
*/
