// Source: src/class117/TwoSmallQuestions.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct TwoSmallQuestions {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  TwoSmallQuestions() {}
  static void show1(int x, int m) {
    {
      int p = (m - 1);
      int t = x;
      for (; (p >= 0); (p--)) {
        if ((jshl(1, p) <= t)) {
          (t -= jshl(1, p));
          jout.println((((x + String(u"的第")) + p) + String(u"位是1")));
        } else {
          jout.println((((x + String(u"的第")) + p) + String(u"位是0")));
        }
      }
    }
  }
  static void show2(int x) {
    int power = 0;
    while ((jshl(1, power) <= jshr(x, 1))) {
      (power++);
    }
    jout.println(
        ((((String(u"<=") + x) + String(u"最大的2的幂，是2的")) + power) +
         String(u"次方")));
  }
  static void java_main(Array<String> args) {
    int x = 101;
    int m = 10;
    TwoSmallQuestions::show1(x, m);
    (x = 13);
    TwoSmallQuestions::show2(x);
    (x = 16);
    TwoSmallQuestions::show2(x);
    (x = 2000000000);
    TwoSmallQuestions::show2(x);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  TwoSmallQuestions::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
        // 给定一个正数x
        // 已知用m个二进制位一定能表示x
        // 从高位到低位打印x每一位的状态
        // 给定一个正数x
        // 打印<=x最大的2的幂
        // 到底是2的几次方
                // 以下注释掉的写法不对，没有考虑溢出
//		while ((1 << power) <= x) {
//			power++;
//		}
//		power--;
                // 防止溢出的写法
                // 需要保证用m个二进制位一定能表示x
*/
