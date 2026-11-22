// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/distribute-repeating-integers/

// Source: src/class081/Code04_DistributeRepeatingIntegers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DistributeRepeatingIntegers {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DistributeRepeatingIntegers() {}
  static bool canDistribute(Array<int> nums, Array<int> quantity) {
    j::sort(nums);
    int n = 1;
    for (int i = 1; (i < nums.length); (i++)) {
      if ((nums[(i - 1)] != nums[i])) {
        (n++);
      }
    }
    Array<int> cnt = make_array<int>(n);
    int c = 1;
    {
      int i = 1;
      int j = 0;
      for (; (i < nums.length); (i++)) {
        if ((nums[(i - 1)] != nums[i])) {
          (cnt[(j++)] = c);
          (c = 1);
        } else {
          (c++);
        }
      }
    }
    (cnt[(n - 1)] = c);
    int m = quantity.length;
    Array<int> sum = make_array<int>(jshl(1, m));
    {
      int i = 0;
      int v = {};
      int h = {};
      for (; (i < quantity.length); (i++)) {
        (v = quantity[i]);
        (h = jshl(1, i));
        for (int j = 0; (j < h); (j++)) {
          (sum[(h | j)] = (sum[j] + v));
        }
      }
    }
    Array<Array<int>> dp = make_array<int>(jshl(1, m), n);
    return Code04_DistributeRepeatingIntegers::f(cnt, sum, (jshl(1, m) - 1), 0,
                                                 dp);
  }
  static bool f(Array<int> cnt, Array<int> sum, int status, int index,
                Array<Array<int>> dp) {
    if ((status == 0)) {
      return true;
    }
    if ((index == cnt.length)) {
      return false;
    }
    if ((dp[status][index] != 0)) {
      return (dp[status][index] == 1);
    }
    bool ans = false;
    int k = cnt[index];
    for (int j = status; (j > 0); (j = ((j - 1) & status))) {
      if (((sum[j] <= k) && Code04_DistributeRepeatingIntegers::f(
                                cnt, sum, (status ^ j), (index + 1), dp))) {
        (ans = true);
        break;
      }
    }
    if ((!ans)) {
      (ans = Code04_DistributeRepeatingIntegers::f(cnt, sum, status,
                                                   (index + 1), dp));
    }
    (dp[status][index] = (ans ? 1 : (-1)));
    return ans;
  }
};

/* Original teaching comments:
// 分配重复整数
// 给你一个长度为n的整数数组nums，这个数组中至多有50个不同的值
// 同时你有m个顾客的订单quantity，其中整数quantity[i]是第i位顾客订单的数目
// 请你判断是否能将nums中的整数分配给这些顾客，且满足：
// 第i位顾客恰好有quantity[i]个整数、第i位顾客拿到的整数都是相同的
// 每位顾客都要满足上述两个要求，返回是否能都满足
// 测试链接 : https://leetcode.cn/problems/distribute-repeating-integers/
        // 时间复杂度O(n * 3的m次方)，空间复杂度O(n * 2的m次方)
        // ppt上有时间复杂度解析
                // 下面这个枚举是生成quantity中的每个子集，所需要数字的个数
        // 当前来到的数字，编号index，个数cnt[index]
        // status : 订单状态，1还需要去满足，0已经满足过了
                // status != 0
                // 这是整个实现最核心的枚举
                // j枚举了status的所有子集状态
                // 建议记住
*/
