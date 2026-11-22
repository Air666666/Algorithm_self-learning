// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/predict-the-winner/

// Source: src/class076/Code02_PredictTheWinner.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PredictTheWinner {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PredictTheWinner() {}
  static bool predictTheWinner1(Array<int> nums) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    int n = nums.length;
    int first = Code02_PredictTheWinner::f1(nums, 0, (n - 1));
    int second = (sum - first);
    return (first >= second);
  }
  static int f1(Array<int> nums, int l, int r) {
    if ((l == r)) {
      return nums[l];
    }
    if ((l == (r - 1))) {
      return jmax(nums[l], nums[r]);
    }
    int p1 = (nums[l] + [&]() {
      auto jargument_0 = Code02_PredictTheWinner::f1(nums, (l + 2), r);
      auto jargument_1 = Code02_PredictTheWinner::f1(nums, (l + 1), (r - 1));
      return jmin(jargument_0, jargument_1);
    }());
    int p2 = (nums[r] + [&]() {
      auto jargument_0 = Code02_PredictTheWinner::f1(nums, (l + 1), (r - 1));
      auto jargument_1 = Code02_PredictTheWinner::f1(nums, l, (r - 2));
      return jmin(jargument_0, jargument_1);
    }());
    return jmax(p1, p2);
  }
  static bool predictTheWinner2(Array<int> nums) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    int n = nums.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = i; (j < n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    int first = Code02_PredictTheWinner::f2(nums, 0, (n - 1), dp);
    int second = (sum - first);
    return (first >= second);
  }
  static int f2(Array<int> nums, int l, int r, Array<Array<int>> dp) {
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = {};
    if ((l == r)) {
      (ans = nums[l]);
    } else if ((l == (r - 1))) {
      (ans = jmax(nums[l], nums[r]));
    } else {
      int p1 = (nums[l] + [&]() {
        auto jargument_0 = Code02_PredictTheWinner::f2(nums, (l + 2), r, dp);
        auto jargument_1 =
            Code02_PredictTheWinner::f2(nums, (l + 1), (r - 1), dp);
        return jmin(jargument_0, jargument_1);
      }());
      int p2 = (nums[r] + [&]() {
        auto jargument_0 =
            Code02_PredictTheWinner::f2(nums, (l + 1), (r - 1), dp);
        auto jargument_1 = Code02_PredictTheWinner::f2(nums, l, (r - 2), dp);
        return jmin(jargument_0, jargument_1);
      }());
      (ans = jmax(p1, p2));
    }
    (dp[l][r] = ans);
    return ans;
  }
  static bool predictTheWinner3(Array<int> nums) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    int n = nums.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int i = 0; (i < (n - 1)); (i++)) {
      (dp[i][i] = nums[i]);
      (dp[i][(i + 1)] = jmax(nums[i], nums[(i + 1)]));
    }
    (dp[(n - 1)][(n - 1)] = nums[(n - 1)]);
    for (int l = (n - 3); (l >= 0); (l--)) {
      for (int r = (l + 2); (r < n); (r++)) {
        (dp[l][r] = [&]() {
          auto jargument_0 =
              (nums[l] + jmin(dp[(l + 2)][r], dp[(l + 1)][(r - 1)]));
          auto jargument_1 =
              (nums[r] + jmin(dp[(l + 1)][(r - 1)], dp[l][(r - 2)]));
          return jmax(jargument_0, jargument_1);
        }());
      }
    }
    int first = dp[0][(n - 1)];
    int second = (sum - first);
    return (first >= second);
  }
};

/* Original teaching comments:
// 预测赢家
// 给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏
// 玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手
// 开始时，两个玩家的初始分值都是 0
// 每一回合，玩家从数组的任意一端取一个数字
// 取到的数字将会从数组中移除，数组长度减1
// 玩家选中的数字将会加到他的得分上
// 当数组中没有剩余数字可取时游戏结束
// 如果玩家 1 能成为赢家，返回 true
// 如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true
// 你可以假设每个玩家的玩法都会使他的分数最大化
// 测试链接 : https://leetcode.cn/problems/predict-the-winner/
        // 暴力尝试
        // nums[l...r]范围上的数字进行游戏，轮到玩家1
        // 返回玩家1最终能获得多少分数，玩家1和玩家2都绝顶聪明
                // l....r 不只两个数
                // 可能性1 ：玩家1拿走nums[l] l+1...r
                // 可能性2 ：玩家1拿走nums[r] l...r-1
        // 记忆化搜索
        // 严格位置依赖的动态规划
*/
