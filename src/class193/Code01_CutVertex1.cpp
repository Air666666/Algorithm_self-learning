// Source: src/class193/Code01_CutVertex1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CutVertex1 {
  inline static int MAXN = 20001;
  inline static int MAXM = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<bool> cutVertex = make_array<bool>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int root = {};
  inline static int son = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CutVertex1() {}
  static void push(int u, int root, int son, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = root);
    (stack[stacksize][2] = son);
    (stack[stacksize][3] = status);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (root = stack[stacksize][1]);
    (son = stack[stacksize][2]);
    (status = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u, bool root) {
    (dfn[u] = (low[u] = (++cntd)));
    int son = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (son++);
        Code01_CutVertex1::tarjan1(v, false);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] >= dfn[u])) {
          if (((!root) || (son >= 2))) {
            (cutVertex[u] = true);
          }
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node, bool rt) {
    (stacksize = 0);
    Code01_CutVertex1::push(node, (rt ? 1 : 0), 0, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code01_CutVertex1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            if (((root == 0) || (son >= 2))) {
              (cutVertex[u] = true);
            }
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          (son++);
          Code01_CutVertex1::push(u, root, son, 0, e);
          Code01_CutVertex1::push(v, 0, 0, (-1), (-1));
        } else {
          Code01_CutVertex1::push(u, root, son, 1, e);
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
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code01_CutVertex1::addEdge(u, v);
        Code01_CutVertex1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code01_CutVertex1::tarjan2(i, true);
      }
    }
    int cntCnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      if (cutVertex[i]) {
        (cntCnt++);
      }
    }
    out.println(cntCnt);
    for (int i = 1; (i <= n); (i++)) {
      if (cutVertex[i]) {
        out.print((i + String(u" ")));
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
  Code01_CutVertex1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 割点模版题，java版
// 给定一张无向图，一共n个点、m条边，不保证所有点连通
// 打印图中割点的数量，然后从小到大打印所有割点的编号
// 1 <= n <= 2 * 10^4
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3388
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版，Tarjan算法求解割点
        // 迭代版，Tarjan算法求解割点
                                // tarjan1(i, true);
        // 读写工具类
*/
