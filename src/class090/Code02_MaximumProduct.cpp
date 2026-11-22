// Source: src/class090/Code02_MaximumProduct.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MaximumProduct {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MaximumProduct() {}
  static int maxValue1(int n, int k) { return Code02_MaximumProduct::f1(n, k); }
  static int f1(int rest, int k) {
    if ((k == 1)) {
      return rest;
    }
    int ans = std::numeric_limits<int>::min();
    for (int cur = 1; ((cur <= rest) && ((rest - cur) >= (k - 1))); (cur++)) {
      int curAns = (cur * Code02_MaximumProduct::f1((rest - cur), (k - 1)));
      (ans = jmax(ans, curAns));
    }
    return ans;
  }
  static int maxValue2(int n, int k) {
    int mod = 1000000007;
    i64 a = jdiv(n, k);
    int b = jrem(n, k);
    i64 part1 = Code02_MaximumProduct::power((a + 1), b, mod);
    i64 part2 = Code02_MaximumProduct::power(a, (k - b), mod);
    return jrem(static_cast<int>((part1 * part2)), mod);
  }
  static i64 power(i64 x, int n, int mod) {
    i64 ans = 1;
    while ((n > 0)) {
      if (((n & 1) == 1)) {
        (ans = jrem((ans * x), mod));
      }
      (x = jrem((x * x), mod));
      (n = jshr(n, 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 30;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      int k = (static_cast<int>((j::random() * n)) + 1);
      int ans1 = Code02_MaximumProduct::maxValue1(n, k);
      int ans2 = Code02_MaximumProduct::maxValue2(n, k);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了！"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MaximumProduct::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 分成k份的最大乘积
// 一个数字n一定要分成k份，得到的乘积尽量大是多少
// 数字n和k，可能非常大，到达10^12规模
// 结果可能更大，所以返回结果对 1000000007 取模
// 来自真实大厂笔试，没有在线测试，对数器验证
        // 暴力递归
        // 为了验证
        // 剩余的数字rest拆成k份
        // 返回最大乘积
        // 暴力尝试一定能得到最优解
        // 贪心的解
        // 这是最优解
        // 如果结果很大，那么求余数
        // 对数器
        // 为了验证
                                // 如果出错了
                                // 可以增加打印行为找到一组出错的例子
                                // 然后去debug
*/
