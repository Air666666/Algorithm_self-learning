// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-valid-parentheses/

// Source: src/class066/Code06_LongestValidParentheses.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_LongestValidParentheses {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_LongestValidParentheses() {}
  static int longestValidParentheses(String str) {
    Array<jchar> s = str.toCharArray();
    Array<int> dp = make_array<int>(s.length);
    int ans = 0;
    {
      int i = 1;
      int p = {};
      for (; (i < s.length); (i++)) {
        if ((s[i] == u')')) {
          (p = ((i - dp[(i - 1)]) - 1));
          if (((p >= 0) && (s[p] == u'('))) {
            (dp[i] = ((dp[(i - 1)] + 2) + (((p - 1) >= 0) ? dp[(p - 1)] : 0)));
          }
        }
        (ans = jmax(ans, dp[i]));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 最长有效括号
// 给你一个只包含 '(' 和 ')' 的字符串
// 找出最长有效（格式正确且连续）括号子串的长度。
// 测试链接 : https://leetcode.cn/problems/longest-valid-parentheses/
        // 时间复杂度O(n)，n是str字符串的长度
                // dp[0...n-1]
                // dp[i] :
子串必须以i位置的字符结尾的情况下，往左整体有效的最大长度
                                //  ?         )
                                //  p         i
*/
