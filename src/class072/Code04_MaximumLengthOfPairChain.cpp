// Source: src/class072/Code04_MaximumLengthOfPairChain.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MaximumLengthOfPairChain {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MaximumLengthOfPairChain() {}
  static int findLongestChain(Array<Array<int>> pairs) {
    int n = pairs.length;
    j::sort(pairs, [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    Array<int> ends = make_array<int>(n);
    int len = 0;
    for (Array<int> pair : pairs) {
      int find = Code04_MaximumLengthOfPairChain::bs(ends, len, pair[0]);
      if ((find == (-1))) {
        (ends[(len++)] = pair[1]);
      } else {
        (ends[find] = jmin(ends[find], pair[1]));
      }
    }
    return len;
  }
  static int bs(Array<int> ends, int len, int num) {
    int l = 0;
    int r = (len - 1);
    int m = {};
    int ans = (-1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((ends[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int findLongestChain2(Array<Array<int>> pairs) {
    int pre = std::numeric_limits<int>::min();
    int ans = 0;
    j::sort(pairs, [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    for (Array<int> pair : pairs) {
      if ((pre < pair[0])) {
        (pre = pair[1]);
        (ans++);
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 最长数对链
// 给你一个由n个数对组成的数对数组pairs
// 其中 pairs[i] = [lefti, righti] 且 lefti < righti
// 现在，我们定义一种 跟随 关系，当且仅当 b < c 时
// 数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面
// 我们用这种形式来构造 数对链
// 找出并返回能够形成的最长数对链的长度
// 测试链接 : https://leetcode.cn/problems/maximum-length-of-pair-chain/
                // 数对根据开始位置排序，从小到大
                // 结束位置无所谓！
                // 结尾的数值
        // >= num最左位置
        // 最优解利用贪心
*/
