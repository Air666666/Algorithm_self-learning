// Source: src/class041/Code01_GcdAndLcm.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_GcdAndLcm {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_GcdAndLcm() {}
  static i64 gcd(i64 a, i64 b) {
    return ((b == 0) ? a : Code01_GcdAndLcm::gcd(b, jrem(a, b)));
  }
  static i64 lcm(i64 a, i64 b) {
    return (jdiv(static_cast<i64>(a), Code01_GcdAndLcm::gcd(a, b)) * b);
  }
};

/* Original teaching comments:
// 求最大公约数、最小公倍数
        // 证明辗转相除法就是证明如下关系：
        // gcd(a, b) = gcd(b, a % b)
        // 假设a % b = r，即需要证明的关系为：gcd(a, b) = gcd(b, r)
        // 证明过程：
        // 因为a % b = r，所以如下两个等式必然成立
        // 1) a = b * q + r，q为0、1、2、3....中的一个整数
        // 2) r = a − b * q，q为0、1、2、3....中的一个整数
        // 假设u是a和b的公因子，则有: a = s * u, b = t * u
        // 把a和b带入2)得到，r = s * u - t * u * q = (s - t * q) * u
        // 这说明 : u如果是a和b的公因子，那么u也是r的因子
        // 假设v是b和r的公因子，则有: b = x * v, r = y * v
        // 把b和r带入1)得到，a = x * v * q + y * v = (x * q + y) * v
        // 这说明 : v如果是b和r的公因子，那么v也是a的公因子
        // 综上，a和b的每一个公因子 也是 b和r的一个公因子，反之亦然
        // 所以，a和b的全体公因子集合 = b和r的全体公因子集合
        // 即gcd(a, b) = gcd(b, r)
        // 证明结束
*/
