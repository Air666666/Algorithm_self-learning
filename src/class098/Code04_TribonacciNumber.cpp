// Source: src/class098/Code04_TribonacciNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TribonacciNumber {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TribonacciNumber() {}
  static int tribonacci(int n) {
    if ((n == 0)) {
      return 0;
    }
    if ((n == 1)) {
      return 1;
    }
    if ((n == 2)) {
      return 1;
    }
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 1, 0}};
    Array<Array<int>> base = Array<Array<int>>{
        Array<int>{1, 1, 0}, Array<int>{1, 0, 1}, Array<int>{1, 0, 0}};
    Array<Array<int>> ans = Code04_TribonacciNumber::multiply(
        start, Code04_TribonacciNumber::power(base, (n - 2)));
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
        (ans = Code04_TribonacciNumber::multiply(ans, m));
      }
      (m = Code04_TribonacciNumber::multiply(m, m));
    }
    return ans;
  }
};

/* Original teaching comments:
// 第n个泰波那契数
// t(0) = 0, t(1) = 1, t(2) = 1
// t(i) = t(i-1) + t(i-2) + t(i-3)
// 求t(n)
// 测试链接 : https://leetcode.cn/problems/n-th-tribonacci-number/
// 这个测试的数据量太小，并且不牵扯取模的事情
// 所以矩阵快速幂看不出优势
        // 矩阵相乘
        // a的列数一定要等于b的行数
        // 矩阵快速幂
*/
