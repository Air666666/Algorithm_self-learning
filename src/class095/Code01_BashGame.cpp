// Source: src/class095/Code01_BashGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BashGame {
  inline static int MAXN = 1001;
  inline static Array<Array<String>> dp = make_array<String>(MAXN, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BashGame() {}
  static String bashGame1(int n, int m) {
    if ((n == 0)) {
      return String(u"后手");
    }
    if ((dp[n][m] != nullptr)) {
      return dp[n][m];
    }
    String ans = String(u"后手");
    for (int pick = 1; (pick <= m); (pick++)) {
      if (Code01_BashGame::bashGame1((n - pick), m).equals(String(u"后手"))) {
        (ans = String(u"先手"));
        break;
      }
    }
    (dp[n][m] = ans);
    return ans;
  }
  static String bashGame2(int n, int m) {
    return ((jrem(n, (m + 1)) != 0) ? String(u"先手") : String(u"后手"));
  }
  static void java_main(Array<String> args) {
    int V = 500;
    int testTimes = 5000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int n = static_cast<int>((j::random() * V));
      int m = (static_cast<int>((j::random() * V)) + 1);
      String ans1 = Code01_BashGame::bashGame1(n, m);
      String ans2 = Code01_BashGame::bashGame2(n, m);
      if ((!ans1.equals(ans2))) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BashGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 巴什博弈(Bash Game)
// 一共有n颗石子，两个人轮流拿，每次可以拿1~m颗石子
// 拿到最后一颗石子的人获胜，根据n、m返回谁赢
        // 动态规划进行所有尝试
        // 为了验证
                                // 后续过程的赢家是后续过程的后手
                                // 那就表示此时的先手，通过这个后续过程，能赢
        // 正式方法
        // 为了验证
*/
