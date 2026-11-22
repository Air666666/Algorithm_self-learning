// Source: src/class105/Code04_RepeatedStringMatch.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_RepeatedStringMatch {
  inline static int MAXN = 30001;
  inline static Array<jchar> s = make_array<jchar>(MAXN);
  inline static int base = 499;
  inline static Array<i64> pow = make_array<i64>(MAXN);
  inline static Array<i64> hash = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_RepeatedStringMatch() {}
  static int repeatedStringMatch(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    int k = jdiv(((m + n) - 1), n);
    int len = 0;
    for (int cnt = 0; (cnt <= k); (cnt++)) {
      for (int i = 0; (i < n); (i++)) {
        (s[(len++)] = s1[i]);
      }
    }
    Code04_RepeatedStringMatch::build(len);
    i64 h2 = ((s2[0] - u'a') + 1);
    for (int i = 1; (i < m); (i++)) {
      (h2 = ((((h2 * base) + s2[i]) - u'a') + 1));
    }
    {
      int l = 0;
      int r = (m - 1);
      for (; (r < len); (l++), (r++)) {
        if ((Code04_RepeatedStringMatch::hash_method(l, r) == h2)) {
          return ((r < (n * k)) ? k : (k + 1));
        }
      }
    }
    return (-1);
  }
  static void build(int n) {
    (pow[0] = 1);
    for (int i = 1; (i < n); (i++)) {
      (pow[i] = (pow[(i - 1)] * base));
    }
    (hash[0] = ((s[0] - u'a') + 1));
    for (int i = 1; (i < n); (i++)) {
      (hash[i] = ((((hash[(i - 1)] * base) + s[i]) - u'a') + 1));
    }
  }
  static i64 hash_method(int l, int r) {
    i64 ans = hash[r];
    (ans -= ((l == 0) ? 0 : (hash[(l - 1)] * pow[((r - l) + 1)])));
    return ans;
  }
};

/* Original teaching comments:
// 重复叠加字符串匹配
//
给定两个字符串a和b，寻找重复叠加字符串a的最小次数，使得字符串b成为叠加后的字符串a的子串
// 如果不存在则返回-1
// 字符串"abc"重复叠加0次是""
// 重复叠加1次是"abc"
// 重复叠加2次是"abcabc"
// 测试链接 : https://leetcode.cn/problems/repeated-string-match/
                // m / n 向上取整
*/
