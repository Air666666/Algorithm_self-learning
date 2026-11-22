// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/super-egg-drop/

// Source: src/class128/Code04_EggDrop.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_EggDrop {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_EggDrop() {}
  static int superEggDrop1(int k, int n) {
    if ((k == 1)) {
      return n;
    }
    Array<Array<int>> dp = make_array<int>((k + 1), (n + 1));
    for (int j = 1; (j <= n); (j++)) {
      for (int i = 1; (i <= k); (i++)) {
        (dp[i][j] = ((dp[(i - 1)][(j - 1)] + dp[i][(j - 1)]) + 1));
        if ((dp[i][j] >= n)) {
          return j;
        }
      }
    }
    return (-1);
  }
  static int superEggDrop2(int k, int n) {
    if ((k == 1)) {
      return n;
    }
    Array<int> dp = make_array<int>((k + 1));
    for (int j = 1; (j <= n); (j++)) {
      int pre = 0;
      for (int i = 1; (i <= k); (i++)) {
        int tmp = dp[i];
        (dp[i] = ((dp[i] + pre) + 1));
        (pre = tmp);
        if ((dp[i] >= n)) {
          return j;
        }
      }
    }
    return (-1);
  }
};

/* Original teaching comments:
// 大楼扔鸡蛋问题
// 一共有k枚相同的鸡蛋，一共有n层楼
//
已知一定存在楼层f(0<=f<=n)，从>f的楼层扔鸡蛋一定会碎，从<=f的楼层扔鸡蛋，扔几次都不会碎
// 鸡蛋一旦碎了就不能再使用，只能选择另外的鸡蛋
// 现在想确定f的值，返回最少扔几次鸡蛋，可以确保测出该值
// 1 <= k <= 100
// 1 <= n <= 10^4
// 测试链接 : https://leetcode.cn/problems/super-egg-drop/
        // 最优解
        // 最优解空间压缩的版本
*/
