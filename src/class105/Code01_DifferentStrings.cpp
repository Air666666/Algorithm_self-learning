// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3370

// Source: src/class105/Code01_DifferentStrings.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_DifferentStrings {
  inline static int MAXN = 10001;
  inline static int base = 499;
  inline static Array<i64> nums = make_array<i64>(MAXN);
  inline static int n = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_DifferentStrings() {}
  static void java_main(Array<String> args) {
    IO in = IO(IO(jin));
    IO out = IO(IO(jout));
    (n = std::stoi(text(in.readLine())));
    for (int i = 0; (i < n); (i++)) {
      (nums[i] = Code01_DifferentStrings::value(in.readLine().toCharArray()));
    }
    out.println(Code01_DifferentStrings::cnt());
    out.flush();
    out.close();
    in.close();
  }
  static i64 value(Array<jchar> s) {
    i64 ans = Code01_DifferentStrings::v(s[0]);
    for (int i = 1; (i < s.length); (i++)) {
      (ans = ((ans * base) + Code01_DifferentStrings::v(s[i])));
    }
    return ans;
  }
  static int v(jchar c) {
    if (((c >= u'0') && (c <= u'9'))) {
      return ((c - u'0') + 1);
    } else if (((c >= u'A') && (c <= u'Z'))) {
      return ((c - u'A') + 11);
    } else {
      return ((c - u'a') + 37);
    }
  }
  static int cnt() {
    j::sort(nums, 0, n);
    int ans = 1;
    for (int i = 1; (i < n); (i++)) {
      if ((nums[i] != nums[(i - 1)])) {
        (ans++);
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_DifferentStrings::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 统计有多少个不同的字符串
// 测试链接 : https://www.luogu.com.cn/problem/P3370
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 数字 + 大写 + 小写
        // '0' -> 1
        // '1' -> 2
        // ...
        // '9' -> 10
        // 'A' -> 11
        // 'B' -> 12
        // ...
        // 'Z' -> 36
        // 'a' -> 37
        // ...
        // 'z' -> 62
*/
