// Source: src/class042/Code03_IsSumOfConsecutiveNumbers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_IsSumOfConsecutiveNumbers {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_IsSumOfConsecutiveNumbers() {}
  static bool is1(int num) {
    {
      int start = 1;
      int sum = {};
      for (; (start <= num); (start++)) {
        (sum = start);
        for (int j = (start + 1); (j <= num); (j++)) {
          if (((sum + j) > num)) {
            break;
          }
          if (((sum + j) == num)) {
            return true;
          }
          (sum += j);
        }
      }
    }
    return false;
  }
  static bool is2(int num) { return ((num & (num - 1)) != 0); }
  static void java_main(Array<String> args) {
    for (int num = 1; (num < 200); (num++)) {
      jout.println(
          ((num + String(u" : ")) + (Code03_IsSumOfConsecutiveNumbers::is1(num)
                                         ? String(u"T")
                                         : String(u"F"))));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_IsSumOfConsecutiveNumbers::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 判断一个数字是否是若干数量(数量>1)的连续正整数的和
*/
