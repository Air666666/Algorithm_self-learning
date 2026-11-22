// Source: src/class051/Code06_WaitingTime.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_WaitingTime {
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_WaitingTime() {}
  static int waitingTime1(Array<int> arr, int m) {
    JHeap<Array<int>> heap = JHeap<Array<int>>(
        [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    int n = arr.length;
    for (int i = 0; (i < n); (i++)) {
      heap.add(Array<int>{0, arr[i]});
    }
    for (int i = 0; (i < m); (i++)) {
      Array<int> cur = heap.poll();
      (cur[0] += cur[1]);
      heap.add(cur);
    }
    return heap.peek()[0];
  }
  static int waitingTime2(Array<int> arr, int w) {
    int min = std::numeric_limits<int>::max();
    for (int x : arr) {
      (min = jmin(min, x));
    }
    int ans = 0;
    {
      int l = 0;
      int r = (min * w);
      int m = {};
      for (; (l <= r);) {
        (m = (l + jshr((r - l), 1)));
        if ((Code06_WaitingTime::f(arr, m) >= (w + 1))) {
          (ans = m);
          (r = (m - 1));
        } else {
          (l = (m + 1));
        }
      }
    }
    return ans;
  }
  static int f(Array<int> arr, int time) {
    int ans = 0;
    for (int num : arr) {
      (ans += (jdiv(time, num) + 1));
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    jout.println(String(u"测试开始"));
    int N = 50;
    int V = 30;
    int M = 3000;
    int testTime = 20000;
    for (int i = 0; (i < testTime); (i++)) {
      int n = (static_cast<int>((j::random() * N)) + 1);
      Array<int> arr = Code06_WaitingTime::randomArray(n, V);
      int m = static_cast<int>((j::random() * M));
      int ans1 = Code06_WaitingTime::waitingTime1(arr, m);
      int ans2 = Code06_WaitingTime::waitingTime2(arr, m);
      if ((ans1 != ans2)) {
        jout.println(String(u"出错了!"));
      }
    }
    jout.println(String(u"测试结束"));
  }
  static Array<int> randomArray(int n, int v) {
    Array<int> arr = make_array<int>(n);
    for (int i = 0; (i < n); (i++)) {
      (arr[i] = (static_cast<int>((j::random() * v)) + 1));
    }
    return arr;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_WaitingTime::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 计算等位时间
// 给定一个数组arr长度为n，表示n个服务员，每服务一个人的时间
// 给定一个正数m，表示有m个人等位，如果你是刚来的人，请问你需要等多久？
// 假设m远远大于n，比如n <= 10^3, m <= 10^9，该怎么做是最优解？
// 谷歌的面试，这个题连考了2个月
// 找不到测试链接，所以用对数器验证
        // 堆模拟
        // 验证方法，不是重点
        // 如果m很大，该方法会超时
        // 时间复杂度O(m * log(n))，额外空间复杂度O(n)
                // 一个一个对象int[]
                // [醒来时间，服务一个客人要多久]
        // 二分答案法
        // 最优解
        // 时间复杂度O(n * log(min * w))，额外空间复杂度O(1)
                        // m中点，表示一定要让服务员工作的时间！
                        // 能够给几个客人提供服务
        // 如果每个服务员工作time，可以接待几位客人（结束的、开始的客人都算）
        // 对数器测试
        // 对数器测试
*/
