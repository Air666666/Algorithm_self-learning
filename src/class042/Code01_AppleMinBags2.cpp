// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/73e0552b78474a9086781e47f4e01d73

// Source: src/class042/Code01_AppleMinBags2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_AppleMinBags2 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_AppleMinBags2() {}
  static int bags2(int apple) {
    if (((apple & 1) != 0)) {
      return (-1);
    }
    if ((apple < 18)) {
      if ((apple == 0)) {
        return 0;
      }
      if (((apple == 6) || (apple == 8))) {
        return 1;
      }
      if ((((apple == 12) || (apple == 14)) || (apple == 16))) {
        return 2;
      }
      return (-1);
    }
    return (jdiv((apple - 18), 8) + 3);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    int n = in.nextInt();
    out.println(Code01_AppleMinBags2::bags2(n));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_AppleMinBags2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 感谢热心的同学，找到了题目1的在线测试
// 测试链接 : https://www.nowcoder.com/practice/73e0552b78474a9086781e47f4e01d73
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 最优解
        // 读写工具类
*/
