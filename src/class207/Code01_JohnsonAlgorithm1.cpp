// Source: src/class207/Code01_JohnsonAlgorithm1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_JohnsonAlgorithm1 {
  inline static int MAXN = 10001;
  inline static int MAXQ = 5000001;
  inline static int INF = 1000000000;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> h = make_array<int>(MAXN);
  inline static Array<int> update = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static Array<int> que = make_array<int>(MAXQ);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> heap = make_array<int>(MAXN);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static int heapSize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_JohnsonAlgorithm1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void swap(int i, int j) {
    int tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
    (where[heap[i]] = i);
    (where[heap[j]] = j);
  }
  static void heapInsert(int i) {
    while ((dist[heap[i]] < dist[heap[jdiv((i - 1), 2)]])) {
      Code01_JohnsonAlgorithm1::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (dist[heap[(l + 1)]] < dist[heap[l]]))
               ? (l + 1)
               : l);
      (best = ((dist[heap[best]] < dist[heap[i]]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code01_JohnsonAlgorithm1::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static bool isEmpty() { return (heapSize == 0); }
  static int pop() {
    int ans = heap[0];
    Code01_JohnsonAlgorithm1::swap(0, (--heapSize));
    Code01_JohnsonAlgorithm1::heapify(0);
    (where[ans] = (-2));
    return ans;
  }
  static void addOrUpdateOrIgnore(int v, int d) {
    if (((where[v] == (-2)) || (dist[v] <= d))) {
      return;
    }
    if ((where[v] == (-1))) {
      (heap[heapSize] = v);
      (where[v] = (heapSize++));
    }
    (dist[v] = d);
    Code01_JohnsonAlgorithm1::heapInsert(where[v]);
  }
  static bool spfa(int s) {
    for (int i = 1; (i <= n); (i++)) {
      (h[i] = INF);
    }
    (h[s] = 0);
    (update[s] = 1);
    (enter[s] = true);
    int ql = 1;
    int qr = 0;
    (que[(++qr)] = s);
    while ((ql <= qr)) {
      int u = que[(ql++)];
      (enter[u] = false);
      {
        int ei = head[u];
        int v = {};
        int w = {};
        for (; (ei > 0); (ei = nxt[ei])) {
          (v = to[ei]);
          (w = weight[ei]);
          if ((h[v] > (h[u] + w))) {
            (h[v] = (h[u] + w));
            if ((!enter[v])) {
              if (((++update[v]) > n)) {
                return true;
              }
              (que[(++qr)] = v);
              (enter[v] = true);
            }
          }
        }
      }
    }
    return false;
  }
  static void dijkstra(int s) {
    for (int i = 1; (i <= n); (i++)) {
      (dist[i] = INF);
      (where[i] = (-1));
    }
    (heapSize = 0);
    Code01_JohnsonAlgorithm1::addOrUpdateOrIgnore(s, 0);
    while ((!Code01_JohnsonAlgorithm1::isEmpty())) {
      int u = Code01_JohnsonAlgorithm1::pop();
      int d = dist[u];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        Code01_JohnsonAlgorithm1::addOrUpdateOrIgnore(to[e], (d + weight[e]));
      }
    }
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
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code01_JohnsonAlgorithm1::addEdge(u, v, w);
      }
    }
    int virtualNode = 0;
    for (int i = 1; (i <= n); (i++)) {
      Code01_JohnsonAlgorithm1::addEdge(virtualNode, i, 0);
    }
    if (Code01_JohnsonAlgorithm1::spfa(virtualNode)) {
      out.println(String(u"-1"));
    } else {
      for (int u = 1; (u <= n); (u++)) {
        for (int e = head[u]; (e > 0); (e = nxt[e])) {
          int v = to[e];
          (weight[e] += (h[u] - h[v]));
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        Code01_JohnsonAlgorithm1::dijkstra(i);
        i64 ans = 0;
        for (int j = 1; (j <= n); (j++)) {
          if ((dist[j] == INF)) {
            (ans += ((1LL * j) * INF));
          } else {
            (ans += ((1LL * j) * ((dist[j] - h[i]) + h[j])));
          }
        }
        out.println(ans);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_JohnsonAlgorithm1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Johnson全源最短路，java版
// 一共n个点，m条有向边，边有边权，可能有负边、重边、自环
// 如果图中存在负环，打印-1即可，否则计算任意两点的最短距离
// 如果不存在通路，认为距离是10^9，每个点到自己的距离认为是0
// 无负环时，输出n行结果，点i到点j的最短距离记为dist(i, j)
// 第i行的输出 = 累加所有 { dist(i, j) * j }，1 <= j <= n
// 1 <= n <= 3 * 10^3
// 1 <= m <= 6 * 10^3
// -3 * 10^5 <= 边权 <= +3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5905
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// java的实现，反向索引堆实现的Dijkstra算法，才能通过，讲解064讲了
// C++的实现，普通堆实现的Dijkstra算法，可以直接通过
        // 建图
        // spfa
        // dijkstra，反向索引堆优化
        // where[v] = -1，表示v这个节点，从来没有进入过堆
        // where[v] = -2，表示v这个节点，已经弹出过了
        // where[v] >= 0，表示v这个节点在堆上的位置
        // 返回是否发现了负环
        // dijkstra算法，反向索引堆优化，讲解064
        // 读写工具类
*/
