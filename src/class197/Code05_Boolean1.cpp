// Source: src/class197/Code05_Boolean1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Boolean1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 600001;
  inline static int MAXQ = 1000001;
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> error = make_array<int>(MAXM);
  inline static Array<int> u = make_array<int>(MAXM);
  inline static Array<int> v = make_array<int>(MAXM);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = {};
  inline static Array<int> first = make_array<int>(MAXM);
  inline static Array<Array<int>> st = make_array<int>((MAXM + 1), MAXP);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Boolean1() {}
  static int find(int i) {
    while ((i != fa[i])) {
      (i = fa[i]);
    }
    return i;
  }
  static void union_method(int x, int y) {
    int fx = Code05_Boolean1::find(x);
    int fy = Code05_Boolean1::find(y);
    if ((fx != fy)) {
      if ((siz[fx] < siz[fy])) {
        int tmp = fx;
        (fx = fy);
        (fy = tmp);
      }
      (fa[fy] = fx);
      (siz[fx] += siz[fy]);
      (rollback[(++opsize)][0] = fx);
      (rollback[opsize][1] = fy);
    }
  }
  static void undo(int oldsiz) {
    while ((opsize > oldsiz)) {
      int fx = rollback[opsize][0];
      int fy = rollback[(opsize--)][1];
      (fa[fy] = fy);
      (siz[fx] -= siz[fy]);
    }
  }
  static int other(int x) { return ((x <= n) ? (x + n) : (x - n)); }
  static bool conflict(int x) {
    return [&]() {
      auto jleft = Code05_Boolean1::find(x);
      auto jright = Code05_Boolean1::find(Code05_Boolean1::other(x));
      return (jleft == jright);
    }();
  }
  static void compute(int ql, int qr, int vl, int vr) {
    if ((ql > qr)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = ql; (i <= qr); (i++)) {
        (first[i] = vl);
      }
      return;
    }
    int mid = jshr((vl + vr), 1);
    int backup1 = opsize;
    bool bad = false;
    for (int i = jmax((qr + 1), vl); (i <= mid); (i++)) {
      Code05_Boolean1::union_method(u[i], v[i]);
      [&]() {
        auto jargument_0 = Code05_Boolean1::other(u[i]);
        auto jargument_1 = Code05_Boolean1::other(v[i]);
        return Code05_Boolean1::union_method(jargument_0, jargument_1);
      }();
      if (Code05_Boolean1::conflict(u[i])) {
        (bad = true);
        break;
      }
    }
    if (bad) {
      Code05_Boolean1::undo(backup1);
      Code05_Boolean1::compute(ql, qr, vl, mid);
    } else {
      int backup2 = opsize;
      int split = jmin(qr, mid);
      for (; (split >= ql); (split--)) {
        Code05_Boolean1::union_method(u[split], v[split]);
        [&]() {
          auto jargument_0 = Code05_Boolean1::other(u[split]);
          auto jargument_1 = Code05_Boolean1::other(v[split]);
          return Code05_Boolean1::union_method(jargument_0, jargument_1);
        }();
        if (Code05_Boolean1::conflict(u[split])) {
          break;
        }
      }
      Code05_Boolean1::undo(backup2);
      Code05_Boolean1::compute((split + 1), qr, (mid + 1), vr);
      Code05_Boolean1::undo(backup1);
      for (int i = (split + 1); ((i <= qr) && (i < vl)); (i++)) {
        Code05_Boolean1::union_method(u[i], v[i]);
        [&]() {
          auto jargument_0 = Code05_Boolean1::other(u[i]);
          auto jargument_1 = Code05_Boolean1::other(v[i]);
          return Code05_Boolean1::union_method(jargument_0, jargument_1);
        }();
      }
      Code05_Boolean1::compute(ql, split, vl, mid);
    }
  }
  static void buildst() {
    (opsize = 0);
    for (int i = 1; (i <= jshl(n, 1)); (i++)) {
      (fa[i] = i);
      (siz[i] = 1);
    }
    Code05_Boolean1::compute(1, m, 1, (m + 1));
    for (int p = 0; (p < MAXP); (p++)) {
      (st[(m + 1)][p] = (m + 1));
    }
    for (int i = m; (i >= 1); (i--)) {
      (st[i][0] = first[i]);
      for (int p = 1; (p < MAXP); (p++)) {
        (st[i][p] = st[st[i][(p - 1)]][(p - 1)]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (u[i] = in.nextInt());
        (x = in.nextInt());
        (v[i] = in.nextInt());
        (y = in.nextInt());
        (error[i] = (((u[i] == v[i]) && (x != y)) ? 1 : 0));
        (u[i] = ((x == 0) ? u[i] : (u[i] + n)));
        (v[i] = ((y == 0) ? v[i] : (v[i] + n)));
      }
    }
    Code05_Boolean1::buildst();
    for (int i = 1; (i <= m); (i++)) {
      (error[i] += error[(i - 1)]);
    }
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= q); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        if (((error[r] - error[(l - 1)]) > 0)) {
          out.println((-1));
        } else {
          int ans = 0;
          for (int p = (MAXP - 1); (p >= 0); (p--)) {
            if ((st[l][p] <= r)) {
              (l = st[l][p]);
              (ans += jshl(1, p));
            }
          }
          (ans++);
          out.println(ans);
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
  Code05_Boolean1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 布尔，java版
// 一共n个变量，取值为0或1，一共m条限制，格式 u x v y，含义如下
// 如果u的取值为x，则v的取值为y，同时如果v的取值为y，则u的取值为x
// 限制的编号范围1~m，限制区间[a, b]如果满足如下条件，就认为是合法的
// 区间[a, b]内的所有限制，存在一种变量赋值方案，能让它们全部成立
// 一共有q条查询，格式 l r，含义如下
// 整个限制区间[l, r]，最少划分成多少段连续区间，使得每个连续区间都合法
// 打印划分的连续区间数量，如果怎么划分都做不到上述要求，打印-1
// 1 <= n <= 10^5
// 1 <= m <= 6 * 10^5
// 1 <= q <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P7843
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 错误计数
        // 决定编号
        // 可撤销并查集
        // first[i] = 从i位置开始，向右不停添加限制，首次违规的位置
        // st[i][p] =
从i位置开始，允许拆成2的p次个连续区间，每个都合法，往右能到什么位置
        // 整体二分，计算每个位置i的first[i]信息
        // 读写工具类
*/
