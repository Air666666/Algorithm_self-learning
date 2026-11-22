// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3304

// Source: src/class121/Code02_DiameterAndCommonEdges2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DiameterAndCommonEdges2 {
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
  inline static Array<Array<int>> ufeStack = make_array<int>(MAXN, 3);
  inline static Array<i64> distStack = make_array<i64>(MAXN);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static i64 c = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DiameterAndCommonEdges2() {}
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
    Code02_DiameterAndCommonEdges2::dfs(1);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code02_DiameterAndCommonEdges2::dfs(start);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter = dist[end]);
  }
  static void push(int u, int f, int e, i64 c) {
    (ufeStack[stackSize][0] = u);
    (ufeStack[stackSize][1] = f);
    (ufeStack[stackSize][2] = e);
    (distStack[stackSize] = c);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufeStack[stackSize][0]);
    (f = ufeStack[stackSize][1]);
    (e = ufeStack[stackSize][2]);
    (c = distStack[stackSize]);
  }
  static void dfs(int root) {
    (stackSize = 0);
    Code02_DiameterAndCommonEdges2::push(root, 0, (-1), 0);
    while ((stackSize > 0)) {
      Code02_DiameterAndCommonEdges2::pop();
      if ((e == (-1))) {
        (last[u] = f);
        (dist[u] = c);
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code02_DiameterAndCommonEdges2::push(u, f, e, c);
        if ((to[e] != f)) {
          Code02_DiameterAndCommonEdges2::push(to[e], u, (-1), (c + weight[e]));
        }
      }
    }
  }
  static i64 maxDistanceExceptDiameter(int root) {
    (stackSize = 0);
    Code02_DiameterAndCommonEdges2::push(root, 0, (-1), 0);
    i64 ans = 0;
    while ((stackSize > 0)) {
      Code02_DiameterAndCommonEdges2::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      int v = {};
      if ((e != 0)) {
        Code02_DiameterAndCommonEdges2::push(u, f, e, c);
        (v = to[e]);
        if (((!diameterPath[v]) && (v != f))) {
          Code02_DiameterAndCommonEdges2::push(v, u, (-1), (c + weight[e]));
        }
      } else {
        (ans = jmax(ans, c));
      }
    }
    return ans;
  }
  static void compute() {
    Code02_DiameterAndCommonEdges2::road();
    for (int i = end; (i != 0); (i = last[i])) {
      (diameterPath[i] = true);
    }
    int l = start;
    int r = end;
    i64 maxDist = {};
    for (int i = last[end]; (i != start); (i = last[i])) {
      (maxDist = Code02_DiameterAndCommonEdges2::maxDistanceExceptDiameter(i));
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
    Code02_DiameterAndCommonEdges2::build();
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
        Code02_DiameterAndCommonEdges2::addEdge(u, v, w);
        Code02_DiameterAndCommonEdges2::addEdge(v, u, w);
      }
    }
    Code02_DiameterAndCommonEdges2::compute();
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
  Code02_DiameterAndCommonEdges2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 所有直径的公共部分(迭代版)
// 给定一棵树，边权都为正
// 打印直径长度、所有直径的公共部分有几条边
// 测试链接 : https://www.luogu.com.cn/problem/P3304
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // dfs方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // maxDistanceExceptDiameter方法改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/
