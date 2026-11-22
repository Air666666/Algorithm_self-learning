// Source: src/class100/Code01_KMP.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_KMP {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_KMP() {}
  static int strStr(String s1, String s2) {
    return [&]() {
      auto jargument_0 = s1.toCharArray();
      auto jargument_1 = s2.toCharArray();
      return Code01_KMP::kmp(jargument_0, jargument_1);
    }();
  }
  static int kmp(Array<jchar> s1, Array<jchar> s2) {
    int n = s1.length;
    int m = s2.length;
    int x = 0;
    int y = 0;
    Array<int> next = Code01_KMP::nextArray(s2, m);
    while (((x < n) && (y < m))) {
      if ((s1[x] == s2[y])) {
        (x++);
        (y++);
      } else if ((y == 0)) {
        (x++);
      } else {
        (y = next[y]);
      }
    }
    return ((y == m) ? (x - y) : (-1));
  }
  static Array<int> nextArray(Array<jchar> s, int m) {
    if ((m == 1)) {
      return Array<int>{(-1)};
    }
    Array<int> next = make_array<int>(m);
    (next[0] = (-1));
    (next[1] = 0);
    int i = 2;
    int cn = 0;
    while ((i < m)) {
      if ((s[(i - 1)] == s[cn])) {
        (next[(i++)] = (++cn));
      } else if ((cn > 0)) {
        (cn = next[cn]);
      } else {
        (next[(i++)] = 0);
      }
    }
    return next;
  }
};

/* Original teaching comments:
// KMP算法模版
// 测试链接 :
https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
                // return s1.indexOf(s2);
        // KMP算法
                // s1中当前比对的位置是x
                // s2中当前比对的位置是y
                // O(m)
                // O(n)
        // 得到next数组
                // i表示当前要求next值的位置
                // cn表示当前要和前一个字符比对的下标
*/
