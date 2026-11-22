// Source: src/class071/Code05_ReverseArraySubarrayMaxSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_ReverseArraySubarrayMaxSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_ReverseArraySubarrayMaxSum() {}
  static int maxSumReverse1(Array<int> nums) {
    int ans = std::numeric_limits<int>::min();
    for (int l = 0; (l < nums.length); (l++)) {
      for (int r = l; (r < nums.length); (r++)) {
        Code05_ReverseArraySubarrayMaxSum::reverse(nums, l, r);
        (ans = jmax(ans, Code05_ReverseArraySubarrayMaxSum::maxSum(nums)));
        Code05_ReverseArraySubarrayMaxSum::reverse(nums, l, r);
      }
    }
    return ans;
  }
  static void reverse(Array<int> nums, int l, int r) {
    while ((l < r)) {
      int tmp = nums[l];
      (nums[(l++)] = nums[r]);
      (nums[(r--)] = tmp);
    }
  }
  static int maxSum(Array<int> nums) {
    int n = nums.length;
    int ans = nums[0];
    {
      int i = 1;
      int pre = nums[0];
      for (; (i < n); (i++)) {
        (pre = jmax(nums[i], (pre + nums[i])));
        (ans = jmax(ans, pre));
      }
    }
    return ans;
  }
  static int maxSumReverse2(Array<int> nums) {
    int n = nums.length;
    Array<int> start = make_array<int>(n);
    (start[(n - 1)] = nums[(n - 1)]);
    for (int i = (n - 2); (i >= 0); (i--)) {
      (start[i] = jmax(nums[i], (nums[i] + start[(i + 1)])));
    }
    int ans = start[0];
    int end = nums[0];
    int maxEnd = nums[0];
    for (int i = 1; (i < n); (i++)) {
      (ans = jmax(ans, (maxEnd + start[i])));
      (end = jmax(nums[i], (end + nums[i])));
      (maxEnd = jmax(maxEnd, end));
    }
    (ans = jmax(ans, maxEnd));
    return ans;
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = (static_cast<int>((j::random() * ((v * 2) + 1))) - v));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 50;
    int v = 200;
    int testTime = 20000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int len = (static_cast<int>((j::random() * n)) + 1);
      Array<int> arr = Code05_ReverseArraySubarrayMaxSum::randomArray(len, v);
      int ans1 = Code05_ReverseArraySubarrayMaxSum::maxSumReverse1(arr);
      int ans2 = Code05_ReverseArraySubarrayMaxSum::maxSumReverse2(arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_ReverseArraySubarrayMaxSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 可以翻转1次的情况下子数组最大累加和
// 给定一个数组nums，
// 现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
// 比如翻转[1,2,3,4,5,6]的[2~4]范围，得到的是[1,2,5,4,3,6]
// 返回必须随意翻转1次之后，子数组的最大累加和
// 对数器验证
        // 暴力方法
        // 为了验证
        // nums[l...r]范围上的数字进行逆序调整
        // 返回子数组最大累加和
        // 正式方法
        // 时间复杂度O(n)
                // start[i] : 所有必须以i开头的子数组中，最大累加和是多少
                        // nums[i]
                        // nums[i] + start[i+1]
                // end : 子数组必须以i-1结尾，其中的最大累加和
                // maxEnd :
                // 0~i-1范围上，
                // 子数组必须以0结尾，其中的最大累加和
                // 子数组必须以1结尾，其中的最大累加和
                // ...
                // 子数组必须以i-1结尾，其中的最大累加和
                // 所有情况中，最大的那个累加和就是maxEnd
                        // maxend   i....
                        // 枚举划分点 i...
                        // 子数组必须以i结尾，其中的最大累加和
        // 为了测试
        // 生成随机数组
        // 为了测试
        // 对数器
*/
