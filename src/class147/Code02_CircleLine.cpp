// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1976

// Source: src/class147/Code02_CircleLine.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CircleLine {
  inline static int MOD = 100000007;
  inline static int MAXN = 1000001;
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<i64> inv = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CircleLine() {}
  static void build(int n) {
    (fac[0] = (inv[0] = 1));
    (fac[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (fac[i] = jrem((static_cast<i64>(i) * fac[(i - 1)]), MOD));
    }
    (inv[n] = Code02_CircleLine::power(fac[n], (MOD - 2)));
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
  static i64 compute(int n) {
    Code02_CircleLine::build((2 * n));
    return jrem(([&]() {
                  auto jleft = Code02_CircleLine::c((2 * n), n);
                  auto jright = Code02_CircleLine::c((2 * n), (n - 1));
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
    out.println(Code02_CircleLine::compute(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CircleLine::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 圆上连线
//
圆上有2n个点，这些点成对连接起来，形成n条线段，任意两条线段不能相交，返回连接的方法数
// 注意！答案不对 10^9 + 7 取模！而是对 10^8 + 7 取模！
// 1 <= n <= 2999
// 测试链接 : https://www.luogu.com.cn/problem/P1976
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 这里用公式1
*/
