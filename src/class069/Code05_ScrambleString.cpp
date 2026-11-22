// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/scramble-string/

// Source: src/class069/Code05_ScrambleString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ScrambleString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ScrambleString() {}
  static bool isScramble1(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    return Code05_ScrambleString::f1(s1, 0, (n - 1), s2, 0, (n - 1));
  }
  static bool f1(Array<jchar> s1, int l1, int r1, Array<jchar> s2, int l2,
                 int r2) {
    if ((l1 == r1)) {
      return (s1[l1] == s2[l2]);
    }
    {
      int i = l1;
      int j = l2;
      for (; (i < r1); (i++), (j++)) {
        if ((Code05_ScrambleString::f1(s1, l1, i, s2, l2, j) &&
             Code05_ScrambleString::f1(s1, (i + 1), r1, s2, (j + 1), r2))) {
          return true;
        }
      }
    }
    {
      int i = l1;
      int j = r2;
      for (; (i < r1); (i++), (j--)) {
        if ((Code05_ScrambleString::f1(s1, l1, i, s2, j, r2) &&
             Code05_ScrambleString::f1(s1, (i + 1), r1, s2, l2, (j - 1)))) {
          return true;
        }
      }
    }
    return false;
  }
  static bool isScramble2(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    return Code05_ScrambleString::f2(s1, s2, 0, 0, n);
  }
  static bool f2(Array<jchar> s1, Array<jchar> s2, int l1, int l2, int len) {
    if ((len == 1)) {
      return (s1[l1] == s2[l2]);
    }
    for (int k = 1; (k < len); (k++)) {
      if ((Code05_ScrambleString::f2(s1, s2, l1, l2, k) &&
           Code05_ScrambleString::f2(s1, s2, (l1 + k), (l2 + k), (len - k)))) {
        return true;
      }
    }
    {
      int i = (l1 + 1);
      int j = ((l2 + len) - 1);
      int k = 1;
      for (; (k < len); (i++), (j--), (k++)) {
        if ((Code05_ScrambleString::f2(s1, s2, l1, j, k) &&
             Code05_ScrambleString::f2(s1, s2, i, l2, (len - k)))) {
          return true;
        }
      }
    }
    return false;
  }
  static bool isScramble3(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    Array<Array<Array<int>>> dp = make_array<int>(n, n, (n + 1));
    return Code05_ScrambleString::f3(s1, s2, 0, 0, n, dp);
  }
  static bool f3(Array<jchar> s1, Array<jchar> s2, int l1, int l2, int len,
                 Array<Array<Array<int>>> dp) {
    if ((len == 1)) {
      return (s1[l1] == s2[l2]);
    }
    if ((dp[l1][l2][len] != 0)) {
      return (dp[l1][l2][len] == 1);
    }
    bool ans = false;
    for (int k = 1; (k < len); (k++)) {
      if ((Code05_ScrambleString::f3(s1, s2, l1, l2, k, dp) &&
           Code05_ScrambleString::f3(s1, s2, (l1 + k), (l2 + k), (len - k),
                                     dp))) {
        (ans = true);
        break;
      }
    }
    if ((!ans)) {
      {
        int i = (l1 + 1);
        int j = ((l2 + len) - 1);
        int k = 1;
        for (; (k < len); (i++), (j--), (k++)) {
          if ((Code05_ScrambleString::f3(s1, s2, l1, j, k, dp) &&
               Code05_ScrambleString::f3(s1, s2, i, l2, (len - k), dp))) {
            (ans = true);
            break;
          }
        }
      }
    }
    (dp[l1][l2][len] = (ans ? 1 : (-1)));
    return ans;
  }
  static bool isScramble4(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    Array<Array<Array<bool>>> dp = make_array<bool>(n, n, (n + 1));
    for (int l1 = 0; (l1 < n); (l1++)) {
      for (int l2 = 0; (l2 < n); (l2++)) {
        (dp[l1][l2][1] = (s1[l1] == s2[l2]));
      }
    }
    for (int len = 2; (len <= n); (len++)) {
      for (int l1 = 0; (l1 <= (n - len)); (l1++)) {
        for (int l2 = 0; (l2 <= (n - len)); (l2++)) {
          for (int k = 1; (k < len); (k++)) {
            if ((dp[l1][l2][k] && dp[(l1 + k)][(l2 + k)][(len - k)])) {
              (dp[l1][l2][len] = true);
              break;
            }
          }
          if ((!dp[l1][l2][len])) {
            {
              int i = (l1 + 1);
              int j = ((l2 + len) - 1);
              int k = 1;
              for (; (k < len); (i++), (j--), (k++)) {
                if ((dp[l1][j][k] && dp[i][l2][(len - k)])) {
                  (dp[l1][l2][len] = true);
                  break;
                }
              }
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};

/* Original teaching comments:
// 扰乱字符串
// 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
// 步骤1 : 如果字符串的长度为 1 ，算法停止
// 步骤2 : 如果字符串的长度 > 1 ，执行下述步骤：
//        在一个随机下标处将字符串分割成两个非空的子字符串
//        已知字符串s，则可以将其分成两个子字符串x和y且满足s=x+y
//        可以决定是要 交换两个子字符串 还是要 保持这两个子字符串的顺序不变
//        即s可能是 s = x + y 或者 s = y + x
//        在x和y这两个子字符串上继续从步骤1开始递归执行此算法
// 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串
// 如果是，返回true ；否则，返回false
// 测试链接 : https://leetcode.cn/problems/scramble-string/
        // s1[l1....r1]
        // s2[l2....r2]
        // 保证l1....r1与l2....r2
        // 是不是扰乱串的关系
                        // s1[l1..r1]
                        // s2[l2..r2]
                // s1[l1..i][i+1....r1]
                // s2[l2..j][j+1....r2]
                // 不交错去讨论扰乱关系
                // 交错去讨论扰乱关系
                // s1[l1..........i][i+1...r1]
                // s2[l2...j-1][j..........r2]
        // 依然暴力尝试，只不过四个可变参数，变成了三个
                // s1[l1.......]  len
                // s2[l2.......]  len
                // 左 : k个   右: len - k 个
                // 交错！
                // dp[l1][l2][len] : int 0 -> 没展开过
                // dp[l1][l2][len] : int -1 -> 展开过，返回的结果是false
                // dp[l1][l2][len] : int 1 -> 展开过，返回的结果是true
                // 填写len=1层，所有的格子
                        // 注意如下的边界条件 : l1 <= n - len l2 <= n - len
*/
