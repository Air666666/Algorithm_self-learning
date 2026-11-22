// Source: src/class090/Code01_CuttingBamboo.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CuttingBamboo {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CuttingBamboo() {}
  static i64 power(i64 x, int n, int mod) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * x), mod));
      }
      (x = jrem((x * x), mod));
      (n = jshr(n, 1));
    }
    return ans;
  }
  static int cuttingBamboo(int n) {
    if ((n == 2)) {
      return 1;
    }
    if ((n == 3)) {
      return 2;
    }
    int mod = 1000000007;
    int tail = ((jrem(n, 3) == 0) ? 1 : ((jrem(n, 3) == 1) ? 4 : 2));
    int power = jdiv(((tail == 1) ? n : (n - tail)), 3);
    return static_cast<int>(
        jrem((Code01_CuttingBamboo::power(3, power, mod) * tail), mod));
  }
};

/* Original teaching comments:
// 砍竹子II
// 现需要将一根长为正整数bamboo_len的竹子砍为若干段
// 每段长度均为正整数
// 请返回每段竹子长度的最大乘积是多少
// 答案需要对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/
        // 快速幂，求余数
        // 求x的n次方，最终得到的结果 % mod
                // n = 4  -> 2 * 2
                // n = 5  -> 3 * 2
                // n = 6  -> 3 * 3
                // n = 7  -> 3 * 2 * 2
                // n = 8  -> 3 * 3 * 2
                // n = 9  -> 3 * 3 * 3
                // n = 10 -> 3 * 3 * 2 * 2
                // n = 11 -> 3 * 3 * 3 * 2
                // n = 12 -> 3 * 3 * 3 * 3
*/
