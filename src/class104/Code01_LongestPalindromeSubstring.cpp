// Source: src/class104/Code01_LongestPalindromeSubstring.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LongestPalindromeSubstring {
  inline static int MAXN = 1001;
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static int n = {};
  inline static int max = {};
  inline static int end = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LongestPalindromeSubstring() {}
  static String longestPalindrome(String s) {
    Code01_LongestPalindromeSubstring::manacher(s);
    return s.substring((end - max), end);
  }
  static void manacher(String str) {
    Code01_LongestPalindromeSubstring::manacherss(str.toCharArray());
    (max = (end = 0));
    {
      int i = 0;
      int c = 0;
      int r = 0;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin(p[((2 * c) - i)], (r - i)) : 1));
        while (((((i + len) < n) && ((i - len) >= 0)) &&
                (ss[(i + len)] == ss[(i - len)]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        if ((len > max)) {
          (max = (len - 1));
          (end = jdiv(((i + len) - 1), 2));
        }
        (p[i] = len);
      }
    }
  }
  static void manacherss(Array<jchar> a) {
    (n = ((a.length * 2) + 1));
    {
      int i = 0;
      int j = 0;
      for (; (i < n); (i++)) {
        (ss[i] = (((i & 1) == 0) ? u'#' : a[(j++)]));
      }
    }
  }
};

/* Original teaching comments:
// 最长回文子串
// 找到字符串s中最长的回文子串并返回
// 测试链接 : https://leetcode.cn/problems/longest-palindromic-substring/
*/
