// Source: src/class123/Code02_TreePainting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TreePainting {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TreePainting() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(size, 1, (n + 1), 0);
    j::fill(dp, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    (size[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code02_TreePainting::dfs1(v, u);
          (size[u] += size[v]);
          (dp[u] += dp[v]);
        }
      }
    }
    (dp[u] += size[u]);
  }
  static void dfs2(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (dp[v] = (((dp[u] + n) - size[v]) - size[v]));
          Code02_TreePainting::dfs2(v, u);
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
    Code02_TreePainting::build();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_TreePainting::addEdge(u, v);
        Code02_TreePainting::addEdge(v, u);
      }
    }
    Code02_TreePainting::dfs1(1, 0);
    Code02_TreePainting::dfs2(1, 0);
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TreePainting::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 染色的最大收益
// 给定一棵n个点的树，初始时所有节点全是白点
// 第一次操作，你可以选择任意点染黑
// 以后每次操作，必须选择已经染黑的点的相邻点继续染黑，一直到所有的点都被染完
// 每次都获得，当前被染色点的白色连通块大小，作为收益
// 返回可获得的最大收益和
// 测试链接 : https://www.luogu.com.cn/problem/CF1187E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dp[i]更新成
        // 节点i作为自己这棵子树最先染的点，染完子树后，收益是多少
        // dp[i]更新成
        // 节点i作为整棵树最先染的点，染完整棵树后，收益是多少
*/
