// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-total-distance-traveled/

// Source: src/class130/Code05_MinimumTotalDistanceTraveled.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MinimumTotalDistanceTraveled {
  inline static i64 NA = std::numeric_limits<i64>::max();
  inline static int MAXN = 101;
  inline static int MAXM = 101;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> fac = make_array<int>(MAXN, 2);
  inline static Array<int> rob = make_array<int>(MAXM);
  inline static Array<Array<i64>> dp = make_array<i64>(MAXN, MAXM);
  inline static Array<i64> sum = make_array<i64>(MAXM);
  inline static Array<int> queue = make_array<int>(MAXM);
  inline static int l = {};
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MinimumTotalDistanceTraveled() {}
  static void build(Array<Array<int>> factory, JList<int> robot) {
    j::sort(factory, [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    robot.sort([=](Box<int> a, Box<int> b) { return (a - b); });
    (n = factory.length);
    (m = robot.size());
    for (int i = 1; (i <= n); (i++)) {
      (fac[i][0] = factory[(i - 1)][0]);
      (fac[i][1] = factory[(i - 1)][1]);
    }
    for (int i = 1; (i <= m); (i++)) {
      (rob[i] = robot.get((i - 1)));
    }
    for (int j = 1; (j <= m); (j++)) {
      (dp[0][j] = NA);
    }
  }
  static i64 minimumTotalDistance(JList<int> robot, Array<Array<int>> factory) {
    Code05_MinimumTotalDistanceTraveled::build(factory, robot);
    {
      int i = 1;
      int cap = {};
      for (; (i <= n); (i++)) {
        (cap = fac[i][1]);
        for (int j = 1; (j <= m); (j++)) {
          (sum[j] = (sum[(j - 1)] +
                     Code05_MinimumTotalDistanceTraveled::dist(i, j)));
        }
        (l = (r = 0));
        for (int j = 1; (j <= m); (j++)) {
          (dp[i][j] = dp[(i - 1)][j]);
          if ((Code05_MinimumTotalDistanceTraveled::value(i, j) != NA)) {
            while (((l < r) && [&]() {
              auto jleft =
                  Code05_MinimumTotalDistanceTraveled::value(i, queue[(r - 1)]);
              auto jright = Code05_MinimumTotalDistanceTraveled::value(i, j);
              return (jleft >= jright);
            }())) {
              (r--);
            }
            (queue[(r++)] = j);
          }
          if (((l < r) && (queue[l] == (j - cap)))) {
            (l++);
          }
          if ((l < r)) {
            (dp[i][j] =
                 jmin(dp[i][j],
                      (Code05_MinimumTotalDistanceTraveled::value(i, queue[l]) +
                       sum[j])));
          }
        }
      }
    }
    return dp[n][m];
  }
  static i64 dist(int i, int j) {
    return std::abs((static_cast<i64>(fac[i][0]) - rob[j]));
  }
  static i64 value(int i, int j) {
    if ((dp[(i - 1)][(j - 1)] == NA)) {
      return NA;
    }
    return (dp[(i - 1)][(j - 1)] - sum[(j - 1)]);
  }
};

/* Original teaching comments:
// 最小移动总距离
// 所有工厂和机器人都分布在x轴上
//
给定长度为n的二维数组factory，factory[i][0]为i号工厂的位置，factory[i][1]为容量
// 给定长度为m的一维数组robot，robot[j]为第j个机器人的位置
//
每个工厂所在的位置都不同，每个机器人所在的位置都不同，机器人到工厂的距离为位置差的绝对值
//
所有机器人都是坏的，但是机器人可以去往任何工厂进行修理，但是不能超过某个工厂的容量
// 测试数据保证所有机器人都可以被维修，返回所有机器人移动的最小总距离
// 1 <= n、m <= 100
// -10^9 <= factory[i][0]、robot[j] <= +10^9
// 0 <= factory[i][1] <= m
// 测试链接 : https://leetcode.cn/problems/minimum-total-distance-traveled/
        // 工厂下标从1开始，fac[i][0]表示位置，fac[i][1]表示容量
        // 机器人下标从1开始，rob[i]表示位置
        // dp[i][j] : 1...i工厂去修理1...j号机器人，最短总距离是多少
        // 前缀和数组
        // 单调队列
                // 工厂和机器人都根据所在位置排序
                // 让工厂和机器人的下标都从1开始
                // dp初始化
        // 最优解O(n * m)
        // 其他题解都没有达到这个最优复杂度
                        // i号工厂的容量
                        // sum[j]表示
                        // 1号机器人去往i号工厂的距离
                        // 2号机器人去往i号工厂的距离
                        // ...
                        // j号机器人去往i号工厂的距离
                        // 上面全加起来，也就是前缀和的概念
        // i号工厂和j号机器人的距离
        // i号工厂从j号机器人开始负责的指标
        // 真的可行，返回指标的值
        // 如果不可行，返回NA
*/
