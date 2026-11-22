// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4779

// Source: src/class064/Code01_DijkstraLuogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DijkstraLuogu {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> heap = make_array<int>(MAXN);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static int heapSize = {};
  inline static Array<int> distance = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  inline static int s = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DijkstraLuogu() {}
  static void build() {
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
  static void addOrUpdateOrIgnore(int v, int w) {
    if ((where[v] == (-1))) {
      (heap[heapSize] = v);
      (where[v] = (heapSize++));
      (distance[v] = w);
      Code01_DijkstraLuogu::heapInsert(where[v]);
    } else if ((where[v] >= 0)) {
      (distance[v] = jmin(distance[v], w));
      Code01_DijkstraLuogu::heapInsert(where[v]);
    }
  }
  static void heapInsert(int i) {
    while ((distance[heap[i]] < distance[heap[jdiv((i - 1), 2)]])) {
      Code01_DijkstraLuogu::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static int pop() {
    int ans = heap[0];
    Code01_DijkstraLuogu::swap(0, (--heapSize));
    Code01_DijkstraLuogu::heapify(0);
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
      Code01_DijkstraLuogu::swap(best, i);
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
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      in.nextToken();
      (s = static_cast<int>(in.nval));
      Code01_DijkstraLuogu::build();
      {
        int i = 0;
        int u = {};
        int v = {};
        int w = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          in.nextToken();
          (w = static_cast<int>(in.nval));
          Code01_DijkstraLuogu::addEdge(u, v, w);
        }
      }
      Code01_DijkstraLuogu::dijkstra();
      out.print(distance[1]);
      for (int i = 2; (i <= n); (i++)) {
        out.print((String(u" ") + distance[i]));
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
  static void dijkstra() {
    Code01_DijkstraLuogu::addOrUpdateOrIgnore(s, 0);
    while ((!Code01_DijkstraLuogu::isEmpty())) {
      int v = Code01_DijkstraLuogu::pop();
      for (int ei = head[v]; (ei > 0); (ei = next[ei])) {
        Code01_DijkstraLuogu::addOrUpdateOrIgnore(to[ei],
                                                  (distance[v] + weight[ei]));
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DijkstraLuogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Dijkstra算法模版（洛谷）
// 静态空间实现 : 链式前向星 + 反向索引堆
// 测试链接 : https://www.luogu.com.cn/problem/P4779
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 链式前向星
        // 反向索引堆
        // where[v] = -1，表示v这个节点，从来没有进入过堆
        // where[v] = -2，表示v这个节点，已经弹出过了
        // where[v] = i(>=0)，表示v这个节点，在堆上的i位置
        // 链式前向星建图
*/
