// Source: src/class062/Code03_MinimumObstacleRemovalToReachCorner.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumObstacleRemovalToReachCorner {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumObstacleRemovalToReachCorner() {}
  static int minimumObstacles(Array<Array<int>> grid) {
    Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
    int m = grid.length;
    int n = grid[0].length;
    Array<Array<int>> distance = make_array<int>(m, n);
    for (int i = 0; (i < m); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        (distance[i][j] = std::numeric_limits<int>::max());
      }
    }
    JDeque<Array<int>> deque = JDeque<Array<int>>();
    deque.addFirst(Array<int>{0, 0});
    (distance[0][0] = 0);
    while ((!deque.isEmpty())) {
      Array<int> record = deque.pollFirst();
      int x = record[0];
      int y = record[1];
      if (((x == (m - 1)) && (y == (n - 1)))) {
        return distance[x][y];
      }
      for (int i = 0; (i < 4); (i++)) {
        int nx = (x + move[i]);
        int ny = (y + move[(i + 1)]);
        if ((((((nx >= 0) && (nx < m)) && (ny >= 0)) && (ny < n)) &&
             ((distance[x][y] + grid[nx][ny]) < distance[nx][ny]))) {
          (distance[nx][ny] = (distance[x][y] + grid[nx][ny]));
          if ((grid[nx][ny] == 0)) {
            deque.addFirst(Array<int>{nx, ny});
          } else {
            deque.addLast(Array<int>{nx, ny});
          }
        }
      }
    }
    return (-1);
  }
};

/* Original teaching comments:
// 到达角落需要移除障碍物的最小数目
// 给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n
// 每个单元格都是两个值之一：
// 0 表示一个 空 单元格，
// 1 表示一个可以移除的 障碍物
// 你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
// 现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1)
// 返回需要移除的障碍物的最小数目
// 测试链接 :
https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/
*/
