// Source: src/class087/Code04_MakeArrayStrictlyIncreasing.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MakeArrayStrictlyIncreasing {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MakeArrayStrictlyIncreasing() {}
  static int makeArrayIncreasing1(Array<int> arr1, Array<int> arr2) {
    j::sort(arr2);
    int m = 1;
    for (int i = 1; (i < arr2.length); (i++)) {
      if ((arr2[i] != arr2[(m - 1)])) {
        (arr2[(m++)] = arr2[i]);
      }
    }
    int n = arr1.length;
    Array<int> dp = make_array<int>(n);
    j::fill(dp, (-1));
    int ans = Code04_MakeArrayStrictlyIncreasing::f1(arr1, arr2, n, m, 0, dp);
    return ((ans == std::numeric_limits<int>::max()) ? (-1) : ans);
  }
  static int f1(Array<int> arr1, Array<int> arr2, int n, int m, int i,
                Array<int> dp) {
    if ((i == n)) {
      return 0;
    }
    if ((dp[i] != (-1))) {
      return dp[i];
    }
    int ans = std::numeric_limits<int>::max();
    int pre = ((i == 0) ? std::numeric_limits<int>::min() : arr1[(i - 1)]);
    int find = Code04_MakeArrayStrictlyIncreasing::bs(arr2, m, pre);
    {
      int j = i;
      int k = 0;
      int next = {};
      for (; (j <= n); (j++), (k++)) {
        if ((j == n)) {
          (ans = jmin(ans, k));
        } else {
          if ((pre < arr1[j])) {
            (next = Code04_MakeArrayStrictlyIncreasing::f1(arr1, arr2, n, m,
                                                           (j + 1), dp));
            if ((next != std::numeric_limits<int>::max())) {
              (ans = jmin(ans, (k + next)));
            }
          }
          if (((find != (-1)) && (find < m))) {
            (pre = arr2[(find++)]);
          } else {
            break;
          }
        }
      }
    }
    (dp[i] = ans);
    return ans;
  }
  static int bs(Array<int> arr2, int size, int num) {
    int l = 0;
    int r = (size - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((arr2[m] > num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int makeArrayIncreasing2(Array<int> arr1, Array<int> arr2) {
    j::sort(arr2);
    int m = 1;
    for (int i = 1; (i < arr2.length); (i++)) {
      if ((arr2[i] != arr2[(m - 1)])) {
        (arr2[(m++)] = arr2[i]);
      }
    }
    int n = arr1.length;
    Array<int> dp = make_array<int>((n + 1));
    {
      int i = (n - 1);
      int ans = {};
      int pre = {};
      int find = {};
      for (; (i >= 0); (i--)) {
        (ans = std::numeric_limits<int>::max());
        (pre = ((i == 0) ? std::numeric_limits<int>::min() : arr1[(i - 1)]));
        (find = Code04_MakeArrayStrictlyIncreasing::bs(arr2, m, pre));
        {
          int j = i;
          int k = 0;
          int next = {};
          for (; (j <= n); (j++), (k++)) {
            if ((j == n)) {
              (ans = jmin(ans, k));
            } else {
              if ((pre < arr1[j])) {
                (next = dp[(j + 1)]);
                if ((next != std::numeric_limits<int>::max())) {
                  (ans = jmin(ans, (k + next)));
                }
              }
              if (((find != (-1)) && (find < m))) {
                (pre = arr2[(find++)]);
              } else {
                break;
              }
            }
          }
        }
        (dp[i] = ans);
      }
    }
    return ((dp[0] == std::numeric_limits<int>::max()) ? (-1) : dp[0]);
  }
};

/* Original teaching comments:
// 使数组严格递增的最小操作数
// 给你两个整数数组 arr1 和 arr2
// 返回使 arr1 严格递增所需要的最小操作数（可能为0）
// 每一步操作中，你可以分别从 arr1 和 arr2 中各选出一个索引
// 分别为 i 和 j，0 <= i < arr1.length 和 0 <= j < arr2.length
// 然后进行赋值运算 arr1[i] = arr2[j]
// 如果无法让 arr1 严格递增，请返回-1
// 1 <= arr1.length, arr2.length <= 2000
// 0 <= arr1[i], arr2[i] <= 10^9
// 测试链接 : https://leetcode.cn/problems/make-array-strictly-increasing/
        // arr1长度为n，arr2有效部分长度为m
        // arr2有效部分可以替换arr1中的数字
        // arr1[0..i-1]已经严格递增且arr1[i-1]一定没有替换
        // 返回让arr1整体都严格递增，arr1[i...]范围上还需要几次替换
        // 如果做不到，返回无穷大
                // ans : 遍历所有的分支，所得到的最少的操作次数
                // pre : 前一位的数字
                // find : arr2有效长度m的范围上，找到刚比pre大的位置
                // 枚举arr1[i...]范围上，第一个不需要替换的位置j
                                // pre : 被arr2替换的前一位数字
        // arr2[0..size-1]范围上是严格递增的
        // 找到这个范围上>num的最左位置
        // 不存在返回-1
        // 严格位置依赖的动态规划
        // 和方法1的思路没有区别
        // 甚至填写dp表的逻辑都保持一致
*/
