// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3379

// Source: src/class161/Code02_LCA1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LCA1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static int root = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<Array<int>> fse = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int first = {};
  inline static int second = {};
  inline static int edge = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LCA1() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
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
          Code02_LCA1::dfs1(v, u);
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
    if ((son[u] == 0)) {
      return;
    }
    Code02_LCA1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = next[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code02_LCA1::dfs2(v, v);
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
    Code02_LCA1::push(root, 0, (-1));
    while ((stacksize > 0)) {
      Code02_LCA1::pop();
      if ((edge == (-1))) {
        (fa[first] = second);
        (dep[first] = (dep[second] + 1));
        (siz[first] = 1);
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code02_LCA1::push(first, second, edge);
        if ((to[edge] != second)) {
          Code02_LCA1::push(to[edge], first, (-1));
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
    Code02_LCA1::push(root, root, (-1));
    while ((stacksize > 0)) {
      Code02_LCA1::pop();
      if ((edge == (-1))) {
        (top[first] = second);
        if ((son[first] == 0)) {
          continue;
        }
        Code02_LCA1::push(first, second, (-2));
        Code02_LCA1::push(son[first], second, (-1));
        continue;
      } else if ((edge == (-2))) {
        (edge = head[first]);
      } else {
        (edge = next[edge]);
      }
      if ((edge != 0)) {
        Code02_LCA1::push(first, second, edge);
        if (((to[edge] != fa[first]) && (to[edge] != son[first]))) {
          Code02_LCA1::push(to[edge], to[edge], (-1));
        }
      }
    }
  }
  static int lca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
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
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_LCA1::addEdge(u, v);
        Code02_LCA1::addEdge(v, u);
      }
    }
    Code02_LCA1::dfs3();
    Code02_LCA1::dfs4();
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        out.println(Code02_LCA1::lca(a, b));
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
  Code02_LCA1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 重链剖分解决LCA查询，java版
// 一共有n个节点，给定n-1条边，节点连成一棵树，给定头节点编号root
// 一共有m条查询，每条查询给定a和b，打印a和b的最低公共祖先
// 请用树链剖分的方式实现
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3379
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归版，C++可以通过，java会爆栈
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // dfs2的迭代版
*/
