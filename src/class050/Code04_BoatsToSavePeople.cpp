// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/boats-to-save-people/

// Source: src/class050/Code04_BoatsToSavePeople.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_BoatsToSavePeople {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_BoatsToSavePeople() {}
  static int numRescueBoats(Array<int> people, int limit) {
    j::sort(people);
    int ans = 0;
    int l = 0;
    int r = (people.length - 1);
    int sum = 0;
    while ((l <= r)) {
      (sum = ((l == r) ? people[l] : (people[l] + people[r])));
      if ((sum > limit)) {
        (r--);
      } else {
        (l++);
        (r--);
      }
      (ans++);
    }
    return ans;
  }
};

/* Original teaching comments:
// 救生艇
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
// 测试链接 : https://leetcode.cn/problems/boats-to-save-people/
        // 时间复杂度O(n * logn)，因为有排序，额外空间复杂度O(1)
*/
