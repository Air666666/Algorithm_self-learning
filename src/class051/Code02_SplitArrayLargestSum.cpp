// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/split-array-largest-sum/

// Source: src/class051/Code02_SplitArrayLargestSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SplitArrayLargestSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SplitArrayLargestSum() {}
  static int splitArray(Array<int> nums, int k) {
    i64 sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    i64 ans = 0;
    {
      i64 l = 0;
      i64 r = sum;
      i64 m = {};
      i64 need = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        (need = Code02_SplitArrayLargestSum::f(nums, m));
        if ((need <= k)) {
          (ans = m);
          (r = (m - 1));
        } else {
          (l = (m + 1));
        }
      }
    }
    return static_cast<int>(ans);
  }
  static int f(Array<int> arr, i64 limit) {
    int parts = 1;
    int sum = 0;
    for (int num : arr) {
      if ((num > limit)) {
        return std::numeric_limits<int>::max();
      }
      if (((sum + num) > limit)) {
        (parts++);
        (sum = num);
      } else {
        (sum += num);
      }
    }
    return parts;
  }
};

/* Original teaching comments:
// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/
        // 时间复杂度O(n * log(sum))，额外空间复杂度O(1)
                // [0,sum]二分
                        // 中点m
                        // 必须让数组每一部分的累加和 <=
m，请问划分成几个部分才够!
                                // 达标
        // 必须让数组arr每一部分的累加和 <= limit，请问划分成几个部分才够!
        // 返回需要的部分数量
*/
