// Source: src/class206/Code03_4DPartialOrder1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_4DPartialOrder1 {
  inline static int MAXN = 50001;
  inline static int MAXT = 500001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static Array<Array<int>> abcd = make_array<int>(MAXN, 4);
  inline static Array<Array<int>> bi = make_array<int>(MAXN, 2);
  inline static Array<int> ranking = make_array<int>(MAXN);
  inline static Array<int> c = make_array<int>(MAXT);
  inline static Array<int> d = make_array<int>(MAXT);
  inline static int cntkdt = {};
  inline static Array<int> rootkdt = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> siz = make_array<int>(MAXT);
  inline static Array<int> cmin = make_array<int>(MAXT);
  inline static Array<int> cmax = make_array<int>(MAXT);
  inline static Array<int> dmin = make_array<int>(MAXT);
  inline static Array<int> dmax = make_array<int>(MAXT);
  inline static Array<int> dp = make_array<int>(MAXT);
  inline static Array<int> maxdp = make_array<int>(MAXT);
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
  Code03_4DPartialOrder1() {}
  static int init(int qc, int qd, int qv) {
    (cntkdt++);
    (c[cntkdt] = qc);
    (d[cntkdt] = qd);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (siz[cntkdt] = 1);
    (cmin[cntkdt] = (cmax[cntkdt] = qc));
    (dmin[cntkdt] = (dmax[cntkdt] = qd));
    (dp[cntkdt] = (maxdp[cntkdt] = qv));
    return cntkdt;
  }
  static void maintain(int i) {
    (siz[i] = ((1 + siz[ls[i]]) + siz[rs[i]]));
    (cmin[i] = jmin(c[i], jmin(cmin[ls[i]], cmin[rs[i]])));
    (cmax[i] = jmax(c[i], jmax(cmax[ls[i]], cmax[rs[i]])));
    (dmin[i] = jmin(d[i], jmin(dmin[ls[i]], dmin[rs[i]])));
    (dmax[i] = jmax(d[i], jmax(dmax[ls[i]], dmax[rs[i]])));
    (maxdp[i] = jmax(dp[i], jmax(maxdp[ls[i]], maxdp[rs[i]])));
  }
  static int compareNode(int i, int j, int dimension) {
    int v1 = ((dimension == 0) ? c[i] : d[i]);
    int v2 = ((dimension == 0) ? c[j] : d[j]);
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
      int cmp = Code03_4DPartialOrder1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code03_4DPartialOrder1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code03_4DPartialOrder1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code03_4DPartialOrder1::partition(l, r, pidx, dimension);
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
    Code03_4DPartialOrder1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code03_4DPartialOrder1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code03_4DPartialOrder1::build((mid + 1), r, (dimension ^ 1)));
    Code03_4DPartialOrder1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * siz[i]) >= jmax(siz[ls[i]], siz[rs[i]]));
  }
  static void dfs(int i) {
    if ((i != 0)) {
      (arr[(++treeSiz)] = i);
      Code03_4DPartialOrder1::dfs(ls[i]);
      Code03_4DPartialOrder1::dfs(rs[i]);
    }
  }
  static void rebuild(int version) {
    if ((top != 0)) {
      (treeSiz = 0);
      Code03_4DPartialOrder1::dfs(top);
      int newRoot = Code03_4DPartialOrder1::build(1, treeSiz, topDimension);
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
    if ((Code03_4DPartialOrder1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] = Code03_4DPartialOrder1::addKdt(insertNode, ls[u], u, 1,
                                              (dimension ^ 1)));
    } else {
      (rs[u] = Code03_4DPartialOrder1::addKdt(insertNode, rs[u], u, 2,
                                              (dimension ^ 1)));
    }
    Code03_4DPartialOrder1::maintain(u);
    if ((!Code03_4DPartialOrder1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void addKdt(int version, int qx, int qy, int qv) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code03_4DPartialOrder1::init(qx, qy, qv);
    (rootkdt[version] =
         Code03_4DPartialOrder1::addKdt(insertNode, rootkdt[version], 0, 0, 0));
    Code03_4DPartialOrder1::rebuild(version);
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int rank, int qc, int qd, int qv) {
    for (int i = rank; (i <= n); (i += Code03_4DPartialOrder1::lowbit(i))) {
      Code03_4DPartialOrder1::addKdt(i, qc, qd, qv);
    }
  }
  static void updateAns(int qc, int qd, int i) {
    if ((i == 0)) {
      return;
    }
    if (((cmin[i] > qc) || (dmin[i] > qd))) {
      return;
    }
    if ((maxdp[i] <= queryAns)) {
      return;
    }
    if (((cmax[i] <= qc) && (dmax[i] <= qd))) {
      (queryAns = jmax(queryAns, maxdp[i]));
      return;
    }
    if (((c[i] <= qc) && (d[i] <= qd))) {
      (queryAns = jmax(queryAns, dp[i]));
    }
    Code03_4DPartialOrder1::updateAns(qc, qd, ls[i]);
    Code03_4DPartialOrder1::updateAns(qc, qd, rs[i]);
  }
  static int query(int rank, int qc, int qd) {
    (queryAns = 0);
    for (int i = rank; (i > 0); (i -= Code03_4DPartialOrder1::lowbit(i))) {
      Code03_4DPartialOrder1::updateAns(qc, qd, rootkdt[i]);
    }
    return queryAns;
  }
  static void prepare() {
    j::sort(abcd, 1, (n + 1), [=](Array<int> o1, Array<int> o2) {
      for (int i = 0; (i < 4); (i++)) {
        if ((o1[i] != o2[i])) {
          return (o1[i] - o2[i]);
        }
      }
      return 0;
    });
    for (int i = 1; (i <= n); (i++)) {
      (bi[i][0] = abcd[i][1]);
      (bi[i][1] = i);
    }
    j::sort(bi, 1, (n + 1), [=](Array<int> o1, Array<int> o2) {
      return ((o1[0] != o2[0]) ? (o1[0] - o2[0]) : (o1[1] - o2[1]));
    });
    for (int i = 1; (i <= n); (i++)) {
      (ranking[bi[i][1]] = i);
    }
    (cmin[0] = (dmin[0] = INF));
    (cmax[0] = (dmax[0] = (-INF)));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (abcd[i][0] = in.nextInt());
      (abcd[i][1] = in.nextInt());
      (abcd[i][2] = in.nextInt());
      (abcd[i][3] = in.nextInt());
    }
    Code03_4DPartialOrder1::prepare();
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      int cur =
          (Code03_4DPartialOrder1::query(ranking[i], abcd[i][2], abcd[i][3]) +
           1);
      (ans = jmax(ans, cur));
      Code03_4DPartialOrder1::add(ranking[i], abcd[i][2], abcd[i][3], cur);
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_4DPartialOrder1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 四维偏序最长链，java版
// 一共n个点，每个点有四维坐标(a, b, c, d)
// 可以任意选择点的排列顺序，每个点最多使用一次
// 点x的后面可以放置点y的条件为，x每个维度的坐标值 <= y对应维度的坐标值
// 希望选择的点尽量多，打印最多能选择几个点
// 1 <= n <= 5 * 10^4
// -10^9 <= 坐标值 <= +10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3769
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // b值、点的编号
        // (b值，点编号)的排名
        // K-D树维护c、d坐标
        // 每个树状数组的下标，背后是一棵动态kdt
        // 单点结尾时的最长偏序链的长度
        // 区域的最大dp值
        // 新增一个状态，b排名为rank，二维坐标为(qc, qd)，dp值为qv
        // 一棵KDT中查询，c坐标 <= qc，d坐标 <= qd，最大的dp值
        // 查询b排名 <= rank，c坐标 <= qc，d坐标 <= qd，最大的dp值
        // 读写工具类
*/
