// Source: src/class198/Code04_Cdq_Optimization_3D_java.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Cdq_Optimization_3D_java {
  inline static int MAXN = 101;
  inline static int MAXM = 1001;
  inline static int MAXV = 10001;
  inline static int MAXT = 100001;
  inline static int MAXE = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static int maxc = {};
  inline static int cntt = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 4);
  inline static int cnta = {};
  inline static Array<int> headg = make_array<int>(MAXT);
  inline static Array<int> nextg = make_array<int>(MAXE);
  inline static Array<int> tog = make_array<int>(MAXE);
  inline static Array<int> weightg = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> headp = make_array<int>(MAXT);
  inline static Array<int> nextp = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> top = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weightp = make_array<int>(jshl(MAXM, 1));
  inline static int cntp = {};
  inline static Array<int> tree = make_array<int>(MAXV);
  inline static int MAX_2 = 100001;
  inline static Array<int> head_2 = make_array<int>(MAX_2);
  inline static Array<int> nxt_2 = make_array<int>(MAX_2);
  inline static Array<int> to_2 = make_array<int>(MAX_2);
  inline static Array<int> weight_2 = make_array<int>(MAX_2);
  inline static int cnt_2 = {};
  inline static int INF = 1000000001;
  inline static Array<int> dist = make_array<int>(MAXT);
  inline static Array<bool> vis = make_array<bool>(MAXT);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> x, Array<int> y) { return (x[1] - y[1]); });
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Cdq_Optimization_3D_java() {}
  static void addEdge(int u, int v, int w) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (weightg[cntg] = w);
    (headg[u] = cntg);
  }
  static void addOp(int x, int u, int w) {
    (nextp[(++cntp)] = headp[x]);
    (top[cntp] = u);
    (weightp[cntp] = w);
    (headp[x] = cntp);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int x) {
    while ((i <= maxc)) {
      int pre = tree[i];
      int cur = (++cntt);
      if ((pre != 0)) {
        Code04_Cdq_Optimization_3D_java::addEdge(pre, cur, 0);
      }
      Code04_Cdq_Optimization_3D_java::addEdge(x, cur, 0);
      (tree[i] = cur);
      (i += Code04_Cdq_Optimization_3D_java::lowbit(i));
    }
  }
  static void rangeToX(int i, int x, int w) {
    while ((i > 0)) {
      if ((tree[i] > 0)) {
        Code04_Cdq_Optimization_3D_java::addEdge(tree[i], x, w);
      }
      (i -= Code04_Cdq_Optimization_3D_java::lowbit(i));
    }
  }
  static void clear(int val) {
    while ((val <= maxc)) {
      (tree[val] = 0);
      (val += Code04_Cdq_Optimization_3D_java::lowbit(val));
    }
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][2] <= arr[p2][2]))) {
        (p1++);
        Code04_Cdq_Optimization_3D_java::add(arr[p1][3], arr[p1][0]);
      }
      for (int e = headp[arr[p2][0]]; (e > 0); (e = nextp[e])) {
        int u = top[e];
        int w = weightp[e];
        Code04_Cdq_Optimization_3D_java::rangeToX(arr[p2][3], u, w);
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      Code04_Cdq_Optimization_3D_java::clear(arr[i][3]);
    }
    j::sort(arr, l, (r + 1),
            [=](Array<int> x, Array<int> y) { return (x[2] - y[2]); });
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code04_Cdq_Optimization_3D_java::cdq(l, mid);
    Code04_Cdq_Optimization_3D_java::cdq((mid + 1), r);
    Code04_Cdq_Optimization_3D_java::merge(l, mid, r);
  }
  static void buildGraph() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = a[i]);
      (arr[i][2] = b[i]);
      (arr[i][3] = c[i]);
      (maxc = jmax(maxc, c[i]));
    }
    j::sort(arr, 1, (n + 1), [=](Array<int> x, Array<int> y) {
      return ((x[1] != y[1])
                  ? (x[1] - y[1])
                  : ((x[2] != y[2]) ? (x[2] - y[2]) : (x[3] - y[3])));
    });
    (cntt = n);
    {
      int l = 1;
      int r = 1;
      for (; (l <= n); (l = (++r))) {
        int a = arr[l][1];
        int b = arr[l][2];
        int c = arr[l][3];
        while ((((((r + 1) <= n) && (a == arr[(r + 1)][1])) &&
                 (b == arr[(r + 1)][2])) &&
                (c == arr[(r + 1)][3]))) {
          (r++);
        }
        int x = (++cntt);
        for (int i = l; (i <= r); (i++)) {
          int u = arr[i][0];
          Code04_Cdq_Optimization_3D_java::addEdge(u, x, 0);
          for (int e = headp[u]; (e > 0); (e = nextp[e])) {
            Code04_Cdq_Optimization_3D_java::addEdge(x, u, weightp[e]);
            Code04_Cdq_Optimization_3D_java::addOp(x, u, weightp[e]);
          }
        }
        (arr[(++cnta)][0] = x);
        (arr[cnta][1] = a);
        (arr[cnta][2] = b);
        (arr[cnta][3] = c);
      }
    }
    Code04_Cdq_Optimization_3D_java::cdq(1, cnta);
  }
  static void addEdge_2(int u, int v, int w) {
    (nxt_2[(++cnt_2)] = head_2[u]);
    (to_2[cnt_2] = v);
    (weight_2[cnt_2] = w);
    (head_2[u] = cnt_2);
  }
  static void link(int x, int w) {
    for (int i = 1; (i <= n); (i++)) {
      if ((((a[i] <= a[x]) && (b[i] <= b[x])) && (c[i] <= c[x]))) {
        Code04_Cdq_Optimization_3D_java::addEdge_2(i, x, w);
      }
    }
  }
  static int dijkstra(int s, int t) {
    for (int i = 1; (i <= cntt); (i++)) {
      (dist[i] = INF);
      (vis[i] = false);
    }
    heap.clear();
    (dist[s] = 0);
    heap.add(Array<int>{s, 0});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int u = cur[0];
      int d = cur[1];
      if ((u == t)) {
        return d;
      }
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = headg[u]; (e > 0); (e = nextg[e])) {
          int v = tog[e];
          int w = weightg[e];
          if (((!vis[v]) && (dist[v] > (d + w)))) {
            (dist[v] = (d + w));
            heap.add(Array<int>{v, dist[v]});
          }
        }
      }
    }
    return (-1);
  }
  static int dijkstra2(int s, int t) {
    for (int i = 1; (i <= n); (i++)) {
      (dist[i] = INF);
      (vis[i] = false);
    }
    heap.clear();
    (dist[s] = 0);
    heap.add(Array<int>{s, 0});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int u = cur[0];
      int d = cur[1];
      if ((u == t)) {
        return d;
      }
      if ((!vis[u])) {
        (vis[u] = true);
        for (int e = head_2[u]; (e > 0); (e = nxt_2[e])) {
          int v = to_2[e];
          int w = weight_2[e];
          if (((!vis[v]) && (dist[v] > (d + w)))) {
            (dist[v] = (d + w));
            heap.add(Array<int>{v, dist[v]});
          }
        }
      }
    }
    return (-1);
  }
  static int random(int v) { return (static_cast<int>((j::random() * v)) + 1); }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (headg[i] = (headp[i] = 0));
    }
    for (int i = 1; (i <= n); (i++)) {
      (head_2[i] = 0);
    }
    (maxc = (cnta = (cntg = (cntp = (cntt = (cnt_2 = 0))))));
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"cdq优化建图，三维偏序"));
    jout.println(String(u"============="));
    (n = 100);
    (m = 1000);
    int valMax = 10;
    int weightMax = 10000;
    int round = 20;
    for (int t = 1; (t <= round); (t++)) {
      jout.println(((String(u"第") + t) + String(u"轮")));
      jout.println(String(u"测试开始"));
      for (int i = 1; (i <= n); (i++)) {
        (a[i] = Code04_Cdq_Optimization_3D_java::random(valMax));
        (b[i] = Code04_Cdq_Optimization_3D_java::random(valMax));
        (c[i] = Code04_Cdq_Optimization_3D_java::random(valMax));
      }
      for (int i = 1; (i <= m); (i++)) {
        int x = Code04_Cdq_Optimization_3D_java::random(n);
        int w = Code04_Cdq_Optimization_3D_java::random(weightMax);
        Code04_Cdq_Optimization_3D_java::addOp(x, x, w);
        Code04_Cdq_Optimization_3D_java::link(x, w);
      }
      Code04_Cdq_Optimization_3D_java::buildGraph();
      for (int x = 1; (x <= n); (x++)) {
        for (int y = 1; (y <= n); (y++)) {
          int ans1 = Code04_Cdq_Optimization_3D_java::dijkstra(x, y);
          int ans2 = Code04_Cdq_Optimization_3D_java::dijkstra2(x, y);
          if ((ans1 != ans2)) {
            jout.println(String(u"出错了!"));
          }
        }
      }
      Code04_Cdq_Optimization_3D_java::clear();
      jout.println(String(u"测试结束"));
      jout.println(String(u"======="));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Cdq_Optimization_3D_java::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// cdq优化建图三维偏序，java版
// 一共n个点，每个点给定三个点权，a[i]、b[i]、c[i]，初始时没有边
// 一共m条操作，格式 x w，每个满足如下要求的点，都向x连权值为w的边
// 三种点权 <= x对应的点权，这样的点就算满足要求，注意x自己也是达标的
// 建好图之后可以测试图的任何算法，比如dijkstra算法求最短路
// 对数器验证
        // i、a、b、c
        // 建图
        // 每个小组的操作列表
        // 树状数组
*/
