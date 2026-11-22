// Source: src/class190/Code02_PickMushroom1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PickMushroom1 {
  inline static int MAXN = 80001;
  inline static int MAXM = 200001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> init = make_array<int>(MAXM);
  inline static Array<int> recover = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PickMushroom1() {}
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
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code02_PickMushroom1::tarjan1(v);
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
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code02_PickMushroom1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code02_PickMushroom1::pop();
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
          Code02_PickMushroom1::push(u, 0, e);
          Code02_PickMushroom1::push(v, (-1), (-1));
        } else {
          Code02_PickMushroom1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
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
      if (((scc1 > 0) && (scc2 > 0))) {
        int val = init[i];
        int rec = recover[i];
        if ((scc1 == scc2)) {
          while ((val > 0)) {
            (sum[scc1] += val);
            (val = jdiv((val * rec), 10));
          }
        } else {
          Code02_PickMushroom1::addEdge(scc1, scc2, val);
        }
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
        int w = weight[e];
        (dp[v] = jmax(dp[v], ((dp[u] + w) + sum[v])));
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
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      (init[i] = in.nextInt());
      double rec = in.nextDouble();
      (recover[i] = static_cast<int>((rec * 10)));
      Code02_PickMushroom1::addEdge(a[i], b[i], 0);
    }
    (s = in.nextInt());
    Code02_PickMushroom1::tarjan2(s);
    Code02_PickMushroom1::condense();
    int ans = Code02_PickMushroom1::dpOnDAG();
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PickMushroom1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 采蘑菇，java版
// 给定一张n个点，m条边的有向图，每条边有初始收益、恢复系数两种边权
// 初始收益为非负整数，恢复系数范围[0, 0.8]，并且最多有一位小数
// 比如，如果重复走过一条边，该边的初始收益为10，恢复系数为0.6
// 那么依次获得的收益为，10、6、3、1、0，随后重复经过就没有收益了
// 给定起点s，找到一条必须从s出发的路径，打印收益累加和的最大值
// 1 <= n <= 8 * 10^4
// 1 <= m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P2656
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，java会爆栈，C++可以通过
        // 迭代版
                // tarjan1(s);
        // 读写工具类
*/
