// Source: src/class085/Code04_DigitCount3.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DigitCount3 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DigitCount3() {}
  static int countDigitOne(int n) { return Code04_DigitCount3::count(n, 1); }
  static int count(int num, int d) {
    int ans = 0;
    {
      int right = 1;
      int tmp = num;
      int left = {};
      int cur = {};
      for (; (tmp != 0); (right *= 10), (tmp /= 10)) {
        (left = jdiv(tmp, 10));
        (cur = jrem(tmp, 10));
        if ((d == 0)) {
          (left--);
        }
        (ans += (left * right));
        if ((cur > d)) {
          (ans += right);
        } else if ((cur == d)) {
          (ans += (jrem(num, right) + 1));
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 数字1的个数
// 给定一个整数n
// 计算所有小于等于n的非负整数中数字1出现的个数
// 测试链接 : https://leetcode.cn/problems/number-of-digit-one/
*/
