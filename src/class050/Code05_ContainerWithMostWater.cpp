// Source: src/class050/Code05_ContainerWithMostWater.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ContainerWithMostWater {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ContainerWithMostWater() {}
  static int maxArea(Array<int> height) {
    int ans = 0;
    {
      int l = 0;
      int r = (height.length - 1);
      for (; (l < r);) {
        (ans = jmax(ans, (jmin(height[l], height[r]) * (r - l))));
        if ((height[l] <= height[r])) {
          (l++);
        } else {
          (r--);
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 盛最多水的容器
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i,
0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
// 返回容器可以储存的最大水量
// 说明：你不能倾斜容器
// 测试链接 : https://leetcode.cn/problems/container-with-most-water/
        // 时间复杂度O(n)，额外空间复杂度O(1)
*/
