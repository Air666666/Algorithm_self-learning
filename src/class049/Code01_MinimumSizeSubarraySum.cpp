// Source: src/class049/Code01_MinimumSizeSubarraySum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumSizeSubarraySum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumSizeSubarraySum() {}
  static int minSubArrayLen(int target, Array<int> nums) {
    int ans = std::numeric_limits<int>::max();
    {
      int l = 0;
      int r = 0;
      int sum = 0;
      for (; (r < nums.length); (r++)) {
        (sum += nums[r]);
        while (((sum - nums[l]) >= target)) {
          (sum -= nums[(l++)]);
        }
        if ((sum >= target)) {
          (ans = jmin(ans, ((r - l) + 1)));
        }
      }
    }
    return ((ans == std::numeric_limits<int>::max()) ? 0 : ans);
  }
};

/* Original teaching comments:
// 累加和大于等于target的最短子数组长度
// 给定一个含有 n 个正整数的数组和一个正整数 target
// 找到累加和 >= target 的长度最小的子数组并返回其长度
// 如果不存在符合条件的子数组返回0
// 测试链接 : https://leetcode.cn/problems/minimum-size-subarray-sum/
                                // sum : nums[l....r]
                                //
如果l位置的数从窗口出去，还能继续达标，那就出去
*/
