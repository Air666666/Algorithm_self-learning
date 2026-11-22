// Source: src/class123/Code06_Centroids.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Centroids {
  inline static int MAXN = 400001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> maxsub = make_array<int>(MAXN);
  inline static Array<int> inner1 = make_array<int>(MAXN);
  inline static Array<int> inner2 = make_array<int>(MAXN);
  inline static Array<int> choose = make_array<int>(MAXN);
  inline static Array<int> outer = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Centroids() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    j::fill(maxsub, 1, (n + 1), 0);
    j::fill(choose, 1, (n + 1), 0);
    j::fill(inner1, 1, (n + 1), 0);
    j::fill(inner2, 1, (n + 1), 0);
    j::fill(outer, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void dfs1(int u, int f) {
    (size[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code06_Centroids::dfs1(v, u);
          (size[u] += size[v]);
          if ((size[maxsub[u]] < size[v])) {
            (maxsub[u] = v);
          }
          int innerSize = ((size[v] <= jdiv(n, 2)) ? size[v] : inner1[v]);
          if ((inner1[u] < innerSize)) {
            (choose[u] = v);
            (inner2[u] = inner1[u]);
            (inner1[u] = innerSize);
          } else if ((inner2[u] < innerSize)) {
            (inner2[u] = innerSize);
          }
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
          if (((n - size[v]) <= jdiv(n, 2))) {
            (outer[v] = (n - size[v]));
          } else if ((choose[u] != v)) {
            (outer[v] = jmax(outer[u], inner1[u]));
          } else {
            (outer[v] = jmax(outer[u], inner2[u]));
          }
          Code06_Centroids::dfs2(v, u);
        }
      }
    }
  }
  static bool check(int u) {
    if ((size[maxsub[u]] > jdiv(n, 2))) {
      return ((size[maxsub[u]] - inner1[maxsub[u]]) <= jdiv(n, 2));
    }
    if (((n - size[u]) > jdiv(n, 2))) {
      return (((n - size[u]) - outer[u]) <= jdiv(n, 2));
    }
    return true;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Code06_Centroids::build();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code06_Centroids::addEdge(u, v);
        Code06_Centroids::addEdge(v, u);
      }
    }
    Code06_Centroids::dfs1(1, 0);
    Code06_Centroids::dfs2(1, 0);
    for (int i = 1; (i <= n); (i++)) {
      out.print((Code06_Centroids::check(i) ? String(u"1 ") : String(u"0 ")));
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Centroids::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 哪些点可以改造成重心
// 给定一棵n个点的树，你可以随便删掉一条边，然后随便加上一条边
// 通过这种方式可以让很多点变成重心
// 打印所有能变成重心的点
// 测试链接 : https://www.luogu.com.cn/problem/CF708C
// 测试链接 : https://codeforces.com/problemset/problem/708/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // size[i]: i内部，整棵子树大小
        // maxsub[i]: i内部，最大子树，是i节点的哪个儿子拥有，记录节点编号
        // inner1[i]: i内部，<=n/2且第一大的子树是多大，记录大小
        // inner2[i]: i内部，<=n/2且第二大的子树是多大，记录大小
        // 注意: inner1[i]和inner2[i]，所代表的子树一定要来自i的不同儿子
        // choose[i]: inner1[i]所代表的子树，是i节点的哪个儿子拥有，记录节点编号
        // outer[i]: i外部，<=n/2且第一大的子树是多大，记录大小
*/
