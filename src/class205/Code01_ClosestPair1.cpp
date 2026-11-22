// Source: src/class205/Code01_ClosestPair1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ClosestPair1 {
  inline static int MAXN = 200001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static Array<i64> x = make_array<i64>(MAXN);
  inline static Array<i64> y = make_array<i64>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<i64> xmin = make_array<i64>(MAXN);
  inline static Array<i64> xmax = make_array<i64>(MAXN);
  inline static Array<i64> ymin = make_array<i64>(MAXN);
  inline static Array<i64> ymax = make_array<i64>(MAXN);
  inline static i64 ans = {};
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ClosestPair1() {}
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
      int cmp = Code01_ClosestPair1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code01_ClosestPair1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code01_ClosestPair1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code01_ClosestPair1::partition(l, r, pidx, dimension);
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
    (xmin[i] = jmin(x[i], jmin(xmin[ls[i]], xmin[rs[i]])));
    (xmax[i] = jmax(x[i], jmax(xmax[ls[i]], xmax[rs[i]])));
    (ymin[i] = jmin(y[i], jmin(ymin[ls[i]], ymin[rs[i]])));
    (ymax[i] = jmax(y[i], jmax(ymax[ls[i]], ymax[rs[i]])));
  }
  static int build1(int l, int r, int dimension) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    Code01_ClosestPair1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code01_ClosestPair1::build1(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code01_ClosestPair1::build1((mid + 1), r, (dimension ^ 1)));
    Code01_ClosestPair1::maintain(rt);
    return rt;
  }
  static double variance(int l, int r, int dimension) {
    double siz = ((r - l) + 1);
    double sum = 0;
    double avg = 0;
    double dif = 0;
    for (int i = l; (i <= r); (i++)) {
      (sum += ((dimension == 0) ? x[arr[i]] : y[arr[i]]));
    }
    (avg = jdiv(sum, siz));
    (sum = 0);
    for (int i = l; (i <= r); (i++)) {
      (dif = (((dimension == 0) ? x[arr[i]] : y[arr[i]]) - avg));
      (sum += (dif * dif));
    }
    return jdiv(sum, siz);
  }
  static int build2(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    int dimension = ([&]() {
      auto jleft = Code01_ClosestPair1::variance(l, r, 0);
      auto jright = Code01_ClosestPair1::variance(l, r, 1);
      return (jleft >= jright);
    }()
                         ? 0
                         : 1);
    Code01_ClosestPair1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code01_ClosestPair1::build2(l, (mid - 1)));
    (rs[rt] = Code01_ClosestPair1::build2((mid + 1), r));
    Code01_ClosestPair1::maintain(rt);
    return rt;
  }
  static i64 dist(int qi, int i) {
    i64 dx = (x[qi] - x[i]);
    i64 dy = (y[qi] - y[i]);
    return ((dx * dx) + (dy * dy));
  }
  static i64 guess(int qi, int i) {
    if ((i == 0)) {
      return INF;
    }
    i64 qx = x[qi];
    i64 qy = y[qi];
    i64 dx = ((qx < xmin[i]) ? (xmin[i] - qx)
                             : ((qx > xmax[i]) ? (qx - xmax[i]) : 0));
    i64 dy = ((qy < ymin[i]) ? (ymin[i] - qy)
                             : ((qy > ymax[i]) ? (qy - ymax[i]) : 0));
    return ((dx * dx) + (dy * dy));
  }
  static void updateAns(int qi, int i) {
    if ((i == 0)) {
      return;
    }
    if ((qi != i)) {
      (ans = jmin(ans, Code01_ClosestPair1::dist(qi, i)));
    }
    i64 gl = Code01_ClosestPair1::guess(qi, ls[i]);
    i64 gr = Code01_ClosestPair1::guess(qi, rs[i]);
    if ((gl < gr)) {
      if ((gl < ans)) {
        Code01_ClosestPair1::updateAns(qi, ls[i]);
      }
      if ((gr < ans)) {
        Code01_ClosestPair1::updateAns(qi, rs[i]);
      }
    } else {
      if ((gr < ans)) {
        Code01_ClosestPair1::updateAns(qi, rs[i]);
      }
      if ((gl < ans)) {
        Code01_ClosestPair1::updateAns(qi, ls[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (x[i] = in.nextLong());
      (y[i] = in.nextLong());
      (arr[i] = i);
    }
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    (root = Code01_ClosestPair1::build1(1, n, 0));
    (ans = Code01_ClosestPair1::dist(1, 2));
    for (int i = 1; (i <= n); (i++)) {
      Code01_ClosestPair1::updateAns(i, root);
      if ((ans == 0)) {
        break;
      }
    }
    out.printf(String(u"%.4f\n"), std::sqrt(ans));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ClosestPair1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 平面最近点对，java版
// 课上讲述K-D树的方法，但这不是正解，刻意设计测试是可以卡住的
// 本题复杂度正确的正解，是平面最近点对的分治算法，计算几何专题会讲述
// 一共n个点，每个点给定坐标(x, y)，输出最近两个点的距离，保留四位小数
// 2 <= n <= 2 * 10^5
// 0 <= x、y <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P1429
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解024，随机选择算法，无序数组中找到第k小的数，时间复杂度O(n)
        // 交替选维度
        // 返回dimension维度数据的方差
        // 方差选维度
        // 估计函数，估计查询点qi到i子树中所有点的最小距离平方
                // 不能算自己到自己的距离
                // root = build2(1, n);
        // 读写工具类
*/
