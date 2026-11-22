// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2627

// Source: src/class130/Code03_ChooseLimitMaximumSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ChooseLimitMaximumSum {
  inline static int MAXN = 100001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXN);
  inline static Array<int> queue = make_array<int>(MAXN);
  inline static int l = {};
  inline static int r = {};
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ChooseLimitMaximumSum() {}
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
      (arr[i] = static_cast<int>(in.nval));
    }
    out.println(Code03_ChooseLimitMaximumSum::compute());
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    for (int i = 1; (i <= n); (i++)) {
      (sum[i] = (sum[(i - 1)] + arr[i]));
    }
    (l = (r = 0));
    (queue[(r++)] = 0);
    for (int i = 1; (i <= n); (i++)) {
      while (((l < r) && [&]() {
        auto jleft = Code03_ChooseLimitMaximumSum::value(queue[(r - 1)]);
        auto jright = Code03_ChooseLimitMaximumSum::value(i);
        return (jleft <= jright);
      }())) {
        (r--);
      }
      (queue[(r++)] = i);
      if (((l < r) && (queue[l] == ((i - k) - 1)))) {
        (l++);
      }
      (dp[i] = (Code03_ChooseLimitMaximumSum::value(queue[l]) + sum[i]));
    }
    return dp[n];
  }
  static i64 value(int i) { return ((i == 0) ? 0 : (dp[(i - 1)] - sum[i])); }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_ChooseLimitMaximumSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 不超过连续k个元素的最大累加和
// 给定一个长度为n的数组arr，你可以随意选择数字
// 要求选择的方案中，连续选择的个数不能超过k个
// 返回能得到的最大累加和
// 1 <= n、k <= 10^5
// 0 <= arr[i] <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2627
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 不要i位置的数字产生的指标
*/
