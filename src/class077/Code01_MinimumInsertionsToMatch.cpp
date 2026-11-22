// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/e391767d80d942d29e6095a935a5b96b

// Source: src/class077/Code01_MinimumInsertionsToMatch.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumInsertionsToMatch {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumInsertionsToMatch() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    String str = br.readLine();
    out.println(Code01_MinimumInsertionsToMatch::compute(str));
    out.flush();
    out.close();
    br.close();
  }
  static int compute(String str) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code01_MinimumInsertionsToMatch::f(s, 0, (s.length - 1), dp);
  }
  static int f(Array<jchar> s, int l, int r, Array<Array<int>> dp) {
    if ((l == r)) {
      return 1;
    }
    if ((l == (r - 1))) {
      if ((((s[l] == u'(') && (s[r] == u')')) ||
           ((s[l] == u'[') && (s[r] == u']')))) {
        return 0;
      }
      return 2;
    }
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int p1 = std::numeric_limits<int>::max();
    if ((((s[l] == u'(') && (s[r] == u')')) ||
         ((s[l] == u'[') && (s[r] == u']')))) {
      (p1 = Code01_MinimumInsertionsToMatch::f(s, (l + 1), (r - 1), dp));
    }
    int p2 = std::numeric_limits<int>::max();
    for (int m = l; (m < r); (m++)) {
      (p2 = jmin(p2, [&]() {
         auto jleft = Code01_MinimumInsertionsToMatch::f(s, l, m, dp);
         auto jright = Code01_MinimumInsertionsToMatch::f(s, (m + 1), r, dp);
         return (jleft + jright);
       }()));
    }
    int ans = jmin(p1, p2);
    (dp[l][r] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MinimumInsertionsToMatch::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 完成配对需要的最少字符数量
// 给定一个由'['、']'、'('，')'组成的字符串
// 请问最少插入多少个括号就能使这个字符串的所有括号正确配对
// 例如当前串是 "([[])"，那么插入一个']'即可满足
// 输出最少需要插入多少个字符
// 测试链接 : https://www.nowcoder.com/practice/e391767d80d942d29e6095a935a5b96b
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 时间复杂度O(n^3)
        // 让s[l...r]配对至少需要几个字符
                // l...r字符数量 >= 3
                // 可能性1 : [l]、[r]本来就是配对的
                // 可能性2 : 基于每个可能的划分点，做左右划分
*/
