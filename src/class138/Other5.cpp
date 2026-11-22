// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4322

// Source: src/class138/Other5.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Other5 {
  inline static int MAXN = 3001;
  inline static int LIMIT = 10000;
  inline static double NA = (-1e9);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(MAXN);
  inline static Array<int> to = make_array<int>(MAXN);
  inline static int edgeCnt = {};
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<int> strength = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<Array<double>> dp = make_array<double>(MAXN, MAXN);
  inline static int k = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Other5() {}
  static void prepare() {
    (edgeCnt = 1);
    (dfnCnt = 0);
    j::fill(head, 1, (n + 1), 0);
  }
  static void addEdge(int u, int v) {
    (next[edgeCnt] = head[u]);
    (to[edgeCnt] = v);
    (head[u] = (edgeCnt++));
  }
  static int dfs(int u) {
    int i = (++dfnCnt);
    (dfn[u] = i);
    (size[i] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        (size[i] += Other5::dfs(v));
      }
    }
    return size[i];
  }
  static bool check(double x) {
    for (int i = 0; (i <= n); (i++)) {
      (value[dfn[i]] = (static_cast<double>(strength[i]) - (x * cost[i])));
    }
    for (int j = 1; (j <= k); (j++)) {
      (dp[(dfnCnt + 1)][j] = NA);
    }
    for (int i = dfnCnt; (i >= 2); (i--)) {
      for (int j = 1; (j <= k); (j++)) {
        (dp[i][j] =
             jmax(dp[(i + size[i])][j], (value[i] + dp[(i + 1)][(j - 1)])));
      }
    }
    return (dp[2][k] >= 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    Other5::prepare();
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (cost[i] = static_cast<int>(in.nval));
      in.nextToken();
      (strength[i] = static_cast<int>(in.nval));
      in.nextToken();
      Other5::addEdge(static_cast<int>(in.nval), i);
    }
    Other5::dfs(0);
    double l = 0;
    double r = LIMIT;
    double x = {};
    for (int i = 1; (i <= 60); (i++)) {
      (x = jdiv((l + r), 2));
      if (Other5::check(x)) {
        (l = x);
      } else {
        (r = x);
      }
    }
    out.printf(String(u"%.3f\n"), l);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Other5::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目5，最佳团体，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : https://www.luogu.com.cn/problem/P4322
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 二分进行60次，足够达到题目要求的精度
                // 二分完成后，l就是答案
*/
