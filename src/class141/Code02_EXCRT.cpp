// Source: src/class141/Code02_EXCRT.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_EXCRT {
  inline static int MAXN = 100001;
  inline static Array<i64> m = make_array<i64>(MAXN);
  inline static Array<i64> r = make_array<i64>(MAXN);
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_EXCRT() {}
  static i64 excrt(int n) {
    i64 tail = 0;
    i64 lcm = 1;
    i64 tmp = {};
    i64 b = {};
    i64 c = {};
    i64 x0 = {};
    for (int i = 1; (i <= n); (i++)) {
      (b = m[i]);
      (c = jrem((jrem((r[i] - tail), b) + b), b));
      Code02_EXCRT::exgcd(lcm, b);
      if ((jrem(c, d) != 0)) {
        return (-1);
      }
      (x0 = Code02_EXCRT::multiply(x, jdiv(c, d), jdiv(b, d)));
      (tmp = (lcm * jdiv(b, d)));
      (tail = jrem((tail + Code02_EXCRT::multiply(x0, lcm, tmp)), tmp));
      (lcm = tmp);
    }
    return tail;
  }
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code02_EXCRT::exgcd(b, jrem(a, b));
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
    out.println(Code02_EXCRT::excrt(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_EXCRT::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 扩展中国剩余定理模版
// 给出n个同余方程，求满足同余方程的最小正数解x
// 一共n个同余方程，x ≡ ri(% mi)
// 1 <= n <= 10^5
// 0 <= ri、mi <= 10^12
// 所有mi不一定互质
// 所有mi的最小公倍数 <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P4777
// 测试链接 : https://www.luogu.com.cn/problem/P1495
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 扩展中国剩余定理模版
                // ans = lcm * x + tail
                        // ans = m[i] * y + ri
                        // lcm * x + m[i] * y = ri - tail
                        // a = lcm
                        // b = m[i]
                        // c = ri - tail
                        // ax + by = gcd(a,b)，特解是，x变量
                        // ax + by = c，特解是，x变量 * (c/d)
                        // ax + by = c，最小非负特解x0 = (x * (c/d)) % (b/d)
取非负余数
                        // 通解 = x0 + (b/d) * n
                        // ans = lcm * x + tail，带入通解
                        // ans = lcm * (x0 + (b/d) * n) + tail
                        // ans = lcm * (b/d) * n + lcm * x0 + tail
                        // tail' = tail' % lcm'
        // 讲解139 - 扩展欧几里得算法
        // 讲解033 - 位运算实现乘法
        // a*b过程每一步都%mod，这么写是防止溢出，也叫龟速乘
*/
