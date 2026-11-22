// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1776

// Source: src/class075/Code02_BoundedKnapsackWithBinarySplitting.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BoundedKnapsackWithBinarySplitting {
  inline static int MAXN = 1001;
  inline static int MAXW = 40001;
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXW);
  inline static int n = {};
  inline static int t = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BoundedKnapsackWithBinarySplitting() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (t = static_cast<int>(in.nval));
      (m = 0);
      {
        int i = 1;
        int value = {};
        int weight = {};
        int cnt = {};
        for (; (i <= n); (i++)) {
          in.nextToken();
          (value = static_cast<int>(in.nval));
          in.nextToken();
          (weight = static_cast<int>(in.nval));
          in.nextToken();
          (cnt = static_cast<int>(in.nval));
          for (int k = 1; (k <= cnt); (k = jshl(k, 1))) {
            (v[(++m)] = (k * value));
            (w[m] = (k * weight));
            (cnt -= k);
          }
          if ((cnt > 0)) {
            (v[(++m)] = (cnt * value));
            (w[m] = (cnt * weight));
          }
        }
      }
      out.println(Code02_BoundedKnapsackWithBinarySplitting::compute());
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
  Code02_BoundedKnapsackWithBinarySplitting::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 多重背包通过二进制分组转化成01背包(模版)
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 把每一种货物根据个数做二进制分组，去生成衍生商品
        // 衍生出来的每一种商品，价值放入v、重量放入w
        // 时间复杂度O(t * (log(第1种商品的个数) + log(第2种商品的个数) + ... +
log(第n种商品的个数)))
        // 对每一种商品的个数取log，所以时间复杂度虽然大于O(n *
t)，但也不会大多少
        // 多重背包最常用的方式
                                // 整个文件最重要的逻辑 : 二进制分组
                                // 一般都使用这种技巧，这段代码非常重要
                                // 虽然时间复杂度不如单调队列优化的版本
                                // 但是好写，而且即便是比赛，时间复杂度也达标
                                // 二进制分组的时间复杂度为O(log cnt)
        // 01背包的空间压缩代码(模版)
*/
