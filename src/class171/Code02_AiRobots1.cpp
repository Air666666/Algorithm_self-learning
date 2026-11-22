// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF1045G
// https://codeforces.com/problemset/problem/1045/G

// Source: src/class171/Code02_AiRobots1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_AiRobots1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int k = {};
  inline static int s = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 5);
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_AiRobots1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= s)) {
      (tree[i] += v);
      (i += Code02_AiRobots1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code02_AiRobots1::lowbit(i));
    }
    return ret;
  }
  static int query(int l, int r) {
    return [&]() {
      auto jleft = Code02_AiRobots1::sum(r);
      auto jright = Code02_AiRobots1::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static i64 merge(int l, int m, int r) {
    int winl = l;
    int winr = (l - 1);
    i64 ans = 0;
    for (int i = (m + 1); (i <= r); (i++)) {
      while (((winl <= m) && (arr[winl][2] < (arr[i][2] - k)))) {
        Code02_AiRobots1::add(arr[winl][0], (-1));
        (winl++);
      }
      while ((((winr + 1) <= m) && (arr[(winr + 1)][2] <= (arr[i][2] + k)))) {
        (winr++);
        Code02_AiRobots1::add(arr[winr][0], 1);
      }
      (ans += Code02_AiRobots1::query(arr[i][3], arr[i][4]));
    }
    for (int i = winl; (i <= winr); (i++)) {
      Code02_AiRobots1::add(arr[i][0], (-1));
    }
    j::sort(arr, l, (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    return ans;
  }
  static i64 cdq(int l, int r) {
    if ((l == r)) {
      return 0;
    }
    int mid = jdiv((l + r), 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code02_AiRobots1::cdq(l, mid);
        auto jright = Code02_AiRobots1::cdq((mid + 1), r);
        return (jleft + jright);
      }();
      auto jright = Code02_AiRobots1::merge(l, mid, r);
      return (jleft + jright);
    }();
  }
  static int lower(int num) {
    int l = 1;
    int r = s;
    int m = {};
    int ans = 1;
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((x[m] >= num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static int upper(int num) {
    int l = 1;
    int r = s;
    int m = {};
    int ans = (s + 1);
    while ((l <= r)) {
      (m = jdiv((l + r), 2));
      if ((x[m] > num)) {
        (ans = m);
        (r = (m - 1));
      } else {
        (l = (m + 1));
      }
    }
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (x[i] = arr[i][0]);
    }
    j::sort(x, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((x[s] != x[i])) {
        (x[(++s)] = x[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][3] = Code02_AiRobots1::lower((arr[i][0] - arr[i][1])));
      (arr[i][4] = (Code02_AiRobots1::upper((arr[i][0] + arr[i][1])) - 1));
      (arr[i][0] = Code02_AiRobots1::lower(arr[i][0]));
    }
    j::sort(arr, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (b[1] - a[1]); });
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = in.nextInt());
      (arr[i][1] = in.nextInt());
      (arr[i][2] = in.nextInt());
    }
    Code02_AiRobots1::prepare();
    out.println(Code02_AiRobots1::cdq(1, n));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_AiRobots1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 机器人聊天对，java版
// 一共有n个机器人，给定一个整数k，每个机器人给定，位置x、视野y、智商q
// 第i个机器人可以看见的范围是[xi − yi, xi + yi]
// 如果两个机器人相互之间可以看见，并且智商差距不大于k，那么它们会开始聊天
// 打印有多少对机器人可以聊天
// 1 <= n <= 10^5
// 0 <= k <= 20
// 0 <= x、y、q <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/CF1045G
// 测试链接 : https://codeforces.com/problemset/problem/1045/G
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 位置x、视野y、智商q、能看到的最左位置l、能看到的最右位置r
        // 所有x坐标组成的数组
        // 读写工具类
*/
