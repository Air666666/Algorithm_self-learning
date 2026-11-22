// Source: src/class200/Code04_CactusIndependentSet1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CactusIndependentSet1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int INF = 1000000000;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
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
  inline static Array<Array<int>> dp = make_array<int>(MAXN, 2);
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stap = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CactusIndependentSet1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stau[stacksiz] = u);
    (stap[stacksiz] = preEdge);
    (stas[stacksiz] = status);
    (stae[stacksiz] = e);
    (stacksiz++);
  }
  static void pop() {
    (stacksiz--);
    (u = stau[stacksiz]);
    (preEdge = stap[stacksiz]);
    (status = stas[stacksiz]);
    (e = stae[stacksiz]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dpOnCycle(int u, int v) {
    int siz = 0;
    int pop = {};
    do {
      (pop = sta[(top--)]);
      (cycle[(++siz)] = pop);
    } while ((pop != v));
    int pre0 = dp[cycle[1]][0];
    int pre1 = dp[cycle[1]][1];
    int cur0 = {};
    int cur1 = {};
    for (int i = 2; (i <= siz); (i++)) {
      int x = cycle[i];
      (cur0 = (jmax(pre0, pre1) + dp[x][0]));
      (cur1 = (pre0 + dp[x][1]));
      (pre0 = cur0);
      (pre1 = cur1);
    }
    (dp[u][0] += jmax(pre0, pre1));
    (pre0 = dp[cycle[1]][0]);
    (pre1 = (-INF));
    for (int i = 2; (i <= siz); (i++)) {
      int x = cycle[i];
      (cur0 = (jmax(pre0, pre1) + dp[x][0]));
      (cur1 = (pre0 + dp[x][1]));
      (pre0 = cur0);
      (pre1 = cur1);
    }
    (dp[u][1] += pre0);
  }
  static void tarjan1(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    (dp[u][0] = 0);
    (dp[u][1] = arr[u]);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code04_CactusIndependentSet1::tarjan1(v, e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (dp[u][0] += jmax(dp[v][0], dp[v][1]));
          (dp[u][1] += dp[v][0]);
          (top--);
        } else {
          Code04_CactusIndependentSet1::dpOnCycle(u, v);
        }
      } else if ((dfn[v] < dfn[u])) {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksiz = 0);
    Code04_CactusIndependentSet1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksiz > 0)) {
      Code04_CactusIndependentSet1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (dp[u][0] = 0);
        (dp[u][1] = arr[u]);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          if ((low[v] < dfn[u])) {
            (low[u] = jmin(low[u], low[v]));
          } else if ((low[v] > dfn[u])) {
            (dp[u][0] += jmax(dp[v][0], dp[v][1]));
            (dp[u][1] += dp[v][0]);
            (top--);
          } else {
            Code04_CactusIndependentSet1::dpOnCycle(u, v);
          }
        } else {
          if ((dfn[v] < dfn[u])) {
            (low[u] = jmin(low[u], dfn[v]));
          }
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code04_CactusIndependentSet1::push(u, preEdge, 0, e);
          Code04_CactusIndependentSet1::push(v, e, (-1), (-1));
        } else {
          Code04_CactusIndependentSet1::push(u, preEdge, 1, e);
        }
      }
    }
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
        Code04_CactusIndependentSet1::addEdge(u, v);
        Code04_CactusIndependentSet1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    Code04_CactusIndependentSet1::tarjan2(1, 0);
    out.println(jmax(dp[1][0], dp[1][1]));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_CactusIndependentSet1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌最大独立集，java版
// 给定n个点、m条边的无向连通图，输入保证图是仙人掌
// 你可以选择一些点，但是图中任意相邻两点不能同时选择
// 计算能得到的最大点权累加和
// 第一个测试链接，给定每个点的点权
// 第二个测试链接，认为每个点的点权是1
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4410
// 测试链接 : https://www.luogu.com.cn/problem/P10779
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 收集环上的节点，不包含环顶
        // dp[u][0] : 以u为头的子仙人掌中，不选u的情况下，获得的最大收益
        // dp[u][1] : 以u为头的子仙人掌中，选u的情况下，获得的最大收益
        // 递归改迭代需要的栈
                // 不选u
                // 选u
        // 递归版
        // 迭代版
                // 洛谷P4410，使用如下的点权设置
                // 洛谷P10779，使用如下的点权设置
//		for (int i = 1; i <= n; i++) {
//			arr[i] = 1;
//		}
        // 读写工具类
*/
