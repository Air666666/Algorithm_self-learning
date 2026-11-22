// Source: src/class042/Code01_AppleMinBags1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_AppleMinBags1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_AppleMinBags1() {}
  static int bags1(int apple) {
    int ans = Code01_AppleMinBags1::f(apple);
    return ((ans == std::numeric_limits<int>::max()) ? (-1) : ans);
  }
  static int f(int rest) {
    if ((rest < 0)) {
      return std::numeric_limits<int>::max();
    }
    if ((rest == 0)) {
      return 0;
    }
    int p1 = Code01_AppleMinBags1::f((rest - 8));
    int p2 = Code01_AppleMinBags1::f((rest - 6));
    (p1 += ((p1 != std::numeric_limits<int>::max()) ? 1 : 0));
    (p2 += ((p2 != std::numeric_limits<int>::max()) ? 1 : 0));
    return jmin(p1, p2);
  }
  static int bags2(int apple) {
    if (((apple & 1) != 0)) {
      return (-1);
    }
    if ((apple < 18)) {
      if ((apple == 0)) {
        return 0;
      }
      if (((apple == 6) || (apple == 8))) {
        return 1;
      }
      if ((((apple == 12) || (apple == 14)) || (apple == 16))) {
        return 2;
      }
      return (-1);
    }
    return (jdiv((apple - 18), 8) + 3);
  }
  static void java_main(Array<String> args) {
    for (int apple = 0; (apple < 100); (apple++)) {
      jout.println(
          ((apple + String(u" : ")) + Code01_AppleMinBags1::bags1(apple)));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_AppleMinBags1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 买苹果使用最少袋子
// 本题已经找到了在线测试，就是本节课Code01_AppleMinBags2文件
//
有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个苹果，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1
        // 当前还有rest个苹果，使用的每个袋子必须装满，返回至少几个袋子
                // 使用8规格的袋子，剩余的苹果还需要几个袋子，有可能返回无效解
                // 使用6规格的袋子，剩余的苹果还需要几个袋子，有可能返回无效解
*/
