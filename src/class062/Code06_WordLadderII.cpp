// Source: src/class062/Code06_WordLadderII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_WordLadderII {
  inline static JHashSet<String> dict = {};
  inline static JHashSet<String> curLevel = JHashSet<String>();
  inline static JHashSet<String> nextLevel = JHashSet<String>();
  inline static JMap<String, JList<String>> graph =
      JMap<String, JList<String>>();
  inline static JDeque<String> path = JDeque<String>();
  inline static JList<JList<String>> ans = JList<JList<String>>();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_WordLadderII() {}
  static void build(JList<String> wordList) {
    (dict = JHashSet<String>(wordList));
    graph.clear();
    ans.clear();
    curLevel.clear();
    nextLevel.clear();
  }
  static JList<JList<String>> findLadders(String beginWord, String endWord,
                                          JList<String> wordList) {
    Code06_WordLadderII::build(wordList);
    if ((!dict.contains(endWord))) {
      return ans;
    }
    if (Code06_WordLadderII::bfs(beginWord, endWord)) {
      Code06_WordLadderII::dfs(endWord, beginWord);
    }
    return ans;
  }
  static bool bfs(String begin, String end) {
    bool find = false;
    curLevel.add(begin);
    while ((!curLevel.isEmpty())) {
      dict.removeAll(curLevel);
      for (String word : curLevel) {
        Array<jchar> w = word.toCharArray();
        for (int i = 0; (i < w.length); (i++)) {
          jchar old = w[i];
          for (jchar ch = u'a'; (ch <= u'z'); (ch++)) {
            (w[i] = ch);
            String str = j::str(w);
            if ((dict.contains(str) && (!str.equals(word)))) {
              if (str.equals(end)) {
                (find = true);
              }
              graph.putIfAbsent(str, JList<String>());
              graph.get(str).add(word);
              nextLevel.add(str);
            }
          }
          (w[i] = old);
        }
      }
      if (find) {
        return true;
      } else {
        JHashSet<String> tmp = curLevel;
        (curLevel = nextLevel);
        (nextLevel = tmp);
        nextLevel.clear();
      }
    }
    return false;
  }
  static void dfs(String word, String aim) {
    path.addFirst(word);
    if (word.equals(aim)) {
      ans.add(JList<String>(path));
    } else if (graph.containsKey(word)) {
      for (String next : graph.get(word)) {
        Code06_WordLadderII::dfs(next, aim);
      }
    }
    path.removeFirst();
  }
};

/* Original teaching comments:
// 单词接龙 II
// 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化
// 一个表示此过程的 转换序列 是形式上像
// beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
// 每对相邻的单词之间仅有单个字母不同
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词
// 注意，beginWord 不必是字典 wordList 中的单词
// sk == endWord
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList
// 请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列
// 如果不存在这样的转换序列，返回一个空列表
// 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回
// 测试链接 : https://leetcode.cn/problems/word-ladder-ii/
        // 单词表 ： list -> hashSet
        // 反向图
        // 记录路径，当生成一条有效路的时候，拷贝进ans！
        // begin -> end ，一层层bfs去，建图
        // 返回值：真的能找到end，返回true；false
                                // word : 去扩
                                //
每个位置，字符a~z，换一遍！检查在词表中是否存在
                                // 避免，加工出自己
*/
