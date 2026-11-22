// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/AT_abc302_h
// https://atcoder.jp/contests/abc302/tasks/abc302_h

// Source: src/class165/Code02_UndoUnionFind1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_UndoUnionFind1 {
  inline static int MAXN = 200001;
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> edgeCnt = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int ball = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_UndoUnionFind1() {}
  static void addEdge(int u, int v) {
    (next[(++cnt)] = head[u]);
    (to[cnt] = v);
    (head[u] = cnt);
  }
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code02_UndoUnionFind1::find(x);
    int fy = Code02_UndoUnionFind1::find(y);
    if ((siz[fx] < siz[fy])) {
      int tmp = fx;
      (fx = fy);
      (fy = tmp);
    }
    (father[fy] = fx);
    (siz[fx] += siz[fy]);
    (edgeCnt[fx] += (edgeCnt[fy] + 1));
    (rollback[(++opsize)][0] = fx);
    (rollback[opsize][1] = fy);
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (siz[fx] -= siz[fy]);
    (edgeCnt[fx] -= (edgeCnt[fy] + 1));
  }
  static void dfs(int u, int fa) {
    int fx = Code02_UndoUnionFind1::find(arr[u][0]);
    int fy = Code02_UndoUnionFind1::find(arr[u][1]);
    bool added = false;
    bool unioned = false;
    if ((fx == fy)) {
      if ((edgeCnt[fx] < siz[fx])) {
        (ball++);
        (added = true);
      }
      (edgeCnt[fx]++);
    } else {
      if (((edgeCnt[fx] < siz[fx]) || (edgeCnt[fy] < siz[fy]))) {
        (ball++);
        (added = true);
      }
      Code02_UndoUnionFind1::union_method(fx, fy);
      (unioned = true);
    }
    (ans[u] = ball);
    for (int e = head[u]; (e > 0); (e = next[e])) {
      if ((to[e] != fa)) {
        Code02_UndoUnionFind1::dfs(to[e], u);
      }
    }
    if (added) {
      (ball--);
    }
    if (unioned) {
      Code02_UndoUnionFind1::undo();
    } else {
      (edgeCnt[fx]--);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (arr[i][1] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_UndoUnionFind1::addEdge(u, v);
        Code02_UndoUnionFind1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
      (edgeCnt[i] = 0);
    }
    Code02_UndoUnionFind1::dfs(1, 0);
    for (int i = 2; (i < n); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println(ans[n]);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_UndoUnionFind1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可撤销并查集模版题，java版
// 一共有n个点，每个点有两个小球，每个点给定两个小球的编号
// 一共有n-1条无向边，所有节点连成一棵树
// 对i号点，2 <= i <= n，都计算如下问题的答案并打印
// 从1号点到i号点的最短路径上，每个点只能拿一个小球，最多能拿几个编号不同的小球
// 1 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/AT_abc302_h
// 测试链接 : https://atcoder.jp/contests/abc302/tasks/abc302_h
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
