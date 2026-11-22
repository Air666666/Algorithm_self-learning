// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/domino-and-tromino-tiling/

// Source: src/class098/Code05_DominoTromino.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_DominoTromino {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_DominoTromino() {}
  static void java_main(Array<String> args) {
    for (int i = 1; (i <= 9); (i++)) {
      jout.println((((String(u"铺满 2 * ") + i) + String(u" 的区域方法数 : ")) +
                    Code05_DominoTromino::f(i, 0)));
    }
  }
  static int f(int n, int h) {
    if ((n == 0)) {
      return ((h == 0) ? 1 : 0);
    }
    if ((n == 1)) {
      return 1;
    }
    if ((h == 1)) {
      return [&]() {
        auto jleft = Code05_DominoTromino::f((n - 1), 0);
        auto jright = Code05_DominoTromino::f((n - 1), 1);
        return (jleft + jright);
      }();
    } else {
      return [&]() {
        auto jleft = [&]() {
          auto jleft = Code05_DominoTromino::f((n - 1), 0);
          auto jright = Code05_DominoTromino::f((n - 2), 0);
          return (jleft + jright);
        }();
        auto jright = (2 * Code05_DominoTromino::f((n - 2), 1));
        return (jleft + jright);
      }();
    }
  }
  static int numTilings(int n) { return Code05_DominoTromino::f2((n - 1)); }
  static int f2(int n) {
    if ((n == 0)) {
      return 1;
    }
    if ((n == 1)) {
      return 2;
    }
    if ((n == 2)) {
      return 5;
    }
    Array<Array<int>> start = Array<Array<int>>{Array<int>{5, 2, 1}};
    Array<Array<int>> base = Array<Array<int>>{
        Array<int>{2, 1, 0}, Array<int>{0, 0, 1}, Array<int>{1, 0, 0}};
    Array<Array<int>> ans = Code05_DominoTromino::multiply(
        start, Code05_DominoTromino::power(base, (n - 2)));
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
          (ans[i][j] = static_cast<int>(
               jrem(((static_cast<i64>(a[i][c]) * b[c][j]) + ans[i][j]), MOD)));
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
        (ans = Code05_DominoTromino::multiply(ans, m));
      }
      (m = Code05_DominoTromino::multiply(m, m));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_DominoTromino::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 多米诺和托米诺平铺
// 有两种形状的瓷砖，一种是2*1的多米诺形，另一种是形如"L"的托米诺形
// 两种形状都可以旋转，给定整数n，返回可以平铺2*n的面板的方法数量
// 返回对1000000007取模的值
// 测试链接 : https://leetcode.cn/problems/domino-and-tromino-tiling/
        // f(1) = 1
        // f(2) = 2
        // f(3) = 5
        // f(4) = 11
        // f(n) = 2 * f(n-1) + f(n-3)
        // 打表或者公式化简都可以发现规律，这里推荐打表找规律
        // 暴力方法
        // 为了找规律
        // 如果h==0，返回2*n的区域铺满的方法数
        // 如果h==1，返回1 + 2*n的区域铺满的方法数
        // 正式方法
        // 矩阵快速幂
        // 时间复杂度O(logn)
        // 矩阵相乘 + 乘法取模
        // a的列数一定要等于b的行数
        // 矩阵快速幂
*/
