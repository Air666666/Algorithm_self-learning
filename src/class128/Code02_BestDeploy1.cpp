// Source: src/class128/Code02_BestDeploy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BestDeploy1 {
  inline static int MAXN = 1001;
  inline static Array<int> no = make_array<int>(MAXN);
  inline static Array<int> one = make_array<int>(MAXN);
  inline static Array<int> both = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BestDeploy1() {}
  static int best1() {
    Array<Array<int>> dp = make_array<int>((n + 1), (n + 1));
    for (int l = 1; (l <= n); (l++)) {
      for (int r = l; (r <= n); (r++)) {
        (dp[l][r] = (-1));
      }
    }
    return Code02_BestDeploy1::f(1, n, dp);
  }
  static int f(int l, int r, Array<Array<int>> dp) {
    if ((l == r)) {
      return no[l];
    }
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = (Code02_BestDeploy1::f((l + 1), r, dp) + one[l]);
    (ans = jmax(ans, (Code02_BestDeploy1::f(l, (r - 1), dp) + one[r])));
    for (int i = (l + 1); (i < r); (i++)) {
      (ans = jmax(ans, ([&]() {
                    auto jleft = Code02_BestDeploy1::f(l, (i - 1), dp);
                    auto jright = Code02_BestDeploy1::f((i + 1), r, dp);
                    return (jleft + jright);
                  }() + both[i])));
    }
    (dp[l][r] = ans);
    return ans;
  }
  static int best2() {
    Array<Array<int>> dp = make_array<int>((n + 1), 2);
    (dp[n][0] = no[n]);
    (dp[n][1] = one[n]);
    for (int i = (n - 1); (i >= 1); (i--)) {
      (dp[i][0] = jmax((no[i] + dp[(i + 1)][1]), (one[i] + dp[(i + 1)][0])));
      (dp[i][1] = jmax((one[i] + dp[(i + 1)][1]), (both[i] + dp[(i + 1)][0])));
    }
    return dp[1][0];
  }
  static void random(int size, int v) {
    (n = size);
    for (int i = 1; (i <= n); (i++)) {
      (no[i] = static_cast<int>((j::random() * v)));
      (one[i] = static_cast<int>((j::random() * v)));
      (both[i] = static_cast<int>((j::random() * v)));
    }
  }
  static void java_main(Array<String> args) {
    int maxn = 100;
    int maxv = 100;
    int testTime = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int size = (static_cast<int>((j::random() * maxn)) + 1);
      Code02_BestDeploy1::random(size, maxv);
      int ans1 = Code02_BestDeploy1::best1();
      int ans2 = Code02_BestDeploy1::best2();
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BestDeploy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 注意查看Code02_BestDeploy2文件，找到了题目2的在线测试
// 最好的部署
// 一共有n台机器，编号1 ~ n，所有机器排成一排
// 你只能一台一台的部署机器，你可以决定部署的顺序，最终所有机器都要部署
// 给定三个数组no[]、one[]、both[]
// no[i] : 如果i号机器部署时，相邻没有机器部署，此时能获得的收益
// one[i] : 如果i号机器部署时，相邻有一台机器部署，此时能获得的收益
// both[i] : 如果i号机器部署时，相邻有两台机器部署，此时能获得的收益
// 第1号机器、第n号机器当然不会有两台相邻的机器
// 返回部署的最大收益
// 1 <= n <= 10^5
// 0 <= no[i]、one[i]、both[i]
// 来自真实大厂笔试，对数器验证
        // 区间dp的尝试
        // 时间复杂度O(n^3)
        // 正确但是并不推荐
        // 部署l...r范围上的机器
        // 并且l-1和r+1的机器一定都没有部署
        // 返回部署的最大收益
        // 线性dp的尝试
        // 时间复杂度O(n)
        // 推荐
                // dp[i][0] :
i号机器的前一台机器没有部署的情况下，部署i...的机器获得的最大收益
                // dp[i][1] :
i号机器的前一台机器已经部署的情况下，部署i...的机器获得的最大收益
        // 为了测试
        // 为了测试
*/
