// Source: src/class190/Code03_RobberyPlan1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_RobberyPlan1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 500001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static int p = {};
  inline static Array<int> money = make_array<int>(MAXN);
  inline static Array<bool> isBar = make_array<bool>(MAXN);
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
  inline static Array<bool> hasBar = make_array<bool>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_RobberyPlan1() {}
  static void push(int u, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_RobberyPlan1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (sum[sccCnt] = 0);
      (hasBar[sccCnt] = false);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (sum[sccCnt] += money[pop]);
        (hasBar[sccCnt] = (hasBar[sccCnt] | isBar[pop]));
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code03_RobberyPlan1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code03_RobberyPlan1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code03_RobberyPlan1::push(u, 0, e);
          Code03_RobberyPlan1::push(v, (-1), (-1));
        } else {
          Code03_RobberyPlan1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (sum[sccCnt] = 0);
          (hasBar[sccCnt] = false);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sum[sccCnt] += money[pop]);
            (hasBar[sccCnt] = (hasBar[sccCnt] | isBar[pop]));
          } while ((pop != u));
        }
      }
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
      if ((((scc1 > 0) && (scc2 > 0)) && (scc1 != scc2))) {
        Code03_RobberyPlan1::addEdge(scc1, scc2);
      }
    }
  }
  static int dpOnDAG() {
    for (int u = 1; (u <= sccCnt); (u++)) {
      (dp[u] = (-INF));
    }
    (dp[belong[s]] = sum[belong[s]]);
    for (int u = sccCnt; (u > 0); (u--)) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        (dp[v] = jmax(dp[v], (dp[u] + sum[v])));
      }
    }
    int ans = 0;
    for (int u = 1; (u <= sccCnt); (u++)) {
      if (hasBar[u]) {
        (ans = jmax(ans, dp[u]));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code03_RobberyPlan1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      (money[i] = in.nextInt());
    }
    (s = in.nextInt());
    (p = in.nextInt());
    {
      int i = 1;
      int x = {};
      for (; (i <= p); (i++)) {
        (x = in.nextInt());
        (isBar[x] = true);
      }
    }
    Code03_RobberyPlan1::tarjan2(s);
    Code03_RobberyPlan1::condense();
    int ans = Code03_RobberyPlan1::dpOnDAG();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_RobberyPlan1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 劫掠计划，java版
// 一共有n个城市，给定m条有向道路，每个城市给定拥有的钱数
// 给定起点城市s，给定p个有酒吧的城市，有酒吧的城市才能作为终点
// 路线必须从s出发到任意终点停止，重复经过城市的话，钱仅获得一次
// 题目保证一定存在这样的路线，打印能获得的最大钱数
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3627
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                // tarjan1(s);
        // 读写工具类
*/
