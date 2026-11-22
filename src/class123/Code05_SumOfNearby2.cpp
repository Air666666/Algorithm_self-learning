// Source: src/class123/Code05_SumOfNearby2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_SumOfNearby2 {
  inline static int MAXN = 100001;
  inline static int MAXK = 21;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<Array<int>> sum = make_array<int>(MAXN, MAXK);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXK);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_SumOfNearby2() {}
  static void build() {
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
    Code05_SumOfNearby2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code05_SumOfNearby2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code05_SumOfNearby2::push(u, f, e);
        if ((to[e] != f)) {
          Code05_SumOfNearby2::push(to[e], u, (-1));
        }
      } else {
        {
          int e = head[u];
          int v = {};
          for (; (e != 0); (e = next[e])) {
            (v = to[e]);
            if ((v != f)) {
              for (int j = 1; (j <= k); (j++)) {
                (sum[u][j] += sum[v][(j - 1)]);
              }
            }
          }
        }
      }
    }
  }
  static void dfs2(int root) {
    (stackSize = 0);
    Code05_SumOfNearby2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code05_SumOfNearby2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code05_SumOfNearby2::push(u, f, e);
        int v = to[e];
        if ((v != f)) {
          (dp[v][0] = sum[v][0]);
          (dp[v][1] = (sum[v][1] + dp[u][0]));
          for (int i = 2; (i <= k); (i++)) {
            (dp[v][i] = ((sum[v][i] + dp[u][(i - 1)]) - sum[v][(i - 2)]));
          }
          Code05_SumOfNearby2::push(v, u, (-1));
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
    Code05_SumOfNearby2::build();
    in.nextToken();
    (k = static_cast<int>(in.nval));
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code05_SumOfNearby2::addEdge(u, v);
        Code05_SumOfNearby2::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (sum[i][0] = static_cast<int>(in.nval));
    }
    Code05_SumOfNearby2::dfs1(1);
    for (int i = 0; (i <= k); (i++)) {
      (dp[1][i] = sum[1][i]);
    }
    Code05_SumOfNearby2::dfs2(1);
    {
      int i = 1;
      int ans = {};
      for (; (i <= n); (i++)) {
        (ans = 0);
        for (int j = 0; (j <= k); (j++)) {
          (ans += dp[i][j]);
        }
        out.println(ans);
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
  Code05_SumOfNearby2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 每个节点距离k以内的权值和(迭代版)
// 给定一棵n个点的树，每个点有点权
// 到达每个节点的距离不超过k的节点就有若干个
// 把这些节点权值加起来，就是该点不超过距离k的点权和
// 打印每个节点不超过距离k的点权和
// 注意k并不大
// 测试链接 : https://www.luogu.com.cn/problem/P3047
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs1方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // dfs2方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/
