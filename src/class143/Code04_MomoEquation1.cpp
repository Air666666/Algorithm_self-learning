// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2371

// Source: src/class143/Code04_MomoEquation1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MomoEquation1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 5000001;
  inline static int n = {};
  inline static int x = {};
  inline static i64 l = {};
  inline static i64 r = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<i64> weight = make_array<i64>(MAXM);
  inline static int cnt = {};
  inline static JHeap<Array<i64>> heap = JHeap<Array<i64>>(
      [](Array<i64> a, Array<i64> b) { return jcompare(a[1], b[1]); });
  inline static Array<i64> distance = make_array<i64>(MAXN);
  inline static Array<bool> visited = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MomoEquation1() {}
  static void prepare() {
    (cnt = 1);
    heap.clear();
    j::fill(head, 0, x, 0);
    j::fill(distance, 0, x, std::numeric_limits<i64>::max());
    j::fill(visited, 0, x, false);
  }
  static void addEdge(int u, int v, i64 w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void dijkstra() {
    heap.add(Array<i64>{0, 0});
    (distance[0] = 0);
    Array<i64> cur = {};
    int u = {};
    i64 w = {};
    while ((!heap.isEmpty())) {
      (cur = heap.poll());
      (u = static_cast<int>(cur[0]));
      (w = cur[1]);
      if (visited[u]) {
        continue;
      }
      (visited[u] = true);
      {
        int ei = head[u];
        int v = {};
        for (; (ei > 0); (ei = next[ei])) {
          (v = to[ei]);
          if (((!visited[v]) && (distance[v] > (w + weight[ei])))) {
            (distance[v] = (w + weight[ei]));
            heap.add(Array<i64>{v, distance[v]});
          }
        }
      }
    }
  }
  static i64 compute() {
    Code04_MomoEquation1::dijkstra();
    i64 ans = 0;
    for (int i = 0; (i < x); (i++)) {
      if ((r >= distance[i])) {
        (ans += (jdiv((r - distance[i]), x) + 1));
      }
      if ((l >= distance[i])) {
        (ans -= (jdiv((l - distance[i]), x) + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (l = (static_cast<i64>(in.nval) - 1));
    in.nextToken();
    (r = static_cast<i64>(in.nval));
    (x = 0);
    {
      int i = 1;
      int vi = {};
      for (; (i <= n); (i++)) {
        in.nextToken();
        (vi = static_cast<int>(in.nval));
        if ((vi != 0)) {
          if ((x == 0)) {
            (x = vi);
            Code04_MomoEquation1::prepare();
          } else {
            for (int j = 0; (j < x); (j++)) {
              Code04_MomoEquation1::addEdge(j, jrem((j + vi), x), vi);
            }
          }
        }
      }
    }
    out.println(Code04_MomoEquation1::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_MomoEquation1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 墨墨的等式(dijkstra算法)
// 一共有n种正数，每种数可以选择任意个，个数不能是负数
// 那么一定有某些数值可以由这些数字累加得到
// 请问在[l...r]范围上，有多少个数能被累加得到
// 0 <= n <= 12
// 0 <= 数值范围 <= 5 * 10^5
// 1 <= l <= r <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P2371
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // dijkstra算法需要
        // 0 : 当前节点
        // 1 : 源点到当前点距离
*/
