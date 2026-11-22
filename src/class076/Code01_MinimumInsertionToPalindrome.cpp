// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Source: src/class076/Code01_MinimumInsertionToPalindrome.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumInsertionToPalindrome {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumInsertionToPalindrome() {}
  static int minInsertions1(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    return Code01_MinimumInsertionToPalindrome::f1(s, 0, (n - 1));
  }
  static int f1(Array<jchar> s, int l, int r) {
    if ((l == r)) {
      return 0;
    }
    if (((l + 1) == r)) {
      return ((s[l] == s[r]) ? 0 : 1);
    }
    if ((s[l] == s[r])) {
      return Code01_MinimumInsertionToPalindrome::f1(s, (l + 1), (r - 1));
    } else {
      return ([&]() {
        auto jargument_0 =
            Code01_MinimumInsertionToPalindrome::f1(s, l, (r - 1));
        auto jargument_1 =
            Code01_MinimumInsertionToPalindrome::f1(s, (l + 1), r);
        return jmin(jargument_0, jargument_1);
      }() + 1);
    }
  }
  static int minInsertions2(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = i; (j < n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code01_MinimumInsertionToPalindrome::f2(s, 0, (n - 1), dp);
  }
  static int f2(Array<jchar> s, int l, int r, Array<Array<int>> dp) {
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = {};
    if ((l == r)) {
      (ans = 0);
    } else if (((l + 1) == r)) {
      (ans = ((s[l] == s[(l + 1)]) ? 0 : 1));
    } else {
      if ((s[l] == s[r])) {
        (ans =
             Code01_MinimumInsertionToPalindrome::f2(s, (l + 1), (r - 1), dp));
      } else {
        (ans = ([&]() {
           auto jargument_0 =
               Code01_MinimumInsertionToPalindrome::f2(s, l, (r - 1), dp);
           auto jargument_1 =
               Code01_MinimumInsertionToPalindrome::f2(s, (l + 1), r, dp);
           return jmin(jargument_0, jargument_1);
         }() + 1));
      }
    }
    (dp[l][r] = ans);
    return ans;
  }
  static int minInsertions3(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int l = 0; (l < (n - 1)); (l++)) {
      (dp[l][(l + 1)] = ((s[l] == s[(l + 1)]) ? 0 : 1));
    }
    for (int l = (n - 3); (l >= 0); (l--)) {
      for (int r = (l + 2); (r < n); (r++)) {
        if ((s[l] == s[r])) {
          (dp[l][r] = dp[(l + 1)][(r - 1)]);
        } else {
          (dp[l][r] = (jmin(dp[l][(r - 1)], dp[(l + 1)][r]) + 1));
        }
      }
    }
    return dp[0][(n - 1)];
  }
  static int minInsertions4(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    if ((n < 2)) {
      return 0;
    }
    Array<int> dp = make_array<int>(n);
    (dp[(n - 1)] = ((s[(n - 2)] == s[(n - 1)]) ? 0 : 1));
    {
      int l = (n - 3);
      int leftDown = {};
      int backUp = {};
      for (; (l >= 0); (l--)) {
        (leftDown = dp[(l + 1)]);
        (dp[(l + 1)] = ((s[l] == s[(l + 1)]) ? 0 : 1));
        for (int r = (l + 2); (r < n); (r++)) {
          (backUp = dp[r]);
          if ((s[l] == s[r])) {
            (dp[r] = leftDown);
          } else {
            (dp[r] = (jmin(dp[(r - 1)], dp[r]) + 1));
          }
          (leftDown = backUp);
        }
      }
    }
    return dp[(n - 1)];
  }
};

/* Original teaching comments:
// 让字符串成为回文串的最少插入次数
// 给你一个字符串 s
// 每一次操作你都可以在字符串的任意位置插入任意字符
// 请你返回让s成为回文串的最少操作次数
// 测试链接 :
https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
        // 暴力尝试
        // s[l....r]这个范围上的字符串，整体都变成回文串
        // 返回至少插入几个字符
                // l <= r
                // l...r不只两个字符
        // 记忆化搜索
        // 严格位置依赖的动态规划
        // 空间压缩
        //
本题有关空间压缩的实现，可以参考讲解067，题目4，最长回文子序列问题的讲解
        // 这两个题空间压缩写法高度相似
        // 因为之前的课多次讲过空间压缩的内容，所以这里不再赘述
*/
