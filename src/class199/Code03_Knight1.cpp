// Source: src/class199/Code03_Knight1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Knight1 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static int x = {};
  inline static int y = {};
  inline static int skip = {};
  inline static Array<Array<i64>> dp = make_array<i64>(MAXN, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Knight1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_Knight1::dfs(v);
      } else if ((dfn[u] < dfn[v])) {
        (x = u);
        (y = v);
        (skip = jshr((e + 1), 1));
      }
    }
  }
  static void dpOnTree(int u, int fa) {
    (dp[u][0] = 0);
    (dp[u][1] = arr[u]);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (jshr((e + 1), 1) != skip))) {
        Code03_Knight1::dpOnTree(v, u);
        (dp[u][0] += jmax(dp[v][0], dp[v][1]));
        (dp[u][1] += dp[v][0]);
      }
    }
  }
  static i64 compute() {
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        (x = (y = 0));
        Code03_Knight1::dfs(i);
        Code03_Knight1::dpOnTree(x, 0);
        i64 cur = dp[x][0];
        Code03_Knight1::dpOnTree(y, 0);
        (cur = jmax(cur, dp[y][0]));
        (ans += cur);
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int x = 1;
      int y = {};
      for (; (x <= n); (x++)) {
        (arr[x] = in.nextInt());
        (y = in.nextInt());
        Code03_Knight1::addEdge(x, y);
        Code03_Knight1::addEdge(y, x);
      }
    }
    i64 ans = Code03_Knight1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Knight1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 骑士，java版
// 图中有n个点、n条无向边，每个点有点权
// 图中可能有多个连通块，保证每个连通块都是一棵基环树
// 图中任意相邻两点不能同时选择，计算能得到的最大点权累加和
// 1 <= n、点权 <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P2607
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
