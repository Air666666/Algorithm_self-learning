// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/climbing-stairs/

// Source: src/class098/Code03_ClimbingStairs.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ClimbingStairs {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ClimbingStairs() {}
  static int climbStairs(int n) {
    if ((n == 0)) {
      return 1;
    }
    if ((n == 1)) {
      return 1;
    }
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 1}};
    Array<Array<int>> base =
        Array<Array<int>>{Array<int>{1, 1}, Array<int>{1, 0}};
    Array<Array<int>> ans = Code03_ClimbingStairs::multiply(
        start, Code03_ClimbingStairs::power(base, (n - 1)));
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
        (ans = Code03_ClimbingStairs::multiply(ans, m));
      }
      (m = Code03_ClimbingStairs::multiply(m, m));
    }
    return ans;
  }
};

/* Original teaching comments:
// 爬楼梯
// 假设你正在爬楼梯，每次你可以爬1或2个台阶
// 你有多少种不同的方法可以爬到n层
// 测试链接 : https://leetcode.cn/problems/climbing-stairs/
// 这个测试的数据量太小，并且不牵扯取模的事情
// 所以矩阵快速幂看不出优势
        // 时间复杂度O(logn)，矩阵快速幂的解法
        // 矩阵相乘
        // a的列数一定要等于b的行数
        // 矩阵快速幂
*/
