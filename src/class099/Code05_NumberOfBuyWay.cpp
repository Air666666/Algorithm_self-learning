// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1450

// Source: src/class099/Code05_NumberOfBuyWay.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_NumberOfBuyWay {
  inline static int LIMIT = 100000;
  inline static Array<i64> dp = make_array<i64>((LIMIT + 1));
  inline static Array<int> value = make_array<int>(4);
  inline static Array<int> cnt = make_array<int>(4);
  inline static int n = {};
  inline static int s = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_NumberOfBuyWay() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (value[0] = static_cast<int>(in.nval));
      in.nextToken();
      (value[1] = static_cast<int>(in.nval));
      in.nextToken();
      (value[2] = static_cast<int>(in.nval));
      in.nextToken();
      (value[3] = static_cast<int>(in.nval));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      Code05_NumberOfBuyWay::build();
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (cnt[0] = static_cast<int>(in.nval));
        in.nextToken();
        (cnt[1] = static_cast<int>(in.nval));
        in.nextToken();
        (cnt[2] = static_cast<int>(in.nval));
        in.nextToken();
        (cnt[3] = static_cast<int>(in.nval));
        in.nextToken();
        (s = static_cast<int>(in.nval));
        out.println(Code05_NumberOfBuyWay::query());
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static void build() {
    (dp[0] = 1);
    for (int i = 0; (i <= 3); (i++)) {
      for (int j = value[i]; (j <= LIMIT); (j++)) {
        (dp[j] += dp[(j - value[i])]);
      }
    }
  }
  static i64 query() {
    i64 illegal = 0;
    for (int status = 1; (status <= 15); (status++)) {
      i64 t = s;
      int sign = (-1);
      for (int j = 0; (j <= 3); (j++)) {
        if (((jshr(status, j) & 1) == 1)) {
          (t -= (value[j] * (cnt[j] + 1)));
          (sign = (-sign));
        }
      }
      if ((t >= 0)) {
        (illegal += (dp[static_cast<int>(t)] * sign));
      }
    }
    return (dp[s] - illegal);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_NumberOfBuyWay::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 多次查询购买方法
// 一共有4种硬币，面值分别为v0、v1、v2、v3，这个永远是确定的
// 每次去购物的细节由一个数组arr来表示，每次购物都是一次查询
// arr[0] = 携带v0面值的硬币数量
// arr[1] = 携带v1面值的硬币数量
// arr[2] = 携带v2面值的硬币数量
// arr[3] = 携带v3面值的硬币数量
// arr[4] = 本次购物一定要花多少钱
// 返回每次有多少种花钱的方法
// 1 <= v0、v1、v2、v3、arr[i] <= 10^5
// 查询数量 <= 1000
// 测试链接 : https://www.luogu.com.cn/problem/P1450
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // dp表就是查询系统
        // dp[i]表示当所有硬币无限制的情况下，花掉i元，方法数是多少
                        // 总体时间复杂度O(LIMIT + 查询次数)
                                // query时间复杂度O(1)
        // 时间复杂度O(LIMIT)
        // 最基本的完全背包问题 + 空间压缩
        // 完全背包在讲解074，不会的同学看一下
        // 时间复杂度O(15 * 4) -> O(1)
                // status -> 0001到1111
                        // 遇到奇数个1，sigh变成1
                        // 遇到偶数个1，sigh变成-1
*/
