// Source: src/class043/Code03_IsPalindrome.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_IsPalindrome {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_IsPalindrome() {}
  static bool isPalindrome(int num) {
    if ((num < 0)) {
      return false;
    }
    int offset = 1;
    while ((jdiv(num, offset) >= 10)) {
      (offset *= 10);
    }
    while ((num != 0)) {
      if ((jdiv(num, offset) != jrem(num, 10))) {
        return false;
      }
      (num = jdiv(jrem(num, offset), 10));
      (offset /= 100);
    }
    return true;
  }
};

/* Original teaching comments:
// 超级回文数中的一个小函数，本身也是一道题 : 判断一个数字是不是回文数
// 测试链接 : https://leetcode.cn/problems/palindrome-number/
                // 注意这么写是为了防止溢出
                // 首尾判断
*/
