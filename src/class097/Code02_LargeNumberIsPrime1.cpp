// Source: src/class097/Code02_LargeNumberIsPrime1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LargeNumberIsPrime1 {
  inline static Array<i64> p =
      Array<i64>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LargeNumberIsPrime1() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    int t = std::stoi(text(br.readLine()));
    for (int i = 0; (i < t); (i++)) {
      i64 n = std::stoll(text(br.readLine()));
      out.println((Code02_LargeNumberIsPrime1::millerRabin(n) ? String(u"Yes")
                                                              : String(u"No")));
    }
    out.flush();
    out.close();
    br.close();
  }
  static bool millerRabin(i64 n) {
    if ((n <= 2)) {
      return (n == 2);
    }
    if (((n & 1) == 0)) {
      return false;
    }
    for (int i = 0; ((i < p.length) && (p[i] < n)); (i++)) {
      if (Code02_LargeNumberIsPrime1::witness(p[i], n)) {
        return false;
      }
    }
    return true;
  }
  static bool witness(i64 a, i64 n) {
    i64 u = (n - 1);
    int t = 0;
    while (((u & 1) == 0)) {
      (t++);
      (u = jshr(u, 1));
    }
    i64 x1 = Code02_LargeNumberIsPrime1::power(a, u, n);
    i64 x2 = {};
    for (int i = 1; (i <= t); (i++)) {
      (x2 = Code02_LargeNumberIsPrime1::power(x1, 2, n));
      if ((((x2 == 1) && (x1 != 1)) && (x1 != (n - 1)))) {
        return true;
      }
      (x1 = x2);
    }
    if ((x1 != 1)) {
      return true;
    }
    return false;
  }
  static i64 power(i64 n, i64 p, i64 mod) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * n), mod));
      }
      (n = jrem((n * n), mod));
      (p = jshr(p, 1));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_LargeNumberIsPrime1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 判断较大的数字是否是质数(Miller-Rabin测试)
// 测试链接 : https://www.luogu.com.cn/problem/U148828
// 如下代码无法通过所有测试用例
// 本文件可以解决10^9范围内数字的质数检查
// 时间复杂度O(s * (logn)的三次方)，很快
// 为什么不能搞定所有long类型的数字检查
// 原因在于long类型位数不够，乘法同余的时候会溢出，课上已经做了说明
                        // 这里要注意
                        // 如果读入long类型的数字，数字本身很大的话
                        // 先读出字符串str，然后用Long.valueOf(str)
        // 质数的个数代表测试次数
        // 如果想增加测试次数就继续增加更大的质数
        // 单次测试的函数，不用纠结原理
        // 返回n是不是合数
        // 返回 : n的p次方 % mod
        // 快速幂，讲解098会重点讲述，此时直接用即可
*/
