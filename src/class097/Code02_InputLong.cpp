// Source: src/class097/Code02_InputLong.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_InputLong {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_InputLong() {}
  static void java_main(Array<String> args) {
    Code02_InputLong::f1();
    Code02_InputLong::f2();
  }
  static void f1() {
    jout.println(String(u"f1函数测试读入"));
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    i64 num = static_cast<i64>(in.nval);
    out.println(num);
    out.flush();
  }
  static void f2() {
    jout.println(String(u"f2函数测试读入"));
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    String str = br.readLine();
    i64 num = std::stoll(text(str));
    out.println(num);
    out.flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_InputLong::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 读入long类型数字的注意点
// 讲解019的扩展，没有看过讲解019的同学去看一下
                // 尝试读入 : 131237128371723187
                // in.nval读出的是double类型
                // double类型64位
                // long类型也是64位
                // double的64位会分配若干位去表达小数部分
                // long类型的64位全用来表达整数部分
                // 所以读入是long范围的数，如果用以下的写法
                //
in.nval会先变成double类型，如果再转成long类型，就可能有精度损耗
                // 尝试读入 : 131237128371723187
                // 直接读出字符串
                // 然后把字符串转成long
                // 不可能有精度损耗
*/
