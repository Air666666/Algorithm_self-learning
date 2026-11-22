// Source: src/class098/Code02_FibonacciNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_FibonacciNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_FibonacciNumber() {}
  static int fib1(int n) {
    if ((n == 0)) {
      return 0;
    }
    if ((n == 1)) {
      return 1;
    }
    int lastLast = 0;
    int last = 1;
    {
      int i = 2;
      int cur = {};
      for (; (i <= n); (i++)) {
        (cur = (lastLast + last));
        (lastLast = last);
        (last = cur);
      }
    }
    return last;
  }
  static int fib2(int n) {
    if ((n == 0)) {
      return 0;
    }
    if ((n == 1)) {
      return 1;
    }
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 0}};
    Array<Array<int>> base =
        Array<Array<int>>{Array<int>{1, 1}, Array<int>{1, 0}};
    Array<Array<int>> ans = Code02_FibonacciNumber::multiply(
        start, Code02_FibonacciNumber::power(base, (n - 1)));
    return ans[0][0];
  }
  static Array<Array<int>> multiply(Array<Array<int>> a, Array<Array<int>> b) {
    int n = a.length;
    int m = b[0].length;
    int k = a[0].length;
    Array<Array<int>> ans = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int c = 0; (c < k); (c++)) {
          (ans[i][j] += (a[i][c] * b[c][j]));
        }
      }
    }
    return ans;
  }
  static Array<Array<int>> power(Array<Array<int>> m, int p) {
    int n = m.length;
    Array<Array<int>> ans = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i][i] = 1);
    }
    for (; (p != 0); (p = jshr(p, 1))) {
      if (((p & 1) != 0)) {
        (ans = Code02_FibonacciNumber::multiply(ans, m));
      }
      (m = Code02_FibonacciNumber::multiply(m, m));
    }
    return ans;
  }
};

/* Original teaching comments:
// 求斐波那契数列第n项
// 测试链接 : https://leetcode.cn/problems/fibonacci-number/
// 这个测试的数据量太小，并且不牵扯取模的事情
// 所以矩阵快速幂看不出优势
        // 时间复杂度O(n)，普通解法，讲解066，题目1
        // 时间复杂度O(logn)，矩阵快速幂的解法
        // 矩阵相乘
        // a的列数一定要等于b的行数
        // 矩阵快速幂
*/
