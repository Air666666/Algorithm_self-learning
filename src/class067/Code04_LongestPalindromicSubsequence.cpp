// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-palindromic-subsequence/

// Source: src/class067/Code04_LongestPalindromicSubsequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LongestPalindromicSubsequence {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LongestPalindromicSubsequence() {}
  static int longestPalindromeSubseq1(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    return Code04_LongestPalindromicSubsequence::f1(s, 0, (n - 1));
  }
  static int f1(Array<jchar> s, int l, int r) {
    if ((l == r)) {
      return 1;
    }
    if (((l + 1) == r)) {
      return ((s[l] == s[r]) ? 2 : 1);
    }
    if ((s[l] == s[r])) {
      return (2 +
              Code04_LongestPalindromicSubsequence::f1(s, (l + 1), (r - 1)));
    } else {
      return [&]() {
        auto jargument_0 =
            Code04_LongestPalindromicSubsequence::f1(s, (l + 1), r);
        auto jargument_1 =
            Code04_LongestPalindromicSubsequence::f1(s, l, (r - 1));
        return jmax(jargument_0, jargument_1);
      }();
    }
  }
  static int longestPalindromeSubseq2(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    return Code04_LongestPalindromicSubsequence::f2(s, 0, (n - 1), dp);
  }
  static int f2(Array<jchar> s, int l, int r, Array<Array<int>> dp) {
    if ((l == r)) {
      return 1;
    }
    if (((l + 1) == r)) {
      return ((s[l] == s[r]) ? 2 : 1);
    }
    if ((dp[l][r] != 0)) {
      return dp[l][r];
    }
    int ans = {};
    if ((s[l] == s[r])) {
      (ans = (2 + Code04_LongestPalindromicSubsequence::f2(s, (l + 1), (r - 1),
                                                           dp)));
    } else {
      (ans = [&]() {
        auto jargument_0 =
            Code04_LongestPalindromicSubsequence::f2(s, (l + 1), r, dp);
        auto jargument_1 =
            Code04_LongestPalindromicSubsequence::f2(s, l, (r - 1), dp);
        return jmax(jargument_0, jargument_1);
      }());
    }
    (dp[l][r] = ans);
    return ans;
  }
  static int longestPalindromeSubseq3(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int l = (n - 1); (l >= 0); (l--)) {
      (dp[l][l] = 1);
      if (((l + 1) < n)) {
        (dp[l][(l + 1)] = ((s[l] == s[(l + 1)]) ? 2 : 1));
      }
      for (int r = (l + 2); (r < n); (r++)) {
        if ((s[l] == s[r])) {
          (dp[l][r] = (2 + dp[(l + 1)][(r - 1)]));
        } else {
          (dp[l][r] = jmax(dp[(l + 1)][r], dp[l][(r - 1)]));
        }
      }
    }
    return dp[0][(n - 1)];
  }
  static int longestPalindromeSubseq4(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<int> dp = make_array<int>(n);
    {
      int l = (n - 1);
      int leftDown = 0;
      int backup = {};
      for (; (l >= 0); (l--)) {
        (dp[l] = 1);
        if (((l + 1) < n)) {
          (leftDown = dp[(l + 1)]);
          (dp[(l + 1)] = ((s[l] == s[(l + 1)]) ? 2 : 1));
        }
        for (int r = (l + 2); (r < n); (r++)) {
          (backup = dp[r]);
          if ((s[l] == s[r])) {
            (dp[r] = (2 + leftDown));
          } else {
            (dp[r] = jmax(dp[r], dp[(r - 1)]));
          }
          (leftDown = backup);
        }
      }
    }
    return dp[(n - 1)];
  }
};

/* Original teaching comments:
// 最长回文子序列
// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度
// 测试链接 : https://leetcode.cn/problems/longest-palindromic-subsequence/
        // 最长回文子序列问题可以转化成最长公共子序列问题
        // 不过这里讲述区间动态规划的思路
        // 区间dp还会有单独的视频做详细讲述
        // s[l...r]最长回文子序列长度
        // l <= r
                        // dp[l] : 想象中的dp[l][l]
                                // dp[l+1] : 想象中的dp[l][l+1]
*/
