// Source: src/class128/Code03_AddLimitLcs.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_AddLimitLcs {
  inline static int MAXN = 1000005;
  inline static int MAXM = 1005;
  inline static Array<jchar> s1 = {};
  inline static Array<jchar> s2 = {};
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> right = make_array<int>(26);
  inline static Array<Array<int>> next = make_array<int>(MAXN, 26);
  inline static Array<Array<int>> dp = make_array<int>(MAXM, MAXM);
  inline static int NA = std::numeric_limits<int>::max();
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_AddLimitLcs() {}
  static void java_main(Array<String> args) {
    int n = 100;
    int m = 100;
    int testTime = 10000;
    jout.println(String(u"功能测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int size1 = (static_cast<int>((j::random() * n)) + 1);
      int size2 = (static_cast<int>((j::random() * m)) + 1);
      String str1 = Code03_AddLimitLcs::randomString(size1);
      String str2 = Code03_AddLimitLcs::randomString(size2);
      int ans1 = Code03_AddLimitLcs::lcs1(str1, str2);
      int ans2 = Code03_AddLimitLcs::lcs2(str1, str2);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println();
    jout.println(String(u"性能测试开始"));
    (n = 1000000);
    (m = 1000);
    jout.println((String(u"n = ") + n));
    jout.println((String(u"m = ") + m));
    String str1 = Code03_AddLimitLcs::randomString(n);
    String str2 = Code03_AddLimitLcs::randomString(m);
    i64 start = {};
    i64 end = {};
    (start = millis());
    Code03_AddLimitLcs::lcs1(str1, str2);
    (end = millis());
    jout.println(
        ((String(u"lcs1方法运行时间 : ") + (end - start)) + String(u" 毫秒")));
    (start = millis());
    Code03_AddLimitLcs::lcs2(str1, str2);
    (end = millis());
    jout.println(
        ((String(u"lcs2方法运行时间 : ") + (end - start)) + String(u" 毫秒")));
    jout.println(String(u"性能测试结束"));
  }
  static String randomString(int n) {
    Array<jchar> ans = make_array<jchar>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] =
           static_cast<jchar>((static_cast<int>((j::random() * 26)) + u'a')));
    }
    return j::str(ans);
  }
  static int lcs1(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= m); (j++)) {
        if ((s1[(i - 1)] == s2[(j - 1)])) {
          (dp[i][j] = (1 + dp[(i - 1)][(j - 1)]));
        } else {
          (dp[i][j] = jmax(dp[(i - 1)][j], dp[i][(j - 1)]));
        }
      }
    }
    return dp[n][m];
  }
  static int lcs2(String str1, String str2) {
    (s1 = str1.toCharArray());
    (s2 = str2.toCharArray());
    (n = s1.length);
    (m = s2.length);
    Code03_AddLimitLcs::build();
    int ans = 0;
    for (int j = m; (j >= 1); (j--)) {
      if ((Code03_AddLimitLcs::f(m, j) != NA)) {
        (ans = j);
        break;
      }
    }
    return ans;
  }
  static void build() {
    for (int j = 0; (j < 26); (j++)) {
      (right[j] = NA);
    }
    for (int i = n; (i >= 0); (i--)) {
      for (int j = 0; (j < 26); (j++)) {
        (next[i][j] = right[j]);
      }
      if ((i > 0)) {
        (right[(s1[(i - 1)] - u'a')] = i);
      }
    }
    for (int i = 0; (i <= m); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = (-1));
      }
    }
  }
  static int f(int i, int j) {
    if ((i < j)) {
      return NA;
    }
    if ((j == 0)) {
      return 0;
    }
    if ((dp[i][j] != (-1))) {
      return dp[i][j];
    }
    int cha = (s2[(i - 1)] - u'a');
    int ans = Code03_AddLimitLcs::f((i - 1), j);
    int pre = Code03_AddLimitLcs::f((i - 1), (j - 1));
    if ((pre != NA)) {
      (ans = jmin(ans, next[pre][cha]));
    }
    (dp[i][j] = ans);
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_AddLimitLcs::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 增加限制的最长公共子序列问题
// 给定两个字符串s1和s2，s1长度为n，s2长度为m
// 返回s1和s2的最长公共子序列长度
// 注意：
// 两个字符串都只由小写字母组成
// 1 <= n <= 10^6
// 1 <= m <= 10^3
// 状态设计优化的经典题，对数器验证
        // 为了测试
        // 为了测试
        // 随机生成长度为n只有小写字母构成的字符串
        // 经典动态规划的版本
        // 来自讲解067，题目3，最经典的方法4
        // 不利用任何限制，时间复杂度O(n*m)
        // 利用限制条件做优化的版本
        // 时间复杂度O(26*n + m^2)
                                // s1的i长度，对应的字符是s1[i-1]
        // 长度为i的s2前缀串，想和s1字符串形成长度为j的公共子序列
        // 返回至少需要多长的s1前缀串才能做到
        // 如果怎么都做不到，返回NA
                // s2前缀串长度为i，最后字符s2[i-1]
*/
