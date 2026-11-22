// Source: src/class125/Code01_CornFields1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CornFields1 {
  inline static int MAXN = 12;
  inline static int MAXM = 12;
  inline static int MOD = 100000000;
  inline static Array<Array<int>> grid = make_array<int>(MAXN, MAXM);
  inline static Array<Array<int>> dp = make_array<int>(MAXN, jshl(1, MAXM));
  inline static int n = {};
  inline static int m = {};
  inline static int maxs = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CornFields1() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (m = static_cast<int>(in.nval));
    (maxs = jshl(1, m));
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        in.nextToken();
        (grid[i][j] = static_cast<int>(in.nval));
      }
    }
    out.println(Code01_CornFields1::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    for (int i = 0; (i < n); (i++)) {
      for (int s = 0; (s < maxs); (s++)) {
        (dp[i][s] = (-1));
      }
    }
    return Code01_CornFields1::f(0, 0);
  }
  static int f(int i, int s) {
    if ((i == n)) {
      return 1;
    }
    if ((dp[i][s] != (-1))) {
      return dp[i][s];
    }
    int ans = Code01_CornFields1::dfs(i, 0, s, 0);
    (dp[i][s] = ans);
    return ans;
  }
  static int dfs(int i, int j, int s, int ss) {
    if ((j == m)) {
      return Code01_CornFields1::f((i + 1), ss);
    }
    int ans = Code01_CornFields1::dfs(i, (j + 1), s, ss);
    if ((((grid[i][j] == 1) &&
          ((j == 0) || (Code01_CornFields1::get(ss, (j - 1)) == 0))) &&
         (Code01_CornFields1::get(s, j) == 0))) {
      (ans = jrem((ans + Code01_CornFields1::dfs(
                             i, (j + 1), s, Code01_CornFields1::set(ss, j, 1))),
                  MOD));
    }
    return ans;
  }
  static int get(int s, int j) { return (jshr(s, j) & 1); }
  static int set(int s, int j, int v) {
    return ((v == 0) ? (s & (~jshl(1, j))) : (s | jshl(1, j)));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_CornFields1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 种草的方法数(普通状压dp)
// 给定一个n*m的二维网格grid
// 网格里只有0、1两种值，0表示该田地不能种草，1表示该田地可以种草
// 种草的时候，任何两个种了草的田地不能相邻，相邻包括上、下、左、右四个方向
// 你可以随意决定种多少草，只要不破坏上面的规则即可
// 返回种草的方法数，答案对100000000取模
// 1 <= n, m <= 12
// 测试链接 : https://www.luogu.com.cn/problem/P1879
// 提交以下的code，提交时请把类名改成"Main"
// 普通状压dp的版本无法通过所有测试用例
// 有些测试样本会超时，这是dfs过程很费时导致的
        // 时间复杂度O(n * 2的m次方 * 2的m次方)
        // 当前来到i行j列
        // i-1行每列种草的状况s
        // i行每列种草的状况ss
        // 返回后续有几种方法
        // 得到状态s中j位的状态
        // 状态s中j位的状态设置成v，然后把新的值返回
*/
