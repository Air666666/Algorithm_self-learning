// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/736e12861f9746ab8ae064d4aae2d5a9

// Source: src/class087/Code01_BuyMonster.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_BuyMonster {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_BuyMonster() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      int n = static_cast<int>(in.nval);
      Array<int> a = make_array<int>((n + 1));
      Array<int> b = make_array<int>((n + 1));
      for (int i = 1; (i <= n); (i++)) {
        in.nextToken();
        (a[i] = static_cast<int>(in.nval));
        in.nextToken();
        (b[i] = static_cast<int>(in.nval));
      }
      out.println(Code01_BuyMonster::compute1(n, a, b));
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1(int n, Array<int> a, Array<int> b) {
    int m = 0;
    for (int money : b) {
      (m += money);
    }
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = std::numeric_limits<int>::min());
        if ((dp[(i - 1)][j] >= a[i])) {
          (dp[i][j] = dp[(i - 1)][j]);
        }
        if ((((j - b[i]) >= 0) &&
             (dp[(i - 1)][(j - b[i])] != std::numeric_limits<int>::min()))) {
          (dp[i][j] = jmax(dp[i][j], (dp[(i - 1)][(j - b[i])] + a[i])));
        }
      }
    }
    int ans = (-1);
    for (int j = 0; (j <= m); (j++)) {
      if ((dp[n][j] != std::numeric_limits<int>::min())) {
        (ans = j);
        break;
      }
    }
    return ans;
  }
  static int compute2(int n, Array<int> a, Array<int> b) {
    int m = 0;
    for (int money : b) {
      (m += money);
    }
    Array<int> dp = make_array<int>((m + 1));
    {
      int i = 1;
      int cur = {};
      for (; (i <= n); (i++)) {
        for (int j = m; (j >= 0); (j--)) {
          (cur = std::numeric_limits<int>::min());
          if ((dp[j] >= a[i])) {
            (cur = dp[j]);
          }
          if ((((j - b[i]) >= 0) &&
               (dp[(j - b[i])] != std::numeric_limits<int>::min()))) {
            (cur = jmax(cur, (dp[(j - b[i])] + a[i])));
          }
          (dp[j] = cur);
        }
      }
    }
    int ans = (-1);
    for (int j = 0; (j <= m); (j++)) {
      if ((dp[j] != std::numeric_limits<int>::min())) {
        (ans = j);
        break;
      }
    }
    return ans;
  }
  static int compute3(int n, Array<int> a, Array<int> b) {
    int m = 0;
    for (int ability : a) {
      (m += ability);
    }
    Array<Array<int>> dp = make_array<int>((n + 1), (m + 1));
    for (int j = 1; (j <= m); (j++)) {
      (dp[0][j] = std::numeric_limits<int>::max());
    }
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 0; (j <= m); (j++)) {
        (dp[i][j] = std::numeric_limits<int>::max());
        if (((j >= a[i]) &&
             (dp[(i - 1)][j] != std::numeric_limits<int>::max()))) {
          (dp[i][j] = dp[(i - 1)][j]);
        }
        if ((((j - a[i]) >= 0) &&
             (dp[(i - 1)][(j - a[i])] != std::numeric_limits<int>::max()))) {
          (dp[i][j] = jmin(dp[i][j], (dp[(i - 1)][(j - a[i])] + b[i])));
        }
      }
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = 0; (j <= m); (j++)) {
      (ans = jmin(ans, dp[n][j]));
    }
    return ((ans == std::numeric_limits<int>::max()) ? (-1) : ans);
  }
  static int compute4(int n, Array<int> a, Array<int> b) {
    int m = 0;
    for (int ability : a) {
      (m += ability);
    }
    Array<int> dp = make_array<int>((m + 1));
    for (int j = 1; (j <= m); (j++)) {
      (dp[j] = std::numeric_limits<int>::max());
    }
    {
      int i = 1;
      int cur = {};
      for (; (i <= n); (i++)) {
        for (int j = m; (j >= 0); (j--)) {
          (cur = std::numeric_limits<int>::max());
          if (((j >= a[i]) && (dp[j] != std::numeric_limits<int>::max()))) {
            (cur = dp[j]);
          }
          if ((((j - a[i]) >= 0) &&
               (dp[(j - a[i])] != std::numeric_limits<int>::max()))) {
            (cur = jmin(cur, (dp[(j - a[i])] + b[i])));
          }
          (dp[j] = cur);
        }
      }
    }
    int ans = std::numeric_limits<int>::max();
    for (int j = 0; (j <= m); (j++)) {
      (ans = jmin(ans, dp[j]));
    }
    return ((ans == std::numeric_limits<int>::max()) ? (-1) : ans);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_BuyMonster::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 贿赂怪兽
// 开始时你的能力是0，你的目标是从0号怪兽开始，通过所有的n只怪兽
// 如果你当前的能力小于i号怪兽的能力，则必须付出b[i]的钱贿赂这个怪兽
// 然后怪兽就会加入你，他的能力a[i]直接累加到你的能力上
// 如果你当前的能力大于等于i号怪兽的能力，你可以选择直接通过，且能力不会下降
// 但你依然可以选择贿赂这个怪兽，然后怪兽的能力直接累加到你的能力上
// 返回通过所有的怪兽，需要花的最小钱数
// 测试链接 : https://www.nowcoder.com/practice/736e12861f9746ab8ae064d4aae2d5a9
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 讲解本题的目的不仅仅是为了通过这个题，而是进行如下的思考:
        // 假设a[i]数值的范围很大，但是b[i]数值的范围不大，该怎么做？
        // 假设a[i]数值的范围不大，但是b[i]数值的范围很大，又该怎么做？
        // 假设a[i]数值的范围很大，但是b[i]数值的范围不大
        // 时间复杂度O(n * 所有怪兽的钱数累加和)
                // dp[i][j] : 花的钱不能超过j，通过前i个怪兽，最大能力是多少
                // 如果dp[i][j] == Integer.MIN_VALUE
                // 表示花的钱不能超过j，无论如何都无法通过前i个怪兽
        // 就是方法1的空间压缩版本
        // 假设a[i]数值的范围不大，但是b[i]数值的范围很大
        // 时间复杂度O(n * 所有怪兽的能力累加和)
                // dp[i][j] :
能力正好是j，并且确保能通过前i个怪兽，需要至少花多少钱
                // 如果dp[i][j] == Integer.MAX_VALUE
                // 表示能力正好是j，无论如何都无法通过前i个怪兽
        // 就是方法3的空间压缩版本
*/
