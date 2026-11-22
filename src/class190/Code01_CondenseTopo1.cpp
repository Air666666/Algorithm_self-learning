// Source: src/class190/Code01_CondenseTopo1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CondenseTopo1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CondenseTopo1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code01_CondenseTopo1::tarjan(v);
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
        (sum[sccCnt] += arr[pop]);
      } while ((pop != u));
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        (indegree[scc2]++);
        Code01_CondenseTopo1::addEdge(scc1, scc2);
      }
    }
  }
  static int topo() {
    int l = 1;
    int r = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((indegree[i] == 0)) {
        (dp[i] = sum[i]);
        (que[(++r)] = i);
      }
    }
    while ((l <= r)) {
      int u = que[(l++)];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        (dp[v] = jmax(dp[v], (dp[u] + sum[v])));
        if (((--indegree[v]) == 0)) {
          (que[(++r)] = v);
        }
      }
    }
    int ans = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static int dpOnDAG() {
    for (int u = sccCnt; (u > 0); (u--)) {
      if ((indegree[u] == 0)) {
        (dp[u] = sum[u]);
      }
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        (dp[v] = jmax(dp[v], (dp[u] + sum[v])));
      }
    }
    int ans = 0;
    for (int u = 1; (u <= sccCnt); (u++)) {
      (ans = jmax(ans, dp[u]));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code01_CondenseTopo1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code01_CondenseTopo1::tarjan(i);
      }
    }
    Code01_CondenseTopo1::condense();
    int ans = Code01_CondenseTopo1::dpOnDAG();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CondenseTopo1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 缩点结合动态规划模版题，java版
// 给定一张n个点，m条边的有向图，每个点给定非负点权
// 如果重复经过一个点，点权只获得一次
// 找到一条路径，使得点权累加和最大，打印这个值
// 1 <= n <= 10^4
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3387
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 拓扑排序的写法
        // 直接转移的写法
                // int ans = topo();
        // 读写工具类
*/
