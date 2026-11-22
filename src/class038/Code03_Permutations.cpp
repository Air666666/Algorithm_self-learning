// Source: src/class038/Code03_Permutations.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Permutations {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Permutations() {}
  static JList<JList<int>> permute(Array<int> nums) {
    JList<JList<int>> ans = JList<JList<int>>();
    Code03_Permutations::f(nums, 0, ans);
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
      for (int j = i; (j < nums.length); (j++)) {
        Code03_Permutations::swap(nums, i, j);
        Code03_Permutations::f(nums, (i + 1), ans);
        Code03_Permutations::swap(nums, i, j);
      }
    }
  }
  static void swap(Array<int> nums, int i, int j) {
    int tmp = nums[i];
    (nums[i] = nums[j]);
    (nums[j] = tmp);
  }
  static void java_main(Array<String> args) {
    Array<int> nums = Array<int>{1, 2, 3};
    JList<JList<int>> ans = Code03_Permutations::permute(nums);
    for (JList<int> list : ans) {
      for (int num : list) {
        jout.print((num + String(u" ")));
      }
      jout.println();
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Permutations::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 没有重复项数字的全排列
// 测试链接 : https://leetcode.cn/problems/permutations/
*/
