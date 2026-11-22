// Source: src/class141/Code01_CRT.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CRT {
  inline static int MAXN = 11;
  inline static Array<i64> m = make_array<i64>(MAXN);
  inline static Array<i64> r = make_array<i64>(MAXN);
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CRT() {}
  static i64 crt(int n) {
    i64 lcm = 1;
    for (int i = 1; (i <= n); (i++)) {
      (lcm = (lcm * m[i]));
    }
    i64 ai = {};
    i64 ci = {};
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ai = jdiv(lcm, m[i]));
      Code01_CRT::exgcd(ai, m[i]);
      (ci = Code01_CRT::multiply(r[i], Code01_CRT::multiply(ai, x, lcm), lcm));
      (ans = jrem((ans + ci), lcm));
    }
    return ans;
  }
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code01_CRT::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static i64 multiply(i64 a, i64 b, i64 mod) {
    (a = jrem((jrem(a, mod) + mod), mod));
    (b = jrem((jrem(b, mod) + mod), mod));
    i64 ans = 0;
    while ((b != 0)) {
      if (((b & 1) != 0)) {
        (ans = jrem((ans + a), mod));
      }
      (a = jrem((a + a), mod));
      (b = jshr(b, 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (m[i] = static_cast<i64>(in.nval));
      in.nextToken();
      (r[i] = static_cast<i64>(in.nval));
    }
    out.println(Code01_CRT::crt(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CRT::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 中国剩余定理模版
// 给出n个同余方程，求满足同余方程的最小正数解x
// 一共n个同余方程，x ≡ ri(% mi)
// 1 <= n <= 10
// 0 <= ri、mi <= 10^5
// 所有mi一定互质
// 所有mi整体乘积 <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P1495
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 中国剩余定理模版
                        // ai = lcm / m[i]
                        // ai逆元，在%m[i]意义下的逆元
                        // ci = (ri * ai * ai逆元) % lcm
        // 讲解139 - 扩展欧几里得算法
        // 讲解033 - 位运算实现乘法
        // a*b过程每一步都%mod，这么写是防止溢出，也叫龟速乘
*/
