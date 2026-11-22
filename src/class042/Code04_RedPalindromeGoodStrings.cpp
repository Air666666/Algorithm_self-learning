// Source: src/class042/Code04_RedPalindromeGoodStrings.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_RedPalindromeGoodStrings {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_RedPalindromeGoodStrings() {}
  static int num1(int n) {
    Array<jchar> path = make_array<jchar>(n);
    return Code04_RedPalindromeGoodStrings::f(path, 0);
  }
  static int f(Array<jchar> path, int i) {
    if ((i == path.length)) {
      int cnt = 0;
      for (int l = 0; (l < path.length); (l++)) {
        for (int r = (l + 1); (r < path.length); (r++)) {
          if (Code04_RedPalindromeGoodStrings::is(path, l, r)) {
            (cnt++);
          }
          if ((cnt > 1)) {
            return 0;
          }
        }
      }
      return ((cnt == 1) ? 1 : 0);
    } else {
      int ans = 0;
      (path[i] = u'r');
      (ans += Code04_RedPalindromeGoodStrings::f(path, (i + 1)));
      (path[i] = u'e');
      (ans += Code04_RedPalindromeGoodStrings::f(path, (i + 1)));
      (path[i] = u'd');
      (ans += Code04_RedPalindromeGoodStrings::f(path, (i + 1)));
      return ans;
    }
  }
  static bool is(Array<jchar> s, int l, int r) {
    while ((l < r)) {
      if ((s[l] != s[r])) {
        return false;
      }
      (l++);
      (r--);
    }
    return true;
  }
  static int num2(int n) {
    if ((n == 1)) {
      return 0;
    }
    if ((n == 2)) {
      return 3;
    }
    if ((n == 3)) {
      return 18;
    }
    return static_cast<int>(jrem((static_cast<i64>(6) * (n + 1)), 1000000007));
  }
  static void java_main(Array<String> args) {
    for (int i = 1; (i <= 10); (i++)) {
      jout.println((((String(u"长度为") + i) + String(u", 答案:")) +
                    Code04_RedPalindromeGoodStrings::num1(i)));
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_RedPalindromeGoodStrings::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对 1000000007 取模， 1 <= n <= 10^9
// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18
        // 暴力方法
        // 为了观察规律
                        // i正常位置
        // 正式方法
        // 观察规律之后变成代码
*/
