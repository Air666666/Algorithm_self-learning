// Source: src/class129/Code03_CountRepetitions.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CountRepetitions {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CountRepetitions() {}
  static int getMaxRepetitions(String str1, int a, String str2, int b) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    Array<Array<int>> next = make_array<int>(n, 26);
    if ((!Code03_CountRepetitions::find(s1, n, next, s2))) {
      return 0;
    }
    Array<Array<i64>> st = make_array<i64>(n, 30);
    {
      int i = 0;
      int cur = {};
      int len = {};
      for (; (i < n); (i++)) {
        (cur = i);
        (len = 0);
        for (jchar c : s2) {
          (len += next[cur][(c - u'a')]);
          (cur = jrem((cur + next[cur][(c - u'a')]), n));
        }
        (st[i][0] = len);
      }
    }
    for (int p = 1; (p <= 29); (p++)) {
      for (int i = 0; (i < n); (i++)) {
        (st[i][p] =
             (st[i][(p - 1)] +
              st[static_cast<int>(jrem((st[i][(p - 1)] + i), n))][(p - 1)]));
      }
    }
    i64 ans = 0;
    {
      int p = 29;
      int start = 0;
      for (; (p >= 0); (p--)) {
        if (((st[jrem(start, n)][p] + start) <= (n * a))) {
          (ans += jshl(1, p));
          (start += st[jrem(start, n)][p]);
        }
      }
    }
    return static_cast<int>(jdiv(ans, b));
  }
  static bool find(Array<jchar> s1, int n, Array<Array<int>> next,
                   Array<jchar> s2) {
    Array<int> right = make_array<int>(26);
    j::fill(right, (-1));
    for (int i = (n - 1); (i >= 0); (i--)) {
      (right[(s1[i] - u'a')] = (i + n));
    }
    for (int i = (n - 1); (i >= 0); (i--)) {
      (right[(s1[i] - u'a')] = i);
      for (int j = 0; (j < 26); (j++)) {
        if ((right[j] != (-1))) {
          (next[i][j] = ((right[j] - i) + 1));
        } else {
          (next[i][j] = (-1));
        }
      }
    }
    for (jchar c : s2) {
      if ((next[0][(c - u'a')] == (-1))) {
        return false;
      }
    }
    return true;
  }
};

/* Original teaching comments:
// 统计重复个数
// 如果字符串x删除一些字符，可以得到字符串y，那么就说y可以从x中获得
// 给定s1和a，代表s1拼接a次，记为字符串x
// 给定s2和b，代表s2拼接b次，记为字符串y
// 现在把y拼接m次之后，得到的字符串依然可能从x中获得，返回尽可能大的m
// s1、s2只由小写字母组成
// 1 <= s1长度、s2长度 <= 100
// 1 <= a、b <= 10^6
// 测试链接 : https://leetcode.cn/problems/count-the-repetitions/
        // 该题的题解中有很多打败比例优异，但是时间复杂度不是最优的方法
        // 如果数据苛刻一些，就通过不了，所以一定要做到时间复杂度与a、b的值无关
        // 本方法时间复杂度O(s1长度 *
s2长度)，一定是最优解，而且比其他方法更好理解
                // next[i][j] : 从i位置出发，至少需要多少长度，能找到j字符
                // 时间复杂度O(s1长度 + s2长度)
                // st[i][p] : 从i位置出发，至少需要多少长度，可以获得2^p个s2
                // 时间复杂度O(s1长度 * s2长度)
                // 时间复杂度O(s1长度)
                // 时间复杂度O(1)
        // 时间复杂度O(s1长度 + s2长度)
*/
