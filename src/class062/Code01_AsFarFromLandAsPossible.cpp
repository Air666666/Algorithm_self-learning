// Source: src/class062/Code01_AsFarFromLandAsPossible.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_AsFarFromLandAsPossible {
  inline static int MAXN = 101;
  inline static int MAXM = 101;
  inline static Array<Array<int>> queue = make_array<int>((MAXN * MAXM), 2);
  inline static int l = {};
  inline static int r = {};
  inline static Array<Array<bool>> visited = make_array<bool>(MAXN, MAXM);
  inline static Array<int> move = Array<int>{(-1), 0, 1, 0, (-1)};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_AsFarFromLandAsPossible() {}
  static int maxDistance(Array<Array<int>> grid) {
    (l = (r = 0));
    int n = grid.length;
    int m = grid[0].length;
    int seas = 0;
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if ((grid[i][j] == 1)) {
          (visited[i][j] = true);
          (queue[r][0] = i);
          (queue[(r++)][1] = j);
        } else {
          (visited[i][j] = false);
          (seas++);
        }
      }
    }
    if (((seas == 0) || (seas == (n * m)))) {
      return (-1);
    }
    int level = 0;
    while ((l < r)) {
      (level++);
      int size = (r - l);
      {
        int k = 0;
        int x = {};
        int y = {};
        int nx = {};
        int ny = {};
        for (; (k < size); (k++)) {
          (x = queue[l][0]);
          (y = queue[(l++)][1]);
          for (int i = 0; (i < 4); (i++)) {
            (nx = (x + move[i]));
            (ny = (y + move[(i + 1)]));
            if ((((((nx >= 0) && (nx < n)) && (ny >= 0)) && (ny < m)) &&
                 (!visited[nx][ny]))) {
              (visited[nx][ny] = true);
              (queue[r][0] = nx);
              (queue[(r++)][1] = ny);
            }
          }
        }
      }
    }
    return (level - 1);
  }
};

/* Original teaching comments:
// 地图分析
// 你现在手里有一份大小为 n x n 的 网格 grid
// 上面的每个 单元格 都用 0 和 1 标记好了其中 0 代表海洋，1 代表陆地。
// 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的
// 并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
// (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
// 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/
        // 0:上，1:右，2:下，3:左
        //                                      0  1  2  3   4
        //                                               i
        // (x,y)  i来到0位置 : x + move[i], y + move[i+1] -> x - 1, y
        // (x,y)  i来到1位置 : x + move[i], y + move[i+1] -> x, y + 1
        // (x,y)  i来到2位置 : x + move[i], y + move[i+1] -> x + 1, y
        // (x,y)  i来到3位置 : x + move[i], y + move[i+1] -> x, y - 1
                                        // 上、右、下、左
*/
