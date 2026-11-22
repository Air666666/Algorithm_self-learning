// Source: src/class068/Code02_EditDistance.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_EditDistance {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_EditDistance() {}
  int minDistance(String word1, String word2) {
    return Code02_EditDistance::editDistance2(word1, word2, 1, 1, 1);
  }
  static int editDistance1(String str1, String str2, int a, int b, int c) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 1; (i <= n); (i++)) {
      (dp[i][0] = (i * b));
    }
    for (int j = 1; (j <= m); (j++)) {
      (dp[0][j] = (j * a));
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        int p1 = std::numeric_limits<int>::max();
        if ((s1[(i - 1)] == s2[(j - 1)])) {
          (p1 = dp[(i - 1)][(j - 1)]);
        }
        int p2 = std::numeric_limits<int>::max();
        if ((s1[(i - 1)] != s2[(j - 1)])) {
          (p2 = (dp[(i - 1)][(j - 1)] + c));
        }
        int p3 = (dp[i][(j - 1)] + a);
        int p4 = (dp[(i - 1)][j] + b);
        (dp[i][j] = [&]() {
          auto jargument_0 = jmin(p1, p2);
          auto jargument_1 = jmin(p3, p4);
          return jmin(jargument_0, jargument_1);
        }());
      }
    }
    return dp[n][m];
  }
  static int editDistance2(String str1, String str2, int a, int b, int c) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 1; (i <= n); (i++)) {
      (dp[i][0] = (i * b));
    }
    for (int j = 1; (j <= m); (j++)) {
      (dp[0][j] = (j * a));
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        if ((s1[(i - 1)] == s2[(j - 1)])) {
          (dp[i][j] = dp[(i - 1)][(j - 1)]);
        } else {
          (dp[i][j] = jmin(jmin((dp[(i - 1)][j] + b), (dp[i][(j - 1)] + a)),
                           (dp[(i - 1)][(j - 1)] + c)));
        }
      }
    }
    return dp[n][m];
  }
  static int editDistance3(String str1, String str2, int a, int b, int c) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<int> dp = make_array<int>((m + 1));
    for (int j = 1; (j <= m); (j++)) {
      (dp[j] = (j * a));
    }
    {
      int i = 1;
      int leftUp = {};
      int backUp = {};
      for (; (i <= n); (i++)) {
        (leftUp = ((i - 1) * b));
        (dp[0] = (i * b));
        for (int j = 1; (j <= m); (j++)) {
          (backUp = dp[j]);
          if ((s1[(i - 1)] == s2[(j - 1)])) {
            (dp[j] = leftUp);
          } else {
            (dp[j] = jmin(jmin((dp[j] + b), (dp[(j - 1)] + a)), (leftUp + c)));
          }
          (leftUp = backUp);
        }
      }
    }
    return dp[m];
  }
};

/* Original teaching comments:
// 编辑距离
// 给你两个单词 word1 和 word2
// 请返回将 word1 转换成 word2 所使用的最少代价
// 你可以对一个单词进行如下三种操作：
// 插入一个字符，代价a
// 删除一个字符，代价b
// 替换一个字符，代价c
// 测试链接 : https://leetcode.cn/problems/edit-distance/
        // 已经展示太多次从递归到动态规划了
        // 直接写动态规划吧
        // 原初尝试版
        // a : str1中插入1个字符的代价
        // b : str1中删除1个字符的代价
        // c : str1中改变1个字符的代价
        // 返回从str1转化成str2的最低代价
                // dp[i][j] :
                // s1[前缀长度为i]想变成s2[前缀长度为j]，至少付出多少代价
        // 枚举小优化版
        // a : str1中插入1个字符的代价
        // b : str1中删除1个字符的代价
        // c : str1中改变1个字符的代价
        // 返回从str1转化成str2的最低代价
                // dp[i][j] :
                // s1[前缀长度为i]想变成s2[前缀长度为j]，至少付出多少代价
        // 空间压缩
*/
