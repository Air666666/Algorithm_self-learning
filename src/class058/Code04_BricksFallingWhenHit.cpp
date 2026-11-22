// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/bricks-falling-when-hit/

// Source: src/class058/Code04_BricksFallingWhenHit.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_BricksFallingWhenHit {
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> grid = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_BricksFallingWhenHit() {}
  static Array<int> hitBricks(Array<Array<int>> g, Array<Array<int>> h) {
    (grid = g);
    (n = g.length);
    (m = g[0].length);
    Array<int> ans = make_array<int>(h.length);
    if ((n == 1)) {
      return ans;
    }
    for (Array<int> hit : h) {
      (grid[hit[0]][hit[1]]--);
    }
    for (int i = 0; (i < m); (i++)) {
      Code04_BricksFallingWhenHit::dfs(0, i);
    }
    {
      int i = (h.length - 1);
      int row = {};
      int col = {};
      for (; (i >= 0); (i--)) {
        (row = h[i][0]);
        (col = h[i][1]);
        (grid[row][col]++);
        if (Code04_BricksFallingWhenHit::worth(row, col)) {
          (ans[i] = (Code04_BricksFallingWhenHit::dfs(row, col) - 1));
        }
      }
    }
    return ans;
  }
  static int dfs(int i, int j) {
    if ((((((i < 0) || (i == n)) || (j < 0)) || (j == m)) ||
         (grid[i][j] != 1))) {
      return 0;
    }
    (grid[i][j] = 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = [&]() {
          auto jleft = (1 + Code04_BricksFallingWhenHit::dfs((i + 1), j));
          auto jright = Code04_BricksFallingWhenHit::dfs(i, (j + 1));
          return (jleft + jright);
        }();
        auto jright = Code04_BricksFallingWhenHit::dfs((i - 1), j);
        return (jleft + jright);
      }();
      auto jright = Code04_BricksFallingWhenHit::dfs(i, (j - 1));
      return (jleft + jright);
    }();
  }
  static bool worth(int i, int j) {
    return ((grid[i][j] == 1) &&
            (((((i == 0) || ((i > 0) && (grid[(i - 1)][j] == 2))) ||
               ((i < (n - 1)) && (grid[(i + 1)][j] == 2))) ||
              ((j > 0) && (grid[i][(j - 1)] == 2))) ||
             ((j < (m - 1)) && (grid[i][(j + 1)] == 2))));
  }
};

/* Original teaching comments:
// 打砖块
// 有一个 m * n 的二元网格 grid ，其中 1 表示砖块，0 表示空白
// 砖块 稳定（不会掉落）的前提是：
// 一块砖直接连接到网格的顶部，或者
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
// 给你一个数组 hits ，这是需要依次消除砖块的位置
// 每当消除 hits[i] = (rowi, coli)
位置上的砖块时，对应位置的砖块（若存在）会消失
// 然后其他的砖块可能因为这一消除操作而 掉落
// 一旦砖块掉落，它会 立即 从网格 grid 中消失（即，它不会落在其他稳定的砖块上）
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
// 测试链接 : https://leetcode.cn/problems/bricks-falling-when-hit/
        // 从(i,j)格子出发，遇到1就感染成2
        // 统计新增了几个2！
*/
