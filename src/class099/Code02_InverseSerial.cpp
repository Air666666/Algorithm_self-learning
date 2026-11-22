// Source: src/class099/Code02_InverseSerial.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_InverseSerial {
  inline static int MAXN = 3000001;
  inline static Array<int> inv = make_array<int>(MAXN);
  inline static int n = {};
  inline static int p = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_InverseSerial() {}
  static void build(int n) {
    (inv[1] = 1);
    for (int i = 2; (i <= n); (i++)) {
      (inv[i] = static_cast<int>(
           (p - jrem((static_cast<i64>(inv[jrem(p, i)]) * jdiv(p, i)), p))));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(jout);
    (n = in.readInt());
    (p = in.readInt());
    Code02_InverseSerial::build(n);
    for (int i = 1; (i <= n); (i++)) {
      out.println(inv[i]);
    }
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_InverseSerial::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 连续数字逆元的线性递推
// 给定n、p，求1∼n中所有整数在模p意义下的乘法逆元
// 1 <= n <= 3 * 10^6
// n < p < 20000528
// 输入保证p为质数
// 测试链接 : https://www.luogu.com.cn/problem/P3811
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 如下代码可以通过全部测试用例
// 但是这个题卡常数比较严重
// 一般情况下不会如此卡常数
// 需要使用快读、快写增加IO效率
        // 快读
        // 快写
*/
