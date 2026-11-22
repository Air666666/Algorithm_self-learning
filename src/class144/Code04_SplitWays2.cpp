// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/

// Source: src/class144/Code04_SplitWays2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SplitWays2 {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SplitWays2() {}
  static int countOfPairs(Array<int> arr) {
    int n = arr.length;
    int k = (arr[0] + 1);
    for (int i = 1; ((i < n) && (k > 0)); (i++)) {
      if ((arr[(i - 1)] > arr[i])) {
        (k -= (arr[(i - 1)] - arr[i]));
      }
    }
    if ((k <= 0)) {
      return 0;
    }
    return Code04_SplitWays2::c(((k + n) - 1), n);
  }
  static int c(int n, int k) {
    i64 fac = 1;
    i64 inv1 = 1;
    i64 inv2 = 1;
    for (int i = 1; (i <= n); (i++)) {
      (fac = jrem((fac * i), MOD));
      if ((i == k)) {
        (inv1 = Code04_SplitWays2::power(fac, (MOD - 2)));
      }
      if ((i == (n - k))) {
        (inv2 = Code04_SplitWays2::power(fac, (MOD - 2)));
      }
    }
    return static_cast<int>(jrem((jrem((fac * inv1), MOD) * inv2), MOD));
  }
  static i64 power(i64 x, i64 p) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (p = jshr(p, 1));
    }
    return ans;
  }
};

/* Original teaching comments:
// 分割的方法数
// 有同学找到了测试链接，题意几乎一样，而且数据量小很多
// 唯一的区别是：
// 课上讲的题意，单独的3可以分裂成(1, 2)、(2, 1)，一共两种方式
// 测试链接题意，单独的3可以分裂成(0, 3)、(1, 2)、(2, 1)、(3, 0)，一共四种方式
//
也就是对单独的v来说，课上讲的题意，分裂方式为v-1种。测试链接题意，分裂方式为v+1种
// 别的没有任何区别，实现代码中唯一有注释的那行，是仅有的改动
// 测试链接 : https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/
                // 原始题意，k = arr[0] - 1，这里改成，k = arr[0] + 1
                // 其他代码毫无区别
*/
