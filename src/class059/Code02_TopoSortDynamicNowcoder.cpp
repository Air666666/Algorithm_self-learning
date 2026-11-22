// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/88f7e156ca7d43a1a535f619cd3f495c

// Source: src/class059/Code02_TopoSortDynamicNowcoder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TopoSortDynamicNowcoder {
  inline static int MAXN = 200001;
  inline static Array<int> queue = make_array<int>(MAXN);
  inline static int l = {};
  inline static int r = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TopoSortDynamicNowcoder() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      JList<JList<int>> graph = JList<JList<int>>();
      for (int i = 0; (i <= n); (i++)) {
        graph.add(JList<int>());
      }
      j::fill(indegree, 0, (n + 1), 0);
      {
        int i = 0;
        int from = {};
        int to = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (from = static_cast<int>(in.nval));
          in.nextToken();
          (to = static_cast<int>(in.nval));
          graph.get(from).add(to);
          (indegree[to]++);
        }
      }
      if ((!Code02_TopoSortDynamicNowcoder::topoSort(graph))) {
        out.println((-1));
      } else {
        for (int i = 0; (i < (n - 1)); (i++)) {
          out.print((ans[i] + String(u" ")));
        }
        out.println(ans[(n - 1)]);
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static bool topoSort(JList<JList<int>> graph) {
    (l = (r = 0));
    for (int i = 1; (i <= n); (i++)) {
      if ((indegree[i] == 0)) {
        (queue[(r++)] = i);
      }
    }
    int fill = 0;
    while ((l < r)) {
      int cur = queue[(l++)];
      (ans[(fill++)] = cur);
      for (int next : graph.get(cur)) {
        if (((--indegree[next]) == 0)) {
          (queue[(r++)] = next);
        }
      }
    }
    return (fill == n);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TopoSortDynamicNowcoder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 拓扑排序模版（牛客）
// 邻接表建图（动态方式）
// 测试链接 : https://www.nowcoder.com/practice/88f7e156ca7d43a1a535f619cd3f495c
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 拓扑排序，用到队列
        // 拓扑排序，入度表
        // 收集拓扑排序的结果
                        // 动态建图，比赛肯定不行，但是一般大厂笔试、面试允许
        // 有拓扑排序返回true
        // 没有拓扑排序返回false
*/
