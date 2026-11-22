// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/sort-array-by-parity-ii/

// Source: src/class050/Code01_SortArrayByParityII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SortArrayByParityII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SortArrayByParityII() {}
  static Array<int> sortArrayByParityII(Array<int> nums) {
    int n = nums.length;
    {
      int odd = 1;
      int even = 0;
      for (; ((odd < n) && (even < n));) {
        if (((nums[(n - 1)] & 1) == 1)) {
          Code01_SortArrayByParityII::swap(nums, odd, (n - 1));
          (odd += 2);
        } else {
          Code01_SortArrayByParityII::swap(nums, even, (n - 1));
          (even += 2);
        }
      }
    }
    return nums;
  }
  static void swap(Array<int> nums, int i, int j) {
    int tmp = nums[i];
    (nums[i] = nums[j]);
    (nums[j] = tmp);
  }
};

/* Original teaching comments:
// 按奇偶排序数组II
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 你可以返回 任何满足上述条件的数组作为答案
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/
        // 时间复杂度O(n)，额外空间复杂度O(1)
*/
