// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4220
// https://loj.ac/p/2339

// Source: src/class187/Code05_Passage1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Passage1 {
  inline static int MAXN = 100001;
  inline static int MAXM = jshl(MAXN, 1);
  inline static int MAXP = 20;
  inline static int MAXT = (MAXN * 20);
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int cntn = {};
  inline static Array<int> head0 = make_array<int>(MAXN);
  inline static Array<int> next0 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to0 = make_array<int>(jshl(MAXN, 1));
  inline static Array<i64> weight0 = make_array<i64>(jshl(MAXN, 1));
  inline static int cnt0 = {};
  inline static Array<int> head1 = make_array<int>(MAXM);
  inline static Array<int> next1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to1 = make_array<int>(jshl(MAXM, 1));
  inline static Array<i64> weight1 = make_array<i64>(jshl(MAXM, 1));
  inline static int cnt1 = {};
  inline static Array<int> head2 = make_array<int>(MAXN);
  inline static Array<int> next2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to2 = make_array<int>(jshl(MAXN, 1));
  inline static Array<i64> weight2 = make_array<i64>(jshl(MAXN, 1));
  inline static int cnt2 = {};
  inline static Array<int> head3 = make_array<int>(MAXN);
  inline static Array<int> next3 = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to3 = make_array<int>(jshl(MAXN, 1));
  inline static Array<i64> weight3 = make_array<i64>(jshl(MAXN, 1));
  inline static int cnt3 = {};
  inline static Array<i64> dep2 = make_array<i64>(MAXN);
  inline static Array<i64> dist3 = make_array<i64>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXM);
  inline static Array<int> siz = make_array<int>(MAXM);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> lg2 = make_array<int>(MAXN);
  inline static Array<Array<int>> rmq = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> lx = make_array<int>(MAXT);
  inline static Array<int> ly = make_array<int>(MAXT);
  inline static Array<i64> lxv = make_array<i64>(MAXT);
  inline static Array<i64> lyv = make_array<i64>(MAXT);
  inline static Array<int> rx = make_array<int>(MAXT);
  inline static Array<int> ry = make_array<int>(MAXT);
  inline static Array<i64> rxv = make_array<i64>(MAXT);
  inline static Array<i64> ryv = make_array<i64>(MAXT);
  inline static int cntt = {};
  inline static i64 ans = {};
  inline static int a = {};
  inline static int b = {};
  inline static int c = {};
  inline static int d = {};
  inline static i64 av = {};
  inline static i64 bv = {};
  inline static i64 cv = {};
  inline static i64 dv = {};
  inline static int x = {};
  inline static int y = {};
  inline static i64 xv = {};
  inline static i64 yv = {};
  inline static i64 bestDist = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Passage1() {}
  static void addEdge0(int u, int v, i64 w) {
    (next0[(++cnt0)] = head0[u]);
    (to0[cnt0] = v);
    (weight0[cnt0] = w);
    (head0[u] = cnt0);
  }
  static void addEdge1(int u, int v, i64 w) {
    (next1[(++cnt1)] = head1[u]);
    (to1[cnt1] = v);
    (weight1[cnt1] = w);
    (head1[u] = cnt1);
  }
  static void addEdge2(int u, int v, i64 w) {
    (next2[(++cnt2)] = head2[u]);
    (to2[cnt2] = v);
    (weight2[cnt2] = w);
    (head2[u] = cnt2);
  }
  static void addEdge3(int u, int v, i64 w) {
    (next3[(++cnt3)] = head3[u]);
    (to3[cnt3] = v);
    (weight3[cnt3] = w);
    (head3[u] = cnt3);
  }
  static void dfsTree2(int u, int fa, i64 dep) {
    (dep2[u] = dep);
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code05_Passage1::dfsTree2(v, u, (dep + weight2[e]));
      }
    }
  }
  static void rebuildTree1(int u, int fa) {
    int last = 0;
    for (int e = head0[u]; (e > 0); (e = next0[e])) {
      int v = to0[e];
      i64 w = weight0[e];
      if ((v != fa)) {
        if ((last == 0)) {
          (last = u);
          Code05_Passage1::addEdge1(u, v, w);
          Code05_Passage1::addEdge1(v, u, w);
        } else {
          int add = (++cntn);
          Code05_Passage1::addEdge1(last, add, 0);
          Code05_Passage1::addEdge1(add, last, 0);
          Code05_Passage1::addEdge1(add, v, w);
          Code05_Passage1::addEdge1(v, add, w);
          (last = add);
        }
        Code05_Passage1::rebuildTree1(v, u);
      }
    }
  }
  static void getSize(int u, int fa) {
    (siz[u] = 1);
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code05_Passage1::getSize(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static int getCentroidEdge(int u, int fa) {
    Code05_Passage1::getSize(u, fa);
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
  static void dfsTree1(int u, int fa, i64 path, int op) {
    if ((u <= n)) {
      if ((up[u] == 0)) {
        (up[u] = (++cntt));
        (root[u] = cntt);
      }
      int cur = up[u];
      int nxt = (++cntt);
      i64 val = (path + dep2[u]);
      if ((op == 0)) {
        (ls[cur] = nxt);
        (lx[cur] = (ly[cur] = u));
        (lxv[cur] = (lyv[cur] = val));
      } else {
        (rs[cur] = nxt);
        (rx[cur] = (ry[cur] = u));
        (rxv[cur] = (ryv[cur] = val));
      }
      (up[u] = nxt);
    }
    for (int e = head1[u]; (e > 0); (e = next1[e])) {
      int v = to1[e];
      if (((v != fa) && (!vis[jshr(e, 1)]))) {
        Code05_Passage1::dfsTree1(v, u, (path + weight1[e]), op);
      }
    }
  }
  static void solveTree1(int u) {
    int edge = Code05_Passage1::getCentroidEdge(u, 0);
    if ((edge > 0)) {
      (vis[jshr(edge, 1)] = true);
      int v1 = to1[edge];
      int v2 = to1[(edge ^ 1)];
      Code05_Passage1::dfsTree1(v1, 0, 0, 0);
      Code05_Passage1::dfsTree1(v2, 0, weight1[edge], 1);
      Code05_Passage1::solveTree1(v1);
      Code05_Passage1::solveTree1(v2);
    }
  }
  static int getUp(int x, int y) { return ((dfn[x] < dfn[y]) ? x : y); }
  static void dfsTree3(int u, int fa, i64 dist) {
    (dfn[u] = (++cntd));
    (rmq[dfn[u]][0] = fa);
    (dist3[u] = dist);
    for (int e = head3[u]; (e > 0); (e = next3[e])) {
      int v = to3[e];
      if ((v != fa)) {
        Code05_Passage1::dfsTree3(v, u, (dist + weight3[e]));
      }
    }
  }
  static void rmqTree3() {
    Code05_Passage1::dfsTree3(1, 0, 0);
    for (int i = 2; (i <= n); (i++)) {
      (lg2[i] = (lg2[jshr(i, 1)] + 1));
    }
    {
      int pre = 0;
      int cur = 1;
      for (; (cur <= lg2[n]); (pre++), (cur++)) {
        for (int i = 1; (((i + jshl(1, cur)) - 1) <= n); (i++)) {
          (rmq[i][cur] = Code05_Passage1::getUp(rmq[i][pre],
                                                rmq[(i + jshl(1, pre))][pre]));
        }
      }
    }
  }
  static int lcaTree3(int x, int y) {
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
    return Code05_Passage1::getUp(rmq[x][k], rmq[((y - jshl(1, k)) + 1)][k]);
  }
  static i64 getDist3(int x, int y) {
    return ((dist3[x] + dist3[y]) -
            (dist3[Code05_Passage1::lcaTree3(x, y)] * 2));
  }
  static i64 getDist(int x, int y, i64 xv, i64 yv) {
    if ((x == y)) {
      return 0;
    }
    return ((Code05_Passage1::getDist3(x, y) + xv) + yv);
  }
  static void getInfo(int i, int j, int iop, int jop) {
    if ((iop == 0)) {
      (a = lx[i]);
      (b = ly[i]);
      (av = lxv[i]);
      (bv = lyv[i]);
    } else {
      (a = rx[i]);
      (b = ry[i]);
      (av = rxv[i]);
      (bv = ryv[i]);
    }
    if ((jop == 0)) {
      (c = lx[j]);
      (d = ly[j]);
      (cv = lxv[j]);
      (dv = lyv[j]);
    } else {
      (c = rx[j]);
      (d = ry[j]);
      (cv = rxv[j]);
      (dv = ryv[j]);
    }
  }
  static i64 bestCross(int i, int j, int iop, int jop) {
    Code05_Passage1::getInfo(i, j, iop, jop);
    i64 p1 = Code05_Passage1::getDist(a, c, av, cv);
    i64 p2 = Code05_Passage1::getDist(a, d, av, dv);
    i64 p3 = Code05_Passage1::getDist(b, c, bv, cv);
    i64 p4 = Code05_Passage1::getDist(b, d, bv, dv);
    return [&]() {
      auto jargument_0 = jmax(p1, p2);
      auto jargument_1 = jmax(p3, p4);
      return jmax(jargument_0, jargument_1);
    }();
  }
  static void better(int curx, int cury, i64 curxv, i64 curyv) {
    if (((curx == 0) || (cury == 0))) {
      return;
    }
    i64 curDist = Code05_Passage1::getDist(curx, cury, curxv, curyv);
    if ((curDist > bestDist)) {
      (x = curx);
      (y = cury);
      (xv = curxv);
      (yv = curyv);
      (bestDist = curDist);
    }
  }
  static void mergeInfo(int i, int j, int op) {
    Code05_Passage1::getInfo(i, j, op, op);
    (x = (y = 0));
    (xv = (yv = 0));
    (bestDist = (-INF));
    Code05_Passage1::better(a, b, av, bv);
    Code05_Passage1::better(c, d, cv, dv);
    Code05_Passage1::better(a, c, av, cv);
    Code05_Passage1::better(a, d, av, dv);
    Code05_Passage1::better(b, c, bv, cv);
    Code05_Passage1::better(b, d, bv, dv);
    if ((op == 0)) {
      (lx[i] = x);
      (ly[i] = y);
      (lxv[i] = xv);
      (lyv[i] = yv);
    } else {
      (rx[i] = x);
      (ry[i] = y);
      (rxv[i] = xv);
      (ryv[i] = yv);
    }
  }
  static int mergeTree(int i, int j, i64 add) {
    if (((i == 0) || (j == 0))) {
      return (i + j);
    }
    if (((ls[i] > 0) && (rs[j] > 0))) {
      (ans = jmax(ans, (Code05_Passage1::bestCross(i, j, 0, 1) + add)));
    }
    if (((rs[i] > 0) && (ls[j] > 0))) {
      (ans = jmax(ans, (Code05_Passage1::bestCross(i, j, 1, 0) + add)));
    }
    Code05_Passage1::mergeInfo(i, j, 0);
    Code05_Passage1::mergeInfo(i, j, 1);
    (ls[i] = Code05_Passage1::mergeTree(ls[i], ls[j], add));
    (rs[i] = Code05_Passage1::mergeTree(rs[i], rs[j], add));
    return i;
  }
  static void compute(int u, int fa) {
    for (int e = head2[u]; (e > 0); (e = next2[e])) {
      int v = to2[e];
      if ((v != fa)) {
        Code05_Passage1::compute(v, u);
        (root[u] =
             Code05_Passage1::mergeTree(root[u], root[v], ((-dep2[u]) * 2)));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    int u = {};
    int v = {};
    i64 w = {};
    for (int i = 1; (i < n); (i++)) {
      (u = in.nextInt());
      (v = in.nextInt());
      (w = in.nextLong());
      Code05_Passage1::addEdge0(u, v, w);
      Code05_Passage1::addEdge0(v, u, w);
    }
    for (int i = 1; (i < n); (i++)) {
      (u = in.nextInt());
      (v = in.nextInt());
      (w = in.nextLong());
      Code05_Passage1::addEdge2(u, v, w);
      Code05_Passage1::addEdge2(v, u, w);
    }
    for (int i = 1; (i < n); (i++)) {
      (u = in.nextInt());
      (v = in.nextInt());
      (w = in.nextLong());
      Code05_Passage1::addEdge3(u, v, w);
      Code05_Passage1::addEdge3(v, u, w);
    }
    (cntn = n);
    (cnt1 = 1);
    (ans = (-INF));
    Code05_Passage1::dfsTree2(1, 0, 0);
    Code05_Passage1::rebuildTree1(1, 0);
    Code05_Passage1::solveTree1(1);
    Code05_Passage1::rmqTree3();
    Code05_Passage1::compute(1, 0);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Passage1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 通道，java版
// 三棵树t1、t2、t3都有n个节点，各自给定n-1条边以及每条边的边权，边权没有负数
// 点对(x, y)，要求两点必须不同，两点在树上的距离就是简单路径上边权的累加和
// 点对(x, y)，在t1、t2、t3的距离，分别记为dis1(x, y)、dis2(x, y)、dis3(x, y)
// 打印最大的dis1(x, y) + dis2(x, y) + dis3(x, y)
// 2 <= n <= 10^5
// 0 <= 边权 <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P4220
// 测试链接 : https://loj.ac/p/2339
// 提交以下的code，提交时请把类名改成"Main"
//
java实现的逻辑一定是正确的，但是需要把太多递归函数改成迭代才能通过，索性不改了
// 想通过用C++实现，本节课Code05_Passage2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 读写工具类
*/
