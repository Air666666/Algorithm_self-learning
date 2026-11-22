// Source: src/class205/Code04_SimpleProblem1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_SimpleProblem1 {
  inline static int MAXN = 200001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static int cntkdt = {};
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> sum = make_array<int>(MAXN);
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
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_SimpleProblem1() {}
  static int init(int qx, int qy, int qv) {
    (cntkdt++);
    (x[cntkdt] = qx);
    (y[cntkdt] = qy);
    (v[cntkdt] = qv);
    (ls[cntkdt] = (rs[cntkdt] = 0));
    (siz[cntkdt] = 1);
    (sum[cntkdt] = qv);
    (xmin[cntkdt] = (xmax[cntkdt] = qx));
    (ymin[cntkdt] = (ymax[cntkdt] = qy));
    return cntkdt;
  }
  static void maintain(int i) {
    (siz[i] = ((1 + siz[ls[i]]) + siz[rs[i]]));
    (sum[i] = ((v[i] + sum[ls[i]]) + sum[rs[i]]));
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
      int cmp = Code04_SimpleProblem1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code04_SimpleProblem1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code04_SimpleProblem1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code04_SimpleProblem1::partition(l, r, pidx, dimension);
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
    Code04_SimpleProblem1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code04_SimpleProblem1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code04_SimpleProblem1::build((mid + 1), r, (dimension ^ 1)));
    Code04_SimpleProblem1::maintain(rt);
    return rt;
  }
  static bool balance(int i) {
    return ((ALPHA * siz[i]) >= jmax(siz[ls[i]], siz[rs[i]]));
  }
  static void dfs(int i) {
    if ((i != 0)) {
      (arr[(++treeSiz)] = i);
      Code04_SimpleProblem1::dfs(ls[i]);
      Code04_SimpleProblem1::dfs(rs[i]);
    }
  }
  static void rebuild() {
    if ((top != 0)) {
      (treeSiz = 0);
      Code04_SimpleProblem1::dfs(top);
      int newRoot = Code04_SimpleProblem1::build(1, treeSiz, topDimension);
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
    if ((Code04_SimpleProblem1::compareNode(insertNode, u, dimension) <= 0)) {
      (ls[u] = Code04_SimpleProblem1::add(insertNode, ls[u], u, 1,
                                          (dimension ^ 1)));
    } else {
      (rs[u] = Code04_SimpleProblem1::add(insertNode, rs[u], u, 2,
                                          (dimension ^ 1)));
    }
    Code04_SimpleProblem1::maintain(u);
    if ((!Code04_SimpleProblem1::balance(u))) {
      (top = u);
      (topFather = fa);
      (topSide = side);
      (topDimension = dimension);
    }
    return u;
  }
  static void add(int qx, int qy, int qv) {
    (top = (topFather = (topSide = (topDimension = 0))));
    int insertNode = Code04_SimpleProblem1::init(qx, qy, qv);
    (root = Code04_SimpleProblem1::add(insertNode, root, 0, 0, 0));
    Code04_SimpleProblem1::rebuild();
  }
  static int query(int x1, int y1, int x2, int y2, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((((xmax[i] < x1) || (x2 < xmin[i])) || (ymax[i] < y1)) ||
         (y2 < ymin[i]))) {
      return 0;
    }
    if (((((x1 <= xmin[i]) && (xmax[i] <= x2)) && (y1 <= ymin[i])) &&
         (ymax[i] <= y2))) {
      return sum[i];
    }
    int ans = 0;
    if (((((x1 <= x[i]) && (x[i] <= x2)) && (y1 <= y[i])) && (y[i] <= y2))) {
      (ans += v[i]);
    }
    (ans += Code04_SimpleProblem1::query(x1, y1, x2, y2, ls[i]));
    (ans += Code04_SimpleProblem1::query(x1, y1, x2, y2, rs[i]));
    return ans;
  }
  static int query(int x1, int y1, int x2, int y2) {
    return Code04_SimpleProblem1::query(x1, y1, x2, y2, root);
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    int op = {};
    int a = {};
    int b = {};
    int c = {};
    int d = {};
    int lastAns = {};
    (op = in.nextInt());
    (lastAns = 0);
    while ((op != 3)) {
      (a = in.nextInt());
      (b = in.nextInt());
      (c = in.nextInt());
      (a ^= lastAns);
      (b ^= lastAns);
      (c ^= lastAns);
      if ((op == 1)) {
        Code04_SimpleProblem1::add(a, b, c);
      } else {
        (d = in.nextInt());
        (d ^= lastAns);
        (lastAns = Code04_SimpleProblem1::query(a, b, c, d));
        out.println(lastAns);
      }
      (op = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_SimpleProblem1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 简单题，替罪羊树的方式，java版
// 有一个n * n的平面区域，初始时没有点，有若干条操作，类型如下
// 操作 1 a b c   : 平面里增加一个点，坐标(a, b)，点权为c
// 操作 2 a b c d : 查询(a, b)为左下角、(c, d)为右上角的区域中，所有点的点权和
// 操作 3         : 终止，以后没有操作了
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 1 <= n <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4148
// 提交以下的code，提交时请把类名改成"Main"，本题卡空间，java实现无法通过
// 想通过用C++实现，本节课Code04_SimpleProblem2文件就是C++的实现
// 两个版本的逻辑完全一样，C++版本可以通过所有测试
        // K-D树的节点计数
        // K-D树采用替罪羊树的方式，只有一个头
        // 子树节点数量
        // 子树点权累加和
        // 平衡因子
        // 最顶部不平衡点
        // 最顶部不平衡点的父亲
        // 最顶部不平衡点是其父亲的哪侧儿子
        // 最顶部不平衡点用什么维度进行的划分
        // 不平衡时收集节点编号
        // 遍历不平衡子树，收集到的节点数量
        // 建立单个节点，返回节点编号
        // 判断是否平衡
        //
收集不平衡子树的节点编号，先序、中序、后序都可以，因为重构交替维度选中位点
        // 重构不平衡子树
        //
插入节点编号insertNode，当前节点u，父亲fa，哪侧side，维度dimension，返回头节点编号
                // 递归返回时不停覆盖，最终的top是最上方的不平衡点
        // 查询矩形的范围[x1~x2] * [y1~y2]，节点i有掌管的区域
        // 返回节点i的区域中，属于查询范围的点权累加和
                // 读入n其实没用
        // 读写工具类
*/
