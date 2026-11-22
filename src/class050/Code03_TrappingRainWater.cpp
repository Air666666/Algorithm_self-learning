// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/trapping-rain-water/

// Source: src/class050/Code03_TrappingRainWater.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TrappingRainWater {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TrappingRainWater() {}
  static int trap1(Array<int> nums) {
    int n = nums.length;
    Array<int> lmax = make_array<int>(n);
    Array<int> rmax = make_array<int>(n);
    (lmax[0] = nums[0]);
    for (int i = 1; (i < n); (i++)) {
      (lmax[i] = jmax(lmax[(i - 1)], nums[i]));
    }
    (rmax[(n - 1)] = nums[(n - 1)]);
    for (int i = (n - 2); (i >= 0); (i--)) {
      (rmax[i] = jmax(rmax[(i + 1)], nums[i]));
    }
    int ans = 0;
    for (int i = 1; (i < (n - 1)); (i++)) {
      (ans += jmax(0, (jmin(lmax[(i - 1)], rmax[(i + 1)]) - nums[i])));
    }
    return ans;
  }
  static int trap2(Array<int> nums) {
    int l = 1;
    int r = (nums.length - 2);
    int lmax = nums[0];
    int rmax = nums[(nums.length - 1)];
    int ans = 0;
    while ((l <= r)) {
      if ((lmax <= rmax)) {
        (ans += jmax(0, (lmax - nums[l])));
        (lmax = jmax(lmax, nums[(l++)]));
      } else {
        (ans += jmax(0, (rmax - nums[r])));
        (rmax = jmax(rmax, nums[(r--)]));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 接雨水
// 给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water/
        // 辅助数组的解法（不是最优解）
        // 时间复杂度O(n)，额外空间复杂度O(n)
        // 提交时改名为trap
                // 0~i范围上的最大值，记录在lmax[i]
                // i~n-1范围上的最大值，记录在rmax[i]
                //   x              x
                //   0 1 2 3...n-2 n-1
        // 双指针的解法（最优解）
        // 时间复杂度O(n)，额外空间复杂度O(1)
        // 提交时改名为trap
*/
