// Source: src/class096/Code03_TwoStonesBashGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_TwoStonesBashGame {
  inline static int MAXN = 101;
  inline static Array<Array<Array<String>>> dp =
      make_array<String>(MAXN, MAXN, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_TwoStonesBashGame() {}
  static String win1(int a, int b, int m) {
    if ((m >= jmax(a, b))) {
      return ((a != b) ? String(u"先手") : String(u"后手"));
    }
    if ((a == b)) {
      return String(u"后手");
    }
    if ((dp[a][b][m] != nullptr)) {
      return dp[a][b][m];
    }
    String ans = String(u"后手");
    for (int pick = 1; (pick <= jmin(a, m)); (pick++)) {
      if (Code03_TwoStonesBashGame::win1((a - pick), b, m)
              .equals(String(u"后手"))) {
        (ans = String(u"先手"));
      }
      if (ans.equals(String(u"先手"))) {
        break;
      }
    }
    for (int pick = 1; (pick <= jmin(b, m)); (pick++)) {
      if (Code03_TwoStonesBashGame::win1(a, (b - pick), m)
              .equals(String(u"后手"))) {
        (ans = String(u"先手"));
      }
      if (ans.equals(String(u"先手"))) {
        break;
      }
    }
    (dp[a][b][m] = ans);
    return ans;
  }
  static String win2(int a, int b, int m) {
    int n = jmax(a, b);
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
    return (((sg[a] ^ sg[b]) != 0) ? String(u"先手") : String(u"后手"));
  }
  static String win3(int a, int b, int m) {
    return ((jrem(a, (m + 1)) != jrem(b, (m + 1))) ? String(u"先手")
                                                   : String(u"后手"));
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    for (int a = 0; (a < MAXN); (a++)) {
      for (int b = 0; (b < MAXN); (b++)) {
        for (int m = 1; (m < MAXN); (m++)) {
          String ans1 = Code03_TwoStonesBashGame::win1(a, b, m);
          String ans2 = Code03_TwoStonesBashGame::win2(a, b, m);
          String ans3 = Code03_TwoStonesBashGame::win3(a, b, m);
          if (((!ans1.equals(ans2)) || (!ans1.equals(ans3)))) {
            jout.println(String(u"出错了！"));
          }
        }
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_TwoStonesBashGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 两堆石头的巴什博弈
// 有两堆石头，数量分别为a、b
// 两个人轮流拿，每次可以选择其中一堆石头，拿1~m颗
// 拿到最后一颗石子的人获胜，根据a、b、m返回谁赢
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 动态规划方法彻底尝试
        // 为了验证
                                // 后续过程的赢家是后续过程的后手
                                // 那就表示此时的先手，通过这个后续过程，能赢
                                // 后续过程的赢家是后续过程的后手
                                // 那就表示此时的先手，通过这个后续过程，能赢
                                // 后续过程的赢家是后续过程的后手
                                // 那就表示此时的先手，通过这个后续过程，能赢
        // sg定理
        // 时间复杂度O(1)的最优解
        // 其实是根据方法2中的sg表观察出来的
*/
