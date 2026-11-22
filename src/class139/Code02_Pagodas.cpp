// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=5512
// https://vjudge.net/problem/HDU-5512

// Source: src/class139/Code02_Pagodas.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Pagodas {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Pagodas() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code02_Pagodas::gcd(b, jrem(a, b)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    {
      int t = 1;
      int n = {};
      int a = {};
      int b = {};
      for (; (t <= cases); (t++)) {
        in.nextToken();
        (n = static_cast<int>(in.nval));
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        out.print(((String(u"Case #") + t) + String(u": ")));
        if (((jdiv(n, Code02_Pagodas::gcd(a, b)) & 1) == 1)) {
          out.println(String(u"Yuwgna"));
        } else {
          out.println(String(u"Iaka"));
        }
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Pagodas::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 修理宝塔
// 一共有编号1~n的宝塔，其中a号和b号宝塔已经修好了
// Yuwgna和Iaka两个人轮流修塔，Yuwgna先手，Iaka后手，谁先修完所有的塔谁赢
// 每次可以选择j+k号或者j-k号塔进行修理，其中j和k是任意两个已经修好的塔
// 也就是输入n、a、b，如果先手赢打印"Yuwgna"，后手赢打印"Iaka"
// 2 <= n <= 2 * 10^4
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=5512
// 测试链接 : https://vjudge.net/problem/HDU-5512
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
