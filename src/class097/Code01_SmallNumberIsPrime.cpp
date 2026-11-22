// Source: src/class097/Code01_SmallNumberIsPrime.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SmallNumberIsPrime {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SmallNumberIsPrime() {}
  static bool isPrime(i64 n) {
    if ((n <= 1)) {
      return false;
    }
    for (i64 i = 2; ((i * i) <= n); (i++)) {
      if ((jrem(n, i) == 0)) {
        return false;
      }
    }
    return true;
  }
};

/* Original teaching comments:
// 判断较小的数字是否是质数
// 时间复杂度O(根号n)
                // 2 ... 根号n
*/
