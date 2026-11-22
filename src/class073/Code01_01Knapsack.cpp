// Source: src/class073/Code01_01Knapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_01Knapsack {
  inline static int MAXM = 101;
  inline static int MAXT = 1001;
  inline static Array<int> cost = make_array<int>(MAXM);
  inline static Array<int> val = make_array<int>(MAXM);
  inline static Array<int> dp = make_array<int>(MAXT);
  inline static int t = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_01Knapsack() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (t = static_cast<int>(in.nval));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (cost[i] = static_cast<int>(in.nval));
        in.nextToken();
        (val[i] = static_cast<int>(in.nval));
      }
      out.println(Code01_01Knapsack::compute2());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<Array<int>> dp = make_array<int>((n + 1), (t + 1));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= t); (j++)) {
        (dp[i][j] = dp[(i - 1)][j]);
        if (((j - cost[i]) >= 0)) {
          (dp[i][j] = jmax(dp[i][j], (dp[(i - 1)][(j - cost[i])] + val[i])));
        }
      }
    }
    return dp[n][t];
  }
  static int compute2() {
    j::fill(dp, 0, (t + 1), 0);
    for (int i = 1; (i <= n); (i++)) {
      for (int j = t; (j >= cost[i]); (j--)) {
        (dp[j] = jmax(dp[j], (dp[(j - cost[i])] + val[i])));
      }
    }
    return dp[t];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_01Knapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 01背包(模版)
// 给定一个正数t，表示背包的容量
// 有m个货物，每个货物可以选择一次
// 每个货物有自己的体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1048
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // 严格位置依赖的动态规划
        // n个物品编号1~n，第i号物品的花费cost[i]、价值val[i]
        // cost、val数组是全局变量，已经把数据读入了
                                // 不要i号物品
                                        // 要i号物品
        // 空间压缩
*/
