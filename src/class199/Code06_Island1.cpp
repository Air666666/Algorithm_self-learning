// Source: src/class199/Code06_Island1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Island1 {
  inline static int MAXN = 1000001;
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
  inline static Array<i64> sum = make_array<i64>(jshl(MAXN, 1));
  inline static Array<i64> height = make_array<i64>(jshl(MAXN, 1));
  inline static Array<int> que = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Island1() {}
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
        Code06_Island1::dfs1(v);
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
    Code06_Island1::push(cur, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code06_Island1::pop();
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
          Code06_Island1::push(u, 0, e);
          (fromNode[v] = u);
          (fromWeight[v] = weight[e]);
          Code06_Island1::push(v, (-1), (-1));
        } else {
          Code06_Island1::push(u, 1, e);
        }
      }
    }
  }
  static void dpOnTree(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if (((v != fa) && (!cycle[v]))) {
        Code06_Island1::dpOnTree(v, u);
        (diameter = jmax(diameter, ((dist[u] + dist[v]) + w)));
        (dist[u] = jmax(dist[u], (dist[v] + w)));
      }
    }
  }
  static i64 compute(int root) {
    (cnta = 0);
    Code06_Island1::dfs2(root);
    (sum[1] = 0);
    {
      int i = 2;
      int j = 1;
      for (; (j <= cnta); (i++), (j++)) {
        (sum[i] = val[j]);
      }
    }
    for (int i = (cnta + 2); (i <= (cnta * 2)); (i++)) {
      (sum[i] = sum[(i - cnta)]);
    }
    for (int i = 1; (i <= (cnta * 2)); (i++)) {
      (sum[i] += sum[(i - 1)]);
    }
    i64 ans1 = 0;
    for (int i = 1; (i <= cnta); (i++)) {
      (diameter = 0);
      Code06_Island1::dpOnTree(arr[i], 0);
      (ans1 = jmax(ans1, diameter));
      (height[i] = dist[arr[i]]);
      (height[(i + cnta)] = height[i]);
    }
    i64 ans2 = 0;
    int ql = 1;
    int qr = 0;
    for (int i = 1; (i <= (cnta * 2)); (i++)) {
      while (((ql <= qr) && (que[ql] <= (i - cnta)))) {
        (ql++);
      }
      if ((ql <= qr)) {
        (ans2 = jmax(
             ans2, (((height[i] + height[que[ql]]) + sum[i]) - sum[que[ql]])));
      }
      while (((ql <= qr) &&
              ((height[que[qr]] - sum[que[qr]]) <= (height[i] - sum[i])))) {
        (qr--);
      }
      (que[(++qr)] = i);
    }
    return jmax(ans1, ans2);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int u = 1;
      int v = {};
      int w = {};
      for (; (u <= n); (u++)) {
        (v = in.nextInt());
        (w = in.nextInt());
        Code06_Island1::addEdge(u, v, w);
        Code06_Island1::addEdge(v, u, w);
      }
    }
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        (ans += Code06_Island1::compute(i));
      }
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Island1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 岛屿，java版
// 图中有n个点、n条无向边，每条边有边权
// 图中可能有多个连通块，保证每个连通块都是一棵基环树
// 对每个连通块，计算点不重复的路径能得到的最大边权和，即基环树直径
// 图中每棵基环树的直径累加起来，打印这个结果
// 2 <= n <= 10^6
// 1 <= 边权 <= 10^8
// 测试链接 : https://www.luogu.com.cn/problem/P4381
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
                // dfs1(root);
        // 读写工具类
*/
