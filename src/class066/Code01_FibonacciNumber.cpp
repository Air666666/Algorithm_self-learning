// Source: src/class066/Code01_FibonacciNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_FibonacciNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_FibonacciNumber() {}
  static int fib1(int n) { return Code01_FibonacciNumber::f1(n); }
  static int f1(int i) {
    if ((i == 0)) {
      return 0;
    }
    if ((i == 1)) {
      return 1;
    }
    return [&]() {
      auto jleft = Code01_FibonacciNumber::f1((i - 1));
      auto jright = Code01_FibonacciNumber::f1((i - 2));
      return (jleft + jright);
    }();
  }
  static int fib2(int n) {
    Array<int> dp = make_array<int>((n + 1));
    j::fill(dp, (-1));
    return Code01_FibonacciNumber::f2(n, dp);
  }
  static int f2(int i, Array<int> dp) {
    if ((i == 0)) {
      return 0;
    }
    if ((i == 1)) {
      return 1;
    }
    if ((dp[i] != (-1))) {
      return dp[i];
    }
    int ans = [&]() {
      auto jleft = Code01_FibonacciNumber::f2((i - 1), dp);
      auto jright = Code01_FibonacciNumber::f2((i - 2), dp);
      return (jleft + jright);
    }();
    (dp[i] = ans);
    return ans;
  }
  static int fib3(int n) {
    if ((n == 0)) {
      return 0;
    }
    if ((n == 1)) {
      return 1;
    }
    Array<int> dp = make_array<int>((n + 1));
    (dp[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (dp[i] = (dp[(i - 1)] + dp[(i - 2)]));
    }
    return dp[n];
  }
  static int fib4(int n) {
    if ((n == 0)) {
      return 0;
    }
    if ((n == 1)) {
      return 1;
    }
    int lastLast = 0;
    int last = 1;
    {
      int i = 2;
      int cur = {};
      for (; (i <= n); (i++)) {
        (cur = (lastLast + last));
        (lastLast = last);
        (last = cur);
      }
    }
    return last;
  }
};

/* Original teaching comments:
// 斐波那契数
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
// 也就是：F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n)
// 测试链接 : https://leetcode.cn/problems/fibonacci-number/
// 注意：最优解来自矩阵快速幂，时间复杂度可以做到O(log n)
// 后续课程一定会讲述！本节课不涉及！
*/
