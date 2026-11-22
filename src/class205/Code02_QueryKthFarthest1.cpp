// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2093

// Source: src/class205/Code02_QueryKthFarthest1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_QueryKthFarthest1 {
  inline static int MAXN = 100001;
  inline static i64 INF = jshl(1LL, 60);
  inline static int n = {};
  inline static int m = {};
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
  inline static JHeap<Array<i64>> heap =
      JHeap<Array<i64>>([](Array<i64> a, Array<i64> b) {
        return ((a[0] != b[0]) ? jcompare(a[0], b[0]) : jcompare(b[1], a[1]));
      });
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_QueryKthFarthest1() {}
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
      int cmp = Code02_QueryKthFarthest1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code02_QueryKthFarthest1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code02_QueryKthFarthest1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code02_QueryKthFarthest1::partition(l, r, pidx, dimension);
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
  static int build(int l, int r, int dimension) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    Code02_QueryKthFarthest1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code02_QueryKthFarthest1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code02_QueryKthFarthest1::build((mid + 1), r, (dimension ^ 1)));
    Code02_QueryKthFarthest1::maintain(rt);
    return rt;
  }
  static i64 dist(i64 x1, i64 y1, i64 x2, i64 y2) {
    i64 dx = (x1 - x2);
    i64 dy = (y1 - y2);
    return ((dx * dx) + (dy * dy));
  }
  static i64 guess(int qx, int qy, int i) {
    if ((i == 0)) {
      return 0;
    }
    i64 dx = [&]() {
      auto jargument_0 = std::abs((qx - xmin[i]));
      auto jargument_1 = std::abs((qx - xmax[i]));
      return jmax(jargument_0, jargument_1);
    }();
    i64 dy = [&]() {
      auto jargument_0 = std::abs((qy - ymin[i]));
      auto jargument_1 = std::abs((qy - ymax[i]));
      return jmax(jargument_0, jargument_1);
    }();
    return ((dx * dx) + (dy * dy));
  }
  static void updateAns(int qx, int qy, int qk, int i) {
    if ((i == 0)) {
      return;
    }
    heap.add(Array<i64>{Code02_QueryKthFarthest1::dist(qx, qy, x[i], y[i]), i});
    if ((heap.size() > qk)) {
      heap.poll();
    }
    i64 gl = Code02_QueryKthFarthest1::guess(qx, qy, ls[i]);
    i64 gr = Code02_QueryKthFarthest1::guess(qx, qy, rs[i]);
    if ((gl > gr)) {
      if (((heap.size() < qk) || (gl >= heap.peek()[0]))) {
        Code02_QueryKthFarthest1::updateAns(qx, qy, qk, ls[i]);
      }
      if (((heap.size() < qk) || (gr >= heap.peek()[0]))) {
        Code02_QueryKthFarthest1::updateAns(qx, qy, qk, rs[i]);
      }
    } else {
      if (((heap.size() < qk) || (gr >= heap.peek()[0]))) {
        Code02_QueryKthFarthest1::updateAns(qx, qy, qk, rs[i]);
      }
      if (((heap.size() < qk) || (gl >= heap.peek()[0]))) {
        Code02_QueryKthFarthest1::updateAns(qx, qy, qk, ls[i]);
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
    (root = Code02_QueryKthFarthest1::build(1, n, 0));
    (m = in.nextInt());
    {
      int i = 1;
      int qx = {};
      int qy = {};
      int qk = {};
      for (; (i <= m); (i++)) {
        (qx = in.nextInt());
        (qy = in.nextInt());
        (qk = in.nextInt());
        heap.clear();
        Code02_QueryKthFarthest1::updateAns(qx, qy, qk, root);
        out.println(heap.peek()[1]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_QueryKthFarthest1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 查询第k远的点，java版
// 一共n个点，编号1~n，每个点给定坐标(x, y)
// 一共m条查询，格式 qx qy qk，查询距离(qx, qy)第qk远的点，打印该点的编号
// 如果多个点到(qx, qy)的距离相同，那么编号较小的点认为距离更远
// 1 <= n <= 10^5
// 1 <= m <= 10^4
// 1 <= qk <= 20
// -10^9 <= 坐标值 <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P2093
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 堆中数据 = (距离、点的编号)
        // 距离一样时，题目规定点的编号越小越远
        // 所以小根堆先看距离，距离小的点先淘汰，距离一样，编号大的点先淘汰
        // 估计函数，估计查询点到i子树中所有点的最大距离平方
                        // 注意判断必须是 >=
                        // 因为距离相同，依然可能存在编号更小的点
        // 读写工具类
*/
