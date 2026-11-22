// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4549

// Source: src/class139/Code01_BezoutLemma.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BezoutLemma {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BezoutLemma() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code01_BezoutLemma::gcd(b, jrem(a, b)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (ans = Code01_BezoutLemma::gcd(std::abs(static_cast<int>(in.nval)), ans));
    }
    out.println(ans);
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BezoutLemma::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 裴蜀定理模版题
// 给定长度为n的一组整数值[a1, a2, a3...]，你找到一组数值[x1, x2, x3...]
// 要让a1*x1 + a2*x2 + a3*x3...得到的结果为最小正整数
// 返回能得到的最小正整数是多少
// 1 <= n <= 20
// 1 <= ai <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4549
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
