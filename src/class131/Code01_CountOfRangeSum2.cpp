// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/count-of-range-sum/

// Source: src/class131/Code01_CountOfRangeSum2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_CountOfRangeSum2 {
  inline static int MAXN = 100002;
  inline static int n = {};
  inline static int m = {};
  inline static Array<i64> sort = make_array<i64>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_CountOfRangeSum2() {}
  static int countRangeSum(Array<int> nums, int lower, int upper) {
    Code01_CountOfRangeSum2::build(nums);
    i64 sum = 0;
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      (sum += nums[i]);
      (ans += [&]() {
        auto jleft = Code01_CountOfRangeSum2::sum(
            Code01_CountOfRangeSum2::rank((sum - lower)));
        auto jright = Code01_CountOfRangeSum2::sum(
            Code01_CountOfRangeSum2::rank(((sum - upper) - 1)));
        return (jleft - jright);
      }());
      if (((lower <= sum) && (sum <= upper))) {
        (ans++);
      }
      Code01_CountOfRangeSum2::add(Code01_CountOfRangeSum2::rank(sum), 1);
    }
    return ans;
  }
  static void build(Array<int> nums) {
    (n = nums.length);
    {
      int i = 1;
      int j = 0;
      for (; (i <= n); (i++), (j++)) {
        (sort[i] = (sort[(i - 1)] + nums[j]));
      }
    }
    j::sort(sort, 1, (n + 1));
    (m = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sort[m] != sort[i])) {
        (sort[(++m)] = sort[i]);
      }
    }
    j::fill(tree, 1, (m + 1), 0);
  }
  static int rank(i64 v) {
    int left = 1;
    int right = m;
    int mid = {};
    int ans = 0;
    while ((left <= right)) {
      (mid = jdiv((left + right), 2));
      if ((sort[mid] <= v)) {
        (ans = mid);
        (left = (mid + 1));
      } else {
        (right = (mid - 1));
      }
    }
    return ans;
  }
  static void add(int i, int c) {
    while ((i <= m)) {
      (tree[i] += c);
      (i += (i & (-i)));
    }
  }
  static int sum(int i) {
    int ans = 0;
    while ((i > 0)) {
      (ans += tree[i]);
      (i -= (i & (-i)));
    }
    return ans;
  }
};

/* Original teaching comments:
// 达标子数组的个数
// 给定一个长度为n的数组nums，给定两个整数lower和upper
// 子数组达标的条件是累加和在[lower, upper]范围上
// 返回nums中有多少个达标子数组
// 1 <= n <= 10^5
// nums[i]可能是任意整数
// -10^5 <= lower <= upper <= +10^5
// 测试链接 : https://leetcode.cn/problems/count-of-range-sum/
        // 树状数组 + 离散化的解法，理解难度较低
                // 生成前缀和数组
                // 前缀和数组排序和去重，最终有m个不同的前缀和
                // 初始化树状数组，下标1~m
        // 返回 <=v 并且尽量大的前缀和是第几号前缀和
        // 树状数组模版代码，没有任何修改
        // i号前缀和，个数增加c个
        // 树状数组模版代码，没有任何修改
        // 查询1~i号前缀和一共有几个
*/
