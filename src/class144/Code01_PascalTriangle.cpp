// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5732

// Source: src/class144/Code01_PascalTriangle.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PascalTriangle {
  inline static int MAXN = 20;
  inline static Array<Array<i64>> tri = make_array<i64>(MAXN, MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PascalTriangle() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    for (int i = 0; (i < n); (i++)) {
      (tri[i][0] = (tri[i][i] = 1));
    }
    for (int i = 1; (i < n); (i++)) {
      for (int j = 1; (j < i); (j++)) {
        (tri[i][j] = (tri[(i - 1)][j] + tri[(i - 1)][(j - 1)]));
      }
    }
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j <= i); (j++)) {
        out.print((tri[i][j] + String(u" ")));
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_PascalTriangle::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 杨辉三角
// 给定数字n，打印杨辉三角的前n行
// 1 <= n <= 20
// 测试链接 : https://www.luogu.com.cn/problem/P5732
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
*/
