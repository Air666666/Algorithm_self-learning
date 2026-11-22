// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4149

// Source: src/class183/Code03_Race1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Race1 {
  inline static int MAXN = 200001;
  inline static int MAXK = 1000001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> curDis = make_array<int>(MAXN);
  inline static Array<int> curEdge = make_array<int>(MAXN);
  inline static int cntc = {};
  inline static Array<int> allDis = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> dp = make_array<int>(MAXK);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int dis = {};
  inline static int edge = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Race1() {}
  static void push(int u, int f, int dis, int edge, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = dis);
    (stack[stacksize][3] = edge);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (dis = stack[stacksize][2]);
    (edge = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code03_Race1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code03_Race1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code03_Race1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Race1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code03_Race1::push(v, u, 0, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code03_Race1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
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
  static void dfs1(int u, int fa, int dis, int edge) {
    if ((dis > k)) {
      return;
    }
    (curDis[(++cntc)] = dis);
    (curEdge[cntc] = edge);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code03_Race1::dfs1(v, u, (dis + weight[e]), (edge + 1));
      }
    }
  }
  static void dfs2(int cur, int fa, int pathDis, int pathEdge) {
    (stacksize = 0);
    Code03_Race1::push(cur, fa, pathDis, pathEdge, (-1));
    while ((stacksize > 0)) {
      Code03_Race1::pop();
      if ((e == (-1))) {
        if ((dis > k)) {
          continue;
        }
        (curDis[(++cntc)] = dis);
        (curEdge[cntc] = edge);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Race1::push(u, f, dis, edge, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code03_Race1::push(to[e], u, (dis + weight[e]), (edge + 1), (-1));
        }
      }
    }
  }
  static int calc(int u) {
    int ans = INF;
    (cnta = 0);
    (dp[0] = 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (cntc = 0);
        Code03_Race1::dfs2(v, u, weight[e], 1);
        for (int i = 1; (i <= cntc); (i++)) {
          (ans = jmin(ans, (dp[(k - curDis[i])] + curEdge[i])));
        }
        for (int i = 1; (i <= cntc); (i++)) {
          (allDis[(++cnta)] = curDis[i]);
          (dp[curDis[i]] = jmin(dp[curDis[i]], curEdge[i]));
        }
      }
    }
    for (int i = 1; (i <= cnta); (i++)) {
      (dp[allDis[i]] = INF);
    }
    return ans;
  }
  static int solve(int u) {
    (vis[u] = true);
    int ans = Code03_Race1::calc(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans = jmin(ans, Code03_Race1::solve(Code03_Race1::getCentroid(v, u))));
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
      int w = {};
      for (; (i < n); (i++)) {
        (u = (in.nextInt() + 1));
        (v = (in.nextInt() + 1));
        (w = in.nextInt());
        Code03_Race1::addEdge(u, v, w);
        Code03_Race1::addEdge(v, u, w);
      }
    }
    j::fill(dp, INF);
    int ans = Code03_Race1::solve(Code03_Race1::getCentroid(1, 0));
    if ((ans == INF)) {
      (ans = (-1));
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Race1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 路径权值和为k的最少边数，java版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 给定数字k，要求找到路径权值和等于k的简单路径，并且边的数量最小
// 打印这个最小的边数，如果不存在路径权值和等于k的简单路径，那么打印-1
// 注意，本题给定的点的编号从0开始
// 1 <= n <= 2 * 10^5
// 0 <= 边权、k <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4149
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 从u出发到当前子树的节点，收集(路径权值和, 路径边数)
        // 从u出发到之前子树的节点，收集路径权值和
        //
dp[s]表示，从u出发到之前子树的节点，路径权值和为s的路径，最少边数是多少
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                                // dfs1(v, u, weight[e], 1);
        // 读写工具类
*/
