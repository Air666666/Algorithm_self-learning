// Source: src/class051/Code04_FindKthSmallestPairDistance.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_FindKthSmallestPairDistance {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_FindKthSmallestPairDistance() {}
  static int smallestDistancePair(Array<int> nums, int k) {
    int n = nums.length;
    j::sort(nums);
    int ans = 0;
    {
      int l = 0;
      int r = (nums[(n - 1)] - nums[0]);
      int m = {};
      int cnt = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        (cnt = Code04_FindKthSmallestPairDistance::f(nums, m));
        if ((cnt >= k)) {
          (ans = m);
          (r = (m - 1));
        } else {
          (l = (m + 1));
        }
      }
    }
    return ans;
  }
  static int f(Array<int> arr, int limit) {
    int ans = 0;
    {
      int l = 0;
      int r = 0;
      for (; (l < arr.length); (l++)) {
        while ((((r + 1) < arr.length) && ((arr[(r + 1)] - arr[l]) <= limit))) {
          (r++);
        }
        (ans += (r - l));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 找出第K小的数对距离
// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
// 给你一个整数数组 nums 和一个整数 k
// 数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
// 返回 所有数对距离中 第 k 小的数对距离。
// 测试链接 : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
        // 时间复杂度O(n * log(n) + log(max-min) * n)，额外空间复杂度O(1)
                // [0, 最大-最小]，不停二分
                        // m中点，arr中任意两数的差值 <= m
                        // 返回数字对的数量
        // arr中任意两数的差值 <= limit
        // 这样的数字配对，有几对？
                // O(n)
                        // l......r r+1
                        // arr[l...r]范围上的数差值的绝对值都不超过limit
                        // arr[0...3]
                        // 0,1
                        // 0,2
                        // 0,3
*/
