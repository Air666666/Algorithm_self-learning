// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/U107394

// Source: src/class059/Code03_TopoSortStaticLuogu.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TopoSortStaticLuogu {
  inline static int MAXN = 100001;
  inline static int MAXM = 100001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> heap = make_array<int>(MAXN);
  inline static int heapSize = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TopoSortStaticLuogu() {}
  static void build(int n) {
    (cnt = 1);
    (heapSize = 0);
    j::fill(head, 0, (n + 1), 0);
    j::fill(indegree, 0, (n + 1), 0);
  }
  static void addEdge(int f, int t) {
    (next[cnt] = head[f]);
    (to[cnt] = t);
    (head[f] = (cnt++));
  }
  static void push(int num) {
    int i = (heapSize++);
    (heap[i] = num);
    while ((heap[i] < heap[jdiv((i - 1), 2)])) {
      Code03_TopoSortStaticLuogu::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static int pop() {
    int ans = heap[0];
    (heap[0] = heap[(--heapSize)]);
    int i = 0;
    int l = 1;
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)] < heap[l])) ? (l + 1) : l);
      (best = ((heap[best] < heap[i]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code03_TopoSortStaticLuogu::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
    return ans;
  }
  static bool isEmpty() { return (heapSize == 0); }
  static void swap(int i, int j) {
    int tmp = heap[i];
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
      Code03_TopoSortStaticLuogu::build(n);
      {
        int i = 0;
        int from = {};
        int to = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (from = static_cast<int>(in.nval));
          in.nextToken();
          (to = static_cast<int>(in.nval));
          Code03_TopoSortStaticLuogu::addEdge(from, to);
          (indegree[to]++);
        }
      }
      Code03_TopoSortStaticLuogu::topoSort();
      for (int i = 0; (i < (n - 1)); (i++)) {
        out.print((ans[i] + String(u" ")));
      }
      out.println(ans[(n - 1)]);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void topoSort() {
    for (int i = 1; (i <= n); (i++)) {
      if ((indegree[i] == 0)) {
        Code03_TopoSortStaticLuogu::push(i);
      }
    }
    int fill = 0;
    while ((!Code03_TopoSortStaticLuogu::isEmpty())) {
      int cur = Code03_TopoSortStaticLuogu::pop();
      (ans[(fill++)] = cur);
      for (int ei = head[cur]; (ei != 0); (ei = next[ei])) {
        if (((--indegree[to[ei]]) == 0)) {
          Code03_TopoSortStaticLuogu::push(to[ei]);
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TopoSortStaticLuogu::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 字典序最小的拓扑排序
// 要求返回所有正确的拓扑排序中 字典序最小 的结果
// 建图请使用链式前向星方式，因为比赛平台用其他建图方式会卡空间
// 测试链接 : https://www.luogu.com.cn/problem/U107394
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 建图相关，链式前向星
        // 拓扑排序，不用队列，用小根堆，为了得到字典序最小的拓扑排序
        // 拓扑排序，入度表
        // 收集拓扑排序的结果
        // 清理之前的脏数据
        // 用链式前向星建图
        // 小根堆里加入数字
                // heapInsert的过程
        // 小根堆里弹出最小值
                // heapify的过程
        // 判断小根堆是否为空
        // 交换堆上两个位置的数字
                        // 用链式前向星的方式，遍历cur的相邻节点
*/
