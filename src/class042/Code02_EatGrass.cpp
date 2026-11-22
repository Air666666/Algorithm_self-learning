// Source: src/class042/Code02_EatGrass.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_EatGrass {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_EatGrass() {}
  static String win1(int n) { return Code02_EatGrass::f(n, String(u"A")); }
  static String f(int rest, String cur) {
    String enemy = (cur.equals(String(u"A")) ? String(u"B") : String(u"A"));
    if ((rest < 5)) {
      return (((rest == 0) || (rest == 2)) ? enemy : cur);
    }
    int pick = 1;
    while ((pick <= rest)) {
      if (Code02_EatGrass::f((rest - pick), enemy).equals(cur)) {
        return cur;
      }
      (pick *= 4);
    }
    return enemy;
  }
  static String win2(int n) {
    if (((jrem(n, 5) == 0) || (jrem(n, 5) == 2))) {
      return String(u"B");
    } else {
      return String(u"A");
    }
  }
  static void java_main(Array<String> args) {
    for (int i = 0; (i <= 50); (i++)) {
      jout.println(((i + String(u" : ")) + Code02_EatGrass::win1(i)));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_EatGrass::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢
        // "A"  "B"
        // rest : 还剩多少草
        // cur  : 当前选手的名字
        // 返回  : 还剩rest份草，当前选手是cur，按照题目说的，返回最终谁赢
                // rest >= 5
                // rest == 100
                // cur :
                // 1) 1 ->99,enemy ....
                // 2) 4 ->96,enemy ....
                // 3) 16 -> 84,enemy ....
                // 4) 64 -> 36,enemy ...
                // 没有cur赢的分支，enemy赢
*/
