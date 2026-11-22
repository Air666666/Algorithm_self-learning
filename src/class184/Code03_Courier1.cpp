// Source: src/class184/Code03_Courier1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Courier1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int d = {};
  inline static int t = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Courier1() {}
  static void push(int u, int f, int d, int t, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = d);
    (stack[stacksize][3] = t);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (d = stack[stacksize][2]);
    (t = stack[stacksize][3]);
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
        Code03_Courier1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code03_Courier1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code03_Courier1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Courier1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code03_Courier1::push(v, u, 0, 0, (-1));
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
    Code03_Courier1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int d, int t) {
    (tree[u] = t);
    (dist[u] = d);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code03_Courier1::dfs1(v, u, (d + weight[e]), t);
      }
    }
  }
  static void dfs2(int cur, int fa, int di, int tr) {
    (stacksize = 0);
    Code03_Courier1::push(cur, fa, di, tr, (-1));
    while ((stacksize > 0)) {
      Code03_Courier1::pop();
      if ((e == (-1))) {
        (tree[u] = t);
        (dist[u] = d);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Courier1::push(u, f, d, t, e);
        int v = to[e];
        if ((v != f)) {
          Code03_Courier1::push(v, u, (d + weight[e]), t, (-1));
        }
      }
    }
  }
  static int compute() {
    int ans = 1000000001;
    int u = Code03_Courier1::getCentroid(1, 0);
    while ((!vis[u])) {
      (vis[u] = true);
      (tree[u] = u);
      (dist[u] = 0);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        int w = weight[e];
        Code03_Courier1::dfs2(v, u, w, v);
      }
      int maxDist = 0;
      int son = 0;
      for (int i = 1; (i <= m); (i++)) {
        int curDist = (dist[a[i]] + dist[b[i]]);
        int t1 = tree[a[i]];
        int t2 = tree[b[i]];
        if ((maxDist < curDist)) {
          (maxDist = curDist);
          (son = ((t1 == t2) ? t1 : 0));
        } else if (((maxDist == curDist) && ((t1 != t2) || (t1 != son)))) {
          (son = 0);
        }
      }
      (ans = jmin(ans, maxDist));
      if ((son == 0)) {
        break;
      }
      (u = Code03_Courier1::getCentroid(son, u));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code03_Courier1::addEdge(u, v, w);
        Code03_Courier1::addEdge(v, u, w);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
    }
    out.println(Code03_Courier1::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Courier1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 快递员，java版
// 一共有n个节点，给定n-1条边，每条边给定边权，所有节点组成一棵树
// 对于点对(a, b)，假设你选择的中心点为x，那么点对的距离如下
// 点对(a, b)的距离 = a到x的路径权值和 + b到x的路径权值和
// 一共有m个点对，你需要选择中心点x，使得点对距离的最大值尽量小
// 打印这个最小的点对距离最大值
// 1 <= n、m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4886
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                                // dfs1(v, u, w, v);
        // 读写工具类
*/
