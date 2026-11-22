// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/making-a-large-island/

// Source: src/class058/Code03_MakingLargeIsland.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MakingLargeIsland {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MakingLargeIsland() {}
  static int largestIsland(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    int id = 2;
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((grid[i][j] == 1)) {
          Code03_MakingLargeIsland::dfs(grid, n, m, i, j, (id++));
        }
      }
    }
    Array<int> sizes = make_array<int>(id);
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((grid[i][j] > 1)) {
          (ans = jmax(ans, (++sizes[grid[i][j]])));
        }
      }
    }
    Array<bool> visited = make_array<bool>(id);
    int up = {};
    int down = {};
    int left = {};
    int right = {};
    int merge = {};
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((grid[i][j] == 0)) {
          (up = ((i > 0) ? grid[(i - 1)][j] : 0));
          (down = (((i + 1) < n) ? grid[(i + 1)][j] : 0));
          (left = ((j > 0) ? grid[i][(j - 1)] : 0));
          (right = (((j + 1) < m) ? grid[i][(j + 1)] : 0));
          (visited[up] = true);
          (merge = (1 + sizes[up]));
          if ((!visited[down])) {
            (merge += sizes[down]);
            (visited[down] = true);
          }
          if ((!visited[left])) {
            (merge += sizes[left]);
            (visited[left] = true);
          }
          if ((!visited[right])) {
            (merge += sizes[right]);
            (visited[right] = true);
          }
          (ans = jmax(ans, merge));
          (visited[up] = false);
          (visited[down] = false);
          (visited[left] = false);
          (visited[right] = false);
        }
      }
    }
    return ans;
  }
  static void dfs(Array<Array<int>> grid, int n, int m, int i, int j, int id) {
    if ((((((i < 0) || (i == n)) || (j < 0)) || (j == m)) ||
         (grid[i][j] != 1))) {
      return;
    }
    (grid[i][j] = id);
    Code03_MakingLargeIsland::dfs(grid, n, m, (i - 1), j, id);
    Code03_MakingLargeIsland::dfs(grid, n, m, (i + 1), j, id);
    Code03_MakingLargeIsland::dfs(grid, n, m, i, (j - 1), id);
    Code03_MakingLargeIsland::dfs(grid, n, m, i, (j + 1), id);
  }
};

/* Original teaching comments:
// 最大人工岛
// 给你一个大小为 n * n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
// 返回执行此操作后，grid 中最大的岛屿面积是多少？
// 岛屿 由一组上、下、左、右四个方向相连的 1 形成
// 测试链接 : https://leetcode.cn/problems/making-a-large-island/
                // 讨论所有的0，变成1，能带来的最大岛的大小
                //  grid[i][j] == 1
*/
