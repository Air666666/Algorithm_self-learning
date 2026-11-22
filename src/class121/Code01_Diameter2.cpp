// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/U81904

// Source: src/class121/Code01_Diameter2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Diameter2 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Diameter2() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(dist, 1, (n + 1), 0);
    j::fill(ans, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void dp(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code01_Diameter2::dp(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (ans[u] = jmax(ans[u], ((dist[u] + dist[v]) + weight[e])));
          (dist[u] = jmax(dist[u], (dist[v] + weight[e])));
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
    Code01_Diameter2::build();
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
        Code01_Diameter2::addEdge(u, v, w);
        Code01_Diameter2::addEdge(v, u, w);
      }
    }
    Code01_Diameter2::dp(1, 0);
    int diameter = std::numeric_limits<int>::min();
    for (int i = 1; (i <= n); (i++)) {
      (diameter = jmax(diameter, ans[i]));
    }
    out.println(diameter);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Diameter2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树的直径模版(树型dp)
// 给定一棵树，边权可能为负，求直径长度
// 测试链接 : https://www.luogu.com.cn/problem/U81904
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有的用例
        // dist[u] : 从u开始必须往下走，能走出的最大距离，可以不选任何边
        // ans[u] : 路径必须包含点u的情况下，最大路径和
*/
