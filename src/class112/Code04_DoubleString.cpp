// 原题测试 / 参考链接（保留上游原始地址）
// https://oi-wiki.org/lang/java-pro/

// Source: src/class112/Code04_DoubleString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DoubleString {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DoubleString() {}
  static void java_main(Array<String> args) { Code04_DoubleString::test2(); }
  static void test1() {
    jout.println(String(u"测试StreamTokenizer"));
    jout.println(String(u"输入 : "));
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    double num = {};
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (num = static_cast<double>(in.nval));
      out.println(num);
    }
    out.flush();
    out.close();
    br.close();
  }
  static void test2() {
    jout.println(String(u"测试StringTokenizer"));
    jout.println(String(u"输入 : "));
    IO io = IO();
    int n = io.nextInt();
    double num = {};
    for (int i = 1; (i <= n); (i++)) {
      (num = io.nextDouble());
      io.println(num);
    }
    io.flush();
    io.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_DoubleString::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 读取科学计数法表达的double数字
// 如果输入的字符串代表double数字的科学计数法形式
// 用StreamTokenizer读取会出错
// 用StringTokenizer读取正确但比较费内存
// 参考链接 : https://oi-wiki.org/lang/java-pro/
                // test1();
        // Kattio类IO效率很好，但还是不如StreamTokenizer
        // 只有StreamTokenizer无法正确处理时，才考虑使用这个类
        // 参考链接 : https://oi-wiki.org/lang/java-pro/
        // StreamTokenizer无法正确读取
        // StringTokenizer可以正确读取
*/
