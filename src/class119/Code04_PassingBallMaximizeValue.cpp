// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/

// Source: src/class119/Code04_PassingBallMaximizeValue.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PassingBallMaximizeValue {
  inline static int MAXN = 100001;
  inline static int LIMIT = 34;
  inline static int power = {};
  inline static int m = {};
  inline static Array<int> kbits = make_array<int>(LIMIT);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static Array<Array<i64>> stsum = make_array<i64>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PassingBallMaximizeValue() {}
  static void build(i64 k) {
    (power = 0);
    while ((jshl(1LL, power) <= jshr(k, 1))) {
      (power++);
    }
    (m = 0);
    for (int p = power; (p >= 0); (p--)) {
      if ((jshl(1LL, p) <= k)) {
        (kbits[(m++)] = p);
        (k -= jshl(1LL, p));
      }
    }
  }
  static i64 getMaxFunctionValue(JList<int> receiver, i64 k) {
    Code04_PassingBallMaximizeValue::build(k);
    int n = receiver.size();
    for (int i = 0; (i < n); (i++)) {
      (stjump[i][0] = receiver.get(i));
      (stsum[i][0] = receiver.get(i));
    }
    for (int p = 1; (p <= power); (p++)) {
      for (int i = 0; (i < n); (i++)) {
        (stjump[i][p] = stjump[stjump[i][(p - 1)]][(p - 1)]);
        (stsum[i][p] =
             (stsum[i][(p - 1)] + stsum[stjump[i][(p - 1)]][(p - 1)]));
      }
    }
    i64 sum = {};
    i64 ans = 0;
    {
      int i = 0;
      int cur = {};
      for (; (i < n); (i++)) {
        (cur = i);
        (sum = i);
        for (int j = 0; (j < m); (j++)) {
          (sum += stsum[cur][kbits[j]]);
          (cur = stjump[cur][kbits[j]]);
        }
        (ans = jmax(ans, sum));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 在传球游戏中最大化函数值
// 给定一个长度为n的数组receiver和一个整数k
// 总共有n名玩家，编号0 ~ n-1，这些玩家在玩一个传球游戏
// receiver[i]表示编号为i的玩家会传球给下一个人的编号
// 玩家可以传球给自己，也就是说receiver[i]可能等于i
// 你需要选择一名开始玩家，然后开始传球，球会被传恰好k次
// 如果选择编号为x的玩家作为开始玩家
// 函数f(x)表示从x玩家开始，k次传球内所有接触过球的玩家编号之和
// 如果某位玩家多次触球，则累加多次
// f(x) = x + receiver[x] + receiver[receiver[x]] + ...
// 你的任务时选择开始玩家x，目的是最大化f(x)，返回函数的最大值
// 测试链接 :
https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/
        // 给定k的二进制位上有几个1
        // 收集k的二进制上哪些位有1
        // 该方法是树上倍增的解法
        // 打败比例很一般但是非常好想
        // 这个题最优解来自对基环树的分析
        // 后面的课会安排基环树的内容
*/
