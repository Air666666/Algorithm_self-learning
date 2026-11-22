// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3951

// Source: src/class140/Code05_LargestUnattainable.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_LargestUnattainable {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_LargestUnattainable() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    i64 a = static_cast<i64>(in.nval);
    in.nextToken();
    i64 b = static_cast<i64>(in.nval);
    out.println((((a * b) - a) - b));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_LargestUnattainable::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 无法组成的最大值
// 一共有a、b两种面值的硬币，a和b一定互质，每种硬币都有无限个
// 返回a和b无法组成的钱数中，最大值是多少
// 题目的输入保证存在最大的无法组成的钱数
// 1 <= a、b <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3951
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
