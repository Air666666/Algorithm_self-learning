// Source: src/class072/Code01_LongestIncreasingSubsequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LongestIncreasingSubsequence {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LongestIncreasingSubsequence() {}
  static int lengthOfLIS1(Array<int> nums) {
    int n = nums.length;
    Array<int> dp = make_array<int>(n);
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (dp[i] = 1);
      for (int j = 0; (j < i); (j++)) {
        if ((nums[j] < nums[i])) {
          (dp[i] = jmax(dp[i], (dp[j] + 1)));
        }
      }
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static int lengthOfLIS2(Array<int> nums) {
    int n = nums.length;
    Array<int> ends = make_array<int>(n);
    int len = 0;
    {
      int i = 0;
      int find = {};
      for (; (i < n); (i++)) {
        (find = Code01_LongestIncreasingSubsequence::bs1(ends, len, nums[i]));
        if ((find == (-1))) {
          (ends[(len++)] = nums[i]);
        } else {
          (ends[find] = nums[i]);
        }
      }
    }
    return len;
  }
  static int bs1(Array<int> ends, int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int bs2(Array<int> ends, int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] > num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 最长递增子序列和最长不下降子序列
// 给定一个整数数组nums
// 找到其中最长严格递增子序列长度、最长不下降子序列长度
// 测试链接 : https://leetcode.cn/problems/longest-increasing-subsequence/
        // 普通解法的动态规划
        // 时间复杂度O(n^2)，数组稍大就会超时
        // 最优解
        // 时间复杂度O(n * logn)
                // len表示ends数组目前的有效区长度
                // ends[0...len-1]是有效区，有效区内的数字一定严格升序
        // "最长递增子序列"使用如下二分搜索 :
        // ends[0...len-1]是严格升序的，找到>=num的最左位置
        // 如果不存在返回-1
        // 如果求最长不下降子序列，那么使用如下的二分搜索 :
        // ends[0...len-1]是不降序的
        // 在其中找到>num的最左位置，如果不存在返回-1
        // 如果求最长不下降子序列，就在lengthOfLIS中把bs1方法换成bs2方法
        // 已经用对数器验证了，是正确的
*/
