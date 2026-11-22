// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-window-substring/

// Source: src/class049/Code03_MinimumWindowSubstring.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumWindowSubstring {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumWindowSubstring() {}
  static String minWindow(String str, String tar) {
    Array<jchar> s = str.toCharArray();
    Array<jchar> t = tar.toCharArray();
    Array<int> cnts = make_array<int>(256);
    for (jchar cha : t) {
      (cnts[cha]--);
    }
    int len = std::numeric_limits<int>::max();
    int start = 0;
    int debt = t.length;
    {
      int l = 0;
      int r = 0;
      for (; (r < s.length); (r++)) {
        if (((cnts[s[r]]++) < 0)) {
          (debt--);
        }
        if ((debt == 0)) {
          while ((cnts[s[l]] > 0)) {
            (cnts[s[(l++)]]--);
          }
          if ((((r - l) + 1) < len)) {
            (len = ((r - l) + 1));
            (start = l);
          }
        }
      }
    }
    return ((len == std::numeric_limits<int>::max())
                ? String(u"")
                : str.substring(start, (start + len)));
  }
};

/* Original teaching comments:
// 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 测试链接 : https://leetcode.cn/problems/minimum-window-substring/
                // 每种字符的欠债情况
                // cnts[i] = 负数，代表字符i有负债
                // cnts[i] = 正数，代表字符i有盈余
                // 最小覆盖子串的长度
                // 从哪个位置开头，发现的最小覆盖子串
                // 总债务
                        // 窗口右边界向右，给出字符
                                // 窗口左边界向右，拿回字符
                                // 以r位置结尾的达标窗口，更新答案
*/
