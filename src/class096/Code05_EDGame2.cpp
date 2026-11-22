// Source: src/class096/Code05_EDGame2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_EDGame2 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_EDGame2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int t = static_cast<int>(in.nval);
    for (int i = 0; (i < t); (i++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      int sg = 0;
      {
        int j = 1;
        int a = {};
        int b = {};
        for (; (j <= n); (j += 2)) {
          in.nextToken();
          (a = static_cast<int>(in.nval));
          in.nextToken();
          (b = static_cast<int>(in.nval));
          (sg ^= Code05_EDGame2::lowZero(((a - 1) | (b - 1))));
        }
      }
      if ((sg != 0)) {
        out.println(String(u"YES"));
      } else {
        out.println(String(u"NO"));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
  static int lowZero(int status) {
    int ans = 0;
    while ((status > 0)) {
      if (((status & 1) == 0)) {
        break;
      }
      (status = jshr(status, 1));
      (ans++);
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_EDGame2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// E&D游戏
// 桌子上有2n堆石子，编号为1、2、3...2n
// 其中1、2为一组；3、4为一组；5、6为一组...2n-1、2n为一组
// 每组可以进行分割操作：
// 任取一堆石子，将其移走，然后分割同一组的另一堆石子
// 从中取出若干个石子放在被移走的位置，组成新的一堆
// 操作完成后，组内每堆的石子数必须保证大于0
// 显然，被分割的一堆的石子数至少要为2
//
两个人轮流进行分割操作，如果轮到某人进行操作时，所有堆的石子数均为1，判此人输掉比赛
// 返回先手能不能获胜
// 测试链接 : https://www.luogu.com.cn/problem/P2148
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
