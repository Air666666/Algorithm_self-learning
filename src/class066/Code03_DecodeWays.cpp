// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/decode-ways/

// Source: src/class066/Code03_DecodeWays.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DecodeWays {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DecodeWays() {}
  static int numDecodings1(String s) {
    return Code03_DecodeWays::f1(s.toCharArray(), 0);
  }
  static int f1(Array<jchar> s, int i) {
    if ((i == s.length)) {
      return 1;
    }
    int ans = {};
    if ((s[i] == u'0')) {
      (ans = 0);
    } else {
      (ans = Code03_DecodeWays::f1(s, (i + 1)));
      if ((((i + 1) < s.length) &&
           (((((s[i] - u'0') * 10) + s[(i + 1)]) - u'0') <= 26))) {
        (ans += Code03_DecodeWays::f1(s, (i + 2)));
      }
    }
    return ans;
  }
  static int numDecodings2(String s) {
    Array<int> dp = make_array<int>(s.length());
    j::fill(dp, (-1));
    return Code03_DecodeWays::f2(s.toCharArray(), 0, dp);
  }
  static int f2(Array<jchar> s, int i, Array<int> dp) {
    if ((i == s.length)) {
      return 1;
    }
    if ((dp[i] != (-1))) {
      return dp[i];
    }
    int ans = {};
    if ((s[i] == u'0')) {
      (ans = 0);
    } else {
      (ans = Code03_DecodeWays::f2(s, (i + 1), dp));
      if ((((i + 1) < s.length) &&
           (((((s[i] - u'0') * 10) + s[(i + 1)]) - u'0') <= 26))) {
        (ans += Code03_DecodeWays::f2(s, (i + 2), dp));
      }
    }
    (dp[i] = ans);
    return ans;
  }
  static int numDecodings3(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<int> dp = make_array<int>((n + 1));
    (dp[n] = 1);
    for (int i = (n - 1); (i >= 0); (i--)) {
      if ((s[i] == u'0')) {
        (dp[i] = 0);
      } else {
        (dp[i] = dp[(i + 1)]);
        if ((((i + 1) < s.length) &&
             (((((s[i] - u'0') * 10) + s[(i + 1)]) - u'0') <= 26))) {
          (dp[i] += dp[(i + 2)]);
        }
      }
    }
    return dp[0];
  }
  static int numDecodings4(String s) {
    int next = 1;
    int nextNext = 0;
    {
      int i = (s.length() - 1);
      int cur = {};
      for (; (i >= 0); (i--)) {
        if ((s.charAt(i) == u'0')) {
          (cur = 0);
        } else {
          (cur = next);
          if ((((i + 1) < s.length()) && (([&]() {
                                            auto jleft =
                                                ((s.charAt(i) - u'0') * 10);
                                            auto jright = s.charAt((i + 1));
                                            return (jleft + jright);
                                          }() -
                                           u'0') <= 26))) {
            (cur += nextNext);
          }
        }
        (nextNext = next);
        (next = cur);
      }
    }
    return next;
  }
};

/* Original teaching comments:
// 解码方法
// 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码
已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，消息不能分组为(1 11 06)，因为 "06" 不能映射为 "F"
// 这是由于 "6" 和 "06" 在映射中并不等价
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数
// 题目数据保证答案肯定是一个 32位 的整数
// 测试链接 : https://leetcode.cn/problems/decode-ways/
        // 暴力尝试
        // s : 数字字符串
        // s[i....]有多少种有效的转化方案
        // 暴力尝试改记忆化搜索
        // 严格位置依赖的动态规划
        // 严格位置依赖的动态规划 + 空间压缩
                // dp[i+1]
                // dp[i+2]
*/
