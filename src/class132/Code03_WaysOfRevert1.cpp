// Source: src/class132/Code03_WaysOfRevert1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_WaysOfRevert1 {
  inline static int MOD = 998244353;
  inline static int MAXN = 10001;
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int n = {};
  inline static int m = 200;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_WaysOfRevert1() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (arr[i] = static_cast<int>(in.nval));
      }
      out.println(Code03_WaysOfRevert1::compute1());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<Array<Array<int>>> dp = make_array<int>((n + 1), (m + 1), 2);
    for (int i = 0; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j][0] = (-1));
        (dp[i][j][1] = (-1));
      }
    }
    return Code03_WaysOfRevert1::f1(n, 0, 1, dp);
  }
  static int f1(int i, int v, int s, Array<Array<Array<int>>> dp) {
    if ((i == 0)) {
      return s;
    }
    if ((dp[i][v][s] != (-1))) {
      return dp[i][v][s];
    }
    int ans = 0;
    if ((arr[i] != 0)) {
      if (((arr[i] >= v) || (s == 1))) {
        (ans = Code03_WaysOfRevert1::f1((i - 1), arr[i], ((arr[i] > v) ? 0 : 1),
                                        dp));
      }
    } else {
      for (int cur = (v + 1); (cur <= m); (cur++)) {
        (ans =
             jrem((ans + Code03_WaysOfRevert1::f1((i - 1), cur, 0, dp)), MOD));
      }
      if ((v != 0)) {
        (ans = jrem((ans + Code03_WaysOfRevert1::f1((i - 1), v, 1, dp)), MOD));
      }
      if ((s == 1)) {
        for (int cur = 1; (cur < v); (cur++)) {
          (ans = jrem((ans + Code03_WaysOfRevert1::f1((i - 1), cur, 1, dp)),
                      MOD));
        }
      }
    }
    (dp[i][v][s] = ans);
    return ans;
  }
  static int compute2() {
    Array<Array<Array<int>>> dp = make_array<int>((n + 1), (m + 1), 2);
    for (int v = 0; (v <= m); (v++)) {
      (dp[0][v][0] = 0);
      (dp[0][v][1] = 1);
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int v = 0; (v <= m); (v++)) {
        for (int s = 0; (s <= 1); (s++)) {
          int ans = 0;
          if ((arr[i] != 0)) {
            if (((arr[i] >= v) || (s == 1))) {
              (ans = dp[(i - 1)][arr[i]][((arr[i] > v) ? 0 : 1)]);
            }
          } else {
            for (int cur = (v + 1); (cur <= m); (cur++)) {
              (ans = jrem((ans + dp[(i - 1)][cur][0]), MOD));
            }
            if ((v != 0)) {
              (ans = jrem((ans + dp[(i - 1)][v][1]), MOD));
            }
            if ((s == 1)) {
              for (int cur = 1; (cur < v); (cur++)) {
                (ans = jrem((ans + dp[(i - 1)][cur][1]), MOD));
              }
            }
          }
          (dp[i][v][s] = ans);
        }
      }
    }
    return dp[n][0][1];
  }
  static int compute3() {
    Array<Array<int>> memo = make_array<int>((m + 1), 2);
    Array<Array<int>> dp = make_array<int>((m + 1), 2);
    for (int v = 0; (v <= m); (v++)) {
      (memo[v][0] = 0);
      (memo[v][1] = 1);
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int v = 0; (v <= m); (v++)) {
        for (int s = 0; (s <= 1); (s++)) {
          int ans = 0;
          if ((arr[i] != 0)) {
            if (((arr[i] >= v) || (s == 1))) {
              (ans = memo[arr[i]][((arr[i] > v) ? 0 : 1)]);
            }
          } else {
            for (int cur = (v + 1); (cur <= m); (cur++)) {
              (ans = jrem((ans + memo[cur][0]), MOD));
            }
            if ((v != 0)) {
              (ans = jrem((ans + memo[v][1]), MOD));
            }
            if ((s == 1)) {
              for (int cur = 1; (cur < v); (cur++)) {
                (ans = jrem((ans + memo[cur][1]), MOD));
              }
            }
          }
          (dp[v][s] = ans);
        }
      }
      Array<Array<int>> tmp = memo;
      (memo = dp);
      (dp = tmp);
    }
    return memo[0][1];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_WaysOfRevert1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 还原数组的方法数(不优化枚举)
// 原本有一个长度为n的数组arr，下标从1开始，数组中都是<=200的正数
// 并且任意i位置的数字都满足 : arr[i] <= max(arr[i-1], arr[i+1])
// 特别的，arr[1] <= arr[2]，arr[n] <= arr[n-1]
// 但是输入的arr中有些数字丢失了，丢失的数字用0表示
// 返回还原成不违规的arr有多少种方法，答案对 998244353 取模
// 3 <= n <= 10^4
// 测试链接 : https://www.nowcoder.com/practice/49c5284278974cbda474ec13d8bd86a9
// 提交以下的code，提交时请把类名改成"Main"，无法通过所有测试用例
// 需要优化枚举才能通过所有测试用例，具体看本节课Code03_WaysOfRevert2文件的实现
        // 递归 + 记忆化搜索，不优化枚举
        // 时间复杂度O(n * m平方)
        // 1...i范围上去决定数字，i+1位置的数字已经变成了v
        // 如果s == 0, 表示i+1位置变成的数字v > i+2位置变成的数字
        // 如果s == 1, 表示i+1位置变成的数字v <= i+2位置变成的数字
        // 返回还原的方法数
        // 严格位置依赖的动态规划，不优化枚举
        // 时间复杂度O(n * m平方)
        // 空间压缩版本，不优化枚举
        // 时间复杂度O(n * m平方)
*/
