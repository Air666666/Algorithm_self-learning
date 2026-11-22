// Source: src/class105/Code02_NumberOfUniqueString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_NumberOfUniqueString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_NumberOfUniqueString() {}
  static int equalDigitFrequency(String str) {
    i64 base = 499;
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    JHashSet<i64> set = JHashSet<i64>();
    Array<int> cnt = make_array<int>(10);
    for (int i = 0; (i < n); (i++)) {
      j::fill(cnt, 0);
      i64 hashCode = 0;
      int curVal = 0;
      int maxCnt = 0;
      int maxCntKinds = 0;
      int allKinds = 0;
      for (int j = i; (j < n); (j++)) {
        (curVal = (s[j] - u'0'));
        (hashCode = (((hashCode * base) + curVal) + 1));
        (cnt[curVal]++);
        if ((cnt[curVal] == 1)) {
          (allKinds++);
        }
        if ((cnt[curVal] > maxCnt)) {
          (maxCnt = cnt[curVal]);
          (maxCntKinds = 1);
        } else if ((cnt[curVal] == maxCnt)) {
          (maxCntKinds++);
        }
        if ((maxCntKinds == allKinds)) {
          set.add(hashCode);
        }
      }
    }
    return set.size();
  }
};

/* Original teaching comments:
// 独特子串的数量
// 给你一个由数字组成的字符串s
// 返回s中独特子字符串数量
// 其中的每一个数字出现的频率都相同
// 测试链接 :
https://leetcode.cn/problems/unique-substrings-with-equal-digit-frequency/
*/
