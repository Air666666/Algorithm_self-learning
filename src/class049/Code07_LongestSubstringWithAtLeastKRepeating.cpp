// Source: src/class049/Code07_LongestSubstringWithAtLeastKRepeating.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_LongestSubstringWithAtLeastKRepeating {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_LongestSubstringWithAtLeastKRepeating() {}
  static int longestSubstring(String str, int k) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<int> cnts = make_array<int>(256);
    int ans = 0;
    for (int require = 1; (require <= 26); (require++)) {
      j::fill(cnts, 0);
      {
        int l = 0;
        int r = 0;
        int collect = 0;
        int satisfy = 0;
        for (; (r < n); (r++)) {
          (cnts[s[r]]++);
          if ((cnts[s[r]] == 1)) {
            (collect++);
          }
          if ((cnts[s[r]] == k)) {
            (satisfy++);
          }
          while ((collect > require)) {
            if ((cnts[s[l]] == 1)) {
              (collect--);
            }
            if ((cnts[s[l]] == k)) {
              (satisfy--);
            }
            (cnts[s[(l++)]]--);
          }
          if ((satisfy == require)) {
            (ans = jmax(ans, ((r - l) + 1)));
          }
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 至少有K个重复字符的最长子串
// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串
// 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度
// 如果不存在这样的子字符串，则返回 0。
// 测试链接 :
https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
                //
每次要求子串必须含有require种字符，每种字符都必须>=k次，这样的最长子串是多长
                        // collect : 窗口中一共收集到的种类数
                        // satisfy : 窗口中达标的种类数(次数>=k)
                                // l....r 种类超了！
                                // l位置的字符，窗口中吐出来！
                                // l.....r :
子串以r位置的字符结尾，且种类数不超的，最大长度！
*/
