// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2487

// Source: src/class171/Code04_Interceptor1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Interceptor1 {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static int s = {};
  inline static Array<int> h = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> sortv = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 3);
  inline static Array<int> treeVal = make_array<int>(MAXN);
  inline static Array<double> treeCnt = make_array<double>(MAXN);
  inline static Array<int> len1 = make_array<int>(MAXN);
  inline static Array<double> cnt1 = make_array<double>(MAXN);
  inline static Array<int> len2 = make_array<int>(MAXN);
  inline static Array<double> cnt2 = make_array<double>(MAXN);
  inline static int queryVal = {};
  inline static double queryCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Interceptor1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void more(int i, int val, double cnt) {
    while ((i <= s)) {
      if ((val > treeVal[i])) {
        (treeVal[i] = val);
        (treeCnt[i] = cnt);
      } else if ((val == treeVal[i])) {
        (treeCnt[i] += cnt);
      }
      (i += Code04_Interceptor1::lowbit(i));
    }
  }
  static void query(int i) {
    (queryVal = 0);
    (queryCnt = 0);
    while ((i > 0)) {
      if ((treeVal[i] > queryVal)) {
        (queryVal = treeVal[i]);
        (queryCnt = treeCnt[i]);
      } else if ((treeVal[i] == queryVal)) {
        (queryCnt += treeCnt[i]);
      }
      (i -= Code04_Interceptor1::lowbit(i));
    }
  }
  static void clear(int i) {
    while ((i <= s)) {
      (treeVal[i] = 0);
      (treeCnt[i] = 0);
      (i += Code04_Interceptor1::lowbit(i));
    }
  }
  static void merge1(int l, int m, int r) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = h[i]);
      (arr[i][2] = v[i]);
    }
    j::sort(arr, l, (m + 1),
            [=](Array<int> a, Array<int> b) { return (b[1] - a[1]); });
    j::sort(arr, (m + 1), (r + 1),
            [=](Array<int> a, Array<int> b) { return (b[1] - a[1]); });
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] >= arr[p2][1]))) {
        (p1++);
        Code04_Interceptor1::more(((s - arr[p1][2]) + 1), len1[arr[p1][0]],
                                  cnt1[arr[p1][0]]);
      }
      Code04_Interceptor1::query(((s - arr[p2][2]) + 1));
      if (((queryVal + 1) > len1[arr[p2][0]])) {
        (len1[arr[p2][0]] = (queryVal + 1));
        (cnt1[arr[p2][0]] = queryCnt);
      } else if (((queryVal + 1) == len1[arr[p2][0]])) {
        (cnt1[arr[p2][0]] += queryCnt);
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      Code04_Interceptor1::clear(((s - arr[i][2]) + 1));
    }
  }
  static void cdq1(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code04_Interceptor1::cdq1(l, mid);
    Code04_Interceptor1::merge1(l, mid, r);
    Code04_Interceptor1::cdq1((mid + 1), r);
  }
  static void merge2(int l, int m, int r) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = h[i]);
      (arr[i][2] = v[i]);
    }
    j::sort(arr, l, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    j::sort(arr, (m + 1), (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] <= arr[p2][1]))) {
        (p1++);
        Code04_Interceptor1::more(arr[p1][2], len2[arr[p1][0]],
                                  cnt2[arr[p1][0]]);
      }
      Code04_Interceptor1::query(arr[p2][2]);
      if (((queryVal + 1) > len2[arr[p2][0]])) {
        (len2[arr[p2][0]] = (queryVal + 1));
        (cnt2[arr[p2][0]] = queryCnt);
      } else if (((queryVal + 1) == len2[arr[p2][0]])) {
        (cnt2[arr[p2][0]] += queryCnt);
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      Code04_Interceptor1::clear(arr[i][2]);
    }
  }
  static void cdq2(int l, int r) {
    if ((l == r)) {
      return;
    }
    int m = jdiv((l + r), 2);
    Code04_Interceptor1::cdq2(l, m);
    Code04_Interceptor1::merge2(l, m, r);
    Code04_Interceptor1::cdq2((m + 1), r);
  }
  static int lower(int num) {
    int l = 1;
    int r = s;
    int ans = 1;
    while ((l <= r)) {
      int mid = jdiv((l + r), 2);
      if ((sortv[mid] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (sortv[i] = v[i]);
    }
    j::sort(sortv, 1, (n + 1));
    (s = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((sortv[s] != sortv[i])) {
        (sortv[(++s)] = sortv[i]);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = Code04_Interceptor1::lower(v[i]));
    }
    for (int i = 1; (i <= n); (i++)) {
      (len1[i] = (len2[i] = 1));
      (cnt1[i] = (cnt2[i] = 1.0));
    }
  }
  static void compute() {
    Code04_Interceptor1::cdq1(1, n);
    {
      int l = 1;
      int r = n;
      for (; (l < r); (l++), (r--)) {
        int a = h[l];
        (h[l] = h[r]);
        (h[r] = a);
        int b = v[l];
        (v[l] = v[r]);
        (v[r] = b);
      }
    }
    Code04_Interceptor1::cdq2(1, n);
    {
      int l = 1;
      int r = n;
      for (; (l < r); (l++), (r--)) {
        int a = len2[l];
        (len2[l] = len2[r]);
        (len2[r] = a);
        double b = cnt2[l];
        (cnt2[l] = cnt2[r]);
        (cnt2[r] = b);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (h[i] = in.nextInt());
      (v[i] = in.nextInt());
    }
    Code04_Interceptor1::prepare();
    Code04_Interceptor1::compute();
    int len = 0;
    double cnt = 0;
    for (int i = 1; (i <= n); (i++)) {
      (len = jmax(len, len1[i]));
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((len1[i] == len)) {
        (cnt += cnt1[i]);
      }
    }
    out.println(len);
    for (int i = 1; (i <= n); (i++)) {
      if ((((len1[i] + len2[i]) - 1) < len)) {
        out.print(String(u"0 "));
      } else {
        out.printf(String(u"%.5f "), jdiv((cnt1[i] * cnt2[i]), cnt));
      }
    }
    out.println();
    out.flush();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Interceptor1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 拦截导弹，java版
// 一共有n个导弹，编号1~n，表示导弹从早到晚依次到达，每个导弹给定，高度h、速度v
// 你有导弹拦截系统，第1次可以拦截任意参数的导弹
// 但是之后拦截的导弹，高度和速度都不能比前一次拦截的导弹大
// 你的目的是尽可能多的拦截导弹，如果有多个最优方案，会随机选一个执行
// 打印最多能拦截几个导弹，并且打印每个导弹被拦截的概率
// 1 <= n <= 5 * 10^4
// 1 <= h、v <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2487
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 位置i、高度h、速度v
        // 树状数组维护前缀最大值、最大值出现的次数
        // i位置结尾的情况下，最长不上升子序列的长度 及其 子序列个数
        // i位置开头的情况下，最长不上升子序列的长度 及其 子序列个数
                // 为了防止出现0下标，(s - v + 1)是树状数组的下标
        // 最长不上升子序列的长度 及其 个数
        // 最长不下降子序列的长度 及其 个数
        // 读写工具类
*/
