// Source: src/class183/Code06_Maschera1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Maschera1 {
  inline static int MAXN = 100002;
  inline static int n = {};
  inline static int l = {};
  inline static int r = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> maxvArr = make_array<int>(MAXN);
  inline static Array<int> edgeArr = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int maxv = {};
  inline static int edge = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Maschera1() {}
  static void push(int u, int f, int maxv, int edge, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = maxv);
    (stack[stacksize][3] = edge);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (maxv = stack[stacksize][2]);
    (edge = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void sort(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = maxvArr[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((maxvArr[i] < pivot))
        (i++);
      while ((maxvArr[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = maxvArr[i]);
        (maxvArr[i] = maxvArr[j]);
        (maxvArr[j] = tmp);
        (tmp = edgeArr[i]);
        (edgeArr[i] = edgeArr[j]);
        (edgeArr[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code06_Maschera1::sort(l, j);
    Code06_Maschera1::sort(i, r);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    (i++);
    while ((i <= (r + 1))) {
      (tree[i] += v);
      (i += Code06_Maschera1::lowbit(i));
    }
  }
  static int sum(int i) {
    (i++);
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code06_Maschera1::lowbit(i));
    }
    return ret;
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code06_Maschera1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code06_Maschera1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code06_Maschera1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code06_Maschera1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code06_Maschera1::push(v, u, 0, 0, (-1));
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
    Code06_Maschera1::getSize2(u, fa);
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
  static void dfs1(int u, int fa, int maxv, int edge) {
    if ((edge > r)) {
      return;
    }
    (maxvArr[(++cnta)] = maxv);
    (edgeArr[cnta] = edge);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code06_Maschera1::dfs1(v, u, jmax(maxv, weight[e]), (edge + 1));
      }
    }
  }
  static void dfs2(int cur, int fa, int pmaxv, int pedge) {
    (stacksize = 0);
    Code06_Maschera1::push(cur, fa, pmaxv, pedge, (-1));
    while ((stacksize > 0)) {
      Code06_Maschera1::pop();
      if ((e == (-1))) {
        if ((edge > r)) {
          continue;
        }
        (maxvArr[(++cnta)] = maxv);
        (edgeArr[cnta] = edge);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code06_Maschera1::push(u, f, maxv, edge, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code06_Maschera1::push(to[e], u, jmax(maxv, weight[e]), (edge + 1),
                                 (-1));
        }
      }
    }
  }
  static i64 calc(int u, int maxv, int edge) {
    (cnta = 0);
    Code06_Maschera1::dfs2(u, 0, maxv, edge);
    Code06_Maschera1::sort(1, cnta);
    i64 ans = 0;
    for (int i = 1; (i <= cnta); (i++)) {
      (ans += ((1LL * maxvArr[i]) * [&]() {
         auto jleft = Code06_Maschera1::sum((r - edgeArr[i]));
         auto jright = Code06_Maschera1::sum(((l - edgeArr[i]) - 1));
         return (jleft - jright);
       }()));
      Code06_Maschera1::add(edgeArr[i], 1);
    }
    for (int i = 1; (i <= cnta); (i++)) {
      Code06_Maschera1::add(edgeArr[i], (-1));
    }
    return ans;
  }
  static i64 solve(int u) {
    (vis[u] = true);
    i64 ans = Code06_Maschera1::calc(u, 0, 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans -= Code06_Maschera1::calc(v, weight[e], 1));
        (ans += Code06_Maschera1::solve(Code06_Maschera1::getCentroid(v, u)));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (l = in.nextInt());
    (r = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code06_Maschera1::addEdge(u, v, w);
        Code06_Maschera1::addEdge(v, u, w);
      }
    }
    i64 ans = Code06_Maschera1::solve(Code06_Maschera1::getCentroid(1, 0));
    out.println(jshl(ans, 1));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Maschera1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 所有合法路径的魔力和，java版
// 一共有n个节点，给定n-1条边，每条边有边权，所有节点组成一棵树
// 给定两个整数l、r，对于点对(x, y)，考虑两点之间的简单路径
// 如果路径的边数在[l, r]范围内，则该路径视为合法
// 一条路径的魔力值 = 该路径上所有边权的最大值
// 计算所有合法路径的魔力值之和
// 本题规定(x, x)不是点对，(x, y)和(y, x)认为是不同的点对
// 1 <= n、边权 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5351
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 得到子树大小递归版，java会爆栈，C++可以通过
        // 得到子树大小迭代版
                // getSize1(u, fa);
        // 收集信息递归版，java会爆栈，C++可以通过
        // 收集信息迭代版
                // dfs1(u, 0, maxv, edge);
        // 读写工具类
*/
