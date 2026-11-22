// Source: src/class070/Code04_HouseRobberII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_HouseRobberII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_HouseRobberII() {}
  static int rob(Array<int> nums) {
    int n = nums.length;
    if ((n == 1)) {
      return nums[0];
    }
    return [&]() {
      auto jargument_0 = Code04_HouseRobberII::best(nums, 1, (n - 1));
      auto jargument_1 =
          (nums[0] + Code04_HouseRobberII::best(nums, 2, (n - 2)));
      return jmax(jargument_0, jargument_1);
    }();
  }
  static int best(Array<int> nums, int l, int r) {
    if ((l > r)) {
      return 0;
    }
    if ((l == r)) {
      return nums[l];
    }
    if (((l + 1) == r)) {
      return jmax(nums[l], nums[r]);
    }
    int prepre = nums[l];
    int pre = jmax(nums[l], nums[(l + 1)]);
    {
      int i = (l + 2);
      int cur = {};
      for (; (i <= r); (i++)) {
        (cur = jmax(pre, (nums[i] + jmax(0, prepre))));
        (prepre = pre);
        (pre = cur);
      }
    }
    return pre;
  }
};

/* Original teaching comments:
// 环形数组中不能选相邻元素的最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 可以随意选择数字，但是不能选择相邻的数字
// 返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber-ii/
        // nums[l....r]范围上，没有环形的概念
        // 返回 : 可以随意选择数字，但不能选择相邻数字的情况下，最大累加和
*/
