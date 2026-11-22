// Source: src/class199/Code05_DiameterMinimize1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_DiameterMinimize1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> fromNode = make_array<int>(MAXN);
  inline static Array<int> fromWeight = make_array<int>(MAXN);
  inline static Array<bool> cycle = make_array<bool>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> val = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<i64> dist = make_array<i64>(MAXN);
  inline static i64 diameter = {};
  inline static Array<i64> height = make_array<i64>(MAXN);
  inline static Array<i64> preMax = make_array<i64>(MAXN);
  inline static Array<i64> preDiameter = make_array<i64>(MAXN);
  inline static Array<i64> sufMax = make_array<i64>(MAXN);
  inline static Array<i64> sufDiameter = make_array<i64>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_DiameterMinimize1() {}
  static void push(int u, int status, int e) {
    (stau[stacksize] = u);
    (stas[stacksize] = status);
    (stae[stacksize] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stau[stacksize]);
    (status = stas[stacksize]);
    (e = stae[stacksize]);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void dfs1(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (fromNode[v] = u);
        (fromWeight[v] = weight[e]);
        Code05_DiameterMinimize1::dfs1(v);
      } else if ((dfn[u] < dfn[v])) {
        (cycle[u] = true);
        (arr[(++cnta)] = u);
        (val[cnta] = weight[e]);
        for (int i = v; (i != u); (i = fromNode[i])) {
          (cycle[i] = true);
          (arr[(++cnta)] = i);
          (val[cnta] = fromWeight[i]);
        }
      }
    }
  }
  static void dfs2(int cur) {
    (stacksize = 0);
    Code05_DiameterMinimize1::push(cur, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_DiameterMinimize1::pop();
      if ((status == (-1))) {
        (dfn[u] = (++cntd));
        (e = head[u]);
      } else {
        (v = to[e]);
        if (((status == 1) && (dfn[u] < dfn[v]))) {
          (cycle[u] = true);
          (arr[(++cnta)] = u);
          (val[cnta] = weight[e]);
          for (int i = v; (i != u); (i = fromNode[i])) {
            (cycle[i] = true);
            (arr[(++cnta)] = i);
            (val[cnta] = fromWeight[i]);
          }
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_DiameterMinimize1::push(u, 0, e);
          (fromNode[v] = u);
          (fromWeight[v] = weight[e]);
          Code05_DiameterMinimize1::push(v, (-1), (-1));
        } else {
          Code05_DiameterMinimize1::push(u, 1, e);
        }
      }
    }
  }
  static void dpOnTree(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if (((v != fa) && (!cycle[v]))) {
        Code05_DiameterMinimize1::dpOnTree(v, u);
        (diameter = jmax(diameter, ((dist[u] + dist[v]) + w)));
        (dist[u] = jmax(dist[u], (dist[v] + w)));
      }
    }
  }
  static i64 dpOnCycle() {
    i64 best = 0;
    i64 sum = 0;
    for (int i = 1; (i <= cnta); (i++)) {
      (preMax[i] = jmax(preMax[(i - 1)], (height[i] + sum)));
      (preDiameter[i] = jmax(preDiameter[(i - 1)], ((sum + height[i]) + best)));
      (best = jmax(best, (height[i] - sum)));
      (sum += val[i]);
    }
    (sufMax[cnta] = (height[cnta] + val[cnta]));
    (sufDiameter[cnta] = height[cnta]);
    (best = (height[cnta] - val[cnta]));
    (sum = (val[cnta] + val[(cnta - 1)]));
    for (int i = (cnta - 1); (i >= 1); (i--)) {
      (sufMax[i] = jmax(sufMax[(i + 1)], (height[i] + sum)));
      (sufDiameter[i] = jmax(sufDiameter[(i + 1)], ((sum + height[i]) + best)));
      (best = jmax(best, (height[i] - sum)));
      (sum += val[(i - 1)]);
    }
    i64 ans = std::numeric_limits<i64>::max();
    for (int i = 1; (i < cnta); (i++)) {
      (ans = jmin(ans, jmax((preMax[i] + sufMax[(i + 1)]),
                            jmax(preDiameter[i], sufDiameter[(i + 1)]))));
    }
    (ans = jmin(ans, preDiameter[cnta]));
    return ans;
  }
  static i64 compute() {
    Code05_DiameterMinimize1::dfs2(1);
    i64 ans1 = 0;
    for (int i = 1; (i <= cnta); (i++)) {
      (diameter = 0);
      Code05_DiameterMinimize1::dpOnTree(arr[i], 0);
      (ans1 = jmax(ans1, diameter));
      (height[i] = dist[arr[i]]);
    }
    i64 ans2 = Code05_DiameterMinimize1::dpOnCycle();
    return jmax(ans1, ans2);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i <= n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code05_DiameterMinimize1::addEdge(u, v, w);
        Code05_DiameterMinimize1::addEdge(v, u, w);
      }
    }
    i64 ans = Code05_DiameterMinimize1::compute();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_DiameterMinimize1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树直径最小化，java版
// 图中有n个点、n条无向边，每条边有边权，图是一棵基环树
// 可以任意删掉环上的一条边，让图变成树，希望让树的直径最小
// 第一个测试链接，计算树的直径最小值
// 第二个测试链接，等价于计算树的直径最小值 / 2，结果保留一位小数
// 1 <= n <= 2 * 10^5
// 1 <= 边权 <= 10^9
// 测试链接 : https://codeforces.com/problemset/problem/835/F
// 测试链接 : https://www.luogu.com.cn/problem/P1399
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
                // dfs1(1);
                // 王国道路，CF835F，使用如下打印
                // 快餐店，洛谷P1399，使用如下打印
                // out.printf("%.1f\n", (double) ans / 2.0);
        // 读写工具类
*/
