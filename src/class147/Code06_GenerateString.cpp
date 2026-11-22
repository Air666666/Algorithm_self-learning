// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1641

// Source: src/class147/Code06_GenerateString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_GenerateString {
  inline static int MOD = 20100403;
  inline static int MAXN = 2000001;
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<i64> inv = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_GenerateString() {}
  static void build(int n) {
    (fac[0] = (inv[0] = 1));
    (fac[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv[n] = Code06_GenerateString::power(fac[n], (MOD - 2)));
    for (int i = (n - 1); (i >= 1); (i--)) {
      (inv[i] = jrem((static_cast<i64>((i + 1)) * inv[(i + 1)]), MOD));
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
    return jrem((jrem((fac[n] * inv[k]), MOD) * inv[(n - k)]), MOD);
  }
  static i64 compute(int n, int m) {
    Code06_GenerateString::build((n + m));
    return jrem(([&]() {
                  auto jleft = Code06_GenerateString::c((n + m), m);
                  auto jright = Code06_GenerateString::c((n + m), (m - 1));
                  return (jleft - jright);
                }() +
                 MOD),
                MOD);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    out.println(Code06_GenerateString::compute(n, m));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_GenerateString::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 生成字符串
// 有n个1和m个0，要组成n+m长度的数列，保证任意前缀上，1的数量 >= 0的数量
// 返回有多少种排列方法，答案对 20100403 取模
// 1 <= m <= n <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P1641
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
