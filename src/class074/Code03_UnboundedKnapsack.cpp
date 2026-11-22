// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1616

// Source: src/class074/Code03_UnboundedKnapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_UnboundedKnapsack {
  inline static int MAXM = 10001;
  inline static int MAXT = 10000001;
  inline static Array<int> cost = make_array<int>(MAXM);
  inline static Array<int> val = make_array<int>(MAXM);
  inline static Array<i64> dp = make_array<i64>(MAXT);
  inline static int t = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_UnboundedKnapsack() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (t = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      for (int i = 1; (i <= m); (i++)) {
        in.nextToken();
        (cost[i] = static_cast<int>(in.nval));
        in.nextToken();
        (val[i] = static_cast<int>(in.nval));
      }
      out.println(Code03_UnboundedKnapsack::compute2());
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute1() {
    Array<Array<int>> dp = make_array<int>((m + 1), (t + 1));
    for (int i = 1; (i <= m); (i++)) {
      for (int j = 0; (j <= t); (j++)) {
        (dp[i][j] = dp[(i - 1)][j]);
        if (((j - cost[i]) >= 0)) {
          (dp[i][j] = jmax(dp[i][j], (dp[i][(j - cost[i])] + val[i])));
        }
      }
    }
    return dp[m][t];
  }
  static i64 compute2() {
    j::fill(dp, 1, (t + 1), 0);
    for (int i = 1; (i <= m); (i++)) {
      for (int j = cost[i]; (j <= t); (j++)) {
        (dp[j] = jmax(dp[j], (dp[(j - cost[i])] + val[i])));
      }
    }
    return dp[t];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_UnboundedKnapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 完全背包(模版)
// 给定一个正数t，表示背包的容量
// 有m种货物，每种货物可以选择任意个
// 每种货物都有体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1616
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // 严格位置依赖的动态规划
        // 会空间不够，导致无法通过全部测试用例
                // dp[0][.....] = 0
        // 空间压缩
        // 可以通过全部测试用例
*/
