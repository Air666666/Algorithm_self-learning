// Source: src/class083/Code01_MaximumProfitInJobScheduling.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MaximumProfitInJobScheduling {
  inline static int MAXN = 50001;
  inline static Array<Array<int>> jobs = make_array<int>(MAXN, 3);
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MaximumProfitInJobScheduling() {}
  static int jobScheduling(Array<int> startTime, Array<int> endTime,
                           Array<int> profit) {
    int n = startTime.length;
    for (int i = 0; (i < n); (i++)) {
      (jobs[i][0] = startTime[i]);
      (jobs[i][1] = endTime[i]);
      (jobs[i][2] = profit[i]);
    }
    j::sort(jobs, 0, n,
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    (dp[0] = jobs[0][2]);
    {
      int i = 1;
      int start = {};
      for (; (i < n); (i++)) {
        (start = jobs[i][0]);
        (dp[i] = jobs[i][2]);
        if ((jobs[0][1] <= start)) {
          (dp[i] +=
           dp[Code01_MaximumProfitInJobScheduling::find((i - 1), start)]);
        }
        (dp[i] = jmax(dp[i], dp[(i - 1)]));
      }
    }
    return dp[(n - 1)];
  }
  static int find(int i, int start) {
    int ans = 0;
    int l = 0;
    int r = i;
    int m = {};
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((jobs[m][1] <= start)) {
        (ans = m);
        (l = (m + 1));
      } else {
        (r = (m - 1));
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 规划兼职工作
// 你打算利用空闲时间来做兼职工作赚些零花钱，这里有n份兼职工作
// 每份工作预计从startTime[i]开始、endTime[i]结束，报酬为profit[i]
// 返回可以获得的最大报酬
// 注意，时间上出现重叠的 2 份工作不能同时进行
// 如果你选择的工作在时间X结束，那么你可以立刻进行在时间X开始的下一份工作
// 测试链接 : https://leetcode.cn/problems/maximum-profit-in-job-scheduling/
                // 工作按照结束时间从小到大排序
        // job[0...i]范围上，找到结束时间 <= start，最右的下标
*/
