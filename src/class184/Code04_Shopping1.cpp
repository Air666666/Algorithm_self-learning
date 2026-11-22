// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6326

// Source: src/class184/Code04_Shopping1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Shopping1 {
  inline static int MAXN = 501;
  inline static int MAXM = 4001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> d = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> nodeArr = make_array<int>(MAXN);
  inline static Array<int> endDfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<Array<int>> dp = make_array<int>((MAXN + 1), MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Shopping1() {}
  static void prepare() {
    (cntg = 0);
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = 0);
      (vis[i] = false);
    }
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code04_Shopping1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code04_Shopping1::getSize(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void dfs(int u, int fa) {
    (nodeArr[(++cntd)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code04_Shopping1::dfs(v, u);
      }
    }
    (endDfn[u] = cntd);
  }
  static int calc(int u) {
    (cntd = 0);
    Code04_Shopping1::dfs(u, 0);
    for (int i = cntd; (i > 0); (i--)) {
      int cur = nodeArr[i];
      int cnt = (d[cur] - 1);
      int num = 0;
      for (int k = 1; (k <= cnt); (k = jshl(k, 1))) {
        (val[(++num)] = (v[cur] * k));
        (cost[num] = (c[cur] * k));
        (cnt -= k);
      }
      if ((cnt > 0)) {
        (val[(++num)] = (v[cur] * cnt));
        (cost[num] = (c[cur] * cnt));
      }
      for (int j = m; (j >= c[cur]); (j--)) {
        (dp[i][j] = (dp[(i + 1)][(j - c[cur])] + v[cur]));
      }
      for (int k = 1; (k <= num); (k++)) {
        for (int j = m; (j >= cost[k]); (j--)) {
          (dp[i][j] = jmax(dp[i][j], (dp[i][(j - cost[k])] + val[k])));
        }
      }
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = jmax(dp[i][j], dp[(endDfn[cur] + 1)][j]));
      }
    }
    int ans = dp[1][m];
    for (int i = 1; (i <= cntd); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = 0);
      }
    }
    return ans;
  }
  static int solve(int u) {
    (vis[u] = true);
    int ans = Code04_Shopping1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans = jmax(ans, Code04_Shopping1::solve(
                             Code04_Shopping1::getCentroid(v, u))));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int k = 1; (k <= t); (k++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      for (int i = 1; (i <= n); (i++)) {
        (v[i] = in.nextInt());
      }
      for (int i = 1; (i <= n); (i++)) {
        (c[i] = in.nextInt());
      }
      for (int i = 1; (i <= n); (i++)) {
        (d[i] = in.nextInt());
      }
      Code04_Shopping1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code04_Shopping1::addEdge(u, v);
          Code04_Shopping1::addEdge(v, u);
        }
      }
      out.println(Code04_Shopping1::solve(Code04_Shopping1::getCentroid(1, 0)));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Shopping1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树上购物，java版
// 一共有n个商店，有n-1条路构成一棵树，第i个商店只卖第i种物品
// 给定每种物品三个属性，价值v[i]、单价c[i]、数量d[i]
// 你逛商店可能会购买物品，要求所有买过东西的商店，在树上必须连通
// 你有m元，打印能获得的最大价值总和
// 1 <= n <= 500    1 <= m <= 4000    1 <= d[i] <= 2000
// 测试链接 : https://www.luogu.com.cn/problem/P6326
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 二进制分组优化，注意物品量-1，然后二进制分组
                        // 先必选一件，然后考虑更多件，课上解释了为什么
                        // 必选cur的情况，先必选一件
                        // 然后用二进制分组，拼出可能的更多件
                        //
不选cur的情况，那么cur的子树都跳过，直接跳到endDfn[cur] + 1
                // 返回之前清空
        // 读写工具类
*/
