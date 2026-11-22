// Source: src/class070/Code06_MaximumSubmatrix.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_MaximumSubmatrix {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_MaximumSubmatrix() {}
  static Array<int> getMaxMatrix(Array<Array<int>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    int max = std::numeric_limits<int>::min();
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    Array<int> nums = make_array<int>(m);
    for (int up = 0; (up < n); (up++)) {
      j::fill(nums, 0);
      for (int down = up; (down < n); (down++)) {
        {
          int l = 0;
          int r = 0;
          int pre = std::numeric_limits<int>::min();
          for (; (r < m); (r++)) {
            (nums[r] += grid[down][r]);
            if ((pre >= 0)) {
              (pre += nums[r]);
            } else {
              (pre = nums[r]);
              (l = r);
            }
            if ((pre > max)) {
              (max = pre);
              (a = up);
              (b = l);
              (c = down);
              (d = r);
            }
          }
        }
      }
    }
    return Array<int>{a, b, c, d};
  }
};

/* Original teaching comments:
// 子矩阵最大累加和问题
// 给定一个二维数组grid，找到其中子矩阵的最大累加和
// 返回拥有最大累加和的子矩阵左上角和右下角坐标
// 如果有多个子矩阵都有最大累加和，返回哪一个都可以
// 测试链接 : https://leetcode.cn/problems/max-submatrix-lcci/
        // 如果行和列的规模都是n，时间复杂度O(n^3)，最优解了
                                // 如下代码就是题目1的附加问题 :
                                // 子数组中找到拥有最大累加和的子数组
*/
