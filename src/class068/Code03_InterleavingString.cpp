// Source: src/class068/Code03_InterleavingString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_InterleavingString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_InterleavingString() {}
  static bool isInterleave1(String str1, String str2, String str3) {
    if ([&]() {
          auto jleft = [&]() {
            auto jleft = str1.length();
            auto jright = str2.length();
            return (jleft + jright);
          }();
          auto jright = str3.length();
          return (jleft != jright);
        }()) {
      return false;
    }
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    Array<jchar> s3 = str3.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<bool>> dp = make_array<bool>((n + 1), (m + 1));
    (dp[0][0] = true);
    for (int i = 1; (i <= n); (i++)) {
      if ((s1[(i - 1)] != s3[(i - 1)])) {
        break;
      }
      (dp[i][0] = true);
    }
    for (int j = 1; (j <= m); (j++)) {
      if ((s2[(j - 1)] != s3[(j - 1)])) {
        break;
      }
      (dp[0][j] = true);
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        (dp[i][j] = (((s1[(i - 1)] == s3[((i + j) - 1)]) && dp[(i - 1)][j]) ||
                     ((s2[(j - 1)] == s3[((i + j) - 1)]) && dp[i][(j - 1)])));
      }
    }
    return dp[n][m];
  }
  static bool isInterleave2(String str1, String str2, String str3) {
    if ([&]() {
          auto jleft = [&]() {
            auto jleft = str1.length();
            auto jright = str2.length();
            return (jleft + jright);
          }();
          auto jright = str3.length();
          return (jleft != jright);
        }()) {
      return false;
    }
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    Array<jchar> s3 = str3.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<bool> dp = make_array<bool>((m + 1));
    (dp[0] = true);
    for (int j = 1; (j <= m); (j++)) {
      if ((s2[(j - 1)] != s3[(j - 1)])) {
        break;
      }
      (dp[j] = true);
    }
    for (int i = 1; (i <= n); (i++)) {
      (dp[0] = ((s1[(i - 1)] == s3[(i - 1)]) && dp[0]));
      for (int j = 1; (j <= m); (j++)) {
        (dp[j] = (((s1[(i - 1)] == s3[((i + j) - 1)]) && dp[j]) ||
                  ((s2[(j - 1)] == s3[((i + j) - 1)]) && dp[(j - 1)])));
      }
    }
    return dp[m];
  }
};

/* Original teaching comments:
// 交错字符串
// 给定三个字符串 s1、s2、s3
// 请帮忙验证s3是否由s1和s2交错组成
// 测试链接 : https://leetcode.cn/problems/interleaving-string/
        // 已经展示太多次从递归到动态规划了
        // 直接写动态规划吧
                // dp[i][j]:
                //
s1[前缀长度为i]和s2[前缀长度为j]，能否交错组成出s3[前缀长度为i+j]
        // 空间压缩
*/
