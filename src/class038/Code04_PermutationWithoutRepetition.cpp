// Source: src/class038/Code04_PermutationWithoutRepetition.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PermutationWithoutRepetition {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PermutationWithoutRepetition() {}
  static JList<JList<int>> permuteUnique(Array<int> nums) {
    JList<JList<int>> ans = JList<JList<int>>();
    Code04_PermutationWithoutRepetition::f(nums, 0, ans);
    return ans;
  }
  static void f(Array<int> nums, int i, JList<JList<int>> ans) {
    if ((i == nums.length)) {
      JList<int> cur = JList<int>();
      for (int num : nums) {
        cur.add(num);
      }
      ans.add(cur);
    } else {
      JHashSet<int> set = JHashSet<int>();
      for (int j = i; (j < nums.length); (j++)) {
        if ((!set.contains(nums[j]))) {
          set.add(nums[j]);
          Code04_PermutationWithoutRepetition::swap(nums, i, j);
          Code04_PermutationWithoutRepetition::f(nums, (i + 1), ans);
          Code04_PermutationWithoutRepetition::swap(nums, i, j);
        }
      }
    }
  }
  static void swap(Array<int> nums, int i, int j) {
    int tmp = nums[i];
    (nums[i] = nums[j]);
    (nums[j] = tmp);
  }
};

/* Original teaching comments:
// 有重复项数组的去重全排列
// 测试链接 : https://leetcode.cn/problems/permutations-ii/
                                // nums[j]没有来到过i位置，才会去尝试
*/
