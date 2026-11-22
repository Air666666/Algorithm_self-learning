// Source: src/class123/Code04_MaximizeFlow2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximizeFlow2 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> degree = make_array<int>(MAXN);
  inline static Array<int> flow = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximizeFlow2() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(degree, 1, (n + 1), 0);
    j::fill(flow, 1, (n + 1), 0);
    j::fill(dp, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
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
    Code04_MaximizeFlow2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code04_MaximizeFlow2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code04_MaximizeFlow2::push(u, f, e);
        if ((to[e] != f)) {
          Code04_MaximizeFlow2::push(to[e], u, (-1));
        }
      } else {
        {
          int e = head[u];
          int v = {};
          for (; (e != 0); (e = next[e])) {
            (v = to[e]);
            if ((v != f)) {
              if ((degree[v] == 1)) {
                (flow[u] += weight[e]);
              } else {
                (flow[u] += jmin(flow[v], weight[e]));
              }
            }
          }
        }
      }
    }
  }
  static void dfs2(int root) {
    (stackSize = 0);
    Code04_MaximizeFlow2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code04_MaximizeFlow2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code04_MaximizeFlow2::push(u, f, e);
        int v = to[e];
        if ((v != f)) {
          if ((degree[u] == 1)) {
            (dp[v] = (flow[v] + weight[e]));
          } else {
            int uOut = (dp[u] - jmin(flow[v], weight[e]));
            (dp[v] = (flow[v] + jmin(uOut, weight[e])));
          }
          Code04_MaximizeFlow2::push(v, u, (-1));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int testCase = static_cast<int>(in.nval);
    for (int t = 1; (t <= testCase); (t++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      Code04_MaximizeFlow2::build();
      {
        int i = 1;
        int u = {};
        int v = {};
        int w = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          in.nextToken();
          (w = static_cast<int>(in.nval));
          Code04_MaximizeFlow2::addEdge(u, v, w);
          Code04_MaximizeFlow2::addEdge(v, u, w);
          (degree[u]++);
          (degree[v]++);
        }
      }
      Code04_MaximizeFlow2::dfs1(1);
      (dp[1] = flow[1]);
      Code04_MaximizeFlow2::dfs2(1);
      int ans = 0;
      for (int i = 1; (i <= n); (i++)) {
        (ans = jmax(ans, dp[i]));
      }
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MaximizeFlow2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 选择节点做根使流量和最大(迭代版)
// 给定一棵n个点的树，边的边权代表流量限制
// 从边上流过的流量，不能超过流量限制
// 现在想知道以某个节点做根时，流到所有叶节点的流量，最大是多少
// 测试链接 : http://poj.org/problem?id=3585
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs1方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // dfs2方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/
