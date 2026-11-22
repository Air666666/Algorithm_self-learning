// Source: src/class086/Code01_LCS.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LCS {
  inline static int MAXN = 5001;
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXN);
  inline static Array<jchar> ans = make_array<jchar>(MAXN);
  inline static Array<jchar> s1 = {};
  inline static Array<jchar> s2 = {};
  inline static int n = {};
  inline static int m = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LCS() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    IO out = IO(IO(jout));
    (s1 = br.readLine().toCharArray());
    (s2 = br.readLine().toCharArray());
    (n = s1.length);
    (m = s2.length);
    Code01_LCS::lcs();
    if ((k == 0)) {
      out.println((-1));
    } else {
      for (int i = 0; (i < k); (i++)) {
        out.print(ans[i]);
      }
      out.println();
    }
    out.flush();
    out.close();
    br.close();
  }
  static void lcs() {
    Code01_LCS::dp_method();
    (k = dp[n][m]);
    if ((k > 0)) {
      {
        int len = k;
        int i = n;
        int j = m;
        for (; (len > 0);) {
          if ((s1[(i - 1)] == s2[(j - 1)])) {
            (ans[(--len)] = s1[(i - 1)]);
            (i--);
            (j--);
          } else {
            if ((dp[(i - 1)][j] >= dp[i][(j - 1)])) {
              (i--);
            } else {
              (j--);
            }
          }
        }
      }
    }
  }
  static void dp_method() {
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        if ((s1[(i - 1)] == s2[(j - 1)])) {
          (dp[i][j] = (1 + dp[(i - 1)][(j - 1)]));
        } else {
          (dp[i][j] = jmax(dp[(i - 1)][j], dp[i][(j - 1)]));
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_LCS::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最长公共子序列其中一个结果
// 给定两个字符串str1和str2
// 输出两个字符串的最长公共子序列
// 如果最长公共子序列为空，则输出-1
// 测试链接 : https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 讲解067 - 题目3，最长公共子序列长度
        // 填好dp表
*/
