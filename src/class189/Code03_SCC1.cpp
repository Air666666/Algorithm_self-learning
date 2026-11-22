// Source: src/class189/Code03_SCC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SCC1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> sccSiz = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SCC1() {}
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
        Code03_SCC1::tarjan1(v);
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
        (sccSiz[sccCnt]++);
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code03_SCC1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code03_SCC1::pop();
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
          Code03_SCC1::push(u, 0, e);
          Code03_SCC1::push(v, (-1), (-1));
        } else {
          Code03_SCC1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (sccSiz[sccCnt]++);
          } while ((pop != u));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int a = {};
      int b = {};
      int t = {};
      for (; (i <= m); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (t = in.nextInt());
        if ((t == 1)) {
          Code03_SCC1::addEdge(a, b);
        } else {
          Code03_SCC1::addEdge(a, b);
          Code03_SCC1::addEdge(b, a);
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code03_SCC1::tarjan2(i);
      }
    }
    int largest = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      (largest = jmax(largest, sccSiz[i]));
    }
    out.println(largest);
    for (int i = 1; (i <= n); (i++)) {
      if ((sccSiz[belong[i]] == largest)) {
        int scc = belong[i];
        for (int j = i; (j <= n); (j++)) {
          if ((belong[j] == scc)) {
            out.print((j + String(u" ")));
          }
        }
        break;
      }
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SCC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 强连通分量模版题3，java版
// 一共有n个节点，给定m条边，边的格式 a b t
// 如果t为1，表示a到b的单向边，如果t为2，表示a到b的双向边
// 找到图中最大的强连通分量，先打印大小，然后打印包含的节点，编号从小到大输出
// 如果有多个最大的强连通分量，打印字典序最小的结果
// 1 <= n <= 5 * 10^3
// 0 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P1726
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                                // tarjan1(i);
        // 读写工具类
*/
