// 原题测试 / 参考链接（保留上游原始地址）
// http://poj.org/problem?id=1597

// Source: src/class139/Code03_UniformGenerator.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_UniformGenerator {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_UniformGenerator() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code03_UniformGenerator::gcd(b, jrem(a, b)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int step = static_cast<int>(in.nval);
      in.nextToken();
      int mod = static_cast<int>(in.nval);
      out.print(([&]() {
        auto jleft = String::format(String(u"%10d"), step);
        auto jright = String::format(String(u"%10d"), mod);
        return (jleft + jright);
      }() + String(u"    ")));
      out.println(((Code03_UniformGenerator::gcd(step, mod) == 1)
                       ? String(u"Good Choice")
                       : String(u"Bad Choice")));
      out.println(String(u" "));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_UniformGenerator::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 均匀生成器
// 如果有两个数字step和mod，那么可以由以下方式生成很多数字
// seed(1) = 0，seed(i+1) = (seed(i) + step) % mod
// 比如，step = 3、mod = 5
// seed(1) = 0，seed(2) = 3，seed(3) = 1，seed(4) = 4，seed(5) = 2
// 如果能产生0 ~ mod-1所有数字，step和mod的组合叫  "Good Choice"
// 如果无法产生0 ~ mod-1所有数字，step和mod的组合叫 "Bad Choice"
// 根据step和mod，打印结果
// 1 <= step、mod <= 10^5
// 测试链接 : http://poj.org/problem?id=1597
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
