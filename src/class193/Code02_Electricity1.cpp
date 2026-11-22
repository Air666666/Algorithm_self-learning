// 原题测试 / 参考链接（保留上游原始地址）
// https://loj.ac/p/10103
// http://poj.org/problem?id=2117

// Source: src/class193/Code02_Electricity1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Electricity1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 20001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static int block = {};
  inline static int ans = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 6);
  inline static int u = {};
  inline static int root = {};
  inline static int son = {};
  inline static int cut = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Electricity1() {}
  static void push(int u, int root, int son, int cut, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = root);
    (stack[stacksize][2] = son);
    (stack[stacksize][3] = cut);
    (stack[stacksize][4] = status);
    (stack[stacksize][5] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (root = stack[stacksize][1]);
    (son = stack[stacksize][2]);
    (cut = stack[stacksize][3]);
    (status = stack[stacksize][4]);
    (e = stack[stacksize][5]);
  }
  static void prepare() {
    (cntg = (cntd = (block = (ans = 0))));
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = (dfn[i] = (low[i] = 0)));
    }
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan1(int u, bool root) {
    (dfn[u] = (low[u] = (++cntd)));
    int son = 0;
    int cut = 0;
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        (son++);
        Code02_Electricity1::tarjan1(v, false);
        (low[u] = jmin(low[u], low[v]));
        if (((low[v] >= dfn[u]) && (!root))) {
          (cut++);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    if (root) {
      (ans = jmax(ans, son));
    } else {
      (ans = jmax(ans, (cut + 1)));
    }
  }
  static void tarjan2(int node, bool rt) {
    (stacksize = 0);
    Code02_Electricity1::push(node, (rt ? 1 : 0), 0, 0, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code02_Electricity1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if (((low[v] >= dfn[u]) && (root == 0))) {
            (cut++);
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
          Code02_Electricity1::push(u, root, son, cut, 0, e);
          Code02_Electricity1::push(v, 0, 0, 0, (-1), (-1));
        } else {
          Code02_Electricity1::push(u, root, son, cut, 1, e);
        }
      } else {
        if ((root == 1)) {
          (ans = jmax(ans, son));
        } else {
          (ans = jmax(ans, (cut + 1)));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    while (((n != 0) || (m != 0))) {
      Code02_Electricity1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i <= m); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          (u++);
          (v++);
          Code02_Electricity1::addEdge(u, v);
          Code02_Electricity1::addEdge(v, u);
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        if ((dfn[i] == 0)) {
          (block++);
          Code02_Electricity1::tarjan2(i, true);
        }
      }
      out.println((block + (ans - 1)));
      (n = in.nextInt());
      (m = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Electricity1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 电力，java版
// 给定一张无向图，一共n个点、m条边，不保证所有点连通
// 点的编号0 ~ n-1，只能删除一个点的话，连通块最多有多少
// 1 <= n <= 10^4
// 1 <= m <= 2 * 10^4
// 测试链接 : https://loj.ac/p/10103
// 测试链接 : http://poj.org/problem?id=2117
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                        // tarjan1(i, true);
        // 读写工具类
*/
