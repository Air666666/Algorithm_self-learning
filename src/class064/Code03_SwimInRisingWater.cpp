// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/swim-in-rising-water/

// Source: src/class064/Code03_SwimInRisingWater.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SwimInRisingWater {
  inline static Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SwimInRisingWater() {}
  static int swimInWater(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> distance = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
      }
    }
    (distance[0][0] = grid[0][0]);
    Array<Array<bool>> visited = make_array<bool>(n, m);
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    heap.add(Array<int>{0, 0, grid[0][0]});
    while ((!heap.isEmpty())) {
      int x = heap.peek()[0];
      int y = heap.peek()[1];
      int c = heap.peek()[2];
      heap.poll();
      if (visited[x][y]) {
        continue;
      }
      (visited[x][y] = true);
      if (((x == (n - 1)) && (y == (m - 1)))) {
        return c;
      }
      {
        int i = 0;
        int nx = {};
        int ny = {};
        int nc = {};
        for (; (i < 4); (i++)) {
          (nx = (x + move[i]));
          (ny = (y + move[(i + 1)]));
          if ((((((nx >= 0) && (nx < n)) && (ny >= 0)) && (ny < m)) &&
               (!visited[nx][ny]))) {
            (nc = jmax(c, grid[nx][ny]));
            if ((nc < distance[nx][ny])) {
              (distance[nx][ny] = nc);
              heap.add(Array<int>{nx, ny, nc});
            }
          }
        }
      }
    }
    return (-1);
  }
};

/* Original teaching comments:
// 水位上升的泳池中游泳
// 在一个 n x n 的整数矩阵 grid 中
// 每一个方格的值 grid[i][j] 表示位置 (i, j) 的平台高度
// 当开始下雨时，在时间为 t 时，水池中的水位为 t
//
你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台
// 假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的
// 当然，在你游泳的时候你必须待在坐标方格里面。
// 你从坐标方格的左上平台 (0，0) 出发
// 返回 你到达坐标方格的右下平台 (n-1, n-1) 所需的最少时间
// 测试链接 : https://leetcode.cn/problems/swim-in-rising-water/
        // 0:上，1:右，2:下，3:左
                // 0 : 格子的行
                // 1 : 格子的列
                // 2 : 源点到当前格子的代价
                                // 常见剪枝
                                // 发现终点直接返回
                                // 不用等都结束
*/
