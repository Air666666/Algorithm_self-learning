// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3366

// Source: src/class061/Code02_PrimDynamic.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PrimDynamic {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PrimDynamic() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      JList<JList<Array<int>>> graph = JList<JList<Array<int>>>();
      int n = static_cast<int>(in.nval);
      for (int i = 0; (i <= n); (i++)) {
        graph.add(JList<Array<int>>());
      }
      in.nextToken();
      int m = static_cast<int>(in.nval);
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
          graph.get(u).add(Array<int>{v, w});
          graph.get(v).add(Array<int>{u, w});
        }
      }
      JHeap<Array<int>> heap = JHeap<Array<int>>(
          [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
      for (Array<int> edge : graph.get(1)) {
        heap.add(edge);
      }
      Array<bool> set = make_array<bool>((n + 1));
      int nodeCnt = 1;
      (set[1] = true);
      int ans = 0;
      while ((!heap.isEmpty())) {
        Array<int> edge = heap.poll();
        int next = edge[0];
        int cost = edge[1];
        if ((!set[next])) {
          (nodeCnt++);
          (set[next] = true);
          (ans += cost);
          for (Array<int> e : graph.get(next)) {
            heap.add(e);
          }
        }
      }
      out.println(((nodeCnt == n) ? j::str(ans) : String(u"orz")));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PrimDynamic::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Prim算法模版（洛谷）
// 动态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
// 时间复杂度O(n + m) + O(m * log m)
                        // int[] record
                        // record[0] : 到达的节点
                        // record[1] : 到达的花费
                        // 哪些节点已经发现过了
*/
