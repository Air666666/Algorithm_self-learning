// Source: src/class103/Code01_Manacher.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Manacher {
  inline static int MAXN = 11000001;
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Manacher() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    out.println(Code01_Manacher::manacher(in.readLine()));
    out.flush();
    out.close();
    in.close();
  }
  static int manacher(String str) {
    Code01_Manacher::manacherss(str.toCharArray());
    int max = 0;
    {
      int i = 0;
      int c = 0;
      int r = 0;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin(p[((2 * c) - i)], (r - i)) : 1));
        while (((((i + len) < n) && ((i - len) >= 0)) &&
                (ss[(i + len)] == ss[(i - len)]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (max = jmax(max, len));
        (p[i] = len);
      }
    }
    return (max - 1);
  }
  static void manacherss(Array<jchar> a) {
    (n = ((a.length * 2) + 1));
    {
      int i = 0;
      int j = 0;
      for (; (i < n); (i++)) {
        (ss[i] = (((i & 1) == 0) ? u'#' : a[(j++)]));
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Manacher::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// Manacher算法模版
// 求字符串s中最长回文子串的长度
// 测试链接 : https://www.luogu.com.cn/problem/P3805
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
