// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/string-transforms-into-another-string/
// https://www.lintcode.com/problem/3869

// Source: src/class093/Code03_StringTransforms.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_StringTransforms {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_StringTransforms() {}
  static bool canConvert(String str1, String str2) {
    if (str1.equals(str2)) {
      return true;
    }
    Array<int> map = make_array<int>(26);
    int kinds = 0;
    for (int i = 0; (i < str2.length()); (i++)) {
      if (((map[(str2.charAt(i) - u'a')]++) == 0)) {
        (kinds++);
      }
    }
    if ((kinds == 26)) {
      return false;
    }
    j::fill(map, (-1));
    {
      int i = 0;
      int cur = {};
      for (; (i < str1.length()); (i++)) {
        (cur = (str1.charAt(i) - u'a'));
        if (((map[cur] != (-1)) && [&]() {
              auto jleft = str2.charAt(map[cur]);
              auto jright = str2.charAt(i);
              return (jleft != jright);
            }())) {
          return false;
        }
        (map[cur] = i);
      }
    }
    return true;
  }
};

/* Original teaching comments:
// 字符串转化
// 给出两个长度相同的字符串str1和str2
// 请你帮忙判断字符串str1能不能在 零次 或 多次 转化后变成字符串str2
// 每一次转化时，你可以将str1中出现的所有相同字母变成其他任何小写英文字母
// 只有在字符串str1能够通过上述方式顺利转化为字符串str2时才能返回true
// 测试链接 :
https://leetcode.cn/problems/string-transforms-into-another-string/
// 测试链接 : https://www.lintcode.com/problem/3869
                // map[x] : str2中字符x的词频
                // kinds : str2中字符的种类数
                // map[x] = y : str1中的字符x上次出现在str1中的y位置
*/
