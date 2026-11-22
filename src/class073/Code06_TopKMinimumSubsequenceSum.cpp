// Source: src/class073/Code06_TopKMinimumSubsequenceSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_TopKMinimumSubsequenceSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_TopKMinimumSubsequenceSum() {}
  static Array<int> topKSum1(Array<int> nums, int k) {
    JList<int> allSubsequences = JList<int>();
    Code06_TopKMinimumSubsequenceSum::f1(nums, 0, 0, allSubsequences);
    allSubsequences.sort(
        [=](Box<int> a, Box<int> b) { return jcompare(a, b); });
    Array<int> ans = make_array<int>(k);
    for (int i = 0; (i < k); (i++)) {
      (ans[i] = allSubsequences.get(i));
    }
    return ans;
  }
  static void f1(Array<int> nums, int index, int sum, JList<int> ans) {
    if ((index == nums.length)) {
      ans.add(sum);
    } else {
      Code06_TopKMinimumSubsequenceSum::f1(nums, (index + 1), sum, ans);
      Code06_TopKMinimumSubsequenceSum::f1(nums, (index + 1),
                                           (sum + nums[index]), ans);
    }
  }
  static Array<int> topKSum2(Array<int> nums, int k) {
    int sum = 0;
    for (int num : nums) {
      (sum += num);
    }
    Array<int> dp = make_array<int>((sum + 1));
    (dp[0] = 1);
    for (int num : nums) {
      for (int j = sum; (j >= num); (j--)) {
        (dp[j] += dp[(j - num)]);
      }
    }
    Array<int> ans = make_array<int>(k);
    int index = 0;
    for (int j = 0; ((j <= sum) && (index < k)); (j++)) {
      for (int i = 0; ((i < dp[j]) && (index < k)); (i++)) {
        (ans[(index++)] = j);
      }
    }
    return ans;
  }
  static Array<int> topKSum3(Array<int> nums, int k) {
    j::sort(nums);
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    heap.add(Array<int>{0, nums[0]});
    Array<int> ans = make_array<int>(k);
    for (int i = 1; (i < k); (i++)) {
      Array<int> cur = heap.poll();
      int right = cur[0];
      int sum = cur[1];
      (ans[i] = sum);
      if (((right + 1) < nums.length)) {
        heap.add(
            Array<int>{(right + 1), ((sum - nums[right]) + nums[(right + 1)])});
        heap.add(Array<int>{(right + 1), (sum + nums[(right + 1)])});
      }
    }
    return ans;
  }
  static Array<int> randomArray(int len, int value) {
    Array<int> ans = make_array<int>(len);
    for (int i = 0; (i < len); (i++)) {
      (ans[i] = static_cast<int>((j::random() * value)));
    }
    return ans;
  }
  static bool equals(Array<int> ans1, Array<int> ans2) {
    if ((ans1.length != ans2.length)) {
      return false;
    }
    for (int i = 0; (i < ans1.length); (i++)) {
      if ((ans1[i] != ans2[i])) {
        return false;
      }
    }
    return true;
  }
  static void java_main(Array<String> args) {
    int n = 15;
    int v = 40;
    int testTime = 5000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int len = (static_cast<int>((j::random() * n)) + 1);
      Array<int> nums = Code06_TopKMinimumSubsequenceSum::randomArray(len, v);
      int k = (static_cast<int>((j::random() * (jshl(1, len) - 1))) + 1);
      Array<int> ans1 = Code06_TopKMinimumSubsequenceSum::topKSum1(nums, k);
      Array<int> ans2 = Code06_TopKMinimumSubsequenceSum::topKSum2(nums, k);
      Array<int> ans3 = Code06_TopKMinimumSubsequenceSum::topKSum3(nums, k);
      if (((!Code06_TopKMinimumSubsequenceSum::equals(ans1, ans2)) ||
           (!Code06_TopKMinimumSubsequenceSum::equals(ans1, ans3)))) {
        jout.println(String(u"出错了！"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_TopKMinimumSubsequenceSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 非负数组前k个最小的子序列累加和
// 给定一个数组nums，含有n个数字，都是非负数
// 给定一个正数k，返回所有子序列中累加和最小的前k个累加和
// 子序列是包含空集的
// 1 <= n <= 10^5
// 1 <= nums[i] <= 10^6
// 1 <= k <= 10^5
// 注意这个数据量，用01背包的解法是不行的，时间复杂度太高了
// 对数器验证
        // 暴力方法
        // 为了验证
        // 暴力方法
        // 得到所有子序列的和
        // 01背包来实现
        // 这种方法此时不是最优解
        // 因为n很大，数值也很大，那么可能的累加和就更大
        // 时间复杂度太差
                // dp[i][j]
                // 1) dp[i-1][j]
                // 2) dp[i-1][j-nums[i]
        // 正式方法
        // 用堆来做是最优解，时间复杂度O(n * log n) + O(k * log k)
                // (子序列的最右下标，子序列的累加和)
        // 为了测试
        // 为了测试
        // 为了测试
        // 对数器
*/
