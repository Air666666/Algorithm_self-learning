// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2532

// Source: src/class147/Code08_TreehouseLadder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_TreehouseLadder {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_TreehouseLadder() {}
  static BigInteger compute(int n) {
    BigInteger a = BigInteger(String(u"1"));
    BigInteger b = BigInteger(String(u"1"));
    BigInteger cur = {};
    for (int i = 1; (i <= (2 * n)); (i++)) {
      (cur = BigInteger(j::str(i)));
      (a = a.multiply(cur));
      if ((i <= n)) {
        (b = b.multiply(cur));
      }
    }
    return a.divide(b.multiply(b)).divide(BigInteger(j::str((n + 1))));
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    BigInteger ans = Code08_TreehouseLadder::compute(n);
    out.println(ans.toString());
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_TreehouseLadder::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 树屋阶梯
// 地面高度是0，想搭建一个阶梯，要求每一个台阶上升1的高度，最终到达高度n
// 有无穷多任意规格的矩形材料，但是必须选择n个矩形，希望能搭建出阶梯的样子
// 返回搭建阶梯的不同方法数，答案可能很大，不取模！就打印真实答案
// 1 <= n <= 500
// 测试链接 : https://www.luogu.com.cn/problem/P2532
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 这里用公式2
        // java同学使用BigInteger即可
        // C++同学需要自己实现高精度乘法
*/
