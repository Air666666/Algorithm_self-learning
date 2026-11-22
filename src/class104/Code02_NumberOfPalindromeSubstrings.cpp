// Source: src/class104/Code02_NumberOfPalindromeSubstrings.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NumberOfPalindromeSubstrings {
  inline static int MAXN = 1001;
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NumberOfPalindromeSubstrings() {}
  static int countSubstrings(String s) {
    Code02_NumberOfPalindromeSubstrings::manacher(s);
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (ans += jdiv(p[i], 2));
    }
    return ans;
  }
  static void manacher(String str) {
    Code02_NumberOfPalindromeSubstrings::manacherss(str.toCharArray());
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
// 回文子串数量
// 返回字符串s的回文子串数量
// 测试链接 : https://leetcode.cn/problems/palindromic-substrings/
*/
