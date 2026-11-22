// Source: src/class062/Code02_StickersToSpellWord.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_StickersToSpellWord {
  inline static int MAXN = 401;
  inline static Array<String> queue = make_array<String>(MAXN);
  inline static int l = {};
  inline static int r = {};
  inline static JList<JList<String>> graph = JList<JList<String>>();
  inline static JHashSet<String> visited = JHashSet<String>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_StickersToSpellWord() {}
  static int minStickers(Array<String> stickers, String target) {
    for (int i = 0; (i < 26); (i++)) {
      graph.get(i).clear();
    }
    visited.clear();
    for (String str : stickers) {
      (str = Code02_StickersToSpellWord::sort(str));
      for (int i = 0; (i < str.length()); (i++)) {
        if (((i == 0) || [&]() {
              auto jleft = str.charAt(i);
              auto jright = str.charAt((i - 1));
              return (jleft != jright);
            }())) {
          graph.get((str.charAt(i) - u'a')).add(str);
        }
      }
    }
    (target = Code02_StickersToSpellWord::sort(target));
    visited.add(target);
    (l = (r = 0));
    (queue[(r++)] = target);
    int level = 1;
    while ((l < r)) {
      int size = (r - l);
      for (int i = 0; (i < size); (i++)) {
        String cur = queue[(l++)];
        for (String s : graph.get((cur.charAt(0) - u'a'))) {
          String next = Code02_StickersToSpellWord::next(cur, s);
          if (next.equals(String(u""))) {
            return level;
          } else if ((!visited.contains(next))) {
            visited.add(next);
            (queue[(r++)] = next);
          }
        }
      }
      (level++);
    }
    return (-1);
  }
  static String sort(String str) {
    Array<jchar> s = str.toCharArray();
    j::sort(s);
    return j::str(s);
  }
  static String next(String t, String s) {
    StringBuilder builder = StringBuilder();
    {
      int i = 0;
      int j = 0;
      for (; (i < t.length());) {
        if ((j == s.length())) {
          builder.append(t.charAt((i++)));
        } else {
          if ([&]() {
                auto jleft = t.charAt(i);
                auto jright = s.charAt(j);
                return (jleft < jright);
              }()) {
            builder.append(t.charAt((i++)));
          } else if ([&]() {
                       auto jleft = t.charAt(i);
                       auto jright = s.charAt(j);
                       return (jleft > jright);
                     }()) {
            (j++);
          } else {
            (i++);
            (j++);
          }
        }
      }
    }
    return builder.toString();
  }
};

/* Original teaching comments:
// 贴纸拼词
// 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
// 您想要拼写出给定的字符串 target
，方法是从收集的贴纸中切割单个字母并重新排列它们
// 如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
// 返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1
// 注意：在所有的测试用例中，所有的单词都是从 1000
个最常见的美国英语单词中随机选择的
// 并且 target 被选择为两个随机单词的连接。
// 测试链接 : https://leetcode.cn/problems/stickers-to-spell-word/
        // 下标0 -> a
        // 下标1 -> b
        // 下标2 -> c
        // ...
        // 下标25 -> z
        // 宽度优先遍历的解法
        // 也可以使用动态规划
        // 后续课程会有动态规划专题讲解
                // 使用队列的形式是整层弹出
*/
