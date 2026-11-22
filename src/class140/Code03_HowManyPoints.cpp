// 原题测试 / 参考链接（保留上游原始地址）
// https://lightoj.com/problem/how-many-points

// Source: src/class140/Code03_HowManyPoints.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_HowManyPoints {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_HowManyPoints() {}
  static i64 gcd(i64 a, i64 b) {
    return ((b == 0) ? a : Code03_HowManyPoints::gcd(b, jrem(a, b)));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      i64 x1 = static_cast<i64>(in.nval);
      in.nextToken();
      i64 y1 = static_cast<i64>(in.nval);
      in.nextToken();
      i64 x2 = static_cast<i64>(in.nval);
      in.nextToken();
      i64 y2 = static_cast<i64>(in.nval);
      i64 ans = ([&]() {
        auto jargument_0 = std::abs((x1 - x2));
        auto jargument_1 = std::abs((y1 - y2));
        return Code03_HowManyPoints::gcd(jargument_0, jargument_1);
      }() + 1);
      out.println((((String(u"Case ") + t) + String(u": ")) + ans));
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_HowManyPoints::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 格点连线上有几个格点
// 二维网格中只有x和y的值都为整数的坐标，才叫格点
// 给定两个格点，A在(x1, y1)，B在(x2, y2)
// 返回A和B的连线上，包括A和B在内，一共有几个格点
// -10^9 <= x1、y1、x2、y2 <= 10^9
// 测试链接 : https://lightoj.com/problem/how-many-points
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
