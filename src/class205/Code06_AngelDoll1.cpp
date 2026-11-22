// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P4169

// Source: src/class205/Code06_AngelDoll1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_AngelDoll1 {
  inline static int MAXN = 1000001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static int cntkdt = {};
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> xmin = make_array<int>(MAXN);
  inline static Array<int> xmax = make_array<int>(MAXN);
  inline static Array<int> ymin = make_array<int>(MAXN);
  inline static Array<int> ymax = make_array<int>(MAXN);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int topFather = {};
  inline static int topSide = {};
  inline static int topDimension = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int treeSiz = {};
  inline static int first = {};
  inline static int last = {};
  inline static int queryAns = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_AngelDoll1() {}
  static int init(int qx, int qy) {
    (cntkdt++);
    (x[cntkdt] = qx);
    (y[cntkdt] = qy);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (siz[cntkdt] = 1);
    (xmin[cntkdt] = (xmax[cntkdt] = qx));
    (ymin[cntkdt] = (ymax[cntkdt] = qy));
    return cntkdt;
  }
  static void maintain(int i) {
    (siz[i] = ((1 + siz[ls[i]]) + siz[rs[i]]));
    (xmin[i] = jmin(x[i], jmin(xmin[ls[i]], xmin[rs[i]])));
    (xmax[i] = jmax(x[i], jmax(xmax[ls[i]], xmax[rs[i]])));
    (ymin[i] = jmin(y[i], jmin(ymin[ls[i]], ymin[rs[i]])));
    (ymax[i] = jmax(y[i], jmax(ymax[ls[i]], ymax[rs[i]])));
  }
  static int compareNode(int i, int j, int dimension) {
    int v1 = ((dimension == 0) ? x[i] : y[i]);
    int v2 = ((dimension == 0) ? x[j] : y[j]);
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
      int cmp = Code06_AngelDoll1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code06_AngelDoll1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code06_AngelDoll1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code06_AngelDoll1::partition(l, r, pidx, dimension);
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
    Code06_AngelDoll1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code06_AngelDoll1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code06_AngelDoll1::build((mid + 1), r, (dimension ^ 1)));
    Code06_AngelDoll1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * siz[i]) >= jmax(siz[ls[i]], siz[rs[i]]));
  }
  static void dfs(int i) {
    if ((i != 0)) {
      (arr[(++treeSiz)] = i);
      Code06_AngelDoll1::dfs(ls[i]);
      Code06_AngelDoll1::dfs(rs[i]);
    }
  }
  static void rebuild() {
    if ((top != 0)) {
      (treeSiz = 0);
      Code06_AngelDoll1::dfs(top);
      int newRoot = Code06_AngelDoll1::build(1, treeSiz, topDimension);
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
    if ((Code06_AngelDoll1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] =
           Code06_AngelDoll1::add(insertNode, ls[u], u, 1, (dimension ^ 1)));
    } else {
      (rs[u] =
           Code06_AngelDoll1::add(insertNode, rs[u], u, 2, (dimension ^ 1)));
    }
    Code06_AngelDoll1::maintain(u);
    if ((!Code06_AngelDoll1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void add(int qx, int qy) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code06_AngelDoll1::init(qx, qy);
    (root = Code06_AngelDoll1::add(insertNode, root, 0, 0, 0));
    Code06_AngelDoll1::rebuild();
  }
  static int guess(int qx, int qy, int i) {
    if ((i == 0)) {
      return INF;
    }
    int ans = ((qx < xmin[i]) ? (xmin[i] - qx)
                              : ((qx > xmax[i]) ? (qx - xmax[i]) : 0));
    (ans +=
     ((qy < ymin[i]) ? (ymin[i] - qy) : ((qy > ymax[i]) ? (qy - ymax[i]) : 0)));
    return ans;
  }
  static void updateAns(int qx, int qy, int i) {
    if ((i == 0)) {
      return;
    }
    (queryAns = jmin(queryAns, [&]() {
       auto jleft = std::abs((qx - x[i]));
       auto jright = std::abs((qy - y[i]));
       return (jleft + jright);
     }()));
    int gl = Code06_AngelDoll1::guess(qx, qy, ls[i]);
    int gr = Code06_AngelDoll1::guess(qx, qy, rs[i]);
    if ((gl < gr)) {
      if ((gl < queryAns)) {
        Code06_AngelDoll1::updateAns(qx, qy, ls[i]);
      }
      if ((gr < queryAns)) {
        Code06_AngelDoll1::updateAns(qx, qy, rs[i]);
      }
    } else {
      if ((gr < queryAns)) {
        Code06_AngelDoll1::updateAns(qx, qy, rs[i]);
      }
      if ((gl < queryAns)) {
        Code06_AngelDoll1::updateAns(qx, qy, ls[i]);
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    {
      int i = 1;
      int qx = {};
      int qy = {};
      for (; (i <= n); (i++)) {
        (qx = in.nextInt());
        (qy = in.nextInt());
        Code06_AngelDoll1::add(qx, qy);
      }
    }
    {
      int i = 1;
      int op = {};
      int qx = {};
      int qy = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (qx = in.nextInt());
        (qy = in.nextInt());
        if ((op == 1)) {
          Code06_AngelDoll1::add(qx, qy);
        } else {
          (queryAns = INF);
          Code06_AngelDoll1::updateAns(qx, qy, root);
          out.println(queryAns);
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
  Code06_AngelDoll1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 天使玩偶，java版
// 本题就是讲解170，题目6，讲了CDQ分治的解法，这里用kdt的解法
// 规定(x1, y1)和(x2, y2)之间的距离 = | x1 - x2 | + | y1 - y2 |
// 一开始先给定n个点的位置，接下来有m条操作，每种操作是如下两种类型中的一种
// 操作 1 x y : 在(x, y)位置添加一个点
// 操作 2 x y : 打印已经添加的所有点中，距离(x, y)最近的点有多远
// 1 <= n、m <= 3 * 10^5
// 0 <= x、y <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P4169
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 估计查询点到i的掌管区域中，最小的曼哈顿距离
                // 单点的答案
        // 读写工具类
*/
