// Source: src/class206/Code02_CameraRelocationAndQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CameraRelocationAndQueries1 {
  inline static int MAXN = 200001;
  inline static double INF = 1e100;
  inline static double EPS = 1e-8;
  inline static int n = {};
  inline static int m = {};
  inline static double a = {};
  inline static double b = {};
  inline static double lastAns = {};
  inline static Array<double> x = make_array<double>(MAXN);
  inline static Array<double> y = make_array<double>(MAXN);
  inline static Array<double> z = make_array<double>(MAXN);
  inline static Array<int> kdtToCamera = make_array<int>(MAXN);
  inline static Array<int> cameraToKdt = make_array<int>(MAXN);
  inline static int cntkdt = {};
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> alive = make_array<bool>(MAXN);
  inline static Array<int> aliveSiz = make_array<int>(MAXN);
  inline static Array<double> xmin = make_array<double>(MAXN);
  inline static Array<double> xmax = make_array<double>(MAXN);
  inline static Array<double> ymin = make_array<double>(MAXN);
  inline static Array<double> ymax = make_array<double>(MAXN);
  inline static Array<double> zmin = make_array<double>(MAXN);
  inline static Array<double> zmax = make_array<double>(MAXN);
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
  Code02_CameraRelocationAndQueries1() {}
  static int init(double qx, double qy, double qz, int camera) {
    (cntkdt++);
    (x[cntkdt] = qx);
    (y[cntkdt] = qy);
    (z[cntkdt] = qz);
    (kdtToCamera[cntkdt] = camera);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (alive[cntkdt] = true);
    (aliveSiz[cntkdt] = 1);
    (xmin[cntkdt] = (xmax[cntkdt] = qx));
    (ymin[cntkdt] = (ymax[cntkdt] = qy));
    (zmin[cntkdt] = (zmax[cntkdt] = qz));
    return cntkdt;
  }
  static void maintain(int i) {
    int l = ls[i];
    int r = rs[i];
    if (alive[i]) {
      (aliveSiz[i] = ((1 + aliveSiz[l]) + aliveSiz[r]));
      (xmin[i] = (xmax[i] = x[i]));
      (ymin[i] = (ymax[i] = y[i]));
      (zmin[i] = (zmax[i] = z[i]));
    } else {
      (aliveSiz[i] = (aliveSiz[l] + aliveSiz[r]));
      (xmin[i] = (ymin[i] = (zmin[i] = INF)));
      (xmax[i] = (ymax[i] = (zmax[i] = (-INF))));
    }
    if ((aliveSiz[l] != 0)) {
      (xmin[i] = jmin(xmin[i], xmin[l]));
      (xmax[i] = jmax(xmax[i], xmax[l]));
      (ymin[i] = jmin(ymin[i], ymin[l]));
      (ymax[i] = jmax(ymax[i], ymax[l]));
      (zmin[i] = jmin(zmin[i], zmin[l]));
      (zmax[i] = jmax(zmax[i], zmax[l]));
    }
    if ((aliveSiz[r] != 0)) {
      (xmin[i] = jmin(xmin[i], xmin[r]));
      (xmax[i] = jmax(xmax[i], xmax[r]));
      (ymin[i] = jmin(ymin[i], ymin[r]));
      (ymax[i] = jmax(ymax[i], ymax[r]));
      (zmin[i] = jmin(zmin[i], zmin[r]));
      (zmax[i] = jmax(zmax[i], zmax[r]));
    }
  }
  static int compareNode(int i, int j, int dimension) {
    double v1 = ((dimension == 0) ? x[i] : ((dimension == 1) ? y[i] : z[i]));
    double v2 = ((dimension == 0) ? x[j] : ((dimension == 1) ? y[j] : z[j]));
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
      int cmp = Code02_CameraRelocationAndQueries1::compareNode(arr[i], pidx,
                                                                dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code02_CameraRelocationAndQueries1::swap(jargument_0,
                                                          jargument_1);
        }();
      } else {
        Code02_CameraRelocationAndQueries1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int k, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code02_CameraRelocationAndQueries1::partition(l, r, pidx, dimension);
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
    Code02_CameraRelocationAndQueries1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code02_CameraRelocationAndQueries1::build(
         l, (mid - 1), jrem((dimension + 1), 3)));
    (rs[rt] = Code02_CameraRelocationAndQueries1::build(
         (mid + 1), r, jrem((dimension + 1), 3)));
    Code02_CameraRelocationAndQueries1::maintain(rt);
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
      Code02_CameraRelocationAndQueries1::dfs(ls[i]);
      Code02_CameraRelocationAndQueries1::dfs(rs[i]);
    }
  }
  static void rebuild() {
    if ((top != 0)) {
      (treeSiz = 0);
      Code02_CameraRelocationAndQueries1::dfs(top);
      int newRoot =
          Code02_CameraRelocationAndQueries1::build(1, treeSiz, topDimension);
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
    if ((Code02_CameraRelocationAndQueries1::compareNode(insertNode, u,
                                                         dimension) <= 0)) {
      (ls[u] = Code02_CameraRelocationAndQueries1::add(
           insertNode, ls[u], u, 1, jrem((dimension + 1), 3)));
    } else {
      (rs[u] = Code02_CameraRelocationAndQueries1::add(
           insertNode, rs[u], u, 2, jrem((dimension + 1), 3)));
    }
    Code02_CameraRelocationAndQueries1::maintain(u);
    if ((!Code02_CameraRelocationAndQueries1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void add(double qx, double qy, double qz, int camera) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode =
        Code02_CameraRelocationAndQueries1::init(qx, qy, qz, camera);
    (cameraToKdt[camera] = insertNode);
    (root = Code02_CameraRelocationAndQueries1::add(insertNode, root, 0, 0, 0));
    Code02_CameraRelocationAndQueries1::rebuild();
  }
  static void remove(int removeNode, int u, int fa, int side, int dimension) {
    if ((u == removeNode)) {
      (alive[u] = false);
    } else if ((Code02_CameraRelocationAndQueries1::compareNode(
                    removeNode, u, dimension) <= 0)) {
      Code02_CameraRelocationAndQueries1::remove(removeNode, ls[u], u, 1,
                                                 jrem((dimension + 1), 3));
    } else {
      Code02_CameraRelocationAndQueries1::remove(removeNode, rs[u], u, 2,
                                                 jrem((dimension + 1), 3));
    }
    Code02_CameraRelocationAndQueries1::maintain(u);
    if ((!Code02_CameraRelocationAndQueries1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
  }
  static void remove(int removeNode) {
    (top = (topFather = (topSide = (topDimension = 0))));
    Code02_CameraRelocationAndQueries1::remove(removeNode, root, 0, 0, 0);
    Code02_CameraRelocationAndQueries1::rebuild();
  }
  static double mindist(double qx, double qy, double qz, int i) {
    double xd = ((qx < xmin[i]) ? (xmin[i] - qx)
                                : ((qx > xmax[i]) ? (qx - xmax[i]) : 0));
    double yd = ((qy < ymin[i]) ? (ymin[i] - qy)
                                : ((qy > ymax[i]) ? (qy - ymax[i]) : 0));
    double zd = ((qz < zmin[i]) ? (zmin[i] - qz)
                                : ((qz > zmax[i]) ? (qz - zmax[i]) : 0));
    return (((xd * xd) + (yd * yd)) + (zd * zd));
  }
  static double maxdist(double qx, double qy, double qz, int i) {
    double xd2 = jmax(((qx - xmin[i]) * (qx - xmin[i])),
                      ((qx - xmax[i]) * (qx - xmax[i])));
    double yd2 = jmax(((qy - ymin[i]) * (qy - ymin[i])),
                      ((qy - ymax[i]) * (qy - ymax[i])));
    double zd2 = jmax(((qz - zmin[i]) * (qz - zmin[i])),
                      ((qz - zmax[i]) * (qz - zmax[i])));
    return ((xd2 + yd2) + zd2);
  }
  static double dist(double qx, double qy, double qz, int i) {
    double xd = (qx - x[i]);
    double yd = (qy - y[i]);
    double zd = (qz - z[i]);
    return (((xd * xd) + (yd * yd)) + (zd * zd));
  }
  static int query(double qx, double qy, double qz, double low, double high,
                   int i) {
    if (((i == 0) || (aliveSiz[i] == 0))) {
      return 0;
    }
    if (((Code02_CameraRelocationAndQueries1::mindist(qx, qy, qz, i) > high) ||
         (Code02_CameraRelocationAndQueries1::maxdist(qx, qy, qz, i) < low))) {
      return 0;
    }
    if (alive[i]) {
      double d = Code02_CameraRelocationAndQueries1::dist(qx, qy, qz, i);
      if (((low <= d) && (d <= high))) {
        return kdtToCamera[i];
      }
    }
    int ans =
        Code02_CameraRelocationAndQueries1::query(qx, qy, qz, low, high, ls[i]);
    if ((ans != 0)) {
      return ans;
    }
    return Code02_CameraRelocationAndQueries1::query(qx, qy, qz, low, high,
                                                     rs[i]);
  }
  static int query(double qx, double qy, double qz, double qr) {
    double low = jmax(0, (qr - EPS));
    double high = (qr + EPS);
    (low = (low * low));
    (high = (high * high));
    return Code02_CameraRelocationAndQueries1::query(qx, qy, qz, low, high,
                                                     root);
  }
  static double decode(double encrypt, double l, double r) {
    (l = ((lastAns * l) + 1));
    (r = ((lastAns * r) + 1));
    for (int i = 1; (i <= 60); (i++)) {
      double mid = jdiv((l + r), 2);
      double fx = ((a * mid) - (b * std::sin(mid)));
      if ((fx <= encrypt)) {
        (l = mid);
      } else {
        (r = mid);
      }
    }
    return jdiv((l - 1), lastAns);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (a = in.nextDouble());
    (b = in.nextDouble());
    (lastAns = 0.1);
    (xmin[0] = (ymin[0] = (zmin[0] = INF)));
    (xmax[0] = (ymax[0] = (zmax[0] = (-INF))));
    double qx = {};
    double qy = {};
    double qz = {};
    double qr = {};
    double qid = {};
    int op = {};
    int camera = {};
    int kdtNode = {};
    int curAns = {};
    for (int i = 1; (i <= n); (i++)) {
      (qx = in.nextDouble());
      (qy = in.nextDouble());
      (qz = in.nextDouble());
      (kdtNode = Code02_CameraRelocationAndQueries1::init(qx, qy, qz, i));
      (cameraToKdt[i] = kdtNode);
      (arr[i] = kdtNode);
    }
    (root = Code02_CameraRelocationAndQueries1::build(1, n, 0));
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextInt());
      if ((op == 0)) {
        (qid = in.nextDouble());
        (qx = in.nextDouble());
        (qy = in.nextDouble());
        (qz = in.nextDouble());
        (qx = Code02_CameraRelocationAndQueries1::decode(qx, (-100), 100));
        (qy = Code02_CameraRelocationAndQueries1::decode(qy, (-100), 100));
        (qz = Code02_CameraRelocationAndQueries1::decode(qz, (-100), 100));
        (camera = static_cast<int>(std::llround(
             Code02_CameraRelocationAndQueries1::decode(qid, 1, n))));
        Code02_CameraRelocationAndQueries1::remove(cameraToKdt[camera]);
        Code02_CameraRelocationAndQueries1::add(qx, qy, qz, camera);
      } else {
        (qx = in.nextDouble());
        (qy = in.nextDouble());
        (qz = in.nextDouble());
        (qr = in.nextDouble());
        (qx = Code02_CameraRelocationAndQueries1::decode(qx, (-100), 100));
        (qy = Code02_CameraRelocationAndQueries1::decode(qy, (-100), 100));
        (qz = Code02_CameraRelocationAndQueries1::decode(qz, (-100), 100));
        (qr = Code02_CameraRelocationAndQueries1::decode(qr, 0, 400));
        (curAns = Code02_CameraRelocationAndQueries1::query(qx, qy, qz, qr));
        out.println(curAns);
        (lastAns = curAns);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_CameraRelocationAndQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 摄像头的修改和查询，java版
// 三维空间中有n个摄像头，给定每个摄像头的初始位置，三维坐标(x, y, z)
// 接下来有m条操作，格式如下
// 操作 0 i x y z : 第i号摄像头位置变成(x, y, z)
// 操作 1 x y z r : 一个球体出现了，球心在(x, y, z)，半径为r
//                  题目保证该球体的表面会恰好碰到一个摄像头
//                  打印这个摄像头的编号，注意在内部的摄像头不算数
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 1 <= n、m <= 65536    随机生成坐标的绝对值 <= 100，至少小数点后5位
// 测试链接 : https://www.luogu.com.cn/problem/P11716
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 加密参数
        // 三维坐标
        // kdt节点编号对应的摄像头编号
        // 摄像头编号对应的kdt节点编号
        // 解密函数，密文encrypt，明文范围 l ~ r，解密得到明文返回
        // 题目给定的加密函数f(x)，该函数是严格单调递增的
        // 所以x在其范围上不断二分，当 f(x) == 密文，x就确定了
        // 于是需要确定，不同数据各自的范围，范围够用即可
        // 关于坐标，题目说了范围 -100 ~ +100
        // 关于摄像头编号，范围明显是 1 ~ n
        // 关于半径，题目保证每次出现球体时，表面一定会恰好出现一个摄像头
        // 所以球体的半径 <= 到达最远摄像头的距离
        // 球心和摄像头的每一维的坐标都在 -100 ~ +100
        // 所以每个维度的差值最多200，一共三个维度，根据欧式距离的计算公式
        // 半径 <= sqrt(200 * 200 * 3) < 347，所以半径范围取 0 ~ 400
        // 读写工具类
*/
