// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade

// Source: src/class083/Code04_LongestSubarraySumNoMoreK.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LongestSubarraySumNoMoreK {
  inline static int MAXN = 100001;
  inline static Array<int> nums = make_array<int>(MAXN);
  inline static Array<int> minSums = make_array<int>(MAXN);
  inline static Array<int> minSumEnds = make_array<int>(MAXN);
  inline static int n = {};
  inline static int k = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LongestSubarraySumNoMoreK() {}
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    while ((in.nextToken() != -1)) {
      (n = static_cast<int>(in.nval));
      in.nextToken();
      (k = static_cast<int>(in.nval));
      for (int i = 0; (i < n); (i++)) {
        in.nextToken();
        (nums[i] = static_cast<int>(in.nval));
      }
      out.println(Code04_LongestSubarraySumNoMoreK::compute2());
    }
    out.flush();
    out.close();
    br.close();
  }
  static int compute1() {
    Array<int> sums = make_array<int>((n + 1));
    {
      int i = 0;
      int sum = 0;
      for (; (i < n); (i++)) {
        (sum += nums[i]);
        (sums[(i + 1)] = jmax(sum, sums[i]));
      }
    }
    int ans = 0;
    {
      int i = 0;
      int sum = 0;
      int pre = {};
      int len = {};
      for (; (i < n); (i++)) {
        (sum += nums[i]);
        (pre = Code04_LongestSubarraySumNoMoreK::find(sums, (sum - k)));
        (len = ((pre == (-1)) ? 0 : ((i - pre) + 1)));
        (ans = jmax(ans, len));
      }
    }
    return ans;
  }
  static int find(Array<int> sums, int num) {
    int l = 0;
    int r = n;
    int m = 0;
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((sums[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int compute2() {
    (minSums[(n - 1)] = nums[(n - 1)]);
    (minSumEnds[(n - 1)] = (n - 1));
    for (int i = (n - 2); (i >= 0); (i--)) {
      if ((minSums[(i + 1)] < 0)) {
        (minSums[i] = (nums[i] + minSums[(i + 1)]));
        (minSumEnds[i] = minSumEnds[(i + 1)]);
      } else {
        (minSums[i] = nums[i]);
        (minSumEnds[i] = i);
      }
    }
    int ans = 0;
    {
      int i = 0;
      int sum = 0;
      int end = 0;
      for (; (i < n); (i++)) {
        while (((end < n) && ((sum + minSums[end]) <= k))) {
          (sum += minSums[end]);
          (end = (minSumEnds[end] + 1));
        }
        if ((end > i)) {
          (ans = jmax(ans, (end - i)));
          (sum -= nums[i]);
        } else {
          (end = (i + 1));
        }
      }
    }
    return ans;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_LongestSubarraySumNoMoreK::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 累加和不大于k的最长子数组
// 给定一个无序数组arr，长度为n，其中元素可能是正、负、0
// 给定一个整数k，求arr所有的子数组中累加和不大于k的最长子数组长度
// 要求时间复杂度为O(n)
// 测试链接 : https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
// 至今的最优解，全网题解几乎都是我几年前讲的方法
                        // sum : 0...i范围上，这前i+1个数字的累加和
                        // sums[i + 1] :
前i+1个，包括一个数字也没有的时候，所有前缀和中的最大值
                                // 如果end > i，
                                // 窗口范围：i...end-1，那么窗口有效
                                // 如果end ==
i，那么说明窗口根本没扩出来，代表窗口无效
                                // end来到i+1位置，然后i++了
                                // 继续以新的i位置做开头去扩窗口
*/
