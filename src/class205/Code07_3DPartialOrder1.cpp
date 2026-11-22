// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3810

// Source: src/class205/Code07_3DPartialOrder1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_3DPartialOrder1 {
  inline static int MAXN = 100001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int k = {};
  inline static Array<Array<int>> abc = make_array<int>(MAXN, 3);
  inline static Array<int> b = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXN);
  inline static int cntkdt = {};
  inline static int root = {};
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> bmin = make_array<int>(MAXN);
  inline static Array<int> bmax = make_array<int>(MAXN);
  inline static Array<int> cmin = make_array<int>(MAXN);
  inline static Array<int> cmax = make_array<int>(MAXN);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int topFather = {};
  inline static int topSide = {};
  inline static int topDimension = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int treeSiz = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_3DPartialOrder1() {}
  static int init(int qb, int qc) {
    (cntkdt++);
    (b[cntkdt] = qb);
    (c[cntkdt] = qc);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (siz[cntkdt] = 1);
    (bmin[cntkdt] = (bmax[cntkdt] = qb));
    (cmin[cntkdt] = (cmax[cntkdt] = qc));
    return cntkdt;
  }
  static void maintain(int i) {
    (siz[i] = ((siz[ls[i]] + siz[rs[i]]) + 1));
    (bmin[i] = jmin(b[i], jmin(bmin[ls[i]], bmin[rs[i]])));
    (bmax[i] = jmax(b[i], jmax(bmax[ls[i]], bmax[rs[i]])));
    (cmin[i] = jmin(c[i], jmin(cmin[ls[i]], cmin[rs[i]])));
    (cmax[i] = jmax(c[i], jmax(cmax[ls[i]], cmax[rs[i]])));
  }
  static int compareNode(int i, int j, int dimension) {
    int v1 = ((dimension == 0) ? b[i] : c[i]);
    int v2 = ((dimension == 0) ? b[j] : c[j]);
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
      int cmp = Code07_3DPartialOrder1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code07_3DPartialOrder1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code07_3DPartialOrder1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code07_3DPartialOrder1::partition(l, r, pidx, dimension);
      if ((i < first)) {
        (r = (first - 1));
      } else if ((i > last)) {
        (l = (last + 1));
      } else {
        break;
      }
    }
  }
  static int build(int l, int r, int dimension) {
    if ((l > r)) {
      return 0;
    }
    int mid = jshr((l + r), 1);
    Code07_3DPartialOrder1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code07_3DPartialOrder1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code07_3DPartialOrder1::build((mid + 1), r, (dimension ^ 1)));
    Code07_3DPartialOrder1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * siz[i]) >= jmax(siz[ls[i]], siz[rs[i]]));
  }
  static void dfs(int i) {
    if ((i != 0)) {
      (arr[(++treeSiz)] = i);
      Code07_3DPartialOrder1::dfs(ls[i]);
      Code07_3DPartialOrder1::dfs(rs[i]);
    }
  }
  static void rebuild() {
    if ((top != 0)) {
      (treeSiz = 0);
      Code07_3DPartialOrder1::dfs(top);
      int newRoot = Code07_3DPartialOrder1::build(1, treeSiz, topDimension);
      if ((topFather == 0)) {
        (root = newRoot);
      } else if ((topSide == 1)) {
        (ls[topFather] = newRoot);
      } else {
        (rs[topFather] = newRoot);
      }
    }
  }
  static int add(int insertNode, int u, int fa, int side, int dimension) {
    if ((u == 0)) {
      return insertNode;
    }
    if ((Code07_3DPartialOrder1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] = Code07_3DPartialOrder1::add(insertNode, ls[u], u, 1,
                                           (dimension ^ 1)));
    } else {
      (rs[u] = Code07_3DPartialOrder1::add(insertNode, rs[u], u, 2,
                                           (dimension ^ 1)));
    }
    Code07_3DPartialOrder1::maintain(u);
    if ((!Code07_3DPartialOrder1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void add(int qx, int qy) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code07_3DPartialOrder1::init(qx, qy);
    (root = Code07_3DPartialOrder1::add(insertNode, root, 0, 0, 0));
    Code07_3DPartialOrder1::rebuild();
  }
  static int query(int qb, int qc, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((bmin[i] > qb) || (cmin[i] > qc))) {
      return 0;
    }
    if (((bmax[i] <= qb) && (cmax[i] <= qc))) {
      return siz[i];
    }
    int ans = 0;
    if (((b[i] <= qb) && (c[i] <= qc))) {
      (ans++);
    }
    (ans += Code07_3DPartialOrder1::query(qb, qc, ls[i]));
    (ans += Code07_3DPartialOrder1::query(qb, qc, rs[i]));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (k = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (abc[i][0] = in.nextInt());
      (abc[i][1] = in.nextInt());
      (abc[i][2] = in.nextInt());
    }
    j::sort(abc, 1, (n + 1),
            [=](Array<int> x, Array<int> y) { return (x[0] - y[0]); });
    (bmin[0] = (cmin[0] = INF));
    (bmax[0] = (cmax[0] = (-INF)));
    {
      int l = 1;
      int r = 1;
      for (; (l <= n); (l = (++r))) {
        while ((((r + 1) <= n) && (abc[(r + 1)][0] == abc[l][0]))) {
          (r++);
        }
        for (int i = l; (i <= r); (i++)) {
          Code07_3DPartialOrder1::add(abc[i][1], abc[i][2]);
        }
        for (int i = l; (i <= r); (i++)) {
          int fi =
              (Code07_3DPartialOrder1::query(abc[i][1], abc[i][2], root) - 1);
          (ans[fi]++);
        }
      }
    }
    for (int d = 0; (d < n); (d++)) {
      out.println(ans[d]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_3DPartialOrder1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 三维偏序，java版
// 本题就是讲解170，题目1，讲了CDQ分治的解法，这里用kdt的解法
// 一共有n个对象，每个对象有a、b、c三个属性，每个属性值的范围都是[1, k]
// f(i)表示，aj <= ai 且 bj <= bi 且 cj <= ci 且 j != i 的j的数量
// ans(d)表示，f(i) == d 的i的数量
// 打印所有的ans[d]，d的范围[0, n)
// 1 <= n <= 10^5
// 1 <= k <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P3810
// 提交以下的code，提交时请把类名改成"Main"，因为不是正解，java实现无法通过
// 想通过用C++实现，本节课Code07_3DPartialOrder2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // 查询 <= qb 并且 <= qc 点的数量
        // 读写工具类
*/
