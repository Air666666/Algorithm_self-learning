// Source: src/class127/Code05_WaysOfArrangePlates.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_WaysOfArrangePlates {
  inline static int MOD = 1000000007;
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_WaysOfArrangePlates() {}
  static int dp1(int n, int k) {
    if ((n == 1)) {
      return k;
    }
    return static_cast<int>(
        jrem(([&]() {
               auto jleft =
                   static_cast<i64>(Code05_WaysOfArrangePlates::f1((n - 1), k));
               auto jright = Code05_WaysOfArrangePlates::f1((n - 2), k);
               return (jleft + jright);
             }() *
              k),
             MOD));
  }
  static int f1(int i, int k) {
    if ((i == 0)) {
      return 1;
    }
    if ((i == 1)) {
      return (k - 1);
    }
    i64 p1 = Code05_WaysOfArrangePlates::f1((i - 1), k);
    i64 p2 = Code05_WaysOfArrangePlates::f1((i - 2), k);
    return static_cast<int>(jrem(((p1 + p2) * (k - 1)), MOD));
  }
  static int dp2(int n, int k) {
    if ((n == 1)) {
      return k;
    }
    Array<int> dp = make_array<int>(n);
    (dp[0] = 1);
    (dp[1] = (k - 1));
    for (int i = 2; (i < n); (i++)) {
      i64 p1 = dp[(i - 1)];
      i64 p2 = dp[(i - 2)];
      (dp[i] = static_cast<int>(jrem(((p1 + p2) * (k - 1)), MOD)));
    }
    return static_cast<int>(
        jrem(((static_cast<i64>(dp[(n - 1)]) + dp[(n - 2)]) * k), MOD));
  }
  static int dp3(int n, int k) {
    if ((n == 1)) {
      return k;
    }
    int s = (k - 1);
    Array<Array<int>> start = Array<Array<int>>{Array<int>{1, s}};
    Array<Array<int>> base =
        Array<Array<int>>{Array<int>{0, s}, Array<int>{1, s}};
    Array<Array<int>> ans = Code05_WaysOfArrangePlates::multiply(
        start, Code05_WaysOfArrangePlates::power(base, (n - 2)));
    return static_cast<int>(
        jrem(((static_cast<i64>(ans[0][0]) + ans[0][1]) * k), MOD));
  }
  static Array<Array<int>> multiply(Array<Array<int>> a, Array<Array<int>> b) {
    int n = a.length;
    int m = b[0].length;
    int k = a[0].length;
    Array<Array<int>> ans = make_array<int>(n, m);
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j < m); (j++)) {
        for (int c = 0; (c < k); (c++)) {
          (ans[i][j] =
               static_cast<int>(jrem((static_cast<i64>(ans[i][j]) +
                                      (static_cast<i64>(a[i][c]) * b[c][j])),
                                     MOD)));
        }
      }
    }
    return ans;
  }
  static Array<Array<int>> power(Array<Array<int>> m, int p) {
    int n = m.length;
    Array<Array<int>> ans = make_array<int>(n, n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i][i] = 1);
    }
    for (; (p != 0); (p = jshr(p, 1))) {
      if (((p & 1) != 0)) {
        (ans = Code05_WaysOfArrangePlates::multiply(ans, m));
      }
      (m = Code05_WaysOfArrangePlates::multiply(m, m));
    }
    return ans;
  }
  static int right(int n, int k) {
    Array<int> path = make_array<int>(n);
    return Code05_WaysOfArrangePlates::dfs(path, 0, k);
  }
  static int dfs(Array<int> path, int i, int k) {
    if ((i == path.length)) {
      int len = 1;
      for (int j = 1; (j < path.length); (j++)) {
        if ((path[(j - 1)] == path[j])) {
          (len++);
        } else {
          (len = 1);
        }
        if ((len > 2)) {
          return 0;
        }
      }
      return ((len > 2) ? 0 : 1);
    } else {
      int ans = 0;
      for (int j = 0; (j < k); (j++)) {
        (path[i] = j);
        (ans += Code05_WaysOfArrangePlates::dfs(path, (i + 1), k));
      }
      return ans;
    }
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"功能测试开始"));
    for (int n = 1; (n <= 8); (n++)) {
      for (int k = 1; (k <= 8); (k++)) {
        int ans1 = Code05_WaysOfArrangePlates::dp1(n, k);
        int ans2 = Code05_WaysOfArrangePlates::dp2(n, k);
        int ans3 = Code05_WaysOfArrangePlates::dp3(n, k);
        int ans4 = Code05_WaysOfArrangePlates::right(n, k);
        if ((((ans1 != ans2) || (ans1 != ans3)) || (ans1 != ans4))) {
          jout.println(String(u"出错了!"));
        }
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println();
    jout.println(String(u"性能测试开始"));
    int n = 505060123;
    int k = 303060123;
    jout.println((((String(u"数据量 : n = ") + n) + String(u", k = ")) + k));
    i64 start = {};
    i64 end = {};
    (start = millis());
    jout.println((String(u"dp2方法结果(已经取模) : ") +
                  Code05_WaysOfArrangePlates::dp2(n, k)));
    (end = millis());
    jout.println((String(u"dp2方法用时(毫秒) : ") + (end - start)));
    (start = millis());
    jout.println((String(u"dp3方法结果(已经取模) : ") +
                  Code05_WaysOfArrangePlates::dp3(n, k)));
    (end = millis());
    jout.println((String(u"dp3方法用时(毫秒) : ") + (end - start)));
    jout.println(String(u"性能测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_WaysOfArrangePlates::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 摆盘子的方法
// 一共有n个盘子k种菜，所有盘子排成一排，每个盘子只能放一种菜
// 要求最多连续两个盘子菜品一样，更长的重复出现是不允许的
// 返回摆盘的方法数，答案对 1000000007 取模
// 1 <= n <= 1000
// 1 <= k <= 1000
// 来自真实大厂笔试，对数器验证
        // 正式方法的尝试思路
        // 正式方法的普通动态规划版本
        // 时间复杂度O(n)
        // 最优解的版本，动态规划 + 矩阵快速幂优化
        // 时间复杂度O(log n)
        // 不会的同学看讲解098
        // 暴力方法
        // 为了验证
        // 暴力方法
        // 为了验证
        // 对数器
        // 为了验证
*/
