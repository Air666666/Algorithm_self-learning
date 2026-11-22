// Source: src/class195/Code03_Road1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Road1 {
  inline static int MAXN = 50001;
  inline static int MAXT = (MAXN * 10);
  inline static int MAXE = (MAXN * 20);
  inline static int MAXK = 11;
  inline static int INF = jshl(1, 30);
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
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
  inline static Array<Array<int>> dist = make_array<int>(MAXT, MAXK);
  inline static Array<Array<bool>> vis = make_array<bool>(MAXT, MAXK);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Road1() {}
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
      (ls[rt] = Code03_Road1::buildOut(l, mid));
      (rs[rt] = Code03_Road1::buildOut((mid + 1), r));
      Code03_Road1::addEdge(ls[rt], rt, 0);
      Code03_Road1::addEdge(rs[rt], rt, 0);
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
      (ls[rt] = Code03_Road1::buildIn(l, mid));
      (rs[rt] = Code03_Road1::buildIn((mid + 1), r));
      Code03_Road1::addEdge(rt, ls[rt], 0);
      Code03_Road1::addEdge(rt, rs[rt], 0);
    }
    return rt;
  }
  static void xToRange(int jobx, int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_Road1::addEdge(jobx, i, 0);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_Road1::xToRange(jobx, jobl, jobr, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code03_Road1::xToRange(jobx, jobl, jobr, (mid + 1), r, rs[i]);
      }
    }
  }
  static void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code03_Road1::addEdge(i, jobx, 0);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code03_Road1::rangeToX(jobl, jobr, jobx, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code03_Road1::rangeToX(jobl, jobr, jobx, (mid + 1), r, rs[i]);
      }
    }
  }
  static void rangeToRange(int a, int b, int c, int d, int w) {
    int x = (++cntt);
    int y = (++cntt);
    Code03_Road1::rangeToX(a, b, x, 1, n, rootOut);
    Code03_Road1::xToRange(y, c, d, 1, n, rootIn);
    Code03_Road1::addEdge(x, y, w);
  }
  static int dijkstra(int start, int target) {
    for (int i = 1; (i <= cntt); (i++)) {
      for (int j = 0; (j <= k); (j++)) {
        (dist[i][j] = INF);
        (vis[i][j] = false);
      }
    }
    (dist[start][0] = 0);
    heap.add(Array<int>{start, 0, 0});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int node = cur[0];
      int time = cur[1];
      int cost = cur[2];
      if ((!vis[node][time])) {
        (vis[node][time] = true);
        if ((node == target)) {
          return cost;
        }
        for (int e = head[node]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          int w = weight[e];
          if (((!vis[v][time]) && (dist[v][time] > (cost + w)))) {
            (dist[v][time] = (cost + w));
            heap.add(Array<int>{v, time, dist[v][time]});
          }
          if ((((time < k) && (!vis[v][(time + 1)])) &&
               (dist[v][(time + 1)] > cost))) {
            (dist[v][(time + 1)] = cost);
            heap.add(Array<int>{v, (time + 1), dist[v][(time + 1)]});
          }
        }
      }
    }
    return (-1);
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = 0);
    }
    (cntg = (cntt = 0));
    heap.clear();
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int test = 1; (test <= t); (test++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      (k = in.nextInt());
      (cntt = n);
      (rootOut = Code03_Road1::buildOut(1, n));
      (rootIn = Code03_Road1::buildIn(1, n));
      {
        int i = 1;
        int a = {};
        int b = {};
        int c = {};
        int d = {};
        int w = {};
        for (; (i <= m); (i++)) {
          (a = in.nextInt());
          (b = in.nextInt());
          (c = in.nextInt());
          (d = in.nextInt());
          (w = in.nextInt());
          Code03_Road1::rangeToRange(a, b, c, d, w);
          Code03_Road1::rangeToRange(c, d, a, b, w);
        }
      }
      int ans = Code03_Road1::dijkstra(1, n);
      if ((ans == (-1))) {
        out.println(String(u"CreationAugust is a sb!"));
      } else {
        out.println(ans);
      }
      Code03_Road1::clear();
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Road1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 道路，java版
// 一共n个点，一共m次操作，格式如下
// 操作 a b c d w: a~b范围每个点与c~d范围每个点之间，都增加权值为w的无向边
// 给定数字k，表示有k次机会，每次在通过一条边时，不用支付这条边的代价
// 所有操作完成后，打印1号点到n号点的最低代价
// 如果不存在通路，打印"CreationAugust is a sb!"
// 1 <= n <= 5 * 10^4
// 1 <= m <= 10^5
// 1 <= k <= 10
// 1 <= w <= 10^3
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=5669
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 编号、次数、花费
        // 读写工具类
*/
