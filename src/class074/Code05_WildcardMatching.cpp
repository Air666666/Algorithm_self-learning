// Source: src/class074/Code05_WildcardMatching.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_WildcardMatching {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_WildcardMatching() {}
  static bool isMatch1(String str, String pat) {
    Array<jchar> s = str.toCharArray();
    Array<jchar> p = pat.toCharArray();
    return Code05_WildcardMatching::f1(s, p, 0, 0);
  }
  static bool f1(Array<jchar> s, Array<jchar> p, int i, int j) {
    if ((i == s.length)) {
      if ((j == p.length)) {
        return true;
      } else {
        return ((p[j] == u'*') &&
                Code05_WildcardMatching::f1(s, p, i, (j + 1)));
      }
    } else if ((j == p.length)) {
      return false;
    } else {
      if ((p[j] != u'*')) {
        return (((s[i] == p[j]) || (p[j] == u'?')) &&
                Code05_WildcardMatching::f1(s, p, (i + 1), (j + 1)));
      } else {
        return (Code05_WildcardMatching::f1(s, p, (i + 1), j) ||
                Code05_WildcardMatching::f1(s, p, i, (j + 1)));
      }
    }
  }
  static bool isMatch2(String str, String pat) {
    Array<jchar> s = str.toCharArray();
    Array<jchar> p = pat.toCharArray();
    int n = s.length;
    int m = p.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    return Code05_WildcardMatching::f2(s, p, 0, 0, dp);
  }
  static bool f2(Array<jchar> s, Array<jchar> p, int i, int j,
                 Array<Array<int>> dp) {
    if ((dp[i][j] != 0)) {
      return (dp[i][j] == 1);
    }
    bool ans = {};
    if ((i == s.length)) {
      if ((j == p.length)) {
        (ans = true);
      } else {
        (ans = ((p[j] == u'*') &&
                Code05_WildcardMatching::f2(s, p, i, (j + 1), dp)));
      }
    } else if ((j == p.length)) {
      (ans = false);
    } else {
      if ((p[j] != u'*')) {
        (ans = (((s[i] == p[j]) || (p[j] == u'?')) &&
                Code05_WildcardMatching::f2(s, p, (i + 1), (j + 1), dp)));
      } else {
        (ans = (Code05_WildcardMatching::f2(s, p, (i + 1), j, dp) ||
                Code05_WildcardMatching::f2(s, p, i, (j + 1), dp)));
      }
    }
    (dp[i][j] = (ans ? 1 : 2));
    return ans;
  }
  static bool isMatch3(String str, String pat) {
    Array<jchar> s = str.toCharArray();
    Array<jchar> p = pat.toCharArray();
    int n = s.length;
    int m = p.length;
    Array<Array<bool>> dp = make_array<bool>((n + 1), (m + 1));
    (dp[n][m] = true);
    for (int j = (m - 1); ((j >= 0) && (p[j] == u'*')); (j--)) {
      (dp[n][j] = true);
    }
    for (int i = (n - 1); (i >= 0); (i--)) {
      for (int j = (m - 1); (j >= 0); (j--)) {
        if ((p[j] != u'*')) {
          (dp[i][j] =
               (((s[i] == p[j]) || (p[j] == u'?')) && dp[(i + 1)][(j + 1)]));
        } else {
          (dp[i][j] = (dp[(i + 1)][j] || dp[i][(j + 1)]));
        }
      }
    }
    return dp[0][0];
  }
};

/* Original teaching comments:
// 通配符匹配（和题目4高度相似，只是边界条件不同而已，而且更简单）
// 给你字符串s、字符串p
// s中一定不含有'?'、'*'字符，p中可能含有'?'、'*'字符
// '?' 表示可以变成任意字符，数量1个
// '*' 表示可以匹配任何字符串
// 请实现一个支持 '?' 和 '*' 的通配符匹配
// 返回p的整个字符串能不能匹配出s的整个字符串
// 测试链接 : https://leetcode.cn/problems/wildcard-matching/
        // 暴力递归
        // s[i....]能不能被p[j....]完全匹配出来
                        // s没了
                                // 如果p也没了，返回true
                                //
如果p[j]是*，可以消掉，然后看看p[j+1....]是不是都能消掉
                        // s有
                        // p没了
                                // s[i....]
                                // p[j....]
                                //
如果p[j]不是*，那么当前的字符必须能匹配：(s[i] == p[j] || p[j] == '?')
                                // 同时，后续也必须匹配上：process1(s, p, i + 1,
j + 1);
                                // s[i....]
                                // p[j....]
                                // 如果p[j]是*
                                // 选择1:
反正当前p[j]是*，必然可以搞定s[i]，那么继续 : process1(s, p, i + 1, j)
                                // 选择2:
虽然当前p[j]是*，但就是不让它搞定s[i]，那么继续 : process1(s, p, i, j + 1)
                                //
两种选择有一个能走通，答案就是true；如果都搞不定，答案就是false
        // 记忆化搜索
                // dp[i][j] == 0，表示没算过
                // dp[i][j] == 1，表示算过，答案是true
                // dp[i][j] == 2，表示算过，答案是false
        // 严格位置依赖的动态规划
*/
