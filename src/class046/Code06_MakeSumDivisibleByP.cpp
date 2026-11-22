// Source: src/class046/Code06_MakeSumDivisibleByP.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MakeSumDivisibleByP {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MakeSumDivisibleByP() {}
  static int minSubarray(Array<int> nums, int p) {
    int mod = 0;
    for (int num : nums) {
      (mod = jrem((mod + num), p));
    }
    if ((mod == 0)) {
      return 0;
    }
    JMap<int, int> map = JMap<int, int>();
    map.put(0, (-1));
    int ans = std::numeric_limits<int>::max();
    {
      int i = 0;
      int cur = 0;
      int find = {};
      for (; (i < nums.length); (i++)) {
        (cur = jrem((cur + nums[i]), p));
        (find = ((cur >= mod) ? (cur - mod) : ((cur + p) - mod)));
        if (map.containsKey(find)) {
          (ans = jmin(ans, (i - map.get(find))));
        }
        map.put(cur, i);
      }
    }
    return ((ans == nums.length) ? (-1) : ans);
  }
};

/* Original teaching comments:
// 使数组和能被P整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/
                // 整体余数
                // key : 前缀和%p的余数
                // value : 最晚出现的位置
                        // 0...i这部分的余数
                        // find = (cur + p - mod) % p;
*/
