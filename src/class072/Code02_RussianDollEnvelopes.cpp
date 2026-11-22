// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/russian-doll-envelopes/

// Source: src/class072/Code02_RussianDollEnvelopes.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_RussianDollEnvelopes {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_RussianDollEnvelopes() {}
  static int maxEnvelopes(Array<Array<int>> envelopes) {
    int n = envelopes.length;
    j::sort(envelopes, [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (b[1] - a[1]));
    });
    Array<int> ends = make_array<int>(n);
    int len = 0;
    {
      int i = 0;
      int find = {};
      int num = {};
      for (; (i < n); (i++)) {
        (num = envelopes[i][1]);
        (find = Code02_RussianDollEnvelopes::bs(ends, len, num));
        if ((find == (-1))) {
          (ends[(len++)] = num);
        } else {
          (ends[find] = num);
        }
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
};

/* Original teaching comments:
// 俄罗斯套娃信封问题
// 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
// 表示第 i 个信封的宽度和高度
// 当另一个信封的宽度和高度都比这个信封大的时候
// 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
// 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
// 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
// 测试链接 : https://leetcode.cn/problems/russian-doll-envelopes/
                // 排序策略:
                // 宽度从小到大
                // 宽度一样，高度从大到小
*/
