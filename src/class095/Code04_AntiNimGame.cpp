// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4279

// Source: src/class095/Code04_AntiNimGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_AntiNimGame {
  inline static int MAXN = 51;
  inline static Array<int> stones = make_array<int>(MAXN);
  inline static int t = {};
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_AntiNimGame() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (t = static_cast<int>(in.nval));
    for (int i = 0; (i < t); (i++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      for (int j = 0; (j < n); (j++)) {
        in.nextToken();
        (stones[j] = static_cast<int>(in.nval));
      }
      out.println(Code04_AntiNimGame::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static String compute() {
    int eor = 0;
    int sum = 0;
    for (int i = 0; (i < n); (i++)) {
      (eor ^= stones[i]);
      (sum += ((stones[i] == 1) ? 1 : 0));
    }
    if ((sum == n)) {
      return (((n & 1) == 1) ? String(u"Brother") : String(u"John"));
    } else {
      return ((eor != 0) ? String(u"John") : String(u"Brother"));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_AntiNimGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 反尼姆博弈(反常游戏)
// 一共有n堆石头，两人轮流进行游戏
//
在每个玩家的回合中，玩家需要选择任何一个非空的石头堆，并从这堆石头中移除任意正数的石头数量
// 谁先拿走最后的石头就失败，返回最终谁会获胜
// 先手获胜，打印John
// 后手获胜，打印Brother
// 测试链接 : https://www.luogu.com.cn/problem/P4279
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
