// Source: src/class183/Code05_CloseVertices1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CloseVertices1 {
  inline static int MAXN = 100002;
  inline static int n = {};
  inline static int limitl = {};
  inline static int limitw = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> disArr = make_array<int>(MAXN);
  inline static Array<int> edgeArr = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> tree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CloseVertices1() {}
  static void sort(int l, int r) {
    if ((l >= r))
      return;
    int i = l;
    int j = r;
    int pivot = disArr[jshr((l + r), 1)];
    int tmp = {};
    while ((i <= j)) {
      while ((disArr[i] < pivot))
        (i++);
      while ((disArr[j] > pivot))
        (j--);
      if ((i <= j)) {
        (tmp = disArr[i]);
        (disArr[i] = disArr[j]);
        (disArr[j] = tmp);
        (tmp = edgeArr[i]);
        (edgeArr[i] = edgeArr[j]);
        (edgeArr[j] = tmp);
        (i++);
        (j--);
      }
    }
    Code05_CloseVertices1::sort(l, j);
    Code05_CloseVertices1::sort(i, r);
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
    while ((i <= (limitl + 1))) {
      (tree[i] += v);
      (i += Code05_CloseVertices1::lowbit(i));
    }
  }
  static int sum(int i) {
    (i++);
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code05_CloseVertices1::lowbit(i));
    }
    return ret;
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_CloseVertices1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code05_CloseVertices1::getSize(u, fa);
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
  static void dfs(int u, int fa, int dis, int edge) {
    if (((dis > limitw) || (edge > limitl))) {
      return;
    }
    (disArr[(++cnta)] = dis);
    (edgeArr[cnta] = edge);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code05_CloseVertices1::dfs(v, u, (dis + weight[e]), (edge + 1));
      }
    }
  }
  static i64 calc(int u, int dis, int edge) {
    (cnta = 0);
    Code05_CloseVertices1::dfs(u, 0, dis, edge);
    Code05_CloseVertices1::sort(1, cnta);
    for (int i = 1; (i <= cnta); (i++)) {
      Code05_CloseVertices1::add(edgeArr[i], 1);
    }
    i64 ans = 0;
    {
      int l = 1;
      int r = cnta;
      for (; (l <= r);) {
        if (((disArr[l] + disArr[r]) <= limitw)) {
          Code05_CloseVertices1::add(edgeArr[l], (-1));
          (ans += Code05_CloseVertices1::sum((limitl - edgeArr[l])));
          (l++);
        } else {
          Code05_CloseVertices1::add(edgeArr[r], (-1));
          (r--);
        }
      }
    }
    return ans;
  }
  static i64 solve(int u) {
    (vis[u] = true);
    i64 ans = Code05_CloseVertices1::calc(u, 0, 0);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        (ans -= Code05_CloseVertices1::calc(v, weight[e], 1));
        (ans += Code05_CloseVertices1::solve(
             Code05_CloseVertices1::getCentroid(v, u)));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (limitl = in.nextInt());
    (limitw = in.nextInt());
    {
      int i = 2;
      int fa = {};
      int w = {};
      for (; (i <= n); (i++)) {
        (fa = in.nextInt());
        (w = in.nextInt());
        Code05_CloseVertices1::addEdge(i, fa, w);
        Code05_CloseVertices1::addEdge(fa, i, w);
      }
    }
    out.println(
        Code05_CloseVertices1::solve(Code05_CloseVertices1::getCentroid(1, 0)));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_CloseVertices1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相近点对的数量，java版
// 一共有n个节点，所有节点组成一棵树，1号节点是树头
// 从2号点开始，给定每个点的父节点编号、与父节点之间无向边的边权
// 给定两个整数limitl、limitw，要求两点之间的简单路径满足如下关系
// 路径权值和 <= limitw、路径边数 <= limitl，求出这样的点对数量
// 本题规定(x, x)不是点对，(x, y)和(y, x)认为是同一个点对
// 1 <= limitl <= n <= 10^5    0 <= limitw <= 10^9    0 <= 边权 <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/CF293E
// 测试链接 : https://codeforces.com/problemset/problem/293/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 树状数组
        // 下标是边数，统计节点个数
        // 但是注意，边数从0开始，而树状数组的下标从1开始
        // 所以每次的入参i，需要i++进行平移
        // 从真正的头来到u时，路径权值和为dis，边的数量为edge
        // 子树u上的点对(x, y)，需要走过，x -> 真正的头 -> y
        // 返回 路径权值和<=limitw、路径边数<=limitwl 的点对数量
        // 读写工具类
*/
