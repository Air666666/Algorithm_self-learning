// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3389

// Source: src/class133/Code01_GaussAdd.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GaussAdd {
  inline static int MAXN = 102;
  inline static Array<Array<double>> mat = make_array<double>(MAXN, MAXN);
  inline static int n = {};
  inline static double sml = 1e-7;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GaussAdd() {}
  static int gauss(int n) {
    for (int i = 1; (i <= n); (i++)) {
      int max = i;
      for (int j = (i + 1); (j <= n); (j++)) {
        if ([&]() {
              auto jleft = std::abs(mat[j][i]);
              auto jright = std::abs(mat[max][i]);
              return (jleft > jright);
            }()) {
          (max = j);
        }
      }
      Code01_GaussAdd::swap(i, max);
      if ((std::abs(mat[i][i]) < sml)) {
        return 0;
      }
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
    return 1;
  }
  static void swap(int a, int b) {
    Array<double> tmp = mat[a];
    (mat[a] = mat[b]);
    (mat[b] = tmp);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= (n + 1)); (j++)) {
        in.nextToken();
        (mat[i][j] = static_cast<double>(in.nval));
      }
    }
    int sign = Code01_GaussAdd::gauss(n);
    if ((sign == 0)) {
      out.println(String(u"No Solution"));
    } else {
      for (int i = 1; (i <= n); (i++)) {
        out.printf(String(u"%.2f\n"), mat[i][(n + 1)]);
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_GaussAdd::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 高斯消元解决加法方程组模版(区分是否有唯一解)
// 一共有n个变量，给定n个加法方程，构成一个加法方程组
// 如果方程组存在矛盾或者无法确定唯一解，打印"No Solution"
// 如果方程组存在唯一解，打印每个变量的值，保留小数点后两位
// 1 <= n <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P3389
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 0.0000001 == 1e-7
        // 因为double类型有精度问题，所以认为
        // 如果一个数字绝对值 <  sml，则认为该数字是0
        // 如果一个数字绝对值 >= sml，则认为该数字不是0
        // 需要保证变量有n个，表达式也有n个
                        // 本题一旦没有唯一解，直接打印"No
Solution"，于是可以这么写
*/
