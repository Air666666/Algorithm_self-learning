// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4475

// Source: src/class205/Code03_ChocolateKingdom1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_ChocolateKingdom1 {
  inline static int MAXN = 50001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
  inline static Array<i64> x = make_array<i64>(MAXN);
  inline static Array<i64> y = make_array<i64>(MAXN);
  inline static Array<i64> v = make_array<i64>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> xmin = make_array<i64>(MAXN);
  inline static Array<i64> xmax = make_array<i64>(MAXN);
  inline static Array<i64> ymin = make_array<i64>(MAXN);
  inline static Array<i64> ymax = make_array<i64>(MAXN);
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_ChocolateKingdom1() {}
  static int compareNode(int i, int j, int dimension) {
    i64 v1 = ((dimension == 0) ? x[i] : y[i]);
    i64 v2 = ((dimension == 0) ? x[j] : y[j]);
    return ((v1 == v2) ? 0 : ((v1 < v2) ? (-1) : 1));
  }
  static void swap(int i, int j) {
    int tmp = arr[i];
    (arr[i] = arr[j]);
    (arr[j] = tmp);
  }
  static void partition(int l, int r, int pidx, int dimension) {
    (first = l);
    (last = r);
    int i = l;
    while ((i <= last)) {
      int cmp = Code03_ChocolateKingdom1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code03_ChocolateKingdom1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code03_ChocolateKingdom1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code03_ChocolateKingdom1::partition(l, r, pidx, dimension);
      if ((i < first)) {
        (r = (first - 1));
      } else if ((i > last)) {
        (l = (last + 1));
      } else {
        break;
      }
    }
  }
  static void maintain(int i) {
    (sum[i] = ((v[i] + sum[ls[i]]) + sum[rs[i]]));
    (xmin[i] = jmin(x[i], jmin(xmin[ls[i]], xmin[rs[i]])));
    (xmax[i] = jmax(x[i], jmax(xmax[ls[i]], xmax[rs[i]])));
    (ymin[i] = jmin(y[i], jmin(ymin[ls[i]], ymin[rs[i]])));
    (ymax[i] = jmax(y[i], jmax(ymax[ls[i]], ymax[rs[i]])));
  }
  static int build(int l, int r, int dimension) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    Code03_ChocolateKingdom1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code03_ChocolateKingdom1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code03_ChocolateKingdom1::build((mid + 1), r, (dimension ^ 1)));
    Code03_ChocolateKingdom1::maintain(rt);
    return rt;
  }
  static i64 query(i64 a, i64 b, i64 c, int i) {
    if ((i == 0)) {
      return 0;
    }
    i64 ax1 = (xmin[i] * a);
    i64 ax2 = (xmax[i] * a);
    i64 by1 = (ymin[i] * b);
    i64 by2 = (ymax[i] * b);
    i64 minv = [&]() {
      auto jleft = jmin(ax1, ax2);
      auto jright = jmin(by1, by2);
      return (jleft + jright);
    }();
    i64 maxv = [&]() {
      auto jleft = jmax(ax1, ax2);
      auto jright = jmax(by1, by2);
      return (jleft + jright);
    }();
    if ((minv >= c)) {
      return 0;
    }
    if ((maxv < c)) {
      return sum[i];
    }
    i64 ans = 0;
    if ((((a * x[i]) + (b * y[i])) < c)) {
      (ans += v[i]);
    }
    (ans += Code03_ChocolateKingdom1::query(a, b, c, ls[i]));
    (ans += Code03_ChocolateKingdom1::query(a, b, c, rs[i]));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (x[i] = in.nextLong());
      (y[i] = in.nextLong());
      (v[i] = in.nextLong());
      (arr[i] = i);
    }
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    (root = Code03_ChocolateKingdom1::build(1, n, 0));
    i64 a = {};
    i64 b = {};
    i64 c = {};
    for (int i = 1; (i <= m); (i++)) {
      (a = in.nextLong());
      (b = in.nextLong());
      (c = in.nextLong());
      out.println(Code03_ChocolateKingdom1::query(a, b, c, root));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_ChocolateKingdom1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 巧克力王国，java版
// 一共n个点，每个点有坐标(x, y)，还有点权v
// 一共m条查询，格式 a b c，含义如下
// 满足 a * x + b * y < c 的所有点，打印点权累加和
// 1 <= n、m <= 5 * 10^4
// -10^9 <= a、b、x、y <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P4475
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 区域点权和
                // a、b、x、y，可能是正或者负，最值的可能性要考虑完整
        // 读写工具类
*/
