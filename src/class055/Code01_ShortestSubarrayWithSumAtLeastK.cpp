// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

// Source: src/class055/Code01_ShortestSubarrayWithSumAtLeastK.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ShortestSubarrayWithSumAtLeastK {
  inline static int MAXN = 100001;
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<int> deque = make_array<int>(MAXN);
  inline static int h = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ShortestSubarrayWithSumAtLeastK() {}
  static int shortestSubarray(Array<int> arr, int K) {
    int n = arr.length;
    for (int i = 0; (i < n); (i++)) {
      (sum[(i + 1)] = (sum[i] + arr[i]));
    }
    (h = (t = 0));
    int ans = std::numeric_limits<int>::max();
    for (int i = 0; (i <= n); (i++)) {
      while (((h != t) && ((sum[i] - sum[deque[h]]) >= K))) {
        (ans = jmin(ans, (i - deque[(h++)])));
      }
      while (((h != t) && (sum[deque[(t - 1)]] >= sum[i]))) {
        (t--);
      }
      (deque[(t++)] = i);
    }
    return ((ans != std::numeric_limits<int>::max()) ? ans : (-1));
  }
};

/* Original teaching comments:
// 和至少为K的最短子数组
// 给定一个数组arr，其中的值有可能正、负、0
// 给定一个正数k
// 返回累加和>=k的所有子数组中，最短的子数组长度
// 测试链接 :
https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/
        // sum[0] : 前0个数的前缀和
        // sum[i] : 前i个数的前缀和
                        // [3,4,5]
                        //  0 1 2
                        // sum[0] = 0
                        // sum[1] = 3
                        // sum[2] = 7
                        // sum[3] = 12
                        // 前0个数前缀和
                        // 前1个数前缀和
                        // 前2个数前缀和
                        // ...
                        // 前n个数前缀和
                                // 如果当前的前缀和 - 头前缀和，达标！
                        // 前i个数前缀和，从尾部加入
                        // 小 大
*/
