// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1082

// Source: src/class139/Code04_CongruenceEquation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CongruenceEquation {
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CongruenceEquation() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code04_CongruenceEquation::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    i64 a = static_cast<i64>(in.nval);
    in.nextToken();
    i64 b = static_cast<i64>(in.nval);
    Code04_CongruenceEquation::exgcd(a, b);
    out.println(jrem((jrem(x, b) + b), b));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_CongruenceEquation::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 同余方程
// 求关于x的同余方程 ax ≡ 1(mod b) 的最小正整数解
// 题目保证一定有解，也就是a和b互质
// 2 <= a、b <= 2 * 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1082
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 扩展欧几里得算法
*/
