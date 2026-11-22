// Source: src/class051/Code06_WaitingTime2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_WaitingTime2 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_WaitingTime2() {}
  static i64 minimumTime(Array<int> arr, int w) {
    int min = std::numeric_limits<int>::max();
    for (int x : arr) {
      (min = jmin(min, x));
    }
    i64 ans = 0;
    {
      i64 l = 0;
      i64 r = (static_cast<i64>(min) * w);
      i64 m = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        if ((Code06_WaitingTime2::f(arr, m) >= w)) {
          (ans = m);
          (r = (m - 1));
        } else {
          (l = (m + 1));
        }
      }
    }
    return ans;
  }
  static i64 f(Array<int> arr, i64 time) {
    i64 ans = 0;
    for (int num : arr) {
      (ans += jdiv(time, num));
    }
    return ans;
  }
};

/* Original teaching comments:
// 完成旅途的最少时间(题目6的在线测试)
// 有同学找到了在线测试链接，和课上讲的题目6几乎是一个意思，但是有细微差别
//
实现的代码，除了一些变量需要改成long类型之外，仅有两处关键逻辑不同，都打上了注释
// 除此之外，和课上讲的题目6的实现，再无区别
// 可以仔细阅读如下测试链接里的题目，重点关注此题和题目6，在题意上的差别
// 测试链接 : https://leetcode.cn/problems/minimum-time-to-complete-trips/
                        // 这里逻辑和课上讲的不同
                        // 课上讲的题意，是需要等多少人才能获得服务，你是第w+1个
                        // 在线测试的题意，是需要完成w趟旅行
                        // 这里逻辑和课上讲的不同
                        // 课上讲的题意，计算time时间内，(完成 +
开始)服务的人数，需要+1
                        //
在线测试的题意，计算time时间内，能完成多少旅行，不需要+1
*/
