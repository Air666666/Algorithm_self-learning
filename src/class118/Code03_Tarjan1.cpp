// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3379

// Source: src/class118/Code03_Tarjan1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Tarjan1 {
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Tarjan1() {}
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
    if ((i != father[i])) {
      (father[i] = Code03_Tarjan1::find(father[i]));
    }
    return father[i];
  }
  static void tarjan(int u, int f) {
    (visited[u] = true);
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code03_Tarjan1::tarjan(v, u);
          (father[v] = u);
        }
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (ans[queryIndex[e]] = Code03_Tarjan1::find(v));
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
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int root = static_cast<int>(in.nval);
    Code03_Tarjan1::build(n);
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code03_Tarjan1::addEdge(u, v);
        Code03_Tarjan1::addEdge(v, u);
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
        Code03_Tarjan1::addQuery(u, v, i);
        Code03_Tarjan1::addQuery(v, u, i);
      }
    }
    Code03_Tarjan1::tarjan(root, 0);
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
  Code03_Tarjan1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// tarjan算法解法
// 测试链接 : https://www.luogu.com.cn/problem/P3379
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code03_Tarjan2文件
        // 链式前向星建图
        // 每个节点有哪些查询，也用链式前向星方式存储
        // 问题的编号，一旦有答案可以知道填写在哪
        // 某个节点是否访问过
        // 并查集
        // 收集的答案
        // 并查集找头节点递归版
        // 一般来说都这么写，但是本题附加的测试数据很毒
        // java这么写就会因为递归太深而爆栈，C++这么写就能通过
        // tarjan算法递归版
        // 一般来说都这么写，但是本题附加的测试数据很毒
        // java这么写就会因为递归太深而爆栈，C++这么写就能通过
*/
