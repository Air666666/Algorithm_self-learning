// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/

// Source: src/class085/Code03_IntegersWithoutConsecutiveOnes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_IntegersWithoutConsecutiveOnes {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_IntegersWithoutConsecutiveOnes() {}
  static int findIntegers1(int n) {
    Array<int> cnt = make_array<int>(31);
    (cnt[0] = 1);
    (cnt[1] = 2);
    for (int len = 2; (len <= 30); (len++)) {
      (cnt[len] = (cnt[(len - 1)] + cnt[(len - 2)]));
    }
    return Code03_IntegersWithoutConsecutiveOnes::f(cnt, n, 30);
  }
  static int f(Array<int> cnt, int num, int i) {
    if ((i == (-1))) {
      return 1;
    }
    int ans = 0;
    if (((num & jshl(1, i)) != 0)) {
      (ans += cnt[i]);
      if (((num & jshl(1, (i + 1))) != 0)) {
        return ans;
      }
    }
    (ans += Code03_IntegersWithoutConsecutiveOnes::f(cnt, num, (i - 1)));
    return ans;
  }
  static int findIntegers2(int n) {
    Array<int> cnt = make_array<int>(31);
    (cnt[0] = 1);
    (cnt[1] = 2);
    for (int len = 2; (len <= 30); (len++)) {
      (cnt[len] = (cnt[(len - 1)] + cnt[(len - 2)]));
    }
    int ans = 0;
    for (int i = 30; (i >= (-1)); (i--)) {
      if ((i == (-1))) {
        (ans++);
        break;
      }
      if (((n & jshl(1, i)) != 0)) {
        (ans += cnt[i]);
        if (((n & jshl(1, (i + 1))) != 0)) {
          break;
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 不含连续1的非负整数
// 给定一个正整数n，请你统计在[0, n]范围的非负整数中
// 有多少个整数的二进制表示中不存在连续的1
// 测试链接 :
https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/
        // cnt[len] :
二进制如果有len位，所有二进制状态中不存在连续的1的状态有多少个，辅助数组
        // 从num二进制形式的高位开始，当前来到第i位，之前的位完全和num一样
        // 返回<=num且不存在连续的1的状态有多少个
                                // 如果num二进制状态，前一位是1，当前位也是1
                                // 如果前缀保持和num一样，后续一定不合法了
                                // 所以提前返回
                // 之前的高位和num一样，且合法，继续去i-1位递归
        // 只是把方法1从递归改成迭代而已
        // 完全是等义改写，没有新东西
*/
