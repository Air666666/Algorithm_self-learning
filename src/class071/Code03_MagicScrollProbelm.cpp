// Source: src/class071/Code03_MagicScrollProbelm.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MagicScrollProbelm {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MagicScrollProbelm() {}
  static int maxSum1(Array<int> nums) {
    int p1 = 0;
    for (int num : nums) {
      (p1 += num);
    }
    int n = nums.length;
    int p2 = Code03_MagicScrollProbelm::mustOneScroll(nums, 0, (n - 1));
    int p3 = std::numeric_limits<int>::min();
    for (int i = 1; (i < n); (i++)) {
      (p3 = jmax(p3, [&]() {
         auto jleft =
             Code03_MagicScrollProbelm::mustOneScroll(nums, 0, (i - 1));
         auto jright =
             Code03_MagicScrollProbelm::mustOneScroll(nums, i, (n - 1));
         return (jleft + jright);
       }()));
    }
    return jmax(p1, jmax(p2, p3));
  }
  static int mustOneScroll(Array<int> nums, int l, int r) {
    int ans = std::numeric_limits<int>::min();
    for (int a = l; (a <= r); (a++)) {
      for (int b = a; (b <= r); (b++)) {
        int curAns = 0;
        for (int i = l; (i < a); (i++)) {
          (curAns += nums[i]);
        }
        for (int i = (b + 1); (i <= r); (i++)) {
          (curAns += nums[i]);
        }
        (ans = jmax(ans, curAns));
      }
    }
    return ans;
  }
  static int maxSum2(Array<int> nums) {
    int n = nums.length;
    if ((n == 0)) {
      return 0;
    }
    int p1 = 0;
    for (int num : nums) {
      (p1 += num);
    }
    Array<int> prefix = make_array<int>(n);
    int sum = nums[0];
    int maxPresum = jmax(0, nums[0]);
    for (int i = 1; (i < n); (i++)) {
      (prefix[i] = jmax((prefix[(i - 1)] + nums[i]), maxPresum));
      (sum += nums[i]);
      (maxPresum = jmax(maxPresum, sum));
    }
    int p2 = prefix[(n - 1)];
    Array<int> suffix = make_array<int>(n);
    (sum = nums[(n - 1)]);
    (maxPresum = jmax(0, sum));
    for (int i = (n - 2); (i >= 0); (i--)) {
      (suffix[i] = jmax((nums[i] + suffix[(i + 1)]), maxPresum));
      (sum += nums[i]);
      (maxPresum = jmax(maxPresum, sum));
    }
    int p3 = std::numeric_limits<int>::min();
    for (int i = 1; (i < n); (i++)) {
      (p3 = jmax(p3, (prefix[(i - 1)] + suffix[i])));
    }
    return jmax(p1, jmax(p2, p3));
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
    int v = 100;
    int testTime = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 0; (i < testTime); (i++)) {
      int len = static_cast<int>((j::random() * n));
      Array<int> nums = Code03_MagicScrollProbelm::randomArray(len, v);
      int ans1 = Code03_MagicScrollProbelm::maxSum1(nums);
      int ans2 = Code03_MagicScrollProbelm::maxSum2(nums);
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
  Code03_MagicScrollProbelm::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 魔法卷轴
// 给定一个数组nums，其中可能有正、负、0
// 每个魔法卷轴可以把nums中连续的一段全变成0
// 你希望数组整体的累加和尽可能大
// 卷轴使不使用、使用多少随意，但一共只有2个魔法卷轴
// 请返回数组尽可能大的累加和
// 对数器验证
        // 暴力方法
        // 为了测试
        // 暴力方法
        // 为了测试
        // nums[l...r]范围上一定要用一次卷轴情况下的最大累加和
                // l...r范围上包含a...b范围
                // 如果a...b范围上的数字都变成0
                // 返回剩下数字的累加和
                // 所以枚举所有可能的a...b范围
                // 相当暴力，但是正确
                                // l...a...b...r
        // 正式方法
        // 时间复杂度O(n)
                // 情况1 : 完全不使用卷轴
                // prefix[i] :
0~i范围上一定要用1次卷轴的情况下，0~i范围上整体最大累加和多少
                // 每一步的前缀和
                // maxPresum : 之前所有前缀和的最大值
                // 情况二 : 必须用1次卷轴
                // suffix[i] :
i~n-1范围上一定要用1次卷轴的情况下，i~n-1范围上整体最大累加和多少
                // 情况二 : 必须用2次卷轴
                        // 枚举所有的划分点i
                        // 0~i-1 左
                        // i~n-1 右
        // 为了测试
        // 为了测试
*/
