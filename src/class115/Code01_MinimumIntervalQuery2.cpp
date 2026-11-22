// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-interval-to-include-each-query/

// Source: src/class115/Code01_MinimumIntervalQuery2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MinimumIntervalQuery2 {
  inline static int MAXN = 100001;
  inline static Array<Array<int>> heap = make_array<int>(MAXN, 2);
  inline static int heapSize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MinimumIntervalQuery2() {}
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
    (heapSize = 0);
    Array<int> ans = make_array<int>(m);
    {
      int i = 0;
      int j = 0;
      for (; (i < m); (i++)) {
        for (; ((j < n) && (intervals[j][0] <= ques[i][0])); (j++)) {
          Code01_MinimumIntervalQuery2::push(
              ((intervals[j][1] - intervals[j][0]) + 1), intervals[j][1]);
        }
        while (((!Code01_MinimumIntervalQuery2::isEmpty()) &&
                (Code01_MinimumIntervalQuery2::peekEnd() < ques[i][0]))) {
          Code01_MinimumIntervalQuery2::poll();
        }
        if ((!Code01_MinimumIntervalQuery2::isEmpty())) {
          (ans[ques[i][1]] = Code01_MinimumIntervalQuery2::peekLength());
        } else {
          (ans[ques[i][1]] = (-1));
        }
      }
    }
    return ans;
  }
  static bool isEmpty() { return (heapSize == 0); }
  static int peekLength() { return heap[0][0]; }
  static int peekEnd() { return heap[0][1]; }
  static void push(int h, int e) {
    (heap[heapSize][0] = h);
    (heap[heapSize][1] = e);
    Code01_MinimumIntervalQuery2::heapInsert((heapSize++));
  }
  static void poll() {
    Code01_MinimumIntervalQuery2::swap(0, (--heapSize));
    Code01_MinimumIntervalQuery2::heapify(0);
  }
  static void heapInsert(int i) {
    while ((heap[i][0] < heap[jdiv((i - 1), 2)][0])) {
      Code01_MinimumIntervalQuery2::swap(i, jdiv((i - 1), 2));
      (i = jdiv((i - 1), 2));
    }
  }
  static void heapify(int i) {
    int l = ((i * 2) + 1);
    while ((l < heapSize)) {
      int best =
          ((((l + 1) < heapSize) && (heap[(l + 1)][0] < heap[l][0])) ? (l + 1)
                                                                     : l);
      (best = ((heap[best][0] < heap[i][0]) ? best : i));
      if ((best == i)) {
        break;
      }
      Code01_MinimumIntervalQuery2::swap(best, i);
      (i = best);
      (l = ((i * 2) + 1));
    }
  }
  static void swap(int i, int j) {
    Array<int> tmp = heap[i];
    (heap[i] = heap[j]);
    (heap[j] = tmp);
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
        // 堆结构由自己实现
*/
