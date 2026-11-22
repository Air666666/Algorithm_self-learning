// Source: src/class171/Code03_Sequence1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Sequence1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> lv = make_array<int>(MAXN);
  inline static Array<int> rv = make_array<int>(MAXN);
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 4);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> dp = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Sequence1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void more(int i, int num) {
    while ((i <= n)) {
      (tree[i] = jmax(tree[i], num));
      (i += Code03_Sequence1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret = jmax(ret, tree[i]));
      (i -= Code03_Sequence1::lowbit(i));
    }
    return ret;
  }
  static void clear(int i) {
    while ((i <= n)) {
      (tree[i] = 0);
      (i += Code03_Sequence1::lowbit(i));
    }
  }
  static void merge(int l, int m, int r) {
    for (int i = l; (i <= r); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = v[i]);
      (arr[i][2] = lv[i]);
      (arr[i][3] = rv[i]);
    }
    j::sort(arr, l, (m + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    j::sort(arr, (m + 1), (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] <= arr[p2][2]))) {
        (p1++);
        Code03_Sequence1::more(arr[p1][3], dp[arr[p1][0]]);
      }
      (dp[arr[p2][0]] =
           jmax(dp[arr[p2][0]], (Code03_Sequence1::query(arr[p2][1]) + 1)));
    }
    for (int i = l; (i <= p1); (i++)) {
      Code03_Sequence1::clear(arr[i][3]);
    }
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code03_Sequence1::cdq(l, mid);
    Code03_Sequence1::merge(l, mid, r);
    Code03_Sequence1::cdq((mid + 1), r);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (v[i] = in.nextInt());
      (lv[i] = v[i]);
      (rv[i] = v[i]);
    }
    {
      int i = 1;
      int idx = {};
      int val = {};
      for (; (i <= m); (i++)) {
        (idx = in.nextInt());
        (val = in.nextInt());
        (lv[idx] = jmin(lv[idx], val));
        (rv[idx] = jmax(rv[idx], val));
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (dp[i] = 1);
    }
    Code03_Sequence1::cdq(1, n);
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans = jmax(ans, dp[i]));
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Sequence1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 序列，java版
// 给定一个长度为n的数组arr，一共有m条操作，格式为 x v 表示x位置的数变成v
// 你可以选择不执行任何操作，或者只选择一个操作来执行，然后arr不再变动
//
请在arr中选出一组下标序列，不管你做出什么选择，下标序列所代表的数字都是不下降的
// 打印序列能达到的最大长度
// 1 <= 所有数字 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4093
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 位置i、数值v、最小值lv、最大值rv
        // 树状数组维护前缀最大值
                // 辅助数组arr拷贝l..r所有的对象
                // 接下来的排序都发生在arr中，不影响原始的次序
                // 左侧根据v排序
                // 右侧根据lv排序
                        // 左侧对象.v <= 右侧对象.lv 窗口扩充
                                //
树状数组中，下标是rv，加入的值是左侧对象的dp值
                        // 右侧对象更新dp值，查出1..v范围上最大的dp值 + 1
                // 清空树状数组
        // 读写工具类
*/
