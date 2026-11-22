// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4859

// Source: src/class145/Code04_NothingFear.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_NothingFear {
  inline static int MAXN = 2001;
  inline static int MOD = 1000000009;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<i64> fac = make_array<i64>(MAXN);
  inline static Array<Array<i64>> c = make_array<i64>(MAXN, MAXN);
  inline static Array<i64> small = make_array<i64>(MAXN);
  inline static Array<Array<i64>> dp = make_array<i64>(MAXN, MAXN);
  inline static Array<i64> g = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_NothingFear() {}
  static void build() {
    (fac[0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (fac[i] = jrem((fac[(i - 1)] * i), MOD));
    }
    for (int i = 0; (i <= n); (i++)) {
      (c[i][0] = 1);
      for (int j = 1; (j <= i); (j++)) {
        (c[i][j] = jrem((c[(i - 1)][j] + c[(i - 1)][(j - 1)]), MOD));
      }
    }
  }
  static i64 compute() {
    Code04_NothingFear::build();
    j::sort(a, 1, (n + 1));
    j::sort(b, 1, (n + 1));
    {
      int i = 1;
      int cnt = 0;
      for (; (i <= n); (i++)) {
        while ((((cnt + 1) <= n) && (b[(cnt + 1)] < a[i]))) {
          (cnt++);
        }
        (small[i] = cnt);
      }
    }
    (dp[0][0] = 1);
    for (int i = 1; (i <= n); (i++)) {
      (dp[i][0] = dp[(i - 1)][0]);
      for (int j = 1; (j <= i); (j++)) {
        (dp[i][j] =
             jrem((dp[(i - 1)][j] +
                   jrem((dp[(i - 1)][(j - 1)] * ((small[i] - j) + 1)), MOD)),
                  MOD));
      }
    }
    for (int i = 0; (i <= n); (i++)) {
      (g[i] = jrem((fac[(n - i)] * dp[n][i]), MOD));
    }
    i64 ans = 0;
    for (int i = k; (i <= n); (i++)) {
      if ((((i - k) & 1) == 0)) {
        (ans = jrem((ans + jrem((c[i][k] * g[i]), MOD)), MOD));
      } else {
        (ans =
             jrem((ans + jrem((jrem((c[i][k] * g[i]), MOD) * (MOD - 1)), MOD)),
                  MOD));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (a[i] = static_cast<int>(in.nval));
    }
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (b[i] = static_cast<int>(in.nval));
    }
    if ((((n + k) & 1) == 0)) {
      (k = jdiv((n + k), 2));
      out.println(Code04_NothingFear::compute());
    } else {
      out.println(0);
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_NothingFear::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 已经没有什么好害怕的了
// 给定两个长度为n的数组，a[i]表示第i个糖果的能量，b[i]表示第i个药片的能量
// 所有能量数值都不相同，每一个糖果要选一个药片进行配对
// 如果配对之后，糖果能量 > 药片能量，称为糖果大的配对
// 如果配对之后，糖果能量 < 药片能量，称为药片大的配对
// 希望做到，糖果大的配对数量 = 药片大的配对数量 + k
// 返回配对方法数，答案对 1000000009 取模
// 举例，a = [5, 35, 15, 45]，b = [40, 20, 10, 30]，k =
2，返回4，因为有4种配对方法
// (5-40，35-20，15-10，45-30)、(5-40，35-30，15-10，45-20)
// (5-20，35-30，15-10，45-40)、(5-30，35-20，15-10，45-40)
// 1 <= n <= 2000
// 0 <= k <= n
// 测试链接 : https://www.luogu.com.cn/problem/P4859
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                                // -1 和 (MOD-1) 同余
*/
