// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5494

// Source: src/class182/Code04_SegmentTreeSplit1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SegmentTreeSplit1 {
  inline static int MAXN = 200001;
  inline static int MAXT = (MAXN * 10);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static int version = {};
  inline static Array<int> pool = make_array<int>(MAXT);
  inline static int top = {};
  inline static int tree1 = {};
  inline static int tree2 = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SegmentTreeSplit1() {}
  static void prepare() {
    (top = 0);
    for (int i = 1; (i < MAXT); (i++)) {
      (pool[(++top)] = i);
    }
  }
  static int newNode() { return pool[(top--)]; }
  static void del(int i) {
    (pool[(++top)] = i);
    (ls[i] = 0);
    (rs[i] = 0);
    (sum[i] = 0);
  }
  static void up(int i) { (sum[i] = (sum[ls[i]] + sum[rs[i]])); }
  static int add(int jobi, int jobv, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = Code04_SegmentTreeSplit1::newNode());
    }
    if ((l == r)) {
      (sum[rt] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code04_SegmentTreeSplit1::add(jobi, jobv, l, mid, ls[rt]));
      } else {
        (rs[rt] =
             Code04_SegmentTreeSplit1::add(jobi, jobv, (mid + 1), r, rs[rt]));
      }
      Code04_SegmentTreeSplit1::up(rt);
    }
    return rt;
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans += Code04_SegmentTreeSplit1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ans += Code04_SegmentTreeSplit1::query(jobl, jobr, (mid + 1), r, rs[i]));
    }
    return ans;
  }
  static int kth(i64 jobk, int l, int r, int i) {
    if ((i == 0)) {
      return (-1);
    }
    if ((l == r)) {
      return l;
    }
    int mid = jshr((l + r), 1);
    if ((sum[ls[i]] >= jobk)) {
      return Code04_SegmentTreeSplit1::kth(jobk, l, mid, ls[i]);
    } else {
      return Code04_SegmentTreeSplit1::kth((jobk - sum[ls[i]]), (mid + 1), r,
                                           rs[i]);
    }
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (sum[t1] += sum[t2]);
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code04_SegmentTreeSplit1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code04_SegmentTreeSplit1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code04_SegmentTreeSplit1::up(t1);
    }
    Code04_SegmentTreeSplit1::del(t2);
    return t1;
  }
  static void split(int jobl, int jobr, int l, int r, int t1) {
    if ((t1 == 0)) {
      (tree1 = t1);
      (tree2 = 0);
      return;
    }
    if (((jobl <= l) && (r <= jobr))) {
      (tree1 = 0);
      (tree2 = t1);
      return;
    }
    int t2 = Code04_SegmentTreeSplit1::newNode();
    int mid = jshr((l + r), 1);
    if ((jobl <= mid)) {
      Code04_SegmentTreeSplit1::split(jobl, jobr, l, mid, ls[t1]);
      (ls[t1] = tree1);
      (ls[t2] = tree2);
    }
    if ((jobr > mid)) {
      Code04_SegmentTreeSplit1::split(jobl, jobr, (mid + 1), r, rs[t1]);
      (rs[t1] = tree1);
      (rs[t2] = tree2);
    }
    Code04_SegmentTreeSplit1::up(t1);
    Code04_SegmentTreeSplit1::up(t2);
    (tree1 = t1);
    (tree2 = t2);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    Code04_SegmentTreeSplit1::prepare();
    (n = in.nextInt());
    (m = in.nextInt());
    (version = 1);
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        (x = in.nextInt());
        (root[version] = Code04_SegmentTreeSplit1::add(i, x, 1, n, root[1]));
      }
    }
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      int z = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        if ((op == 0)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          Code04_SegmentTreeSplit1::split(y, z, 1, n, root[x]);
          (root[x] = tree1);
          (root[(++version)] = tree2);
        } else if ((op == 1)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (root[x] = Code04_SegmentTreeSplit1::merge(1, n, root[x], root[y]));
        } else if ((op == 2)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          (root[x] = Code04_SegmentTreeSplit1::add(z, y, 1, n, root[x]));
        } else if ((op == 3)) {
          (x = in.nextInt());
          (y = in.nextInt());
          (z = in.nextInt());
          out.println(Code04_SegmentTreeSplit1::query(y, z, 1, n, root[x]));
        } else {
          (x = in.nextInt());
          (y = in.nextInt());
          out.println(Code04_SegmentTreeSplit1::kth(y, 1, n, root[x]));
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SegmentTreeSplit1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 线段树分裂，java版
//
数字范围1~n，给定每种数字的个数，建立编号为1的可重集合，以后新集合的编号自增即可
// 接下来有m条操作，每条操作是如下五种类型中的一种
// 操作 0 x y z : x号集合中，取出[y, z]范围上的所有数字，生成新的集合
// 操作 1 x y   : x号集合与y号集合合并，以后y编号的集合不会使用了
// 操作 2 x y z : x号集合中，加入y个数字z
// 操作 3 x y z : x号集合中，查询[y, z]范围上的数字个数
// 操作 4 x y   : x号集合中，查询第y小的数字，不存在打印-1
// 1 <= 所有数据 <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5494
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
