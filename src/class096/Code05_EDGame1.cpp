// Source: src/class096/Code05_EDGame1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_EDGame1 {
  inline static int MAXN = 1001;
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_EDGame1() {}
  static void build() {
    for (int i = 0; (i < MAXN); (i++)) {
      for (int j = 0; (j < MAXN); (j++)) {
        (dp[i][j] = (-1));
      }
    }
  }
  static int sg(int a, int b) {
    if (((a == 1) && (b == 1))) {
      return 0;
    }
    if ((dp[a][b] != (-1))) {
      return dp[a][b];
    }
    Array<bool> appear = make_array<bool>((jmax(a, b) + 1));
    if ((a > 1)) {
      {
        int l = 1;
        int r = (a - 1);
        for (; (l < a); (l++), (r--)) {
          (appear[Code05_EDGame1::sg(l, r)] = true);
        }
      }
    }
    if ((b > 1)) {
      {
        int l = 1;
        int r = (b - 1);
        for (; (l < b); (l++), (r--)) {
          (appear[Code05_EDGame1::sg(l, r)] = true);
        }
      }
    }
    int ans = 0;
    for (int s = 0; (s <= jmax(a, b)); (s++)) {
      if ((!appear[s])) {
        (ans = s);
        break;
      }
    }
    (dp[a][b] = ans);
    return ans;
  }
  static void f1() {
    jout.println(String(u"石子数9以内所有组合的sg值"));
    jout.println();
    jout.print(String(u"    "));
    for (int i = 1; (i <= 9); (i++)) {
      jout.print((i + String(u" ")));
    }
    jout.println();
    jout.println();
    for (int a = 1; (a <= 9); (a++)) {
      jout.print((a + String(u"   ")));
      for (int b = 1; (b < a); (b++)) {
        jout.print(String(u"X "));
      }
      for (int b = a; (b <= 9); (b++)) {
        int sg = Code05_EDGame1::sg(a, b);
        jout.print((sg + String(u" ")));
      }
      jout.println();
    }
  }
  static void f2() {
    jout.println(String(u"石子数9以内所有组合的sg值，但是行列都-1"));
    jout.println();
    jout.print(String(u"    "));
    for (int i = 0; (i <= 8); (i++)) {
      jout.print((i + String(u" ")));
    }
    jout.println();
    jout.println();
    for (int a = 1; (a <= 9); (a++)) {
      jout.print(((a - 1) + String(u"   ")));
      for (int b = 1; (b < a); (b++)) {
        jout.print(String(u"X "));
      }
      for (int b = a; (b <= 9); (b++)) {
        int sg = Code05_EDGame1::sg(a, b);
        jout.print((sg + String(u" ")));
      }
      jout.println();
    }
  }
  static void f3() {
    jout.println(String(u"测试开始"));
    for (int a = 1; (a < MAXN); (a++)) {
      for (int b = 1; (b < MAXN); (b++)) {
        int sg1 = Code05_EDGame1::sg(a, b);
        int sg2 = Code05_EDGame1::lowZero(((a - 1) | (b - 1)));
        if ((sg1 != sg2)) {
          jout.println(String(u"出错了!"));
        }
      }
    }
    jout.println(String(u"测试结束"));
  }
  static int lowZero(int status) {
    int cnt = 0;
    while ((status > 0)) {
      if (((status & 1) == 0)) {
        break;
      }
      (status = jshr(status, 1));
      (cnt++);
    }
    return cnt;
  }
  static void java_main(Array<String> args) {
    Code05_EDGame1::build();
    Code05_EDGame1::f1();
    jout.println();
    jout.println();
    Code05_EDGame1::f2();
    jout.println();
    jout.println();
    Code05_EDGame1::f3();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_EDGame1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 计算两堆石子的SG值
// 桌上有两堆石子，石头数量分别为a、b
// 任取一堆石子，将其移走，然后分割同一组的另一堆石子
// 从中取出若干个石子放在被移走的位置，组成新的一堆
// 操作完成后，组内每堆的石子数必须保证大于0
// 显然，被分割的一堆的石子数至少要为2
//
两个人轮流进行分割操作，如果轮到某人进行操作时，两堆石子数均为1，判此人输掉比赛
// 计算sg[a][b]的值并找到简洁规律
// 本文件仅为题目5打表找规律的代码
        // 返回status最低位的0在第几位
*/
