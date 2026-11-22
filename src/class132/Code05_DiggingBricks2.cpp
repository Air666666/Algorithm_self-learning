// Source: src/class132/Code05_DiggingBricks2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_DiggingBricks2 {
  inline static int MAXN = 51;
  inline static int MAXM = 1301;
  inline static Array<Array<int>> grid = make_array<int>(MAXN, MAXN);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, MAXM);
  inline static Array<Array<int>> max = make_array<int>(MAXN, MAXM);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_DiggingBricks2() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    for (int j = 1; (j <= n); (j++)) {
      for (int i = n; (i >= j); (i--)) {
        in.nextToken();
        (grid[i][j] = static_cast<int>(in.nval));
      }
    }
    out.println(Code05_DiggingBricks2::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    int ans = 0;
    {
      int i = 1;
      int cur = {};
      for (; (i <= n); (i++)) {
        Code05_DiggingBricks2::prepare((i - 1));
        (cur = 0);
        for (int j = 0; (j <= i); (j++)) {
          (cur += grid[i][j]);
          for (int k = jdiv(((j + 1) * j), 2); (k <= m); (k++)) {
            (dp[j][k] = (max[jmax(0, (j - 1))][(k - j)] + cur));
            (ans = jmax(ans, dp[j][k]));
          }
        }
      }
    }
    return ans;
  }
  static void prepare(int rowLimit) {
    for (int col = 0; (col <= m); (col++)) {
      {
        int row = rowLimit;
        int suf = 0;
        for (; (row >= 0); (row--)) {
          (suf = jmax(suf, dp[row][col]));
          (max[row][col] = suf);
        }
      }
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_DiggingBricks2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 从上到下挖砖块(优化枚举+空间压缩)
//
一堆组成倒三角形状的砖埋在地里，一共有n层，第1层有n块砖，每层递减，类似如下数据
// 4 2 9 5
//  3 1 7
//   2 4
//    8
// 需要从第1层开始挖，每挖开一块砖都可以获得数值作为收益，第1层的砖可以随意挖
//
但是挖到下面的砖是有条件的，想挖i层的j号砖，你需要确保i-1层的(j、j+1)块砖已经被挖开
// 最多可以挖m块砖，返回最大的收益
// 1 <= n <= 50
// 1 <= m <= 1300
// 砖块数值 <= 100
// 测试链接 : https://www.luogu.com.cn/problem/P1437
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 优化枚举 + 空间压缩
        // 时间复杂度O(n^2 * m)
        // 预处理结构优化枚举
*/
