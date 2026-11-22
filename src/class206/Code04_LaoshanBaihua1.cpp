// 原题测试 / 参考链接（保留上游原始地址）
// https://loj.ac/p/6016
// https://www.luogu.com.cn/problem/P4848

// Source: src/class206/Code04_LaoshanBaihua1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LaoshanBaihua1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 3100001;
  inline static int MAXV = 1000000000;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int q = {};
  inline static int cntseg = {};
  inline static int cntkdt = {};
  inline static int rootseg = {};
  inline static Array<int> lseg = make_array<int>(MAXT);
  inline static Array<int> rseg = make_array<int>(MAXT);
  inline static Array<int> rootkdt = make_array<int>(MAXT);
  inline static Array<int> x = make_array<int>(MAXT);
  inline static Array<int> y = make_array<int>(MAXT);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static Array<int> xmin = make_array<int>(MAXT);
  inline static Array<int> xmax = make_array<int>(MAXT);
  inline static Array<int> ymin = make_array<int>(MAXT);
  inline static Array<int> ymax = make_array<int>(MAXT);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int topFather = {};
  inline static int topSide = {};
  inline static int topDimension = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int treeSiz = {};
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LaoshanBaihua1() {}
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
      int cmp = Code04_LaoshanBaihua1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code04_LaoshanBaihua1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code04_LaoshanBaihua1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code04_LaoshanBaihua1::partition(l, r, pidx, dimension);
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
    Code04_LaoshanBaihua1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code04_LaoshanBaihua1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code04_LaoshanBaihua1::build((mid + 1), r, (dimension ^ 1)));
    Code04_LaoshanBaihua1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * siz[i]) >= jmax(siz[ls[i]], siz[rs[i]]));
  }
  static void dfs(int i) {
    if ((i != 0)) {
      (arr[(++treeSiz)] = i);
      Code04_LaoshanBaihua1::dfs(ls[i]);
      Code04_LaoshanBaihua1::dfs(rs[i]);
    }
  }
  static void rebuild(int version) {
    if ((top != 0)) {
      (treeSiz = 0);
      Code04_LaoshanBaihua1::dfs(top);
      int newRoot = Code04_LaoshanBaihua1::build(1, treeSiz, topDimension);
      if ((topFather == 0)) {
        (rootkdt[version] = newRoot);
      } else if ((topSide == 1)) {
        (ls[topFather] = newRoot);
      } else {
        (rs[topFather] = newRoot);
      }
    }
  }
  static int addKdt(int insertNode, int u, int fa, int side, int dimension) {
    if ((u == 0)) {
      return insertNode;
    }
    if ((Code04_LaoshanBaihua1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] = Code04_LaoshanBaihua1::addKdt(insertNode, ls[u], u, 1,
                                             (dimension ^ 1)));
    } else {
      (rs[u] = Code04_LaoshanBaihua1::addKdt(insertNode, rs[u], u, 2,
                                             (dimension ^ 1)));
    }
    Code04_LaoshanBaihua1::maintain(u);
    if ((!Code04_LaoshanBaihua1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void addKdt(int version, int qx, int qy) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code04_LaoshanBaihua1::init(qx, qy);
    (rootkdt[version] =
         Code04_LaoshanBaihua1::addKdt(insertNode, rootkdt[version], 0, 0, 0));
    Code04_LaoshanBaihua1::rebuild(version);
  }
  static int add(int qx, int qy, int qv, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cntseg));
    }
    Code04_LaoshanBaihua1::addKdt(i, qx, qy);
    if ((l < r)) {
      int mid = jshr((l + r), 1);
      if ((qv <= mid)) {
        (lseg[i] = Code04_LaoshanBaihua1::add(qx, qy, qv, l, mid, lseg[i]));
      } else {
        (rseg[i] =
             Code04_LaoshanBaihua1::add(qx, qy, qv, (mid + 1), r, rseg[i]));
      }
    }
    return i;
  }
  static int queryCount(int a, int b, int c, int d, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((((xmax[i] < a) || (c < xmin[i])) || (ymax[i] < b)) ||
         (d < ymin[i]))) {
      return 0;
    }
    if (((((a <= xmin[i]) && (xmax[i] <= c)) && (b <= ymin[i])) &&
         (ymax[i] <= d))) {
      return siz[i];
    }
    int ans = 0;
    if (((((a <= x[i]) && (x[i] <= c)) && (b <= y[i])) && (y[i] <= d))) {
      (ans = 1);
    }
    (ans += Code04_LaoshanBaihua1::queryCount(a, b, c, d, ls[i]));
    (ans += Code04_LaoshanBaihua1::queryCount(a, b, c, d, rs[i]));
    return ans;
  }
  static int query(int a, int b, int c, int d, int k, int l, int r, int i) {
    if ((l == r)) {
      return l;
    }
    int mid = jshr((l + r), 1);
    int cnt = Code04_LaoshanBaihua1::queryCount(a, b, c, d, rootkdt[rseg[i]]);
    if ((cnt >= k)) {
      return Code04_LaoshanBaihua1::query(a, b, c, d, k, (mid + 1), r, rseg[i]);
    } else {
      return Code04_LaoshanBaihua1::query(a, b, c, d, (k - cnt), l, mid,
                                          lseg[i]);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (q = in.nextInt());
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    int op = {};
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    int v = {};
    int k = {};
    int lastAns = 0;
    for (int i = 1; (i <= q); (i++)) {
      (op = in.nextInt());
      if ((op == 1)) {
        (a = in.nextInt());
        (b = in.nextInt());
        (v = in.nextInt());
        (a ^= lastAns);
        (b ^= lastAns);
        (v ^= lastAns);
        (rootseg = Code04_LaoshanBaihua1::add(a, b, v, 1, MAXV, rootseg));
      } else {
        (a = in.nextInt());
        (b = in.nextInt());
        (c = in.nextInt());
        (d = in.nextInt());
        (k = in.nextInt());
        (a ^= lastAns);
        (b ^= lastAns);
        (c ^= lastAns);
        (d ^= lastAns);
        (k ^= lastAns);
        if ((Code04_LaoshanBaihua1::queryCount(a, b, c, d, rootkdt[rootseg]) >=
             k)) {
          (lastAns =
               Code04_LaoshanBaihua1::query(a, b, c, d, k, 1, MAXV, rootseg));
        } else {
          (lastAns = 0);
        }
        if ((lastAns == 0)) {
          out.println(String(u"NAIVE!ORZzyz."));
        } else {
          out.println(lastAns);
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
  Code04_LaoshanBaihua1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 崂山白花蛇草水，java版
// 网格空间n * n，一共有q条操作，类型如下
// 操作 1 a b v     : 坐标(a, b)，增加一个点，点权为v
// 操作 2 a b c d k : 查询(a, b)为左下角，(c, d)为右上角的矩形中，第k大的点权
// 如果点不够k个，打印 NAIVE!ORZzyz.
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 1 <= n <= 5 * 10^5
// 1 <= q <= 10^5
// 1 <= v <= 10^9
// 本题推荐loj的测试，洛谷的测试让该题变成了卡常竞赛，实在没必要
// 测试链接 : https://loj.ac/p/6016
// 测试链接 : https://www.luogu.com.cn/problem/P4848
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 权值线段树节点计数
        // K-D树的节点计数
        // 外层是权值线段树，开点的设计
        // 每个权值线段树的节点，背后是一棵动态kdt
        // 权值线段树上增加点
        // 查询一棵KDT中，矩形内有多少个点
        // 查询权值线段树中，矩形内第k大的点权，确定存在
        // 读写工具类
*/
