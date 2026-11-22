// Source: src/class141/Code03_GuessNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_GuessNumber {
  inline static int MAXN = 11;
  inline static Array<i64> m = make_array<i64>(MAXN);
  inline static Array<i64> r = make_array<i64>(MAXN);
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_GuessNumber() {}
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
      Code03_GuessNumber::exgcd(ai, m[i]);
      (ci = Code03_GuessNumber::multiply(
           r[i], Code03_GuessNumber::multiply(ai, x, lcm), lcm));
      (ans = jrem((ans + ci), lcm));
    }
    return ans;
  }
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
      Code03_GuessNumber::exgcd(lcm, b);
      if ((jrem(c, d) != 0)) {
        return (-1);
      }
      (x0 = Code03_GuessNumber::multiply(x, jdiv(c, d), jdiv(b, d)));
      (tmp = (lcm * jdiv(b, d)));
      (tail = jrem((tail + Code03_GuessNumber::multiply(x0, lcm, tmp)), tmp));
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
      Code03_GuessNumber::exgcd(b, jrem(a, b));
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
      (r[i] = static_cast<i64>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (m[i] = static_cast<i64>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      (r[i] = jrem((jrem(r[i], m[i]) + m[i]), m[i]));
    }
    out.println(Code03_GuessNumber::excrt(n));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_GuessNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 猜数字
// 给定两个长度为n数组，一组为r1，r2，r3...，另一组为m1，m2，m3...
// 其中第二组数字两两互质，求最小正数解x
// 要求x满足，mi | (x - ri)，即(x - ri)是mi的整数倍
// 1 <= n <= 10
// -10^9 <= ri <= +10^9
// 1 <= mi <= 6 * 10^3
// 所有mi的乘积 <= 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P3868
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 中国剩余定理模版
        // 扩展中国剩余定理模版
        // 讲解139 - 扩展欧几里得算法
        // 讲解033 - 位运算实现乘法
        // a*b过程每一步都%mod，这么写是防止溢出，也叫龟速乘
                // 题目输入的余数可能为负所以转化成非负数
                // out.println(crt(n)); // 中国剩余定理解决
*/
