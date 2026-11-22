// Source: src/class067/Code02_WordSearch.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_WordSearch {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_WordSearch() {}
  static bool exist(Array<Array<jchar>> board, String word) {
    Array<jchar> w = word.toCharArray();
    for (int i = 0; (i < board.length); (i++)) {
      for (int j = 0; (j < board[0].length); (j++)) {
        if (Code02_WordSearch::f(board, i, j, w, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  static bool f(Array<Array<jchar>> b, int i, int j, Array<jchar> w, int k) {
    if ((k == w.length)) {
      return true;
    }
    if ((((((i < 0) || (i == b.length)) || (j < 0)) || (j == b[0].length)) ||
         (b[i][j] != w[k]))) {
      return false;
    }
    jchar tmp = b[i][j];
    (b[i][j] = 0);
    bool ans = (((Code02_WordSearch::f(b, (i - 1), j, w, (k + 1)) ||
                  Code02_WordSearch::f(b, (i + 1), j, w, (k + 1))) ||
                 Code02_WordSearch::f(b, i, (j - 1), w, (k + 1))) ||
                Code02_WordSearch::f(b, i, (j + 1), w, (k + 1)));
    (b[i][j] = tmp);
    return ans;
  }
};

/* Original teaching comments:
// 单词搜索（无法改成动态规划）
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word
// 如果 word 存在于网格中，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成
// 其中"相邻"单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母不允许被重复使用
// 测试链接 : https://leetcode.cn/problems/word-search/
        // 因为board会改其中的字符
        // 用来标记哪些字符无法再用
        // 带路径的递归无法改成动态规划或者说没必要
        // 从(i,j)出发，来到w[k]，请问后续能不能把word走出来w[k...]
                // 不越界，b[i][j] == w[k]
*/
