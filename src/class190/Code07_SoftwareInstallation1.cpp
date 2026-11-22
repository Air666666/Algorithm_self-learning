// Source: src/class190/Code07_SoftwareInstallation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_SoftwareInstallation1 {
  inline static int MAXN = 301;
  inline static int MAXM = 601;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> depend = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> wsum = make_array<int>(MAXN);
  inline static Array<int> vsum = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static Array<int> value = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_SoftwareInstallation1() {}
  static void addEdge(int a, int b) {
    (nxt[(++cntg)] = head[a]);
    (to[cntg] = b);
    (head[a] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code07_SoftwareInstallation1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (wsum[sccCnt] += w[pop]);
        (vsum[sccCnt] += v[pop]);
      } while ((pop != u));
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((depend[i] > 0)) {
        int scc1 = belong[depend[i]];
        int scc2 = belong[i];
        if ((scc1 != scc2)) {
          (indegree[scc2]++);
          Code07_SoftwareInstallation1::addEdge(scc1, scc2);
        }
      }
    }
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((indegree[i] == 0)) {
        Code07_SoftwareInstallation1::addEdge(0, i);
      }
    }
  }
  static int dfs(int u) {
    int i = (++dfnCnt);
    (siz[i] = 1);
    (weight[i] = wsum[u]);
    (value[i] = vsum[u]);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      (siz[i] += Code07_SoftwareInstallation1::dfs(v));
    }
    return siz[i];
  }
  static int knapsackOnTree() {
    Code07_SoftwareInstallation1::dfs(0);
    for (int i = dfnCnt; (i >= 2); (i--)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] = dp[(i + siz[i])][j]);
        if (((j - weight[i]) >= 0)) {
          (dp[i][j] =
               jmax(dp[i][j], (value[i] + dp[(i + 1)][(j - weight[i])])));
        }
      }
    }
    return dp[2][m];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (w[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (depend[i] = in.nextInt());
      if ((depend[i] > 0)) {
        Code07_SoftwareInstallation1::addEdge(depend[i], i);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code07_SoftwareInstallation1::tarjan(i);
      }
    }
    Code07_SoftwareInstallation1::condense();
    int ans = Code07_SoftwareInstallation1::knapsackOnTree();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_SoftwareInstallation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 软件安装，java版
// 一共有n个物品，你的背包能容纳的总重量为m
// 选择某个物品时，重量消耗为当前物品的w，获得收益为当前物品的v
// 给定每个物品最多一件依赖物品，不拿依赖物品无法选择当前物品
// 如果一批物品循环依赖，想选的话就只能都选，有的物品不存在依赖物品
// 打印你能获得的最大收益
// 0 <= n <= 100
// 0 <= m <= 500
// 测试链接 : https://www.luogu.com.cn/problem/P2515
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 树上背包最优解，来自讲解079，题目5
        // 缩点后的树，每个节点重新分配dfn序号
        // 树上01背包最优解
        // 讲解079，题目5，树上背包最优解，讲的非常清楚
        // 读写工具类
*/
