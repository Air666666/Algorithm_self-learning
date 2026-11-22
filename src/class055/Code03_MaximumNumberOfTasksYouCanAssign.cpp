// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

// Source: src/class055/Code03_MaximumNumberOfTasksYouCanAssign.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MaximumNumberOfTasksYouCanAssign {
  inline static Array<int> tasks = {};
  inline static Array<int> workers = {};
  inline static int MAXN = 50001;
  inline static Array<int> deque = make_array<int>(MAXN);
  inline static int h = {};
  inline static int t = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MaximumNumberOfTasksYouCanAssign() {}
  static int maxTaskAssign(Array<int> ts, Array<int> ws, int pills,
                           int strength) {
    (tasks = ts);
    (workers = ws);
    j::sort(tasks);
    j::sort(workers);
    int tsize = tasks.length;
    int wsize = workers.length;
    int ans = 0;
    {
      int l = 0;
      int r = jmin(tsize, wsize);
      int m = {};
      for (; (l <= r);) {
        (m = jdiv((l + r), 2));
        if (Code03_MaximumNumberOfTasksYouCanAssign::f(
                0, (m - 1), (wsize - m), (wsize - 1), strength, pills)) {
          (ans = m);
          (l = (m + 1));
        } else {
          (r = (m - 1));
        }
      }
    }
    return ans;
  }
  static bool f(int tl, int tr, int wl, int wr, int s, int pills) {
    (h = (t = 0));
    int cnt = 0;
    {
      int i = wl;
      int j = tl;
      for (; (i <= wr); (i++)) {
        for (; ((j <= tr) && (tasks[j] <= workers[i])); (j++)) {
          (deque[(t++)] = j);
        }
        if (((h < t) && (tasks[deque[h]] <= workers[i]))) {
          (h++);
        } else {
          for (; ((j <= tr) && (tasks[j] <= (workers[i] + s))); (j++)) {
            (deque[(t++)] = j);
          }
          if ((h < t)) {
            (cnt++);
            (t--);
          } else {
            return false;
          }
        }
      }
    }
    return (cnt <= pills);
  }
};

/* Original teaching comments:
// 你可以安排的最多任务数目
// 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成
// 需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
// 第i个任务需要 tasks[i] 的力量才能完成
// 每个工人的力量值保存在下标从 0 开始的整数数组workers中，
// 第j个工人的力量值为 workers[j]
//
每个工人只能完成一个任务，且力量值需要大于等于该任务的力量要求值，即workers[j]>=tasks[i]
// 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength
// 你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸
// 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength
// 请你返回 最多 有多少个任务可以被完成。
// 测试链接 :
https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/
        // 两个数组排序 : O(n * logn) + O(m * logm)
        // 二分答案的过程，每次二分都用一下双端队列 :
O((n和m最小值)*log(n和m最小值))
        // 最复杂的反而是排序的过程了，所以时间复杂度O(n * logn) + O(m * logm)
                // [0, Math.min(tsize, wsize)]
                        // m中点，一定要完成的任务数量
        // tasks[tl....tr]需要力量最小的几个任务
        // workers[wl....wr]力量值最大的几个工人
        // 药效是s，一共有的药pills个
        // 在药的数量不超情况下，能不能每个工人都做一个任务
                // 已经使用的药的数量
                        // i : 工人的编号
                        // j : 任务的编号
                                // 工人不吃药的情况下，去解锁任务
                                // 吃药之后的逻辑
*/
