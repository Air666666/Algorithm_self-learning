// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/range-sum-query-immutable/

// Source: src/class046/Code01_PrefixSumArray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PrefixSumArray {
  struct NumArray;
  struct NumArray {
    Array<int> sum = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    NumArray(Array<int> nums) {
      (sum = make_array<int>((nums.length + 1)));
      for (int i = 1; (i <= nums.length); (i++)) {
        (sum[i] = (sum[(i - 1)] + nums[(i - 1)]));
      }
    }
    int sumRange(int left, int right) { return (sum[(right + 1)] - sum[left]); }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PrefixSumArray() {}
};

/* Original teaching comments:
// 利用前缀和快速得到区域累加和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-immutable/
*/
