// Source: src/class121/Code03_BuildPark.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_BuildPark {
  inline static int MAXN = 300001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> diameter = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_BuildPark() {}
  static void build(int n) {
    (cnt = 1);
    j::fill(head, 1, n, 0);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    j::fill(dist, 1, n, 0);
    j::fill(diameter, 1, n, 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_BuildPark::find(father[i]));
    }
    return father[i];
  }
  static void dp(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code03_BuildPark::dp(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (diameter[u] =
               jmax(diameter[u], jmax(diameter[v], ((dist[u] + dist[v]) + 1))));
          (dist[u] = jmax(dist[u], (dist[v] + 1)));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int q = static_cast<int>(in.nval);
    Code03_BuildPark::build(n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code03_BuildPark::addEdge(u, v);
        Code03_BuildPark::addEdge(v, u);
        (u = Code03_BuildPark::find(u));
        (v = Code03_BuildPark::find(v));
        (father[u] = v);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((i == father[i])) {
        Code03_BuildPark::dp(i, 0);
      }
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        in.nextToken();
        (op = static_cast<int>(in.nval));
        if ((op == 1)) {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          (x = Code03_BuildPark::find(x));
          out.println(diameter[x]);
        } else {
          in.nextToken();
          (x = static_cast<int>(in.nval));
          in.nextToken();
          (y = static_cast<int>(in.nval));
          (x = Code03_BuildPark::find(x));
          (y = Code03_BuildPark::find(y));
          if ((x != y)) {
            (father[x] = y);
            (diameter[y] = jmax(
                 ((jdiv((diameter[x] + 1), 2) + jdiv((diameter[y] + 1), 2)) +
                  1),
                 jmax(diameter[x], diameter[y])));
          }
        }
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
  Code03_BuildPark::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 造公园
// 一共n个节点，编号1~n，有m条边连接，边权都是1
// 所有节点可能形成多个连通区，每个连通区保证是树结构
// 有两种类型的操作
// 操作 1 x   : 返回x到离它最远的点的距离
// 操作 2 x y : 如果x和y已经连通，那么忽略
//              如果不连通，那么执行连通操作，把x和y各自的区域连通起来
//              并且要保证连通成的大区域的直径长度最小
// 测试链接 : https://www.luogu.com.cn/problem/P2195
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 并查集需要
        // 树型dp需要
        // dist[u] : 从u开始必须往下走，能走出的最大距离，可以不选任何边
        // diameter[i] : 如果i是集合的头节点，diameter[i]表示整个集合的直径长度
        //               如果i不再是集合的头节点，diameter[i]的值没有用
        // 并查集 + 集合打标签技巧，不会的看讲解056、讲解057
        // 树型dp的方式求直径长度
*/
