// Source: src/class139/Exgcd.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Exgcd {
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Exgcd() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Exgcd::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static i64 fermat(i64 num, i64 mod) {
    return Exgcd::power(num, (mod - 2), mod);
  }
  static i64 power(i64 num, i64 pow, i64 mod) {
    i64 ans = 1;
    while ((pow > 0)) {
      if (((pow & 1) == 1)) {
        (ans = jrem((ans * num), mod));
      }
      (num = jrem((num * num), mod));
      (pow = jshr(pow, 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int a = 220;
    int b = 170;
    Exgcd::exgcd(a, b);
    jout.println(
        ((((((String(u"gcd(") + a) + String(u", ")) + b) + String(u")")) +
          String(u" = ")) +
         d));
    jout.println(
        ((((String(u"x = ") + x) + String(u", ")) + String(u" y = ")) + y));
    jout.println(String(u"求逆元测试开始"));
    i64 mod = 1000000007;
    i64 test = 10000000;
    for (i64 num = 1; (num <= test); (num++)) {
      Exgcd::exgcd(num, mod);
      (x = jrem((jrem(x, mod) + mod), mod));
      if ((x != Exgcd::fermat(num, mod))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"求逆元测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Exgcd::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
        // 扩展欧几里得算法
        // 对于方程ax + by = gcd(a,b)
        // 当a和b确定，那么gcd(a,b)也确定
        // 扩展欧几里得算法可以给出a和b的最大公约数d、以及其中一个特解x、y
        // 特别注意要保证入参a和b没有负数
        // 讲解099，费马小定理计算逆元
                // 扩展欧几里得算法例子
                // 扩展欧几里得算法可以去求逆元
*/
