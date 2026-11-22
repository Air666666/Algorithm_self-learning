// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/U81904

// Source: src/class121/Code01_Diameter1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Diameter1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static int start = {};
  inline static int end = {};
  inline static int diameter = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> last = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Diameter1() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void road() {
    Code01_Diameter1::dfs(1, 0, 0);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code01_Diameter1::dfs(start, 0, 0);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter = dist[end]);
  }
  static void dfs(int u, int f, int w) {
    (last[u] = f);
    (dist[u] = (dist[f] + w));
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code01_Diameter1::dfs(to[e], u, weight[e]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code01_Diameter1::build();
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
        Code01_Diameter1::addEdge(u, v, w);
        Code01_Diameter1::addEdge(v, u, w);
      }
    }
    Code01_Diameter1::road();
    out.println(diameter);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Diameter1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树的直径模版(两遍dfs)
// 给定一棵树，边权可能为负，求直径长度
// 测试链接 : https://www.luogu.com.cn/problem/U81904
// 提交以下的code，提交时请把类名改成"Main"
// 会有无法通过的用例，因为树上有负边
        // 直径的开始点
        // 直径的结束点
        // 直径长度
        // dist[i] : 从规定的头节点出发，走到i的距离
        // last[i] : 从规定的头节点出发，i节点的上一个节点
*/
