// Source: src/class099/Code01_InverseSingle.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_InverseSingle {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_InverseSingle() {}
  static void java_main(Array<String> args) {
    int mod = 41;
    i64 b = 3671613LL;
    i64 a = (67312LL * b);
    jout.println(Code01_InverseSingle::compute1(a, b, mod));
    jout.println(Code01_InverseSingle::compute2(a, b, mod));
  }
  static int compute1(i64 a, i64 b, int mod) {
    return static_cast<int>(jrem(jdiv(a, b), mod));
  }
  static int compute2(i64 a, i64 b, int mod) {
    i64 inv = Code01_InverseSingle::power(b, (mod - 2), mod);
    return static_cast<int>(jrem((jrem(a, mod) * inv), mod));
  }
  static i64 power(i64 b, int n, int mod) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * b), mod));
      }
      (b = jrem((b * b), mod));
      (n = jshr(n, 1));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_InverseSingle::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 单个除数求逆元
// 对数器验证
                // 1) 必须保证a/b可以整除
                // 2) 必须保证mod是质数
                // 3) 必须保证b和mod的最大公约数为1
        // 乘法快速幂
        // 计算b的n次方的结果%mod
*/
