// Source: src/class071/Code06_DeleteOneNumberLengthKMaxSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_DeleteOneNumberLengthKMaxSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_DeleteOneNumberLengthKMaxSum() {}
  static int maxSum1(Array<int> nums, int k) {
    int n = nums.length;
    if ((n <= k)) {
      return 0;
    }
    int ans = std::numeric_limits<int>::min();
    for (int i = 0; (i < n); (i++)) {
      Array<int> rest =
          Code06_DeleteOneNumberLengthKMaxSum::delete_method(nums, i);
      (ans =
           jmax(ans, Code06_DeleteOneNumberLengthKMaxSum::lenKmaxSum(rest, k)));
    }
    return ans;
  }
  static Array<int> delete_method(Array<int> nums, int index) {
    int len = (nums.length - 1);
    Array<int> ans = make_array<int>(len);
    int i = 0;
    for (int j = 0; (j < nums.length); (j++)) {
      if ((j != index)) {
        (ans[(i++)] = nums[j]);
      }
    }
    return ans;
  }
  static int lenKmaxSum(Array<int> nums, int k) {
    int n = nums.length;
    int ans = std::numeric_limits<int>::min();
    for (int i = 0; (i <= (n - k)); (i++)) {
      int cur = 0;
      {
        int j = i;
        int cnt = 0;
        for (; (cnt < k); (j++), (cnt++)) {
          (cur += nums[j]);
        }
      }
      (ans = jmax(ans, cur));
    }
    return ans;
  }
  static int maxSum2(Array<int> nums, int k) {
    int n = nums.length;
    if ((n <= k)) {
      return 0;
    }
    Array<int> window = make_array<int>(n);
    int l = 0;
    int r = 0;
    i64 sum = 0;
    int ans = std::numeric_limits<int>::min();
    for (int i = 0; (i < n); (i++)) {
      while (((l < r) && (nums[window[(r - 1)]] >= nums[i]))) {
        (r--);
      }
      (window[(r++)] = i);
      (sum += nums[i]);
      if ((i >= k)) {
        (ans = jmax(ans, static_cast<int>((sum - nums[window[l]]))));
        if ((window[l] == (i - k))) {
          (l++);
        }
        (sum -= nums[(i - k)]);
      }
    }
    return ans;
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = (static_cast<int>((j::random() * ((2 * v) + 1))) - v));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 200;
    int v = 1000;
    int testTimes = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int len = (static_cast<int>((j::random() * n)) + 1);
      Array<int> nums =
          Code06_DeleteOneNumberLengthKMaxSum::randomArray(len, v);
      int k = (static_cast<int>((j::random() * n)) + 1);
      int ans1 = Code06_DeleteOneNumberLengthKMaxSum::maxSum1(nums, k);
      int ans2 = Code06_DeleteOneNumberLengthKMaxSum::maxSum2(nums, k);
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
  Code06_DeleteOneNumberLengthKMaxSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 删掉1个数字后长度为k的子数组最大累加和
// 给定一个数组nums，求必须删除一个数字后的新数组中
// 长度为k的子数组最大累加和，删除哪个数字随意
// 对数器验证
        // 暴力方法
        // 为了测试
        // 暴力方法
        // 为了测试
        // 删掉index位置的元素，然后返回新数组
        // 暴力方法
        // 为了测试
        // 枚举每一个子数组找到最大累加和
        // 正式方法
        // 时间复杂度O(N)
                // 单调队列 : 维持窗口内最小值的更新结构，讲解054的内容
                // 窗口累加和
                        // 单调队列 : i位置进入单调队列
                                        // 单调队列 :
如果单调队列最左侧的位置过期了，从队列中弹出
        // 为了测试
        // 生成长度为n，值在[-v, +v]之间的随机数组
        // 为了测试
        // 对数器
*/
