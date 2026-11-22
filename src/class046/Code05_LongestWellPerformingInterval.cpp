// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/longest-well-performing-interval/

// Source: src/class046/Code05_LongestWellPerformingInterval.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_LongestWellPerformingInterval {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_LongestWellPerformingInterval() {}
  static int longestWPI(Array<int> hours) {
    JMap<int, int> map = JMap<int, int>();
    map.put(0, (-1));
    int ans = 0;
    {
      int i = 0;
      int sum = 0;
      for (; (i < hours.length); (i++)) {
        (sum += ((hours[i] > 8) ? 1 : (-1)));
        if ((sum > 0)) {
          (ans = (i + 1));
        } else {
          if (map.containsKey((sum - 1))) {
            (ans = jmax(ans, (i - map.get((sum - 1)))));
          }
        }
        if ((!map.containsKey(sum))) {
          map.put(sum, i);
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于
不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/
                // 某个前缀和，最早出现的位置
                // 0这个前缀和，最早出现在-1，一个数也没有的时候
                                // sum <= 0
*/
