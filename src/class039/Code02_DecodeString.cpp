// Source: src/class039/Code02_DecodeString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DecodeString {
  inline static int where = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DecodeString() {}
  static String decodeString(String str) {
    (where = 0);
    return Code02_DecodeString::f(str.toCharArray(), 0);
  }
  static String f(Array<jchar> s, int i) {
    StringBuilder path = StringBuilder();
    int cnt = 0;
    while (((i < s.length) && (s[i] != u']'))) {
      if ((((s[i] >= u'a') && (s[i] <= u'z')) ||
           ((s[i] >= u'A') && (s[i] <= u'Z')))) {
        path.append(s[(i++)]);
      } else if (((s[i] >= u'0') && (s[i] <= u'9'))) {
        (cnt = (((cnt * 10) + s[(i++)]) - u'0'));
      } else {
        path.append(
            Code02_DecodeString::get(cnt, Code02_DecodeString::f(s, (i + 1))));
        (i = (where + 1));
        (cnt = 0);
      }
    }
    (where = i);
    return path.toString();
  }
  static String get(int cnt, String str) {
    StringBuilder builder = StringBuilder();
    for (int i = 0; (i < cnt); (i++)) {
      builder.append(str);
    }
    return builder.toString();
  }
};

/* Original teaching comments:
// 含有嵌套的字符串解码
// 测试链接 : https://leetcode.cn/problems/decode-string/
        // s[i....]开始计算，遇到字符串终止 或者 遇到 ] 停止
        // 返回 : 自己负责的这一段字符串的结果
        // 返回之间，更新全局变量where，为了上游函数知道从哪继续！
                                // 遇到 [
                                // cnt = 7 * ?
*/
