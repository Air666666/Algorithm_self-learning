// Source: src/class071/Code01_MaximumProductSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximumProductSubarray {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximumProductSubarray() {}
  static int maxProduct(Array<int> nums) {
    double ans = nums[0];
    double min = nums[0];
    double max = nums[0];
    double curmin = {};
    double curmax = {};
    for (int i = 1; (i < nums.length); (i++)) {
      (curmin = jmin(nums[i], jmin((min * nums[i]), (max * nums[i]))));
      (curmax = jmax(nums[i], jmax((min * nums[i]), (max * nums[i]))));
      (min = curmin);
      (max = curmax);
      (ans = jmax(ans, max));
    }
    return static_cast<int>(ans);
  }
};

/* Original teaching comments:
// 乘积最大子数组
// 给你一个整数数组 nums
// 请你找出数组中乘积最大的非空连续子数组
// 并返回该子数组所对应的乘积
// 测试链接 : https://leetcode.cn/problems/maximum-product-subarray/
        // 这节课讲完之后，测试数据又增加了
        // 用int类型的变量会让中间结果溢出
        // 所以改成用double类型的变量
        // 思路是不变的
*/
