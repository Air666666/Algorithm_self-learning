// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/surrounded-regions/

// Source: src/class058/Code02_SurroundedRegions.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SurroundedRegions {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SurroundedRegions() {}
  static void solve(Array<Array<jchar>> board) {
    int n = board.length;
    int m = board[0].length;
    for (int j = 0; (j < m); (j++)) {
      if ((board[0][j] == u'O')) {
        Code02_SurroundedRegions::dfs(board, n, m, 0, j);
      }
      if ((board[(n - 1)][j] == u'O')) {
        Code02_SurroundedRegions::dfs(board, n, m, (n - 1), j);
      }
    }
    for (int i = 1; (i < (n - 1)); (i++)) {
      if ((board[i][0] == u'O')) {
        Code02_SurroundedRegions::dfs(board, n, m, i, 0);
      }
      if ((board[i][(m - 1)] == u'O')) {
        Code02_SurroundedRegions::dfs(board, n, m, i, (m - 1));
      }
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((board[i][j] == u'O')) {
          (board[i][j] = u'X');
        }
        if ((board[i][j] == u'F')) {
          (board[i][j] = u'O');
        }
      }
    }
  }
  static void dfs(Array<Array<jchar>> board, int n, int m, int i, int j) {
    if ((((((i < 0) || (i == n)) || (j < 0)) || (j == m)) ||
         (board[i][j] != u'O'))) {
      return;
    }
    (board[i][j] = u'F');
    Code02_SurroundedRegions::dfs(board, n, m, (i + 1), j);
    Code02_SurroundedRegions::dfs(board, n, m, (i - 1), j);
    Code02_SurroundedRegions::dfs(board, n, m, i, (j + 1));
    Code02_SurroundedRegions::dfs(board, n, m, i, (j - 1));
  }
};

/* Original teaching comments:
// 被围绕的区域
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X'
围绕的区域
// 并将这些区域里所有的 'O' 用 'X' 填充。
// 测试链接 : https://leetcode.cn/problems/surrounded-regions/
*/
