// Source: src/class072/Code03_MinimumOperationsToMakeArraykIncreasing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumOperationsToMakeArraykIncreasing {
  inline static int MAXN = 100001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<int> ends = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumOperationsToMakeArraykIncreasing() {}
  static int kIncreasing(Array<int> arr, int k) {
    int n = arr.length;
    int ans = 0;
    {
      int i = 0;
      int size = {};
      for (; (i < k); (i++)) {
        (size = 0);
        for (int j = i; (j < n); (j += k)) {
          (nums[(size++)] = arr[j]);
        }
        (ans +=
         (size -
          Code03_MinimumOperationsToMakeArraykIncreasing::lengthOfNoDecreasing(
              size)));
      }
    }
    return ans;
  }
  static int lengthOfNoDecreasing(int size) {
    int len = 0;
    {
      int i = 0;
      int find = {};
      for (; (i < size); (i++)) {
        (find =
             Code03_MinimumOperationsToMakeArraykIncreasing::bs(len, nums[i]));
        if ((find == (-1))) {
          (ends[(len++)] = nums[i]);
        } else {
          (ends[find] = nums[i]);
        }
      }
    }
    return len;
  }
  static int bs(int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((num < ends[m])) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 使数组K递增的最少操作次数
// 给你一个下标从0开始包含n个正整数的数组arr，和一个正整数k
// 如果对于每个满足 k <= i <= n-1 的下标 i
// 都有 arr[i-k] <= arr[i] ，那么称 arr 是K递增的
// 每一次操作中，你可以选择一个下标i并将arr[i]改成任意正整数
// 请你返回对于给定的 k ，使数组变成K递增的最少操作次数
// 测试链接 :
https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/
                        // 把每一组的数字放入容器
                        // 当前组长度 - 当前组最长不下降子序列长度 =
当前组至少需要修改的数字个数
        // nums[0...size-1]中的最长不下降子序列长度
*/
