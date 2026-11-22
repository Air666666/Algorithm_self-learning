// Source: src/class146/Code03_Joseph.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Joseph {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Joseph() {}
  static int compute(int n, int k) {
    int ans = 1;
    for (int c = 2; (c <= n); (c++)) {
      (ans = (jrem(((ans + k) - 1), c) + 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int k = static_cast<int>(in.nval);
    out.println(Code03_Joseph::compute(n, k));
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Joseph::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 约瑟夫环问题
// 一共有1~n这些点，组成首尾相接的环
// 从1号点从数字1开始报数，哪个节点报到数字k，就删除该节点
// 然后下一个节点从数字1开始重新报数，最终环上会剩下一个节点
// 返回该节点的编号
// 1 <= n, k <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8671
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
