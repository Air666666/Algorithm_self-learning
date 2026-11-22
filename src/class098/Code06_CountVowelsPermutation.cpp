// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/count-vowels-permutation/

// Source: src/class098/Code06_CountVowelsPermutation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_CountVowelsPermutation {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_CountVowelsPermutation() {}
  static int countVowelPermutation(int n) {
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, 1, 1, 1, 1}};
    Array<Array<int>> base =
        Array<Array<int>>{Array<int>{0, 1, 0, 0, 0}, Array<int>{1, 0, 1, 0, 0},
                          Array<int>{1, 1, 0, 1, 1}, Array<int>{0, 0, 1, 0, 1},
                          Array<int>{1, 0, 0, 0, 0}};
    Array<Array<int>> ans = Code06_CountVowelsPermutation::multiply(
        start, Code06_CountVowelsPermutation::power(base, (n - 1)));
    int ret = 0;
    for (int a : ans[0]) {
      (ret = jrem((ret + a), MOD));
    }
    return ret;
  }
  static Array<Array<int>> multiply(Array<Array<int>> a, Array<Array<int>> b) {
    int n = a.length;
    int m = b[0].length;
    int k = a[0].length;
    Array<Array<int>> ans = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int c = 0; (c < k); (c++)) {
          (ans[i][j] = static_cast<int>(
               jrem(((static_cast<i64>(a[i][c]) * b[c][j]) + ans[i][j]), MOD)));
        }
      }
    }
    return ans;
  }
  static Array<Array<int>> power(Array<Array<int>> m, int p) {
    int n = m.length;
    Array<Array<int>> ans = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i][i] = 1);
    }
    for (; (p != 0); (p = jshr(p, 1))) {
      if (((p & 1) != 0)) {
        (ans = Code06_CountVowelsPermutation::multiply(ans, m));
      }
      (m = Code06_CountVowelsPermutation::multiply(m, m));
    }
    return ans;
  }
};

/* Original teaching comments:
// 统计元音字母序列的数目
// 给你一个整数n，请你帮忙统计一下我们可以按下述规则形成多少个长度为n的字符串：
// 字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
// 每个元音 'a' 后面都只能跟着 'e'
// 每个元音 'e' 后面只能跟着 'a' 或者是 'i'
// 每个元音 'i' 后面 不能 再跟着另一个 'i'
// 每个元音 'o' 后面只能跟着 'i' 或者是 'u'
// 每个元音 'u' 后面只能跟着 'a'
// 由于答案可能会很大，结果对1000000007取模
// 测试链接 : https://leetcode.cn/problems/count-vowels-permutation/
        // 正式方法
        // 矩阵快速幂
        // 时间复杂度O(logn)
                // 长度为1的时候，以a、e、i、o、u结尾的合法数量
        // 矩阵相乘 + 乘法取模
        // a的列数一定要等于b的行数
        // 矩阵快速幂
*/
