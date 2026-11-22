// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other

// Source: src/class081/Code01_NumberOfWaysWearDifferentHats.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_NumberOfWaysWearDifferentHats {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_NumberOfWaysWearDifferentHats() {}
  static int numberWays(JList<JList<int>> arr) {
    int m = 0;
    for (JList<int> person : arr) {
      for (int hat : person) {
        (m = jmax(m, hat));
      }
    }
    int n = arr.size();
    Array<int> hats = make_array<int>((m + 1));
    for (int pi = 0; (pi < n); (pi++)) {
      for (int hat : arr.get(pi)) {
        (hats[hat] |= jshl(1, pi));
      }
    }
    Array<Array<int>> dp = make_array<int>((m + 1), jshl(1, n));
    for (int i = 0; (i <= m); (i++)) {
      j::fill(dp[i], (-1));
    }
    return Code01_NumberOfWaysWearDifferentHats::f2(hats, m, n, 1, 0, dp);
  }
  static int f1(Array<int> hats, int m, int n, int i, int s,
                Array<Array<int>> dp) {
    if ((s == (jshl(1, n) - 1))) {
      return 1;
    }
    if ((i == (m + 1))) {
      return 0;
    }
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int ans =
        Code01_NumberOfWaysWearDifferentHats::f1(hats, m, n, (i + 1), s, dp);
    int cur = hats[i];
    for (int p = 0; (p < n); (p++)) {
      if ((((cur & jshl(1, p)) != 0) && ((s & jshl(1, p)) == 0))) {
        (ans = jrem((ans + Code01_NumberOfWaysWearDifferentHats::f1(
                               hats, m, n, (i + 1), (s | jshl(1, p)), dp)),
                    MOD));
      }
    }
    (dp[i][s] = ans);
    return ans;
  }
  static int f2(Array<int> hats, int m, int n, int i, int s,
                Array<Array<int>> dp) {
    if ((s == (jshl(1, n) - 1))) {
      return 1;
    }
    if ((i == (m + 1))) {
      return 0;
    }
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int ans =
        Code01_NumberOfWaysWearDifferentHats::f2(hats, m, n, (i + 1), s, dp);
    int cur = hats[i];
    int rightOne = {};
    while ((cur != 0)) {
      (rightOne = (cur & (-cur)));
      if (((s & rightOne) == 0)) {
        (ans = jrem((ans + Code01_NumberOfWaysWearDifferentHats::f2(
                               hats, m, n, (i + 1), (s | rightOne), dp)),
                    MOD));
      }
      (cur ^= rightOne);
    }
    (dp[i][s] = ans);
    return ans;
  }
};

/* Original teaching comments:
// 每个人戴不同帽子的方案数
// 总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40
// 给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表
//
请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 :
https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other
                // 帽子颜色的最大值
                // 1 ~ m 帽子，能满足哪些人，状态信息 -> int
        // m : 帽子颜色的最大值, 1 ~ m
        // n : 人的数量，0 ~ n-1
        // i : 来到了什么颜色的帽子
        // s : n个人，谁没满足状态就是0，谁满足了状态就是1
        // dp : 记忆化搜索的表
        // 返回 : 有多少种方法
                // 还有人没满足
                // 可能性1 : i颜色的帽子，不分配给任何人
                // 可能性2 : i颜色的帽子，分配给可能的每一个人
                // 用for循环从0 ~ n-1枚举每个人
                // 不用for循环枚举
                // 从当前帽子中依次提取能满足的人
                // 提取出二进制状态中最右侧的1，讲解030-异或运算，题目5，Brian
Kernighan算法
                // cur :
                // 0 0 0 1 1 0 1 0
                // -> 0 0 0 0 0 0 1 0
                // -> 0 0 0 0 1 0 0 0
                // -> 0 0 0 1 0 0 0 0
*/
