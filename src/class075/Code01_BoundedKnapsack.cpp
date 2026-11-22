// Source: src/class075/Code01_BoundedKnapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BoundedKnapsack {
  inline static int MAXN = 101;
  inline static int MAXW = 40001;
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXW);
  inline static int n = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BoundedKnapsack() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (t = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (v[i] = static_cast<int>(in.nval));
        in.nextToken();
        (w[i] = static_cast<int>(in.nval));
        in.nextToken();
        (c[i] = static_cast<int>(in.nval));
      }
      out.println(Code01_BoundedKnapsack::compute2());
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
        for (int k = 1; ((k <= c[i]) && ((w[i] * k) <= j)); (k++)) {
          (dp[i][j] =
               jmax(dp[i][j], (dp[(i - 1)][(j - (k * w[i]))] + (k * v[i]))));
        }
      }
    }
    return dp[n][t];
  }
  static int compute2() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = t; (j >= 0); (j--)) {
        for (int k = 1; ((k <= c[i]) && ((w[i] * k) <= j)); (k++)) {
          (dp[j] = jmax(dp[j], (dp[(j - (k * w[i]))] + (k * v[i]))));
        }
      }
    }
    return dp[t];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BoundedKnapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 多重背包不进行枚举优化
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 严格位置依赖的动态规划
        // 时间复杂度O(n * t * 每种商品的平均个数)
                // dp[0][....] =
0，表示没有货物的情况下，背包容量不管是多少，最大价值都是0
        // 空间压缩
        // 部分测试用例超时
        // 因为没有优化枚举
        // 时间复杂度O(n * t * 每种商品的平均个数)
*/
