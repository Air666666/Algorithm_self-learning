// Source: src/class131/Code02_MaximumBalancedSubsequence.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MaximumBalancedSubsequence {
  inline static int MAXN = 100001;
  inline static Array<int> sort = make_array<int>(MAXN);
  inline static Array<i64> tree = make_array<i64>(MAXN);
  inline static int n = {};
  inline static int m = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MaximumBalancedSubsequence() {}
  static i64 maxBalancedSubsequenceSum(Array<int> nums) {
    Code02_MaximumBalancedSubsequence::build(nums);
    i64 pre = {};
    {
      int i = 0;
      int k = {};
      for (; (i < n); (i++)) {
        (k = Code02_MaximumBalancedSubsequence::rank((nums[i] - i)));
        (pre = Code02_MaximumBalancedSubsequence::max(k));
        if ((pre < 0)) {
          Code02_MaximumBalancedSubsequence::update(k, nums[i]);
        } else {
          Code02_MaximumBalancedSubsequence::update(k, (pre + nums[i]));
        }
      }
    }
    return Code02_MaximumBalancedSubsequence::max(m);
  }
  static void build(Array<int> nums) {
    (n = nums.length);
    {
      int i = 1;
      int j = 0;
      for (; (i <= n); (i++), (j++)) {
        (sort[i] = (nums[j] - j));
      }
    }
    j::sort(sort, 1, (n + 1));
    (m = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sort[m] != sort[i])) {
        (sort[(++m)] = sort[i]);
      }
    }
    j::fill(tree, 1, (m + 1), std::numeric_limits<i64>::min());
  }
  static int rank(int v) {
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
  static void update(int i, i64 v) {
    while ((i <= m)) {
      (tree[i] = jmax(tree[i], v));
      (i += (i & (-i)));
    }
  }
  static i64 max(int i) {
    i64 ans = std::numeric_limits<i64>::min();
    while ((i > 0)) {
      (ans = jmax(ans, tree[i]));
      (i -= (i & (-i)));
    }
    return ans;
  }
};

/* Original teaching comments:
// 平衡子序列的最大和
// 给定一个长度为n的数组nums，下面定义平衡子序列
// 如果下标i和下标j被选进了子序列，i在j的左边
// 那么必须有nums[j] - nums[i] >= j - i
// 如果一个子序列中任意的两个下标都满足上面的要求，那子序列就是平衡的
// 返回nums所有平衡子序列里，最大的累加和是多少
// 1 <= n <= 10^5
// -10^9 <= nums[i] <= +10^9
// 测试链接 : https://leetcode.cn/problems/maximum-balanced-subsequence-sum/
                        // k的含义为当前的指标是第几号指标
                        // dp[1号..k号指标]中的最大值是多少
                                // 如果之前的最好情况是负数，那么不要之前的数了
                                // 当前数字自己单独形成平衡子序列
                                // 去更新dp[k号指标]，看能不能变得更大
                                //
如果之前的最好情况不是负数，那么和当前数字一起形成更大的累加和
                                // 去更新dp[k号指标]，看能不能变得更大
                // 返回dp[1号..m号指标]中的最大值
        // 当前的指标值是v，返回这是第几号指标
        // dp[i号指标]，当前算出的值是v
        // dp[1..i]，最大值多少返回
*/
