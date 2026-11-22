// Source: src/class096/Code04_ThreeStonesPickFibonacci.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_ThreeStonesPickFibonacci {
  inline static int MAXN = 201;
  inline static Array<int> f =
      Array<int>{1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
  inline static Array<Array<Array<String>>> dp =
      make_array<String>(MAXN, MAXN, MAXN);
  inline static Array<int> sg = make_array<int>(MAXN);
  inline static Array<bool> appear = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_ThreeStonesPickFibonacci() {}
  static String win1(int a, int b, int c) {
    if ((((a + b) + c) == 0)) {
      return String(u"后手");
    }
    if ((dp[a][b][c] != nullptr)) {
      return dp[a][b][c];
    }
    String ans = String(u"后手");
    for (int i = 0; (i < f.length); (i++)) {
      if ((f[i] <= a)) {
        if (Code04_ThreeStonesPickFibonacci::win1((a - f[i]), b, c)
                .equals(String(u"后手"))) {
          (ans = String(u"先手"));
          break;
        }
      }
      if ((f[i] <= b)) {
        if (Code04_ThreeStonesPickFibonacci::win1(a, (b - f[i]), c)
                .equals(String(u"后手"))) {
          (ans = String(u"先手"));
          break;
        }
      }
      if ((f[i] <= c)) {
        if (Code04_ThreeStonesPickFibonacci::win1(a, b, (c - f[i]))
                .equals(String(u"后手"))) {
          (ans = String(u"先手"));
          break;
        }
      }
    }
    (dp[a][b][c] = ans);
    return ans;
  }
  static void build() {
    for (int i = 1; (i < MAXN); (i++)) {
      j::fill(appear, false);
      for (int j = 0; ((j < f.length) && ((i - f[j]) >= 0)); (j++)) {
        (appear[sg[(i - f[j])]] = true);
      }
      for (int s = 0; (s < MAXN); (s++)) {
        if ((!appear[s])) {
          (sg[i] = s);
          break;
        }
      }
    }
  }
  static String win2(int a, int b, int c) {
    return ((((sg[a] ^ sg[b]) ^ sg[c]) != 0) ? String(u"先手")
                                             : String(u"后手"));
  }
  static void java_main(Array<String> args) {
    Code04_ThreeStonesPickFibonacci::build();
    jout.println(String(u"测试开始"));
    for (int a = 0; (a < MAXN); (a++)) {
      for (int b = 0; (b < MAXN); (b++)) {
        for (int c = 0; (c < MAXN); (c++)) {
          String ans1 = Code04_ThreeStonesPickFibonacci::win1(a, b, c);
          String ans2 = Code04_ThreeStonesPickFibonacci::win2(a, b, c);
          if ((!ans1.equals(ans2))) {
            jout.println(String(u"出错了！"));
          }
        }
      }
    }
    jout.println(String(u"测试结束"));
    for (int i = 0; (i < MAXN); (i++)) {
      jout.println((((String(u"sg(") + i) + String(u") : ")) + sg[i]));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_ThreeStonesPickFibonacci::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 三堆石头拿取斐波那契数博弈
// 有三堆石头，数量分别为a、b、c
// 两个人轮流拿，每次可以选择其中一堆石头，拿取斐波那契数的石头
// 拿到最后一颗石子的人获胜，根据a、b、c返回谁赢
// 来自真实大厂笔试，每堆石子的数量在10^5以内
// 没有在线测试，对数器验证
        // 如果MAXN变大
        // 相应的要修改f数组
        // MAXN以内的斐波那契数
        // 动态规划方法彻底尝试
        // 为了验证
                // 假设当前的先手来行动
                // 注意不是全局的先手，是当前的先手来行动！
                // 当前！当前！当前！
                        // 当前的先手，面对这个局面
                        // 返回当前的后手赢
                                        // 后续过程的赢家是后续过程的后手
                                        //
那就表示当前的先手，通过这个后续过程，能赢
                                        // 后续过程的赢家是后续过程的后手
                                        //
那就表示当前的先手，通过这个后续过程，能赢
                                        // 后续过程的赢家是后续过程的后手
                                        //
那就表示当前的先手，通过这个后续过程，能赢
        // sg定理
        // O(10^5 * 24 * 2)
                // 试图找到简洁规律，想通过O(1)的过程就得到sg(x)
                // 于是打印200以内的sg值，开始观察
                // 刚开始有规律，但是在sg(138)之后开始发生异常波动
                // 这道题在考的时候，数据量并没有大到需要O(1)的过程才能通过
                // 那就用build方法计算sg值，不再找寻简洁规律
                // 考试时一切根据题目数据量来决定是否继续优化
*/
