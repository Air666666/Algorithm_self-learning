// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4035

// Source: src/class133/Code03_SphereCenter.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SphereCenter {
  inline static int MAXN = 12;
  inline static Array<Array<double>> data = make_array<double>(MAXN, MAXN);
  inline static Array<Array<double>> mat = make_array<double>(MAXN, MAXN);
  inline static int n = {};
  inline static double sml = 1e-7;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SphereCenter() {}
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
      Code03_SphereCenter::swap(i, max);
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
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= (n + 1)); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        in.nextToken();
        (data[i][j] = static_cast<double>(in.nval));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (mat[i][j] = (2 * (data[i][j] - data[(i + 1)][j])));
        (mat[i][(n + 1)] +=
         ((data[i][j] * data[i][j]) - (data[(i + 1)][j] * data[(i + 1)][j])));
      }
    }
    Code03_SphereCenter::gauss(n);
    for (int i = 1; (i <= n); (i++)) {
      out.printf(String(u"%.3f "), mat[i][(n + 1)]);
    }
    out.println();
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SphereCenter::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 球形空间的中心点
// 如果在n维空间中，那么表达一个点的位置，需要n个坐标的值
// 现在给定n+1个点，每个点都有n个坐标的值，代表在n维空间中的位置
// 假设这n+1个点都在n维空间的球面上，请返回球心的位置
// 球心的位置当然也是n个坐标的值，打印出来
// 在n维空间中，计算任意两点的距离，请用经典的欧式距离
// 1 <= n <= 10
// 坐标信息精确到小数点后6位，绝对值都不超过20000
// 测试链接 : https://www.luogu.com.cn/problem/P4035
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 高斯消元解决加法方程组模版
*/
