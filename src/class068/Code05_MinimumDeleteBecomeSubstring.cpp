// Source: src/class068/Code05_MinimumDeleteBecomeSubstring.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MinimumDeleteBecomeSubstring {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MinimumDeleteBecomeSubstring() {}
  static int minDelete1(String s1, String s2) {
    JList<String> list = JList<String>();
    Code05_MinimumDeleteBecomeSubstring::f(s1.toCharArray(), 0, String(u""),
                                           list);
    list.sort([=](String a, String b) {
      return [&]() {
        auto jleft = b.length();
        auto jright = a.length();
        return (jleft - jright);
      }();
    });
    for (String str : list) {
      if ((s2.indexOf(str) != (-1))) {
        return [&]() {
          auto jleft = s1.length();
          auto jright = str.length();
          return (jleft - jright);
        }();
      }
    }
    return s1.length();
  }
  static void f(Array<jchar> s1, int i, String path, JList<String> list) {
    if ((i == s1.length)) {
      list.add(path);
    } else {
      Code05_MinimumDeleteBecomeSubstring::f(s1, (i + 1), path, list);
      Code05_MinimumDeleteBecomeSubstring::f(s1, (i + 1), (path + s1[i]), list);
    }
  }
  static int minDelete2(String str1, String str2) {
    Array<jchar> s1 = str1.toCharArray();
    Array<jchar> s2 = str2.toCharArray();
    int n = s1.length;
    int m = s2.length;
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 1; (i <= n); (i++)) {
      (dp[i][0] = i);
      for (int j = 1; (j <= m); (j++)) {
        if ((s1[(i - 1)] == s2[(j - 1)])) {
          (dp[i][j] = dp[(i - 1)][(j - 1)]);
        } else {
          (dp[i][j] = (dp[(i - 1)][j] + 1));
        }
      }
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = 0; (j <= m); (j++)) {
      (ans = jmin(ans, dp[n][j]));
    }
    return ans;
  }
  static String randomString(int n, int v) {
    Array<jchar> ans = make_array<jchar>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] =
           static_cast<jchar>((u'a' + static_cast<int>((j::random() * v)))));
    }
    return j::str(ans);
  }
  static void java_main(Array<String> args) {
    int n = 12;
    int v = 3;
    int testTime = 20000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int len1 = (static_cast<int>((j::random() * n)) + 1);
      int len2 = (static_cast<int>((j::random() * n)) + 1);
      String s1 = Code05_MinimumDeleteBecomeSubstring::randomString(len1, v);
      String s2 = Code05_MinimumDeleteBecomeSubstring::randomString(len2, v);
      int ans1 = Code05_MinimumDeleteBecomeSubstring::minDelete1(s1, s2);
      int ans2 = Code05_MinimumDeleteBecomeSubstring::minDelete2(s1, s2);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MinimumDeleteBecomeSubstring::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 删除至少几个字符可以变成另一个字符串的子串
// 给定两个字符串s1和s2
// 返回s1至少删除多少字符可以成为s2的子串
// 对数器验证
        // 暴力方法
        // 为了验证
                // 排序 : 长度大的子序列先考虑
                // 因为如果长度大的子序列是s2的子串
                // 那么需要删掉的字符数量 = s1的长度 - s1子序列长度
                // 子序列长度越大，需要删掉的字符数量就越少
                // 所以长度大的子序列先考虑
                                // 检查s2中，是否包含当前的s1子序列str
        // 生成s1字符串的所有子序列串
        // 正式方法，动态规划
        // 已经展示太多次从递归到动态规划了
        // 直接写动态规划吧
        // 也不做空间压缩了，因为千篇一律
        // 有兴趣的同学自己试试
                // dp[len1][len2] :
                //
s1[前缀长度为i]至少删除多少字符，可以变成s2[前缀长度为j]的任意后缀串
        // 为了验证
        // 生成长度为n，有v种字符的随机字符串
        // 为了验证
        // 对数器
                // 测试的数据量比较小
                // 那是因为数据量大了，暴力方法过不了
                // 但是这个数据量足够说明正式方法是正确的
*/
