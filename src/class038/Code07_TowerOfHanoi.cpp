// Source: src/class038/Code07_TowerOfHanoi.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_TowerOfHanoi {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_TowerOfHanoi() {}
  static void hanoi(int n) {
    if ((n > 0)) {
      Code07_TowerOfHanoi::f(n, String(u"左"), String(u"右"), String(u"中"));
    }
  }
  static void f(int i, String from, String to, String other) {
    if ((i == 1)) {
      jout.println(
          (((String(u"移动圆盘 1 从 ") + from) + String(u" 到 ")) + to));
    } else {
      Code07_TowerOfHanoi::f((i - 1), from, other, to);
      jout.println((((((String(u"移动圆盘 ") + i) + String(u" 从 ")) + from) +
                     String(u" 到 ")) +
                    to));
      Code07_TowerOfHanoi::f((i - 1), other, to, from);
    }
  }
  static void java_main(Array<String> args) {
    int n = 3;
    Code07_TowerOfHanoi::hanoi(n);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_TowerOfHanoi::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 打印n层汉诺塔问题的最优移动轨迹
*/
