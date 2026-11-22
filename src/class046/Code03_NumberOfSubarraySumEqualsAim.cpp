// Source: src/class046/Code03_NumberOfSubarraySumEqualsAim.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_NumberOfSubarraySumEqualsAim {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_NumberOfSubarraySumEqualsAim() {}
  static int subarraySum(Array<int> nums, int aim) {
    JMap<int, int> map = JMap<int, int>();
    map.put(0, 1);
    int ans = 0;
    {
      int i = 0;
      int sum = 0;
      for (; (i < nums.length); (i++)) {
        (sum += nums[i]);
        (ans += map.getOrDefault((sum - aim), 0));
        map.put(sum, (map.getOrDefault(sum, 0) + 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 返回无序数组中累加和为给定值的子数组个数
// 测试链接 : https://leetcode.cn/problems/subarray-sum-equals-k/
                // 0这个前缀和，在没有任何数字的时候，已经有1次了
                        // sum : 0...i前缀和
*/
