// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/range-sum-query-2d-immutable/

// Source: src/class048/Code01_PrefixSumMatrix.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_PrefixSumMatrix {
  struct NumMatrix;
  struct NumMatrix {
    Array<Array<int>> sum = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    NumMatrix(Array<Array<int>> matrix) {
      int n = matrix.length;
      int m = matrix[0].length;
      (sum = make_array<int>((n + 1), (m + 1)));
      {
        int a = 1;
        int c = 0;
        for (; (c < n); (a++), (c++)) {
          {
            int b = 1;
            int d = 0;
            for (; (d < m); (b++), (d++)) {
              (sum[a][b] = matrix[c][d]);
            }
          }
        }
      }
      for (int i = 1; (i <= n); (i++)) {
        for (int j = 1; (j <= m); (j++)) {
          (sum[i][j] +=
           ((sum[i][(j - 1)] + sum[(i - 1)][j]) - sum[(i - 1)][(j - 1)]));
        }
      }
    }
    int sumRegion(int a, int b, int c, int d) {
      (c++);
      (d++);
      return (((sum[c][d] - sum[c][b]) - sum[a][d]) + sum[a][b]);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_PrefixSumMatrix() {}
};

/* Original teaching comments:
// 利用二维前缀和信息迅速得到二维区域和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-2d-immutable/
*/
