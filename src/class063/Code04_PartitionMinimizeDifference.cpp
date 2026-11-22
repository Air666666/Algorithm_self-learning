// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference/

// Source: src/class063/Code04_PartitionMinimizeDifference.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PartitionMinimizeDifference {
  struct Solution;
  struct Solution {
    inline static int MAXK = 16;
    inline static int MAXS = jshl(1, 15);
    inline static Array<int> lsiz = make_array<int>(MAXK);
    inline static Array<int> rsiz = make_array<int>(MAXK);
    inline static Array<Array<int>> lsum = make_array<int>(MAXK, MAXS);
    inline static Array<Array<int>> rsum = make_array<int>(MAXK, MAXS);
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
    static int minimumDifference(Array<int> nums) {
      int m = nums.length;
      int n = jshr(m, 1);
      int sum = 0;
      for (int num : nums) {
        (sum += num);
      }
      j::sort(nums);
      j::fill(lsiz, 0, (n + 1), 0);
      j::fill(rsiz, 0, (n + 1), 0);
      Solution::collect(nums, 0, n, 0, 0, lsum, lsiz);
      Solution::collect(nums, n, m, 0, 0, rsum, rsiz);
      for (int i = 0; (i <= n); (i++)) {
        j::sort(lsum[i], 0, lsiz[i]);
        j::sort(rsum[i], 0, rsiz[i]);
      }
      i64 ans = std::numeric_limits<i64>::max();
      for (int k = 0; (k <= n); (k++)) {
        int need = (n - k);
        {
          int i = 0;
          int j = (rsiz[need] - 1);
          for (; (i < lsiz[k]); (i++)) {
            while (((j > 0) && [&]() {
              auto jleft =
                  std::abs((static_cast<i64>(sum) -
                            (2LL * (lsum[k][i] + rsum[need][(j - 1)]))));
              auto jright = std::abs((static_cast<i64>(sum) -
                                      (2LL * (lsum[k][i] + rsum[need][j]))));
              return (jleft <= jright);
            }())) {
              (j--);
            }
            (ans = jmin(ans, std::abs((static_cast<i64>(sum) -
                                       (2LL * (lsum[k][i] + rsum[need][j]))))));
          }
        }
      }
      return static_cast<int>(ans);
    }
    static void collect(Array<int> nums, int i, int end, int s, int c,
                        Array<Array<int>> sum, Array<int> siz) {
      if ((i == end)) {
        (sum[c][(siz[c]++)] = s);
      } else {
        int j = (i + 1);
        while (((j < end) && (nums[j] == nums[i]))) {
          (j++);
        }
        for (int k = 0; (k <= (j - i)); (k++)) {
          Solution::collect(nums, j, end, (s + (k * nums[i])), (c + k), sum,
                            siz);
        }
      }
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PartitionMinimizeDifference() {}
};

/* Original teaching comments:
// 将数组分成两个数组并最小化数组和的差
// 这道题课上没讲，其实就是题目3加上了选取数字个数的限制
// 比如一共30个数，分配到两个部分
// 要求每个部分都是15个数，并且做到累加和差值最小
// 那么就是题目3的代码，加上个数的考虑就可以，以下代码提交可以直接通过
// 测试链接 :
https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
                // siz[k] : 选了k个数的情况下，一共有多少个累加和
                // sum[k][...] : 选了k个数的情况下，收集的每个累加和都是什么
                // 到底有几个累加和？就是siz[k]的数量
                        // 排序只是为了递归收集时压缩相同数字，常数优化
*/
