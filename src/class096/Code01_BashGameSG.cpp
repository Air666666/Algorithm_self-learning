// Source: src/class096/Code01_BashGameSG.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BashGameSG {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BashGameSG() {}
  static String bash1(int n, int m) {
    return ((jrem(n, (m + 1)) != 0) ? String(u"先手") : String(u"后手"));
  }
  static String bash2(int n, int m) {
    Array<int> sg = make_array<int>((n + 1));
    Array<bool> appear = make_array<bool>((m + 1));
    for (int i = 1; (i <= n); (i++)) {
      j::fill(appear, false);
      for (int j = 1; ((j <= m) && ((i - j) >= 0)); (j++)) {
        (appear[sg[(i - j)]] = true);
      }
      for (int s = 0; (s <= m); (s++)) {
        if ((!appear[s])) {
          (sg[i] = s);
          break;
        }
      }
    }
    return ((sg[n] != 0) ? String(u"先手") : String(u"后手"));
  }
  static void java_main(Array<String> args) {
    int V = 1000;
    int testTimes = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int n = static_cast<int>((j::random() * V));
      int m = static_cast<int>((j::random() * V));
      String ans1 = Code01_BashGameSG::bash1(n, m);
      String ans2 = Code01_BashGameSG::bash2(n, m);
      if ((!ans1.equals(ans2))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
    int n = 100;
    int m = 6;
    Code01_BashGameSG::bash2(n, m);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BashGameSG::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 巴什博弈(SG函数求解过程展示)
// 一共有n颗石子，两个人轮流拿，每次可以拿1~m颗石子
// 拿到最后一颗石子的人获胜，根据n、m返回谁赢
// 对数器验证
        // 发现结论去求解，时间复杂度O(1)
        // 充分研究了性质
        // sg函数去求解，时间复杂度O(n*m)
        // 不用研究性质
        // 其实把sg表打印之后，也可以发现性质，也就是打表找规律
//		System.out.println("打印 n = " + n + ", m = " + m + " 的sg表");
//		for (int i = 0; i <= n; i++) {
//			System.out.println("sg(" + i + ") : " + sg[i]);
//		}
        // 为了验证
*/
