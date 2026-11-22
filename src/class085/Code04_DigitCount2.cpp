// Source: src/class085/Code04_DigitCount2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DigitCount2 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DigitCount2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      i64 a = static_cast<i64>(in.nval);
      in.nextToken();
      i64 b = static_cast<i64>(in.nval);
      for (int i = 0; (i < 9); (i++)) {
        out.print((Code04_DigitCount2::digitsCount(i, a, b) + String(u" ")));
      }
      out.println(Code04_DigitCount2::digitsCount(9, a, b));
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 digitsCount(int d, i64 a, i64 b) {
    return [&]() {
      auto jleft = Code04_DigitCount2::count(b, d);
      auto jright = Code04_DigitCount2::count((a - 1), d);
      return (jleft - jright);
    }();
  }
  static i64 count(i64 num, int d) {
    i64 ans = 0;
    {
      i64 right = 1;
      i64 tmp = num;
      i64 left = {};
      i64 cur = {};
      for (; (tmp != 0); (right *= 10), (tmp /= 10)) {
        (left = jdiv(tmp, 10));
        if ((d == 0)) {
          (left--);
        }
        (ans += (left * right));
        (cur = jrem(tmp, 10));
        if ((cur > d)) {
          (ans += right);
        } else if ((cur == d)) {
          (ans += (jrem(num, right) + 1));
        }
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_DigitCount2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 范围内的数字计数
// 给定两个正整数a和b，求在[a,b]范围上的所有整数中
// 每个数码(digit)各出现了多少次
// 1 <= a, b
// 测试链接 : https://www.luogu.com.cn/problem/P2602
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
