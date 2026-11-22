// Source: src/class191/Code03_CriticalNetworkLines1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CriticalNetworkLines1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int l = {};
  inline static Array<int> acnt = make_array<int>(MAXN);
  inline static Array<int> bcnt = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> ans1 = make_array<int>(MAXN);
  inline static Array<int> ans2 = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stap = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stasiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CriticalNetworkLines1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stau[stasiz] = u);
    (stap[stasiz] = preEdge);
    (stas[stasiz] = status);
    (stae[stasiz] = e);
    (stasiz++);
  }
  static void pop() {
    (stasiz--);
    (u = stau[stasiz]);
    (preEdge = stap[stasiz]);
    (status = stas[stasiz]);
    (e = stae[stasiz]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_CriticalNetworkLines1::tarjan1(v, e);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] > dfn[u])) {
          if (((((acnt[v] == 0) || (acnt[v] == k)) || (bcnt[v] == 0)) ||
               (bcnt[v] == l))) {
            (cnta++);
            (ans1[cnta] = v);
            (ans2[cnta] = u);
          }
        }
        (acnt[u] += acnt[v]);
        (bcnt[u] += bcnt[v]);
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stasiz = 0);
    Code03_CriticalNetworkLines1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stasiz > 0)) {
      Code03_CriticalNetworkLines1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] > dfn[u])) {
            if (((((acnt[v] == 0) || (acnt[v] == k)) || (bcnt[v] == 0)) ||
                 (bcnt[v] == l))) {
              (cnta++);
              (ans1[cnta] = v);
              (ans2[cnta] = u);
            }
          }
          (acnt[u] += acnt[v]);
          (bcnt[u] += bcnt[v]);
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code03_CriticalNetworkLines1::push(u, preEdge, 0, e);
          Code03_CriticalNetworkLines1::push(v, e, (-1), (-1));
        } else {
          Code03_CriticalNetworkLines1::push(u, preEdge, 1, e);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    (k = in.nextInt());
    (l = in.nextInt());
    {
      int i = 1;
      int x = {};
      for (; (i <= k); (i++)) {
        (x = in.nextInt());
        (acnt[x] = 1);
      }
    }
    {
      int i = 1;
      int x = {};
      for (; (i <= l); (i++)) {
        (x = in.nextInt());
        (bcnt[x] = 1);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code03_CriticalNetworkLines1::addEdge(u, v);
        Code03_CriticalNetworkLines1::addEdge(v, u);
      }
    }
    Code03_CriticalNetworkLines1::tarjan2(1, 0);
    out.println(cnta);
    for (int i = 1; (i <= cnta); (i++)) {
      out.println(((ans1[i] + String(u" ")) + ans2[i]));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_CriticalNetworkLines1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 关键网络线路，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 给定k个提供A服务的节点，给定l个提供B服务的节点，保证k和l都是正数
// 一个节点可能不提供服务，也可能提供A服务或者B服务或者两种都有
// 每个节点可以通过边，获得任何节点提供的服务，但是必须同时获得两种服务
// 如果断开某一条边，使得某些节点无法同时获得两种服务，这样的边叫关键边
// 打印关键边的数量，打印每条关键边的两个端点
// 1 <= n <= 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P7687
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                // tarjan1(1, 0);
        // 读写工具类
*/
