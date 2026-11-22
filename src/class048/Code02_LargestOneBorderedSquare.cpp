// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/largest-1-bordered-square/

// Source: src/class048/Code02_LargestOneBorderedSquare.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LargestOneBorderedSquare {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LargestOneBorderedSquare() {}
  static int largest1BorderedSquare(Array<Array<int>> g) {
    int n = g.length;
    int m = g[0].length;
    Code02_LargestOneBorderedSquare::build(n, m, g);
    if ((Code02_LargestOneBorderedSquare::sum(g, 0, 0, (n - 1), (m - 1)) ==
         0)) {
      return 0;
    }
    int ans = 1;
    for (int a = 0; (a < n); (a++)) {
      for (int b = 0; (b < m); (b++)) {
        {
          int c = (a + ans);
          int d = (b + ans);
          int k = (ans + 1);
          for (; ((c < n) && (d < m)); (c++), (d++), (k++)) {
            if (([&]() {
                  auto jleft =
                      Code02_LargestOneBorderedSquare::sum(g, a, b, c, d);
                  auto jright = Code02_LargestOneBorderedSquare::sum(
                      g, (a + 1), (b + 1), (c - 1), (d - 1));
                  return (jleft - jright);
                }() == jshl((k - 1), 2))) {
              (ans = k);
            }
          }
        }
      }
    }
    return (ans * ans);
  }
  static void build(int n, int m, Array<Array<int>> g) {
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        (g[i][j] += [&]() {
          auto jleft = [&]() {
            auto jleft = Code02_LargestOneBorderedSquare::get(g, i, (j - 1));
            auto jright = Code02_LargestOneBorderedSquare::get(g, (i - 1), j);
            return (jleft + jright);
          }();
          auto jright =
              Code02_LargestOneBorderedSquare::get(g, (i - 1), (j - 1));
          return (jleft - jright);
        }());
      }
    }
  }
  static int sum(Array<Array<int>> g, int a, int b, int c, int d) {
    return ((a > c) ? 0 : [&]() {
      auto jleft = [&]() {
        auto jleft =
            (g[c][d] - Code02_LargestOneBorderedSquare::get(g, c, (b - 1)));
        auto jright = Code02_LargestOneBorderedSquare::get(g, (a - 1), d);
        return (jleft - jright);
      }();
      auto jright = Code02_LargestOneBorderedSquare::get(g, (a - 1), (b - 1));
      return (jleft + jright);
    }());
  }
  static int get(Array<Array<int>> g, int i, int j) {
    return (((i < 0) || (j < 0)) ? 0 : g[i][j]);
  }
};

/* Original teaching comments:
// 边框为1的最大正方形
// 给你一个由若干 0 和 1 组成的二维网格 grid
// 请你找出边界全部由 1 组成的最大 正方形 子网格
// 并返回该子网格中的元素数量。如果不存在，则返回 0。
// 测试链接 : https://leetcode.cn/problems/largest-1-bordered-square/
        // 打败比例不高，但完全是常数时间的问题
        // 时间复杂度O(n * m * min(n,m))，额外空间复杂度O(1)
        // 复杂度指标上绝对是最优解
                // 找到的最大合法正方形的边长
                                // (a,b)所有左上角点
                                // (c,d)更大边长的右下角点，k是当前尝试的边长
        // g : 原始二维数组
        // 把g变成原始二维数组的前缀和数组sum，复用自己
        // 不能补0行，0列，都是0
*/
