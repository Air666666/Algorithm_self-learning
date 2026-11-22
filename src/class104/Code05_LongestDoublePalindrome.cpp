// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4555

// Source: src/class104/Code05_LongestDoublePalindrome.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_LongestDoublePalindrome {
  inline static int MAXN = 100002;
  inline static Array<jchar> ss = make_array<jchar>(jshl(MAXN, 1));
  inline static Array<int> p = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> left = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> right = make_array<int>(jshl(MAXN, 1));
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_LongestDoublePalindrome() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    out.println(Code05_LongestDoublePalindrome::compute(in.readLine()));
    out.flush();
    out.close();
    in.close();
  }
  static int compute(String s) {
    Code05_LongestDoublePalindrome::manacher(s);
    {
      int i = 0;
      int j = 0;
      for (; (i < n); (i++)) {
        while (((i + p[i]) > j)) {
          (left[j] = (j - i));
          (j += 2);
        }
      }
    }
    {
      int i = (n - 1);
      int j = (n - 1);
      for (; (i >= 0); (i--)) {
        while (((i - p[i]) < j)) {
          (right[j] = (i - j));
          (j -= 2);
        }
      }
    }
    int ans = 0;
    for (int i = 2; (i <= (n - 3)); (i += 2)) {
      (ans = jmax(ans, (left[i] + right[i])));
    }
    return ans;
  }
  static void manacher(String str) {
    Code05_LongestDoublePalindrome::manacherss(str.toCharArray());
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
        (p[i] = len);
      }
    }
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
  Code05_LongestDoublePalindrome::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长双回文串长度
// 输入字符串s，求s的最长双回文子串t的长度
// 双回文子串就是可以分成两个回文串的字符串
// 比如"aabb"，可以分成"aa"、"bb"
// 测试链接 : https://www.luogu.com.cn/problem/P4555
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
*/
