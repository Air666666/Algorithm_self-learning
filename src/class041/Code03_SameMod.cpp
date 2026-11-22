// Source: src/class041/Code03_SameMod.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_SameMod {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_SameMod() {}
  static i64 random() {
    return static_cast<i64>((j::random() * std::numeric_limits<i64>::max()));
  }
  static int f1(i64 a, i64 b, i64 c, i64 d, int mod) {
    BigInteger o1 = BigInteger(j::str(a));
    BigInteger o2 = BigInteger(j::str(b));
    BigInteger o3 = BigInteger(j::str(c));
    BigInteger o4 = BigInteger(j::str(d));
    BigInteger o5 = o1.add(o2);
    BigInteger o6 = o3.subtract(o4);
    BigInteger o7 = o1.multiply(o3);
    BigInteger o8 = o2.multiply(o4);
    BigInteger o9 = o5.multiply(o6);
    BigInteger o10 = o7.subtract(o8);
    BigInteger o11 = o9.add(o10);
    BigInteger o12 = o11.mod(BigInteger(j::str(mod)));
    if ((o12.signum() == (-1))) {
      return o12.add(BigInteger(j::str(mod))).intValue();
    } else {
      return o12.intValue();
    }
  }
  static int f2(i64 a, i64 b, i64 c, i64 d, int mod) {
    int o1 = static_cast<int>(jrem(a, mod));
    int o2 = static_cast<int>(jrem(b, mod));
    int o3 = static_cast<int>(jrem(c, mod));
    int o4 = static_cast<int>(jrem(d, mod));
    int o5 = jrem((o1 + o2), mod);
    int o6 = jrem(((o3 - o4) + mod), mod);
    int o7 = static_cast<int>(jrem((static_cast<i64>(o1) * o3), mod));
    int o8 = static_cast<int>(jrem((static_cast<i64>(o2) * o4), mod));
    int o9 = static_cast<int>(jrem((static_cast<i64>(o5) * o6), mod));
    int o10 = jrem(((o7 - o8) + mod), mod);
    int ans = jrem((o9 + o10), mod);
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int testTime = 100000;
    int mod = 1000000007;
    for (int i = 0; (i < testTime); (i++)) {
      i64 a = Code03_SameMod::random();
      i64 b = Code03_SameMod::random();
      i64 c = Code03_SameMod::random();
      i64 d = Code03_SameMod::random();
      if ([&]() {
            auto jleft = Code03_SameMod::f1(a, b, c, d, mod);
            auto jright = Code03_SameMod::f2(a, b, c, d, mod);
            return (jleft != jright);
          }()) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
    jout.println(String(u"==="));
    i64 a = Code03_SameMod::random();
    i64 b = Code03_SameMod::random();
    i64 c = Code03_SameMod::random();
    i64 d = Code03_SameMod::random();
    jout.println((String(u"a : ") + a));
    jout.println((String(u"b : ") + b));
    jout.println((String(u"c : ") + c));
    jout.println((String(u"d : ") + d));
    jout.println(String(u"==="));
    jout.println((String(u"f1 : ") + Code03_SameMod::f1(a, b, c, d, mod)));
    jout.println((String(u"f2 : ") + Code03_SameMod::f2(a, b, c, d, mod)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_SameMod::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 加法、减法、乘法的同余原理
// 不包括除法，因为除法必须求逆元，后续课讲述
        // 为了测试
        // 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
                // ((a + b) * (c - d) + (a * c - b * d)) % mod
                        // 如果是负数那么+mod返回
                        // 如果不是负数直接返回
        // 计算 ((a + b) * (c - d) + (a * c - b * d)) % mod 的非负结果
*/
