// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4391

// Source: src/class101/Code01_RepeatMinimumLength.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_RepeatMinimumLength {
  inline static int MAXN = 1000001;
  inline static Array<int> next = make_array<int>(MAXN);
  inline static int n = {};
  inline static Array<jchar> s = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_RepeatMinimumLength() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    (n = std::stoi(text(in.readLine())));
    (s = in.readLine().toCharArray());
    out.println(Code01_RepeatMinimumLength::compute());
    out.flush();
    out.close();
    in.close();
  }
  static int compute() {
    Code01_RepeatMinimumLength::nextArray();
    return (n - next[n]);
  }
  static void nextArray() {
    (next[0] = (-1));
    (next[1] = 0);
    int i = 2;
    int cn = 0;
    while ((i <= n)) {
      if ((s[(i - 1)] == s[cn])) {
        (next[(i++)] = (++cn));
      } else if ((cn > 0)) {
        (cn = next[cn]);
      } else {
        (next[(i++)] = 0);
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_RepeatMinimumLength::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最短循环节的长度
// 给你一个字符串s，它一定是由某个循环节不断自我连接形成的
// 题目保证至少重复2次，但是最后一个循环节不一定完整
// 现在想知道s的最短循环节是多长
// 测试链接 : https://www.luogu.com.cn/problem/P4391
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
