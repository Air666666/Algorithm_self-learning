// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/

// Source: src/class094/Code04_MinimumCostToHireWorkers.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MinimumCostToHireWorkers {
  struct Employee;
  struct Employee {
    double ratio = {};
    int quality = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Employee(double r, int q) {
      (ratio = r);
      (quality = q);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MinimumCostToHireWorkers() {}
  static double mincostToHireWorkers(Array<int> quality, Array<int> wage,
                                     int k) {
    int n = quality.length;
    Array<Employee *> employees = make_array<Employee *>(n);
    for (int i = 0; (i < n); (i++)) {
      (employees[i] = new Employee(
           jdiv(static_cast<double>(wage[i]), quality[i]), quality[i]));
    }
    j::sort(employees, [=](Employee *a, Employee *b) {
      return ((a->ratio <= b->ratio) ? (-1) : 1);
    });
    JHeap<int> heap =
        JHeap<int>([=](Box<int> a, Box<int> b) { return (b - a); });
    int qualitySum = 0;
    double ans = std::numeric_limits<double>::max();
    {
      int i = 0;
      int curQuality = {};
      for (; (i < n); (i++)) {
        (curQuality = employees[i]->quality);
        if ((heap.size() < k)) {
          (qualitySum += curQuality);
          heap.add(curQuality);
          if ((heap.size() == k)) {
            (ans = jmin(ans, (qualitySum * employees[i]->ratio)));
          }
        } else {
          if ((heap.peek() > curQuality)) {
            (qualitySum += (curQuality - heap.poll()));
            heap.add(curQuality);
            (ans = jmin(ans, (qualitySum * employees[i]->ratio)));
          }
        }
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 雇佣K名工人的最低成本
// 有n名工人，给定两个数组quality和wage
// 其中quality[i]表示第i名工人的工作质量，其最低期望工资为wage[i]
// 现在我们想雇佣k名工人组成一个工资组
// 在雇佣一组k名工人时，我们必须按照下述规则向他们支付工资：
//
对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资
// 工资组中的每名工人至少应当得到他们的最低期望工资
// 给定整数k，返回组成满足上述条件的付费群体所需的最小金额
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/
                // 根据比例排序，比例小的在前，比例大的在后
                // 大根堆，用来收集最小的前k个质量数值
                // 堆里，最小的前k个质量数值，总和是多少
*/
