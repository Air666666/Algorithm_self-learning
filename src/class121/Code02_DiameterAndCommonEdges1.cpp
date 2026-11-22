// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3304

// Source: src/class121/Code02_DiameterAndCommonEdges1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DiameterAndCommonEdges1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static int start = {};
  inline static int end = {};
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static i64 diameter = {};
  inline static Array<bool> diameterPath = make_array<bool>(MAXN);
  inline static int commonEdges = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DiameterAndCommonEdges1() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(diameterPath, 1, (n + 1), false);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void road() {
    Code02_DiameterAndCommonEdges1::dfs(1, 0, 0);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code02_DiameterAndCommonEdges1::dfs(start, 0, 0);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter = dist[end]);
  }
  static void dfs(int u, int f, i64 c) {
    (last[u] = f);
    (dist[u] = c);
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code02_DiameterAndCommonEdges1::dfs(to[e], u, (c + weight[e]));
      }
    }
  }
  static i64 maxDistanceExceptDiameter(int u, int f, i64 c) {
    i64 ans = c;
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if (((!diameterPath[v]) && (v != f))) {
          (ans = jmax(ans,
                      Code02_DiameterAndCommonEdges1::maxDistanceExceptDiameter(
                          v, u, (c + weight[e]))));
        }
      }
    }
    return ans;
  }
  static void compute() {
    Code02_DiameterAndCommonEdges1::road();
    for (int i = end; (i != 0); (i = last[i])) {
      (diameterPath[i] = true);
    }
    int l = start;
    int r = end;
    i64 maxDist = {};
    for (int i = last[end]; (i != start); (i = last[i])) {
      (maxDist =
           Code02_DiameterAndCommonEdges1::maxDistanceExceptDiameter(i, 0, 0));
      if ((maxDist == (diameter - dist[i]))) {
        (r = i);
      }
      if (((maxDist == dist[i]) && (l == start))) {
        (l = i);
      }
    }
    if ((l == r)) {
      (commonEdges = 0);
    } else {
      (commonEdges = 1);
      for (int i = last[r]; (i != l); (i = last[i])) {
        (commonEdges++);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code02_DiameterAndCommonEdges1::build();
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
        Code02_DiameterAndCommonEdges1::addEdge(u, v, w);
        Code02_DiameterAndCommonEdges1::addEdge(v, u, w);
      }
    }
    Code02_DiameterAndCommonEdges1::compute();
    out.println(diameter);
    out.println(commonEdges);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_DiameterAndCommonEdges1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 所有直径的公共部分(递归版)
// 给定一棵树，边权都为正
// 打印直径长度、所有直径的公共部分有几条边
// 测试链接 : https://www.luogu.com.cn/problem/P3304
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code02_DiameterAndCommonEdges2文件
        // 不能走向直径路径上的节点
        // 能走出的最大距离
*/
