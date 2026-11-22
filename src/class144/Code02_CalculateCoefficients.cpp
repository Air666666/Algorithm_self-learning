// Source: src/class144/Code02_CalculateCoefficients.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CalculateCoefficients {
  inline static int MAXK = 1001;
  inline static int MOD = 10007;
  inline static Array<i64> fac = make_array<i64>((MAXK + 1));
  inline static Array<i64> inv = make_array<i64>((MAXK + 1));
  inline static int a = {};
  inline static int b = {};
  inline static int k = {};
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CalculateCoefficients() {}
  static i64 power(i64 x, int p) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (p = jshr(p, 1));
    }
    return ans;
  }
  static void build() {
    (fac[1] = 1);
    for (int i = 2; (i <= MAXK); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv[MAXK] = Code02_CalculateCoefficients::power(fac[MAXK], (MOD - 2)));
    for (int i = (MAXK - 1); (i >= 0); (i--)) {
      (inv[i] = jrem((static_cast<i64>((i + 1)) * inv[(i + 1)]), MOD));
    }
  }
  static i64 c(int n, int k) {
    return jrem((jrem((fac[n] * inv[k]), MOD) * inv[(n - k)]), MOD);
  }
  static i64 compute() {
    Code02_CalculateCoefficients::build();
    return jrem(
        [&]() {
          auto jleft = jrem(
              [&]() {
                auto jleft = Code02_CalculateCoefficients::power(a, n);
                auto jright = Code02_CalculateCoefficients::power(b, m);
                return (jleft * jright);
              }(),
              MOD);
          auto jright = Code02_CalculateCoefficients::c(k, (k - n));
          return (jleft * jright);
        }(),
        MOD);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (a = static_cast<int>(in.nval));
    in.nextToken();
    (b = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    out.println(Code02_CalculateCoefficients::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CalculateCoefficients::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 计算系数
// 多项式为，(ax + by)的k次方，其中a、b、k为常数
// 计算这个多项式展开后，x的n次方 * y的m次方，这一项的系数
// 0 <= k <= 1000
// 0 <= a、b <= 10^6
// n + m == k
// 测试链接 : https://www.luogu.com.cn/problem/P1313
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // fac[i]代表 i! 在 %MOD 意义下的余数
        // inv[i]代表 i! 在 %MOD 意义下的逆元
        // 来自讲解098，乘法快速幂，x的p次方 % MOD
        // 来自讲解099，生成阶乘表和逆元表
                // 阶乘表线性递推
                // 逆元表线性递推
        // 组合公式
*/
