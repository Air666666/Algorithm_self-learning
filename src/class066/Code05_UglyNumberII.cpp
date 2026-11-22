// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/ugly-number-ii/

// Source: src/class066/Code05_UglyNumberII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_UglyNumberII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_UglyNumberII() {}
  static int nthUglyNumber(int n) {
    Array<int> dp = make_array<int>((n + 1));
    (dp[1] = 1);
    {
      int i = 2;
      int i2 = 1;
      int i3 = 1;
      int i5 = 1;
      int a = {};
      int b = {};
      int c = {};
      int cur = {};
      for (; (i <= n); (i++)) {
        (a = (dp[i2] * 2));
        (b = (dp[i3] * 3));
        (c = (dp[i5] * 5));
        (cur = jmin(jmin(a, b), c));
        if ((cur == a)) {
          (i2++);
        }
        if ((cur == b)) {
          (i3++);
        }
        if ((cur == c)) {
          (i5++);
        }
        (dp[i] = cur);
      }
    }
    return dp[n];
  }
};

/* Original teaching comments:
// 丑数 II
// 给你一个整数 n ，请你找出并返回第 n 个 丑数
// 丑数 就是只包含质因数 2、3 或 5 的正整数
// 测试链接 : https://leetcode.cn/problems/ugly-number-ii/
        // 时间复杂度O(n)，n代表第n个丑数
                // dp 0 1 2 ...  n
                //      1 2 ...  ?
*/
