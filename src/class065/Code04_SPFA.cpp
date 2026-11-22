// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3385

// Source: src/class065/Code04_SPFA.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SPFA {
  inline static int MAXN = 2001;
  inline static int MAXM = 6001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static int MAXQ = 4000001;
  inline static Array<int> distance = make_array<int>(MAXN);
  inline static Array<int> updateCnt = make_array<int>(MAXN);
  inline static Array<int> queue = make_array<int>(MAXQ);
  inline static int l = {};
  inline static int r = {};
  inline static Array<bool> enter = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SPFA() {}
  static void build(int n) {
    (cnt = 1);
    (l = (r = 0));
    j::fill(head, 1, (n + 1), 0);
    j::fill(enter, 1, (n + 1), false);
    j::fill(distance, 1, (n + 1), std::numeric_limits<int>::max());
    j::fill(updateCnt, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    {
      int i = 0;
      int n = {};
      int m = {};
      for (; (i < cases); (i++)) {
        in.nextToken();
        (n = static_cast<int>(in.nval));
        in.nextToken();
        (m = static_cast<int>(in.nval));
        Code04_SPFA::build(n);
        {
          int j = 0;
          int u = {};
          int v = {};
          int w = {};
          for (; (j < m); (j++)) {
            in.nextToken();
            (u = static_cast<int>(in.nval));
            in.nextToken();
            (v = static_cast<int>(in.nval));
            in.nextToken();
            (w = static_cast<int>(in.nval));
            if ((w >= 0)) {
              Code04_SPFA::addEdge(u, v, w);
              Code04_SPFA::addEdge(v, u, w);
            } else {
              Code04_SPFA::addEdge(u, v, w);
            }
          }
        }
        out.println((Code04_SPFA::spfa(n) ? String(u"YES") : String(u"NO")));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static bool spfa(int n) {
    (distance[1] = 0);
    (updateCnt[1]++);
    (queue[(r++)] = 1);
    (enter[1] = true);
    while ((l < r)) {
      int u = queue[(l++)];
      (enter[u] = false);
      {
        int ei = head[u];
        int v = {};
        int w = {};
        for (; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          (w = weight[ei]);
          if (((distance[u] + w) < distance[v])) {
            (distance[v] = (distance[u] + w));
            if ((!enter[v])) {
              if (((++updateCnt[v]) > (n - 1))) {
                return true;
              }
              (queue[(r++)] = v);
              (enter[v] = true);
            }
          }
        }
      }
    }
    return false;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SPFA::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Bellman-Ford + SPFA优化模版（洛谷）
// 给定n个点的有向图，请求出图中是否存在从顶点1出发能到达的负环
// 负环的定义是：一条边权之和为负数的回路
// 测试链接 : https://www.luogu.com.cn/problem/P3385
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
        // 链式前向星建图需要
        // SPFA需要
        // 源点出发到每个节点的距离表
        // 节点被松弛的次数
        // 哪些节点被松弛了放入队列
        // 节点是否已经在队列中
        // Bellman-Ford + SPFA优化的模版
                                                // 松弛次数超过n-1就有负环
*/
