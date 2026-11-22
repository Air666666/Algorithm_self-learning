// Source: src/class198/Code01_Fenwick_Tree_Optimization_java.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Fenwick_Tree_Optimization_java {
  inline static int MAXN = 1001;
  inline static int MAXV = 1001;
  inline static int MAXT = 10001;
  inline static int MAXE = 10001;
  inline static int n = {};
  inline static int v = {};
  inline static int cntt = {};
  inline static Array<bool> inBag = make_array<bool>(MAXN);
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static Array<int> weight = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> outTree = make_array<int>(MAXV);
  inline static Array<int> inTree = make_array<int>(MAXV);
  inline static int MAX_2 = 100001;
  inline static Array<bool> in_bag_2 = make_array<bool>(MAX_2);
  inline static Array<int> bag_id = make_array<int>(MAX_2);
  inline static Array<int> bag_val = make_array<int>(MAX_2);
  inline static int bag_siz = {};
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
  Code01_Fenwick_Tree_Optimization_java() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void addOut(int x, int xv) {
    while ((xv <= v)) {
      int preo = outTree[xv];
      int curo = (++cntt);
      if ((preo > 0)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge(preo, curo, 0);
      }
      Code01_Fenwick_Tree_Optimization_java::addEdge(x, curo, 0);
      (outTree[xv] = curo);
      (xv += Code01_Fenwick_Tree_Optimization_java::lowbit(xv));
    }
  }
  static void addIn(int x, int xv) {
    while ((xv <= v)) {
      int prei = inTree[xv];
      int curi = (++cntt);
      if ((prei > 0)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge(curi, prei, 0);
      }
      Code01_Fenwick_Tree_Optimization_java::addEdge(curi, x, 0);
      (inTree[xv] = curi);
      (xv += Code01_Fenwick_Tree_Optimization_java::lowbit(xv));
    }
  }
  static void add(int x, int xv) {
    if ((!inBag[x])) {
      (inBag[x] = true);
      Code01_Fenwick_Tree_Optimization_java::addOut(x, xv);
      Code01_Fenwick_Tree_Optimization_java::addIn(x, xv);
    }
  }
  static void rangeToX(int p, int x, int w) {
    while ((p > 0)) {
      if ((outTree[p] > 0)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge(outTree[p], x, w);
      }
      (p -= Code01_Fenwick_Tree_Optimization_java::lowbit(p));
    }
  }
  static void xToRange(int x, int p, int w) {
    while ((p > 0)) {
      if ((inTree[p] > 0)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge(x, inTree[p], w);
      }
      (p -= Code01_Fenwick_Tree_Optimization_java::lowbit(p));
    }
  }
  static void rangeToRange(int p1, int p2, int w) {
    int x = (++cntt);
    int y = (++cntt);
    Code01_Fenwick_Tree_Optimization_java::rangeToX(p1, x, 0);
    Code01_Fenwick_Tree_Optimization_java::xToRange(y, p2, 0);
    Code01_Fenwick_Tree_Optimization_java::addEdge(x, y, w);
  }
  static void addEdge_2(int u, int v, int w) {
    (nxt_2[(++cnt_2)] = head_2[u]);
    (to_2[cnt_2] = v);
    (weight_2[cnt_2] = w);
    (head_2[u] = cnt_2);
  }
  static void add_2(int x, int xv) {
    if ((!in_bag_2[x])) {
      (in_bag_2[x] = true);
      (bag_id[(++bag_siz)] = x);
      (bag_val[bag_siz] = xv);
    }
  }
  static void rangeToX_2(int p, int x, int w) {
    for (int i = 1; (i <= bag_siz); (i++)) {
      if ((bag_val[i] <= p)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge_2(bag_id[i], x, w);
      }
    }
  }
  static void xToRange_2(int x, int p, int w) {
    for (int i = 1; (i <= bag_siz); (i++)) {
      if ((bag_val[i] <= p)) {
        Code01_Fenwick_Tree_Optimization_java::addEdge_2(x, bag_id[i], w);
      }
    }
  }
  static void rangeToRange_2(int p1, int p2, int w) {
    for (int i = 1; (i <= bag_siz); (i++)) {
      if ((bag_val[i] <= p1)) {
        for (int j = 1; (j <= bag_siz); (j++)) {
          if ((bag_val[j] <= p2)) {
            Code01_Fenwick_Tree_Optimization_java::addEdge_2(bag_id[i],
                                                             bag_id[j], w);
          }
        }
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
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          int w = weight[e];
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
  static int random(int maxv) {
    return (static_cast<int>((j::random() * maxv)) + 1);
  }
  static void clear() {
    for (int i = 1; (i <= cntt); (i++)) {
      (head[i] = 0);
    }
    (cntg = 0);
    (cntt = 0);
    for (int i = 1; (i <= v); (i++)) {
      (inTree[i] = 0);
      (outTree[i] = 0);
    }
    for (int i = 1; (i <= n); (i++)) {
      (inBag[i] = false);
      (in_bag_2[i] = false);
      (head_2[i] = 0);
    }
    (bag_siz = 0);
    (cnt_2 = 0);
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"树状数组优化建图"));
    jout.println(String(u"============"));
    (n = 100);
    (v = 200);
    int weightMax = 1000;
    int round = 20;
    for (int t = 1; (t <= round); (t++)) {
      jout.println(((String(u"第") + t) + String(u"轮")));
      jout.println(String(u"测试开始"));
      (cntt = n);
      int opCnt = 200;
      for (int i = 1; (i <= opCnt); (i++)) {
        int op = Code01_Fenwick_Tree_Optimization_java::random(4);
        if ((op == 1)) {
          int x = Code01_Fenwick_Tree_Optimization_java::random(n);
          int xv = Code01_Fenwick_Tree_Optimization_java::random(v);
          Code01_Fenwick_Tree_Optimization_java::add(x, xv);
          Code01_Fenwick_Tree_Optimization_java::add_2(x, xv);
        } else {
          int p = Code01_Fenwick_Tree_Optimization_java::random(v);
          int p2 = Code01_Fenwick_Tree_Optimization_java::random(v);
          int x = Code01_Fenwick_Tree_Optimization_java::random(n);
          int w = Code01_Fenwick_Tree_Optimization_java::random(weightMax);
          if ((op == 2)) {
            Code01_Fenwick_Tree_Optimization_java::rangeToX(p, x, w);
            Code01_Fenwick_Tree_Optimization_java::rangeToX_2(p, x, w);
          } else if ((op == 3)) {
            Code01_Fenwick_Tree_Optimization_java::xToRange(x, p, w);
            Code01_Fenwick_Tree_Optimization_java::xToRange_2(x, p, w);
          } else {
            Code01_Fenwick_Tree_Optimization_java::rangeToRange(p, p2, w);
            Code01_Fenwick_Tree_Optimization_java::rangeToRange_2(p, p2, w);
          }
        }
      }
      for (int x = 1; (x <= n); (x++)) {
        for (int y = 1; (y <= n); (y++)) {
          int ans1 = Code01_Fenwick_Tree_Optimization_java::dijkstra(x, y);
          int ans2 = Code01_Fenwick_Tree_Optimization_java::dijkstra2(x, y);
          if ((ans1 != ans2)) {
            jout.println(String(u"出错了!"));
          }
        }
      }
      Code01_Fenwick_Tree_Optimization_java::clear();
      jout.println(String(u"测试结束"));
      jout.println(String(u"======="));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Fenwick_Tree_Optimization_java::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树状数组优化建图，java版
// 点的编号范围1~n，点权范围1~v，初始时袋子为空，没有任何边，实现如下方法
// add(x, xv)，编号为x、点权为xv的点进入袋子，该编号已经入袋则忽略
// rangeToX(p, x, w)，袋中点权范围1~p的每个点，向点x连边权为w的边
// xToRange(x, p, w)，点x向袋中点权范围1~p的每个点，连边权为w的边
// rangeToRange(p1, p2, w)，范围向范围连边，具体含义如下
// 袋中点权1~p1的每个点，向袋中点权1~p2的每个点，连边权为w的边
// 建好图之后可以测试图的任何算法，比如dijkstra算法求最短路
// 对数器验证
*/
