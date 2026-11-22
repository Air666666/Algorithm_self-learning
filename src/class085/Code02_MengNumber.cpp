// Source: src/class085/Code02_MengNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MengNumber {
  inline static int MOD = 1000000007;
  inline static int MAXN = 1001;
  inline static Array<Array<Array<Array<int>>>> dp =
      make_array<int>(MAXN, 11, 11, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MengNumber() {}
  static void build(int n) {
    for (int a = 0; (a < n); (a++)) {
      for (int b = 0; (b <= 10); (b++)) {
        for (int c = 0; (c <= 10); (c++)) {
          for (int d = 0; (d <= 1); (d++)) {
            (dp[a][b][c][d] = (-1));
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    Array<String> strs = br.readLine().split(String(u" "));
    out.println([&]() {
      auto jargument_0 = strs[0].toCharArray();
      auto jargument_1 = strs[1].toCharArray();
      return Code02_MengNumber::compute(jargument_0, jargument_1);
    }());
    out.flush();
    out.close();
    br.close();
  }
  static int compute(Array<jchar> l, Array<jchar> r) {
    int ans = jrem(([&]() {
                     auto jleft = Code02_MengNumber::cnt(r);
                     auto jright = Code02_MengNumber::cnt(l);
                     return (jleft - jright);
                   }() +
                    MOD),
                   MOD);
    if (Code02_MengNumber::check(l)) {
      (ans = jrem((ans + 1), MOD));
    }
    return ans;
  }
  static int cnt(Array<jchar> num) {
    if ((num[0] == u'0')) {
      return 0;
    }
    int n = num.length;
    i64 all = 0;
    i64 base = 1;
    for (int i = (n - 1); (i >= 0); (i--)) {
      (all = jrem((all + (base * (num[i] - u'0'))), MOD));
      (base = jrem((base * 10), MOD));
    }
    Code02_MengNumber::build(n);
    return static_cast<int>(
        jrem(((all - Code02_MengNumber::f(num, 0, 10, 10, 0)) + MOD), MOD));
  }
  static int f(Array<jchar> num, int i, int pp, int p, int free) {
    if ((i == num.length)) {
      return 1;
    }
    if ((dp[i][pp][p][free] != (-1))) {
      return dp[i][pp][p][free];
    }
    int ans = 0;
    if ((free == 0)) {
      if ((p == 10)) {
        (ans =
             jrem((ans + Code02_MengNumber::f(num, (i + 1), 10, 10, 1)), MOD));
        for (int cur = 1; (cur < (num[i] - u'0')); (cur++)) {
          (ans = jrem((ans + Code02_MengNumber::f(num, (i + 1), p, cur, 1)),
                      MOD));
        }
        (ans = jrem(
             (ans + Code02_MengNumber::f(num, (i + 1), p, (num[i] - u'0'), 0)),
             MOD));
      } else {
        for (int cur = 0; (cur < (num[i] - u'0')); (cur++)) {
          if (((pp != cur) && (p != cur))) {
            (ans = jrem((ans + Code02_MengNumber::f(num, (i + 1), p, cur, 1)),
                        MOD));
          }
        }
        if (((pp != (num[i] - u'0')) && (p != (num[i] - u'0')))) {
          (ans = jrem((ans + Code02_MengNumber::f(num, (i + 1), p,
                                                  (num[i] - u'0'), 0)),
                      MOD));
        }
      }
    } else {
      if ((p == 10)) {
        (ans =
             jrem((ans + Code02_MengNumber::f(num, (i + 1), 10, 10, 1)), MOD));
        for (int cur = 1; (cur <= 9); (cur++)) {
          (ans = jrem((ans + Code02_MengNumber::f(num, (i + 1), p, cur, 1)),
                      MOD));
        }
      } else {
        for (int cur = 0; (cur <= 9); (cur++)) {
          if (((pp != cur) && (p != cur))) {
            (ans = jrem((ans + Code02_MengNumber::f(num, (i + 1), p, cur, 1)),
                        MOD));
          }
        }
      }
    }
    (dp[i][pp][p][free] = ans);
    return ans;
  }
  static bool check(Array<jchar> num) {
    {
      int pp = (-2);
      int p = (-1);
      int i = 0;
      for (; (i < num.length); (pp++), (p++), (i++)) {
        if (((pp >= 0) && (num[pp] == num[i]))) {
          return true;
        }
        if (((p >= 0) && (num[p] == num[i]))) {
          return true;
        }
      }
    }
    return false;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MengNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 萌数
// 如果一个数字，存在长度至少为2的回文子串，那么这种数字被称为萌数
// 比如101、110、111、1234321、45568
// 求[l,r]范围上，有多少个萌数
// 由于答案可能很大，所以输出答案对1000000007求余
// 测试链接 : https://www.luogu.com.cn/problem/P3413
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 返回0~num范围上萌数有多少个
                        // 不理解的话看一下，讲解041-同余原理
        // 从num的高位开始，当前来到第i位
        //
前一位数字是p、前前一位数字是pp，如果值是10，则表示那一位没有选择过数字
        // 如果之前的位已经确定比num小，那么free ==
1，表示接下的数字可以自由选择
        // 如果之前的位和num一样，那么free ==
0，表示接下的数字不能大于num当前位的数字
        // 返回<=num且不是萌数的数字有多少个
                                // 当前来到的就是num的最高位
                                // free ==
0，之前和num一样，此时不能自由选择数字
                                // 前一位p，选择过数字，p -> 0 ~ 9
                                // free == 1，能自由选择数字
                                // 从来没选过数字
                                // free == 1，能自由选择数字
                                // 之前选择过数字
*/
