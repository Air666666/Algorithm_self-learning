// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4017

// Source: src/class060/Code01_FoodLines.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FoodLines {
  inline static int MAXN = 5001;
  inline static int MAXM = 500001;
  inline static int MOD = 80112002;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static Array<int> queue = make_array<int>(MAXN);
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> lines = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FoodLines() {}
  static void build(int n) {
    (cnt = 1);
    j::fill(indegree, 0, (n + 1), 0);
    j::fill(lines, 0, (n + 1), 0);
    j::fill(head, 0, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code01_FoodLines::build(n);
      {
        int i = 0;
        int u = {};
        int v = {};
        for (; (i < m); (i++)) {
          in.nextToken();
          (u = static_cast<int>(in.nval));
          in.nextToken();
          (v = static_cast<int>(in.nval));
          Code01_FoodLines::addEdge(u, v);
          (indegree[v]++);
        }
      }
      out.println(Code01_FoodLines::ways());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int ways() {
    int l = 0;
    int r = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((indegree[i] == 0)) {
        (queue[(r++)] = i);
        (lines[i] = 1);
      }
    }
    int ans = 0;
    while ((l < r)) {
      int u = queue[(l++)];
      if ((head[u] == 0)) {
        (ans = jrem((ans + lines[u]), MOD));
      } else {
        {
          int ei = head[u];
          int v = {};
          for (; (ei > 0); (ei = next[ei])) {
            (v = to[ei]);
            (lines[v] = jrem((lines[v] + lines[u]), MOD));
            if (((--indegree[v]) == 0)) {
              (queue[(r++)] = v);
            }
          }
        }
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_FoodLines::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大食物链计数
// a -> b，代表a在食物链中被b捕食
// 给定一个有向无环图，返回
// 这个图中从最初级动物到最顶级捕食者的食物链有几条
// 测试链接 : https://www.luogu.com.cn/problem/P4017
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 链式前向星建图
        // 拓扑排序需要的队列
        // 拓扑排序需要的入度表
        // 拓扑排序需要的推送信息
                                // 当前的u节点不再有后续邻居了
                                        // u -> v
*/
