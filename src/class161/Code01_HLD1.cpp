// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3384

// Source: src/class161/Code01_HLD1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_HLD1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int root = {};
  inline static int MOD = {};
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
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 2));
  inline static Array<i64> addTag = make_array<i64>(jshl(MAXN, 2));
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_HLD1() {}
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
          Code01_HLD1::dfs1(v, u);
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
    Code01_HLD1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_HLD1::dfs2(v, v);
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
    Code01_HLD1::push(root, 0, (-1));
    while ((stacksize > 0)) {
      Code01_HLD1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code01_HLD1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code01_HLD1::push(to[edge], first, (-1));
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
    Code01_HLD1::push(root, root, (-1));
    while ((stacksize > 0)) {
      Code01_HLD1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        (dfn[first] = (++cntd));
        (seg[cntd] = first);
        if ((son[first] == 0)) {
          continue;
        }
        Code01_HLD1::push(first, second, (-2));
        Code01_HLD1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code01_HLD1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code01_HLD1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static void up(int i) {
    (sum[i] = jrem((sum[jshl(i, 1)] + sum[(jshl(i, 1) | 1)]), MOD));
  }
  static void lazy(int i, i64 v, int n) {
    (sum[i] = jrem((sum[i] + (v * n)), MOD));
    (addTag[i] = jrem((addTag[i] + v), MOD));
  }
  static void down(int i, int ln, int rn) {
    if ((addTag[i] != 0)) {
      Code01_HLD1::lazy(jshl(i, 1), addTag[i], ln);
      Code01_HLD1::lazy((jshl(i, 1) | 1), addTag[i], rn);
      (addTag[i] = 0);
    }
  }
  static void build(int l, int r, int i) {
    if ((l == r)) {
      (sum[i] = jrem(arr[seg[l]], MOD));
    } else {
      int mid = jdiv((l + r), 2);
      Code01_HLD1::build(l, mid, jshl(i, 1));
      Code01_HLD1::build((mid + 1), r, (jshl(i, 1) | 1));
      Code01_HLD1::up(i);
    }
  }
  static void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_HLD1::lazy(i, jobv, ((r - l) + 1));
    } else {
      int mid = jdiv((l + r), 2);
      Code01_HLD1::down(i, ((mid - l) + 1), (r - mid));
      if ((jobl <= mid)) {
        Code01_HLD1::add(jobl, jobr, jobv, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code01_HLD1::add(jobl, jobr, jobv, (mid + 1), r, (jshl(i, 1) | 1));
      }
      Code01_HLD1::up(i);
    }
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jdiv((l + r), 2);
    Code01_HLD1::down(i, ((mid - l) + 1), (r - mid));
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans = jrem((ans + Code01_HLD1::query(jobl, jobr, l, mid, jshl(i, 1))),
                  MOD));
    }
    if ((jobr > mid)) {
      (ans = jrem((ans + Code01_HLD1::query(jobl, jobr, (mid + 1), r,
                                            (jshl(i, 1) | 1))),
                  MOD));
    }
    return ans;
  }
  static void pathAdd(int x, int y, int v) {
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        Code01_HLD1::add(dfn[top[y]], dfn[y], v, 1, n, 1);
        (y = fa[top[y]]);
      } else {
        Code01_HLD1::add(dfn[top[x]], dfn[x], v, 1, n, 1);
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
      return Code01_HLD1::add(jargument_0, jargument_1, jargument_2,
                              jargument_3, jargument_4, jargument_5);
    }();
  }
  static void subtreeAdd(int x, int v) {
    Code01_HLD1::add(dfn[x], ((dfn[x] + siz[x]) - 1), v, 1, n, 1);
  }
  static i64 pathSum(int x, int y) {
    i64 ans = 0;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] <= dep[top[y]])) {
        (ans = jrem((ans + Code01_HLD1::query(dfn[top[y]], dfn[y], 1, n, 1)),
                    MOD));
        (y = fa[top[y]]);
      } else {
        (ans = jrem((ans + Code01_HLD1::query(dfn[top[x]], dfn[x], 1, n, 1)),
                    MOD));
        (x = fa[top[x]]);
      }
    }
    (ans = jrem((ans +
                 [&]() {
                   auto jargument_0 = jmin(dfn[x], dfn[y]);
                   auto jargument_1 = jmax(dfn[x], dfn[y]);
                   auto jargument_2 = 1;
                   auto jargument_3 = n;
                   auto jargument_4 = 1;
                   return Code01_HLD1::query(jargument_0, jargument_1,
                                             jargument_2, jargument_3,
                                             jargument_4);
                 }()),
                MOD));
    return ans;
  }
  static i64 subtreeSum(int x) {
    return Code01_HLD1::query(dfn[x], ((dfn[x] + siz[x]) - 1), 1, n, 1);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (root = static_cast<int>(in.nval));
    in.nextToken();
    (MOD = static_cast<int>(in.nval));
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
        Code01_HLD1::addEdge(u, v);
        Code01_HLD1::addEdge(v, u);
      }
    }
    Code01_HLD1::dfs3();
    Code01_HLD1::dfs4();
    Code01_HLD1::build(1, n, 1);
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
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code01_HLD1::pathAdd(x, y, v);
        } else if ((op == 2)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          out.println(Code01_HLD1::pathSum(x, y));
        } else if ((op == 3)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code01_HLD1::subtreeAdd(x, v);
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          out.println(Code01_HLD1::subtreeSum(x));
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
  Code01_HLD1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 重链剖分模版题，java版
// 一共有n个节点，给定n-1条边，节点连成一棵树
// 给定每个节点的初始权值，给定树的头节点编号root
// 一共有m条操作，每种操作是如下4种类型中的一种
// 操作 1 x y v : x到y的路径上，每个节点值增加v
// 操作 2 x y   : x到y的路径上，打印所有节点值的累加和
// 操作 3 x v   : x为头的子树上，每个节点值增加v
// 操作 4 x     : x为头的子树上，打印所有节点值的累加和
// 1 <= n、m <= 10^5
// 1 <= MOD <= 2^30
// 输入的值都为int类型
// 查询操作时，打印(查询结果 % MOD)，题目会给定MOD值
// 测试链接 : https://www.luogu.com.cn/problem/P3384
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，C++可以通过，java会爆栈
        // 来到节点u，节点u树上的父节点是f
        // dfs1的过程去设置 fa dep siz son
        // 递归版，C++可以通过，java会爆栈
        // 来到节点u，节点u所在重链的头节点是t
        // dfs2的过程去设置 top dfn seg
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
        // 从x到y的路径上，所有节点的值增加v
        // x的子树上，所有节点的值增加v
        // 从x到y的路径上，查询所有节点的累加和
        // x的子树上，查询所有节点的累加和
*/
