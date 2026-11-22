// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

// Source: src/class066/Code07_UniqueSubstringsWraparoundString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_UniqueSubstringsWraparoundString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_UniqueSubstringsWraparoundString() {}
  static int findSubstringInWraproundString(String str) {
    int n = str.length();
    Array<int> s = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (s[i] = (str.charAt(i) - u'a'));
    }
    Array<int> dp = make_array<int>(26);
    (dp[s[0]] = 1);
    {
      int i = 1;
      int cur = {};
      int pre = {};
      int len = 1;
      for (; (i < n); (i++)) {
        (cur = s[i]);
        (pre = s[(i - 1)]);
        if ((((pre == 25) && (cur == 0)) || ((pre + 1) == cur))) {
          (len++);
        } else {
          (len = 1);
        }
        (dp[cur] = jmax(dp[cur], len));
      }
    }
    int ans = 0;
    for (int i = 0; (i < 26); (i++)) {
      (ans += dp[i]);
    }
    return ans;
  }
};

/* Original teaching comments:
// 环绕字符串中唯一的子字符串
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
// 所以 base 看起来是这样的：
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
// 测试链接 :
https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
        // 时间复杂度O(n)，n是字符串s的长度，字符串base长度为正无穷
                // abcde...z -> 0, 1, 2, 3, 4....25
                // dp[0] :
s中必须以'a'的子串，最大延伸长度是多少，延伸一定要跟据base串的规则
                // s : c d e....
                //     2 3 4
                        // pre cur
                                // (前一个字符是'z' && 当前字符是'a') ||
前一个字符比当前字符的ascii码少1
*/
