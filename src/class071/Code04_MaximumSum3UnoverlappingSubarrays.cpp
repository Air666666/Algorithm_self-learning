// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

// Source: src/class071/Code04_MaximumSum3UnoverlappingSubarrays.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximumSum3UnoverlappingSubarrays {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximumSum3UnoverlappingSubarrays() {}
  static Array<int> maxSumOfThreeSubarrays(Array<int> nums, int k) {
    int n = nums.length;
    Array<int> sums = make_array<int>(n);
    {
      int l = 0;
      int r = 0;
      int sum = 0;
      for (; (r < n); (r++)) {
        (sum += nums[r]);
        if ((((r - l) + 1) == k)) {
          (sums[l] = sum);
          (sum -= nums[l]);
          (l++);
        }
      }
    }
    Array<int> prefix = make_array<int>(n);
    {
      int l = 1;
      int r = k;
      for (; (r < n); (l++), (r++)) {
        if ((sums[l] > sums[prefix[(r - 1)]])) {
          (prefix[r] = l);
        } else {
          (prefix[r] = prefix[(r - 1)]);
        }
      }
    }
    Array<int> suffix = make_array<int>(n);
    (suffix[(n - k)] = (n - k));
    for (int l = ((n - k) - 1); (l >= 0); (l--)) {
      if ((sums[l] >= sums[suffix[(l + 1)]])) {
        (suffix[l] = l);
      } else {
        (suffix[l] = suffix[(l + 1)]);
      }
    }
    int a = 0;
    int b = 0;
    int c = 0;
    int max = 0;
    {
      int p = {};
      int s = {};
      int i = k;
      int j = ((2 * k) - 1);
      int sum = {};
      for (; (j < (n - k)); (i++), (j++)) {
        (p = prefix[(i - 1)]);
        (s = suffix[(j + 1)]);
        (sum = ((sums[p] + sums[i]) + sums[s]));
        if ((sum > max)) {
          (max = sum);
          (a = p);
          (b = i);
          (c = s);
        }
      }
    }
    return Array<int>{a, b, c};
  }
};

/* Original teaching comments:
// 三个无重叠子数组的最大和
// 给你一个整数数组 nums 和一个整数 k
// 找出三个长度为 k 、互不重叠、且全部数字和（3 * k 项）最大的子数组
// 并返回这三个子数组
// 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置
// 如果有多个结果，返回字典序最小的一个
// 测试链接 :
https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/
                // sums[i] : 以i开头并且长度为k的子数组的累加和
                        // l....r
                // prefix[i] :
                //
0~i范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
                                //
注意>，为了同样最大累加和的情况下，最小的字典序
                // suffix[i] :
                //
i~n-1范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
                                //
注意>=，为了同样最大累加和的情况下，最小的字典序
                // 0...i-1    i...j    j+1...n-1
                //   左     中(长度为k)     右
                        // 0.....i-1   i.....j  j+1.....n-1
                        // 最好开头p      i开头     最好开头s
                                //
注意>，为了同样最大累加和的情况下，最小的字典序
*/
