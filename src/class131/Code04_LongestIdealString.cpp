// Source: src/class131/Code04_LongestIdealString.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LongestIdealString {
  inline static int n = 26;
  inline static Array<int> max = make_array<int>(jshl((n + 1), 2));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LongestIdealString() {}
  static int longestIdealString(String s, int k) {
    j::fill(max, 0);
    int v = {};
    int p = {};
    int ans = 0;
    for (jchar cha : s.toCharArray()) {
      (v = ((cha - u'a') + 1));
      (p = [&]() {
        auto jargument_0 = jmax((v - k), 1);
        auto jargument_1 = jmin((v + k), n);
        auto jargument_2 = 1;
        auto jargument_3 = n;
        auto jargument_4 = 1;
        return Code04_LongestIdealString::max_method(
            jargument_0, jargument_1, jargument_2, jargument_3, jargument_4);
      }());
      (ans = jmax(ans, (p + 1)));
      Code04_LongestIdealString::update(v, (p + 1), 1, n, 1);
    }
    return ans;
  }
  static void up(int i) {
    (max[i] = jmax(max[jshl(i, 1)], max[(jshl(i, 1) | 1)]));
  }
  static void update(int jobi, int jobv, int l, int r, int i) {
    if (((l == r) && (jobi == l))) {
      (max[i] = jobv);
    } else {
      int m = jshr((l + r), 1);
      if ((jobi <= m)) {
        Code04_LongestIdealString::update(jobi, jobv, l, m, jshl(i, 1));
      } else {
        Code04_LongestIdealString::update(jobi, jobv, (m + 1), r,
                                          (jshl(i, 1) | 1));
      }
      Code04_LongestIdealString::up(i);
    }
  }
  static int max_method(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return max[i];
    }
    int m = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= m)) {
      (ans = jmax(ans, Code04_LongestIdealString::max_method(jobl, jobr, l, m,
                                                             jshl(i, 1))));
    }
    if ((jobr > m)) {
      (ans = jmax(ans, Code04_LongestIdealString::max_method(
                           jobl, jobr, (m + 1), r, (jshl(i, 1) | 1))));
    }
    return ans;
  }
};

/* Original teaching comments:
// 最长理想子序列
// 给定一个长度为n，只由小写字母组成的字符串s，给定一个非负整数k
// 字符串s可以生成很多子序列，下面给出理想子序列的定义
// 子序列中任意相邻的两个字符，在字母表中位次的差值绝对值<=k
// 返回最长理想子序列
// 1 <= n <= 10^5
// 0 <= k <= 25
// s只由小写字母组成
// 测试链接 : https://leetcode.cn/problems/longest-ideal-subsequence/
        // 数据量太小，线段树的优势不明显
        // 时间复杂度O(n * log e)，n为字符串长度，e为字符集大小
        // 只有单点更新不需要定义down方法
        // 因为单点更新的任务一定会从线段树头节点直插到某个叶节点
        // 根本没有懒更新这回事
*/
