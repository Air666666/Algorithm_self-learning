// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

// Source: src/class076/Code03_MinimumScoreTriangulationOfPolygon.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MinimumScoreTriangulationOfPolygon {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MinimumScoreTriangulationOfPolygon() {}
  static int minScoreTriangulation1(Array<int> arr) {
    int n = arr.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < n); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    return Code03_MinimumScoreTriangulationOfPolygon::f(arr, 0, (n - 1), dp);
  }
  static int f(Array<int> arr, int l, int r, Array<Array<int>> dp) {
    if ((dp[l][r] != (-1))) {
      return dp[l][r];
    }
    int ans = std::numeric_limits<int>::max();
    if (((l == r) || (l == (r - 1)))) {
      (ans = 0);
    } else {
      for (int m = (l + 1); (m < r); (m++)) {
        (ans = jmin(ans, ([&]() {
                      auto jleft = Code03_MinimumScoreTriangulationOfPolygon::f(
                          arr, l, m, dp);
                      auto jright =
                          Code03_MinimumScoreTriangulationOfPolygon::f(arr, m,
                                                                       r, dp);
                      return (jleft + jright);
                    }() + ((arr[l] * arr[m]) * arr[r]))));
      }
    }
    (dp[l][r] = ans);
    return ans;
  }
  static int minScoreTriangulation2(Array<int> arr) {
    int n = arr.length;
    Array<Array<int>> dp = make_array<int>(n, n);
    for (int l = (n - 3); (l >= 0); (l--)) {
      for (int r = (l + 2); (r < n); (r++)) {
        (dp[l][r] = std::numeric_limits<int>::max());
        for (int m = (l + 1); (m < r); (m++)) {
          (dp[l][r] = jmin(dp[l][r], ((dp[l][m] + dp[m][r]) +
                                      ((arr[l] * arr[m]) * arr[r]))));
        }
      }
    }
    return dp[0][(n - 1)];
  }
};

/* Original teaching comments:
// 多边形三角剖分的最低得分
// 你有一个凸的 n 边形，其每个顶点都有一个整数值
// 给定一个整数数组values，其中values[i]是第i个顶点的值(顺时针顺序)
// 假设将多边形 剖分 为 n - 2 个三角形
// 对于每个三角形，该三角形的值是顶点标记的乘积
// 三角剖分的分数是进行三角剖分后所有 n - 2 个三角形的值之和
// 返回 多边形进行三角剖分后可以得到的最低分
// 测试链接 :
https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/
        // 记忆化搜索
                        // l....r >=3
                        // 0..1..2..3..4...5
                                // l m r
        // 严格位置依赖的动态规划
*/
