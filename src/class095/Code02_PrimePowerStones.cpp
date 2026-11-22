// Source: src/class095/Code02_PrimePowerStones.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_PrimePowerStones {
  inline static int t = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_PrimePowerStones() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    for (int i = 0; (i < t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      out.println(Code02_PrimePowerStones::compute(n));
    }
    out.flush();
    out.close();
    br.close();
  }
  static String compute(int n) {
    return ((jrem(n, 6) != 0) ? String(u"October wins!")
                              : String(u"Roy wins!"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_PrimePowerStones::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 质数次方版取石子(巴什博弈扩展)
// 一共有n颗石子，两个人轮流拿
// 每一轮当前选手可以拿 p的k次方 颗石子
// 当前选手可以随意决定p和k，但要保证p是质数、k是自然数
// 拿到最后一颗石子的人获胜
// 根据石子数返回谁赢
// 如果先手赢，返回"October wins!"
// 如果后手赢，输出"Roy wins!"
// 测试链接 : https://www.luogu.com.cn/problem/P4018
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
