// Source: src/class104/Code03_SplitMaximumPalindromes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SplitMaximumPalindromes {
  inline static int MAXN = 2001;
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SplitMaximumPalindromes() {}
  static int maxPalindromes(String str, int k) {
    Code03_SplitMaximumPalindromes::manacherss(str.toCharArray());
    int ans = 0;
    int next = 0;
    while (((next = Code03_SplitMaximumPalindromes::find(next, k)) != (-1))) {
      (ans++);
    }
    return ans;
  }
  static void manacherss(Array<jchar> a) {
    (n = ((a.length * 2) + 1));
    {
      int i = 0;
      int j = 0;
      for (; (i < n); (i++)) {
        (ss[i] = (((i & 1) == 0) ? u'#' : a[(j++)]));
      }
    }
  }
  static int find(int l, int k) {
    {
      int i = l;
      int c = l;
      int r = l;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin(p[((2 * c) - i)], (r - i)) : 1));
        while (((((i + len) < n) && ((i - len) >= l)) &&
                (ss[(i + len)] == ss[(i - len)]))) {
          if (((++len) > k)) {
            return ((i + k) + ((ss[(i + k)] != u'#') ? 1 : 0));
          }
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (p[i] = len);
      }
    }
    return (-1);
  }
};

/* Original teaching comments:
// 不重叠回文子串的最多数目
// 给定一个字符串str和一个正数k
// 你可以随意把str切分成多个子串
// 目的是找到某一种划分方案，有尽可能多的回文子串
// 并且每个回文子串都要求长度>=k、且彼此没有重合的部分
// 返回最多能划分出几个这样的回文子串
// 测试链接 :
https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/
        // 时间复杂度O(n)
        // 扩展串ss从l位置开始往右寻找回文，且ss[l]一定是'#'
        // 一旦有某个中心的回文半径>k，马上返回最右下标
        // 表示找到了距离l最近且长度>=k的回文串
        // 返回的这个最右下标一定要命中'#'
        // 如果没有命中返回(最右下标+1)，让其一定命中'#'
        // 如果不存在距离l最近且长度>=k的回文串，返回-1
*/
