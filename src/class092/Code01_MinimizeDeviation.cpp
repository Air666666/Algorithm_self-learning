// Source: src/class092/Code01_MinimizeDeviation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimizeDeviation {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimizeDeviation() {}
  static int minimumDeviation(Array<int> nums) {
    JSet<int> set = JSet<int>();
    for (int num : nums) {
      if ((jrem(num, 2) == 0)) {
        set.add(num);
      } else {
        set.add((num * 2));
      }
    }
    int ans = [&]() {
      auto jleft = set.last();
      auto jright = set.first();
      return (jleft - jright);
    }();
    while (((ans > 0) && (jrem(set.last(), 2) == 0))) {
      int max = set.last();
      set.remove(max);
      set.add(jdiv(max, 2));
      (ans = jmin(ans, [&]() {
         auto jleft = set.last();
         auto jright = set.first();
         return (jleft - jright);
       }()));
    }
    return ans;
  }
};

/* Original teaching comments:
// 数组的最小偏移量
// 给你一个由n个正整数组成的数组nums
// 你可以对数组的任意元素执行任意次数的两类操作：
// 如果元素是偶数，除以2
// 例如如果数组是[1,2,3,4]
// 那么你可以对最后一个元素执行此操作，使其变成[1,2,3,2]
// 如果元素是奇数，乘上2
// 例如如果数组是[1,2,3,4]
// 那么你可以对第一个元素执行此操作，使其变成[2,2,3,4]
// 数组的偏移量是数组中任意两个元素之间的最大差值
// 返回数组在执行某些操作之后可以拥有的最小偏移量
// 测试链接 : https://leetcode.cn/problems/minimize-deviation-in-array/
                // 有序表可以查询最大值、最小值
*/
