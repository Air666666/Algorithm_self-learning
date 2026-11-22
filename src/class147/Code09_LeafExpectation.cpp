// Source: src/class147/Code09_LeafExpectation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_LeafExpectation {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_LeafExpectation() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    double n = in.nval;
    out.printf(String(u"%.9f"), jdiv((n * (n + 1)), (((2 * n) - 1) * 2)));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_LeafExpectation::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 叶子节点数的期望
// 一共有n个节点，认为节点之间无差别，能形成很多不同结构的二叉树
// 假设所有不同结构的二叉树，等概率出现一棵，返回叶子节点的期望
// 1 <= n <= 10^9
// 答案误差小于10的-9次方
// 测试链接 : https://www.luogu.com.cn/problem/P3978
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
