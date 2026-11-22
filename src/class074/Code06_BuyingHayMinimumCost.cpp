// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2918

// Source: src/class074/Code06_BuyingHayMinimumCost.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_BuyingHayMinimumCost {
  inline static int MAXN = 101;
  inline static int MAXM = 55001;
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXM);
  inline static int n = {};
  inline static int h = {};
  inline static int maxv = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_BuyingHayMinimumCost() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (h = static_cast<int>(in.nval));
      (maxv = 0);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (val[i] = static_cast<int>(in.nval));
        (maxv = jmax(maxv, val[i]));
        in.nextToken();
        (cost[i] = static_cast<int>(in.nval));
      }
      (m = (h + maxv));
      out.println(Code06_BuyingHayMinimumCost::compute2());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    j::fill(dp[0], 1, (m + 1), std::numeric_limits<int>::max());
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = dp[(i - 1)][j]);
        if ((((j - val[i]) >= 0) &&
             (dp[i][(j - val[i])] != std::numeric_limits<int>::max()))) {
          (dp[i][j] = jmin(dp[i][j], (dp[i][(j - val[i])] + cost[i])));
        }
      }
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = h; (j <= m); (j++)) {
      (ans = jmin(ans, dp[n][j]));
    }
    return ans;
  }
  static int compute2() {
    j::fill(dp, 1, (m + 1), std::numeric_limits<int>::max());
    for (int i = 1; (i <= n); (i++)) {
      for (int j = val[i]; (j <= m); (j++)) {
        if ((dp[(j - val[i])] != std::numeric_limits<int>::max())) {
          (dp[j] = jmin(dp[j], (dp[(j - val[i])] + cost[i])));
        }
      }
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = h; (j <= m); (j++)) {
      (ans = jmin(ans, dp[j]));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_BuyingHayMinimumCost::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 购买足量干草的最小花费
// 有n个提供干草的公司，每个公司都有两个信息
// cost[i]代表购买1次产品需要花的钱
// val[i]代表购买1次产品所获得的干草数量
// 每个公司的产品都可以购买任意次
// 你一定要至少购买h数量的干草，返回最少要花多少钱
// 测试链接 : https://www.luogu.com.cn/problem/P2918
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
                        // 最核心的一句
                        // 包含重要分析
        // dp[i][j] : 1...i里挑公司，购买严格j磅干草，需要的最少花费
        // 1) dp[i-1][j]
        // 2) dp[i][j-val[i]] + cost[i]
        // 两种可能性中选最小
        // 但是关于j需要进行一定的扩充，原因视频里讲了
                // >= h
                // h h+1 h+2 ... m
        // 空间压缩
*/
