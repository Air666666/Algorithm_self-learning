// Source: src/class138/Other2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Other2 {
  inline static int MAXN = 251;
  inline static int MAXW = 1001;
  inline static double NA = (-1e9);
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static Array<int> talent = make_array<int>(MAXN);
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<double> dp = make_array<double>(MAXW);
  inline static int n = {};
  inline static int w = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Other2() {}
  static bool check(double x) {
    for (int i = 1; (i <= n); (i++)) {
      (value[i] = (static_cast<double>(talent[i]) - (x * weight[i])));
    }
    (dp[0] = 0);
    j::fill(dp, 1, (w + 1), NA);
    for (int i = 1; (i <= n); (i++)) {
      {
        int p = w;
        int j = {};
        for (; (p >= 0); (p--)) {
          (j = static_cast<int>((p + weight[i])));
          if ((j >= w)) {
            (dp[w] = jmax(dp[w], (dp[p] + value[i])));
          } else {
            (dp[j] = jmax(dp[j], (dp[p] + value[i])));
          }
        }
      }
    }
    return (dp[w] >= 0);
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (w = static_cast<int>(in.nval));
    for (int i = 1; (i <= n); (i++)) {
      in.nextToken();
      (weight[i] = static_cast<int>(in.nval));
      in.nextToken();
      (talent[i] = static_cast<int>(in.nval));
    }
    double l = 0;
    double r = 0;
    double x = {};
    for (int i = 1; (i <= n); (i++)) {
      (r += talent[i]);
    }
    for (int i = 1; (i <= 60); (i++)) {
      (x = jdiv((l + r), 2));
      if (Other2::check(x)) {
        (l = x);
      } else {
        (r = x);
      }
    }
    out.println(static_cast<int>((l * 1000)));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Other2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 题目2，牛群的才艺展示，另一种二分的写法
// 思路是不变的，二分的写法多种多样
// 代码中打注释的位置，就是更简单的二分逻辑，其他代码没有变化
// 测试链接 : https://www.luogu.com.cn/problem/P4377
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                // 二分进行60次，足够达到题目要求的精度
                // 二分完成后，l就是答案
*/
