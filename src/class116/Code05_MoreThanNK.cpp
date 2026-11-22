// Source: src/class116/Code05_MoreThanNK.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MoreThanNK {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MoreThanNK() {}
  static JList<int> majorityElement(Array<int> nums) {
    return Code05_MoreThanNK::majority(nums, 3);
  }
  static JList<int> majority(Array<int> nums, int k) {
    Array<Array<int>> cands = make_array<int>((--k), 2);
    for (int num : nums) {
      Code05_MoreThanNK::update(cands, k, num);
    }
    JList<int> ans = JList<int>();
    Code05_MoreThanNK::collect(cands, k, nums, nums.length, ans);
    return ans;
  }
  static void update(Array<Array<int>> cands, int k, int num) {
    for (int i = 0; (i < k); (i++)) {
      if (((cands[i][0] == num) && (cands[i][1] > 0))) {
        (cands[i][1]++);
        return;
      }
    }
    for (int i = 0; (i < k); (i++)) {
      if ((cands[i][1] == 0)) {
        (cands[i][0] = num);
        (cands[i][1] = 1);
        return;
      }
    }
    for (int i = 0; (i < k); (i++)) {
      if ((cands[i][1] > 0)) {
        (cands[i][1]--);
      }
    }
  }
  static void collect(Array<Array<int>> cands, int k, Array<int> nums, int n,
                      JList<int> ans) {
    {
      int i = 0;
      int cur = {};
      int real = {};
      for (; (i < k); (i++)) {
        if ((cands[i][1] > 0)) {
          (cur = cands[i][0]);
          (real = 0);
          for (int num : nums) {
            if ((cur == num)) {
              (real++);
            }
          }
          if ((real > jdiv(n, (k + 1)))) {
            ans.add(cur);
          }
        }
      }
    }
  }
};

/* Original teaching comments:
// 出现次数大于n/k的数
// 给定一个大小为n的数组nums，给定一个较小的正数k
// 水王数是指在数组中出现次数大于n/k的数
// 返回所有的水王数，如果没有水王数返回空列表
// 测试链接 : https://leetcode.cn/problems/majority-element-ii/
*/
