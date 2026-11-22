// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/the-number-of-good-subsets/

// Source: src/class081/Code03_TheNumberOfGoodSubsets.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TheNumberOfGoodSubsets {
  inline static int MAXV = 30;
  inline static int LIMIT = jshl(1, 10);
  inline static int MOD = 1000000007;
  inline static Array<int> own = Array<int>{
      0b0000000000, 0b0000000000, 0b0000000001, 0b0000000010, 0b0000000000,
      0b0000000100, 0b0000000011, 0b0000001000, 0b0000000000, 0b0000000000,
      0b0000000101, 0b0000010000, 0b0000000000, 0b0000100000, 0b0000001001,
      0b0000000110, 0b0000000000, 0b0001000000, 0b0000000000, 0b0010000000,
      0b0000000000, 0b0000001010, 0b0000010001, 0b0100000000, 0b0000000000,
      0b0000000000, 0b0000100001, 0b0000000000, 0b0000000000, 0b1000000000,
      0b0000000111};
  inline static Array<int> cnt = make_array<int>((MAXV + 1));
  inline static Array<int> dp = make_array<int>(LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TheNumberOfGoodSubsets() {}
  static int numberOfGoodSubsets1(Array<int> nums) {
    Array<int> cnt = make_array<int>((MAXV + 1));
    for (int num : nums) {
      (cnt[num]++);
    }
    Array<Array<int>> dp = make_array<int>((MAXV + 1), LIMIT);
    for (int i = 0; (i <= MAXV); (i++)) {
      j::fill(dp[i], (-1));
    }
    int ans = 0;
    for (int s = 1; (s < LIMIT); (s++)) {
      (ans = jrem((ans + Code03_TheNumberOfGoodSubsets::f1(MAXV, s, cnt, dp)),
                  MOD));
    }
    return ans;
  }
  static int f1(int i, int s, Array<int> cnt, Array<Array<int>> dp) {
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int ans = 0;
    if ((i == 1)) {
      if ((s == 0)) {
        (ans = 1);
        for (int j = 0; (j < cnt[1]); (j++)) {
          (ans = jrem(jshl(ans, 1), MOD));
        }
      }
    } else {
      (ans = Code03_TheNumberOfGoodSubsets::f1((i - 1), s, cnt, dp));
      int cur = own[i];
      int times = cnt[i];
      if ((((cur != 0) && (times != 0)) && ((s & cur) == cur))) {
        (ans = static_cast<int>(
             jrem(((static_cast<i64>(Code03_TheNumberOfGoodSubsets::f1(
                        (i - 1), (s ^ cur), cnt, dp)) *
                    times) +
                   ans),
                  MOD)));
      }
    }
    (dp[i][s] = ans);
    return ans;
  }
  static int numberOfGoodSubsets2(Array<int> nums) {
    j::fill(cnt, 0);
    j::fill(dp, 0);
    for (int num : nums) {
      (cnt[num]++);
    }
    (dp[0] = 1);
    for (int i = 0; (i < cnt[1]); (i++)) {
      (dp[0] = jrem(jshl(dp[0], 1), MOD));
    }
    {
      int i = 2;
      int cur = {};
      int times = {};
      for (; (i <= MAXV); (i++)) {
        (cur = own[i]);
        (times = cnt[i]);
        if (((cur != 0) && (times != 0))) {
          for (int status = (LIMIT - 1); (status >= 0); (status--)) {
            if (((status & cur) == cur)) {
              (dp[status] = static_cast<int>(
                   jrem(((static_cast<i64>(dp[(status ^ cur)]) * times) +
                         dp[status]),
                        MOD)));
            }
          }
        }
      }
    }
    int ans = 0;
    for (int s = 1; (s < LIMIT); (s++)) {
      (ans = jrem((ans + dp[s]), MOD));
    }
    return ans;
  }
};

/* Original teaching comments:
// 好子集的数目
// 给你一个整数数组 nums，好子集的定义如下：
// nums的某个子集，所有元素的乘积可以表示为一个或多个互不相同质数的乘积
// 比如nums = [1, 2, 3, 4]
// [2, 3]，[1, 2, 3]，[1, 3] 是好子集
// 乘积分别为6=2*3，6=2*3，3=3
// [1, 4]和[4]不是好子集，因为乘积分别为4=2*2和4=2*2
// 返回nums中不同的好子集的数目，答案对 1000000007 取模
// 如果两个子集删除的下标不同，那么它们被视为不同的子集
// 测试链接 : https://leetcode.cn/problems/the-number-of-good-subsets/
        // 打个表来加速判断
        // 如果一个数字拥有某一种质数因子不只1个
        // 那么认为这个数字无效，状态全是0，0b0000000000
        // 如果一个数字拥有任何一种质数因子都不超过1个
        // 那么认为这个数字有效，用位信息表示这个数字拥有质数因子的状态
        // 比如12，拥有2这种质数因子不只1个，所以无效，用0b0000000000表示
        // 比如14，拥有2这种质数因子不超过1个，拥有7这种质数因子不超过1个，有效
        // 从高位到低位依次表示：...13 11 7 5 3 2
        // 所以用0b0000001001表示14拥有质数因子的状态
        // 质数: 29 23 19 17 13 11 7 5 3 2
        // 位置: 9 8 7 6 5 4 3 2 1 0
        // 记忆化搜索
                // 1 ~ 30
        // 1....i范围的数字，每种数字cnt[i]个
        // 最终相乘的结果一定要让质因子的状态为s，且每种质因子只能有1个
        // 请问子集的数量是多少
        // s每一位代表的质因子如下
        // 质数: 29 23 19 17 13 11 7 5 3 2
        // 位置: 9 8 7 6 5 4 3 2 1 0
                                // 能要i这个数字
        // 空间压缩优化
*/
