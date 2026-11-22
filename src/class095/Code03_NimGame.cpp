// Source: src/class095/Code03_NimGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_NimGame {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_NimGame() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int t = static_cast<int>(in.nval);
    for (int i = 0; (i < t); (i++)) {
      in.nextToken();
      int n = static_cast<int>(in.nval);
      int eor = 0;
      for (int j = 0; (j < n); (j++)) {
        in.nextToken();
        (eor ^= static_cast<int>(in.nval));
      }
      if ((eor != 0)) {
        out.println(String(u"Yes"));
      } else {
        out.println(String(u"No"));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_NimGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 尼姆博弈(Nim Game)
// 一共有n堆石头，两人轮流进行游戏
//
在每个玩家的回合中，玩家需要选择任何一个非空的石头堆，并从这堆石头中移除任意正数的石头数量
// 谁先拿走最后的石头就获胜，返回最终谁会获胜
// 测试链接 : https://www.luogu.com.cn/problem/P2197
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
