// Source: src/class199/Code04_RingRoad1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_RingRoad1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static double k = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static int x = {};
  inline static int y = {};
  inline static int skip = {};
  inline static Array<Array<int>> dp = make_array<int>(MAXN, 2);
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> staf = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_RingRoad1() {}
  static void push(int u, int status, int fa, int e) {
    (stau[stacksize] = u);
    (stas[stacksize] = status);
    (staf[stacksize] = fa);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stau[stacksize]);
    (status = stas[stacksize]);
    (fa = staf[stacksize]);
    (e = stae[stacksize]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code04_RingRoad1::dfs1(v);
      } else if ((dfn[u] < dfn[v])) {
        (x = u);
        (y = v);
        (skip = jshr((e + 1), 1));
      }
    }
  }
  static void dfs2(int cur) {
    (stacksize = 0);
    Code04_RingRoad1::push(cur, (-1), 0, (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code04_RingRoad1::pop();
      if ((status == (-1))) {
        (dfn[u] = (++cntd));
        (e = head[u]);
      } else {
        (v = to[e]);
        if (((status == 1) && (dfn[u] < dfn[v]))) {
          (x = u);
          (y = v);
          (skip = jshr((e + 1), 1));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code04_RingRoad1::push(u, 0, 0, e);
          Code04_RingRoad1::push(v, (-1), 0, (-1));
        } else {
          Code04_RingRoad1::push(u, 1, 0, e);
        }
      }
    }
  }
  static void dpOnTree1(int u, int fa) {
    (dp[u][0] = 0);
    (dp[u][1] = arr[u]);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (jshr((e + 1), 1) != skip))) {
        Code04_RingRoad1::dpOnTree1(v, u);
        (dp[u][0] += jmax(dp[v][0], dp[v][1]));
        (dp[u][1] += dp[v][0]);
      }
    }
  }
  static void dpOnTree2(int cur, int father) {
    (stacksize = 0);
    Code04_RingRoad1::push(cur, 0, father, (-1));
    while ((stacksize > 0)) {
      Code04_RingRoad1::pop();
      if ((e == (-1))) {
        (dp[u][0] = 0);
        (dp[u][1] = arr[u]);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_RingRoad1::push(u, 0, fa, e);
        if (((to[e] != fa) && (jshr((e + 1), 1) != skip))) {
          Code04_RingRoad1::push(to[e], 0, u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != fa) && (jshr((ei + 1), 1) != skip))) {
            (dp[u][0] += jmax(dp[v][0], dp[v][1]));
            (dp[u][1] += dp[v][0]);
          }
        }
      }
    }
  }
  static i64 compute() {
    (x = (y = 0));
    Code04_RingRoad1::dfs2(1);
    Code04_RingRoad1::dpOnTree2(x, 0);
    i64 ans = dp[x][0];
    Code04_RingRoad1::dpOnTree2(y, 0);
    (ans = jmax(ans, dp[y][0]));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (u++);
        (v++);
        Code04_RingRoad1::addEdge(u, v);
        Code04_RingRoad1::addEdge(v, u);
      }
    }
    (k = in.nextDouble());
    i64 ans = Code04_RingRoad1::compute();
    out.printf(String(u"%.1f\n"), (k * ans));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_RingRoad1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 城市环路，java版
// 图中有n个点、n条无向边，每个点有点权，图是一棵基环树
// 图中任意相邻两点不能同时选择，先得到最大的点权累加和
// 然后乘以题目给定的系数k，打印结果
// 1 <= n <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1453
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
        // 递归版
        // 迭代版
                // dfs1(1);
                // dpOnTree1(x, 0);
                // dpOnTree1(y, 0);
        // 读写工具类
*/
