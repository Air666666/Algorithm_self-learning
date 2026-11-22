// Source: src/class089/Code04_MeetingRoomsII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MeetingRoomsII {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MeetingRoomsII() {}
  static int minMeetingRooms(Array<Array<int>> meeting) {
    int n = meeting.length;
    j::sort(meeting, [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    JHeap<int> heap = JHeap<int>();
    int ans = 0;
    for (int i = 0; (i < n); (i++)) {
      while (((!heap.isEmpty()) && (heap.peek() <= meeting[i][0]))) {
        heap.poll();
      }
      heap.add(meeting[i][1]);
      (ans = jmax(ans, heap.size()));
    }
    return ans;
  }
};

/* Original teaching comments:
// 会议室II
// 给你一个会议时间安排的数组 intervals
// 每个会议时间都会包括开始和结束的时间intervals[i]=[starti, endi]
// 返回所需会议室的最小数量
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/
*/
