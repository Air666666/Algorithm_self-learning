// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3834

// Source: src/class168/Code01_RangeKth1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_RangeKth1 {
  inline static int MAXN = 200001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> arr = make_array<int>(MAXN, 2);
  inline static Array<int> qid = make_array<int>(MAXN);
  inline static Array<int> l = make_array<int>(MAXN);
  inline static Array<int> r = make_array<int>(MAXN);
  inline static Array<int> k = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> lset = make_array<int>(MAXN);
  inline static Array<int> rset = make_array<int>(MAXN);
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_RangeKth1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code01_RangeKth1::lowbit(i));
    }
  }
  static int sum(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code01_RangeKth1::lowbit(i));
    }
    return ret;
  }
  static int query(int l, int r) {
    return [&]() {
      auto jleft = Code01_RangeKth1::sum(r);
      auto jright = Code01_RangeKth1::sum((l - 1));
      return (jleft - jright);
    }();
  }
  static void compute(int ql, int qr, int vl, int vr) {
    if ((ql > qr)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = ql; (i <= qr); (i++)) {
        (ans[qid[i]] = arr[vl][1]);
      }
    } else {
      int mid = jdiv((vl + vr), 2);
      for (int i = vl; (i <= mid); (i++)) {
        Code01_RangeKth1::add(arr[i][0], 1);
      }
      int lsiz = 0;
      int rsiz = 0;
      for (int i = ql; (i <= qr); (i++)) {
        int id = qid[i];
        int satisfy = Code01_RangeKth1::query(l[id], r[id]);
        if ((satisfy >= k[id])) {
          (lset[(++lsiz)] = id);
        } else {
          (k[id] -= satisfy);
          (rset[(++rsiz)] = id);
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (qid[((ql + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (qid[(((ql + lsiz) + i) - 1)] = rset[i]);
      }
      for (int i = vl; (i <= mid); (i++)) {
        Code01_RangeKth1::add(arr[i][0], (-1));
      }
      Code01_RangeKth1::compute(ql, ((ql + lsiz) - 1), vl, mid);
      Code01_RangeKth1::compute((ql + lsiz), qr, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i][0] = i);
      (arr[i][1] = in.nextInt());
    }
    for (int i = 1; (i <= m); (i++)) {
      (qid[i] = i);
      (l[i] = in.nextInt());
      (r[i] = in.nextInt());
      (k[i] = in.nextInt());
    }
    j::sort(arr, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[1] - b[1]); });
    Code01_RangeKth1::compute(1, m, 1, n);
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
  Code01_RangeKth1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 区间内第k小，第一种写法，java版
// 给定一个长度为n的数组，接下来有m条查询，格式如下
// 查询 l r k : 打印[l..r]范围内第k小的值
// 1 <= n、m <= 2 * 10^5
// 1 <= 数组中的数字 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3834
// 本题是讲解157，可持久化线段树模版题，现在作为整体二分的模版题
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 位置i，数值v
        // 查询
        // 树状数组
        // 整体二分
        // 查询的答案
        // 树状数组中的lowbit
        // 树状数组中增加i位置的词频
        // 树状数组中查询[1~i]范围的词频累加和
        // 树状数组中查询[l~r]范围的词频累加和
        // 整体二分的第一种写法
        // 问题范围[ql..qr]，答案范围[vl..vr]，答案范围的每个下标都是数字的排名
                        // 修改数据状况
                        // 检查每个问题并划分左右
                        // 撤回数据状况
                        // 左右两侧各自递归
        // 读写工具类
*/
