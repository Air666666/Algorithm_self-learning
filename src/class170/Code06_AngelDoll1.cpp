// Source: src/class170/Code06_AngelDoll1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_AngelDoll1 {
  inline static int MAXN = 300001;
  inline static int MAXV = 1000002;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int v = {};
  inline static Array<Array<int>> tim = make_array<int>(jshl(MAXN, 1), 4);
  inline static Array<Array<int>> arr = make_array<int>(jshl(MAXN, 1), 4);
  inline static int cnte = 0;
  inline static int cntq = 0;
  inline static Array<int> tree = make_array<int>(MAXV);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_AngelDoll1() {}
  static void clone(Array<int> a, Array<int> b) {
    (a[0] = b[0]);
    (a[1] = b[1]);
    (a[2] = b[2]);
    (a[3] = b[3]);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void more(int i, int num) {
    while ((i <= v)) {
      (tree[i] = jmax(tree[i], num));
      (i += Code06_AngelDoll1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = (-INF);
    while ((i > 0)) {
      (ret = jmax(ret, tree[i]));
      (i -= Code06_AngelDoll1::lowbit(i));
    }
    return ret;
  }
  static void clear(int i) {
    while ((i <= v)) {
      (tree[i] = (-INF));
      (i += Code06_AngelDoll1::lowbit(i));
    }
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] <= arr[p2][1]))) {
        (p1++);
        if ((arr[p1][0] == 1)) {
          Code06_AngelDoll1::more(arr[p1][2], (arr[p1][1] + arr[p1][2]));
        }
      }
      if ((arr[p2][0] == 2)) {
        (ans[arr[p2][3]] =
             jmin(ans[arr[p2][3]], ((arr[p2][1] + arr[p2][2]) -
                                    Code06_AngelDoll1::query(arr[p2][2]))));
      }
    }
    for (int i = l; (i <= p1); (i++)) {
      if ((arr[i][0] == 1)) {
        Code06_AngelDoll1::clear(arr[i][2]);
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
    Code06_AngelDoll1::cdq(l, mid);
    Code06_AngelDoll1::cdq((mid + 1), r);
    Code06_AngelDoll1::merge(l, mid, r);
  }
  static void to1() {
    for (int i = 1; (i <= cnte); (i++)) {
      Code06_AngelDoll1::clone(arr[i], tim[i]);
    }
    Code06_AngelDoll1::cdq(1, cnte);
  }
  static void to2() {
    for (int i = 1; (i <= cnte); (i++)) {
      Code06_AngelDoll1::clone(arr[i], tim[i]);
      (arr[i][1] = (v - arr[i][1]));
    }
    Code06_AngelDoll1::cdq(1, cnte);
  }
  static void to3() {
    for (int i = 1; (i <= cnte); (i++)) {
      Code06_AngelDoll1::clone(arr[i], tim[i]);
      (arr[i][1] = (v - arr[i][1]));
      (arr[i][2] = (v - arr[i][2]));
    }
    Code06_AngelDoll1::cdq(1, cnte);
  }
  static void to4() {
    for (int i = 1; (i <= cnte); (i++)) {
      Code06_AngelDoll1::clone(arr[i], tim[i]);
      (arr[i][2] = (v - arr[i][2]));
    }
    Code06_AngelDoll1::cdq(1, cnte);
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
      for (; (i <= n); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (tim[(++cnte)][0] = 1);
        (tim[cnte][1] = (++x));
        (tim[cnte][2] = (++y));
        (v = jmax(v, jmax(x, y)));
      }
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        (tim[(++cnte)][0] = op);
        (tim[cnte][1] = (++x));
        (tim[cnte][2] = (++y));
        if ((op == 2)) {
          (tim[cnte][3] = (++cntq));
        }
        (v = jmax(v, jmax(x, y)));
      }
    }
    (v++);
    for (int i = 1; (i <= v); (i++)) {
      (tree[i] = (-INF));
    }
    for (int i = 1; (i <= cntq); (i++)) {
      (ans[i] = INF);
    }
    Code06_AngelDoll1::to1();
    Code06_AngelDoll1::to2();
    Code06_AngelDoll1::to3();
    Code06_AngelDoll1::to4();
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
  Code06_AngelDoll1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 天使玩偶，java版
// 规定(x1, y1)和(x2, y2)之间的距离 = | x1 - x2 | + | y1 - y2 |
// 一开始先给定n个点的位置，接下来有m条操作，每种操作是如下两种类型中的一种
// 操作 1 x y : 在(x, y)位置添加一个点
// 操作 2 x y : 打印已经添加的所有点中，距离(x, y)最近的点有多远
// 1 <= n、m <= 3 * 10^5
// 0 <= x、y <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4169
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // op == 1代表添加事件，x、y、空缺
        // op == 2代表查询事件，x、y、查询编号q
        // tim永远保持原始时序，每次变换象限都拷贝给arr，然后执行cdq分治
        // 树状数组，下标是y的值，维护前缀范围上的最大值
        // 树状数组，如果i位置之前的值更大，忽略，num更大才更新
        // 树状数组，查询1~i范围上的最大值
        // 因为本题的特殊性，树状数组一定全部清空
        // 所以当初更新时，i位置碰过哪些位置，一律设置无效值即可
        // 点变换到第一象限进行cdq分治
        // 点变换到第二象限进行cdq分治
        // 点变换到第三象限进行cdq分治
        // 点变换到第四象限进行cdq分治
                // 树状数组下标从1开始，所以x和y都要自增一下
                // x或y的最大值用v记录，变换象限时，防止 v - (x或y) 出现0
                // 所以最后v再自增一下
                // 初始化树状数组
                // 初始化答案数组
        // 读写工具类
*/
