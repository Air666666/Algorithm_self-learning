// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/network-delay-time

// Source: src/class064/Code01_DijkstraLeetcode.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DijkstraLeetcode {
  inline static int MAXN = 101;
  inline static int MAXM = 6001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> heap = make_array<int>(MAXN);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static int heapSize = {};
  inline static Array<int> distance = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DijkstraLeetcode() {}
  static int networkDelayTime1(Array<Array<int>> times, int n, int s) {
    JList<JList<Array<int>>> graph = JList<JList<Array<int>>>();
    for (int i = 0; (i <= n); (i++)) {
      graph.add(JList<Array<int>>());
    }
    for (Array<int> edge : times) {
      graph.get(edge[0]).add(Array<int>{edge[1], edge[2]});
    }
    Array<int> distance = make_array<int>((n + 1));
    j::fill(distance, std::numeric_limits<int>::max());
    (distance[s] = 0);
    Array<bool> visited = make_array<bool>((n + 1));
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    heap.add(Array<int>{s, 0});
    while ((!heap.isEmpty())) {
      int u = heap.poll()[0];
      if (visited[u]) {
        continue;
      }
      (visited[u] = true);
      for (Array<int> edge : graph.get(u)) {
        int v = edge[0];
        int w = edge[1];
        if (((!visited[v]) && ((distance[u] + w) < distance[v]))) {
          (distance[v] = (distance[u] + w));
          heap.add(Array<int>{v, (distance[u] + w)});
        }
      }
    }
    int ans = std::numeric_limits<int>::min();
    for (int i = 1; (i <= n); (i++)) {
      if ((distance[i] == std::numeric_limits<int>::max())) {
        return (-1);
      }
      (ans = jmax(ans, distance[i]));
    }
    return ans;
  }
  static int networkDelayTime2(Array<Array<int>> times, int n, int s) {
    Code01_DijkstraLeetcode::build(n);
    for (Array<int> edge : times) {
      Code01_DijkstraLeetcode::addEdge(edge[0], edge[1], edge[2]);
    }
    Code01_DijkstraLeetcode::addOrUpdateOrIgnore(s, 0);
    while ((!Code01_DijkstraLeetcode::isEmpty())) {
      int u = Code01_DijkstraLeetcode::pop();
      for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
        Code01_DijkstraLeetcode::addOrUpdateOrIgnore(
            to[ei], (distance[u] + weight[ei]));
      }
    }
    int ans = std::numeric_limits<int>::min();
    for (int i = 1; (i <= n); (i++)) {
      if ((distance[i] == std::numeric_limits<int>::max())) {
        return (-1);
      }
      (ans = jmax(ans, distance[i]));
    }
    return ans;
  }
  static void build(int n) {
    (cnt = 1);
    (heapSize = 0);
    j::fill(head, 1, (n + 1), 0);
    j::fill(where, 1, (n + 1), (-1));
    j::fill(distance, 1, (n + 1), std::numeric_limits<int>::max());
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void addOrUpdateOrIgnore(int v, int c) {
    if ((where[v] == (-1))) {
      (heap[heapSize] = v);
      (where[v] = (heapSize++));
      (distance[v] = c);
      Code01_DijkstraLeetcode::heapInsert(where[v]);
    } else if ((where[v] >= 0)) {
      (distance[v] = jmin(distance[v], c));
      Code01_DijkstraLeetcode::heapInsert(where[v]);
    }
  }
  static void heapInsert(int i) {
    while ((distance[heap[i]] < distance[heap[jdiv((i - 1), 2)]])) {
      Code01_DijkstraLeetcode::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static int pop() {
    int ans = heap[0];
    Code01_DijkstraLeetcode::swap(0, (--heapSize));
    Code01_DijkstraLeetcode::heapify(0);
    (where[ans] = (-2));
    return ans;
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best = ((((l + 1) < heapSize) &&
                   (distance[heap[(l + 1)]] < distance[heap[l]]))
                      ? (l + 1)
                      : l);
      (best = ((distance[heap[best]] < distance[heap[i]]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code01_DijkstraLeetcode::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static bool isEmpty() { return (heapSize == 0); }
  static void swap(int i, int j) {
    int tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
    (where[heap[i]] = i);
    (where[heap[j]] = j);
  }
};

/* Original teaching comments:
// Dijkstra算法模版（Leetcode）
// 网络延迟时间
// 有 n 个网络节点，标记为 1 到 n
// 给你一个列表 times，表示信号经过 有向 边的传递时间
// times[i] = (ui, vi, wi)，表示从ui到vi传递信号的时间是wi
// 现在，从某个节点 s 发出一个信号
// 需要多久才能使所有节点都收到信号
// 如果不能使所有节点收到信号，返回 -1
// 测试链接 : https://leetcode.cn/problems/network-delay-time
        // 动态建图+普通堆的实现
                // 0 : 当前节点
                // 1 : 源点到当前点距离
        // 链式前向星+反向索引堆的实现
        // 链式前向星
        // 反向索引堆
        // where[v] = -1，表示v这个节点，从来没有进入过堆
        // where[v] = -2，表示v这个节点，已经弹出过了
        // where[v] = i(>=0)，表示v这个节点，在堆上的i位置
        // 链式前向星建图
*/
