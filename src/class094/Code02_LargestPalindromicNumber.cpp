// Source: src/class094/Code02_LargestPalindromicNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LargestPalindromicNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LargestPalindromicNumber() {}
  static String largestPalindromic(String num) {
    int n = num.length();
    Array<int> cnts = make_array<int>(58);
    for (jchar a : num.toCharArray()) {
      (cnts[a]++);
    }
    Array<jchar> ans = make_array<jchar>(n);
    int leftSize = 0;
    jchar mid = 0;
    for (jchar i = u'9'; (i >= u'1'); (i--)) {
      if ((((cnts[i] & 1) == 1) && (mid == 0))) {
        (mid = i);
      }
      for (int j = jdiv(cnts[i], 2); (j > 0); (j--)) {
        (ans[(leftSize++)] = i);
      }
    }
    if ((leftSize == 0)) {
      if ((mid == 0)) {
        return String(u"0");
      } else {
        return j::str(mid);
      }
    }
    for (int j = jdiv(cnts[u'0'], 2); (j > 0); (j--)) {
      (ans[(leftSize++)] = u'0');
    }
    int len = leftSize;
    if (((mid == 0) && ((cnts[u'0'] & 1) == 1))) {
      (mid = u'0');
    }
    if ((mid != 0)) {
      (ans[(len++)] = mid);
    }
    for (int i = (leftSize - 1); (i >= 0); (i--)) {
      (ans[(len++)] = ans[i]);
    }
    return String(ans, 0, len);
  }
};

/* Original teaching comments:
// 最大回文数字
// 给你一个仅由数字（0 - 9）组成的字符串num
// 请你找出能够使用num中数字形成的最大回文整数
// 并以字符串形式返回，该整数不含前导零
// 你无需使用num中的所有数字，但你必须使用至少一个数字，数字可以重新排列
// 测试链接 : https://leetcode.cn/problems/largest-palindromic-number/
                // '0' ~ '9'字符对应整数为48 ~ 57
                // '1'~'9'有若干字符出现次数 >=
2，左部分已经建立，再考虑把'0'字符填进来
                // 把中点安插进去
                // 左部分逆序拷贝给右部分
*/
