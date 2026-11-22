// Source: src/class071/Code02_MaxSumDividedBy7.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MaxSumDividedBy7 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MaxSumDividedBy7() {}
  static int maxSum1(Array<int> nums) {
    return Code02_MaxSumDividedBy7::f(nums, 0, 0);
  }
  static int f(Array<int> nums, int i, int s) {
    if ((i == nums.length)) {
      return ((jrem(s, 7) == 0) ? s : 0);
    }
    return [&]() {
      auto jargument_0 = Code02_MaxSumDividedBy7::f(nums, (i + 1), s);
      auto jargument_1 =
          Code02_MaxSumDividedBy7::f(nums, (i + 1), (s + nums[i]));
      return jmax(jargument_0, jargument_1);
    }();
  }
  static int maxSum2(Array<int> nums) {
    int n = nums.length;
    Array<Array<int>> dp = make_array<int>((n + 1), 7);
    (dp[0][0] = 0);
    for (int j = 1; (j < 7); (j++)) {
      (dp[0][j] = (-1));
    }
    {
      int i = 1;
      int x = {};
      int cur = {};
      int need = {};
      for (; (i <= n); (i++)) {
        (x = nums[(i - 1)]);
        (cur = jrem(nums[(i - 1)], 7));
        for (int j = 0; (j < 7); (j++)) {
          (dp[i][j] = dp[(i - 1)][j]);
          (need = ((cur <= j) ? (j - cur) : ((j - cur) + 7)));
          if ((dp[(i - 1)][need] != (-1))) {
            (dp[i][j] = jmax(dp[i][j], (dp[(i - 1)][need] + x)));
          }
        }
      }
    }
    return dp[n][0];
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 15;
    int v = 30;
    int testTime = 20000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int len = (static_cast<int>((j::random() * n)) + 1);
      Array<int> nums = Code02_MaxSumDividedBy7::randomArray(len, v);
      int ans1 = Code02_MaxSumDividedBy7::maxSum1(nums);
      int ans2 = Code02_MaxSumDividedBy7::maxSum2(nums);
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
  Code02_MaxSumDividedBy7::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 子序列累加和必须被7整除的最大累加和
// 给定一个非负数组nums，
// 可以任意选择数字组成子序列，但是子序列的累加和必须被7整除
// 返回最大累加和
// 对数器验证
        // 暴力方法
        // 为了验证
                // nums形成的所有子序列的累加和都求出来
                // 其中%7==0的那些累加和中，返回最大的
                // 就是如下f函数的功能
        // 正式方法
        // 时间复杂度O(n)
                // dp[i][j] : nums[0...i-1]
                // nums前i个数形成的子序列一定要做到，子序列累加和%7 == j
                // 这样的子序列最大累加和是多少
                // 注意 : dp[i][j] == -1代表不存在这样的子序列
                                // 这里求need是核心
                                // 或者如下这种写法也对
                                // need = (7 + j - cur) % 7;
        // 为了测试
        // 生成随机数组
        // 为了测试
        // 对数器
*/
