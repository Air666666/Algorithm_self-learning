// Source: src/class206/Code01_ShootingGallery1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_ShootingGallery1 {
  inline static int MAXN = 100001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int m = {};
  inline static Array<Array<int>> target = make_array<int>(MAXN, 6);
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static int cntkdt = {};
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> alive = make_array<bool>(MAXN);
  inline static Array<int> aliveSiz = make_array<int>(MAXN);
  inline static Array<int> xmin = make_array<int>(MAXN);
  inline static Array<int> xmax = make_array<int>(MAXN);
  inline static Array<int> ymin = make_array<int>(MAXN);
  inline static Array<int> ymax = make_array<int>(MAXN);
  inline static Array<int> idmin = make_array<int>(MAXN);
  inline static double ALPHA = 0.7;
  inline static int top = {};
  inline static int topFather = {};
  inline static int topSide = {};
  inline static int topDimension = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int treeSiz = {};
  inline static int bullet = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_ShootingGallery1() {}
  static int init(int qx, int qy) {
    (cntkdt++);
    (x[cntkdt] = qx);
    (y[cntkdt] = qy);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (alive[cntkdt] = true);
    (aliveSiz[cntkdt] = 1);
    (xmin[cntkdt] = (xmax[cntkdt] = qx));
    (ymin[cntkdt] = (ymax[cntkdt] = qy));
    (idmin[cntkdt] = cntkdt);
    return cntkdt;
  }
  static void maintain(int i) {
    int l = ls[i];
    int r = rs[i];
    if (alive[i]) {
      (aliveSiz[i] = ((1 + aliveSiz[l]) + aliveSiz[r]));
      (xmin[i] = (xmax[i] = x[i]));
      (ymin[i] = (ymax[i] = y[i]));
      (idmin[i] = i);
    } else {
      (aliveSiz[i] = (aliveSiz[l] + aliveSiz[r]));
      (xmin[i] = (ymin[i] = INF));
      (xmax[i] = (ymax[i] = (-INF)));
      (idmin[i] = INF);
    }
    if ((aliveSiz[l] != 0)) {
      (xmin[i] = jmin(xmin[i], xmin[l]));
      (xmax[i] = jmax(xmax[i], xmax[l]));
      (ymin[i] = jmin(ymin[i], ymin[l]));
      (ymax[i] = jmax(ymax[i], ymax[l]));
      (idmin[i] = jmin(idmin[i], idmin[l]));
    }
    if ((aliveSiz[r] != 0)) {
      (xmin[i] = jmin(xmin[i], xmin[r]));
      (xmax[i] = jmax(xmax[i], xmax[r]));
      (ymin[i] = jmin(ymin[i], ymin[r]));
      (ymax[i] = jmax(ymax[i], ymax[r]));
      (idmin[i] = jmin(idmin[i], idmin[r]));
    }
  }
  static int compareNode(int i, int j, int dimension) {
    int v1 = ((dimension == 0) ? x[i] : y[i]);
    int v2 = ((dimension == 0) ? x[j] : y[j]);
    return ((v1 != v2) ? ((v1 < v2) ? (-1) : 1) : (i - j));
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
      int cmp = Code01_ShootingGallery1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code01_ShootingGallery1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code01_ShootingGallery1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int k, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code01_ShootingGallery1::partition(l, r, pidx, dimension);
      if ((k < first)) {
        (r = (first - 1));
      } else if ((k > last)) {
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
    Code01_ShootingGallery1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code01_ShootingGallery1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code01_ShootingGallery1::build((mid + 1), r, (dimension ^ 1)));
    Code01_ShootingGallery1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * aliveSiz[i]) >= jmax(aliveSiz[ls[i]], aliveSiz[rs[i]]));
  }
  static void dfs(int i) {
    if (((i != 0) && (aliveSiz[i] != 0))) {
      if (alive[i]) {
        (arr[(++treeSiz)] = i);
      }
      Code01_ShootingGallery1::dfs(ls[i]);
      Code01_ShootingGallery1::dfs(rs[i]);
    }
  }
  static void rebuild() {
    if ((top != 0)) {
      (treeSiz = 0);
      Code01_ShootingGallery1::dfs(top);
      int newRoot = Code01_ShootingGallery1::build(1, treeSiz, topDimension);
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
    if (((u == 0) || (aliveSiz[u] == 0))) {
      return insertNode;
    }
    if ((Code01_ShootingGallery1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] = Code01_ShootingGallery1::add(insertNode, ls[u], u, 1,
                                            (dimension ^ 1)));
    } else {
      (rs[u] = Code01_ShootingGallery1::add(insertNode, rs[u], u, 2,
                                            (dimension ^ 1)));
    }
    Code01_ShootingGallery1::maintain(u);
    if ((!Code01_ShootingGallery1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void add(int qx, int qy) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code01_ShootingGallery1::init(qx, qy);
    (root = Code01_ShootingGallery1::add(insertNode, root, 0, 0, 0));
    Code01_ShootingGallery1::rebuild();
  }
  static void remove(int removeNode, int u, int fa, int side, int dimension) {
    if ((u == removeNode)) {
      (alive[u] = false);
    } else if ((Code01_ShootingGallery1::compareNode(removeNode, u,
                                                     dimension) <= 0)) {
      Code01_ShootingGallery1::remove(removeNode, ls[u], u, 1, (dimension ^ 1));
    } else {
      Code01_ShootingGallery1::remove(removeNode, rs[u], u, 2, (dimension ^ 1));
    }
    Code01_ShootingGallery1::maintain(u);
    if ((!Code01_ShootingGallery1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
  }
  static void remove(int removeNode) {
    (top = (topFather = (topSide = (topDimension = 0))));
    Code01_ShootingGallery1::remove(removeNode, root, 0, 0, 0);
    Code01_ShootingGallery1::rebuild();
  }
  static void query(int ql, int qr, int qd, int qu, int i) {
    if ((((i == 0) || (aliveSiz[i] == 0)) || (idmin[i] >= bullet))) {
      return;
    }
    if (((((xmax[i] < ql) || (qr < xmin[i])) || (ymax[i] < qd)) ||
         (qu < ymin[i]))) {
      return;
    }
    if (((((ql <= xmin[i]) && (xmax[i] <= qr)) && (qd <= ymin[i])) &&
         (ymax[i] <= qu))) {
      (bullet = jmin(bullet, idmin[i]));
      return;
    }
    if (((((alive[i] && (ql <= x[i])) && (x[i] <= qr)) && (qd <= y[i])) &&
         (y[i] <= qu))) {
      (bullet = jmin(bullet, i));
    }
    int l = ls[i];
    int r = rs[i];
    if ((idmin[l] < idmin[r])) {
      Code01_ShootingGallery1::query(ql, qr, qd, qu, l);
      Code01_ShootingGallery1::query(ql, qr, qd, qu, r);
    } else {
      Code01_ShootingGallery1::query(ql, qr, qd, qu, r);
      Code01_ShootingGallery1::query(ql, qr, qd, qu, l);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (target[i][0] = in.nextInt());
      (target[i][1] = in.nextInt());
      (target[i][2] = in.nextInt());
      (target[i][3] = in.nextInt());
      (target[i][4] = in.nextInt());
      (target[i][5] = i);
    }
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    (idmin[0] = INF);
    (m = in.nextInt());
    {
      int i = 1;
      int qx = {};
      int qy = {};
      for (; (i <= m); (i++)) {
        (qx = in.nextInt());
        (qy = in.nextInt());
        Code01_ShootingGallery1::add(qx, qy);
      }
    }
    j::sort(target, 1, (n + 1),
            [=](Array<int> a, Array<int> b) { return (a[4] - b[4]); });
    for (int k = 1; (k <= n); (k++)) {
      (bullet = INF);
      Code01_ShootingGallery1::query(target[k][0], target[k][1], target[k][2],
                                     target[k][3], root);
      if ((bullet != INF)) {
        (ans[bullet] = target[k][5]);
        Code01_ShootingGallery1::remove(bullet);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_ShootingGallery1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 射击场，java版
// 每个靶子是一个矩形区域，x轴的范围[l, r]，y轴的范围[d, u]，还有z轴的数值
// 空间里有n个靶子，接下来有m发子弹，每发子弹给定出发时的x和y坐标，子弹沿z轴前进
//
子弹会击中前进过程中遇到的第一个尚未消失的靶子，随后击中的靶子和这发子弹都消失
// 对于每一发子弹，打印它击中的靶子编号，如果没有击中打印0
// 1 <= n、m <= 10^5
// 0 <= 坐标值 <= 10^7
// 测试链接 : https://www.luogu.com.cn/problem/CF44G
// 测试链接 : https://codeforces.com/problemset/problem/44/G
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // l、r、d、u、z、id
        // 子弹的K-D树
        // 节点是否存活
        // 子树的存活节点数量，平衡性只用aliveSiz判断
        // 区域内的子弹最小编号
        // 替罪羊树的重构
        // 答案的查询和收集
        // 先按照维度坐标比较，坐标相同时按kdt节点编号比较
        // 建树、插入、删除使用相同的比较规则
        // 即便发生重构，根据比较规则，删除时也能确定唯一的方向
        // 读写工具类
*/
