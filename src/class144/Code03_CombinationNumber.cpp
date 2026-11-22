// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2822

// Source: src/class144/Code03_CombinationNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CombinationNumber {
  inline static int MAXV = 2000;
  inline static int MAXN = 2002;
  inline static Array<Array<int>> c = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> f = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> sum = make_array<int>(MAXN, MAXN);
  inline static int t = {};
  inline static int k = {};
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CombinationNumber() {}
  static void build() {
    for (int i = 0; (i <= MAXV); (i++)) {
      (c[i][0] = 1);
      for (int j = 1; (j <= i); (j++)) {
        (c[i][j] = jrem((c[(i - 1)][j] + c[(i - 1)][(j - 1)]), k));
      }
    }
    for (int i = 1; (i <= MAXV); (i++)) {
      for (int j = 1; (j <= i); (j++)) {
        (f[i][j] = ((jrem(c[i][j], k) == 0) ? 1 : 0));
      }
    }
    for (int i = 2; (i <= MAXV); (i++)) {
      for (int j = 1; (j <= i); (j++)) {
        (sum[i][j] =
             (((sum[i][(j - 1)] + sum[(i - 1)][j]) - sum[(i - 1)][(j - 1)]) +
              f[i][j]));
      }
      (sum[i][(i + 1)] = sum[i][i]);
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    Code03_CombinationNumber::build();
    for (int i = 1; (i <= t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      if ((m > n)) {
        out.println(sum[n][n]);
      } else {
        out.println(sum[n][m]);
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_CombinationNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 组合数问题
// 组合公式c(i, j)，表示从i个物品中选出j个物品的方案数
// 如果该数值是k的整数倍，那么称(i, j)是一个合法对
// 给定具体的一组数字n和m，当i和j满足：0 <= i <= n，0 <= j <= min(i, m)
// 返回有多少合法对
// 一共有t组测试，所有测试的k都为同一个值
// 每组测试给定n和m，打印每组测试的答案
// 1 <= t <= 10^4
// 2 <= k <= 21
// 0 <= n、m <= 2000
// 测试链接 : https://www.luogu.com.cn/problem/P2822
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
