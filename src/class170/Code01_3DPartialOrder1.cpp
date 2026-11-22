// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3810

// Source: src/class170/Code01_3DPartialOrder1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_3DPartialOrder1 {
  inline static int MAXN = 100001;
  inline static int MAXK = 200001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 4);
  inline static Array<int> tree = make_array<int>(MAXK);
  inline static Array<int> f = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_3DPartialOrder1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= k)) {
      (tree[i] += v);
      (i += Code01_3DPartialOrder1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code01_3DPartialOrder1::lowbit(i));
    }
    return ret;
  }
  static void merge(int l, int m, int r) {
    int p1 = {};
    int p2 = {};
    for ((p1 = (l - 1)), (p2 = (m + 1)); (p2 <= r); (p2++)) {
      while ((((p1 + 1) <= m) && (arr[(p1 + 1)][2] <= arr[p2][2]))) {
        (p1++);
        Code01_3DPartialOrder1::add(arr[p1][3], 1);
      }
      (f[arr[p2][0]] += Code01_3DPartialOrder1::query(arr[p2][3]));
    }
    for (int i = l; (i <= p1); (i++)) {
      Code01_3DPartialOrder1::add(arr[i][3], (-1));
    }
    j::sort(arr, l, (r + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
  }
  static void cdq(int l, int r) {
    if ((l == r)) {
      return;
    }
    int mid = jdiv((l + r), 2);
    Code01_3DPartialOrder1::cdq(l, mid);
    Code01_3DPartialOrder1::cdq((mid + 1), r);
    Code01_3DPartialOrder1::merge(l, mid, r);
  }
  static void prepare() {
    j::sort(arr, 1, (n + 1), [=](Array<int> a, Array<int> b) {
      return ((a[1] != b[1])
                  ? (a[1] - b[1])
                  : ((a[2] != b[2]) ? (a[2] - b[2]) : (a[3] - b[3])));
    });
    {
      int l = 1;
      int r = 1;
      for (; (l <= n); (l = (++r))) {
        while ((((((r + 1) <= n) && (arr[l][1] == arr[(r + 1)][1])) &&
                 (arr[l][2] == arr[(r + 1)][2])) &&
                (arr[l][3] == arr[(r + 1)][3]))) {
          (r++);
        }
        for (int i = l; (i <= r); (i++)) {
          (f[arr[i][0]] = (r - i));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = in.nextInt());
      (arr[i][2] = in.nextInt());
      (arr[i][3] = in.nextInt());
    }
    Code01_3DPartialOrder1::prepare();
    Code01_3DPartialOrder1::cdq(1, n);
    for (int i = 1; (i <= n); (i++)) {
      (ans[f[i]]++);
    }
    for (int i = 0; (i < n); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_3DPartialOrder1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 三维偏序，java版
// 一共有n个对象，每个对象有a、b、c三个属性，每个属性值的范围都是[1, k]
// f(i)表示，aj <= ai 且 bj <= bi 且 cj <= ci 且 j != i 的j的数量
// ans(d)表示，f(i) == d 的i的数量
// 打印所有的ans[d]，d的范围[0, n)
// 1 <= n <= 10^5
// 1 <= k <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3810
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 对象的编号i、属性a、属性b、属性c
        // 树状数组，根据属性c的值增加词频，查询 <= 某个数的词频累加和
        // 每个对象的答案
        // 题目要求的ans[d]
                // 利用左、右各自b属性有序
                // 不回退的找，当前右组对象包括了几个左组的对象
                // 清空树状数组
                // 直接根据b属性排序，无需写经典的归并过程，课上重点解释了原因
        // 大顺序已经按a属性排序，cdq分治里按b属性重新排序
                // 根据a排序，a一样根据b排序，b一样根据c排序
                // 排序后a、b、c一样的同组内，组前的下标得不到同组后面的统计量
                // 所以把这部分的贡献，提前补偿给组前的下标，然后再跑CDQ分治
        // 读写工具类
*/
