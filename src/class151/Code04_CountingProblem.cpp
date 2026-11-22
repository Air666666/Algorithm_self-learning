// Source: src/class151/Code04_CountingProblem.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CountingProblem {
  inline static int MOD = 1000000007;
  inline static int MAXN = 1000001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> left = make_array<int>(MAXN);
  inline static Array<int> right = make_array<int>(MAXN);
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static Array<i64> tmp = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CountingProblem() {}
  static void build() {
    {
      int i = 1;
      int top = 0;
      int pos = {};
      for (; (i <= n); (i++)) {
        (pos = top);
        while (((pos > 0) && (arr[stack[pos]] < arr[i]))) {
          (pos--);
        }
        if ((pos > 0)) {
          (right[stack[pos]] = i);
        }
        if ((pos < top)) {
          (left[i] = stack[(pos + 1)]);
        }
        (stack[(++pos)] = i);
        (top = pos);
      }
    }
  }
  static void dfs(int u, Array<Array<int>> dp) {
    if ((u == 0)) {
      return;
    }
    Code04_CountingProblem::dfs(left[u], dp);
    Code04_CountingProblem::dfs(right[u], dp);
    for (int j = 1; (j <= m); (j++)) {
      (tmp[j] = jrem((static_cast<i64>(dp[left[u]][(j - 1)]) * dp[right[u]][j]),
                     MOD));
    }
    for (int j = 1; (j <= m); (j++)) {
      (dp[u][j] = static_cast<int>(jrem((dp[u][(j - 1)] + tmp[j]), MOD)));
    }
  }
  static void clear() {
    j::fill(left, 1, (n + 1), 0);
    j::fill(right, 1, (n + 1), 0);
  }
  static i64 compute() {
    Code04_CountingProblem::build();
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int j = 0; (j <= m); (j++)) {
      (dp[0][j] = 1);
    }
    Code04_CountingProblem::dfs(stack[1], dp);
    Code04_CountingProblem::clear();
    return dp[stack[1]][m];
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int cases = static_cast<int>(in.nval);
    for (int t = 1; (t <= cases); (t++)) {
      in.nextToken();
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (m = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      out.println(Code04_CountingProblem::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_CountingProblem::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 序列计数
// 有一个概念叫，最左端最大值位置，表示一段范围上
// 如果最大值有一个，那么最大值所在的位置，就是最左端最大值位置
// 如果最大值有多个，最左的那个所在的位置，就是最左端最大值位置
// 给定一个长度为n的数组A，那么必然存在等长的数组B，当选择同样的子范围时
//
两者在这段范围上，最左端最大值位置是相同的，不仅存在这样的数组B，而且数量无限多
// 现在要求，数组B中的每个值都在[1,m]范围，返回有多少个这样的数组，答案对
1000000007 取模
// 2 <= n、m <= 2 * 10^5    1 <= A[i] <= m    n * m <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/CF1748E
// 测试链接 : https://codeforces.com/problemset/problem/1748/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 所有数字
        // 笛卡尔树需要
        // tmp是动态规划的临时结果
                // 虽然n * m <= 10^6，但是n和m，单独都是2 * 10^5规模
                // 所以提前准备固定大小的表是不可能的，空间根本接受不了
                //
所以根据此时具体的n和m的大小，临时申请动态规划表，总大小不超过10^6
                        // 没有节点时，不管要求节点值是什么，都默认有1种形态
                        // 因为没有节点时，根本不影响任何决策
*/
