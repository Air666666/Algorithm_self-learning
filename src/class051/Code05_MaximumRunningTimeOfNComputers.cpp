// Source: src/class051/Code05_MaximumRunningTimeOfNComputers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MaximumRunningTimeOfNComputers {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MaximumRunningTimeOfNComputers() {}
  static i64 maxRunTime1(int num, Array<int> arr) {
    i64 sum = 0;
    for (int x : arr) {
      (sum += x);
    }
    i64 ans = 0;
    {
      i64 l = 0;
      i64 r = sum;
      i64 m = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        if (Code05_MaximumRunningTimeOfNComputers::f1(arr, num, m)) {
          (ans = m);
          (l = (m + 1));
        } else {
          (r = (m - 1));
        }
      }
    }
    return ans;
  }
  static bool f1(Array<int> arr, int num, i64 time) {
    i64 sum = 0;
    for (int x : arr) {
      if ((x > time)) {
        (num--);
      } else {
        (sum += x);
      }
      if ((sum >= (static_cast<i64>(num) * time))) {
        return true;
      }
    }
    return false;
  }
  static i64 maxRunTime2(int num, Array<int> arr) {
    int max = 0;
    i64 sum = 0;
    for (int x : arr) {
      (max = jmax(max, x));
      (sum += x);
    }
    if ((sum > (static_cast<i64>(max) * num))) {
      return jdiv(sum, num);
    }
    int ans = 0;
    {
      int l = 0;
      int r = max;
      int m = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        if (Code05_MaximumRunningTimeOfNComputers::f2(arr, num, m)) {
          (ans = m);
          (l = (m + 1));
        } else {
          (r = (m - 1));
        }
      }
    }
    return ans;
  }
  static bool f2(Array<int> arr, int num, int time) {
    i64 sum = 0;
    for (int x : arr) {
      if ((x > time)) {
        (num--);
      } else {
        (sum += x);
      }
      if ((sum >= (static_cast<i64>(num) * time))) {
        return true;
      }
    }
    return false;
  }
};

/* Original teaching comments:
// 同时运行N台电脑的最长时间
// 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries
// 其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟
// 你想使用这些电池让 全部 n 台电脑 同时 运行。
// 一开始，你可以给每台电脑连接 至多一个电池
//
然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作
任意次
// 新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池
// 断开连接和连接新的电池不会花费任何时间。
// 注意，你不能给电池充电。
// 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
// 测试链接 : https://leetcode.cn/problems/maximum-running-time-of-n-computers/
        // 单纯的二分答案法
        // 提交时把函数名改为maxRunTime
        // 时间复杂度O(n * log(sum))，额外空间复杂度O(1)
                // [0, sum]，不停二分
                        // m中点，让num台电脑共同运行m分钟，能不能做到
        // 让num台电脑共同运行time分钟，能不能做到
                // 碎片电量总和
                                // x <= time，是碎片电池
                                // 碎片电量 >= 台数 * 要求
        // 二分答案法 + 增加分析(贪心)
        // 提交时把函数名改为maxRunTime
        // 时间复杂度O(n * log(max))，额外空间复杂度O(1)
                // 就是增加了这里的逻辑
                        // 所有电池的最大电量是max
                        // 如果此时sum > (long) max * num，
                        // 说明 : 最终的供电时间一定在 >=
max，而如果最终的供电时间 >= max
                        // 说明 :
对于最终的答案X来说，所有电池都是课上讲的"碎片拼接"的概念
                        // 那么寻找 ? * num <= sum 的情况中，尽量大的 ? 即可
                        // 即sum / num
                // 最终的供电时间一定在 < max范围上
                // [0, sum]二分范围，可能定的比较粗，虽然不影响，但毕竟是有点慢
                // [0, max]二分范围！更精细的范围，二分次数会变少
                // 碎片电量总和
*/
