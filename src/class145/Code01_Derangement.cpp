// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1595

// Source: src/class145/Code01_Derangement.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Derangement {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Derangement() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    out.println(Code01_Derangement::ways2(n));
    out.flush();
    out.close();
    br.close();
  }
  static i64 ways1(int n) {
    Array<i64> dp = make_array<i64>((n + 1));
    for (int i = 1; (i <= n); (i++)) {
      if ((i == 1)) {
        (dp[i] = 0);
      } else if ((i == 2)) {
        (dp[i] = 1);
      } else {
        (dp[i] = ((i - 1) * (dp[(i - 1)] + dp[(i - 2)])));
      }
    }
    return dp[n];
  }
  static i64 ways2(int n) {
    i64 facn = 1;
    for (int i = 1; (i <= n); (i++)) {
      (facn *= i);
    }
    i64 ans = facn;
    i64 faci = 1;
    for (int i = 1; (i <= n); (i++)) {
      (faci = (faci * i));
      if (((i & 1) == 0)) {
        (ans += jdiv(facn, faci));
      } else {
        (ans -= jdiv(facn, faci));
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Derangement::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 信封问题(错排问题)
// 一共n个人，每个人都写了一封信
// 每个人必须寄出一封信，每个人必须收到一封信，并且不能自己寄给自己
// 返回一共有多少种寄信的方法
// 1 <= n <= 20
// 测试链接 : https://www.luogu.com.cn/problem/P1595
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // out.println(ways1(n));
        // 普通动态规划的方法
        // 二项式反演的方法
                        // i = 1...n
                        // (-1)的i次方 * (n! / i!)
*/
