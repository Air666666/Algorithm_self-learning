// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/

// Source: src/class091/Code05_MinimalBatteryPower.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MinimalBatteryPower {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MinimalBatteryPower() {}
  static int minimumEffort(Array<Array<int>> tasks) {
    j::sort(tasks, [=](Array<int> a, Array<int> b) {
      return ((b[0] - b[1]) - (a[0] - a[1]));
    });
    int ans = 0;
    for (Array<int> job : tasks) {
      (ans = jmax((ans + job[0]), job[1]));
    }
    return ans;
  }
  static int atLeast1(Array<Array<int>> jobs) {
    return Code05_MinimalBatteryPower::f1(jobs, jobs.length, 0);
  }
  static int f1(Array<Array<int>> jobs, int n, int i) {
    if ((i == n)) {
      int ans = 0;
      for (Array<int> job : jobs) {
        (ans = jmax(job[1], (ans + job[0])));
      }
      return ans;
    } else {
      int ans = std::numeric_limits<int>::max();
      for (int j = i; (j < n); (j++)) {
        Code05_MinimalBatteryPower::swap(jobs, i, j);
        (ans = jmin(ans, Code05_MinimalBatteryPower::f1(jobs, n, (i + 1))));
        Code05_MinimalBatteryPower::swap(jobs, i, j);
      }
      return ans;
    }
  }
  static void swap(Array<Array<int>> jobs, int i, int j) {
    Array<int> tmp = jobs[i];
    (jobs[i] = jobs[j]);
    (jobs[j] = tmp);
  }
  static int atLeast2(Array<Array<int>> jobs) {
    j::sort(jobs, [=](Array<int> a, Array<int> b) {
      return ((b[0] - b[1]) - (a[0] - a[1]));
    });
    int ans = 0;
    for (Array<int> job : jobs) {
      (ans = jmax((ans + job[0]), job[1]));
    }
    return ans;
  }
  static Array<Array<int>> randomJobs(int n, int v) {
    Array<Array<int>> jobs = make_array<int>(n, 2);
    for (int i = 0; (i < n); (i++)) {
      (jobs[i][0] = (static_cast<int>((j::random() * v)) + 1));
      (jobs[i][1] = (static_cast<int>((j::random() * v)) + 1));
    }
    return jobs;
  }
  static void java_main(Array<String> args) {
    int N = 10;
    int V = 20;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<Array<int>> jobs = Code05_MinimalBatteryPower::randomJobs(n, V);
      int ans1 = Code05_MinimalBatteryPower::atLeast1(jobs);
      int ans2 = Code05_MinimalBatteryPower::atLeast2(jobs);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了！"));
      }
      if ((jrem(i, 100) == 0)) {
        jout.println(((String(u"测试到第") + i) + String(u"组")));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_MinimalBatteryPower::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 执行所有任务的最少初始电量
// 每一个任务有两个参数，需要耗费的电量、至少多少电量才能开始这个任务
// 返回手机至少需要多少的初始电量，才能执行完所有的任务
// 测试链接 :
https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/
        // 同学找到了本题的在线测试，把如下minimumEffort方法提交，可以直接通过
        // 测试链接 :
https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/
        // 暴力递归
        // 为了验证
        // 时间复杂度O(n!)
        // 得到所有排列
        // 其中一定有返还电量最小的排列
        // 正式方法
        // 贪心
        // 时间复杂度O(n * logn)
                // jobs[i][0] : 耗费
                // jobs[i][1] : 至少电量
                // 消耗电量 - 至少电量，越大的任务，越先倒推
        // 为了验证
        // 为了验证
*/
