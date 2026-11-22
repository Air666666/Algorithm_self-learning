// Source: src/class145/Code02_SetCounting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SetCounting {
  inline static int MAXN = 1000001;
  inline static int MOD = 1000000007;
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<i64> inv = make_array<i64>(MAXN);
  inline static Array<i64> g = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SetCounting() {}
  static void build() {
    (fac[0] = (inv[0] = 1));
    (fac[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv[n] = Code02_SetCounting::power(fac[n], (MOD - 2)));
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
  static i64 compute() {
    Code02_SetCounting::build();
    i64 tmp = 2;
    for (int i = n; (i >= 0); (i--)) {
      (g[i] = tmp);
      (tmp = jrem((tmp * tmp), MOD));
    }
    for (int i = 0; (i <= n); (i++)) {
      (g[i] = jrem((((g[i] + MOD) - 1) * Code02_SetCounting::c(n, i)), MOD));
    }
    i64 ans = 0;
    for (int i = k; (i <= n); (i++)) {
      if ((((i - k) & 1) == 0)) {
        (ans = jrem((ans + jrem((Code02_SetCounting::c(i, k) * g[i]), MOD)),
                    MOD));
      } else {
        (ans =
             jrem((ans + jrem((jrem((Code02_SetCounting::c(i, k) * g[i]), MOD) *
                               (MOD - 1)),
                              MOD)),
                  MOD));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    out.println(Code02_SetCounting::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_SetCounting::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 集合计数
// 一共有n个不同的数，能构成2^n个不同集合
// 在2^n个集合中挑出若干个集合，至少挑一个
// 希望这若干个集合的交集，正好有k个数
// 返回挑选集合的方案数，答案对 1000000007 取模
// 1 <= n <= 10^6
// 0 <= k <= n
// 测试链接 : https://www.luogu.com.cn/problem/P10596
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // -1 和 (MOD-1) 同余
                                // -1 和 (MOD-1) 同余
*/
