// Source: src/class099/Code03_InverseFactorial.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_InverseFactorial {
  inline static int MOD = 1000000007;
  inline static int LIMIT = 1000;
  inline static Array<i64> fac = make_array<i64>((LIMIT + 1));
  inline static Array<i64> inv = make_array<i64>((LIMIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_InverseFactorial() {}
  static void build() {
    (fac[1] = 1);
    for (int i = 2; (i <= LIMIT); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv[LIMIT] = Code03_InverseFactorial::power(fac[LIMIT], (MOD - 2)));
    for (int i = (LIMIT - 1); (i >= 0); (i--)) {
      (inv[i] = jrem((static_cast<i64>((i + 1)) * inv[(i + 1)]), MOD));
    }
  }
  static i64 power(i64 x, int n) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * x), MOD));
      }
      (x = jrem((x * x), MOD));
      (n = jshr(n, 1));
    }
    return ans;
  }
  static int c1(int n, int m) {
    BigInteger a = BigInteger(String(u"1"));
    BigInteger b = BigInteger(String(u"1"));
    BigInteger c = BigInteger(String(u"1"));
    for (int i = 1; (i <= n); (i++)) {
      String cur = j::str(i);
      (a = a.multiply(BigInteger(cur)));
      if ((i <= m)) {
        (b = b.multiply(BigInteger(cur)));
      }
      if ((i <= (n - m))) {
        (c = c.multiply(BigInteger(cur)));
      }
    }
    BigInteger ans = a.divide(b.multiply(c)).mod(BigInteger(j::str(MOD)));
    return ans.intValue();
  }
  static int c2(int n, int m) {
    i64 ans = fac[n];
    (ans = jrem((ans * inv[m]), MOD));
    (ans = jrem((ans * inv[(n - m)]), MOD));
    return static_cast<int>(ans);
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    Code03_InverseFactorial::build();
    int n = 500;
    for (int m = 0; (m <= n); (m++)) {
      int ans1 = Code03_InverseFactorial::c1(n, m);
      int ans2 = Code03_InverseFactorial::c2(n, m);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
    int a = 537;
    int b = 367;
    jout.println((((((String(u"计算 C ( ") + a) + String(u" , ")) + b) +
                   String(u" ) % ")) +
                  MOD));
    jout.println((String(u"方法1答案 : ") + Code03_InverseFactorial::c1(a, b)));
    jout.println((String(u"方法2答案 : ") + Code03_InverseFactorial::c2(a, b)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_InverseFactorial::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 连续阶乘逆元的线性递推
// 实现组合公式C(n,m)的计算
// 最终结果 % 1000000007后返回
// 0 <= m <= n <= 1000
// 对数器验证
        // 阶乘表
        // fac[i]代表 i! 在 %MOD 意义下的余数
        // 阶乘结果的逆元表
        // inv[i]代表i! 在 %MOD 意义下的逆元(1 / i!)
                // 单个阶乘的逆元
//		inv[0] = 1;
//		for (int i = 1; i <= LIMIT; i++) {
//			inv[i] = power(fac[i], MOD - 2);
//		}
                // 利用线性递推优化
        // 组合公式
        // 得到的结果 % MOD
        // BigInteger保证中间计算结果完全正确
        // 组合公式
        // 得到的结果 % MOD
        // 阶乘结果逆元表的线性递推
                // 要保证 n <= LIMIT
                // 要保证 b <= a <= LIMIT
*/
