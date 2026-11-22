// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6348

// Source: src/class195/Code02_Journeys1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Journeys1 {
  inline static int MAXN = 500001;
  inline static int MAXT = (MAXN * 10);
  inline static int MAXE = (MAXN * 20);
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int m = {};
  inline static int p = {};
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
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static JDeque<int> deq = JDeque<int>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Journeys1() {}
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
      (ls[rt] = Code02_Journeys1::buildOut(l, mid));
      (rs[rt] = Code02_Journeys1::buildOut((mid + 1), r));
      Code02_Journeys1::addEdge(ls[rt], rt, 0);
      Code02_Journeys1::addEdge(rs[rt], rt, 0);
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
      (ls[rt] = Code02_Journeys1::buildIn(l, mid));
      (rs[rt] = Code02_Journeys1::buildIn((mid + 1), r));
      Code02_Journeys1::addEdge(rt, ls[rt], 0);
      Code02_Journeys1::addEdge(rt, rs[rt], 0);
    }
    return rt;
  }
  static void xToRange(int jobx, int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code02_Journeys1::addEdge(jobx, i, 0);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code02_Journeys1::xToRange(jobx, jobl, jobr, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code02_Journeys1::xToRange(jobx, jobl, jobr, (mid + 1), r, rs[i]);
      }
    }
  }
  static void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code02_Journeys1::addEdge(i, jobx, 0);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code02_Journeys1::rangeToX(jobl, jobr, jobx, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code02_Journeys1::rangeToX(jobl, jobr, jobx, (mid + 1), r, rs[i]);
      }
    }
  }
  static void rangeToRange(int a, int b, int c, int d) {
    int x = (++cntt);
    int y = (++cntt);
    Code02_Journeys1::rangeToX(a, b, x, 1, n, rootOut);
    Code02_Journeys1::xToRange(y, c, d, 1, n, rootIn);
    Code02_Journeys1::addEdge(x, y, 1);
  }
  static void bfs01() {
    for (int i = 1; (i <= cntt); (i++)) {
      (dist[i] = INF);
    }
    (dist[p] = 0);
    deq.addFirst(p);
    while ((!deq.isEmpty())) {
      int u = deq.pollFirst();
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        int w = weight[e];
        if ((dist[v] > (dist[u] + w))) {
          (dist[v] = (dist[u] + w));
          if ((w == 0)) {
            deq.addFirst(v);
          } else {
            deq.addLast(v);
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (p = in.nextInt());
    (cntt = n);
    (rootOut = Code02_Journeys1::buildOut(1, n));
    (rootIn = Code02_Journeys1::buildIn(1, n));
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      for (; (i <= m); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        (d = in.nextInt());
        Code02_Journeys1::rangeToRange(a, b, c, d);
        Code02_Journeys1::rangeToRange(c, d, a, b);
      }
    }
    Code02_Journeys1::bfs01();
    for (int i = 1; (i <= n); (i++)) {
      out.println(dist[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Journeys1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 旅程，java版
// 一共n个点，给定起点p，一共m次操作，格式如下
// 操作 a b c d : a~b范围每个点与c~d范围每个点之间，都增加一条无向边
// 所有操作完成后，计算起点p到每个点经过的最少边数，题目保证整体连通
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6348
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
