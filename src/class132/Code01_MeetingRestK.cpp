// Source: src/class132/Code01_MeetingRestK.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MeetingRestK {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MeetingRestK() {}
  static i64 best1(Array<int> arr, int k) {
    int n = arr.length;
    Array<i64> dp = make_array<i64>((n + 1));
    {
      int i = (n - 1);
      int j = {};
      int sum = {};
      for (; (i >= 0); (i--)) {
        for ((j = (i + 1)), (sum = 0); ((j < n) && (sum < k)); (j++)) {
          (sum += arr[j]);
        }
        (dp[i] = jmax(dp[(i + 1)], (dp[j] + arr[i])));
      }
    }
    return dp[0];
  }
  static i64 best2(Array<int> arr, int k) {
    int n = arr.length;
    Array<int> jump = make_array<int>(n);
    {
      int i = 0;
      int l = 1;
      int r = 1;
      int sum = 0;
      for (; (i < (n - 1)); (i++), (l++)) {
        while (((r < n) && (sum < k))) {
          (sum += arr[(r++)]);
        }
        (jump[i] = r);
        (sum -= arr[l]);
      }
    }
    (jump[(n - 1)] = n);
    Array<i64> dp = make_array<i64>((n + 1));
    for (int i = (n - 1); (i >= 0); (i--)) {
      (dp[i] = jmax(dp[(i + 1)], (dp[jump[i]] + arr[i])));
    }
    return dp[0];
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> arr = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (arr[i] = (static_cast<int>((j::random() * v)) + 1));
    }
    return arr;
  }
  static void java_main(Array<String> args) {
    int n = 1000;
    int v = 3000;
    int testTime = 10000;
    jout.println(String(u"测试开始"));
    for (int i = 1; (i <= testTime); (i++)) {
      int size = (static_cast<int>((j::random() * n)) + 1);
      Array<int> arr = Code01_MeetingRestK::randomArray(size, v);
      int k = (static_cast<int>((j::random() * v)) + 1);
      i64 ans1 = Code01_MeetingRestK::best1(arr, k);
      i64 ans2 = Code01_MeetingRestK::best2(arr, k);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MeetingRestK::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 休息k分钟最大会议和
// 给定一个长度为n的数组arr，表示从早到晚发生的会议，各自召开的分钟数
// 当选择一个会议并参加之后，必须休息k分钟
// 返回能参加的会议时长最大累加和
// 比如，arr = { 200, 5, 6, 14, 7, 300 }，k = 15
// 最好的选择为，选择200分钟的会议，然后必须休息15分钟
// 那么接下来的5分钟、6分钟、14分钟的会议注定错过
// 然后放弃7分钟的会议，而选择参加300分钟的会议
// 最终返回500
// 1 <= n、arr[i]、k <= 10^6
// 来自真实大厂笔试，对数器验证
        // 不减少枚举的可能性
        // 时间复杂度O(n^2)
        // 利用预处理结构减少枚举的可能性
        // 时间复杂度O(n)
                // 窗口[l...r)，左闭右开，sum是窗口累加和
        // 为了测试
        // 为了测试
*/
