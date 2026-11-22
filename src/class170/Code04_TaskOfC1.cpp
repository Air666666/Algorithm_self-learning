// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3755

// Source: src/class170/Code04_TaskOfC1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_TaskOfC1 {
  inline static int MAXN = 500001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 5);
  inline static int cnt = 0;
  inline static Array<Array<int>> tmp = make_array<int>(MAXN, 5);
  inline static Array<i64> ans = make_array<i64>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_TaskOfC1() {}
  static void clone(Array<int> a, Array<int> b) {
    (a[0] = b[0]);
    (a[1] = b[1]);
    (a[2] = b[2]);
    (a[3] = b[3]);
    (a[4] = b[4]);
  }
  static void addStation(int x, int y, int v) {
    (arr[(++cnt)][0] = 1);
    (arr[cnt][1] = x);
    (arr[cnt][2] = y);
    (arr[cnt][3] = v);
  }
  static void addQuery(int x, int y, int v, int q) {
    (arr[(++cnt)][0] = 2);
    (arr[cnt][1] = x);
    (arr[cnt][2] = y);
    (arr[cnt][3] = v);
    (arr[cnt][4] = q);
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    i64 sum = 0;
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][2] <= arr[p2][2]))) {
        (p1++);
        if ((arr[p1][0] == 1)) {
          (sum += arr[p1][3]);
        }
      }
      if ((arr[p2][0] == 2)) {
        (ans[arr[p2][4]] += (sum * arr[p2][3]));
      }
    }
    (p1 = l);
    (p2 = (m + 1));
    int i = l;
    while (((p1 <= m) && (p2 <= r))) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 =
            ((arr[p1][2] <= arr[p2][2]) ? arr[(p1++)] : arr[(p2++)]);
        return Code04_TaskOfC1::clone(jargument_0, jargument_1);
      }();
    }
    while ((p1 <= m)) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 = arr[(p1++)];
        return Code04_TaskOfC1::clone(jargument_0, jargument_1);
      }();
    }
    while ((p2 <= r)) {
      [&]() {
        auto jargument_0 = tmp[(i++)];
        auto jargument_1 = arr[(p2++)];
        return Code04_TaskOfC1::clone(jargument_0, jargument_1);
      }();
    }
    for ((i = l); (i <= r); (i++)) {
      Code04_TaskOfC1::clone(arr[i], tmp[i]);
    }
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code04_TaskOfC1::cdq(l, mid);
    Code04_TaskOfC1::cdq((mid + 1), r);
    Code04_TaskOfC1::merge(l, mid, r);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      int v = {};
      for (; (i <= n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (v = in.nextInt());
        Code04_TaskOfC1::addStation(x, y, v);
      }
    }
    {
      int i = 1;
      int a = {};
      int b = {};
      int c = {};
      int d = {};
      for (; (i <= m); (i++)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        (d = in.nextInt());
        Code04_TaskOfC1::addQuery(c, d, 1, i);
        Code04_TaskOfC1::addQuery((a - 1), (b - 1), 1, i);
        Code04_TaskOfC1::addQuery((a - 1), d, (-1), i);
        Code04_TaskOfC1::addQuery(c, (b - 1), (-1), i);
      }
    }
    j::sort(arr, 1, (cnt + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1]) ? (a[1] - b[1]) : (a[0] - b[0]));
    });
    Code04_TaskOfC1::cdq(1, cnt);
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_TaskOfC1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 老C的任务，java版
// 有n个基站，每个基站给定x、y、v，表示基站在(x, y)位置，功率为v
// 接下来有m条查询，每条查询格式如下
// 查询 a b c d : 打印左上角(a, b)、右下角(c, d)的区域里基站的功率和
// 1 <= n、m <= 10^5
// 其余数值都在int类型的范围
// 测试链接 : https://www.luogu.com.cn/problem/P3755
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // op == 1代表基站，x、y、功率v
        // op == 2代表查询，x、y、效果v、查询编号q
        // 归并排序需要
        // 问题的答案
                // 下面是经典归并的过程，为啥不直接排序了？
                // 因为没有用到高级数据结构，复杂度可以做到O(n * log n)
                // 那么就维持最好的复杂度，不用排序
        // 读写工具类
*/
