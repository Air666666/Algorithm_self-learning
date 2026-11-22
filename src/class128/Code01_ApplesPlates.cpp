// Source: src/class128/Code01_ApplesPlates.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ApplesPlates {
  inline static int MAXM = 11;
  inline static int MAXN = 11;
  inline static Array<Array<int>> dp = make_array<int>(MAXM, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ApplesPlates() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int n = static_cast<int>(in.nval);
    out.println(Code01_ApplesPlates::compute(m, n));
    out.flush();
    out.close();
    br.close();
  }
  static int compute(int m, int n) {
    for (int i = 0; (i <= m); (i++)) {
      for (int j = 0; (j <= n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code01_ApplesPlates::f(m, n);
  }
  static int f(int m, int n) {
    if ((m == 0)) {
      return 1;
    }
    if ((n == 0)) {
      return 0;
    }
    if ((dp[m][n] != (-1))) {
      return dp[m][n];
    }
    int ans = {};
    if ((n > m)) {
      (ans = Code01_ApplesPlates::f(m, m));
    } else {
      (ans = [&]() {
        auto jleft = Code01_ApplesPlates::f(m, (n - 1));
        auto jright = Code01_ApplesPlates::f((m - n), n);
        return (jleft + jright);
      }());
    }
    (dp[m][n] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ApplesPlates::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 苹果和盘子
// 有m个苹果，认为苹果之间无差别，有n个盘子，认为盘子之间无差别
// 比如5个苹果如果放进3个盘子，那么(1, 3, 1) (1, 1, 3) (3, 1, 1)认为是同一种方法
// 允许有些盘子是空的，返回有多少种放置方法
// 测试链接 : https://www.nowcoder.com/practice/bfd8234bb5e84be0b493656e390bdebf
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/
