// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=3001

// Source: src/class126/Code03_TspTwice.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TspTwice {
  inline static int MAXN = 10;
  inline static int MAXS = static_cast<int>(std::pow(3, MAXN));
  inline static int n = {};
  inline static int m = {};
  inline static int maxs = {};
  inline static Array<Array<int>> graph = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXS);
  inline static Array<int> complete = make_array<int>(jshl(1, MAXN));
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TspTwice() {}
  static void build() {
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        (graph[i][j] = std::numeric_limits<int>::max());
      }
    }
    (maxs = static_cast<int>(std::pow(3, n)));
    for (int i = 0; (i < n); (i++)) {
      for (int s = 0; (s < maxs); (s++)) {
        (dp[i][s] = (-1));
      }
    }
    (size = 0);
    Code03_TspTwice::dfs(0, 1, 0);
  }
  static void dfs(int i, int bit, int s) {
    if ((i == n)) {
      (complete[(size++)] = s);
    } else {
      Code03_TspTwice::dfs((i + 1), (bit * 3), (s + bit));
      Code03_TspTwice::dfs((i + 1), (bit * 3), (s + (2 * bit)));
    }
  }
  static int compute() {
    int ans = std::numeric_limits<int>::max();
    for (int k = 0; (k < size); (k++)) {
      {
        int i = 0;
        int bit = 1;
        for (; (i < n); (i++), (bit *= 3)) {
          (ans = jmin(ans, Code03_TspTwice::f(i, (complete[k] - bit))));
        }
      }
    }
    return ans;
  }
  static int f(int i, int s) {
    if ((s == 0)) {
      return 0;
    }
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int ans = std::numeric_limits<int>::max();
    {
      int j = 0;
      int bit = 1;
      int pre = {};
      for (; (j < n); (j++), (bit *= 3)) {
        if ((jrem(jdiv(s, bit), 3) > 0)) {
          (pre = Code03_TspTwice::f(j, (s - bit)));
          if (((pre != std::numeric_limits<int>::max()) &&
               (graph[j][i] != std::numeric_limits<int>::max()))) {
            (ans = jmin(ans, (pre + graph[j][i])));
          }
        }
      }
    }
    (dp[i][s] = ans);
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      Code03_TspTwice::build();
      {
        int i = 1;
        int u = {};
        int v = {};
        int w = {};
        for (; (i <= m); (i++)) {
          in.nextToken();
          (u = (static_cast<int>(in.nval) - 1));
          in.nextToken();
          (v = (static_cast<int>(in.nval) - 1));
          in.nextToken();
          (w = static_cast<int>(in.nval));
          if ((w < graph[u][v])) {
            (graph[u][v] = (graph[v][u] = w));
          }
        }
      }
      int ans = Code03_TspTwice::compute();
      out.println(((ans == std::numeric_limits<int>::max()) ? (-1) : ans));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TspTwice::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 节点最多经过两次的tsp问题
// 给定有n个地点，用m条边无向边连接，每条边有权值
// 你可以任选一点出发，目标是经过所有的点，最终不必回到出发点
// 并且每个点最多可以到达两次
// 返回总路程最小是多少
// 1 <= n <= 10
// 1 <= m <= 100
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=3001
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/
