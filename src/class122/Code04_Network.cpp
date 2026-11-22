// Source: src/class122/Code04_Network.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Network {
  inline static int MAXN = 100001;
  inline static int LIMIT = 17;
  inline static int power = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static int ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Network() {}
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build() {
    (power = Code04_Network::log2(n));
    j::fill(num, 1, (n + 1), 0);
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (ans = 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    (deep[u] = (deep[f] + 1));
    (stjump[u][0] = f);
    for (int p = 1; (p <= power); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code04_Network::dfs1(to[e], u);
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
  static void dfs2(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code04_Network::dfs2(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      int w = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (w = (0 + num[v]));
          if ((w == 0)) {
            (ans += m);
          } else if ((w == 1)) {
            (ans += 1);
          } else {
            (ans += 0);
          }
          (num[u] += num[v]);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code04_Network::build();
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
        Code04_Network::addEdge(u, v);
        Code04_Network::addEdge(v, u);
      }
    }
    Code04_Network::dfs1(1, 0);
    {
      int i = 1;
      int u = {};
      int v = {};
      int lca = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        (lca = Code04_Network::lca(u, v));
        (num[u]++);
        (num[v]++);
        (num[lca] -= 2);
      }
    }
    Code04_Network::dfs2(1, 0);
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Network::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 边差分实战
// 使图不连通的方法数
// 有n个节点，给定n-1条老边使其连接成一棵树，再给定m条新边额外加在树上
// 你可以切断两条边让这个图不连通，切断的两条边必须是一条老边和一条新边
// 返回方法数
// 测试链接 : http://poj.org/problem?id=3417
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/
