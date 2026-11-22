// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

// Source: src/class080/Code03_PartitionToKEqualSumSubsets.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PartitionToKEqualSumSubsets {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PartitionToKEqualSumSubsets() {}
  static bool canPartitionKSubsets1(Array<int> nums, int k) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    if ((jrem(sum, k) != 0)) {
      return false;
    }
    int n = nums.length;
    Array<int> dp = make_array<int>(jshl(1, n));
    return Code03_PartitionToKEqualSumSubsets::f1(nums, jdiv(sum, k),
                                                  (jshl(1, n) - 1), 0, k, dp);
  }
  static bool f1(Array<int> nums, int limit, int status, int cur, int rest,
                 Array<int> dp) {
    if ((rest == 0)) {
      return (status == 0);
    }
    if ((dp[status] != 0)) {
      return (dp[status] == 1);
    }
    bool ans = false;
    for (int i = 0; (i < nums.length); (i++)) {
      if ((((status & jshl(1, i)) != 0) && ((cur + nums[i]) <= limit))) {
        if (((cur + nums[i]) == limit)) {
          (ans = Code03_PartitionToKEqualSumSubsets::f1(
               nums, limit, (status ^ jshl(1, i)), 0, (rest - 1), dp));
        } else {
          (ans = Code03_PartitionToKEqualSumSubsets::f1(
               nums, limit, (status ^ jshl(1, i)), (cur + nums[i]), rest, dp));
        }
        if (ans) {
          break;
        }
      }
    }
    (dp[status] = (ans ? 1 : (-1)));
    return ans;
  }
  static bool canPartitionKSubsets2(Array<int> nums, int k) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    if ((jrem(sum, k) != 0)) {
      return false;
    }
    int n = nums.length;
    j::sort(nums);
    return Code03_PartitionToKEqualSumSubsets::f2(make_array<int>(k),
                                                  jdiv(sum, k), nums, (n - 1));
  }
  static bool f2(Array<int> group, int target, Array<int> nums, int index) {
    if ((index < 0)) {
      return true;
    }
    int num = nums[index];
    int len = group.length;
    for (int i = 0; (i < len); (i++)) {
      if (((group[i] + num) <= target)) {
        (group[i] += num);
        if (Code03_PartitionToKEqualSumSubsets::f2(group, target, nums,
                                                   (index - 1))) {
          return true;
        }
        (group[i] -= num);
        while ((((i + 1) < group.length) && (group[i] == group[(i + 1)]))) {
          (i++);
        }
      }
    }
    return false;
  }
};

/* Original teaching comments:
// 划分为k个相等的子集
// 给定一个整数数组  nums 和一个正整数 k，
// 找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
// 测试链接 : https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/
        // 状压dp的解法
        // 这是最正式的解
        // 就是题目2的递归函数
        //
纯暴力的递归（不做任何动态规划），利用良好的剪枝策略，可以做到非常好的效率
        // 但这并不是正式的解，如果数据设计的很苛刻，是通过不了的
        // group里面是各个集合已经有的累加和
        // 随着递归的展开，group里的累加和会变化
        // 所以这是一个带路径的递归，而且路径信息比较复杂(group数组)
        // 无法改成动态规划，但是利用剪枝策略可以通过
        // group[0....index]这些数字，填入每个集合，一定要都使用
        // 每个集合的累加和一定都要是target，返回能不能做到
                                // 当前数字num放进i号集合
                                // 递归完成后将路径还原
*/
