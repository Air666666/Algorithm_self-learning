// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P7215

// Source: src/class184/Code01_Capital1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Capital1 {
  inline static int MAXN = 200001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> color = make_array<int>(MAXN);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headc = make_array<int>(MAXN);
  inline static Array<int> nextc = make_array<int>(MAXN);
  inline static Array<int> toc = make_array<int>(MAXN);
  inline static int cntc = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> nodeRoot = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  inline static Array<bool> nodeVis = make_array<bool>(MAXN);
  inline static Array<bool> colorVis = make_array<bool>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int f = {};
  inline static int rt = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Capital1() {}
  static void push(int u, int f, int rt, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = rt);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (rt = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addNode(int color, int node) {
    (nextc[(++cntc)] = headc[color]);
    (toc[cntc] = node);
    (headc[color] = cntc);
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        Code01_Capital1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code01_Capital1::push(cur, fa, 0, (-1));
    while ((stacksize > 0)) {
      Code01_Capital1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code01_Capital1::push(u, f, 0, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          Code01_Capital1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = headg[u]; (ei > 0); (ei = nextg[ei])) {
          int v = tog[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code01_Capital1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = headg[u]; (e > 0); (e = nextg[e])) {
        int v = tog[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void dfs1(int u, int fa, int rt) {
    (father[u] = fa);
    (nodeRoot[u] = rt);
    (nodeVis[u] = false);
    (colorVis[color[u]] = false);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        Code01_Capital1::dfs1(v, u, rt);
      }
    }
  }
  static void dfs2(int cur, int fa, int root) {
    (stacksize = 0);
    Code01_Capital1::push(cur, fa, root, (-1));
    while ((stacksize > 0)) {
      Code01_Capital1::pop();
      if ((e == (-1))) {
        (father[u] = f);
        (nodeRoot[u] = rt);
        (nodeVis[u] = false);
        (colorVis[color[u]] = false);
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code01_Capital1::push(u, f, rt, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          Code01_Capital1::push(v, u, rt, (-1));
        }
      }
    }
  }
  static int calc(int u) {
    Code01_Capital1::dfs2(u, 0, u);
    int l = 1;
    int r = 0;
    (que[(++r)] = u);
    (nodeVis[u] = true);
    int ans = 0;
    while ((l <= r)) {
      int cur = que[(l++)];
      if (((cur != u) && (!nodeVis[father[cur]]))) {
        (que[(++r)] = father[cur]);
        (nodeVis[father[cur]] = true);
      }
      if ((!colorVis[color[cur]])) {
        (colorVis[color[cur]] = true);
        (ans++);
        for (int e = headc[color[cur]]; (e > 0); (e = nextc[e])) {
          int v = toc[e];
          if ((nodeRoot[v] != u)) {
            return INF;
          }
          if ((!nodeVis[v])) {
            (que[(++r)] = v);
            (nodeVis[v] = true);
          }
        }
      }
    }
    return ans;
  }
  static int solve(int u) {
    (vis[u] = true);
    int ans = Code01_Capital1::calc(u);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if ((!vis[v])) {
        (ans = jmin(
             ans, Code01_Capital1::solve(Code01_Capital1::getCentroid(v, u))));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code01_Capital1::addEdge(u, v);
        Code01_Capital1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (color[i] = in.nextInt());
      Code01_Capital1::addNode(color[i], i);
    }
    int ans = Code01_Capital1::solve(Code01_Capital1::getCentroid(1, 0));
    out.println((ans - 1));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Capital1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 首都，java版
// 一共有n个节点，给定n-1条边，所有节点组成一棵树
// 给定长度为n的数组color，color[i]表示i号节点的颜色，颜色有k种
// 你需要在树上找到一个连通区，连通区内出现的每种颜色，在连通区外不存在
// 这样的连通区可能有多个，希望包含的颜色数量尽量少，打印(最少颜色数 - 1)的结果
// 1 <= n、k <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P7215
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 建树的链式前向星
        // 颜色拥有的节点列表
        // 点分治
        // father[x] = y，表示x此时的父亲节点是y
        // nodeRoot[x] = y，表示x此时的重心是y
        // 宽度优先遍历的队列
        // 节点是否进过队列
        // 颜色是否讨论过
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                // dfs1(u, 0, u);
        // 读写工具类
*/
