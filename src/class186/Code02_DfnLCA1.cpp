// Source: src/class186/Code02_DfnLCA1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DfnLCA1 {
  inline static int MAXN = 500001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int root = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> lg2 = make_array<int>(MAXN);
  inline static Array<Array<int>> rmq = make_array<int>(MAXN, MAXP);
  inline static int cntDfn = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DfnLCA1() {}
  static void push(int u, int f, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static int getUp(int x, int y) { return ((dfn[x] < dfn[y]) ? x : y); }
  static void dfs1(int u, int fa) {
    (dfn[u] = (++cntDfn));
    (rmq[dfn[u]][0] = fa);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if ((v != fa)) {
        Code02_DfnLCA1::dfs1(v, u);
      }
    }
  }
  static void dfs2(int cur, int fa) {
    (stacksize = 0);
    Code02_DfnLCA1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code02_DfnLCA1::pop();
      if ((e == (-1))) {
        (dfn[u] = (++cntDfn));
        (rmq[dfn[u]][0] = f);
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code02_DfnLCA1::push(u, f, e);
        int v = tog[e];
        if ((v != f)) {
          Code02_DfnLCA1::push(v, u, (-1));
        }
      }
    }
  }
  static void buildRmq() {
    Code02_DfnLCA1::dfs2(root, 0);
    for (int i = 2; (i <= n); (i++)) {
      (lg2[i] = (lg2[jshr(i, 1)] + 1));
    }
    {
      int pre = 0;
      int cur = 1;
      for (; (cur <= lg2[n]); (pre++), (cur++)) {
        for (int i = 1; (((i + jshl(1, cur)) - 1) <= n); (i++)) {
          (rmq[i][cur] = Code02_DfnLCA1::getUp(rmq[i][pre],
                                               rmq[(i + jshl(1, pre))][pre]));
        }
      }
    }
  }
  static int getLCA(int x, int y) {
    if ((x == y)) {
      return x;
    }
    (x = dfn[x]);
    (y = dfn[y]);
    if ((x > y)) {
      int tmp = x;
      (x = y);
      (y = tmp);
    }
    (x++);
    int k = lg2[((y - x) + 1)];
    return Code02_DfnLCA1::getUp(rmq[x][k], rmq[((y - jshl(1, k)) + 1)][k]);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (root = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code02_DfnLCA1::addEdge(u, v);
        Code02_DfnLCA1::addEdge(v, u);
      }
    }
    Code02_DfnLCA1::buildRmq();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        out.println(Code02_DfnLCA1::getLCA(u, v));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_DfnLCA1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// dfn序求LCA，java版
// 一共有n个节点，给定n-1条边，所有节点组成一棵树，给定树头root
// 一共有m条查询，格式 u v : 打印u和v的最低公共祖先
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3379
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // dfn序递归版，java会爆栈，C++可以通过
        // dfs1迭代版
                // dfs1(root, 0);
        // 读写工具类
*/
