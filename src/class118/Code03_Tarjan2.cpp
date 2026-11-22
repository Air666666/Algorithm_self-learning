// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3379

// Source: src/class118/Code03_Tarjan2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Tarjan2 {
  inline static int MAXN = 500001;
  inline static Array<int> headEdge = make_array<int>(MAXN);
  inline static Array<int> edgeNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> edgeTo = make_array<int>(jshl(MAXN, 1));
  inline static int tcnt = {};
  inline static Array<int> headQuery = make_array<int>(MAXN);
  inline static Array<int> queryNext = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> queryTo = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> queryIndex = make_array<int>(jshl(MAXN, 1));
  inline static int qcnt = {};
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Tarjan2() {}
  static void build(int n) {
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 1, (n + 1), 0);
    j::fill(headQuery, 1, (n + 1), 0);
    j::fill(visited, 1, (n + 1), false);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
  }
  static void addEdge(int u, int v) {
    (edgeNext[tcnt] = headEdge[u]);
    (edgeTo[tcnt] = v);
    (headEdge[u] = (tcnt++));
  }
  static void addQuery(int u, int v, int i) {
    (queryNext[qcnt] = headQuery[u]);
    (queryTo[qcnt] = v);
    (queryIndex[qcnt] = i);
    (headQuery[u] = (qcnt++));
  }
  static int find(int i) {
    int size = 0;
    while ((i != father[i])) {
      (stack[(size++)] = i);
      (i = father[i]);
    }
    while ((size > 0)) {
      (father[stack[(--size)]] = i);
    }
    return i;
  }
  static void push(int u, int f, int e) {
    (ufe[stackSize][0] = u);
    (ufe[stackSize][1] = f);
    (ufe[stackSize][2] = e);
    (stackSize++);
  }
  static void pop() {
    (--stackSize);
    (u = ufe[stackSize][0]);
    (f = ufe[stackSize][1]);
    (e = ufe[stackSize][2]);
  }
  static void tarjan(int u, int f) {
    (visited[u] = true);
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code03_Tarjan2::tarjan(v, u);
        }
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (ans[queryIndex[e]] = Code03_Tarjan2::find(v));
        }
      }
    }
    (father[u] = f);
  }
  static void tarjan(int root) {
    (stackSize = 0);
    Code03_Tarjan2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code03_Tarjan2::pop();
      if ((e == (-1))) {
        (visited[u] = true);
        (e = headEdge[u]);
      } else {
        (e = edgeNext[e]);
      }
      if ((e != 0)) {
        Code03_Tarjan2::push(u, f, e);
        if ((edgeTo[e] != f)) {
          Code03_Tarjan2::push(edgeTo[e], u, (-1));
        }
      } else {
        {
          int q = headQuery[u];
          int v = {};
          for (; (q != 0); (q = queryNext[q])) {
            (v = queryTo[q]);
            if (visited[v]) {
              (ans[queryIndex[q]] = Code03_Tarjan2::find(v));
            }
          }
        }
        (father[u] = f);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int root = static_cast<int>(in.nval);
    Code03_Tarjan2::build(n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code03_Tarjan2::addEdge(u, v);
        Code03_Tarjan2::addEdge(v, u);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code03_Tarjan2::addQuery(u, v, i);
        Code03_Tarjan2::addQuery(v, u, i);
      }
    }
    Code03_Tarjan2::tarjan(root);
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Tarjan2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// tarjan算法解法迭代版
// 测试链接 : https://www.luogu.com.cn/problem/P3379
// 所有递归函数一律改成等义的迭代版
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 为了实现迭代版而准备的栈
        // 并查集找头节点迭代版
        // 为了实现迭代版而准备的栈
        // 为了容易改成迭代版，修改一下递归版
                                // 注意这里，注释了一行
//				father[v] = u;
                // 注意这里，增加了一行
        // tarjan算法迭代版，根据上面的递归版改写
                // 栈里存放三个信息
                // u : 当前处理的点
                // f : 当前点u的父节点
                // e : 处理到几号边了
                // 如果e==-1，表示之前没有处理过u的任何边
                // 如果e==0，表示u的边都已经处理完了
                                // e == 0代表u后续已经没有边需要处理了
*/
