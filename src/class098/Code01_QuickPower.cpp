// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1226

// Source: src/class098/Code01_QuickPower.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_QuickPower {
  inline static i64 a = {};
  inline static i64 b = {};
  inline static i64 p = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_QuickPower() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (a = static_cast<int>(in.nval));
    in.nextToken();
    (b = static_cast<int>(in.nval));
    in.nextToken();
    (p = static_cast<int>(in.nval));
    out.println(
        ((((((a + String(u"^")) + b) + String(u" mod ")) + p) + String(u"=")) +
         Code01_QuickPower::power()));
    out.flush();
    out.close();
    br.close();
  }
  static int power() {
    i64 ans = 1;
    while ((b > 0)) {
      if (((b & 1) == 1)) {
        (ans = jrem((ans * a), p));
      }
      (a = jrem((a * a), p));
      (b = jshr(b, 1));
    }
    return static_cast<int>(ans);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_QuickPower::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 乘法快速幂模版
// 求a的b次方，对p取模的结果
// 测试链接 : https://www.luogu.com.cn/problem/P1226
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
