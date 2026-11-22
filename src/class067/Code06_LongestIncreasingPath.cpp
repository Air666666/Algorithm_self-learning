// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

// Source: src/class067/Code06_LongestIncreasingPath.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_LongestIncreasingPath {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_LongestIncreasingPath() {}
  static int longestIncreasingPath1(Array<Array<int>> grid) {
    int ans = 0;
    for (int i = 0; (i < grid.length); (i++)) {
      for (int j = 0; (j < grid[0].length); (j++)) {
        (ans = jmax(ans, Code06_LongestIncreasingPath::f1(grid, i, j)));
      }
    }
    return ans;
  }
  static int f1(Array<Array<int>> grid, int i, int j) {
    int next = 0;
    if (((i > 0) && (grid[i][j] < grid[(i - 1)][j]))) {
      (next = jmax(next, Code06_LongestIncreasingPath::f1(grid, (i - 1), j)));
    }
    if ((((i + 1) < grid.length) && (grid[i][j] < grid[(i + 1)][j]))) {
      (next = jmax(next, Code06_LongestIncreasingPath::f1(grid, (i + 1), j)));
    }
    if (((j > 0) && (grid[i][j] < grid[i][(j - 1)]))) {
      (next = jmax(next, Code06_LongestIncreasingPath::f1(grid, i, (j - 1))));
    }
    if ((((j + 1) < grid[0].length) && (grid[i][j] < grid[i][(j + 1)]))) {
      (next = jmax(next, Code06_LongestIncreasingPath::f1(grid, i, (j + 1))));
    }
    return (next + 1);
  }
  static int longestIncreasingPath2(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> dp = make_array<int>(n, m);
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (ans = jmax(ans, Code06_LongestIncreasingPath::f2(grid, i, j, dp)));
      }
    }
    return ans;
  }
  static int f2(Array<Array<int>> grid, int i, int j, Array<Array<int>> dp) {
    if ((dp[i][j] != 0)) {
      return dp[i][j];
    }
    int next = 0;
    if (((i > 0) && (grid[i][j] < grid[(i - 1)][j]))) {
      (next =
           jmax(next, Code06_LongestIncreasingPath::f2(grid, (i - 1), j, dp)));
    }
    if ((((i + 1) < grid.length) && (grid[i][j] < grid[(i + 1)][j]))) {
      (next =
           jmax(next, Code06_LongestIncreasingPath::f2(grid, (i + 1), j, dp)));
    }
    if (((j > 0) && (grid[i][j] < grid[i][(j - 1)]))) {
      (next =
           jmax(next, Code06_LongestIncreasingPath::f2(grid, i, (j - 1), dp)));
    }
    if ((((j + 1) < grid[0].length) && (grid[i][j] < grid[i][(j + 1)]))) {
      (next =
           jmax(next, Code06_LongestIncreasingPath::f2(grid, i, (j + 1), dp)));
    }
    (dp[i][j] = (next + 1));
    return (next + 1);
  }
};

/* Original teaching comments:
// 矩阵中的最长递增路径
// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度
// 对于每个单元格，你可以往上，下，左，右四个方向移动
// 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）
// 测试链接 : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
        // 从(i,j)出发，能走出来多长的递增路径，返回最长长度
*/
