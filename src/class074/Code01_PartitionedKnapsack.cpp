// Source: src/class074/Code01_PartitionedKnapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PartitionedKnapsack {
  inline static int MAXN = 1001;
  inline static int MAXM = 1001;
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 3);
  inline static Array<int> dp = make_array<int>(MAXM);
  inline static int m = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PartitionedKnapsack() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (m = static_cast<int>(in.nval));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i][0] = static_cast<int>(in.nval));
        in.nextToken();
        (arr[i][1] = static_cast<int>(in.nval));
        in.nextToken();
        (arr[i][2] = static_cast<int>(in.nval));
      }
      j::sort(arr, 1, (n + 1),
              [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
      out.println(Code01_PartitionedKnapsack::compute1());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    int teams = 1;
    for (int i = 2; (i <= n); (i++)) {
      if ((arr[(i - 1)][2] != arr[i][2])) {
        (teams++);
      }
    }
    Array<Array<int>> dp = make_array<int>((teams + 1), (m + 1));
    {
      int start = 1;
      int end = 2;
      int i = 1;
      for (; (start <= n); (i++)) {
        while (((end <= n) && (arr[end][2] == arr[start][2]))) {
          (end++);
        }
        for (int j = 0; (j <= m); (j++)) {
          (dp[i][j] = dp[(i - 1)][j]);
          for (int k = start; (k < end); (k++)) {
            if (((j - arr[k][0]) >= 0)) {
              (dp[i][j] =
                   jmax(dp[i][j], (dp[(i - 1)][(j - arr[k][0])] + arr[k][1])));
            }
          }
        }
        (start = (end++));
      }
    }
    return dp[teams][m];
  }
  static int compute2() {
    j::fill(dp, 0, (m + 1), 0);
    {
      int start = 1;
      int end = 2;
      for (; (start <= n);) {
        while (((end <= n) && (arr[end][2] == arr[start][2]))) {
          (end++);
        }
        for (int j = m; (j >= 0); (j--)) {
          for (int k = start; (k < end); (k++)) {
            if (((j - arr[k][0]) >= 0)) {
              (dp[j] = jmax(dp[j], (arr[k][1] + dp[(j - arr[k][0])])));
            }
          }
        }
        (start = (end++));
      }
    }
    return dp[m];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_PartitionedKnapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分组背包(模版)
// 给定一个正数m表示背包的容量，有n个货物可供挑选
// 每个货物有自己的体积(容量消耗)、价值(获得收益)、组号(分组)
// 同一个组的物品只能挑选1件，所有挑选物品的体积总和不能超过背包容量
// 怎么挑选货物能达到价值最大，返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1757
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // arr[i][0] i号物品的体积
        // arr[i][1] i号物品的价值
        // arr[i][2] i号物品的组号
        // 严格位置依赖的动态规划
                // 组的编号1~teams
                // dp[i][j] :
1~i是组的范围，每个组的物品挑一件，容量不超过j的情况下，最大收益
                // dp[0][....] = 0
                        // start ... end-1 -> i组
                                // arr[start...end-1]是当前组，组号一样
                                // 其中的每一件商品枚举一遍
                                        // k是组内的一个商品编号
                        // start去往下一组的第一个物品
                        // 继续处理剩下的组
        // 空间压缩
                // dp[0][...] = 0
                        // start....end-1
*/
