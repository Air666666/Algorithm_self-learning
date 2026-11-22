// Source: src/class052/Code05_MaximalRectangle.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximalRectangle {
  inline static int MAXN = 201;
  inline static Array<int> height = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximalRectangle() {}
  static int maximalRectangle(Array<Array<jchar>> grid) {
    int n = grid.length;
    int m = grid[0].length;
    j::fill(height, 0, m, 0);
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (height[j] = ((grid[i][j] == u'0') ? 0 : (height[j] + 1)));
      }
      (ans = jmax(Code05_MaximalRectangle::largestRectangleArea(m), ans));
    }
    return ans;
  }
  static int largestRectangleArea(int m) {
    (r = 0);
    int ans = 0;
    int cur = {};
    int left = {};
    for (int i = 0; (i < m); (i++)) {
      while (((r > 0) && (height[stack[(r - 1)]] >= height[i]))) {
        (cur = stack[(--r)]);
        (left = ((r == 0) ? (-1) : stack[(r - 1)]));
        (ans = jmax(ans, (height[cur] * ((i - left) - 1))));
      }
      (stack[(r++)] = i);
    }
    while ((r > 0)) {
      (cur = stack[(--r)]);
      (left = ((r == 0) ? (-1) : stack[(r - 1)]));
      (ans = jmax(ans, (height[cur] * ((m - left) - 1))));
    }
    return ans;
  }
};

/* Original teaching comments:
// 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
// 找出只包含 1 的最大矩形，并返回其面积
// 测试链接：https://leetcode.cn/problems/maximal-rectangle/
                        // 来到i行，长方形一定要以i行做底！
                        // 加工高度数组(压缩数组)
                        // i -> arr[i]
*/
