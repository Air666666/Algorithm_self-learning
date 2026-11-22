// Source: src/class143/Code05_Knapsack.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Knapsack {
  inline static int MAXN = 100001;
  inline static i64 inf = std::numeric_limits<i64>::min();
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  inline static int x = {};
  inline static int y = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Knapsack() {}
  static int gcd(int a, int b) {
    return ((b == 0) ? a : Code05_Knapsack::gcd(b, jrem(a, b)));
  }
  static void compute() {
    j::fill(dp, 0, x, inf);
    (dp[0] = 0);
    for (int i = 1; (i <= n); (i++)) {
      if ((v[i] != x)) {
        {
          int j = 0;
          int d = Code05_Knapsack::gcd(v[i], x);
          for (; (j < d); (j++)) {
            {
              int cur = j;
              int next = {};
              int circle = 0;
              for (; (circle < 2); (circle += ((cur == j) ? 1 : 0))) {
                (next = jrem((cur + v[i]), x));
                if ((dp[cur] != inf)) {
                  (dp[next] =
                       jmax(dp[next],
                            ((dp[cur] -
                              (static_cast<i64>(jdiv((cur + v[i]), x)) * y)) +
                             c[i])));
                }
                (cur = next);
              }
            }
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    double best = 0;
    double ratio = {};
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (v[i] = static_cast<int>(in.nval));
      in.nextToken();
      (c[i] = static_cast<int>(in.nval));
      (ratio = jdiv(static_cast<double>(c[i]), v[i]));
      if ((ratio > best)) {
        (best = ratio);
        (x = v[i]);
        (y = c[i]);
      }
    }
    Code05_Knapsack::compute();
    i64 jobv = {};
    {
      int i = 1;
      int v = {};
      for (; (i <= m); (i++)) {
        in.nextToken();
        (jobv = static_cast<i64>(in.nval));
        (v = static_cast<int>(jrem(jobv, x)));
        if ((dp[v] == inf)) {
          out.println(String(u"-1"));
        } else {
          out.println(((jdiv(jobv, x) * y) + dp[v]));
        }
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
  Code05_Knapsack::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 背包(两次转圈法)
//
一共有n种物品，第i种物品的体积为v[i]，价值为c[i]，每种物品可以选择任意个，个数不能是负数
// 一共有m条查询，每次查询都会给定jobv，代表体积的要求
// 要求挑选物品的体积和一定要严格是jobv，返回能得到的最大价值和
// 如果没有方案能正好凑满jobv，返回-1
// 1 <= n <= 50
// 1 <= m <= 10^5
// 1 <= v[i] <= 10^5
// 1 <= c[i] <= 10^6
// 10^11 <= jobv <= 10^12
// 测试链接 : https://www.luogu.com.cn/problem/P9140
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // dp[i] : 总体积为某数，先尽可能用基准物品填入，剩余的体积为i
        // 可以去掉若干基准物品，加入若干其他物品，最终凑齐总体积
        // 能获得的最大补偿是多少
*/
