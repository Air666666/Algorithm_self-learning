// Source: src/class049/Code05_ReplaceTheSubstringForBalancedString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ReplaceTheSubstringForBalancedString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ReplaceTheSubstringForBalancedString() {}
  static int balancedString(String str) {
    int n = str.length();
    Array<int> s = make_array<int>(n);
    Array<int> cnts = make_array<int>(4);
    for (int i = 0; (i < n); (i++)) {
      jchar c = str.charAt(i);
      (s[i] = ((c == u'W') ? 1 : ((c == u'E') ? 2 : ((c == u'R') ? 3 : 0))));
      (cnts[s[i]]++);
    }
    int debt = 0;
    for (int i = 0; (i < 4); (i++)) {
      if ((cnts[i] < jdiv(n, 4))) {
        (cnts[i] = 0);
      } else {
        (cnts[i] = (jdiv(n, 4) - cnts[i]));
        (debt -= cnts[i]);
      }
    }
    if ((debt == 0)) {
      return 0;
    }
    int ans = std::numeric_limits<int>::max();
    {
      int l = 0;
      int r = 0;
      for (; (r < n); (r++)) {
        if (((cnts[s[r]]++) < 0)) {
          (debt--);
        }
        if ((debt == 0)) {
          while ((cnts[s[l]] > 0)) {
            (cnts[s[(l++)]]--);
          }
          (ans = jmin(ans, ((r - l) + 1)));
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 替换子串得到平衡字符串
// 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
// 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
// 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s
变成一个「平衡字符串」。
// 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
// 请返回待替换子串的最小可能长度。
// 如果原字符串自身就是一个平衡字符串，则返回 0。
// 测试链接 :
https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
*/
