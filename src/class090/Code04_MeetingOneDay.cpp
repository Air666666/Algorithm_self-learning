// Source: src/class090/Code04_MeetingOneDay.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MeetingOneDay {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MeetingOneDay() {}
  static int maxEvents(Array<Array<int>> events) {
    int n = events.length;
    j::sort(events, [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    int min = events[0][0];
    int max = events[0][1];
    for (int i = 1; (i < n); (i++)) {
      (max = jmax(max, events[i][1]));
    }
    JHeap<int> heap = JHeap<int>();
    int i = 0;
    int ans = 0;
    for (int day = min; (day <= max); (day++)) {
      while (((i < n) && (events[i][0] == day))) {
        heap.add(events[(i++)][1]);
      }
      while (((!heap.isEmpty()) && (heap.peek() < day))) {
        heap.poll();
      }
      if ((!heap.isEmpty())) {
        heap.poll();
        (ans++);
      }
    }
    return ans;
  }
};

/* Original teaching comments:
// 会议只占一天的最大会议数量
// 给定若干会议的开始、结束时间
// 任何会议的召开期间，你只需要抽出1天来参加
// 但是你安排的那一天，只能参加这个会议，不能同时参加其他会议
// 返回你能参加的最大会议数量
// 测试链接 :
https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/
                // events[i][0] : i号会议开始时间
                // events[i][1] : i号会议结束时间
                // 小根堆 : 会议的结束时间
*/
