// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/subsets-ii/

// Source: src/class038/Code02_Combinations.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Combinations {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Combinations() {}
  static JList<JList<int>> subsetsWithDup(Array<int> nums) {
    JList<JList<int>> ans = JList<JList<int>>();
    j::sort(nums);
    Code02_Combinations::f(nums, 0, make_array<int>(nums.length), 0, ans);
    return ans;
  }
  static void f(Array<int> nums, int i, Array<int> path, int size,
                JList<JList<int>> ans) {
    if ((i == nums.length)) {
      JList<int> cur = JList<int>();
      for (int j = 0; (j < size); (j++)) {
        cur.add(path[j]);
      }
      ans.add(cur);
    } else {
      int j = (i + 1);
      while (((j < nums.length) && (nums[i] == nums[j]))) {
        (j++);
      }
      Code02_Combinations::f(nums, j, path, size, ans);
      for (; (i < j); (i++)) {
        (path[(size++)] = nums[i]);
        Code02_Combinations::f(nums, j, path, size, ans);
      }
    }
  }
};

/* Original teaching comments:
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
//
注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 测试链接 : https://leetcode.cn/problems/subsets-ii/
                        // 下一组的第一个数的位置
                        // 当前数x，要0个
                        // 当前数x，要1个、要2个、要3个...都尝试
*/
