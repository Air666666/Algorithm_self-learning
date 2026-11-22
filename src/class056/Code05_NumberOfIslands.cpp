// Source: src/class056/Code05_NumberOfIslands.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_NumberOfIslands {
  inline static int MAXSIZE = 100001;
  inline static Array<int> father = make_array<int>(MAXSIZE);
  inline static int cols = {};
  inline static int sets = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_NumberOfIslands() {}
  static int numIslands(Array<Array<jchar>> board) {
    int n = board.length;
    int m = board[0].length;
    Code05_NumberOfIslands::build(n, m, board);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((board[i][j] == u'1')) {
          if (((j > 0) && (board[i][(j - 1)] == u'1'))) {
            Code05_NumberOfIslands::union_method(i, j, i, (j - 1));
          }
          if (((i > 0) && (board[(i - 1)][j] == u'1'))) {
            Code05_NumberOfIslands::union_method(i, j, (i - 1), j);
          }
        }
      }
    }
    return sets;
  }
  static void build(int n, int m, Array<Array<jchar>> board) {
    (cols = m);
    (sets = 0);
    for (int a = 0; (a < n); (a++)) {
      {
        int b = 0;
        int index = {};
        for (; (b < m); (b++)) {
          if ((board[a][b] == u'1')) {
            (index = Code05_NumberOfIslands::index(a, b));
            (father[index] = index);
            (sets++);
          }
        }
      }
    }
  }
  static int index(int a, int b) { return ((a * cols) + b); }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code05_NumberOfIslands::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int a, int b, int c, int d) {
    int fx = Code05_NumberOfIslands::find(Code05_NumberOfIslands::index(a, b));
    int fy = Code05_NumberOfIslands::find(Code05_NumberOfIslands::index(c, d));
    if ((fx != fy)) {
      (father[fx] = fy);
      (sets--);
    }
  }
};

/* Original teaching comments:
// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/
        // 并查集的做法
*/
