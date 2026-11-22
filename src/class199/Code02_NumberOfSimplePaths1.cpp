// Source: src/class199/Code02_NumberOfSimplePaths1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NumberOfSimplePaths1 {
  inline static int MAXN = 200001;
  inline static int t = {};
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<bool> cycle = make_array<bool>(MAXN);
  inline static Array<i64> siz = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NumberOfSimplePaths1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (from[v] = u);
        Code02_NumberOfSimplePaths1::dfs(v);
      } else if ((dfn[u] < dfn[v])) {
        (cycle[u] = true);
        for (int i = v; (i != u); (i = from[i])) {
          (cycle[i] = true);
        }
      }
    }
  }
  static void dpOnTree(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!cycle[v]))) {
        Code02_NumberOfSimplePaths1::dpOnTree(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static i64 compute() {
    Code02_NumberOfSimplePaths1::dfs(1);
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if (cycle[i]) {
        Code02_NumberOfSimplePaths1::dpOnTree(i, 0);
        (ans += (jdiv((siz[i] * (siz[i] - 1)), 2) + (siz[i] * (n - siz[i]))));
      }
    }
    return ans;
  }
  static void prepare() {
    (cntg = (cntd = 0));
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = (dfn[i] = 0));
      (cycle[i] = false);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      Code02_NumberOfSimplePaths1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= n); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code02_NumberOfSimplePaths1::addEdge(u, v);
          Code02_NumberOfSimplePaths1::addEdge(v, u);
        }
      }
      i64 ans = Code02_NumberOfSimplePaths1::compute();
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_NumberOfSimplePaths1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 简单路径数量，java版
// 图中有n个点、n条无向边，图是一棵基环树，图中没有重边和自环
// 点x到点y的简单路径，要求没有重复节点，要求边的数量 >= 1
// 如果两条简单路径只有方向相反，那么认为是同一条简单路径，不要重复统计
// 比如(a, b, c)和(c, b, a)，就是同一条简单路径
// 计算图中简单路径的数量
// 3 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF1454E
// 测试链接 : https://codeforces.com/problemset/problem/1454/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
