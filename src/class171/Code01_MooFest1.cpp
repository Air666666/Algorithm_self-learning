// Source: src/class171/Code01_MooFest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MooFest1 {
  inline static int MAXN = 50001;
  inline static int n = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<Array<int>> tmp = make_array<int>(MAXN, 2);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MooFest1() {}
  static void clone(Array<int> a, Array<int> b) {
    (a[0] = b[0]);
    (a[1] = b[1]);
  }
  static i64 merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    i64 rsum = 0;
    i64 lsum = 0;
    i64 ans = 0;
    for ((p1 = l); (p1 <= m); (p1++)) {
      (rsum += arr[p1][1]);
    }
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] < arr[p2][1]))) {
        (p1++);
        (rsum -= arr[p1][1]);
        (lsum += arr[p1][1]);
      }
      (ans += ((((((1LL * ((p1 - l) + 1)) * arr[p2][1]) - lsum) + rsum) -
                ((1LL * (m - p1)) * arr[p2][1])) *
               arr[p2][0]));
    }
    (p1 = l);
    (p2 = (m + 1));
    int i = l;
    while (((p1 <= m) && (p2 <= r))) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 =
            ((arr[p1][1] <= arr[p2][1]) ? arr[(p1++)] : arr[(p2++)]);
        return Code01_MooFest1::clone(jargument_0, jargument_1);
      }();
    }
    while ((p1 <= m)) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 = arr[(p1++)];
        return Code01_MooFest1::clone(jargument_0, jargument_1);
      }();
    }
    while ((p2 <= r)) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 = arr[(p2++)];
        return Code01_MooFest1::clone(jargument_0, jargument_1);
      }();
    }
    for ((i = l); (i <= r); (i++)) {
      Code01_MooFest1::clone(arr[i], tmp[i]);
    }
    return ans;
  }
  static i64 cdq(int l, int r) {
    if ((l == r)) {
      return 0;
    }
    int mid = jdiv((l + r), 2);
    return [&]() {
      auto jleft = [&]() {
        auto jleft = Code01_MooFest1::cdq(l, mid);
        auto jright = Code01_MooFest1::cdq((mid + 1), r);
        return (jleft + jright);
      }();
      auto jright = Code01_MooFest1::merge(l, mid, r);
      return (jleft + jright);
    }();
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = in.nextInt());
      (arr[i][1] = in.nextInt());
    }
    j::sort(arr, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
    out.println(Code01_MooFest1::cdq(1, n));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_MooFest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 奶牛音量和，java版
// 一共有n只奶牛，每只奶牛给定，听力v、坐标x
// 任何一对奶牛产生的音量 = max(vi, vj) * 两只奶牛的距离
// 一共有n * (n - 1) / 2对奶牛，打印音量总和
// 1 <= n、v、x <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P5094
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 听力v、位置x
        // 归并排序需要
        // 读写工具类
*/
