// Source: src/class122/Code02_SquirrelHome1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SquirrelHome1 {
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SquirrelHome1() {}
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
    if ((i != unionfind[i])) {
      (unionfind[i] = Code02_SquirrelHome1::find(unionfind[i]));
    }
    return unionfind[i];
  }
  static void tarjan(int u, int f) {
    (visited[u] = true);
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code02_SquirrelHome1::tarjan(v, u);
        }
      }
    }
    {
      int e = headQuery[u];
      int v = {};
      for (; (e != 0); (e = queryNext[e])) {
        (v = queryTo[e]);
        if (visited[v]) {
          (ans[queryIndex[e]] = Code02_SquirrelHome1::find(v));
        }
      }
    }
    (unionfind[u] = f);
    (father[u] = f);
  }
  static void dfs(int u, int f) {
    {
      int e = headEdge[u];
      int v = {};
      for (; (e != 0); (e = edgeNext[e])) {
        (v = edgeTo[e]);
        if ((v != f)) {
          Code02_SquirrelHome1::dfs(v, u);
        }
      }
    }
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
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    Code02_SquirrelHome1::build(n);
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
        Code02_SquirrelHome1::addEdge(u, v);
        Code02_SquirrelHome1::addEdge(v, u);
      }
    }
    for (int i = 1; (i < n); (i++)) {
      Code02_SquirrelHome1::addQuery(travel[i], travel[(i + 1)], i);
      Code02_SquirrelHome1::addQuery(travel[(i + 1)], travel[i], i);
    }
    Code02_SquirrelHome1::compute(n);
    for (int i = 1; (i <= n); (i++)) {
      out.println(num[i]);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void compute(int n) {
    Code02_SquirrelHome1::tarjan(1, 0);
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
    Code02_SquirrelHome1::dfs(1, 0);
    for (int i = 2; (i <= n); (i++)) {
      (num[travel[i]]--);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SquirrelHome1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 松鼠的新家(递归版)
// 有n个节点形成一棵树
// 给定一个由点编号组成的数组，表示松鼠依次要去往的地点
// 松鼠每走到一个节点都必须拿一个糖果，否则松鼠就停止前进
// 松鼠来到最后一个地点时不需要吃糖果
// 打印每个节点上至少准备多少糖果才能让松鼠依次走完数组里的节点
// 测试链接 : https://www.luogu.com.cn/problem/P3258
// 提交以下的code，提交时请把类名改成"Main"
// C++这么写能通过，java会因为递归层数太多而爆栈
// java能通过的写法参考本节课Code02_SquirrelHome2文件
        // 依次去往节点的顺序
        // 每个节点需要分配多少糖果
        // 链式前向星建图
        // 以下结构都是tarjan算法所需要的
        // unionfind数组是tarjan算法专用的并查集结构
        // father数组不用作并查集，就是记录每个节点的父亲节点
        // ans数组是tarjan算法的输出结果，记录每次旅行两端点的最低公共祖先
*/
