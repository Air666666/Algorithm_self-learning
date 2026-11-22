// Source: src/class097/Code02_LargeNumberIsPrime2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LargeNumberIsPrime2 {
  inline static int s = 10;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LargeNumberIsPrime2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    int t = std::stoi(text(br.readLine()));
    for (int i = 0; (i < t); (i++)) {
      BigInteger n = BigInteger(br.readLine());
      out.println((n.isProbablePrime(s) ? String(u"Yes") : String(u"No")));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_LargeNumberIsPrime2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 判断较大的数字是否是质数(Miller-Rabin测试)
// 测试链接 : https://www.luogu.com.cn/problem/U148828
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
// 本文件可以搞定任意范围数字的质数检查，时间复杂度O(s * (logn)的三次方)
// 为什么不自己写，为什么要用BigInteger中的isProbablePrime方法
// 原因在于long类型位数不够，乘法同余的时候会溢出，课上已经做了说明
        // 测试次数，次数越多失误率越低，但速度也越慢
                        // isProbablePrime方法包含MillerRabin和LucasLehmer测试
                        // 给定测试次数s即可
*/
