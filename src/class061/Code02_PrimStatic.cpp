// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3366

// Source: src/class061/Code02_PrimStatic.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PrimStatic {
  inline static int MAXN = 5001;
  inline static int MAXM = 400001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<Array<int>> heap = make_array<int>(MAXN, 2);
  inline static Array<int> where = make_array<int>(MAXN);
  inline static int heapSize = {};
  inline static int nodeCnt = {};
  inline static int u = {};
  inline static int w = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PrimStatic() {}
  static void build() {
    (cnt = 1);
    (heapSize = 0);
    (nodeCnt = 0);
    j::fill(head, 1, (n + 1), 0);
    j::fill(where, 1, (n + 1), (-1));
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void addOrUpdateOrIgnore(int ei) {
    int v = to[ei];
    int w = weight[ei];
    if ((where[v] == (-1))) {
      (heap[heapSize][0] = v);
      (heap[heapSize][1] = w);
      (where[v] = (heapSize++));
      Code02_PrimStatic::heapInsert(where[v]);
    } else if ((where[v] >= 0)) {
      (heap[where[v]][1] = jmin(heap[where[v]][1], w));
      Code02_PrimStatic::heapInsert(where[v]);
    }
  }
  static void heapInsert(int i) {
    while ((heap[i][1] < heap[jdiv((i - 1), 2)][1])) {
      Code02_PrimStatic::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void pop() {
    (u = heap[0][0]);
    (w = heap[0][1]);
    Code02_PrimStatic::swap(0, (--heapSize));
    Code02_PrimStatic::heapify(0);
    (where[u] = (-2));
    (nodeCnt++);
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)][1] < heap[l][1])) ? (l + 1)
                                                                     : l);
      (best = ((heap[best][1] < heap[i][1]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code02_PrimStatic::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static bool isEmpty() { return (heapSize == 0); }
  static void swap(int i, int j) {
    int a = heap[i][0];
    int b = heap[j][0];
    (where[a] = j);
    (where[b] = i);
    Array<int> tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code02_PrimStatic::build();
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
          Code02_PrimStatic::addEdge(u, v, w);
          Code02_PrimStatic::addEdge(v, u, w);
        }
      }
      int ans = Code02_PrimStatic::prim();
      out.println(((nodeCnt == n) ? j::str(ans) : String(u"orz")));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int prim() {
    (nodeCnt = 1);
    (where[1] = (-2));
    for (int ei = head[1]; (ei > 0); (ei = next[ei])) {
      Code02_PrimStatic::addOrUpdateOrIgnore(ei);
    }
    int ans = 0;
    while ((!Code02_PrimStatic::isEmpty())) {
      Code02_PrimStatic::pop();
      (ans += w);
      for (int ei = head[u]; (ei > 0); (ei = next[ei])) {
        Code02_PrimStatic::addOrUpdateOrIgnore(ei);
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PrimStatic::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Prim算法优化（洛谷）
// 静态空间实现
// 时间复杂度O(n + m) + O((m+n) * log n)
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
// 建图用链式前向星
// 堆也是用数组结构手写的、且只和节点个数有关
// 这个实现留给有需要的同学
// 但是一般情况下并不需要做到这个程度
        // 链式前向星建图
        // 改写的堆结构
        // where[v] = -1，表示v这个节点，从来没有进入过堆
        // where[v] = -2，表示v这个节点，已经弹出过了
        // where[v] = i(>=0)，表示v这个节点，在堆上的i位置
        // 堆的大小
        // 找到的节点个数
        // 当前处理的是编号为ei的边！
                // 去往v点，权重w
                        // v这个点，从来没有进入过堆！
                        // v这个点的记录，在堆上的位置是where[v]
        // 堆顶的记录：节点 -> u、到节点的花费 -> w
        // 堆上，i位置的信息 和 j位置的信息 交换！
                // 1节点出发
*/
