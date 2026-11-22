// Source: src/class063/Code01_WordLadder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_WordLadder {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_WordLadder() {}
  static int ladderLength(String begin, String end, JList<String> wordList) {
    JHashSet<String> dict = JHashSet<String>(wordList);
    if ((!dict.contains(end))) {
      return 0;
    }
    JHashSet<String> smallLevel = JHashSet<String>();
    JHashSet<String> bigLevel = JHashSet<String>();
    JHashSet<String> nextLevel = JHashSet<String>();
    smallLevel.add(begin);
    bigLevel.add(end);
    for (int len = 2; (!smallLevel.isEmpty()); (len++)) {
      for (String w : smallLevel) {
        Array<jchar> word = w.toCharArray();
        for (int j = 0; (j < word.length); (j++)) {
          jchar old = word[j];
          for (jchar change = u'a'; (change <= u'z'); (change++)) {
            if ((change != old)) {
              (word[j] = change);
              String next = j::str(word);
              if (bigLevel.contains(next)) {
                return len;
              }
              if (dict.contains(next)) {
                dict.remove(next);
                nextLevel.add(next);
              }
            }
          }
          (word[j] = old);
        }
      }
      if ([&]() {
            auto jleft = nextLevel.size();
            auto jright = bigLevel.size();
            return (jleft <= jright);
          }()) {
        JHashSet<String> tmp = smallLevel;
        (smallLevel = nextLevel);
        (nextLevel = tmp);
      } else {
        JHashSet<String> tmp = smallLevel;
        (smallLevel = bigLevel);
        (bigLevel = nextLevel);
        (nextLevel = tmp);
      }
      nextLevel.clear();
    }
    return 0;
  }
};

/* Original teaching comments:
// 单词接龙
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
// 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk ：
// 每一对相邻的单词只差一个字母。
// 对于 1 <= i <= k 时，每个 si 都在 wordList 中
// 注意， beginWord 不需要在 wordList 中。sk == endWord
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList
// 返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目
// 如果不存在这样的转换序列，返回 0 。
// 测试链接 : https://leetcode.cn/problems/word-ladder/
                // 总词表
                // 数量小的一侧
                // 数量大的一侧
                // 由数量小的一侧，所扩展出的下一层列表
                                // 从小侧扩展
                                        // 每一位字符都试
                                                // 每一位字符都从a到z换一遍
*/
