// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/stamping-the-grid/

// Source: src/class048/Code04_StampingTheGrid.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_StampingTheGrid {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_StampingTheGrid() {}
  static bool possibleToStamp(Array<Array<int>> grid, int h, int w) {
    int n = grid.length;
    int m = grid[0].length;
    Array<Array<int>> sum = make_array<int>((n + 1), (m + 1));
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (sum[(i + 1)][(j + 1)] = grid[i][j]);
      }
    }
    Code04_StampingTheGrid::build(sum);
    Array<Array<int>> diff = make_array<int>((n + 2), (m + 2));
    {
      int a = 1;
      int c = ((a + h) - 1);
      for (; (c <= n); (a++), (c++)) {
        {
          int b = 1;
          int d = ((b + w) - 1);
          for (; (d <= m); (b++), (d++)) {
            if ((Code04_StampingTheGrid::sumRegion(sum, a, b, c, d) == 0)) {
              Code04_StampingTheGrid::add(diff, a, b, c, d);
            }
          }
        }
      }
    }
    Code04_StampingTheGrid::build(diff);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        if (((grid[i][j] == 0) && (diff[(i + 1)][(j + 1)] == 0))) {
          return false;
        }
      }
    }
    return true;
  }
  static void build(Array<Array<int>> m) {
    for (int i = 1; (i < m.length); (i++)) {
      for (int j = 1; (j < m[0].length); (j++)) {
        (m[i][j] += ((m[(i - 1)][j] + m[i][(j - 1)]) - m[(i - 1)][(j - 1)]));
      }
    }
  }
  static int sumRegion(Array<Array<int>> sum, int a, int b, int c, int d) {
    return (((sum[c][d] - sum[c][(b - 1)]) - sum[(a - 1)][d]) +
            sum[(a - 1)][(b - 1)]);
  }
  static void add(Array<Array<int>> diff, int a, int b, int c, int d) {
    (diff[a][b] += 1);
    (diff[(c + 1)][(d + 1)] += 1);
    (diff[(c + 1)][b] -= 1);
    (diff[a][(d + 1)] -= 1);
  }
};

/* Original teaching comments:
// 用邮票贴满网格图
// 给你一个 m * n 的二进制矩阵 grid
// 每个格子要么为 0 （空）要么为 1 （被占据）
// 给你邮票的尺寸为 stampHeight * stampWidth
// 我们想将邮票贴进二进制矩阵中，且满足以下 限制 和 要求 ：
// 覆盖所有空格子，不覆盖任何被占据的格子
// 可以放入任意数目的邮票，邮票可以相互有重叠部分
// 邮票不允许旋转，邮票必须完全在矩阵内
// 如果在满足上述要求的前提下，可以放入邮票，请返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/stamping-the-grid/
        // 时间复杂度O(n*m)，额外空间复杂度O(n*m)
                // sum是前缀和数组
                // 查询原始矩阵中的某个范围的累加和很快速
                // 差分矩阵
                // 当贴邮票的时候，不再原始矩阵里贴，在差分矩阵里贴
                // 原始矩阵就用来判断能不能贴邮票，不进行修改
                // 每贴一张邮票都在差分矩阵里修改
                                // 原始矩阵中 (a,b)左上角点
                                // 根据邮票规格，h、w，算出右下角点(c,d)
                                // 这个区域彻底都是0，那么:
                                // sumRegion(sum, a, b, c, d) == 0
                                // 那么此时这个区域可以贴邮票
                // 检查所有的格子！
                                // 原始矩阵里：grid[i][j] == 0，说明是个洞
                                // 差分矩阵里：diff[i + 1][j + 1] ==
0，说明洞上并没有邮票
                                // 此时返回false
*/
