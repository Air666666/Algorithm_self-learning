// Source: src/class200/Code03_CactusLongestRoute1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CactusLongestRoute1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 20001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> cycle = make_array<int>(MAXN);
  inline static Array<int> f = make_array<int>(MAXN);
  inline static Array<int> g = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CactusLongestRoute1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static int dpOnCycle(int u, int v) {
    int siz = 0;
    int pop = {};
    do {
      (pop = sta[(top--)]);
      (cycle[(++siz)] = pop);
    } while ((pop != v));
    int best = 0;
    int sum = 1;
    for (int i = 1; (i <= siz); (i++)) {
      (best = jmax(best, (sum + g[cycle[i]])));
      (sum += (f[cycle[i]] + 1));
    }
    (f[u] += sum);
    int otherSide = sum;
    for (int i = 1; (i <= siz); (i++)) {
      (otherSide -= (f[cycle[i]] + 1));
      (best = jmax(best, (otherSide + g[cycle[i]])));
    }
    return (best - sum);
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    int delta = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_CactusLongestRoute1::tarjan(v, e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (top--);
          (delta = jmax(delta, (g[v] + 1)));
        } else {
          (delta = jmax(delta, Code03_CactusLongestRoute1::dpOnCycle(u, v)));
        }
      } else if ((dfn[v] < dfn[u])) {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    (g[u] = (f[u] + delta));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntg = 1);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code03_CactusLongestRoute1::addEdge(u, v);
        Code03_CactusLongestRoute1::addEdge(v, u);
      }
    }
    Code03_CactusLongestRoute1::tarjan(1, 0);
    out.println(g[1]);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_CactusLongestRoute1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌最长路线，java版
// 给定n个点、m条边的无向连通图，输入保证图是仙人掌
// 路线可以从任何城市开始，但必须在1号点结束
// 路线可以重复经过同一个点，但不能重复经过同一条边
// 计算最长路线的边数
// 1 <= n <= 10^4
// 1 <= m <= 2 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P6335
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // f[u] :
在u向下的结构中（以u为头的子仙人掌），从u出发并最终回到u，能走过的最大边数
        // g[u] :
在u向下的结构中（以u为头的子仙人掌），从u出发，终点任意，能走过的最大边数
                // best表示，这个环上任选一个点作为最后出去的位置
                // 从u沿两侧之一走到它，能够得到的不回到u的最大边数
                // u可以下方有多个环，所以新增此时的sum
                // f[u]表示从u出发并最终回到u的最大边数
                // delta为了计算，g[u] = f[u] + delta
                // 表示额外选择一条最后不回到u的出口路线，能带来的最大增量
        // 读写工具类
*/
