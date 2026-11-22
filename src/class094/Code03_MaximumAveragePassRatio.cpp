// Source: src/class094/Code03_MaximumAveragePassRatio.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MaximumAveragePassRatio {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MaximumAveragePassRatio() {}
  static double maxAverageRatio(Array<Array<int>> classes, int m) {
    int n = classes.length;
    JHeap<Array<double>> heap =
        JHeap<Array<double>>([=](Array<double> c1, Array<double> c2) {
          return ((c1[2] >= c2[2]) ? (-1) : 1);
        });
    for (Array<int> c : classes) {
      double a = c[0];
      double b = c[1];
      heap.add(Array<double>{
          static_cast<double>(a), static_cast<double>(b),
          static_cast<double>((jdiv((a + 1), (b + 1)) - jdiv(a, b)))});
    }
    while (((m--) > 0)) {
      Array<double> cur = heap.poll();
      double a = (cur[0] + 1);
      double b = (cur[1] + 1);
      heap.add(Array<double>{
          static_cast<double>(a), static_cast<double>(b),
          static_cast<double>((jdiv((a + 1), (b + 1)) - jdiv(a, b)))});
    }
    double ans = 0;
    while ((!heap.isEmpty())) {
      Array<double> cur = heap.poll();
      (ans += jdiv(cur[0], cur[1]));
    }
    return jdiv(ans, n);
  }
};

/* Original teaching comments:
// 最大平均通过率
// 一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试
// 给你一个二维数组classes，其中classes[i]=[passi, totali]
// 表示你提前知道了第i个班级总共有totali个学生
// 其中只有 passi 个学生可以通过考试
//
给你一个整数extraStudents，表示额外有extraStudents个聪明的学生，一定能通过期末考
// 你需要给这extraStudents个学生每人都安排一个班级，使得所有班级的平均通过率最大
// 一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数
// 平均通过率 是所有班级的通过率之和除以班级数目
// 请你返回在安排这extraStudents个学生去对应班级后的最大平均通过率
// 测试链接 : https://leetcode.cn/problems/maximum-average-pass-ratio/
                // double[] c1 : {a, b, c}
                // a : c1班级有多少人通过
                // b : c1班级总人数
                // c : 如果再来一人，c1班级通过率提升多少，(a+1)/(b+1) - a/b
                // 通过率提升的大根堆
                // n * logn
                // 天才一个一个分配
                // m * logn
                // 计算通过率累加和
                // 返回最大平均通过率
*/
