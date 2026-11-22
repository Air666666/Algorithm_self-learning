// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

// Source: src/class045/Code02_TwoNumbersMaximumXor.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_TwoNumbersMaximumXor {
  inline static int MAXN = 3000001;
  inline static Array<Array<int>> tree = make_array<int>(MAXN, 2);
  inline static int cnt = {};
  inline static int high = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_TwoNumbersMaximumXor() {}
  static int findMaximumXOR1(Array<int> nums) {
    Code02_TwoNumbersMaximumXor::build(nums);
    int ans = 0;
    for (int num : nums) {
      (ans = jmax(ans, Code02_TwoNumbersMaximumXor::maxXor(num)));
    }
    Code02_TwoNumbersMaximumXor::clear();
    return ans;
  }
  static void build(Array<int> nums) {
    (cnt = 1);
    int max = std::numeric_limits<int>::min();
    for (int num : nums) {
      (max = jmax(num, max));
    }
    (high = (31 - (max == 0 ? 32 : __builtin_clz(static_cast<unsigned>(max)))));
    for (int num : nums) {
      Code02_TwoNumbersMaximumXor::insert(num);
    }
  }
  static void insert(int num) {
    int cur = 1;
    {
      int i = high;
      int path = {};
      for (; (i >= 0); (i--)) {
        (path = (jshr(num, i) & 1));
        if ((tree[cur][path] == 0)) {
          (tree[cur][path] = (++cnt));
        }
        (cur = tree[cur][path]);
      }
    }
  }
  static int maxXor(int num) {
    int ans = 0;
    int cur = 1;
    {
      int i = high;
      int status = {};
      int want = {};
      for (; (i >= 0); (i--)) {
        (status = (jshr(num, i) & 1));
        (want = (status ^ 1));
        if ((tree[cur][want] == 0)) {
          (want ^= 1);
        }
        (ans |= jshl((status ^ want), i));
        (cur = tree[cur][want]);
      }
    }
    return ans;
  }
  static void clear() {
    for (int i = 1; (i <= cnt); (i++)) {
      (tree[i][0] = (tree[i][1] = 0));
    }
  }
  int findMaximumXOR2(Array<int> nums) {
    int max = std::numeric_limits<int>::min();
    for (int num : nums) {
      (max = jmax(num, max));
    }
    int ans = 0;
    JHashSet<int> set = JHashSet<int>();
    for (int i =
             (31 - (max == 0 ? 32 : __builtin_clz(static_cast<unsigned>(max))));
         (i >= 0); (i--)) {
      int better = (ans | jshl(1, i));
      set.clear();
      for (int num : nums) {
        (num = jshl(jshr(num, i), i));
        set.add(num);
        if (set.contains((better ^ num))) {
          (ans = better);
          break;
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 数组中两个数的最大异或值
// 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中
0<=i<=j<=n
// 1 <= nums.length <= 2 * 10^5
// 0 <= nums[i] <= 2^31 - 1
// 测试链接 :
https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
        // 前缀树的做法
        // 好想
        // 准备这么多静态空间就够了，实验出来的
        // 如果测试数据升级了规模，就改大这个值
        // 前缀树目前使用了多少空间
        // 数字只需要从哪一位开始考虑
                // 找个最大值
                // 计算数组最大值的二进制状态，有多少个前缀的0
                // 可以忽略这些前置的0，从left位开始考虑
                // 最终异或的结果(尽量大)
                // 前缀树目前来到的节点编号
                        // status : num第i位的状态
                        // want : num第i位希望遇到的状态
                                // 不能达成
                        // want变成真的往下走的路
        // 用哈希表的做法
        // 难想
                        // ans : 31....i+1 已经达成的目标
                                // num : 31.....i 这些状态保留，剩下全成0
                                // num ^ 某状态 是否能
达成better目标，就在set中找 某状态 : better ^ num
*/
