// Source: src/class066/Code02_MinimumCostForTickets.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MinimumCostForTickets {
  inline static Array<int> durations = Array<int>{1, 7, 30};
  inline static int MAXN = 366;
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MinimumCostForTickets() {}
  static int mincostTickets1(Array<int> days, Array<int> costs) {
    return Code02_MinimumCostForTickets::f1(days, costs, 0);
  }
  static int f1(Array<int> days, Array<int> costs, int i) {
    if ((i == days.length)) {
      return 0;
    }
    int ans = std::numeric_limits<int>::max();
    {
      int k = 0;
      int j = i;
      for (; (k < 3); (k++)) {
        while (((j < days.length) && ((days[i] + durations[k]) > days[j]))) {
          (j++);
        }
        (ans = jmin(ans, (costs[k] +
                          Code02_MinimumCostForTickets::f1(days, costs, j))));
      }
    }
    return ans;
  }
  static int mincostTickets2(Array<int> days, Array<int> costs) {
    Array<int> dp = make_array<int>(days.length);
    for (int i = 0; (i < days.length); (i++)) {
      (dp[i] = std::numeric_limits<int>::max());
    }
    return Code02_MinimumCostForTickets::f2(days, costs, 0, dp);
  }
  static int f2(Array<int> days, Array<int> costs, int i, Array<int> dp) {
    if ((i == days.length)) {
      return 0;
    }
    if ((dp[i] != std::numeric_limits<int>::max())) {
      return dp[i];
    }
    int ans = std::numeric_limits<int>::max();
    {
      int k = 0;
      int j = i;
      for (; (k < 3); (k++)) {
        while (((j < days.length) && ((days[i] + durations[k]) > days[j]))) {
          (j++);
        }
        (ans = jmin(ans, (costs[k] + Code02_MinimumCostForTickets::f2(
                                         days, costs, j, dp))));
      }
    }
    (dp[i] = ans);
    return ans;
  }
  static int mincostTickets3(Array<int> days, Array<int> costs) {
    int n = days.length;
    j::fill(dp, 0, (n + 1), std::numeric_limits<int>::max());
    (dp[n] = 0);
    for (int i = (n - 1); (i >= 0); (i--)) {
      {
        int k = 0;
        int j = i;
        for (; (k < 3); (k++)) {
          while (((j < days.length) && ((days[i] + durations[k]) > days[j]))) {
            (j++);
          }
          (dp[i] = jmin(dp[i], (costs[k] + dp[j])));
        }
      }
    }
    return dp[0];
  }
};

/* Original teaching comments:
// 最低票价
// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
// 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
// 每一项是一个从 1 到 365 的整数
// 火车票有 三种不同的销售方式
// 一张 为期1天 的通行证售价为 costs[0] 美元
// 一张 为期7天 的通行证售价为 costs[1] 美元
// 一张 为期30天 的通行证售价为 costs[2] 美元
// 通行证允许数天无限制的旅行
// 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
// 那么我们可以连着旅行 7 天(第2~8天)
// 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
// 测试链接 : https://leetcode.cn/problems/minimum-cost-for-tickets/
        // 无论提交什么方法都带着这个数组      0  1  2
        // 暴力尝试
        // days[i..... 最少花费是多少
                        // 后续已经无旅行了
                // i下标 : 第days[i]天，有一场旅行
                // i.... 最少花费是多少
                        // k是方案编号 : 0 1 2
                                // 因为方案2持续的天数最多，30天
                                // 所以while循环最多执行30次
                                // 枚举行为可以认为是O(1)
        // 暴力尝试改记忆化搜索
        // 从顶到底的动态规划
        // 严格位置依赖的动态规划
        // 从底到顶的动态规划
*/
