// Source: src/class097/Code02_LargeNumberIsPrime4.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LargeNumberIsPrime4 {
  inline static Array<i64> p =
      Array<i64>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LargeNumberIsPrime4() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    int t = std::stoi(text(br.readLine()));
    for (int i = 0; (i < t); (i++)) {
      i64 n = std::stoll(text(br.readLine()));
      out.println((Code02_LargeNumberIsPrime4::millerRabin(n) ? String(u"Yes")
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
      if (Code02_LargeNumberIsPrime4::witness(p[i], n)) {
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
    i64 x1 = Code02_LargeNumberIsPrime4::power(a, u, n);
    i64 x2 = {};
    for (int i = 1; (i <= t); (i++)) {
      (x2 = Code02_LargeNumberIsPrime4::power(x1, 2, n));
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
        (ans = Code02_LargeNumberIsPrime4::multiply(ans, n, mod));
      }
      (n = Code02_LargeNumberIsPrime4::multiply(n, n, mod));
      (p = jshr(p, 1));
    }
    return ans;
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
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_LargeNumberIsPrime4::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Miller-Rabin测试，java版，不用BigInteger也能通过的实现
// 这个文件课上没有讲，课上讲的是，java中的long是64位
// 所以 long * long 需要128位才能不溢出，于是直接用BigInteger中自带的方法了
// 但是
// 如果a和b都是long类型，其实 a * b 的过程，用位运算去实现，中间结果都 % mod
即可
// 这样就不需要使用BigInteger
// 讲解033，位运算实现乘法，增加 每一步 % mod 的逻辑即可
// 重点看一下本文件中的 multiply 方法，就是位运算实现乘法的改写
// C++的同学也可以用这种方式来实现，也不需要定义128位的long类型
// 测试链接 : https://www.luogu.com.cn/problem/U148828
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 返回，n的p次方 % mod
        // 乘的每一步都用multiply方法，不用语言自带的乘法
        // a * b的过程，用位运算实现，让每一个中间结果都 % mod
        // 这个原理来自，讲解033，位运算实现乘法
        // 这么写可以防止溢出，这也叫龟速乘
*/
