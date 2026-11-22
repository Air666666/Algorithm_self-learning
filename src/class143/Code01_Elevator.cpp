// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3403
// https://oi-wiki.org/lang/java-pro/

// Source: src/class143/Code01_Elevator.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Elevator {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static i64 h = {};
  inline static int x = {};
  inline static int y = {};
  inline static int z = {};
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
  Code01_Elevator() {}
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
    Code01_Elevator::dijkstra();
    i64 ans = 0;
    for (int i = 0; (i < x); (i++)) {
      if ((distance[i] <= h)) {
        (ans += (jdiv((h - distance[i]), x) + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO io = IO();
    (h = (io.nextLong() - 1));
    (x = io.nextInt());
    (y = io.nextInt());
    (z = io.nextInt());
    Code01_Elevator::prepare();
    for (int i = 0; (i < x); (i++)) {
      Code01_Elevator::addEdge(i, jrem((i + y), x), y);
      Code01_Elevator::addEdge(i, jrem((i + z), x), z);
    }
    io.println(Code01_Elevator::compute());
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Elevator::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 跳楼机
// 一座大楼一共有h层，楼层编号1~h，有如下四种移动方式
// 1, 向上移动x层
// 2, 向上移动y层
// 3, 向上移动z层
// 4, 回到1层
// 假设你正在第1层，请问大楼里有多少楼层你可以到达
// 1 <= h <= 2^63 - 1
// 1 <= x、y、z <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3403
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // dijkstra算法需要
        // 0 : 当前节点
        // 1 : 源点到当前点距离
        // 来自讲解064，dijkstra算法
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
*/
