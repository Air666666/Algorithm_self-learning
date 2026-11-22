// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/numbers-with-repeated-digits/

// Source: src/class084/Code04_NumbersWithRepeatedDigits.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_NumbersWithRepeatedDigits {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_NumbersWithRepeatedDigits() {}
  static int numDupDigitsAtMostN(int n) {
    return (n - Code04_NumbersWithRepeatedDigits::countSpecialNumbers(n));
  }
  static int countSpecialNumbers(int n) {
    int len = 1;
    int offset = 1;
    int tmp = jdiv(n, 10);
    while ((tmp > 0)) {
      (len++);
      (offset *= 10);
      (tmp /= 10);
    }
    Array<int> cnt = make_array<int>(len);
    (cnt[0] = 1);
    {
      int i = 1;
      int k = ((10 - len) + 1);
      for (; (i < len); (i++), (k++)) {
        (cnt[i] = (cnt[(i - 1)] * k));
      }
    }
    int ans = 0;
    if ((len >= 2)) {
      (ans = 9);
      {
        int i = 2;
        int a = 9;
        int b = 9;
        for (; (i < len); (i++), (b--)) {
          (a *= b);
          (ans += a);
        }
      }
    }
    int first = jdiv(n, offset);
    (ans += ((first - 1) * cnt[(len - 1)]));
    (ans += Code04_NumbersWithRepeatedDigits::f(
         cnt, n, (len - 1), jdiv(offset, 10), jshl(1, first)));
    return ans;
  }
  static int f(Array<int> cnt, int num, int len, int offset, int status) {
    if ((len == 0)) {
      return 1;
    }
    int ans = 0;
    int first = jrem(jdiv(num, offset), 10);
    for (int cur = 0; (cur < first); (cur++)) {
      if (((status & jshl(1, cur)) == 0)) {
        (ans += cnt[(len - 1)]);
      }
    }
    if (((status & jshl(1, first)) == 0)) {
      (ans += Code04_NumbersWithRepeatedDigits::f(
           cnt, num, (len - 1), jdiv(offset, 10), (status | jshl(1, first))));
    }
    return ans;
  }
};

/* Original teaching comments:
// 至少有1位重复的数字个数
// 给定正整数n，返回在[1, n]范围内至少有1位重复数字的正整数个数
// 测试链接 : https://leetcode.cn/problems/numbers-with-repeated-digits/
*/
