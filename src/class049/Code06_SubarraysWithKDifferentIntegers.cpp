// Source: src/class049/Code06_SubarraysWithKDifferentIntegers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_SubarraysWithKDifferentIntegers {
  inline static int MAXN = 20001;
  inline static Array<int> cnts = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_SubarraysWithKDifferentIntegers() {}
  static int subarraysWithKDistinct(Array<int> arr, int k) {
    return [&]() {
      auto jleft =
          Code06_SubarraysWithKDifferentIntegers::numsOfMostKinds(arr, k);
      auto jright =
          Code06_SubarraysWithKDifferentIntegers::numsOfMostKinds(arr, (k - 1));
      return (jleft - jright);
    }();
  }
  static int numsOfMostKinds(Array<int> arr, int k) {
    j::fill(cnts, 1, (arr.length + 1), 0);
    int ans = 0;
    {
      int l = 0;
      int r = 0;
      int collect = 0;
      for (; (r < arr.length); (r++)) {
        if (((++cnts[arr[r]]) == 1)) {
          (collect++);
        }
        while ((collect > k)) {
          if (((--cnts[arr[(l++)]]) == 0)) {
            (collect--);
          }
        }
        (ans += ((r - l) + 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// K个不同整数的子数组
// 给定一个正整数数组 nums和一个整数 k，返回 nums 中 「好子数组」 的数目。
// 如果 nums 的某个子数组中不同整数的个数恰好为 k
// 则称 nums 的这个连续、不一定不同的子数组为 「好子数组 」。
// 例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。
// 子数组 是数组的 连续 部分。
// 测试链接 : https://leetcode.cn/problems/subarrays-with-k-different-integers/
        // arr中有多少子数组，数字种类不超过k
        // arr的长度是n，arr里的数值1~n之间
*/
