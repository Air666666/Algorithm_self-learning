// Source: src/class199/Code01_DirectedRoads1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DirectedRoads1 {
  inline static int MAXN = 200001;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int cntb = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<int> all = make_array<int>(MAXN);
  inline static Array<int> cycle = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DirectedRoads1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static i64 power(i64 x, i64 p) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (p = jshr(p, 1));
    }
    return ans;
  }
  static void dfs(int u) {
    (dfn[u] = (++cntd));
    (all[cntb]++);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (from[v] = u);
        Code01_DirectedRoads1::dfs(v);
      } else if ((dfn[u] < dfn[v])) {
        (cycle[cntb]++);
        for (int i = v; (i != u); (i = from[i])) {
          (cycle[cntb]++);
        }
      }
    }
  }
  static i64 compute() {
    i64 ans = 1;
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        (cntb++);
        Code01_DirectedRoads1::dfs(i);
        i64 a = Code01_DirectedRoads1::power(2, all[cntb]);
        i64 b =
            Code01_DirectedRoads1::power(2, ((all[cntb] - cycle[cntb]) + 1));
        (ans = jrem((ans * jrem(((a - b) + MOD), MOD)), MOD));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        (x = in.nextInt());
        Code01_DirectedRoads1::addEdge(i, x);
        Code01_DirectedRoads1::addEdge(x, i);
      }
    }
    i64 ans = Code01_DirectedRoads1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DirectedRoads1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 定向道路，java版
// 图中有n个点、n条无向边
// 图中可能有多个连通块，保证每个连通块都是一棵基环树
// 你可以给每条边分配一个方向，要求得到的有向图不能出现环
// 计算有多少种定向的方案，答案对 1000000007 取余
// 2 <= n <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF711D
// 测试链接 : https://codeforces.com/problemset/problem/711/D
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // all[x] = 第x棵基环树的节点总数 = 第x棵基环树的边总数
        // cycle[x] = 第x棵基环树的环上节点数 = 第x棵基环树的环上边数
        // 读写工具类
*/
