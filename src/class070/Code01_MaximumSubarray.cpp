// Source: src/class070/Code01_MaximumSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximumSubarray {
  inline static int left = {};
  inline static int right = {};
  inline static int sum = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximumSubarray() {}
  static int maxSubArray1(Array<int> nums) {
    int n = nums.length;
    Array<int> dp = make_array<int>(n);
    (dp[0] = nums[0]);
    int ans = nums[0];
    for (int i = 1; (i < n); (i++)) {
      (dp[i] = jmax(nums[i], (dp[(i - 1)] + nums[i])));
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static int maxSubArray2(Array<int> nums) {
    int n = nums.length;
    int ans = nums[0];
    {
      int i = 1;
      int pre = nums[0];
      for (; (i < n); (i++)) {
        (pre = jmax(nums[i], (pre + nums[i])));
        (ans = jmax(ans, pre));
      }
    }
    return ans;
  }
  static void extra(Array<int> nums) {
    (sum = std::numeric_limits<int>::min());
    {
      int l = 0;
      int r = 0;
      int pre = std::numeric_limits<int>::min();
      for (; (r < nums.length); (r++)) {
        if ((pre >= 0)) {
          (pre += nums[r]);
        } else {
          (pre = nums[r]);
          (l = r);
        }
        if ((pre > sum)) {
          (sum = pre);
          (left = l);
          (right = r);
        }
      }
    }
  }
};

/* Original teaching comments:
// 子数组最大累加和
// 给你一个整数数组 nums
// 返回非空子数组的最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-subarray/
        // 动态规划
                // dp[i] :
子数组必须以i位置的数做结尾，往左能延伸出来的最大累加和
        // 空间压缩
        // 如下代码为附加问题的实现
        // 子数组中找到拥有最大累加和的子数组
        // 并返回如下三个信息:
        // 1) 最大累加和子数组的开头left
        // 2) 最大累加和子数组的结尾right
        // 3) 最大累加和子数组的累加和sum
        // 如果不止一个子数组拥有最大累加和，那么找到哪一个都可以
        // 找到拥有最大累加和的子数组
        // 更新好全局变量left、right、sum
        // 上游调用函数可以直接使用这三个变量
        // 相当于返回了三个值
                                // 吸收前面的累加和有利可图
                                // 那就不换开头
                                // 吸收前面的累加和已经无利可图
                                // 那就换开头
*/
