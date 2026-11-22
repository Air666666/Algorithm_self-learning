// Source: src/class098/Code02_BigShow.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BigShow {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BigShow() {}
  static void java_main(Array<String> args) {
    jout.println(String(u"f1() : "));
    jout.println(String(u"矩阵乘法展示开始"));
    Code02_BigShow::f1();
    jout.println(String(u"矩阵乘法展示结束"));
    jout.println();
    jout.println(String(u"f2() : "));
    jout.println(String(u"矩阵快速幂展示开始"));
    Code02_BigShow::f2();
    jout.println(String(u"矩阵快速幂展示结束"));
    jout.println();
    jout.println(String(u"f3() : "));
    jout.println(String(u"求斐波那契数列第n项"));
    jout.println(String(u"用矩阵乘法解决"));
    jout.println(String(u"展示开始"));
    Code02_BigShow::f3();
    jout.println(String(u"展示结束"));
    jout.println();
    jout.println(String(u"f4() : "));
    jout.println(String(u"求斐波那契数列第n项"));
    jout.println(String(u"用矩阵快速幂解决"));
    jout.println(String(u"展示开始"));
    Code02_BigShow::f4();
    jout.println(String(u"展示结束"));
    jout.println();
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
        (ans = Code02_BigShow::multiply(ans, m));
      }
      (m = Code02_BigShow::multiply(m, m));
    }
    return ans;
  }
  static void print(Array<Array<int>> m) {
    for (int i = 0; (i < m.length); (i++)) {
      for (int j = 0; (j < m[0].length); (j++)) {
        if ((m[i][j] < 10)) {
          jout.print((m[i][j] + String(u"   ")));
        } else if ((m[i][j] < 100)) {
          jout.print((m[i][j] + String(u"  ")));
        } else {
          jout.print((m[i][j] + String(u" ")));
        }
      }
      jout.println();
    }
  }
  static void f1() {
    Array<Array<int>> a = Array<Array<int>>{Array<int>{1, 3}, Array<int>{4, 2}};
    Array<Array<int>> b = Array<Array<int>>{Array<int>{2, 3}, Array<int>{3, 2}};
    Array<Array<int>> ans1 = Code02_BigShow::multiply(a, b);
    Code02_BigShow::print(ans1);
    jout.println(String(u"======"));
    Array<Array<int>> c = Array<Array<int>>{Array<int>{2, 4}, Array<int>{3, 2}};
    Array<Array<int>> d =
        Array<Array<int>>{Array<int>{2, 3, 2}, Array<int>{3, 2, 3}};
    Array<Array<int>> ans2 = Code02_BigShow::multiply(c, d);
    Code02_BigShow::print(ans2);
    jout.println(String(u"======"));
    Array<Array<int>> e =
        Array<Array<int>>{Array<int>{2, 4}, Array<int>{1, 2}, Array<int>{3, 1}};
    Array<Array<int>> f = Array<Array<int>>{Array<int>{2, 3}, Array<int>{4, 1}};
    Array<Array<int>> ans3 = Code02_BigShow::multiply(e, f);
    Code02_BigShow::print(ans3);
    jout.println(String(u"======"));
    Array<Array<int>> g = Array<Array<int>>{Array<int>{3, 1, 2}};
    Array<Array<int>> h = Array<Array<int>>{
        Array<int>{1, 2, 1}, Array<int>{3, 2, 1}, Array<int>{4, 2, (-2)}};
    Array<Array<int>> ans4 = Code02_BigShow::multiply(g, h);
    Code02_BigShow::print(ans4);
  }
  static void f2() {
    Array<Array<int>> a = Array<Array<int>>{Array<int>{1, 2}, Array<int>{3, 4}};
    Array<Array<int>> b = Code02_BigShow::multiply(
        a, Code02_BigShow::multiply(
               a, Code02_BigShow::multiply(a, Code02_BigShow::multiply(a, a))));
    Code02_BigShow::print(b);
    jout.println(String(u"======"));
    Code02_BigShow::print(Code02_BigShow::power(a, 5));
  }
  static void f3() {
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 0}};
    Array<Array<int>> m = Array<Array<int>>{Array<int>{1, 1}, Array<int>{1, 0}};
    Array<Array<int>> a = Code02_BigShow::multiply(start, m);
    Code02_BigShow::print(a);
    jout.println(String(u"======"));
    Array<Array<int>> b = Code02_BigShow::multiply(a, m);
    Code02_BigShow::print(b);
    jout.println(String(u"======"));
    Array<Array<int>> c = Code02_BigShow::multiply(b, m);
    Code02_BigShow::print(c);
    jout.println(String(u"======"));
    Array<Array<int>> d = Code02_BigShow::multiply(c, m);
    Code02_BigShow::print(d);
  }
  static void f4() {
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 0}};
    Array<Array<int>> m = Array<Array<int>>{Array<int>{1, 1}, Array<int>{1, 0}};
    Array<Array<int>> a =
        Code02_BigShow::multiply(start, Code02_BigShow::power(m, 1));
    Code02_BigShow::print(a);
    jout.println(String(u"======"));
    Array<Array<int>> b =
        Code02_BigShow::multiply(start, Code02_BigShow::power(m, 2));
    Code02_BigShow::print(b);
    jout.println(String(u"======"));
    Array<Array<int>> c =
        Code02_BigShow::multiply(start, Code02_BigShow::power(m, 3));
    Code02_BigShow::print(c);
    jout.println(String(u"======"));
    Array<Array<int>> d =
        Code02_BigShow::multiply(start, Code02_BigShow::power(m, 4));
    Code02_BigShow::print(d);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BigShow::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 矩阵乘法
// 矩阵快速幂
// 矩阵快速幂解决斐波那契第n项的问题
        // 矩阵相乘
        // a的列数一定要等于b的行数
        // 矩阵快速幂
        // 要求矩阵m是正方形矩阵
                // 对角线全是1、剩下数字都是0的正方形矩阵，称为单位矩阵
                // 相当于正方形矩阵中的1，矩阵a * 单位矩阵 = 矩阵a
        // 打印二维矩阵
        // 矩阵乘法的展示
                //        2  3
                //        3  2
                //
                // 1  3  11  9
                // 4  2  14 16
                //         2  3  2
                //         3  2  3
                //
                // 2  4   16 14 16
                // 3  2   12 13 12
                //          2  3
                //          4  1
                //
                // 2  4    20 10
                // 1  2    10  5
                // 3  1    10 10
                //           1  2  1
                //           3  2  1
                //           4  2 -2
                //
                // 3  1  2  14 12  0
        // 矩阵快速幂用法的展示
                // 只有正方形矩阵可以求幂
                // 连乘得到矩阵a的5次方
                // 矩阵快速幂得到矩阵a的5次方
        // 用矩阵乘法解决斐波那契第n项的问题
                // 0  1  1  2  3  5  8 13 21 34...
                // 0  1  2  3  4  5  6  7  8  9
                //       1  1
                //       1  0
                //
                // 1  0  1  1
                //       1  1
                //       1  0
                //
                // 1  1  2  1
                //       1  1
                //       1  0
                //
                // 2  1  3  2
                //       1  1
                //       1  0
                //
                // 3  2  5  3
        // 用矩阵快速幂解决斐波那契第n项的问题
                // 0  1  1  2  3  5  8 13 21 34...
                // 0  1  2  3  4  5  6  7  8  9
*/
