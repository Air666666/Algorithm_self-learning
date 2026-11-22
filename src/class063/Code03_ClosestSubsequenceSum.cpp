// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/closest-subsequence-sum/

// Source: src/class063/Code03_ClosestSubsequenceSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ClosestSubsequenceSum {
  inline static int MAXN = jshl(1, 20);
  inline static Array<int> lsum = make_array<int>(MAXN);
  inline static Array<int> rsum = make_array<int>(MAXN);
  inline static int fill = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ClosestSubsequenceSum() {}
  static int minAbsDifference(Array<int> nums, int goal) {
    int n = nums.length;
    i64 min = 0;
    i64 max = 0;
    for (int i = 0; (i < n); (i++)) {
      if ((nums[i] >= 0)) {
        (max += nums[i]);
      } else {
        (min += nums[i]);
      }
    }
    if ((max < goal)) {
      return static_cast<int>(std::abs((max - goal)));
    }
    if ((min > goal)) {
      return static_cast<int>(std::abs((min - goal)));
    }
    j::sort(nums);
    (fill = 0);
    Code03_ClosestSubsequenceSum::collect(nums, 0, jshr(n, 1), 0, lsum);
    int lsize = fill;
    (fill = 0);
    Code03_ClosestSubsequenceSum::collect(nums, jshr(n, 1), n, 0, rsum);
    int rsize = fill;
    j::sort(lsum, 0, lsize);
    j::sort(rsum, 0, rsize);
    int ans = std::abs(goal);
    {
      int i = 0;
      int j = (rsize - 1);
      for (; (i < lsize); (i++)) {
        while (((j > 0) && [&]() {
          auto jleft = std::abs(((goal - lsum[i]) - rsum[(j - 1)]));
          auto jright = std::abs(((goal - lsum[i]) - rsum[j]));
          return (jleft <= jright);
        }())) {
          (j--);
        }
        (ans = jmin(ans, std::abs(((goal - lsum[i]) - rsum[j]))));
      }
    }
    return ans;
  }
  static void collect(Array<int> nums, int i, int e, int s, Array<int> sum) {
    if ((i == e)) {
      (sum[(fill++)] = s);
    } else {
      int j = (i + 1);
      while (((j < e) && (nums[j] == nums[i]))) {
        (j++);
      }
      for (int k = 0; (k <= (j - i)); (k++)) {
        Code03_ClosestSubsequenceSum::collect(nums, j, e, (s + (k * nums[i])),
                                              sum);
      }
    }
  }
};

/* Original teaching comments:
// 最接近目标值的子序列和
// 给你一个整数数组 nums 和一个目标值 goal
// 你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal
// 也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal)
// 返回 abs(sum - goal) 可能的 最小值
//
注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
// 数据量描述:
// 1 <= nums.length <= 40
// -10^7 <= nums[i] <= 10^7
// -10^9 <= goal <= 10^9
// 测试链接 : https://leetcode.cn/problems/closest-subsequence-sum/
                // 原始数组排序，为了后面递归的时候，还能剪枝
                // 常数优化
                        // nums[i.....]这一组，相同的数字有几个
                        // nums[ 1 1 1 1 1 2....
                        //       i         j
                                // k = 0个
                                // k = 1个
                                // k = 2个
*/
