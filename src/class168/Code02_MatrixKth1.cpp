// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1527

// Source: src/class168/Code02_MatrixKth1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MatrixKth1 {
  inline static int MAXN = 501;
  inline static int MAXQ = 1000001;
  inline static int n = {};
  inline static int q = {};
  inline static Array<Array<int>> xyv = make_array<int>((MAXN * MAXN), 3);
  inline static int cntv = 0;
  inline static Array<int> qid = make_array<int>(MAXQ);
  inline static Array<int> a = make_array<int>(MAXQ);
  inline static Array<int> b = make_array<int>(MAXQ);
  inline static Array<int> c = make_array<int>(MAXQ);
  inline static Array<int> d = make_array<int>(MAXQ);
  inline static Array<int> k = make_array<int>(MAXQ);
  inline static Array<Array<int>> tree = make_array<int>(MAXN, MAXN);
  inline static Array<int> lset = make_array<int>(MAXQ);
  inline static Array<int> rset = make_array<int>(MAXQ);
  inline static Array<int> ans = make_array<int>(MAXQ);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MatrixKth1() {}
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int x, int y, int v) {
    for (int i = x; (i <= n); (i += Code02_MatrixKth1::lowbit(i))) {
      for (int j = y; (j <= n); (j += Code02_MatrixKth1::lowbit(j))) {
        (tree[i][j] += v);
      }
    }
  }
  static int sum(int x, int y) {
    int ret = 0;
    for (int i = x; (i > 0); (i -= Code02_MatrixKth1::lowbit(i))) {
      for (int j = y; (j > 0); (j -= Code02_MatrixKth1::lowbit(j))) {
        (ret += tree[i][j]);
      }
    }
    return ret;
  }
  static int query(int a, int b, int c, int d) {
    return [&]() {
      auto jleft = [&]() {
        auto jleft = [&]() {
          auto jleft = Code02_MatrixKth1::sum(c, d);
          auto jright = Code02_MatrixKth1::sum((a - 1), d);
          return (jleft - jright);
        }();
        auto jright = Code02_MatrixKth1::sum(c, (b - 1));
        return (jleft - jright);
      }();
      auto jright = Code02_MatrixKth1::sum((a - 1), (b - 1));
      return (jleft + jright);
    }();
  }
  static void compute(int ql, int qr, int vl, int vr) {
    if ((ql > qr)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = ql; (i <= qr); (i++)) {
        (ans[qid[i]] = xyv[vl][2]);
      }
    } else {
      int mid = jshr((vl + vr), 1);
      for (int i = vl; (i <= mid); (i++)) {
        Code02_MatrixKth1::add(xyv[i][0], xyv[i][1], 1);
      }
      int lsiz = 0;
      int rsiz = 0;
      for (int i = ql; (i <= qr); (i++)) {
        int id = qid[i];
        int satisfy = Code02_MatrixKth1::query(a[id], b[id], c[id], d[id]);
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
        Code02_MatrixKth1::add(xyv[i][0], xyv[i][1], (-1));
      }
      Code02_MatrixKth1::compute(ql, ((ql + lsiz) - 1), vl, mid);
      Code02_MatrixKth1::compute((ql + lsiz), qr, (mid + 1), vr);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      for (int j = 1; (j <= n); (j++)) {
        (xyv[(++cntv)][0] = i);
        (xyv[cntv][1] = j);
        (xyv[cntv][2] = in.nextInt());
      }
    }
    for (int i = 1; (i <= q); (i++)) {
      (qid[i] = i);
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      (c[i] = in.nextInt());
      (d[i] = in.nextInt());
      (k[i] = in.nextInt());
    }
    j::sort(xyv, 1, (cntv + 1),
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    Code02_MatrixKth1::compute(1, q, 1, cntv);
    for (int i = 1; (i <= q); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_MatrixKth1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 矩阵内第k小，第一种写法，java版
// 给定一个n * n的矩阵，接下来有q条查询，格式如下
// 查询 a b c d k : 左上角(a, b)，右下角(c, d)，打印该区域中第k小的数
// 1 <= n <= 500
// 1 <= q <= 6 * 10^4
// 0 <= 矩阵中的数字 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1527
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 矩阵中的每个数字，所在行x、所在列y、数值v
        // 矩阵中一共有多少个数字，cntv就是矩阵的规模
        // 查询任务的编号
        // 查询范围的左上角坐标
        // 查询范围的右下角坐标
        // 查询矩阵内第k小
        // 二维树状数组
        // 整体二分
        // 每条查询的答案
        // 二维空间中，(x,y)位置的词频加v
        // 二维空间中，左上角(1,1)到右下角(x,y)范围上的词频累加和
        // 二维空间中，左上角(a,b)到右下角(c,d)范围上的词频累加和
        // 读写工具类
*/
