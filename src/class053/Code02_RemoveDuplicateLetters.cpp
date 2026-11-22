// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/remove-duplicate-letters/

// Source: src/class053/Code02_RemoveDuplicateLetters.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_RemoveDuplicateLetters {
  inline static int MAXN = 26;
  inline static Array<int> cnts = make_array<int>(MAXN);
  inline static Array<bool> enter = make_array<bool>(MAXN);
  inline static Array<jchar> stack = make_array<jchar>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_RemoveDuplicateLetters() {}
  static String removeDuplicateLetters(String str) {
    (r = 0);
    j::fill(cnts, 0);
    j::fill(enter, false);
    Array<jchar> s = str.toCharArray();
    for (jchar cha : s) {
      (cnts[(cha - u'a')]++);
    }
    for (jchar cur : s) {
      if ((!enter[(cur - u'a')])) {
        while ((((r > 0) && (stack[(r - 1)] > cur)) &&
                (cnts[(stack[(r - 1)] - u'a')] > 0))) {
          (enter[(stack[(r - 1)] - u'a')] = false);
          (r--);
        }
        (stack[(r++)] = cur);
        (enter[(cur - u'a')] = true);
      }
      (cnts[(cur - u'a')]--);
    }
    return j::str(stack, 0, r);
  }
};

/* Original teaching comments:
// 去除重复字母保证剩余字符串的字典序最小
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/
        // 每种字符词频
        // 每种字符目前有没有进栈
        // 单调栈
                        // 从左往右依次遍历字符，a -> 0 b -> 1 ... z -> 25
                        // cur -> cur - 'a'
*/
