// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3157

// Source: src/class170/Code02_DynamicInversion1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_DynamicInversion1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 50001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> num = make_array<int>(MAXN);
  inline static Array<int> pos = make_array<int>(MAXN);
  inline static Array<int> del = make_array<int>(MAXM);
  inline static Array<Array<int>> arr = make_array<int>((MAXN + MAXM), 4);
  inline static int cnt = 0;
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<i64> ans = make_array<i64>(MAXM);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_DynamicInversion1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code02_DynamicInversion1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code02_DynamicInversion1::lowbit(i));
    }
    return ret;
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][1] < arr[p2][1]))) {
        (p1++);
        Code02_DynamicInversion1::add(arr[p1][0], arr[p1][2]);
      }
      (ans[arr[p2][3]] += (arr[p2][2] * [&]() {
         auto jleft = Code02_DynamicInversion1::query(n);
         auto jright = Code02_DynamicInversion1::query(arr[p2][0]);
         return (jleft - jright);
       }()));
    }
    for (int i = l; (i <= p1); (i++)) {
      Code02_DynamicInversion1::add(arr[i][0], (-arr[i][2]));
    }
    for ((p1 = (m + 1)), (p2 = r); (p2 > m); (p2--)) {
      while ((((p1 - 1) >= l) && (arr[(p1 - 1)][1] > arr[p2][1]))) {
        (p1--);
        Code02_DynamicInversion1::add(arr[p1][0], arr[p1][2]);
      }
      (ans[arr[p2][3]] +=
       (arr[p2][2] * Code02_DynamicInversion1::query((arr[p2][0] - 1))));
    }
    for (int i = m; (i >= p1); (i--)) {
      Code02_DynamicInversion1::add(arr[i][0], (-arr[i][2]));
    }
    j::sort(arr, l, (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code02_DynamicInversion1::cdq(l, mid);
    Code02_DynamicInversion1::cdq((mid + 1), r);
    Code02_DynamicInversion1::merge(l, mid, r);
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (arr[(++cnt)][0] = num[i]);
      (arr[cnt][1] = i);
      (arr[cnt][2] = 1);
      (arr[cnt][3] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      (arr[(++cnt)][0] = del[i]);
      (arr[cnt][1] = pos[del[i]]);
      (arr[cnt][2] = (-1));
      (arr[cnt][3] = i);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (num[i] = in.nextInt());
      (pos[num[i]] = i);
    }
    for (int i = 1; (i <= m); (i++)) {
      (del[i] = in.nextInt());
    }
    Code02_DynamicInversion1::prepare();
    Code02_DynamicInversion1::cdq(1, cnt);
    for (int i = 1; (i < m); (i++)) {
      (ans[i] += ans[(i - 1)]);
    }
    for (int i = 0; (i < m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_DynamicInversion1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 动态逆序对，java版
// 给定一个长度为n的排列，1~n所有数字都出现一次
// 如果，前面的数 > 后面的数，那么这两个数就组成一个逆序对
// 给定一个长度为m的数组，表示依次删除的数字
// 打印每次删除数字前，排列中一共有多少逆序对，一共m条打印
// 1 <= n <= 10^5
// 1 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P3157
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // num : 原始序列依次的值
        // pos : 每个值在什么位置
        // del : 每一步删掉的值
        // 数值v、位置i、效果d、问题编号q
        // 树状数组
        // 每次逆序对的变化量
                // 从左到右统计左侧值大的数量
                // 清除树状数组
                // 从右到左统计右侧值小的数量
                // 清除树状数组
                // 直接排序
        // 整体按时序组织，cdq分治里根据下标重新排序
        // 读写工具类
*/
