// Source: src/class046/Code07_EvenCountsLongestSubarray.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_EvenCountsLongestSubarray {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_EvenCountsLongestSubarray() {}
  static int findTheLongestSubstring(String s) {
    int n = s.length();
    Array<int> map = make_array<int>(32);
    j::fill(map, (-2));
    (map[0] = (-1));
    int ans = 0;
    {
      int i = 0;
      int status = 0;
      int m = {};
      for (; (i < n); (i++)) {
        (m = Code07_EvenCountsLongestSubarray::move(s.charAt(i)));
        if ((m != (-1))) {
          (status ^= jshl(1, m));
        }
        if ((map[status] != (-2))) {
          (ans = jmax(ans, (i - map[status])));
        } else {
          (map[status] = i);
        }
      }
    }
    return ans;
  }
  static int move(jchar cha) {
    switch (cha) {
    case u'a':
      return 0;
    case u'e':
      return 1;
    case u'i':
      return 2;
    case u'o':
      return 3;
    case u'u':
      return 4;
    default:
      return (-1);
    }
  }
};

/* Original teaching comments:
// 每个元音包含偶数次的最长子字符串
// 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度
// 每个元音字母，即 'a'，'e'，'i'，'o'，'u'
// 在子字符串中都恰好出现了偶数次。
// 测试链接 :
https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
                // 只有5个元音字符，状态就5位
                // map[0...31] = -2
                // map[01100] = -2, 这个状态之前没出现过
                        // status : 0....i-1字符串上，aeiou的奇偶性
                        // s[i] = 当前字符
                        // 情况1 : 当前字符不是元音，status不变
                        // 情况2 : 当前字符是元音，a~u(0~4)，修改相应的状态
                        // status:  0....i字符串上，aeiou的奇偶性
                        // 同样的状态，之前最早出现在哪
*/
