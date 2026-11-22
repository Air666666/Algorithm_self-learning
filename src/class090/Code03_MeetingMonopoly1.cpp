// Source: src/class090/Code03_MeetingMonopoly1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MeetingMonopoly1 {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MeetingMonopoly1() {}
  static int eraseOverlapIntervals(Array<Array<int>> meeting) {
    j::sort(meeting, [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    int n = meeting.length;
    int ans = 0;
    {
      int i = 0;
      int cur = (-50001);
      for (; (i < n); (i++)) {
        if ((cur <= meeting[i][0])) {
          (ans++);
          (cur = meeting[i][1]);
        }
      }
    }
    return (n - ans);
  }
  static int maxMeeting1(Array<Array<int>> meeting) {
    return Code03_MeetingMonopoly1::f(meeting, meeting.length, 0);
  }
  static int f(Array<Array<int>> meeting, int n, int i) {
    int ans = 0;
    if ((i == n)) {
      {
        int j = 0;
        int cur = (-1);
        for (; (j < n); (j++)) {
          if ((cur <= meeting[j][0])) {
            (ans++);
            (cur = meeting[j][1]);
          }
        }
      }
    } else {
      for (int j = i; (j < n); (j++)) {
        Code03_MeetingMonopoly1::swap(meeting, i, j);
        (ans = jmax(ans, Code03_MeetingMonopoly1::f(meeting, n, (i + 1))));
        Code03_MeetingMonopoly1::swap(meeting, i, j);
      }
    }
    return ans;
  }
  static void swap(Array<Array<int>> meeting, int i, int j) {
    Array<int> tmp = meeting[i];
    (meeting[i] = meeting[j]);
    (meeting[j] = tmp);
  }
  static int maxMeeting2(Array<Array<int>> meeting) {
    j::sort(meeting, [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    int n = meeting.length;
    int ans = 0;
    {
      int i = 0;
      int cur = (-1);
      for (; (i < n); (i++)) {
        if ((cur <= meeting[i][0])) {
          (ans++);
          (cur = meeting[i][1]);
        }
      }
    }
    return ans;
  }
  static Array<Array<int>> randomMeeting(int n, int m) {
    Array<Array<int>> ans = make_array<int>(n, 2);
    {
      int i = 0;
      int a = {};
      int b = {};
      for (; (i < n); (i++)) {
        (a = static_cast<int>((j::random() * m)));
        (b = static_cast<int>((j::random() * m)));
        if ((a == b)) {
          (ans[i][0] = a);
          (ans[i][1] = (a + 1));
        } else {
          (ans[i][0] = jmin(a, b));
          (ans[i][1] = jmax(a, b));
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    int N = 10;
    int M = 12;
    int testTimes = 2000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTimes); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<Array<int>> meeting = Code03_MeetingMonopoly1::randomMeeting(n, M);
      int ans1 = Code03_MeetingMonopoly1::maxMeeting1(meeting);
      int ans2 = Code03_MeetingMonopoly1::maxMeeting2(meeting);
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
  Code03_MeetingMonopoly1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 会议必须独占时间段的最大会议数量
// 给定若干会议的开始、结束时间
// 你参加某个会议的期间，不能参加其他会议
// 返回你能参加的最大会议数量
// 同学找到了Leetcode的在线测试，题意类似
// 测试链接 :https://leetcode.cn/problems/non-overlapping-intervals/
        // 测试链接 :https://leetcode.cn/problems/non-overlapping-intervals/
        // 测试链接中，问至少删除多少会议，可以让剩下的会议都不重合
        // 那么求出，最多能不重合的参加多少会议，然后 n - 这个数量，就是答案
        // 同时注意，测试链接中，会议的时间点范围[- 5 * 10 ^ 4 ~ + 5 * 10 ^ 4]
        // 其实就是课上讲的方法，稍微改动一下即可，改动的地方已经加上注释
                // cur初始设置为-50001，因为题目数据状况如此
                // 会议总数 - 参加的最大会议数量
        // 暴力方法
        // 为了验证
        // 时间复杂度O(n!)
        // 把所有会议全排列
        // 其中一定有安排会议次数最多的排列
        // 正式方法
        // 时间复杂度O(n*logn)
                // meeting[i][0] : i号会议开始时间
                // meeting[i][1] : i号会议结束时间
        // 为了验证
        // 生成随机会议
        // 对数器
        // 为了验证
                                // 如果出错了
                                // 可以增加打印行为找到一组出错的例子
                                // 然后去debug
*/
