// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-width-ramp/

// Source: src/class053/Code01_MaximumWidthRamp.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximumWidthRamp {
  inline static int MAXN = 50001;
  inline static Array<int> stack = make_array<int>(MAXN);
  inline static int r = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximumWidthRamp() {}
  static int maxWidthRamp(Array<int> arr) {
    (r = 1);
    int n = arr.length;
    for (int i = 1; (i < n); (i++)) {
      if ((arr[stack[(r - 1)]] > arr[i])) {
        (stack[(r++)] = i);
      }
    }
    int ans = 0;
    for (int j = (n - 1); (j >= 0); (j--)) {
      while (((r > 0) && (arr[stack[(r - 1)]] <= arr[j]))) {
        (ans = jmax(ans, (j - stack[(--r)])));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 最大宽度坡
// 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]
// 这样的坡的宽度为 j - i，找出 A 中的坡的最大宽度，如果不存在，返回 0
// 测试链接 : https://leetcode.cn/problems/maximum-width-ramp/
                // 令r=1相当于0位置进栈了
                // stack[0] = 0，然后栈的大小变成1
*/
