// Source: src/class122/Code01_MaxFlow2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaxFlow2 {
  inline static int MAXN = 50001;
  inline static int LIMIT = 16;
  inline static int power = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaxFlow2() {}
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build(int n) {
    (power = Code01_MaxFlow2::log2(n));
    j::fill(num, 1, (n + 1), 0);
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void push(int u, int f, int e) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
  }
  static void dfs1(int root) {
    (stackSize = 0);
    Code01_MaxFlow2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code01_MaxFlow2::pop();
      if ((e == (-1))) {
        (deep[u] = (deep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p <= power); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code01_MaxFlow2::push(u, f, e);
        if ((to[e] != f)) {
          Code01_MaxFlow2::push(to[e], u, (-1));
        }
      }
    }
  }
  static int lca(int a, int b) {
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void dfs2(int root) {
    (stackSize = 0);
    Code01_MaxFlow2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code01_MaxFlow2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code01_MaxFlow2::push(u, f, e);
        if ((to[e] != f)) {
          Code01_MaxFlow2::push(to[e], u, (-1));
        }
      } else {
        {
          int e = head[u];
          int v = {};
          for (; (e != 0); (e = next[e])) {
            (v = to[e]);
            if ((v != f)) {
              (num[u] += num[v]);
            }
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    Code01_MaxFlow2::build(n);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code01_MaxFlow2::addEdge(u, v);
        Code01_MaxFlow2::addEdge(v, u);
      }
    }
    Code01_MaxFlow2::dfs1(1);
    {
      int i = 1;
      int u = {};
      int v = {};
      int lca = {};
      int lcafather = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (lca = Code01_MaxFlow2::lca(u, v));
        (lcafather = stjump[lca][0]);
        (num[u]++);
        (num[v]++);
        (num[lca]--);
        (num[lcafather]--);
      }
    }
    Code01_MaxFlow2::dfs2(1);
    int max = 0;
    for (int i = 1; (i <= n); (i++)) {
      (max = jmax(max, num[i]));
    }
    out.println(max);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MaxFlow2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上点差分模版(迭代版)
// 有n个节点形成一棵树，一开始所有点权都是0
// 给定很多操作，每个操作(a,b)表示从a到b路径上所有点的点权增加1
// 所有操作完成后，返回树上的最大点权
// 测试链接 : https://www.luogu.com.cn/problem/P3128
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs1方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // dfs2方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/
