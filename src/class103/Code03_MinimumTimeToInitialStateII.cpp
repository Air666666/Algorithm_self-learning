// Source: src/class103/Code03_MinimumTimeToInitialStateII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumTimeToInitialStateII {
  inline static int MAXN = 1000001;
  inline static Array<int> z = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumTimeToInitialStateII() {}
  static int minimumTimeToInitialState(String word, int k) {
    Array<jchar> s = word.toCharArray();
    int n = s.length;
    Code03_MinimumTimeToInitialStateII::zArray(s, n);
    for (int i = k; (i < n); (i += k)) {
      if ((z[i] == (n - i))) {
        return jdiv(i, k);
      }
    }
    return jdiv(((n + k) - 1), k);
  }
  static void zArray(Array<jchar> s, int n) {
    (z[0] = n);
    {
      int i = 1;
      int c = 1;
      int r = 1;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin((r - i), z[(i - c)]) : 0));
        while ((((i + len) < n) && (s[(i + len)] == s[len]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (z[i] = len);
      }
    }
  }
};

/* Original teaching comments:
// 将单词恢复初始状态所需的最短时间II
// 给你一个下标从0开始的字符串word和一个整数k
// 在每一秒，必须执行以下操作
// 移除word的前k个字符
// 在word的末尾添加k个任意字符
// 添加的字符不必和移除的字符相同
// 返回将word恢复到初始状态所需的最短时间
// 该时间必须大于零
// 测试链接 :
https://leetcode.cn/problems/minimum-time-to-revert-word-to-initial-state-ii/
        // leetcode增加了数据量
        // 所以把这个值改成10^6规模
*/
