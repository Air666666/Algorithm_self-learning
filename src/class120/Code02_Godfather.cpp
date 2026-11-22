// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=3107

// Source: src/class120/Code02_Godfather.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Godfather {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> maxsub = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Godfather() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int f) {
    (size[u] = 1);
    (maxsub[u] = 0);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code02_Godfather::dfs(v, u);
          (size[u] += size[v]);
          (maxsub[u] = jmax(maxsub[u], size[v]));
        }
      }
    }
    (maxsub[u] = jmax(maxsub[u], (n - size[u])));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code02_Godfather::build();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_Godfather::addEdge(u, v);
        Code02_Godfather::addEdge(v, u);
      }
    }
    Code02_Godfather::dfs(1, 0);
    int m = 0;
    Array<int> centers = make_array<int>(2);
    for (int i = 1; (i <= n); (i++)) {
      if ((maxsub[i] <= jdiv(n, 2))) {
        (centers[(m++)] = i);
      }
    }
    if ((m == 1)) {
      out.println(centers[0]);
    } else {
      out.println(((centers[0] + String(u" ")) + centers[1]));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Godfather::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 教父
// 一共有n个节点，编号1~n，有n-1条边形成一棵树
// 返回所有重心点
// 树的重心第二种求解方式
// 以某个节点为根时，每颗子树的节点数不超过总节点数的一半，那么这个节点是重心
// 测试链接 : http://poj.org/problem?id=3107
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
