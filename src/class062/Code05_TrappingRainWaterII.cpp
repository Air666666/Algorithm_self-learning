// Source: src/class062/Code05_TrappingRainWaterII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_TrappingRainWaterII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_TrappingRainWaterII() {}
  static int trapRainWater(Array<Array<int>> height) {
    Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
    int n = height.length;
    int m = height[0].length;
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    Array<Array<bool>> visited = make_array<bool>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if (((((i == 0) || (i == (n - 1))) || (j == 0)) || (j == (m - 1)))) {
          heap.add(Array<int>{i, j, height[i][j]});
          (visited[i][j] = true);
        } else {
          (visited[i][j] = false);
        }
      }
    }
    int ans = 0;
    while ((!heap.isEmpty())) {
      Array<int> record = heap.poll();
      int r = record[0];
      int c = record[1];
      int w = record[2];
      (ans += (w - height[r][c]));
      {
        int i = 0;
        int nr = {};
        int nc = {};
        for (; (i < 4); (i++)) {
          (nr = (r + move[i]));
          (nc = (c + move[(i + 1)]));
          if ((((((nr >= 0) && (nr < n)) && (nc >= 0)) && (nc < m)) &&
               (!visited[nr][nc]))) {
            heap.add(Array<int>{nr, nc, jmax(height[nr][nc], w)});
            (visited[nr][nc] = true);
          }
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 二维接雨水
// 给你一个 m * n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度
// 请计算图中形状最多能接多少体积的雨水。
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water-ii/
                // 0 : 行
                // 1 : 列
                // 2 : 水线
                                        // 边界
*/
