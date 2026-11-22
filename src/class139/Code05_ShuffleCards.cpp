// Source: src/class139/Code05_ShuffleCards.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ShuffleCards {
  inline static i64 d = {};
  inline static i64 x = {};
  inline static i64 y = {};
  inline static i64 px = {};
  inline static i64 py = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ShuffleCards() {}
  static void exgcd(i64 a, i64 b) {
    if ((b == 0)) {
      (d = a);
      (x = 1);
      (y = 0);
    } else {
      Code05_ShuffleCards::exgcd(b, jrem(a, b));
      (px = x);
      (py = y);
      (x = py);
      (y = (px - (py * jdiv(a, b))));
    }
  }
  static i64 multiply(i64 a, i64 b, i64 mod) {
    (a = jrem((jrem(a, mod) + mod), mod));
    (b = jrem((jrem(b, mod) + mod), mod));
    i64 ans = 0;
    while ((b != 0)) {
      if (((b & 1) != 0)) {
        (ans = jrem((ans + a), mod));
      }
      (a = jrem((a + a), mod));
      (b = jshr(b, 1));
    }
    return ans;
  }
  static i64 power(i64 a, i64 b, i64 mod) {
    i64 ans = 1;
    while ((b > 0)) {
      if (((b & 1) == 1)) {
        (ans = Code05_ShuffleCards::multiply(ans, a, mod));
      }
      (a = Code05_ShuffleCards::multiply(a, a, mod));
      (b = jshr(b, 1));
    }
    return ans;
  }
  static i64 compute(i64 n, i64 m, i64 l) {
    i64 mod = (n + 1);
    Code05_ShuffleCards::exgcd(Code05_ShuffleCards::power(2, m, mod), mod);
    i64 x0 = jrem((jrem(x, mod) + mod), mod);
    return Code05_ShuffleCards::multiply(x0, l, mod);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    i64 n = static_cast<i64>(in.nval);
    in.nextToken();
    i64 m = static_cast<i64>(in.nval);
    in.nextToken();
    i64 l = static_cast<i64>(in.nval);
    out.println(Code05_ShuffleCards::compute(n, m, l));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_ShuffleCards::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 洗牌
// 一共有n张牌，n一定是偶数，每张牌的牌面从1到n，洗牌规则如下
// 比如n = 6，牌面最初排列为1 2 3 4 5 6
// 先分成左堆1 2 3，右堆4 5
6，然后按照右堆第i张在前，左堆第i张在后的方式依次放置
// 所以洗一次后，得到 4 1 5 2 6 3
// 如果再洗一次，得到 2 4 6 1 3 5
// 如果再洗一次，得到 1 2 3 4 5 6
// 想知道n张牌洗m次的之后，第l张牌，是什么牌面
// 1 <= n <= 10^10，n为偶数
// 0 <= m <= 10^10
// 测试链接 : https://www.luogu.com.cn/problem/P2054
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 扩展欧几里得算法
        // 原理来自，讲解033，位运算实现乘法
        // a * b的过程自己实现，每一个中间过程都%mod
        // 这么写目的是防止溢出，也叫龟速乘
                // 既然是在%mod的意义下，那么a和b可以都转化成非负的
                // 本题不转化无所谓，但是其他题目可能需要转化
                // 尤其是b需要转化，否则while循环会跑不完
        // 原理来自，讲解098，乘法快速幂
        // 计算a的b次方，最终 % mod 的结果
*/
