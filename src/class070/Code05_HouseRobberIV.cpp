// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/house-robber-iv/

// Source: src/class070/Code05_HouseRobberIV.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_HouseRobberIV {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_HouseRobberIV() {}
  static int minCapability(Array<int> nums, int k) {
    int n = nums.length;
    int l = nums[0];
    int r = nums[0];
    for (int i = 1; (i < n); (i++)) {
      (l = jmin(l, nums[i]));
      (r = jmax(r, nums[i]));
    }
    int m = {};
    int ans = 0;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((Code05_HouseRobberIV::mostRob1(nums, n, m) >= k)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int mostRob1(Array<int> nums, int n, int ability) {
    if ((n == 1)) {
      return ((nums[0] <= ability) ? 1 : 0);
    }
    if ((n == 2)) {
      return (((nums[0] <= ability) || (nums[1] <= ability)) ? 1 : 0);
    }
    Array<int> dp = make_array<int>(n);
    (dp[0] = ((nums[0] <= ability) ? 1 : 0));
    (dp[1] = (((nums[0] <= ability) || (nums[1] <= ability)) ? 1 : 0));
    for (int i = 2; (i < n); (i++)) {
      (dp[i] =
           jmax(dp[(i - 1)], (((nums[i] <= ability) ? 1 : 0) + dp[(i - 2)])));
    }
    return dp[(n - 1)];
  }
  static int mostRob2(Array<int> nums, int n, int ability) {
    if ((n == 1)) {
      return ((nums[0] <= ability) ? 1 : 0);
    }
    if ((n == 2)) {
      return (((nums[0] <= ability) || (nums[1] <= ability)) ? 1 : 0);
    }
    int prepre = ((nums[0] <= ability) ? 1 : 0);
    int pre = (((nums[0] <= ability) || (nums[1] <= ability)) ? 1 : 0);
    {
      int i = 2;
      int cur = {};
      for (; (i < n); (i++)) {
        (cur = jmax(pre, (((nums[i] <= ability) ? 1 : 0) + prepre)));
        (prepre = pre);
        (pre = cur);
      }
    }
    return pre;
  }
  static int mostRob3(Array<int> nums, int n, int ability) {
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      if ((nums[i] <= ability)) {
        (ans++);
        (i++);
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 打家劫舍 IV
// 沿街有一排连续的房屋。每间房屋内都藏有一定的现金
// 现在有一位小偷计划从这些房屋中窃取现金
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷不会窃取相邻的房屋
// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额
// 给你一个整数数组 nums 表示每间房屋存放的现金金额
// 第i间房屋中放有nums[i]的钱数
// 另给你一个整数k，表示小偷需要窃取至少 k 间房屋
// 返回小偷需要的最小窃取能力值
// 测试链接 : https://leetcode.cn/problems/house-robber-iv/
                // l....r
        // 盗贼能力为ability时
        // 返回盗贼最多能窃取多少间房屋
        // 注意限制 : 不能窃取相邻房屋
        // 继续空间压缩优化
        // 继续贪心优化
*/
