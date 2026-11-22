// Source: src/class103/Code02_ExpandKMP.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_ExpandKMP {
  inline static int MAXN = 20000001;
  inline static Array<int> z = make_array<int>(MAXN);
  inline static Array<int> e = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_ExpandKMP() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    Array<jchar> a = in.readLine().toCharArray();
    Array<jchar> b = in.readLine().toCharArray();
    Code02_ExpandKMP::zArray(b, b.length);
    Code02_ExpandKMP::eArray(a, b, a.length, b.length);
    out.println(Code02_ExpandKMP::eor(z, b.length));
    out.println(Code02_ExpandKMP::eor(e, a.length));
    out.flush();
    out.close();
    in.close();
  }
  static void zArray(Array<jchar> s, int n) {
    (z[0] = n);
    {
      int i = 1;
      int c = 1;
      int r = 1;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin((r - i), z[(i - c)]) : 0));
        while ((((i + len) < n) && (s[(i + len)] == s[len]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (z[i] = len);
      }
    }
  }
  static void eArray(Array<jchar> a, Array<jchar> b, int n, int m) {
    {
      int i = 0;
      int c = 0;
      int r = 0;
      int len = {};
      for (; (i < n); (i++)) {
        (len = ((r > i) ? jmin((r - i), z[(i - c)]) : 0));
        while (((((i + len) < n) && (len < m)) && (a[(i + len)] == b[len]))) {
          (len++);
        }
        if (((i + len) > r)) {
          (r = (i + len));
          (c = i);
        }
        (e[i] = len);
      }
    }
  }
  static i64 eor(Array<int> arr, int n) {
    i64 ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (ans ^= (static_cast<i64>((i + 1)) * (arr[i] + 1)));
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_ExpandKMP::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 扩展KMP模版，又称Z算法或Z函数
// 给定两个字符串a、b，求出两个数组
// b与b每一个后缀串的最长公共前缀长度，z数组
// b与a每一个后缀串的最长公共前缀长度，e数组
// 计算出要求的两个数组后，输出这两个数组的权值即可
// 对于一个数组x，i位置的权值定义为 : (i * (x[i] + 1))
// 数组权值为所有位置权值的异或和
// 测试链接 : https://www.luogu.com.cn/problem/P5410
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 非常像Manacher算法
        // 非常像Manacher算法
*/
