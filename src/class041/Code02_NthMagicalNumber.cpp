// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/nth-magical-number/

// Source: src/class041/Code02_NthMagicalNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NthMagicalNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NthMagicalNumber() {}
  static int nthMagicalNumber(int n, int a, int b) {
    i64 lcm = Code02_NthMagicalNumber::lcm(a, b);
    i64 ans = 0;
    {
      i64 l = 0;
      i64 r = (static_cast<i64>(n) * jmin(a, b));
      i64 m = 0;
      for (; (l <= r);) {
        (m = jdiv((l + r), 2));
        if ((((jdiv(m, a) + jdiv(m, b)) - jdiv(m, lcm)) >= n)) {
          (ans = m);
          (r = (m - 1));
        } else {
          (l = (m + 1));
        }
      }
    }
    return static_cast<int>(jrem(ans, 1000000007));
  }
  static i64 gcd(i64 a, i64 b) {
    return ((b == 0) ? a : Code02_NthMagicalNumber::gcd(b, jrem(a, b)));
  }
  static i64 lcm(i64 a, i64 b) {
    return (jdiv(static_cast<i64>(a), Code02_NthMagicalNumber::gcd(a, b)) * b);
  }
};

/* Original teaching comments:
// 一个正整数如果能被 a 或 b 整除，那么它是神奇的。
// 给定三个整数 n , a , b ，返回第 n 个神奇的数字。
// 因为答案可能很大，所以返回答案 对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/nth-magical-number/
                // l = 0
                // r = (long) n * Math.min(a, b)
                // l......r
                        // 1....m
*/
