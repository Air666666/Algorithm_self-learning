// Source: src/class121/Code01_Diameter3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Diameter3 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static int diameter = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Diameter3() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(dist, 1, (n + 1), 0);
    (diameter = std::numeric_limits<int>::min());
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
          Code01_Diameter3::dp(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (diameter = jmax(diameter, ((dist[u] + dist[v]) + weight[e])));
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
    Code01_Diameter3::build();
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
        Code01_Diameter3::addEdge(u, v, w);
        Code01_Diameter3::addEdge(v, u, w);
      }
    }
    Code01_Diameter3::dp(1, 0);
    out.println(diameter);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Diameter3::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树的直径模版(树型dp版逻辑小化简)
// 给定一棵树，边权可能为负，求直径长度
// 测试链接 : https://www.luogu.com.cn/problem/U81904
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有的用例
        // 直径的长度
                                // 干脆直接去更新diameter
*/
