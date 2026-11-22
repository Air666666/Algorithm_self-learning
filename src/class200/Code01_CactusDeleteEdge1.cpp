// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4129

// Source: src/class200/Code01_CactusDeleteEdge1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CactusDeleteEdge1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> edgeCnt = make_array<int>(MAXN);
  inline static int cntc = {};
  inline static Array<int> cycleCnt = make_array<int>(MAXN);
  inline static BigInteger ans = {};
  inline static Array<int> stau = make_array<int>(MAXN);
  inline static Array<int> stap = make_array<int>(MAXN);
  inline static Array<int> stas = make_array<int>(MAXN);
  inline static Array<int> stae = make_array<int>(MAXN);
  inline static int u = {};
  inline static int preEdge = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksiz = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CactusDeleteEdge1() {}
  static void push(int u, int preEdge, int status, int e) {
    (stau[stacksiz] = u);
    (stap[stacksiz] = preEdge);
    (stas[stacksiz] = status);
    (stae[stacksiz] = e);
    (stacksiz++);
  }
  static void pop() {
    (stacksiz--);
    (u = stau[stacksiz]);
    (preEdge = stap[stacksiz]);
    (status = stas[stacksiz]);
    (e = stae[stacksiz]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
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
        Code01_CactusDeleteEdge1::tarjan1(v, e);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
          (cycleCnt[u]++);
        } else if ((low[v] > dfn[u])) {
          (top--);
        } else {
          (cntc++);
          (edgeCnt[cntc] = 1);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (edgeCnt[cntc]++);
          } while ((pop != v));
        }
      } else if ((dfn[v] < dfn[u])) {
        (low[u] = jmin(low[u], dfn[v]));
        (cycleCnt[u]++);
      }
    }
  }
  static void tarjan2(int node, int pree) {
    (stacksiz = 0);
    Code01_CactusDeleteEdge1::push(node, pree, (-1), (-1));
    int v = {};
    while ((stacksiz > 0)) {
      Code01_CactusDeleteEdge1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          if ((low[v] < dfn[u])) {
            (low[u] = jmin(low[u], low[v]));
            (cycleCnt[u]++);
          } else if ((low[v] > dfn[u])) {
            (top--);
          } else {
            (cntc++);
            (edgeCnt[cntc] = 1);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              (edgeCnt[cntc]++);
            } while ((pop != v));
          }
        } else {
          if ((dfn[v] < dfn[u])) {
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
          Code01_CactusDeleteEdge1::push(u, preEdge, 0, e);
          Code01_CactusDeleteEdge1::push(v, e, (-1), (-1));
        } else {
          Code01_CactusDeleteEdge1::push(u, preEdge, 1, e);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (cntg = 1);
    {
      int i = 1;
      int k = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (k = in.nextInt());
        (x = in.nextInt());
        for (int j = 2; (j <= k); (j++)) {
          (y = in.nextInt());
          Code01_CactusDeleteEdge1::addEdge(x, y);
          Code01_CactusDeleteEdge1::addEdge(y, x);
          (x = y);
        }
      }
    }
    Code01_CactusDeleteEdge1::tarjan2(1, 0);
    bool check = true;
    for (int i = 1; (i <= n); (i++)) {
      if (((dfn[i] == 0) || (cycleCnt[i] >= 2))) {
        (check = false);
        break;
      }
    }
    if (check) {
      (ans = BigInteger::ONE);
      for (int i = 1; (i <= cntc); (i++)) {
        (ans = ans.multiply(BigInteger::valueOf((edgeCnt[i] + 1))));
      }
      out.println(ans);
    } else {
      out.println(0);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CactusDeleteEdge1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 仙人掌删边方案数，java版
// 给定n个点、m条路径表示无向图，每条路径的相邻两点之间都有边
// 如果图不是仙人掌打印0，如果图是仙人掌，可以在图中删除一些边
// 如果删除后剩下的图仍然连通，就叫有效的删边方案
// 允许一条边也不删，打印有效删边的方案数，答案可能很大，需要高精度
// 1 <= n <= 2 * 10^4
// 1 <= 边总数 <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4129
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 统计每个环的边数
        // 不作为环顶节点的情况下，参与了几个环
        // 本题需要高精度乘法
        // 递归改迭代需要的栈
        // 递归版
        // 迭代版
                // tarjan1(1, 0);
        // 读写工具类
*/
