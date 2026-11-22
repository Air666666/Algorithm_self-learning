// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1025

// Source: src/class128/Code01_SplitNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_SplitNumber {
  inline static int MAXN = 201;
  inline static int MAXK = 7;
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXK);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_SplitNumber() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int m = static_cast<int>(in.nval);
    in.nextToken();
    int n = static_cast<int>(in.nval);
    out.println(Code01_SplitNumber::compute(m, n));
    out.flush();
    out.close();
    br.close();
  }
  static int compute(int m, int n) {
    if ((m < n)) {
      return 0;
    }
    if ((m == n)) {
      return 1;
    }
    (m -= n);
    for (int i = 0; (i <= m); (i++)) {
      for (int j = 0; (j <= n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code01_SplitNumber::f(m, n);
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
      (ans = Code01_SplitNumber::f(m, m));
    } else {
      (ans = [&]() {
        auto jleft = Code01_SplitNumber::f(m, (n - 1));
        auto jright = Code01_SplitNumber::f((m - n), n);
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
  Code01_SplitNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 数的划分方法
// 将整数m分成n份，且每份不能为空，任意两个方案不相同(不考虑顺序)
// 比如，m=7、n=3，那么(1, 1, 5) (1, 5, 1) (5, 1, 1)认为是同一种方法
// 返回有多少种不同的划分方法
// 测试链接 : https://www.luogu.com.cn/problem/P1025
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
*/
