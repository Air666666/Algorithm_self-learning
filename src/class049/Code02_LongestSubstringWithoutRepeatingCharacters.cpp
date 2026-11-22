// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

// Source: src/class049/Code02_LongestSubstringWithoutRepeatingCharacters.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LongestSubstringWithoutRepeatingCharacters {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LongestSubstringWithoutRepeatingCharacters() {}
  static int lengthOfLongestSubstring(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<int> last = make_array<int>(256);
    j::fill(last, (-1));
    int ans = 0;
    {
      int l = 0;
      int r = 0;
      for (; (r < n); (r++)) {
        (l = jmax(l, (last[s[r]] + 1)));
        (ans = jmax(ans, ((r - l) + 1)));
        (last[s[r]] = r);
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 测试链接 :
https://leetcode.cn/problems/longest-substring-without-repeating-characters/
                // char -> int -> 0 ~ 255
                // 每一种字符上次出现的位置
                // 所有字符都没有上次出现的位置
                // 不含有重复字符的 最长子串 的长度
                        // 更新当前字符上一次出现的位置
*/
