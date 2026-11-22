// Source: src/class076/Code05_BurstBalloons.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_BurstBalloons {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_BurstBalloons() {}
  static int maxCoins1(Array<int> nums) {
    int n = nums.length;
    Array<int> arr = make_array<int>((n + 2));
    (arr[0] = 1);
    (arr[(n + 1)] = 1);
    for (int i = 0; (i < n); (i++)) {
      (arr[(i + 1)] = nums[i]);
    }
    Array<Array<int>> dp = make_array<int>((n + 2), (n + 2));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = i; (j <= n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code05_BurstBalloons::f(arr, 1, n, dp);
  }
  static int f(Array<int> arr, int l, int r, Array<Array<int>> dp) {
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = {};
    if ((l == r)) {
      (ans = ((arr[(l - 1)] * arr[l]) * arr[(r + 1)]));
    } else {
      (ans = [&]() {
        auto jargument_0 = (((arr[(l - 1)] * arr[l]) * arr[(r + 1)]) +
                            Code05_BurstBalloons::f(arr, (l + 1), r, dp));
        auto jargument_1 = (((arr[(l - 1)] * arr[r]) * arr[(r + 1)]) +
                            Code05_BurstBalloons::f(arr, l, (r - 1), dp));
        return jmax(jargument_0, jargument_1);
      }());
      for (int k = (l + 1); (k < r); (k++)) {
        (ans = jmax(ans, [&]() {
           auto jleft = (((arr[(l - 1)] * arr[k]) * arr[(r + 1)]) +
                         Code05_BurstBalloons::f(arr, l, (k - 1), dp));
           auto jright = Code05_BurstBalloons::f(arr, (k + 1), r, dp);
           return (jleft + jright);
         }()));
      }
    }
    (dp[l][r] = ans);
    return ans;
  }
  static int maxCoins2(Array<int> nums) {
    int n = nums.length;
    Array<int> arr = make_array<int>((n + 2));
    (arr[0] = 1);
    (arr[(n + 1)] = 1);
    for (int i = 0; (i < n); (i++)) {
      (arr[(i + 1)] = nums[i]);
    }
    Array<Array<int>> dp = make_array<int>((n + 2), (n + 2));
    for (int i = 1; (i <= n); (i++)) {
      (dp[i][i] = ((arr[(i - 1)] * arr[i]) * arr[(i + 1)]));
    }
    {
      int l = n;
      int ans = {};
      for (; (l >= 1); (l--)) {
        for (int r = (l + 1); (r <= n); (r++)) {
          (ans = jmax(
               (((arr[(l - 1)] * arr[l]) * arr[(r + 1)]) + dp[(l + 1)][r]),
               (((arr[(l - 1)] * arr[r]) * arr[(r + 1)]) + dp[l][(r - 1)])));
          for (int k = (l + 1); (k < r); (k++)) {
            (ans = jmax(ans, ((((arr[(l - 1)] * arr[k]) * arr[(r + 1)]) +
                               dp[l][(k - 1)]) +
                              dp[(k + 1)][r])));
          }
          (dp[l][r] = ans);
        }
      }
    }
    return dp[1][n];
  }
};

/* Original teaching comments:
// 戳气球
// 有 n 个气球，编号为0到n-1，每个气球上都标有一个数字，这些数字存在数组nums中
// 现在要求你戳破所有的气球。戳破第 i 个气球
// 你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
// 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
// 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
// 求所能获得硬币的最大数量
// 测试链接 : https://leetcode.cn/problems/burst-balloons/
        // 记忆化搜索
                // a b c d e
                // 1 a b c d e 1
        // arr[l...r]这些气球决定一个顺序，获得最大得分返回！
        // 一定有 : arr[l-1]一定没爆！
        // 一定有 : arr[r+1]一定没爆！
        // 尝试每个气球最后打爆
                        // l   ....r
                        // l +1 +2 .. r
                                // k位置的气球最后打爆
                                // l...k-1  k  k+1...r
        // 严格位置依赖的动态规划
*/
