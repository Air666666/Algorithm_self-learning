// Source: src/class059/Code04_AlienDictionary.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_AlienDictionary {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_AlienDictionary() {}
  static String alienOrder(Array<String> words) {
    Array<int> indegree = make_array<int>(26);
    j::fill(indegree, (-1));
    for (String w : words) {
      for (int i = 0; (i < w.length()); (i++)) {
        (indegree[(w.charAt(i) - u'a')] = 0);
      }
    }
    JList<JList<int>> graph = JList<JList<int>>();
    for (int i = 0; (i < 26); (i++)) {
      graph.add(JList<int>());
    }
    {
      int i = 0;
      int j = {};
      int len = {};
      for (; (i < (words.length - 1)); (i++)) {
        String cur = words[i];
        String next = words[(i + 1)];
        (j = 0);
        (len = [&]() {
          auto jargument_0 = cur.length();
          auto jargument_1 = next.length();
          return jmin(jargument_0, jargument_1);
        }());
        for (; (j < len); (j++)) {
          if ([&]() {
                auto jleft = cur.charAt(j);
                auto jright = next.charAt(j);
                return (jleft != jright);
              }()) {
            graph.get((cur.charAt(j) - u'a')).add((next.charAt(j) - u'a'));
            (indegree[(next.charAt(j) - u'a')]++);
            break;
          }
        }
        if (((j < cur.length()) && (j == next.length()))) {
          return String(u"");
        }
      }
    }
    Array<int> queue = make_array<int>(26);
    int l = 0;
    int r = 0;
    int kinds = 0;
    for (int i = 0; (i < 26); (i++)) {
      if ((indegree[i] != (-1))) {
        (kinds++);
      }
      if ((indegree[i] == 0)) {
        (queue[(r++)] = i);
      }
    }
    StringBuilder ans = StringBuilder();
    while ((l < r)) {
      int cur = queue[(l++)];
      ans.append(static_cast<jchar>((cur + u'a')));
      for (int next : graph.get(cur)) {
        if (((--indegree[next]) == 0)) {
          (queue[(r++)] = next);
        }
      }
    }
    return ((ans.length() == kinds) ? ans.toString() : String(u""));
  }
};

/* Original teaching comments:
// 火星词典
// 现有一种使用英语字母的火星语言
// 这门语言的字母顺序对你来说是未知的。
// 给你一个来自这种外星语言字典的字符串列表 words
// words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
// 如果这种说法是错误的，并且给出的 words 不能对应任何字母的顺序，则返回 ""
// 否则，返回一个按新语言规则的 字典递增顺序 排序的独特字符串
// 如果有多个解决方案，则返回其中任意一个
// words中的单词一定都是小写英文字母组成的
// 测试链接 : https://leetcode.cn/problems/alien-dictionary/
// 测试链接(不需要会员) : https://leetcode.cn/problems/Jf1JuT/
                // 入度表，26种字符
                // 'a' -> 0
                // 'b' -> 1
                // 'z' -> 25
                // x -> x - 'a'
*/
