// Source: src/class143/Code02_CattleFence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CattleFence {
  inline static int MAXN = 101;
  inline static int MAXV = 3001;
  inline static int MAXM = 30001;
  inline static int inf = std::numeric_limits<int>::max();
  inline static int n = {};
  inline static int m = {};
  inline static int x = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<bool> set = make_array<bool>(MAXV);
  inline static Array<int> head = make_array<int>(MAXV);
  inline static Array<int> next = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cnt = {};
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  inline static Array<int> distance = make_array<int>(MAXV);
  inline static Array<bool> visited = make_array<bool>(MAXV);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CattleFence() {}
  static void prepare() {
    (cnt = 1);
    heap.clear();
    j::fill(set, false);
    j::fill(head, 0, x, 0);
    j::fill(distance, 0, x, inf);
    j::fill(visited, 0, x, false);
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void dijkstra() {
    heap.add(Array<int>{0, 0});
    (distance[0] = 0);
    Array<int> cur = {};
    int u = {};
    int w = {};
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
            heap.add(Array<int>{v, distance[v]});
          }
        }
      }
    }
  }
  static int compute() {
    int ans = 0;
    if ((x == 1)) {
      (ans = (-1));
    } else {
      for (int i = 1; (i <= n); (i++)) {
        for (int j = jmax(1, (arr[i] - m)); (j <= arr[i]); (j++)) {
          if ((!set[j])) {
            (set[j] = true);
            for (int k = 0; (k < x); (k++)) {
              Code02_CattleFence::addEdge(k, jrem((k + j), x), j);
            }
          }
        }
      }
      Code02_CattleFence::dijkstra();
      for (int i = 1; (i < x); (i++)) {
        if ((distance[i] == inf)) {
          (ans = (-1));
          break;
        }
        (ans = jmax(ans, (distance[i] - x)));
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
    (m = static_cast<int>(in.nval));
    (x = inf);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
      (x = jmin(x, jmax(1, (arr[i] - m))));
    }
    Code02_CattleFence::prepare();
    out.println(Code02_CattleFence::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CattleFence::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 牛场围栏
// 给定一个长度为n的数组arr, arr[i]代表第i种木棍的长度，每种木棍有无穷多个
//
给定一个正数m，表示你可以把任何一根木棍消去最多m的长度，同一种木棍可以消去不同的长度
// 你可以随意拼接木棍形成一个长度，返回不能拼出来的长度中，最大值是多少
// 如果你可以拼出所有的长度，返回-1
// 如果不能拼出来的长度有无穷多，返回-1
// 1 <= n <= 100
// 1 <= arr[i] <= 3000
// 1 <= m <= 3000
// 测试链接 : https://www.luogu.com.cn/problem/P2662
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星需要
        // dijkstra算法需要
        // 0 : 当前节点
        // 1 : 源点到当前点距离
        // 来自讲解064，dijkstra算法
*/
