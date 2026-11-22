// Source: src/class110/HowManySpace.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct HowManySpace {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  HowManySpace() {}
  static int maxi(int l, int r, int i) {
    if ((l == r)) {
      return i;
    } else {
      int mid = jshr((l + r), 1);
      return [&]() {
        auto jargument_0 = HowManySpace::maxi(l, mid, jshl(i, 1));
        auto jargument_1 = HowManySpace::maxi((mid + 1), r, (jshl(i, 1) | 1));
        return jmax(jargument_0, jargument_1);
      }();
    }
  }
  static void java_main(Array<String> args) {
    int n = 10000;
    int a = 0;
    int b = 0;
    double t = 0;
    for (int i = 1; (i <= n); (i++)) {
      int space = HowManySpace::maxi(1, i, 1);
      double times = jdiv(static_cast<double>(space), static_cast<double>(i));
      jout.println(((((((String(u"范围[1~") + i) + String(u"]，")) +
                       String(u"需要空间")) +
                      space) +
                     String(u"，倍数=")) +
                    times));
      if ((times > t)) {
        (a = i);
        (b = space);
        (t = times);
      }
    }
    jout.println(
        ((((((String(u"其中的最大倍数，范围[1~") + a) + String(u"]，")) +
            String(u"需要空间")) +
           b) +
          String(u"，倍数=")) +
         t));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  HowManySpace::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树范围为1 ~ n时，需要几倍空间才够用？
        // 范围l~r，信息存在独立数组的i位置
        // 返回递归展开的过程中出现的最大编号
*/
