// Source: src/class130/Code07_MaximumOrderSum.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_MaximumOrderSum {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_MaximumOrderSum() {}
  static i64 maxSum1(Array<int> arr) {
    int n = arr.length;
    int max = 0;
    for (int num : arr) {
      (max = jmax(max, num));
    }
    i64 ans = 0;
    Array<Array<i64>> dp = make_array<i64>(n, (max + 1));
    for (int i = 0; (i < n); (i++)) {
      for (int j = 0; (j <= max); (j++)) {
        (dp[i][j] = (-1));
      }
    }
    for (int i = 0; (i < n); (i++)) {
      (ans = jmax(ans, Code07_MaximumOrderSum::f1(arr, i, arr[i], dp)));
    }
    return ans;
  }
  static i64 f1(Array<int> arr, int i, int p, Array<Array<i64>> dp) {
    if (((p <= 0) || (i == (-1)))) {
      return 0;
    }
    if ((dp[i][p] != (-1))) {
      return dp[i][p];
    }
    int cur = jmin(arr[i], p);
    i64 next = Code07_MaximumOrderSum::f1(arr, (i - 1), (cur - 1), dp);
    i64 ans = (static_cast<i64>(cur) + next);
    (dp[i][p] = ans);
    return (cur + next);
  }
  static i64 maxSum2(Array<int> arr) {
    int n = arr.length;
    Array<int> stack = make_array<int>(n);
    int size = 0;
    Array<i64> dp = make_array<i64>(n);
    i64 ans = 0;
    for (int i = 0; (i < n); (i++)) {
      int curIdx = i;
      int curVal = arr[curIdx];
      while (((curVal > 0) && (size > 0))) {
        int topIdx = stack[(size - 1)];
        int topVal = arr[topIdx];
        if ((topVal >= curVal)) {
          (size--);
        } else {
          int idxDiff = (curIdx - topIdx);
          int valDiff = (curVal - topVal);
          if ((valDiff >= idxDiff)) {
            (dp[i] +=
             (Code07_MaximumOrderSum::sum(curVal, idxDiff) + dp[topIdx]));
            (curVal = 0);
            (curIdx = 0);
            break;
          } else {
            (dp[i] += Code07_MaximumOrderSum::sum(curVal, idxDiff));
            (curVal -= idxDiff);
            (curIdx = topIdx);
            (size--);
          }
        }
      }
      if ((curVal > 0)) {
        (dp[i] += Code07_MaximumOrderSum::sum(curVal, (curIdx + 1)));
      }
      (stack[(size++)] = i);
      (ans = jmax(ans, dp[i]));
    }
    return ans;
  }
  static i64 sum(int max, int n) {
    (n = jmin(max, n));
    return jdiv(((((static_cast<i64>(max) * 2) - n) + 1) * n), 2);
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> ans = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (ans[i] = static_cast<int>((j::random() * v)));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int n = 100;
    int v = 100;
    int testTimes = 50000;
    jout.println(String(u"功能测试开始"));
    for (int i = 0; (i < testTimes); (i++)) {
      int size = (static_cast<int>((j::random() * n)) + 1);
      Array<int> arr = Code07_MaximumOrderSum::randomArray(size, v);
      i64 ans1 = Code07_MaximumOrderSum::maxSum1(arr);
      i64 ans2 = Code07_MaximumOrderSum::maxSum2(arr);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"功能测试结束"));
    jout.println(String(u"性能测试开始"));
    (n = 1000000);
    (v = 1000000);
    jout.println((String(u"数组长度 : ") + n));
    jout.println((String(u"数值范围 : ") + v));
    Array<int> arr = Code07_MaximumOrderSum::randomArray(n, v);
    i64 start = millis();
    Code07_MaximumOrderSum::maxSum2(arr);
    i64 end = millis();
    jout.println(((String(u"运行时间 : ") + (end - start)) + String(u" 毫秒")));
    jout.println(String(u"性能测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_MaximumOrderSum::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 子数组最大变序和
// 给定一个长度为n的数组arr，变序和定义如下
// 数组中每个值都可以减小或者不变，必须把整体变成严格升序的
// 所有方案中，能得到的最大累加和，叫做数组的变序和
// 比如[1,100,7]，变序和14，方案为变成[1,6,7]
// 比如[5,4,9]，变序和16，方案为变成[3,4,9]
// 比如[1,4,2]，变序和3，方案为变成[0,1,2]
// 返回arr所有子数组的变序和中，最大的那个
// 1 <= n、arr[i] <= 10^6
// 来自真实大厂笔试，对数器验证
        // 暴力方法
        // 为了验证
        // 时间复杂度O(n * v)
        // 暴力方法
        // 为了验证
        // 子数组一定要以i位置结尾，并且i位置变成的数字不能大于p的情况下
        // 返回子数组的最大变序和
        // 正式方法
        // 时间复杂度O(n)
        // 最大值从max开始，往下一共有n项，只要正数的部分，返回累加和
        // 为了验证
        // 为了验证
*/
