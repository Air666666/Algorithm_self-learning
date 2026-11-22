// Source: src/class076/Code06_BooleanEvaluation.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_BooleanEvaluation {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_BooleanEvaluation() {}
  static int countEval(String str, int result) {
    Array<jchar> s = str.toCharArray();
    int n = s.length;
    Array<Array<Array<int>>> dp = make_array<Array<int>>(n, n);
    Array<int> ft = Code06_BooleanEvaluation::f(s, 0, (n - 1), dp);
    return ft[result];
  }
  static Array<int> f(Array<jchar> s, int l, int r,
                      Array<Array<Array<int>>> dp) {
    if ((dp[l][r] != nullptr)) {
      return dp[l][r];
    }
    int f = 0;
    int t = 0;
    if ((l == r)) {
      (f = ((s[l] == u'0') ? 1 : 0));
      (t = ((s[l] == u'1') ? 1 : 0));
    } else {
      Array<int> tmp = {};
      {
        int k = (l + 1);
        int a = {};
        int b = {};
        int c = {};
        int d = {};
        for (; (k < r); (k += 2)) {
          (tmp = Code06_BooleanEvaluation::f(s, l, (k - 1), dp));
          (a = tmp[0]);
          (b = tmp[1]);
          (tmp = Code06_BooleanEvaluation::f(s, (k + 1), r, dp));
          (c = tmp[0]);
          (d = tmp[1]);
          if ((s[k] == u'&')) {
            (f += (((a * c) + (a * d)) + (b * c)));
            (t += (b * d));
          } else if ((s[k] == u'|')) {
            (f += (a * c));
            (t += (((a * d) + (b * c)) + (b * d)));
          } else {
            (f += ((a * c) + (b * d)));
            (t += ((a * d) + (b * c)));
          }
        }
      }
    }
    Array<int> ft = Array<int>{f, t};
    (dp[l][r] = ft);
    return ft;
  }
};

/* Original teaching comments:
// 布尔运算
// 给定一个布尔表达式和一个期望的布尔结果 result
// 布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成
// 布尔表达式一定是正确的，不需要检查有效性
// 但是其中没有任何括号来表示优先级
// 你可以随意添加括号来改变逻辑优先级
// 目的是让表达式能够最终得出result的结果
// 返回最终得出result有多少种不同的逻辑计算顺序
// 测试链接 : https://leetcode.cn/problems/boolean-evaluation-lcci/
        // 记忆化搜索
        // s[l...r]是表达式的一部分，且一定符合范式
        // 0/1  逻  0/1   逻       0/1
        //  l  l+1  l+2  l+3........r
        // s[l...r]  0 : ?
        //           1 : ?
        // ans : int[2] ans[0] = false方法数 ans[0] = true方法数
                        // 只剩一个字符，0/1
                                // l ... r
                                // 枚举每一个逻辑符号最后执行 k = l+1 ... r-1
k+=2
*/
