// Source: src/class099/Code04_NumberOfSubsetGcdK.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_NumberOfSubsetGcdK {
  inline static int MOD = 1000000007;
  inline static int LIMIT = 100000;
  inline static Array<i64> dp = make_array<i64>((LIMIT + 1));
  inline static Array<i64> cnt = make_array<i64>((LIMIT + 1));
  inline static Array<i64> pow2 = make_array<i64>((LIMIT + 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_NumberOfSubsetGcdK() {}
  static void build() {
    (pow2[0] = 1);
    for (int i = 1; (i <= LIMIT); (i++)) {
      (pow2[i] = jrem((pow2[(i - 1)] * 2), MOD));
    }
  }
  static void java_main(Array<String> args) {
    Code04_NumberOfSubsetGcdK::build();
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (cnt[static_cast<int>(in.nval)]++);
      }
      out.println(Code04_NumberOfSubsetGcdK::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    for (int i = LIMIT; (i >= 1); (i--)) {
      i64 counts = 0;
      for (int j = i; (j <= LIMIT); (j += i)) {
        (counts += cnt[j]);
      }
      (dp[i] = jrem(((pow2[static_cast<int>(counts)] - 1) + MOD), MOD));
      for (int j = (2 * i); (j <= LIMIT); (j += i)) {
        (dp[i] = jrem(((dp[i] - dp[j]) + MOD), MOD));
      }
    }
    return dp[1];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_NumberOfSubsetGcdK::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最大公约数为1的子序列数量
// 给你一个数组，返回有多少个子序列的最大公约数是1
// 结果可能很大对1000000007取模
// 测试链接 : https://www.luogu.com.cn/problem/CF803F
// 测试链接 : https://codeforces.com/problemset/problem/803/F
// 1 <= n <= 10^5
// 1 <= nums[i] <= 10^5
// 扩展问题
// 最大公约数为k的子序列数量
// 给定一个长度为n的正数数组nums，还有正数k
// 返回有多少子序列的最大公约数为k
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 时间复杂度O(v * log v)
*/
