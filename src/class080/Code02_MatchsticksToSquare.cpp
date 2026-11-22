// Source: src/class080/Code02_MatchsticksToSquare.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MatchsticksToSquare {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MatchsticksToSquare() {}
  static bool makesquare(Array<int> nums) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    if ((jrem(sum, 4) != 0)) {
      return false;
    }
    int n = nums.length;
    Array<int> dp = make_array<int>(jshl(1, n));
    return Code02_MatchsticksToSquare::f(nums, jdiv(sum, 4), (jshl(1, n) - 1),
                                         0, 4, dp);
  }
  static bool f(Array<int> nums, int limit, int status, int cur, int rest,
                Array<int> dp) {
    if ((rest == 0)) {
      return (status == 0);
    }
    if ((dp[status] != 0)) {
      return (dp[status] == 1);
    }
    bool ans = false;
    for (int i = 0; (i < nums.length); (i++)) {
      if ((((status & jshl(1, i)) != 0) && ((cur + nums[i]) <= limit))) {
        if (((cur + nums[i]) == limit)) {
          (ans = Code02_MatchsticksToSquare::f(
               nums, limit, (status ^ jshl(1, i)), 0, (rest - 1), dp));
        } else {
          (ans = Code02_MatchsticksToSquare::f(
               nums, limit, (status ^ jshl(1, i)), (cur + nums[i]), rest, dp));
        }
        if (ans) {
          break;
        }
      }
    }
    (dp[status] = (ans ? 1 : (-1)));
    return ans;
  }
};

/* Original teaching comments:
// 火柴拼正方形
// 你将得到一个整数数组 matchsticks
// 其中 matchsticks[i] 是第 i 个火柴棒的长度
// 你要用 所有的火柴棍 拼成一个正方形
// 你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须
使用一次
// 如果你能拼出正方形，则返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/matchsticks-to-square/
        // limit : 每条边规定的长度
        // status : 表示哪些数字还可以选
        // cur : 当前要解决的这条边已经形成的长度
        // rest : 一共还有几条边没有解决
        // 返回 : 能否用光所有火柴去解决剩下的所有边
        // 因为调用子过程之前，一定保证每条边累加起来都不超过limit
        // 所以status是决定cur和rest的，关键可变参数只有status
                        // 考察每一根火柴，只能使用状态为1的火柴
*/
