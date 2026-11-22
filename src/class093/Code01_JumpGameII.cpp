// Source: src/class093/Code01_JumpGameII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_JumpGameII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_JumpGameII() {}
  static int jump(Array<int> arr) {
    int n = arr.length;
    int cur = 0;
    int next = 0;
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      if ((cur < i)) {
        (ans++);
        (cur = next);
      }
      (next = jmax(next, (i + arr[i])));
    }
    return ans;
  }
};

/* Original teaching comments:
// 跳跃游戏II
// 给定一个长度为n的整数数组nums
// 你初始在0下标，nums[i]表示你可以从i下标往右跳的最大距离
// 比如，nums[0] = 3
// 表示你可以从0下标去往：1下标、2下标、3下标
// 你达到i下标后，可以根据nums[i]的值继续往右跳
// 返回你到达n-1下标的最少跳跃次数
// 测试用例可以保证一定能到达
// 测试链接 : https://leetcode.cn/problems/jump-game-ii/
                // 当前步以内，最右到哪
                // 如果再一步，(当前步+1)以内，最右到哪
                // 一共需要跳几步
                        // 来到i下标
                        // cur包括了i所在的位置，不用付出额外步数
                        // cur没有包括i所在的位置，需要付出额外步数
*/
