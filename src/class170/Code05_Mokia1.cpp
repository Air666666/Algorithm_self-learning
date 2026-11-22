// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4390

// Source: src/class170/Code05_Mokia1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Mokia1 {
  inline static int MAXM = 200001;
  inline static int MAXV = 2000002;
  inline static int w = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXM, 5);
  inline static int cnte = 0;
  inline static int cntq = 0;
  inline static Array<int> tree = make_array<int>(MAXV);
  inline static Array<int> ans = make_array<int>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Mokia1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= w)) {
      (tree[i] += v);
      (i += Code05_Mokia1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code05_Mokia1::lowbit(i));
    }
    return ret;
  }
  static void addPeople(int x, int y, int v) {
    (arr[(++cnte)][0] = 1);
    (arr[cnte][1] = x);
    (arr[cnte][2] = y);
    (arr[cnte][3] = v);
  }
  static void addQuery(int x, int y, int v, int q) {
    (arr[(++cnte)][0] = 2);
    (arr[cnte][1] = x);
    (arr[cnte][2] = y);
    (arr[cnte][3] = v);
    (arr[cnte][4] = q);
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] <= arr[p2][1]))) {
        (p1++);
        if ((arr[p1][0] == 1)) {
          Code05_Mokia1::add(arr[p1][2], arr[p1][3]);
        }
      }
      if ((arr[p2][0] == 2)) {
        (ans[arr[p2][4]] += (arr[p2][3] * Code05_Mokia1::query(arr[p2][2])));
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      if ((arr[i][0] == 1)) {
        Code05_Mokia1::add(arr[i][2], (-arr[i][3]));
      }
    }
    j::sort(arr, l, (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code05_Mokia1::cdq(l, mid);
    Code05_Mokia1::cdq((mid + 1), r);
    Code05_Mokia1::merge(l, mid, r);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    in.nextInt();
    (w = (in.nextInt() + 1));
    int op = {};
    int x = {};
    int y = {};
    int v = {};
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    (op = in.nextInt());
    while ((op != 3)) {
      if ((op == 1)) {
        (x = (in.nextInt() + 1));
        (y = (in.nextInt() + 1));
        (v = in.nextInt());
        Code05_Mokia1::addPeople(x, y, v);
      } else {
        (a = (in.nextInt() + 1));
        (b = (in.nextInt() + 1));
        (c = (in.nextInt() + 1));
        (d = (in.nextInt() + 1));
        Code05_Mokia1::addQuery(c, d, 1, (++cntq));
        Code05_Mokia1::addQuery((a - 1), (b - 1), 1, cntq);
        Code05_Mokia1::addQuery((a - 1), d, (-1), cntq);
        Code05_Mokia1::addQuery(c, (b - 1), (-1), cntq);
      }
      (op = in.nextInt());
    }
    Code05_Mokia1::cdq(1, cnte);
    for (int i = 1; (i <= cntq); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Mokia1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 摩基亚，java版
// 给定数字w，表示一个w * w的正方形区域，所有位置都在其中
// 接下来有m条操作，每种操作是如下两种类型中的一种
// 操作 1 x y v   : 坐标(x, y)位置增加了v个人
// 操作 2 a b c d : 打印左上角(a, b)、右下角(c, d)区域里的人数
// 1 <= w <= 2 * 10^6
// 1 <= m <= 2 * 10^5
// 0 <= v <= 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P4390
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // op == 1表示增加事件，x、y、人数v
        // op == 2表示查询事件，x、y、效果v、查询编号q
        // 树状数组
        // 读写工具类
*/
