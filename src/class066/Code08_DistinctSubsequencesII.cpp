// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/distinct-subsequences-ii/

// Source: src/class066/Code08_DistinctSubsequencesII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_DistinctSubsequencesII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_DistinctSubsequencesII() {}
  static int distinctSubseqII(String s) {
    int mod = 1000000007;
    Array<jchar> str = s.toCharArray();
    Array<int> cnt = make_array<int>(26);
    int all = 1;
    int newAdd = {};
    for (jchar x : str) {
      (newAdd = jrem(((all - cnt[(x - u'a')]) + mod), mod));
      (cnt[(x - u'a')] = jrem((cnt[(x - u'a')] + newAdd), mod));
      (all = jrem((all + newAdd), mod));
    }
    return jrem(((all - 1) + mod), mod);
  }
};

/* Original teaching comments:
// 不同的子序列 II
// 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
// 因为结果可能很大，答案对 1000000007 取模
// 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
// 字符但不改变剩余字符相对位置的一个新字符串
// 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是
// 测试链接 : https://leetcode.cn/problems/distinct-subsequences-ii/
        // 时间复杂度O(n)，n是字符串s的长度
*/
