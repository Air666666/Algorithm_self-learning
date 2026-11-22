// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/course-schedule-iii/

// Source: src/class089/Code05_CourseScheduleIII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_CourseScheduleIII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_CourseScheduleIII() {}
  static int scheduleCourse(Array<Array<int>> courses) {
    j::sort(courses, [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    JHeap<int> heap =
        JHeap<int>([=](Box<int> a, Box<int> b) { return (b - a); });
    int time = 0;
    for (Array<int> c : courses) {
      if (((time + c[0]) <= c[1])) {
        heap.add(c[0]);
        (time += c[0]);
      } else {
        if (((!heap.isEmpty()) && (heap.peek() > c[0]))) {
          (time += (c[0] - heap.poll()));
          heap.add(c[0]);
        }
      }
    }
    return heap.size();
  }
};

/* Original teaching comments:
// 课程表III
// 这里有n门不同的在线课程，按从1到n编号
// 给你一个数组courses
// 其中courses[i]=[durationi, lastDayi]表示第i门课将会持续上durationi天课
// 并且必须在不晚于lastDayi的时候完成
// 你的学期从第 1 天开始
// 且不能同时修读两门及两门以上的课程
// 返回你最多可以修读的课程数目
// 测试链接 : https://leetcode.cn/problems/course-schedule-iii/
                // 0 : 代价
                // 1 : 截止
                // 大根堆
                                // time + c[0] > c[1]
*/
