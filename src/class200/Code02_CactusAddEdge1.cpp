// Source: src/class200/Code02_CactusAddEdge1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CactusAddEdge1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 1000001;
  inline static int MOD = 998244353;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<bool> cycleEdge = make_array<bool>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> fromEdge = make_array<int>(MAXN);
  inline static Array<int> cycleCnt = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<i64> f = make_array<i64>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stap = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> staf = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int fa = {};
  inline static int e = {};
  inline static int stacksiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CactusAddEdge1() {}
  static void push(int u, int preEdge, int status, int fa, int e) {
    (stau[stacksiz] = u);
    (stap[stacksiz] = preEdge);
    (stas[stacksiz] = status);
    (staf[stacksiz] = fa);
    (stae[stacksiz] = e);
    (stacksiz++);
  }
  static void pop() {
    (stacksiz--);
    (u = stau[stacksiz]);
    (preEdge = stap[stacksiz]);
    (status = stas[stacksiz]);
    (fa = staf[stacksiz]);
    (e = stae[stacksiz]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (cycleEdge[cntg] = false);
    (head[u] = cntg);
  }
  static void tarjan1(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code02_CactusAddEdge1::tarjan1(v, e);
        (fromEdge[v] = e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
          (cycleCnt[u]++);
        } else if ((low[v] > dfn[u])) {
          (top--);
        } else {
          int pop = {};
          int edge = fromEdge[u];
          (cycleEdge[edge] = (cycleEdge[(edge ^ 1)] = true));
          do {
            (pop = sta[(top--)]);
            (edge = fromEdge[pop]);
            (cycleEdge[edge] = (cycleEdge[(edge ^ 1)] = true));
          } while ((pop != v));
        }
      } else if ((dfn[v] < dfn[u])) {
        (fromEdge[v] = e);
        (low[u] = jmin(low[u], dfn[v]));
        (cycleCnt[u]++);
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksiz = 0);
    Code02_CactusAddEdge1::push(node, pree, (-1), 0, (-1));
    int v = {};
    while ((stacksiz > 0)) {
      Code02_CactusAddEdge1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (fromEdge[v] = e);
          if ((low[v] < dfn[u])) {
            (low[u] = jmin(low[u], low[v]));
            (cycleCnt[u]++);
          } else if ((low[v] > dfn[u])) {
            (top--);
          } else {
            int pop = {};
            int edge = fromEdge[u];
            (cycleEdge[edge] = (cycleEdge[(edge ^ 1)] = true));
            do {
              (pop = sta[(top--)]);
              (edge = fromEdge[pop]);
              (cycleEdge[edge] = (cycleEdge[(edge ^ 1)] = true));
            } while ((pop != v));
          }
        } else {
          if ((dfn[v] < dfn[u])) {
            (fromEdge[v] = e);
            (low[u] = jmin(low[u], dfn[v]));
            (cycleCnt[u]++);
          }
        }
        (e = nxt[e]);
      }
      if (((e ^ 1) == preEdge)) {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code02_CactusAddEdge1::push(u, preEdge, 0, 0, e);
          Code02_CactusAddEdge1::push(v, e, (-1), 0, (-1));
        } else {
          Code02_CactusAddEdge1::push(u, preEdge, 1, 0, e);
        }
      }
    }
  }
  static void dpOnTree1(int u, int fa) {
    (vis[u] = true);
    i64 ans = 1;
    int direction = ((fa == 0) ? 0 : 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!cycleEdge[e]))) {
        Code02_CactusAddEdge1::dpOnTree1(v, u);
        (ans = jrem((ans * dp[v]), MOD));
        (direction++);
      }
    }
    (dp[u] = jrem((ans * f[direction]), MOD));
  }
  static void dpOnTree2(int cur, int father) {
    (stacksiz = 0);
    Code02_CactusAddEdge1::push(cur, 0, 0, father, (-1));
    while ((stacksiz > 0)) {
      Code02_CactusAddEdge1::pop();
      if ((e == (-1))) {
        (vis[u] = true);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code02_CactusAddEdge1::push(u, 0, 0, fa, e);
        int v = to[e];
        if (((v != fa) && (!cycleEdge[e]))) {
          Code02_CactusAddEdge1::push(v, 0, 0, u, (-1));
        }
      } else {
        i64 ans = 1;
        int direction = ((fa == 0) ? 0 : 1);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          if (((v != fa) && (!cycleEdge[e]))) {
            (ans = jrem((ans * dp[v]), MOD));
            (direction++);
          }
        }
        (dp[u] = jrem((ans * f[direction]), MOD));
      }
    }
  }
  static void prepare() {
    (f[0] = (f[1] = 1));
    (f[2] = 2);
    for (int i = 3; (i <= n); (i++)) {
      (f[i] = jrem((f[(i - 1)] + (f[(i - 2)] * (i - 1))), MOD));
    }
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = (dfn[i] = (low[i] = (fromEdge[i] = (cycleCnt[i] = 0)))));
      (vis[i] = false);
      (dp[i] = 0);
    }
    (cntg = 1);
    (cntd = (top = 0));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      Code02_CactusAddEdge1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code02_CactusAddEdge1::addEdge(u, v);
          Code02_CactusAddEdge1::addEdge(v, u);
        }
      }
      Code02_CactusAddEdge1::tarjan2(1, 0);
      bool check = true;
      for (int i = 1; (i <= n); (i++)) {
        if ((cycleCnt[i] >= 2)) {
          (check = false);
          break;
        }
      }
      if (check) {
        i64 ans = 1;
        for (int i = 1; (i <= n); (i++)) {
          if ((!vis[i])) {
            Code02_CactusAddEdge1::dpOnTree2(i, 0);
            (ans = jrem((ans * dp[i]), MOD));
          }
        }
        out.println(ans);
      } else {
        out.println(0);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CactusAddEdge1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌加边方案数，java版
// 给定n个点、m条边的无向连通图，输入保证没有自环、没有重边
// 可以在图中加入一些新的边，如果加入后得到的图是仙人掌，就叫有效的加边方案
// 允许一条边也不加，但不允许加边后，形成自环或二元环，计算有效的加边方案数
// 答案对 998244353 取余，每次输入可能有多组测试数据
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P3687
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // f[i] : 点周围有i个方向，一旦两个方向配对，不可再用
        // 方向也可不配对，总的配对方法数
        // dp[u] : u周围的每个支路配对或者不配对，形成的方案数
        // 两个支路配对是指，各自选出一个端点然后连边
        // 如果u是根，认为上方没有支路
        // 如果u不是根，认为上方有支路，内有一个点
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
        // 递归版
        // 迭代版
                        // tarjan1(1, 0);
                                                // dpOnTree1(i, 0);
        // 读写工具类
*/
