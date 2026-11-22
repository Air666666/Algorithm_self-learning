// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/range-sum-query-2d-mutable/

// Source: src/class108/Code04_TwoDimensionSingleAddIntervalQuery.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TwoDimensionSingleAddIntervalQuery {
  struct NumMatrix;
  struct NumMatrix {
    Array<Array<int>> tree = {};
    Array<Array<int>> nums = {};
    int n = {};
    int m = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    NumMatrix(Array<Array<int>> matrix) {
      (n = matrix.length);
      (m = matrix[0].length);
      (tree = make_array<int>((n + 1), (m + 1)));
      (nums = make_array<int>((n + 1), (m + 1)));
      for (int i = 0; (i < n); (i++)) {
        for (int j = 0; (j < m); (j++)) {
          NumMatrix::update(i, j, matrix[i][j]);
        }
      }
    }
    int lowbit(int i) { return (i & (-i)); }
    void add(int x, int y, int v) {
      for (int i = x; (i <= n); (i += NumMatrix::lowbit(i))) {
        for (int j = y; (j <= m); (j += NumMatrix::lowbit(j))) {
          (tree[i][j] += v);
        }
      }
    }
    int sum(int x, int y) {
      int ans = 0;
      for (int i = x; (i > 0); (i -= NumMatrix::lowbit(i))) {
        for (int j = y; (j > 0); (j -= NumMatrix::lowbit(j))) {
          (ans += tree[i][j]);
        }
      }
      return ans;
    }
    void update(int x, int y, int v) {
      NumMatrix::add((x + 1), (y + 1), (v - nums[(x + 1)][(y + 1)]));
      (nums[(x + 1)][(y + 1)] = v);
    }
    int sumRegion(int a, int b, int c, int d) {
      return [&]() {
        auto jleft = [&]() {
          auto jleft = [&]() {
            auto jleft = NumMatrix::sum((c + 1), (d + 1));
            auto jright = NumMatrix::sum(a, (d + 1));
            return (jleft - jright);
          }();
          auto jright = NumMatrix::sum((c + 1), b);
          return (jleft - jright);
        }();
        auto jright = NumMatrix::sum(a, b);
        return (jleft + jright);
      }();
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TwoDimensionSingleAddIntervalQuery() {}
};

/* Original teaching comments:
// 二维数组上单点增加、范围查询，使用树状数组的模版
// 测试链接 : https://leetcode.cn/problems/range-sum-query-2d-mutable/
                // 入参二维数组下标从0开始
                // 树状数组一定下标从1开始
                // 从(1,1)到(x,y)这个部分的累加和
                // 实际二维数组的位置是(x,y)
                // 树状数组上的位置是(x+1, y+1)
                // 题目说的是单点更新，转化成单点增加(老值-新值)即可
                // 不要忘了在nums中把老值改成新值
                // 实际二维数组的位置是(x,y)
                // 树状数组上的位置是(x+1, y+1)
*/
