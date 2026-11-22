// Source: src/class115/Code01_MinimumIntervalQuery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumIntervalQuery1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumIntervalQuery1() {}
  static Array<int> minInterval(Array<Array<int>> intervals,
                                Array<int> queries) {
    int n = intervals.length;
    int m = queries.length;
    j::sort(intervals,
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    Array<Array<int>> ques = make_array<int>(m, 2);
    for (int i = 0; (i < m); (i++)) {
      (ques[i][0] = queries[i]);
      (ques[i][1] = i);
    }
    j::sort(ques, [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    Array<int> ans = make_array<int>(m);
    {
      int i = 0;
      int j = 0;
      for (; (i < m); (i++)) {
        for (; ((j < n) && (intervals[j][0] <= ques[i][0])); (j++)) {
          heap.add(Array<int>{((intervals[j][1] - intervals[j][0]) + 1),
                              intervals[j][1]});
        }
        while (((!heap.isEmpty()) && (heap.peek()[1] < ques[i][0]))) {
          heap.poll();
        }
        if ((!heap.isEmpty())) {
          (ans[ques[i][1]] = heap.peek()[0]);
        } else {
          (ans[ques[i][1]] = (-1));
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 包含每个查询的最小区间
// 给你一个二维整数数组intervals，其中intervals[i] = [l, r]
// 表示第i个区间开始于l，结束于r，区间的长度是r-l+1
// 给你一个整数数组queries，queries[i]表示要查询的位置
// 答案是所有包含queries[i]的区间中，最小长度的区间是多长
// 返回数组对应查询的所有答案，如果不存在这样的区间那么答案是-1
// 测试链接 :
https://leetcode.cn/problems/minimum-interval-to-include-each-query/
        // 堆结构是现成结构
                // 0 : 长度
                // 1 : 影响到的位置
*/
