#include "../include/jcompat.hpp"
using namespace j;
struct TranslatorRegression {
  inline static int x = 0;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  TranslatorRegression() {}
  static int take() { return (x++); }
  static int pack(int a, int b) { return ((a * 10) + b); }
  static void java_main(Array<String> args) {
    int a = 3;
    int b = 5;
    jout.println((++a));
    jout.println((b--));
    jout.println((-(-a)));
    jout.println((~(~b)));
    jout.println([&]() {
      auto jargument_0 = TranslatorRegression::take();
      auto jargument_1 = TranslatorRegression::take();
      return TranslatorRegression::pack(jargument_0, jargument_1);
    }());
    jout.println([&]() {
      auto jleft = TranslatorRegression::take();
      auto jright = TranslatorRegression::take();
      return (jleft - jright);
    }());
    jout.println([&]() {
      auto jargument_0 = (++a);
      auto jargument_1 = (++a);
      return TranslatorRegression::pack(jargument_0, jargument_1);
    }());
    jout.println([&]() {
      auto jleft = (a++);
      auto jright = (a++);
      return (jleft + jright);
    }());
    jout.println(jdiv(std::numeric_limits<int>::min(), (-1)));
    jout.println(jrem(std::numeric_limits<int>::min(), (-1)));
    jout.println(jshl(1, 33));
    jout.println(jushr((-1), 1));
    String s = newString(String(u"test"));
    String t = newString(String(u"test"));
    jout.println((s == t));
    jout.println(s.equals(t));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  TranslatorRegression::java_main(Array<String>{});
  return 0;
}
