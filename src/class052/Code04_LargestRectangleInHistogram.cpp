// Source: src/class052/Code04_LargestRectangleInHistogram.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LargestRectangleInHistogram {
  inline static int MAXN = 100001;
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LargestRectangleInHistogram() {}
  static int largestRectangleArea(Array<int> height) {
    int n = height.length;
    (r = 0);
    int ans = 0;
    int cur = {};
    int left = {};
    for (int i = 0; (i < n); (i++)) {
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
      (ans = jmax(ans, (height[cur] * ((n - left) - 1))));
    }
    return ans;
  }
};

/* Original teaching comments:
// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
// 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
// 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram
                        // i -> arr[i]
*/
