// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

// Source: src/class091/Code01_ShortestUnsortedContinuousSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ShortestUnsortedContinuousSubarray {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ShortestUnsortedContinuousSubarray() {}
  static int findUnsortedSubarray(Array<int> nums) {
    int n = nums.length;
    int right = (-1);
    int max = std::numeric_limits<int>::min();
    for (int i = 0; (i < n); (i++)) {
      if ((max > nums[i])) {
        (right = i);
      }
      (max = jmax(max, nums[i]));
    }
    int min = std::numeric_limits<int>::max();
    int left = n;
    for (int i = (n - 1); (i >= 0); (i--)) {
      if ((min < nums[i])) {
        (left = i);
      }
      (min = jmin(min, nums[i]));
    }
    return jmax(0, ((right - left) + 1));
  }
};

/* Original teaching comments:
// 最短无序连续子数组
// 给你一个整数数组nums，你需要找出一个 连续子数组
// 如果对这个子数组进行升序排序，那么整个数组都会变为升序排序
// 请你找出符合题意的最短子数组，并输出它的长度
// 测试链接 :
https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/
                // max > 当前数，认为不达标
                // 从左往右遍历，记录最右不达标的位置
                // min < 当前数，认为不达标
                // 从右往左遍历，记录最左不达标的位置
*/
