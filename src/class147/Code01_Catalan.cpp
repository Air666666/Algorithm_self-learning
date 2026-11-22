// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1044

// Source: src/class147/Code01_Catalan.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Catalan {
  inline static int MOD = 1000000007;
  inline static int MAXN = 1000001;
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<i64> inv1 = make_array<i64>(MAXN);
  inline static Array<i64> inv2 = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Catalan() {}
  static void build1(int n) {
    (fac[0] = (inv1[0] = 1));
    (fac[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv1[n] = Code01_Catalan::power(fac[n], (MOD - 2)));
    for (int i = (n - 1); (i >= 1); (i--)) {
      (inv1[i] = jrem((static_cast<i64>((i + 1)) * inv1[(i + 1)]), MOD));
    }
  }
  static void build2(int n) {
    (inv2[1] = 1);
    for (int i = 2; (i <= (n + 1)); (i++)) {
      (inv2[i] = (MOD - jrem((inv2[jrem(MOD, i)] * jdiv(MOD, i)), MOD)));
    }
  }
  static i64 power(i64 x, i64 p) {
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
  static i64 c(int n, int k) {
    return jrem((jrem((fac[n] * inv1[k]), MOD) * inv1[(n - k)]), MOD);
  }
  static i64 compute1(int n) {
    Code01_Catalan::build1((2 * n));
    return jrem(([&]() {
                  auto jleft = Code01_Catalan::c((2 * n), n);
                  auto jright = Code01_Catalan::c((2 * n), (n - 1));
                  return (jleft - jright);
                }() +
                 MOD),
                MOD);
  }
  static i64 compute2(int n) {
    Code01_Catalan::build1((2 * n));
    return jrem(
        [&]() {
          auto jleft = Code01_Catalan::c((2 * n), n);
          auto jright = Code01_Catalan::power((n + 1), (MOD - 2));
          return (jleft * jright);
        }(),
        MOD);
  }
  static i64 compute3(int n) {
    Code01_Catalan::build2(n);
    Array<i64> f = make_array<i64>((n + 1));
    (f[0] = (f[1] = 1));
    for (int i = 2; (i <= n); (i++)) {
      (f[i] = jrem((jrem((f[(i - 1)] * ((4 * i) - 2)), MOD) * inv2[(i + 1)]),
                   MOD));
    }
    return f[n];
  }
  static i64 compute4(int n) {
    Array<i64> f = make_array<i64>((n + 1));
    (f[0] = (f[1] = 1));
    for (int i = 2; (i <= n); (i++)) {
      {
        int l = 0;
        int r = (i - 1);
        for (; (l < i); (l++), (r--)) {
          (f[i] = jrem((f[i] + jrem((f[l] * f[r]), MOD)), MOD));
        }
      }
    }
    return f[n];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    out.println(Code01_Catalan::compute1(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Catalan::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 卡特兰数模版
// 进栈顺序规定为1、2、3..n，返回有多少种不同的出栈顺序
// 测试题目的数据量很小，得到的卡特兰数没有多大，不需要取模处理
// 但是请假设，当n比较大时，卡特兰数是很大的，答案对 1000000007 取模
// 测试链接 : https://www.luogu.com.cn/problem/P1044
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 阶乘余数表
        // 阶乘逆元表
        // 连续数逆元表
        // 来自讲解099，题目3，生成阶乘余数表、阶乘逆元表
        // 来自讲解099，题目2，生成连续数逆元表
        // 公式1
        // 公式2
        // 公式3
        // 公式4
//		out.println(compute2(n));
//		out.println(compute3(n));
//		out.println(compute4(n));
*/
