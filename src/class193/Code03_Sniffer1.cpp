// Source: src/class193/Code03_Sniffer1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Sniffer1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 500001;
  inline static int n = {};
  inline static int a = {};
  inline static int b = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<bool> isKey = make_array<bool>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Sniffer1() {}
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
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code03_Sniffer1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
        if (((((low[v] >= dfn[u]) && (u != a)) && (u != b)) &&
             (dfn[b] >= dfn[v]))) {
          (isKey[u] = true);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code03_Sniffer1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code03_Sniffer1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
          if (((((low[v] >= dfn[u]) && (u != a)) && (u != b)) &&
               (dfn[b] >= dfn[v]))) {
            (isKey[u] = true);
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code03_Sniffer1::push(u, 0, e);
          Code03_Sniffer1::push(v, (-1), (-1));
        } else {
          Code03_Sniffer1::push(u, 1, e);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    int u = in.nextInt();
    int v = in.nextInt();
    while (((u != 0) || (v != 0))) {
      Code03_Sniffer1::addEdge(u, v);
      Code03_Sniffer1::addEdge(v, u);
      (u = in.nextInt());
      (v = in.nextInt());
    }
    (a = in.nextInt());
    (b = in.nextInt());
    Code03_Sniffer1::tarjan2(a);
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if (isKey[i]) {
        (ans = i);
        break;
      }
    }
    if ((ans == 0)) {
      out.println(String(u"No solution"));
    } else {
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Sniffer1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 嗅探器，java版
// 给定一张n个点、m条边的无向图，所有节点属于一个连通区
// 给定点a和点b，如果删掉别的点能让a和b不再连通，这个点叫关键点
// 打印编号最小的关键点，不存在打印"No solution"
// 1 <= n <= 2 * 10^5
// 1 <= m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5058
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                // tarjan1(a);
        // 读写工具类
*/
