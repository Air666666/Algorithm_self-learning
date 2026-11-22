// Source: src/class183/Code07_Message1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Message1 {
  inline static int MAXN = 100001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> tog = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> headq = make_array<int>(MAXN);
  inline static Array<int> nextq = make_array<int>(MAXN);
  inline static Array<int> dis = make_array<int>(MAXN);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static int cntq = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> nodeCnt = make_array<int>(MAXN);
  inline static int maxEdge = {};
  inline static Array<int> needArr = make_array<int>(MAXN);
  inline static Array<int> qidArr = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int f = {};
  inline static int edge = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Message1() {}
  static void push(int u, int f, int edge, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = edge);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (edge = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addQuery(int u, int k, int id) {
    (nextq[(++cntq)] = headq[u]);
    (dis[cntq] = k);
    (qid[cntq] = id);
    (headq[u] = cntq);
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        Code07_Message1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code07_Message1::push(cur, fa, 0, (-1));
    while ((stacksize > 0)) {
      Code07_Message1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code07_Message1::push(u, f, 0, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          Code07_Message1::push(v, u, 0, (-1));
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
    Code07_Message1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int edge) {
    (nodeCnt[edge]++);
    (maxEdge = jmax(maxEdge, edge));
    for (int e = headq[u]; (e > 0); (e = nextq[e])) {
      if ((dis[e] >= edge)) {
        (needArr[(++cnta)] = (dis[e] - edge));
        (qidArr[cnta] = qid[e]);
      }
    }
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if (((v != fa) && (!vis[v]))) {
        Code07_Message1::dfs1(v, u, (edge + 1));
      }
    }
  }
  static void dfs2(int cur, int fa, int edg) {
    (stacksize = 0);
    Code07_Message1::push(cur, fa, edg, (-1));
    while ((stacksize > 0)) {
      Code07_Message1::pop();
      if ((e == (-1))) {
        (nodeCnt[edge]++);
        (maxEdge = jmax(maxEdge, edge));
        for (int e = headq[u]; (e > 0); (e = nextq[e])) {
          if ((dis[e] >= edge)) {
            (needArr[(++cnta)] = (dis[e] - edge));
            (qidArr[cnta] = qid[e]);
          }
        }
        (e = headg[u]);
      } else {
        (e = nextg[e]);
      }
      if ((e != 0)) {
        Code07_Message1::push(u, f, edge, e);
        int v = tog[e];
        if (((v != f) && (!vis[v]))) {
          Code07_Message1::push(tog[e], u, (edge + 1), (-1));
        }
      }
    }
  }
  static void calc(int u, int edge, int effect) {
    (cnta = 0);
    (maxEdge = 0);
    Code07_Message1::dfs2(u, 0, edge);
    for (int i = 1; (i <= cnta); (i++)) {
      (ans[qidArr[i]] += (nodeCnt[needArr[i]] * effect));
    }
    for (int v = 0; (v <= maxEdge); (v++)) {
      (nodeCnt[v] = 0);
    }
  }
  static void solve(int u) {
    (vis[u] = true);
    Code07_Message1::calc(u, 0, 1);
    for (int e = headg[u]; (e > 0); (e = nextg[e])) {
      int v = tog[e];
      if ((!vis[v])) {
        Code07_Message1::calc(v, 1, (-1));
        Code07_Message1::solve(Code07_Message1::getCentroid(v, u));
      }
    }
  }
  static void prepare() {
    (cntg = 0);
    (cntq = 0);
    for (int i = 1; (i <= n); (i++)) {
      (headg[i] = 0);
      (headq[i] = 0);
      (vis[i] = false);
    }
    for (int i = 1; (i <= m); (i++)) {
      (ans[i] = 0);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      Code07_Message1::prepare();
      {
        int i = 1;
        int u = {};
        int v = {};
        for (; (i < n); (i++)) {
          (u = in.nextInt());
          (v = in.nextInt());
          Code07_Message1::addEdge(u, v);
          Code07_Message1::addEdge(v, u);
        }
      }
      {
        int i = 1;
        int x = {};
        int k = {};
        for (; (i <= m); (i++)) {
          (x = in.nextInt());
          (k = in.nextInt());
          Code07_Message1::addQuery(x, k, i);
        }
      }
      Code07_Message1::solve(Code07_Message1::getCentroid(1, 0));
      for (int i = 1; (i <= m); (i++)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Message1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 消息传递，java版
// 一共有n个节点，给定n-1条边，每条边的权值为1，所有节点组成一棵树
// 一共有m条查询，格式 x k : 打印有多少点与x的距离恰好为k
// 1 <= n、m <= 10^5
// 0 <= k < n
// 测试链接 : https://www.luogu.com.cn/problem/P6626
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // nodeCnt[i] = j，表示从u往下走i条边，一共能找到j个点
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                // dfs1(u, 0, edge);
        // 读写工具类
*/
