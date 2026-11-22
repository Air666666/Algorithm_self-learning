// Source: src/class147/Code05_FunnySequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_FunnySequence {
  inline static int MAXN = 2000001;
  inline static Array<int> minpf = make_array<int>(MAXN);
  inline static Array<int> prime = make_array<int>(MAXN);
  inline static int cnt = {};
  inline static Array<int> counts = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_FunnySequence() {}
  static void euler(int n) {
    j::fill(minpf, 2, n, 0);
    (cnt = 0);
    for (int i = 2; (i <= n); (i++)) {
      if ((minpf[i] == 0)) {
        (prime[(cnt++)] = i);
      }
      for (int j = 0; (j < cnt); (j++)) {
        if (((i * prime[j]) > n)) {
          break;
        }
        (minpf[(i * prime[j])] = prime[j]);
        if ((jrem(i, prime[j]) == 0)) {
          break;
        }
      }
    }
  }
  static i64 power(i64 x, i64 p, int mod) {
    i64 ans = 1;
    while ((p > 0)) {
      if (((p & 1) == 1)) {
        (ans = jrem((ans * x), mod));
      }
      (x = jrem((x * x), mod));
      (p = jshr(p, 1));
    }
    return ans;
  }
  static int compute(int n, int mod) {
    Code05_FunnySequence::euler((2 * n));
    j::fill(counts, 2, (n + 1), (-1));
    j::fill(counts, (n + 2), ((2 * n) + 1), 1);
    for (int i = (2 * n); (i >= 2); (i--)) {
      if ((minpf[i] != 0)) {
        (counts[minpf[i]] += counts[i]);
        (counts[jdiv(i, minpf[i])] += counts[i]);
        (counts[i] = 0);
      }
    }
    i64 ans = 1;
    for (int i = 2; (i <= (2 * n)); (i++)) {
      if ((counts[i] != 0)) {
        (ans =
             jrem((ans * Code05_FunnySequence::power(i, counts[i], mod)), mod));
      }
    }
    return static_cast<int>(ans);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int mod = static_cast<int>(in.nval);
    out.println(Code05_FunnySequence::compute(n, mod));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_FunnySequence::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 有趣的数列(重要! 因子计数法)
// 求第n项卡特兰数，要求答案对p取模
// 1 <= n <= 10^6
// 1 <= p <= 10^9
// p可能不为质数
// 测试链接 : https://www.luogu.com.cn/problem/P3200
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 如果minpf[i] == 0，代表i是质数
        // 如果minpf[i] != 0，代表i是合数，并且最小质因子是minpf[i]
        // 质数表
        // 质数表大小
        // 因子计数
        // 来自讲解097，欧拉筛，时间复杂度O(n)
                        // minpf[i] == 0代表i为质数，收集进质数表
                        // minpf数组替代了讲解097中visit数组的作用
                                // 此时收集(i *
prime[j])这个数的最小质因子为prime[j]
                                // minpf[i * prime[j]] != 0，也标记了(i *
prime[j])是合数
                                //
讲解097欧拉筛的部分，重点解释了这个过程，看完必懂
        // 使用的是公式2 + 质因子计数法
                // 利用欧拉筛生成[2 ~ 2*n]范围上所有数的最小质因子
                // 如果x为质数，minpf[x] == 0
                // 如果x为合数，x的最小质因子为minpf[x]
                // 分母每个因子设置计数
                // 分子每个因子设置计数
                // 从大到小的每个数统计计数
                // 合数根据最小质因子来分解，变成更小数字的计数
                // 质数无法分解，计数确定，最后快速幂计算乘积
                // 每个质数的幂，都乘起来，就是最后答案
*/
