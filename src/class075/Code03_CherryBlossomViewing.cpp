// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1833

// Source: src/class075/Code03_CherryBlossomViewing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CherryBlossomViewing {
  inline static int MAXN = 100001;
  inline static int MAXW = 1001;
  inline static int ENOUGH = 1001;
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXW);
  inline static int hour1 = {};
  inline static int minute1 = {};
  inline static int hour2 = {};
  inline static int minute2 = {};
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CherryBlossomViewing() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    in.parseNumbers();
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (hour1 = static_cast<int>(in.nval));
      in.nextToken();
      in.nextToken();
      (minute1 = static_cast<int>(in.nval));
      in.nextToken();
      (hour2 = static_cast<int>(in.nval));
      in.nextToken();
      in.nextToken();
      (minute2 = static_cast<int>(in.nval));
      if ((minute1 > minute2)) {
        (hour2--);
        (minute2 += 60);
      }
      (t = ((((hour2 - hour1) * 60) + minute2) - minute1));
      in.nextToken();
      (n = static_cast<int>(in.nval));
      (m = 0);
      {
        int i = 0;
        int cost = {};
        int val = {};
        int cnt = {};
        for (; (i < n); (i++)) {
          in.nextToken();
          (cost = static_cast<int>(in.nval));
          in.nextToken();
          (val = static_cast<int>(in.nval));
          in.nextToken();
          (cnt = static_cast<int>(in.nval));
          if ((cnt == 0)) {
            (cnt = ENOUGH);
          }
          for (int k = 1; (k <= cnt); (k = jshl(k, 1))) {
            (v[(++m)] = (k * val));
            (w[m] = (k * cost));
            (cnt -= k);
          }
          if ((cnt > 0)) {
            (v[(++m)] = (cnt * val));
            (w[m] = (cnt * cost));
          }
        }
      }
      out.println(Code03_CherryBlossomViewing::compute());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    j::fill(dp, 0, (t + 1), 0);
    for (int i = 1; (i <= m); (i++)) {
      for (int j = t; (j >= w[i]); (j--)) {
        (dp[j] = jmax(dp[j], (dp[(j - w[i])] + v[i])));
      }
    }
    return dp[t];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_CherryBlossomViewing::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 观赏樱花
// 给定一个背包的容量t，一共有n种货物，并且给定每种货物的信息
// 花费(cost)、价值(val)、数量(cnt)
// 如果cnt == 0，代表这种货物可以无限选择
// 如果cnt > 0，那么cnt代表这种货物的数量
// 挑选货物的总容量在不超过t的情况下，返回能得到的最大价值
// 背包容量不超过1000，每一种货物的花费都>0
// 测试链接 : https://www.luogu.com.cn/problem/P1833
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 完全背包转化为多重背包
// 再把多重背包通过二进制分组转化为01背包
                        // 跳过冒号
                        // 跳过冒号
                        // 计算背包容量
                                // 二进制分组
        // 01背包的空间压缩代码(模版)
*/
