// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2657

// Source: src/class085/Code01_WindyNumber.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_WindyNumber {
  inline static int MAXLEN = 11;
  inline static Array<Array<Array<int>>> dp = make_array<int>(MAXLEN, 11, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_WindyNumber() {}
  static void build(int len) {
    for (int i = 0; (i <= len); (i++)) {
      for (int j = 0; (j <= 10); (j++)) {
        (dp[i][j][0] = (-1));
        (dp[i][j][1] = (-1));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int a = static_cast<int>(in.nval);
      in.nextToken();
      int b = static_cast<int>(in.nval);
      out.println(Code01_WindyNumber::compute(a, b));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute(int a, int b) {
    return [&]() {
      auto jleft = Code01_WindyNumber::cnt(b);
      auto jright = Code01_WindyNumber::cnt((a - 1));
      return (jleft - jright);
    }();
  }
  static int cnt(int num) {
    if ((num == 0)) {
      return 1;
    }
    int len = 1;
    int offset = 1;
    int tmp = jdiv(num, 10);
    while ((tmp > 0)) {
      (len++);
      (offset *= 10);
      (tmp /= 10);
    }
    Code01_WindyNumber::build(len);
    return Code01_WindyNumber::f(num, offset, len, 10, 0);
  }
  static int f(int num, int offset, int len, int pre, int free) {
    if ((len == 0)) {
      return 1;
    }
    if ((dp[len][pre][free] != (-1))) {
      return dp[len][pre][free];
    }
    int cur = jrem(jdiv(num, offset), 10);
    int ans = 0;
    if ((free == 0)) {
      if ((pre == 10)) {
        (ans += Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), 10, 1));
        for (int i = 1; (i < cur); (i++)) {
          (ans +=
           Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), i, 1));
        }
        (ans +=
         Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), cur, 0));
      } else {
        for (int i = 0; (i <= 9); (i++)) {
          if (((i <= (pre - 2)) || (i >= (pre + 2)))) {
            if ((i < cur)) {
              (ans +=
               Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), i, 1));
            } else if ((i == cur)) {
              (ans +=
               Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), cur, 0));
            }
          }
        }
      }
    } else {
      if ((pre == 10)) {
        (ans += Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), 10, 1));
        for (int i = 1; (i <= 9); (i++)) {
          (ans +=
           Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), i, 1));
        }
      } else {
        for (int i = 0; (i <= 9); (i++)) {
          if (((i <= (pre - 2)) || (i >= (pre + 2)))) {
            (ans +=
             Code01_WindyNumber::f(num, jdiv(offset, 10), (len - 1), i, 1));
          }
        }
      }
    }
    (dp[len][pre][free] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_WindyNumber::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// windy数
// 不含前导零且相邻两个数字之差至少为2的正整数被称为windy数
// windy想知道[a,b]范围上总共有多少个windy数
// 测试链接 : https://www.luogu.com.cn/problem/P2657
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 求0~num范围上，windy数的个数
        // offset完全由len决定，为了方便提取num中某一位数字（上节课内容）
        // 从num的高位开始，还剩下len位没有决定
        // 前一位的数字是pre，如果pre == 10，表示从来没有选择过数字
        // 如果之前的位已经确定比num小，那么free ==
1，表示接下的数字可以自由选择
        // 如果之前的位和num一样，那么free ==
0，表示接下的数字不能大于num当前位的数字
        // 返回<=num的windy数有多少个
                                // 之前的位和num一样，此时不能随意选择数字
                                // 也从来没有选择过数字
                                // 就表示：来到的是num的最高位
                                // 之前的位和num一样，此时不能随意选择数字，
                                // 之前选择过数字pre
                                // free == 1，可以自由选择数字，前面的状况 < num
                                // 从来没有选择过数字
                                // free == 1，可以自由选择数字，前面的状况 < num
                                // 选择过数字pre
*/
