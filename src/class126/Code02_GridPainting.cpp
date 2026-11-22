// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/

// Source: src/class126/Code02_GridPainting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_GridPainting {
  inline static int MAXN = 1001;
  inline static int MAXM = 5;
  inline static int MAXS = static_cast<int>(std::pow(3, MAXM));
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int m = {};
  inline static int maxs = {};
  inline static Array<Array<Array<int>>> dp = make_array<int>(MAXN, MAXM, MAXS);
  inline static Array<int> first = make_array<int>(MAXS);
  inline static int size = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_GridPainting() {}
  static int colorTheGrid(int rows, int cols) {
    Code02_GridPainting::build(rows, cols);
    int ans = 0;
    for (int i = 0; (i < size); (i++)) {
      (ans = jrem((ans + Code02_GridPainting::f(1, 0, first[i], 1)), MOD));
    }
    return ans;
  }
  static void build(int rows, int cols) {
    (n = jmax(rows, cols));
    (m = jmin(rows, cols));
    (maxs = static_cast<int>(std::pow(3, m)));
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int s = 0; (s < maxs); (s++)) {
          (dp[i][j][s] = (-1));
        }
      }
    }
    (size = 0);
    Code02_GridPainting::dfs(0, 0, 1);
  }
  static void dfs(int j, int s, int bit) {
    if ((j == m)) {
      (first[(size++)] = s);
    } else {
      int left = ((j == 0) ? (-1) : Code02_GridPainting::get(s, jdiv(bit, 3)));
      if ((left != 0)) {
        Code02_GridPainting::dfs((j + 1), Code02_GridPainting::set(s, bit, 0),
                                 (bit * 3));
      }
      if ((left != 1)) {
        Code02_GridPainting::dfs((j + 1), Code02_GridPainting::set(s, bit, 1),
                                 (bit * 3));
      }
      if ((left != 2)) {
        Code02_GridPainting::dfs((j + 1), Code02_GridPainting::set(s, bit, 2),
                                 (bit * 3));
      }
    }
  }
  static int f(int i, int j, int s, int bit) {
    if ((i == n)) {
      return 1;
    }
    if ((j == m)) {
      return Code02_GridPainting::f((i + 1), 0, s, 1);
    }
    if ((dp[i][j][s] != (-1))) {
      return dp[i][j][s];
    }
    int up = Code02_GridPainting::get(s, bit);
    int left = ((j == 0) ? (-1) : Code02_GridPainting::get(s, jdiv(bit, 3)));
    int ans = 0;
    if (((up != 0) && (left != 0))) {
      (ans = jrem((ans + Code02_GridPainting::f(
                             i, (j + 1), Code02_GridPainting::set(s, bit, 0),
                             (bit * 3))),
                  MOD));
    }
    if (((up != 1) && (left != 1))) {
      (ans = jrem((ans + Code02_GridPainting::f(
                             i, (j + 1), Code02_GridPainting::set(s, bit, 1),
                             (bit * 3))),
                  MOD));
    }
    if (((up != 2) && (left != 2))) {
      (ans = jrem((ans + Code02_GridPainting::f(
                             i, (j + 1), Code02_GridPainting::set(s, bit, 2),
                             (bit * 3))),
                  MOD));
    }
    (dp[i][j][s] = ans);
    return ans;
  }
  static int get(int s, int bit) { return jrem(jdiv(s, bit), 3); }
  static int set(int s, int bit, int v) {
    return ((s - (Code02_GridPainting::get(s, bit) * bit)) + (v * bit));
  }
};

/* Original teaching comments:
// 用三种不同颜色为网格涂色
// 给你两个整数m和n，表示m*n的网格，其中每个单元格最开始是白色
// 请你用红、绿、蓝三种颜色为每个单元格涂色，所有单元格都需要被涂色
// 要求相邻单元格的颜色一定要不同
// 返回网格涂色的方法数，答案对 1000000007 取模
// 1 <= m <= 5
// 1 <= n <= 1000
// 测试链接 :
https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/
// 有兴趣的同学可以自己改一下空间压缩的版本
        // 取得所有第一行的有效状态
                // 上方的颜色
                // 左侧的颜色，-1代表左侧没有格子
*/
