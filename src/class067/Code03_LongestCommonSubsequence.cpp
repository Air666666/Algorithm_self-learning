// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-common-subsequence/

// Source: src/class067/Code03_LongestCommonSubsequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_LongestCommonSubsequence {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_LongestCommonSubsequence() {}
  static int longestCommonSubsequence1(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    return Code03_LongestCommonSubsequence::f1(s1, s2, (n - 1), (m - 1));
  }
  static int f1(Array<jchar> s1, Array<jchar> s2, int i1, int i2) {
    if (((i1 < 0) || (i2 < 0))) {
      return 0;
    }
    int p1 = Code03_LongestCommonSubsequence::f1(s1, s2, (i1 - 1), (i2 - 1));
    int p2 = Code03_LongestCommonSubsequence::f1(s1, s2, (i1 - 1), i2);
    int p3 = Code03_LongestCommonSubsequence::f1(s1, s2, i1, (i2 - 1));
    int p4 = ((s1[i1] == s2[i2]) ? (p1 + 1) : 0);
    return [&]() {
      auto jargument_0 = jmax(p1, p2);
      auto jargument_1 = jmax(p3, p4);
      return jmax(jargument_0, jargument_1);
    }();
  }
  static int longestCommonSubsequence2(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    return Code03_LongestCommonSubsequence::f2(s1, s2, n, m);
  }
  static int f2(Array<jchar> s1, Array<jchar> s2, int len1, int len2) {
    if (((len1 == 0) || (len2 == 0))) {
      return 0;
    }
    int ans = {};
    if ((s1[(len1 - 1)] == s2[(len2 - 1)])) {
      (ans = (Code03_LongestCommonSubsequence::f2(s1, s2, (len1 - 1),
                                                  (len2 - 1)) +
              1));
    } else {
      (ans = [&]() {
        auto jargument_0 =
            Code03_LongestCommonSubsequence::f2(s1, s2, (len1 - 1), len2);
        auto jargument_1 =
            Code03_LongestCommonSubsequence::f2(s1, s2, len1, (len2 - 1));
        return jmax(jargument_0, jargument_1);
      }());
    }
    return ans;
  }
  static int longestCommonSubsequence3(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 0; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code03_LongestCommonSubsequence::f3(s1, s2, n, m, dp);
  }
  static int f3(Array<jchar> s1, Array<jchar> s2, int len1, int len2,
                Array<Array<int>> dp) {
    if (((len1 == 0) || (len2 == 0))) {
      return 0;
    }
    if ((dp[len1][len2] != (-1))) {
      return dp[len1][len2];
    }
    int ans = {};
    if ((s1[(len1 - 1)] == s2[(len2 - 1)])) {
      (ans = (Code03_LongestCommonSubsequence::f3(s1, s2, (len1 - 1),
                                                  (len2 - 1), dp) +
              1));
    } else {
      (ans = [&]() {
        auto jargument_0 =
            Code03_LongestCommonSubsequence::f3(s1, s2, (len1 - 1), len2, dp);
        auto jargument_1 =
            Code03_LongestCommonSubsequence::f3(s1, s2, len1, (len2 - 1), dp);
        return jmax(jargument_0, jargument_1);
      }());
    }
    (dp[len1][len2] = ans);
    return ans;
  }
  static int longestCommonSubsequence4(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int len1 = 1; (len1 <= n); (len1++)) {
      for (int len2 = 1; (len2 <= m); (len2++)) {
        if ((s1[(len1 - 1)] == s2[(len2 - 1)])) {
          (dp[len1][len2] = (1 + dp[(len1 - 1)][(len2 - 1)]));
        } else {
          (dp[len1][len2] = jmax(dp[(len1 - 1)][len2], dp[len1][(len2 - 1)]));
        }
      }
    }
    return dp[n][m];
  }
  static int longestCommonSubsequence5(String str1, String str2) {
    Array<jchar> s1 = {};
    Array<jchar> s2 = {};
    if ([&]() {
          auto jleft = str1.length();
          auto jright = str2.length();
          return (jleft >= jright);
        }()) {
      (s1 = str1.toCharArray());
      (s2 = str2.toCharArray());
    } else {
      (s1 = str2.toCharArray());
      (s2 = str1.toCharArray());
    }
    int n = s1.length;
    int m = s2.length;
    Array<int> dp = make_array<int>((m + 1));
    for (int len1 = 1; (len1 <= n); (len1++)) {
      int leftUp = 0;
      int backup = {};
      for (int len2 = 1; (len2 <= m); (len2++)) {
        (backup = dp[len2]);
        if ((s1[(len1 - 1)] == s2[(len2 - 1)])) {
          (dp[len2] = (1 + leftUp));
        } else {
          (dp[len2] = jmax(dp[len2], dp[(len2 - 1)]));
        }
        (leftUp = backup);
      }
    }
    return dp[m];
  }
};

/* Original teaching comments:
// 最长公共子序列
// 给定两个字符串text1和text2
// 返回这两个字符串的最长 公共子序列 的长度
// 如果不存在公共子序列，返回0
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列
// 测试链接 : https://leetcode.cn/problems/longest-common-subsequence/
        // s1[0....i1]与s2[0....i2]最长公共子序列长度
        // 为了避免很多边界讨论
        // 很多时候往往不用下标来定义尝试，而是用长度来定义尝试
        // 因为长度最短是0，而下标越界的话讨论起来就比较麻烦
        // s1[前缀长度为len1]对应s2[前缀长度为len2]
        // 最长公共子序列长度
        // 记忆化搜索
        // 严格位置依赖的动态规划
        // 严格位置依赖的动态规划 + 空间压缩
*/
