// Source: src/class125/Code03_AdjacentDifferent1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AdjacentDifferent1 {
  inline static int LIMIT1 = 100001;
  inline static int LIMIT2 = 101;
  inline static int LIMIT3 = 8;
  inline static int MOD = 376544743;
  inline static Array<int> start = make_array<int>(LIMIT1);
  inline static Array<int> end = make_array<int>(LIMIT1);
  inline static Array<Array<Array<int>>> dp =
      make_array<int>(LIMIT2, LIMIT3, jshl(1, jshl(LIMIT3, 1)));
  inline static int startStatus = {};
  inline static int endStatus = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  inline static int maxs = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AdjacentDifferent1() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    (maxs = jshl(1, jshl(m, 1)));
    for (int i = 0; (i < m); (i++)) {
      in.nextToken();
      (start[i] = static_cast<int>(in.nval));
    }
    for (int i = 0; (i < m); (i++)) {
      in.nextToken();
      (end[i] = static_cast<int>(in.nval));
    }
    if ((k == 2)) {
      out.println(Code03_AdjacentDifferent1::special());
    } else {
      out.println(Code03_AdjacentDifferent1::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int special() {
    if (((n & 1) == 0)) {
      for (int i = 0; (i < m); (i++)) {
        if ((start[i] == end[i])) {
          return 0;
        }
      }
    } else {
      for (int i = 0; (i < m); (i++)) {
        if ((start[i] != end[i])) {
          return 0;
        }
      }
    }
    return 1;
  }
  static int compute() {
    (startStatus = (endStatus = 0));
    for (int j = 0; (j < m); (j++)) {
      (startStatus = Code03_AdjacentDifferent1::set(startStatus, j, start[j]));
      (endStatus = Code03_AdjacentDifferent1::set(endStatus, j, end[j]));
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int s = 0; (s < maxs); (s++)) {
          (dp[i][j][s] = (-1));
        }
      }
    }
    return Code03_AdjacentDifferent1::f(1, 0, startStatus);
  }
  static int f(int i, int j, int s) {
    if ((i == (n - 1))) {
      return (Code03_AdjacentDifferent1::different(s, endStatus) ? 1 : 0);
    }
    if ((j == m)) {
      return Code03_AdjacentDifferent1::f((i + 1), 0, s);
    }
    if ((dp[i][j][s] != (-1))) {
      return dp[i][j][s];
    }
    int ans = 0;
    for (int color = 0; (color < k); (color++)) {
      if ((((j == 0) ||
            (Code03_AdjacentDifferent1::get(s, (j - 1)) != color)) &&
           (Code03_AdjacentDifferent1::get(s, j) != color))) {
        (ans = jrem((ans + Code03_AdjacentDifferent1::f(
                               i, (j + 1),
                               Code03_AdjacentDifferent1::set(s, j, color))),
                    MOD));
      }
    }
    (dp[i][j][s] = ans);
    return ans;
  }
  static bool different(int a, int b) {
    for (int j = 0; (j < m); (j++)) {
      if ([&]() {
            auto jleft = Code03_AdjacentDifferent1::get(a, j);
            auto jright = Code03_AdjacentDifferent1::get(b, j);
            return (jleft == jright);
          }()) {
        return false;
      }
    }
    return true;
  }
  static int get(int s, int j) { return (jshr(s, jshl(j, 1)) & 3); }
  static int set(int s, int j, int v) {
    return ((s & (~jshl(3, jshl(j, 1)))) | jshl(v, jshl(j, 1)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_AdjacentDifferent1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 相邻不同色的染色方法数(轮廓线dp)
// 给定两个参数n和m，表示n行m列的空白区域，一开始所有格子都没有颜色
// 给定参数k，表示有k种颜色，颜色编号0~k-1
// 你需要给每个格子染色，但是相邻的格子颜色不能相同
// 相邻包括上、下、左、右四个方向
// 并且给定了第0行和第n-1行的颜色状况，输入保证一定有效
// 那么你只能在1~n-2行上染色，返回染色的方法数，答案对376544743取模
// 2 <= k <= 4
// k = 2时，1 <= n <= 10^7，1 <= m <= 10^5
// 3 <= k <= 4时，1 <= n <= 100，1 <= m <= 8
// 测试链接 : https://www.luogu.com.cn/problem/P2435
// 提交以下的code，提交时请把类名改成"Main"
// 空间会不达标，在线测试无法全部通过，但逻辑正确
// 我运行了所有可能的情况，结果是正确的
        // 当前来到i行j列
        // i-1行中，[j..m-1]列的颜色状况，用s[j..m-1]号格子表示
        // i行中，[0..j-1]列的颜色状况，用s[0..j-1]号格子表示
        // s表示轮廓线的状况
        // 返回有几种染色方法
        // 颜色状况a和颜色状况b，是否每一格都不同
        // 在颜色状况s里，取出j号格的颜色
        // 颜色状况s中，把j号格的颜色设置成v，然后把新的s返回
*/
