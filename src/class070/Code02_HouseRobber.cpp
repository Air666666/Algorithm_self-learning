// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/house-robber/

// Source: src/class070/Code02_HouseRobber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_HouseRobber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_HouseRobber() {}
  static int rob1(Array<int> nums) {
    int n = nums.length;
    if ((n == 1)) {
      return nums[0];
    }
    if ((n == 2)) {
      return jmax(nums[0], nums[1]);
    }
    Array<int> dp = make_array<int>(n);
    (dp[0] = nums[0]);
    (dp[1] = jmax(nums[0], nums[1]));
    for (int i = 2; (i < n); (i++)) {
      (dp[i] = jmax(dp[(i - 1)], jmax(nums[i], (dp[(i - 2)] + nums[i]))));
    }
    return dp[(n - 1)];
  }
  static int rob2(Array<int> nums) {
    int n = nums.length;
    if ((n == 1)) {
      return nums[0];
    }
    if ((n == 2)) {
      return jmax(nums[0], nums[1]);
    }
    int prepre = nums[0];
    int pre = jmax(nums[0], nums[1]);
    {
      int i = 2;
      int cur = {};
      for (; (i < n); (i++)) {
        (cur = jmax(pre, jmax(nums[i], (prepre + nums[i]))));
        (prepre = pre);
        (pre = cur);
      }
    }
    return pre;
  }
};

/* Original teaching comments:
// 数组中不能选相邻元素的最大累加和
// 给定一个数组，可以随意选择数字
// 但是不能选择相邻的数字，返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber/
        // 动态规划
                // dp[i] :
nums[0...i]范围上可以随意选择数字，但是不能选相邻数，能得到的最大累加和
        // 空间压缩
*/
