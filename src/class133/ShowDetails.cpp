// Source: src/class133/ShowDetails.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ShowDetails {
  inline static int MAXN = 101;
  inline static Array<Array<double>> mat = make_array<double>(MAXN, MAXN);
  inline static double sml = 1e-7;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ShowDetails() {}
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      int max = i;
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (std::abs(mat[j][j]) >= sml))) {
          continue;
        }
        if ([&]() {
              auto jleft = std::abs(mat[j][i]);
              auto jright = std::abs(mat[max][i]);
              return (jleft > jright);
            }()) {
          (max = j);
        }
      }
      ShowDetails::swap(i, max);
      if ((std::abs(mat[i][i]) >= sml)) {
        double tmp = mat[i][i];
        for (int j = i; (j <= (n + 1)); (j++)) {
          (mat[i][j] /= tmp);
        }
        for (int j = 1; (j <= n); (j++)) {
          if ((i != j)) {
            double rate = jdiv(mat[j][i], mat[i][i]);
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] -= (mat[i][k] * rate));
            }
          }
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<double> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void print(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= (n + 1)); (j++)) {
        jout.printf(String(u"%.2f  "), mat[i][j]);
      }
      jout.println();
    }
    jout.println(String(u"========================"));
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"唯一解"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 9);
    (mat[2][1] = 2);
    (mat[2][2] = (-1));
    (mat[2][3] = 2);
    (mat[2][4] = 7);
    (mat[3][1] = 1);
    (mat[3][2] = (-2));
    (mat[3][3] = 2);
    (mat[3][4] = 0);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"矛盾"));
    (mat[1][1] = 1);
    (mat[1][2] = 1);
    (mat[1][3] = 3);
    (mat[2][1] = 2);
    (mat[2][2] = 2);
    (mat[2][3] = 7);
    ShowDetails::gauss(2);
    ShowDetails::print(2);
    jout.println(String(u"多解"));
    (mat[1][1] = 1);
    (mat[1][2] = 1);
    (mat[1][3] = 3);
    (mat[2][1] = 2);
    (mat[2][2] = 2);
    (mat[2][3] = 6);
    ShowDetails::gauss(2);
    ShowDetails::print(2);
    jout.println(String(u"表达式冗余，唯一解"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 0);
    (mat[1][5] = 9);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = (-2));
    (mat[2][4] = 0);
    (mat[2][5] = 18);
    (mat[3][1] = 2);
    (mat[3][2] = (-1));
    (mat[3][3] = 2);
    (mat[3][4] = 0);
    (mat[3][5] = 7);
    (mat[4][1] = 1);
    (mat[4][2] = (-2));
    (mat[4][3] = 2);
    (mat[4][4] = 0);
    (mat[4][5] = 0);
    ShowDetails::gauss(4);
    ShowDetails::print(4);
    jout.println(String(u"表达式冗余，矛盾"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 0);
    (mat[1][5] = 9);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = (-2));
    (mat[2][4] = 0);
    (mat[2][5] = 18);
    (mat[3][1] = 2);
    (mat[3][2] = (-1));
    (mat[3][3] = 2);
    (mat[3][4] = 0);
    (mat[3][5] = 7);
    (mat[4][1] = 4);
    (mat[4][2] = (-2));
    (mat[4][3] = 4);
    (mat[4][4] = 0);
    (mat[4][5] = 10);
    ShowDetails::gauss(4);
    ShowDetails::print(4);
    jout.println(String(u"表达式冗余，多解"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 0);
    (mat[1][5] = 9);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = (-2));
    (mat[2][4] = 0);
    (mat[2][5] = 18);
    (mat[3][1] = 2);
    (mat[3][2] = (-1));
    (mat[3][3] = 2);
    (mat[3][4] = 0);
    (mat[3][5] = 7);
    (mat[4][1] = 4);
    (mat[4][2] = (-2));
    (mat[4][3] = 4);
    (mat[4][4] = 0);
    (mat[4][5] = 14);
    ShowDetails::gauss(4);
    ShowDetails::print(4);
    jout.println(String(u"表达式不足，矛盾"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 5);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = (-2));
    (mat[2][4] = 7);
    (mat[3][1] = 0);
    (mat[3][2] = 0);
    (mat[3][3] = 0);
    (mat[3][4] = 0);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"表达式不足，多解"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = (-1));
    (mat[1][4] = 5);
    (mat[2][1] = 2);
    (mat[2][2] = 2);
    (mat[2][3] = (-1));
    (mat[2][4] = 8);
    (mat[3][1] = 0);
    (mat[3][2] = 0);
    (mat[3][3] = 0);
    (mat[3][4] = 0);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"正确区分矛盾、多解、唯一解"));
    (mat[1][1] = 0);
    (mat[1][2] = 2);
    (mat[1][3] = 3);
    (mat[2][1] = 0);
    (mat[2][2] = 0);
    (mat[2][3] = 0);
    ShowDetails::gauss(2);
    ShowDetails::print(2);
    jout.println(String(u"有些主元可以确定值"));
    (mat[1][1] = 1);
    (mat[1][2] = 1);
    (mat[1][3] = 1);
    (mat[1][4] = 5);
    (mat[2][1] = 2);
    (mat[2][2] = 1);
    (mat[2][3] = 1);
    (mat[2][4] = 7);
    (mat[3][1] = 0);
    (mat[3][2] = 0);
    (mat[3][3] = 0);
    (mat[3][4] = 0);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"有些主元还受到自由元的影响"));
    (mat[1][1] = 1);
    (mat[1][2] = 1);
    (mat[1][3] = 5);
    (mat[2][1] = 0);
    (mat[2][2] = 0);
    (mat[2][3] = 0);
    ShowDetails::gauss(2);
    ShowDetails::print(2);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ShowDetails::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 课上讲述高斯消元解决加法方程组的例子
        // 0.0000001 == 1e-7
        // 因为double类型有精度问题，所以认为
        // 如果一个数字绝对值  <  sml，则认为该数字是0
        // 如果一个数字绝对值  >= sml，则认为该数字不是0
        // 高斯消元解决加法方程组模版
        // 需要保证变量有n个，表达式也有n个
                        // 如果想严格区分矛盾、多解、唯一解，一定要这么写
                // 唯一解
                // 1*x1 + 2*x2 - 1*x3 = 9
                // 2*x1 - 1*x2 + 2*x3 = 7
                // 1*x1 - 2*x2 + 2*x3 = 0
                // 矛盾
                // 1*x1 + 1*x2 = 3
                // 2*x1 + 2*x2 = 7
                // 多解
                // 1*x1 + 1*x2 = 3
                // 2*x1 + 2*x2 = 6
                // 表达式冗余，唯一解
                // 1*x1 + 2*x2 - 1*x3 + 0*x4 = 9
                // 2*x1 + 4*x2 - 2*x3 + 0*x4 = 18
                // 2*x1 - 1*x2 + 2*x3 + 0*x4 = 7
                // 1*x1 - 2*x2 + 2*x3 + 0*x4 = 0
                // 表达式冗余，矛盾
                // 1*x1 + 2*x2 - 1*x3 = 9
                // 2*x1 + 4*x2 - 2*x3 = 18
                // 2*x1 - 1*x2 + 2*x3 = 7
                // 4*x1 - 2*x2 + 4*x3 = 10
                // 表达式冗余，多解
                // 1*x1 + 2*x2 - 1*x3 = 9
                // 2*x1 + 4*x2 - 2*x3 = 18
                // 2*x1 - 1*x2 + 2*x3 = 7
                // 4*x1 - 2*x2 + 4*x3 = 14
                // 表达式不足，矛盾
                // 1*x1 + 2*x2 - 1*x3 = 5
                // 2*x1 + 4*x2 - 2*x3 = 7
                // 表达式不足，多解
                // 1*x1 + 2*x2 - 1*x3 = 5
                // 2*x1 + 2*x2 - 1*x3 = 8
                // 正确区分矛盾、多解、唯一解
                // 0*x1 + 2*x2 = 3
                // 0*x1 + 0*x2 = 0
                // 有些主元可以确定值
                // a  + b + c = 5
                // 2a + b + c = 7
                // 有些主元还受到自由元的影响
                // a + b = 5
*/
