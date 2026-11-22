// 原题测试 / 参考链接（保留上游原始地址）
// https://vjudge.net/problem/OpenJ_Bailian-4150
// http://bailian.openjudge.cn/practice/4150/

// Source: src/class128/Code02_BestDeploy2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BestDeploy2 {
  inline static int MAXN = 10002;
  inline static int n = {};
  inline static Array<int> a = make_array<int>(MAXN);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BestDeploy2() {}
  static int compute() {
    Array<Array<int>> dp = make_array<int>((n + 1), 2);
    (dp[n][0] = a[n]);
    (dp[n][1] = b[n]);
    for (int i = (n - 1); (i >= 1); (i--)) {
      (dp[i][0] = jmax((a[i] + dp[(i + 1)][1]), (b[i] + dp[(i + 1)][0])));
      (dp[i][1] = jmax((b[i] + dp[(i + 1)][1]), (c[i] + dp[(i + 1)][0])));
    }
    return dp[1][0];
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (a[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (b[i] = in.nextInt());
    }
    for (int i = 1; (i <= n); (i++)) {
      (c[i] = in.nextInt());
    }
    out.println(Code02_BestDeploy2::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BestDeploy2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 感谢热心的同学，找到了题目2的在线测试
// 最好的部署
// 一共有n台机器，编号1 ~ n，所有机器排成一排
// 你只能一台一台的部署机器，你可以决定部署的顺序，最终所有机器都要部署
// 给定三个长度为n的数组a[]、b[]、c[]
// a[i] : 如果i号机器部署时，相邻有0台机器部署，此时能获得的收益
// b[i] : 如果i号机器部署时，相邻有1台机器部署，此时能获得的收益
// c[i] : 如果i号机器部署时，相邻有2台机器部署，此时能获得的收益
// 第1号机器、第n号机器当然不会有两台相邻的机器
// 返回部署的最大收益
// 1 <= n、a[i]、b[i]、c[i] <= 10^4
// 测试链接 : https://vjudge.net/problem/OpenJ_Bailian-4150
// 测试链接 : http://bailian.openjudge.cn/practice/4150/
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 课上讲的时间复杂度O(n)的方法
        // 逻辑没有任何修改
        // 读写工具类
*/
