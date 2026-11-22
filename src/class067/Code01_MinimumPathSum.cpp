// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-path-sum/

// Source: src/class067/Code01_MinimumPathSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumPathSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumPathSum() {}
  static int minPathSum1(Array<Array<int>> grid) {
    return Code01_MinimumPathSum::f1(grid, (grid.length - 1),
                                     (grid[0].length - 1));
  }
  static int f1(Array<Array<int>> grid, int i, int j) {
    if (((i == 0) && (j == 0))) {
      return grid[0][0];
    }
    int up = std::numeric_limits<int>::max();
    int left = std::numeric_limits<int>::max();
    if (((i - 1) >= 0)) {
      (up = Code01_MinimumPathSum::f1(grid, (i - 1), j));
    }
    if (((j - 1) >= 0)) {
      (left = Code01_MinimumPathSum::f1(grid, i, (j - 1)));
    }
    return (grid[i][j] + jmin(up, left));
  }
  static int minPathSum2(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> dp = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code01_MinimumPathSum::f2(grid, (grid.length - 1),
                                     (grid[0].length - 1), dp);
  }
  static int f2(Array<Array<int>> grid, int i, int j, Array<Array<int>> dp) {
    if ((dp[i][j] != (-1))) {
      return dp[i][j];
    }
    int ans = {};
    if (((i == 0) && (j == 0))) {
      (ans = grid[0][0]);
    } else {
      int up = std::numeric_limits<int>::max();
      int left = std::numeric_limits<int>::max();
      if (((i - 1) >= 0)) {
        (up = Code01_MinimumPathSum::f2(grid, (i - 1), j, dp));
      }
      if (((j - 1) >= 0)) {
        (left = Code01_MinimumPathSum::f2(grid, i, (j - 1), dp));
      }
      (ans = (grid[i][j] + jmin(up, left)));
    }
    (dp[i][j] = ans);
    return ans;
  }
  static int minPathSum3(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> dp = make_array<int>(n, m);
    (dp[0][0] = grid[0][0]);
    for (int i = 1; (i < n); (i++)) {
      (dp[i][0] = (dp[(i - 1)][0] + grid[i][0]));
    }
    for (int j = 1; (j < m); (j++)) {
      (dp[0][j] = (dp[0][(j - 1)] + grid[0][j]));
    }
    for (int i = 1; (i < n); (i++)) {
      for (int j = 1; (j < m); (j++)) {
        (dp[i][j] = (jmin(dp[(i - 1)][j], dp[i][(j - 1)]) + grid[i][j]));
      }
    }
    return dp[(n - 1)][(m - 1)];
  }
  static int minPathSum4(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    Array<int> dp = make_array<int>(m);
    (dp[0] = grid[0][0]);
    for (int j = 1; (j < m); (j++)) {
      (dp[j] = (dp[(j - 1)] + grid[0][j]));
    }
    for (int i = 1; (i < n); (i++)) {
      (dp[0] += grid[i][0]);
      for (int j = 1; (j < m); (j++)) {
        (dp[j] = (jmin(dp[(j - 1)], dp[j]) + grid[i][j]));
      }
    }
    return dp[(m - 1)];
  }
};

/* Original teaching comments:
// 最小路径和
// 给定一个包含非负整数的 m x n 网格 grid
// 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
// 测试链接 : https://leetcode.cn/problems/minimum-path-sum/
        // 暴力递归
        // 从(0,0)到(i,j)最小路径和
        // 一定每次只能向右或者向下
        // 记忆化搜索
        // 严格位置依赖的动态规划
        // 严格位置依赖的动态规划 + 空间压缩技巧
                // 先让dp表，变成想象中的表的第0行的数据
                        // i = 1，dp表变成想象中二维表的第1行的数据
                        // i = 2，dp表变成想象中二维表的第2行的数据
                        // i = 3，dp表变成想象中二维表的第3行的数据
                        // ...
                        // i = n-1，dp表变成想象中二维表的第n-1行的数据
*/
