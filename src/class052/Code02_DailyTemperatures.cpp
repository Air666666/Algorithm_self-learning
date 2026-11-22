// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/daily-temperatures/

// Source: src/class052/Code02_DailyTemperatures.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DailyTemperatures {
  inline static int MAXN = 100001;
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DailyTemperatures() {}
  static Array<int> dailyTemperatures(Array<int> nums) {
    int n = nums.length;
    Array<int> ans = make_array<int>(n);
    (r = 0);
    {
      int i = 0;
      int cur = {};
      for (; (i < n); (i++)) {
        while (((r > 0) && (nums[stack[(r - 1)]] < nums[i]))) {
          (cur = stack[(--r)]);
          (ans[cur] = (i - cur));
        }
        (stack[(r++)] = i);
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 测试链接 : https://leetcode.cn/problems/daily-temperatures/
                        // 相等时候的处理，相等也加入单调栈
*/
