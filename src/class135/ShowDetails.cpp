// Source: src/class135/ShowDetails.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ShowDetails {
  inline static int MOD = 7;
  inline static int MAXN = 101;
  inline static Array<Array<int>> mat = make_array<int>(MAXN, MAXN);
  inline static Array<int> inv = make_array<int>(MOD);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ShowDetails() {}
  static void inv_method() {
    (inv[1] = 1);
    for (int i = 2; (i < MOD); (i++)) {
      (inv[i] = static_cast<int>(
           (MOD -
            jrem((static_cast<i64>(inv[jrem(MOD, i)]) * jdiv(MOD, i)), MOD))));
    }
  }
  static int gcd(int a, int b) {
    return ((b == 0) ? a : ShowDetails::gcd(b, jrem(a, b)));
  }
  static void gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        if (((j < i) && (mat[j][j] != 0))) {
          continue;
        }
        if ((mat[j][i] != 0)) {
          ShowDetails::swap(i, j);
          break;
        }
      }
      if ((mat[i][i] != 0)) {
        for (int j = 1; (j <= n); (j++)) {
          if (((i != j) && (mat[j][i] != 0))) {
            int gcd = ShowDetails::gcd(mat[j][i], mat[i][i]);
            int a = jdiv(mat[i][i], gcd);
            int b = jdiv(mat[j][i], gcd);
            if (((j < i) && (mat[j][j] != 0))) {
              for (int k = j; (k < i); (k++)) {
                (mat[j][k] = jrem((mat[j][k] * a), MOD));
              }
            }
            for (int k = i; (k <= (n + 1)); (k++)) {
              (mat[j][k] =
                   jrem((jrem(((mat[j][k] * a) - (mat[i][k] * b)), MOD) + MOD),
                        MOD));
            }
          }
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((mat[i][i] != 0)) {
        bool flag = false;
        for (int j = (i + 1); (j <= n); (j++)) {
          if ((mat[i][j] != 0)) {
            (flag = true);
            break;
          }
        }
        if ((!flag)) {
          (mat[i][(n + 1)] = jrem((mat[i][(n + 1)] * inv[mat[i][i]]), MOD));
          (mat[i][i] = 1);
        }
      }
    }
  }
  static void swap(int a, int b) {
    Array<int> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void print(int n) {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= (n + 1)); (j++)) {
        jout.print((mat[i][j] + String(u" ")));
      }
      jout.println();
    }
    jout.println(String(u"========================"));
  }
  static void java_main(Array<String> args) {
    ShowDetails::inv_method();
    jout.println(String(u"课上图解的例子，唯一解"));
    (mat[1][1] = 4);
    (mat[1][2] = 2);
    (mat[1][3] = 4);
    (mat[1][4] = 3);
    (mat[2][1] = 2);
    (mat[2][2] = 5);
    (mat[2][3] = 2);
    (mat[2][4] = 2);
    (mat[3][1] = 6);
    (mat[3][2] = 3);
    (mat[3][3] = 4);
    (mat[3][4] = 5);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"表达式存在矛盾的例子"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = 3);
    (mat[1][4] = 2);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = 6);
    (mat[2][4] = 5);
    (mat[3][1] = 0);
    (mat[3][2] = 3);
    (mat[3][3] = 4);
    (mat[3][4] = 2);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"课上图解的例子，多解"));
    jout.println(String(u"只有确定了自由元，才能确定主元的值"));
    jout.println(String(u"如果是多解的情况，那么在消元结束后"));
    jout.println(String(u"二维矩阵中主元和自由元的关系是正确的"));
    jout.println(String(u"课上也进行了验证"));
    (mat[1][1] = 1);
    (mat[1][2] = 2);
    (mat[1][3] = 3);
    (mat[1][4] = 2);
    (mat[2][1] = 2);
    (mat[2][2] = 4);
    (mat[2][3] = 6);
    (mat[2][4] = 4);
    (mat[3][1] = 0);
    (mat[3][2] = 3);
    (mat[3][3] = 4);
    (mat[3][4] = 2);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"注意下面这个多解的例子"));
    (mat[1][1] = 1);
    (mat[1][2] = 1);
    (mat[1][3] = 1);
    (mat[1][4] = 3);
    (mat[2][1] = 2);
    (mat[2][2] = 1);
    (mat[2][3] = 1);
    (mat[2][4] = 5);
    (mat[3][1] = 0);
    (mat[3][2] = 3);
    (mat[3][3] = 3);
    (mat[3][4] = 3);
    ShowDetails::gauss(3);
    ShowDetails::print(3);
    jout.println(String(u"最后一个例子里"));
    jout.println(String(u"主元x1，不受其他自由元影响，值可以直接确定"));
    jout.println(String(u"但是主元x2，受到自由元x3的影响，6*x2 + 6*x3 同余 6"));
    jout.println(String(u"只有自由元x3确定了值，主元x2的值才能确定"));
    jout.println(String(u"本节课提供的模版，对于能求出的主元可以得到正确结果"));
    jout.println(
        String(u"对于不能求出的主元，该模版也能给出，主元和自由元的正确关系"));
    jout.println(
        String(u"有些题目需要这种多解情况下，主元和自由元之间的正确关系"));
    jout.println(String(u"绝大多数模版和讲解都没有考虑这个，但值得引起重视"));
    jout.println(String(u"如果有些题目不需要这种正确关系"));
    jout.println(
        String(u"那么逻辑可以化简，让常数时间更快，比如本节课的题目1"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ShowDetails::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 课上讲述高斯消元解决同余方程组的例子
        // 题目会保证取模的数字为质数
        // 逆元线性递推公式求逆元表，讲解099 - 除法同余
        // 求a和b的最大公约数，保证a和b都不等于0
        // 高斯消元解决同余方程组模版，保证初始系数没有负数
        // ((系数 % MOD) + MOD) % MOD
                                // 已经成为主元的行不参与
                                // 找到系数不等于0的行做主元即可
                                                        //
如果j行有主元，那么从j列到i-1列的所有系数 * a
                                                        //
正确更新主元和自由元之间的关系
                                                // 正常消元
                                // 检查当前主元是否被若干自由元影响
                                //
如果当前主元不受自由元影响，那么可以确定当前主元的值
                                // 否则保留这种影响，正确显示主元和自由元的关系
                                        // 本来应该是，mat[i][n + 1] = mat[i][n
+ 1] / mat[i][i]
                                        // 但是在模意义下应该求逆元，(a / b) %
MOD = (a * b的逆元) % MOD
                                        // 如果不会，去看讲解099 - 除法同余
                // 逆元表建立好
                // 4*x1 + 2*x2 + 4*x3 同余 3
                // 2*x1 + 5*x2 + 2*x3 同余 2
                // 6*x1 + 3*x2 + 4*x3 同余 5
                // 1*x1 + 2*x2 + 3*x3 同余 2
                // 2*x1 + 4*x2 + 6*x3 同余 5
                // 0*x1 + 3*x2 + 4*x3 同余 2
                // 1*x1 + 2*x2 + 3*x3 同余 2
                // 2*x1 + 4*x2 + 6*x3 同余 4
                // 0*x1 + 3*x2 + 4*x3 同余 2
                // 1*x1 + 1*x2 + 1*x3 同余 3
                // 2*x1 + 1*x2 + 1*x3 同余 5
                // 0*x1 + 3*x2 + 3*x3 同余 3
*/
