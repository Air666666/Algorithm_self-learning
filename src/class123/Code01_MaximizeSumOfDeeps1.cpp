// Source: src/class123/Code01_MaximizeSumOfDeeps1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximizeSumOfDeeps1 {
  inline static int MAXN = 1000001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximizeSumOfDeeps1() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code01_MaximizeSumOfDeeps1::dfs1(v, u);
        }
      }
    }
    (size[u] = 1);
    (sum[u] = 0);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (size[u] += size[v]);
          (sum[u] += (sum[v] + size[v]));
        }
      }
    }
  }
  static void dfs2(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (dp[v] = (((dp[u] - size[v]) + n) - size[v]));
          Code01_MaximizeSumOfDeeps1::dfs2(v, u);
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
    Code01_MaximizeSumOfDeeps1::build();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code01_MaximizeSumOfDeeps1::addEdge(u, v);
        Code01_MaximizeSumOfDeeps1::addEdge(v, u);
      }
    }
    Code01_MaximizeSumOfDeeps1::dfs1(1, 0);
    (dp[1] = sum[1]);
    Code01_MaximizeSumOfDeeps1::dfs2(1, 0);
    i64 max = std::numeric_limits<i64>::min();
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((dp[i] > max)) {
        (max = dp[i]);
        (ans = i);
      }
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
  Code01_MaximizeSumOfDeeps1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大深度和(递归版)
//
给定一棵n个点的树，找到一个节点，使得以这个节点为根时，到达所有节点的深度之和最大
// 如果有多个节点满足要求，返回节点编号最小的
// 测试链接 : https://www.luogu.com.cn/problem/P3478
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code01_MaximizeSumOfDeeps2文件
*/
