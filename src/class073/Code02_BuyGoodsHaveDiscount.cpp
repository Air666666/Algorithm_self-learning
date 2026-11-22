// Source: src/class073/Code02_BuyGoodsHaveDiscount.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_BuyGoodsHaveDiscount {
  inline static int MAXN = 501;
  inline static int MAXX = 100001;
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<i64> val = make_array<i64>(MAXN);
  inline static Array<i64> dp = make_array<i64>(MAXX);
  inline static int n = {};
  inline static int m = {};
  inline static int x = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_BuyGoodsHaveDiscount() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      (m = 1);
      in.nextToken();
      (x = static_cast<int>(in.nval));
      i64 ans = 0;
      i64 happy = 0;
      {
        int i = 1;
        int pre = {};
        int cur = {};
        int well = {};
        for (; (i <= n); (i++)) {
          in.nextToken();
          (pre = static_cast<int>(in.nval));
          in.nextToken();
          (cur = static_cast<int>(in.nval));
          in.nextToken();
          (happy = static_cast<i64>(in.nval));
          (well = ((pre - cur) - cur));
          if ((well >= 0)) {
            (x += well);
            (ans += happy);
          } else {
            (cost[m] = (-well));
            (val[(m++)] = happy);
          }
        }
      }
      (ans += Code02_BuyGoodsHaveDiscount::compute());
      out.println(ans);
    }
    out.flush();
    out.close();
    br.close();
  }
  static i64 compute() {
    j::fill(dp, 0, (x + 1), 0);
    for (int i = 1; (i <= m); (i++)) {
      for (int j = x; (j >= cost[i]); (j--)) {
        (dp[j] = jmax(dp[j], (dp[(j - cost[i])] + val[i])));
      }
    }
    return dp[x];
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_BuyGoodsHaveDiscount::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 夏季特惠
// 某公司游戏平台的夏季特惠开始了，你决定入手一些游戏
// 现在你一共有X元的预算，平台上所有的 n 个游戏均有折扣
// 标号为 i 的游戏的原价a_i元，现价只要b_i元
// 也就是说该游戏可以优惠 a_i - b_i，并且你购买该游戏能获得快乐值为w_i
// 由于优惠的存在，你可能做出一些冲动消费导致最终买游戏的总费用超过预算
// 只要满足 : 获得的总优惠金额不低于超过预算的总金额
// 那在心理上就不会觉得吃亏。
// 现在你希望在心理上不觉得吃亏的前提下，获得尽可能多的快乐值。
// 测试链接 : https://leetcode.cn/problems/tJau2o/
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的所有代码，并把主类名改成"Main"，可以直接通过
        // 对于"一定要买的商品"，直接买！
        // 只把"需要考虑的商品"放入cost、val数组
                                // 原价
                                // 现价
                                // 快乐值
                                // 如下是一件"一定要买的商品"
                                // 预算 = 100，商品原价 = 10，打折后 = 3
                                // 那么好处(well) = (10 - 3) - 3 = 4
                                //
所以，可以认为这件商品把预算增加到了104！一定要买！
                                // 如下是一件"需要考虑的商品"
                                // 预算 = 104，商品原价 = 10，打折后 = 8
                                // 那么好处(well) = (10 - 8) - 8 = -6
                                // 所以，可以认为这件商品就花掉6元！
                                // 也就是说以后花的不是打折后的值，是"坏处"
*/
