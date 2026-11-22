// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2252

// Source: src/class095/Code06_WythoffGame.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_WythoffGame {
  inline static BigDecimal split = BigDecimal(String(u"1.61803398874989484"));
  inline static int a = {};
  inline static int b = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_WythoffGame() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (a = static_cast<int>(in.nval));
      in.nextToken();
      (b = static_cast<int>(in.nval));
      out.println(Code06_WythoffGame::compute());
      out.flush();
    }
    out.close();
    br.close();
  }
  static int compute() {
    int min = jmin(a, b);
    int max = jmax(a, b);
    if ((min != split.multiply(BigDecimal((max - min))).intValue())) {
      return 1;
    } else {
      return 0;
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_WythoffGame::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 威佐夫博弈(Wythoff Game)
// 有两堆石子，数量任意，可以不同，游戏开始由两个人轮流取石子
// 游戏规定，每次有两种不同的取法
// 1) 在任意的一堆中取走任意多的石子
// 2) 可以在两堆中同时取走相同数量的石子
// 最后把石子全部取完者为胜者
// 现在给出初始的两堆石子的数目，返回先手能不能获胜
// 测试链接 : https://www.luogu.com.cn/problem/P2252
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 黄金分割比例
        // 洛谷在2024年5月增加了测试数据
        // 需要更高精度的黄金比例 + 更高精度的乘法，才能全部通过
        // 增加的测试用例有刻意为难的嫌疑，其实没啥意思
        // Java就用BigDecimal类型支持高精度，C++同学可以用long double类型
                // 威佐夫博弈
                // 小 != (大 - 小) * 黄金分割比例，先手赢
                // 小 == (大 - 小) * 黄金分割比例，后手赢
                // 要向下取整
                //
这里用BigDecimal类型的multiply方法，乘完后再转成整型，可以支持高精度的乘
*/
