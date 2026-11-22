// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-sum-circular-subarray/

// Source: src/class070/Code03_MaximumSumCircularSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MaximumSumCircularSubarray {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MaximumSumCircularSubarray() {}
  static int maxSubarraySumCircular(Array<int> nums) {
    int n = nums.length;
    int all = nums[0];
    int maxsum = nums[0];
    int minsum = nums[0];
    {
      int i = 1;
      int maxpre = nums[0];
      int minpre = nums[0];
      for (; (i < n); (i++)) {
        (all += nums[i]);
        (maxpre = jmax(nums[i], (nums[i] + maxpre)));
        (maxsum = jmax(maxsum, maxpre));
        (minpre = jmin(nums[i], (nums[i] + minpre)));
        (minsum = jmin(minsum, minpre));
      }
    }
    return ((all == minsum) ? maxsum : jmax(maxsum, (all - minsum)));
  }
};

/* Original teaching comments:
// 环形数组的子数组最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 返回环形数组中，子数组最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-sum-circular-subarray/
                // 1) maxsum
                // 2) all - minsum
*/
