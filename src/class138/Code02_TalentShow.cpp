// Source: src/class138/Code02_TalentShow.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TalentShow {
  inline static int MAXN = 251;
  inline static int MAXW = 1001;
  inline static double NA = (-1e9);
  inline static double sml = 1e-6;
  inline static Array<int> weight = make_array<int>(MAXN);
  inline static Array<int> talent = make_array<int>(MAXN);
  inline static Array<double> value = make_array<double>(MAXN);
  inline static Array<double> dp = make_array<double>(MAXW);
  inline static int n = {};
  inline static int w = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TalentShow() {}
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
    double ans = 0;
    while (((l < r) && ((r - l) >= sml))) {
      (x = jdiv((l + r), 2));
      if (Code02_TalentShow::check(x)) {
        (ans = x);
        (l = (x + sml));
      } else {
        (r = (x - sml));
      }
    }
    out.println(static_cast<int>((ans * 1000)));
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_TalentShow::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 牛群的才艺展示
// 一共有n只牛，每只牛有重量和才艺两个属性值
// 要求一定要选若干只牛，使得总重量不少于w，并且选出的牛，希望让
// 才艺的和 / 重量的和，这个比值尽量大
// 返回该比值 * 1000的整数结果，小数部分舍弃
// 1 <= n <= 250
// 1 <= w <= 1000
// 1 <= 牛的重量 <= 10^6
// 1 <= 牛的才艺 <= 10^3
// 测试链接 : https://www.luogu.com.cn/problem/P4377
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 足够小代表无效解
        // 最小精度
        // 重量
        // 才艺
        // (才艺 - x * 重量)的结余
        // dp[i][j] : 1...i号牛自由选择，重量必须是j的情况下，最大的结余和
        //
特别的，dp[i][w]表示1...i号牛自由选择，重量必须是w、w+1...的所有情况中，最大的结余和
        // 为了节省时间和空间选择这么定义，同时做空间压缩
*/
