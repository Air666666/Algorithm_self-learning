// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/AT_agc028_b
// https://atcoder.jp/contests/agc028/tasks/agc028_b

// Source: src/class151/Code06_RemovingBlocks.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_RemovingBlocks {
  inline static int MOD = 1000000007;
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> inv = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_RemovingBlocks() {}
  static void build() {
    (inv[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (inv[i] = static_cast<int>(
           (MOD -
            jrem((static_cast<i64>(inv[jrem(MOD, i)]) * jdiv(MOD, i)), MOD))));
    }
    for (int i = 1; (i <= n); (i++)) {
      (sum[i] = jrem((sum[(i - 1)] + inv[i]), MOD));
    }
  }
  static i64 compute() {
    Code06_RemovingBlocks::build();
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans =
           jrem((ans + (static_cast<i64>(((sum[i] + sum[((n - i) + 1)]) - 1)) *
                        arr[i])),
                MOD));
    }
    for (int i = 1; (i <= n); (i++)) {
      (ans = jrem((ans * i), MOD));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code06_RemovingBlocks::compute());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_RemovingBlocks::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 砖块消除
// 给定一个长度为n的数组arr，arr[i]为i号砖块的重量
// 选择一个没有消除的砖块进行消除，收益为被消除砖块联通区域的重量之和，比如arr =
{3,5,2,1}
// 如果先消除5，那么获得3+5+2+1的收益，arr = {3,X,2,1}
// 如果再消除1，那么获得2+1的收益，arr = {3,X,2,X}
// 如果再消除2，那么获得2的收益，arr = {3,X,X,X}
// 如果再消除3，那么获得3的收益，arr = {X,X,X,X}
// 一共有n!种消除方案，返回所有消除方案的收益总和，答案对 1000000007 取模
// 1 <= n <= 10^5    1 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/AT_agc028_b
// 测试链接 : https://atcoder.jp/contests/agc028/tasks/agc028_b
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所有数字
        // 连续数字逆元表
        // sum[i] = (1/1 + 1/2 + 1/3 + ... + 1/i)，%MOD意义下的余数
*/
