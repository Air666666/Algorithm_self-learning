// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF786B
// https://codeforces.com/problemset/problem/786/B

// Source: src/class195/Code01_Legacy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Legacy1 {
  inline static int MAXN = 100001;
  inline static int MAXT = (MAXN * 10);
  inline static int MAXE = (MAXN * 30);
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int q = {};
  inline static int s = {};
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static Array<int> weight = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int rootOut = {};
  inline static int rootIn = {};
  inline static int cntt = {};
  inline static Array<i64> dist = make_array<i64>(MAXT);
  inline static Array<bool> vis = make_array<bool>(MAXT);
  inline static JHeap<Array<i64>> heap = JHeap<Array<i64>>(
      [](Array<i64> x, Array<i64> y) { return jcompare(x[1], y[1]); });
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Legacy1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static int buildOut(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code01_Legacy1::buildOut(l, mid));
      (rs[rt] = Code01_Legacy1::buildOut((mid + 1), r));
      Code01_Legacy1::addEdge(ls[rt], rt, 0);
      Code01_Legacy1::addEdge(rs[rt], rt, 0);
    }
    return rt;
  }
  static int buildIn(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code01_Legacy1::buildIn(l, mid));
      (rs[rt] = Code01_Legacy1::buildIn((mid + 1), r));
      Code01_Legacy1::addEdge(rt, ls[rt], 0);
      Code01_Legacy1::addEdge(rt, rs[rt], 0);
    }
    return rt;
  }
  static void xToRange(int jobx, int jobl, int jobr, int jobw, int l, int r,
                       int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_Legacy1::addEdge(jobx, i, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code01_Legacy1::xToRange(jobx, jobl, jobr, jobw, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code01_Legacy1::xToRange(jobx, jobl, jobr, jobw, (mid + 1), r, rs[i]);
      }
    }
  }
  static void rangeToX(int jobl, int jobr, int jobx, int jobw, int l, int r,
                       int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code01_Legacy1::addEdge(i, jobx, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code01_Legacy1::rangeToX(jobl, jobr, jobx, jobw, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code01_Legacy1::rangeToX(jobl, jobr, jobx, jobw, (mid + 1), r, rs[i]);
      }
    }
  }
  static void dijkstra() {
    for (int i = 1; (i <= cntt); (i++)) {
      (dist[i] = INF);
    }
    (dist[s] = 0);
    heap.add(Array<i64>{s, 0});
    while ((!heap.isEmpty())) {
      Array<i64> cur = heap.poll();
      int u = static_cast<int>(cur[0]);
      i64 d = cur[1];
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          int w = weight[e];
          if (((!vis[v]) && (dist[v] > (d + w)))) {
            (dist[v] = (d + w));
            heap.add(Array<i64>{v, dist[v]});
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    (s = in.nextInt());
    (cntt = n);
    (rootOut = Code01_Legacy1::buildOut(1, n));
    (rootIn = Code01_Legacy1::buildIn(1, n));
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int l = {};
      int r = {};
      int w = {};
      for (; (i <= q); (i++)) {
        (op = in.nextInt());
        if ((op == 1)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (w = in.nextInt());
          Code01_Legacy1::addEdge(x, y, w);
        } else if ((op == 2)) {
          (x = in.nextInt());
          (l = in.nextInt());
          (r = in.nextInt());
          (w = in.nextInt());
          Code01_Legacy1::xToRange(x, l, r, w, 1, n, rootIn);
        } else {
          (x = in.nextInt());
          (l = in.nextInt());
          (r = in.nextInt());
          (w = in.nextInt());
          Code01_Legacy1::rangeToX(l, r, x, w, 1, n, rootOut);
        }
      }
    }
    Code01_Legacy1::dijkstra();
    for (int i = 1; (i <= n); (i++)) {
      out.print(((dist[i] == INF) ? (-1) : dist[i]));
      out.print(String(u" "));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Legacy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 遗产，java版
// 一共n个点，给定起点s，一共q条操作，操作类型如下
// 操作 1 x y w   : 从点x到点y增加有向边，边权是w
// 操作 2 x l r w : 从点x到l~r范围的每个点增加有向边，边权都是w
// 操作 3 x l r w : 从l~r范围的每个点到点x增加有向边，边权都是w
// 所有操作完成后，计算起点s到每个点的最短距离并打印，如果不连通打印-1
// 1 <= n、q <= 10^5
// 1 <= w <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF786B
// 测试链接 : https://codeforces.com/problemset/problem/786/B
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 出树和入树共用ls和rs
        // 出树的头节点编号rootOut
        // 入树的头节点编号rootIn
        // 空间利用cntt计数来分配
        // 可持久化线段树，即主席树，也是这种设计
        // 当前点、源点到当前点的代价
        // 读写工具类
*/
