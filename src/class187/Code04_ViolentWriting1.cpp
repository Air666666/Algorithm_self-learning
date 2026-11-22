// Source: src/class187/Code04_ViolentWriting1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_ViolentWriting1 {
  inline static int MAXN = 366667;
  inline static int MAXM = jshl(MAXN, 1);
  inline static int MAXT = 10000001;
  inline static i64 INF = jshl(1LL, 50);
  inline static int n = {};
  inline static int cntn = {};
  inline static Array<int> head0 = make_array<int>(MAXN);
  inline static Array<int> next0 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to0 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight0 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt0 = {};
  inline static Array<int> head1 = make_array<int>(MAXM);
  inline static Array<int> next1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weight1 = make_array<int>(jshl(MAXM, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight2 = make_array<int>(jshl(MAXN, 1));
  inline static int cnt2 = {};
  inline static Array<i64> dis1 = make_array<i64>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXM);
  inline static Array<int> siz = make_array<int>(MAXM);
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<i64> lmax = make_array<i64>(MAXT);
  inline static Array<i64> rmax = make_array<i64>(MAXT);
  inline static int cntt = {};
  inline static i64 ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_ViolentWriting1() {}
  static void addEdge0(int u, int v, int w) {
    (next0[(++cnt0)] = head0[u]);
    (to0[cnt0] = v);
    (weight0[cnt0] = w);
    (head0[u] = cnt0);
  }
  static void addEdge1(int u, int v, int w) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, int w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static void getDist(int u, int fa, i64 dist1) {
    (dis1[u] = dist1);
    for (int e = head0[u]; (e > 0); (e = next0[e])) {
      int v = to0[e];
      if ((v != fa)) {
        Code04_ViolentWriting1::getDist(v, u, (dist1 + weight0[e]));
      }
    }
  }
  static void rebuild(int u, int fa) {
    int last = 0;
    for (int e = head0[u]; (e > 0); (e = next0[e])) {
      int v = to0[e];
      int w = weight0[e];
      if ((v != fa)) {
        if ((last == 0)) {
          (last = u);
          Code04_ViolentWriting1::addEdge1(u, v, w);
          Code04_ViolentWriting1::addEdge1(v, u, w);
        } else {
          int add = (++cntn);
          Code04_ViolentWriting1::addEdge1(last, add, 0);
          Code04_ViolentWriting1::addEdge1(add, last, 0);
          Code04_ViolentWriting1::addEdge1(add, v, w);
          Code04_ViolentWriting1::addEdge1(v, add, w);
          (last = add);
        }
        Code04_ViolentWriting1::rebuild(v, u);
      }
    }
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code04_ViolentWriting1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroidEdge(int u, int fa) {
    Code04_ViolentWriting1::getSize(u, fa);
    int total = siz[u];
    int half = jshr(total, 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head1[u]; (e > 0); (e = next1[e])) {
        int v = to1[e];
        if ((((v != fa) && (!vis[jshr(e, 1)])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    int best = 0;
    int edge = 0;
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      if ((!vis[jshr(e, 1)])) {
        int v = to1[e];
        int sub = ((v == fa) ? (total - siz[u]) : siz[v]);
        if ((sub > best)) {
          (best = sub);
          (edge = e);
        }
      }
    }
    return edge;
  }
  static void dfs(int u, int fa, i64 path, int op) {
    if ((u <= n)) {
      if ((up[u] == 0)) {
        (up[u] = (++cntt));
        (root[u] = cntt);
      }
      int cur = up[u];
      int nxt = (++cntt);
      if ((op == 0)) {
        (ls[cur] = nxt);
        (lmax[cur] = (dis1[u] + path));
      } else {
        (rs[cur] = nxt);
        (rmax[cur] = (dis1[u] + path));
      }
      (up[u] = nxt);
    }
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code04_ViolentWriting1::dfs(v, u, (path + weight1[e]), op);
      }
    }
  }
  static void solve(int u) {
    int edge = Code04_ViolentWriting1::getCentroidEdge(u, 0);
    if ((edge > 0)) {
      (vis[jshr(edge, 1)] = true);
      int v1 = to1[edge];
      int v2 = to1[(edge ^ 1)];
      Code04_ViolentWriting1::dfs(v1, 0, 0, 0);
      Code04_ViolentWriting1::dfs(v2, 0, weight1[edge], 1);
      Code04_ViolentWriting1::solve(v1);
      Code04_ViolentWriting1::solve(v2);
    }
  }
  static int mergeTree(int x, int y, i64 add) {
    if (((x == 0) || (y == 0))) {
      return (x + y);
    }
    (ans = jmax(ans, (jmax((lmax[x] + rmax[y]), (lmax[y] + rmax[x])) + add)));
    (lmax[x] = jmax(lmax[x], lmax[y]));
    (rmax[x] = jmax(rmax[x], rmax[y]));
    (ls[x] = Code04_ViolentWriting1::mergeTree(ls[x], ls[y], add));
    (rs[x] = Code04_ViolentWriting1::mergeTree(rs[x], rs[y], add));
    return x;
  }
  static void compute(int u, int fa, i64 dist2) {
    (ans = jmax(ans, ((dis1[u] - dist2) * 2)));
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code04_ViolentWriting1::compute(v, u, (dist2 + weight2[e]));
        (root[u] = Code04_ViolentWriting1::mergeTree(root[u], root[v],
                                                     ((-dist2) * 2)));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code04_ViolentWriting1::addEdge0(u, v, w);
        Code04_ViolentWriting1::addEdge0(v, u, w);
      }
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code04_ViolentWriting1::addEdge2(u, v, w);
        Code04_ViolentWriting1::addEdge2(v, u, w);
      }
    }
    for (int i = 1; (i < MAXT); (i++)) {
      (lmax[i] = (rmax[i] = (-INF)));
    }
    (cntn = n);
    (cnt1 = 1);
    (ans = (-INF));
    Code04_ViolentWriting1::getDist(1, 0, 0);
    Code04_ViolentWriting1::rebuild(1, 0);
    Code04_ViolentWriting1::solve(1);
    Code04_ViolentWriting1::compute(1, 0, 0);
    out.println(jshr(ans, 1));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_ViolentWriting1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 暴力写挂，java版
// 两棵树t1、t2都有n个节点，都以1号节点作为树头
// 各自给定n-1条边，以及每条边的边权，边权可能为负数
// 在t1中，点x到树头的距离记为dis1(x)，在t2中，该距离记为dis2(x)
// 点x和点y在t1中的LCA记为lca1(x, y)，在t2中的LCA记为lca2(x, y)
// 点对(x, y)的指标 = dis1(x) + dis1(y) - dis1(lca1(x, y)) - dis2(lca2(x, y))
// 点对(x, y)，要求x <= y，打印这个指标的最大值
// 1 <= n <= 366666
// 测试链接 : https://www.luogu.com.cn/problem/P4565
// 测试链接 : https://loj.ac/p/2553
// 提交以下的code，提交时请把类名改成"Main"
//
java实现的逻辑一定是正确的，但是需要把太多递归函数改成迭代才能通过，索性不改了
// 想通过用C++实现，本节课Code04_ViolentWriting2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/
