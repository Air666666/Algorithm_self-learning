// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1073

// Source: src/class190/Code04_OptimalTrade1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_OptimalTrade1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 500001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> sccMin = make_array<int>(MAXN);
  inline static Array<int> sccMax = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> premin = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_OptimalTrade1() {}
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
        Code04_OptimalTrade1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (sccMin[sccCnt] = INF);
      (sccMax[sccCnt] = (-INF));
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (sccMin[sccCnt] = jmin(sccMin[sccCnt], val[pop]));
        (sccMax[sccCnt] = jmax(sccMax[sccCnt], val[pop]));
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code04_OptimalTrade1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code04_OptimalTrade1::pop();
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
          Code04_OptimalTrade1::push(u, 0, e);
          Code04_OptimalTrade1::push(v, (-1), (-1));
        } else {
          Code04_OptimalTrade1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (sccMin[sccCnt] = INF);
          (sccMax[sccCnt] = (-INF));
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sccMin[sccCnt] = jmin(sccMin[sccCnt], val[pop]));
            (sccMax[sccCnt] = jmax(sccMax[sccCnt], val[pop]));
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
        Code04_OptimalTrade1::addEdge(scc1, scc2);
      }
    }
  }
  static int dpOnDAG() {
    for (int u = 1; (u <= sccCnt); (u++)) {
      (premin[u] = INF);
      (dp[u] = (-INF));
    }
    int s = belong[1];
    (premin[s] = sccMin[s]);
    (dp[s] = (sccMax[s] - sccMin[s]));
    for (int u = sccCnt; (u > 0); (u--)) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        (premin[v] = jmin(premin[v], jmin(premin[u], sccMin[v])));
        (dp[v] = jmax(dp[v], jmax(dp[u], (sccMax[v] - premin[v]))));
      }
    }
    return dp[belong[n]];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (val[i] = in.nextInt());
    }
    {
      int i = 1;
      int op = {};
      for (; (i <= m); (i++)) {
        (a[i] = in.nextInt());
        (b[i] = in.nextInt());
        (op = in.nextInt());
        if ((op == 1)) {
          Code04_OptimalTrade1::addEdge(a[i], b[i]);
        } else {
          Code04_OptimalTrade1::addEdge(a[i], b[i]);
          Code04_OptimalTrade1::addEdge(b[i], a[i]);
        }
      }
    }
    Code04_OptimalTrade1::tarjan2(1);
    if ((belong[n] == 0)) {
      out.println(0);
    } else {
      Code04_OptimalTrade1::condense();
      int ans = Code04_OptimalTrade1::dpOnDAG();
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_OptimalTrade1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最优贸易，java版
// 一共有n个城市，每个城市给定水晶球的销售价格，给定m条道路
// 格式 a b op : op为1代表a到b的单向路，否则表示双向路
// 你要从1号城市出发，可以任选道路，最终来到n号城市，沿途可以买卖一次水晶球
// 在途中你可以任选一座城市买入，可以立即卖出，或者在之后的任何城市卖出
// 如果从1号城市能到达n号城市，打印挣到的最大钱数，如果不能到达打印0
// 1 <= n <= 10^5
// 1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1073
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                // tarjan1(1);
        // 读写工具类
*/
