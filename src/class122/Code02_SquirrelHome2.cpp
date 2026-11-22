// Source: src/class122/Code02_SquirrelHome2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SquirrelHome2 {
  inline static int MAXN = 300001;
  inline static Array<int> travel = make_array<int>(MAXN);
  inline static Array<int> num = make_array<int>(MAXN);
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
  inline static Array<int> unionfind = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stackSize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SquirrelHome2() {}
  static void build(int n) {
    j::fill(num, 1, (n + 1), 0);
    (tcnt = (qcnt = 1));
    j::fill(headEdge, 1, (n + 1), 0);
    j::fill(headQuery, 1, (n + 1), 0);
    j::fill(visited, 1, (n + 1), false);
    for (int i = 1; (i <= n); (i++)) {
      (unionfind[i] = i);
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
    while ((i != unionfind[i])) {
      (stack[(size++)] = i);
      (i = unionfind[i]);
    }
    while ((size > 0)) {
      (unionfind[stack[(--size)]] = i);
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
  static void tarjan(int root) {
    (stackSize = 0);
    Code02_SquirrelHome2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code02_SquirrelHome2::pop();
      if ((e == (-1))) {
        (visited[u] = true);
        (e = headEdge[u]);
      } else {
        (e = edgeNext[e]);
      }
      if ((e != 0)) {
        Code02_SquirrelHome2::push(u, f, e);
        if ((edgeTo[e] != f)) {
          Code02_SquirrelHome2::push(edgeTo[e], u, (-1));
        }
      } else {
        {
          int q = headQuery[u];
          int v = {};
          for (; (q != 0); (q = queryNext[q])) {
            (v = queryTo[q]);
            if (visited[v]) {
              (ans[queryIndex[q]] = Code02_SquirrelHome2::find(v));
            }
          }
        }
        (unionfind[u] = f);
        (father[u] = f);
      }
    }
  }
  static void dfs(int root) {
    (stackSize = 0);
    Code02_SquirrelHome2::push(root, 0, (-1));
    while ((stackSize > 0)) {
      Code02_SquirrelHome2::pop();
      if ((e == (-1))) {
        (e = headEdge[u]);
      } else {
        (e = edgeNext[e]);
      }
      if ((e != 0)) {
        Code02_SquirrelHome2::push(u, f, e);
        if ((edgeTo[e] != f)) {
          Code02_SquirrelHome2::push(edgeTo[e], u, (-1));
        }
      } else {
        {
          int e = headEdge[u];
          int v = {};
          for (; (e != 0); (e = edgeNext[e])) {
            (v = edgeTo[e]);
            if ((v != f)) {
              (num[u] += num[v]);
            }
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    Code02_SquirrelHome2::build(n);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (travel[i] = static_cast<int>(in.nval));
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code02_SquirrelHome2::addEdge(u, v);
        Code02_SquirrelHome2::addEdge(v, u);
      }
    }
    for (int i = 1; (i < n); (i++)) {
      Code02_SquirrelHome2::addQuery(travel[i], travel[(i + 1)], i);
      Code02_SquirrelHome2::addQuery(travel[(i + 1)], travel[i], i);
    }
    Code02_SquirrelHome2::compute(n);
    for (int i = 1; (i <= n); (i++)) {
      out.println(num[i]);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void compute(int n) {
    Code02_SquirrelHome2::tarjan(1);
    {
      int i = 1;
      int u = {};
      int v = {};
      int lca = {};
      int lcafather = {};
      for (; (i < n); (i++)) {
        (u = travel[i]);
        (v = travel[(i + 1)]);
        (lca = ans[i]);
        (lcafather = father[lca]);
        (num[u]++);
        (num[v]++);
        (num[lca]--);
        (num[lcafather]--);
      }
    }
    Code02_SquirrelHome2::dfs(1);
    for (int i = 2; (i <= n); (i++)) {
      (num[travel[i]]--);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SquirrelHome2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 松鼠的新家(迭代版)
// 有n个节点形成一棵树
// 给定一个由点编号组成的数组，表示松鼠依次要去往的地点
// 松鼠每走到一个节点都必须拿一个糖果，否则松鼠就停止前进
// 松鼠来到最后一个地点时不需要吃糖果
// 打印每个节点上至少准备多少糖果才能让松鼠依次走完数组里的节点
// 测试链接 : https://www.luogu.com.cn/problem/P3258
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // find方法的递归版改迭代版
        // tarjan方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
        // dfs方法的递归版改迭代版
        // 不会改，看讲解118，讲了怎么从递归版改成迭代版
*/
