// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5471

// Source: src/class206/Code05_Jump1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Jump1 {
  inline static int MAXN = 200001;
  inline static int INF = jshl(1, 30);
  inline static int n = {};
  inline static int m = {};
  inline static int w = {};
  inline static int h = {};
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<Array<int>> jump = make_array<int>(MAXN, 5);
  inline static int root = {};
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<int> xmin = make_array<int>(MAXN);
  inline static Array<int> xmax = make_array<int>(MAXN);
  inline static Array<int> ymin = make_array<int>(MAXN);
  inline static Array<int> ymax = make_array<int>(MAXN);
  inline static Array<int> headg = make_array<int>(MAXN);
  inline static Array<int> nextg = make_array<int>(MAXN);
  inline static Array<int> tog = make_array<int>(MAXN);
  inline static int cntg = {};
  inline static Array<int> headj = make_array<int>(MAXN);
  inline static Array<int> nextj = make_array<int>(MAXN);
  inline static Array<int> toj = make_array<int>(MAXN);
  inline static int cntj = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static JHeap<Array<int>> heap = JHeap<Array<int>>(
      [](Array<int> a, Array<int> b) { return (a[0] - b[0]); });
  inline static int first = {};
  inline static int last = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Jump1() {}
  static void addEdge(int u, int v) {
    (nextg[(++cntg)] = headg[u]);
    (tog[cntg] = v);
    (headg[u] = cntg);
  }
  static void addJump(int p, int j) {
    (nextj[(++cntj)] = headj[p]);
    (toj[cntj] = j);
    (headj[p] = cntj);
  }
  static void maintain(int i) {
    (xmin[i] = jmin(x[i], jmin(xmin[ls[i]], xmin[rs[i]])));
    (xmax[i] = jmax(x[i], jmax(xmax[ls[i]], xmax[rs[i]])));
    (ymin[i] = jmin(y[i], jmin(ymin[ls[i]], ymin[rs[i]])));
    (ymax[i] = jmax(y[i], jmax(ymax[ls[i]], ymax[rs[i]])));
  }
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
      int cmp = Code05_Jump1::compareNode(arr[i], pidx, dimension);
      if ((cmp == 0)) {
        (i++);
      } else if ((cmp < 0)) {
        [&]() {
          auto jargument_0 = (first++);
          auto jargument_1 = (i++);
          return Code05_Jump1::swap(jargument_0, jargument_1);
        }();
      } else {
        Code05_Jump1::swap(i, (last--));
      }
    }
  }
  static void randSelect(int l, int r, int i, int dimension) {
    while ((l <= r)) {
      int pidx = arr[(l + static_cast<int>((j::random() * ((r - l) + 1))))];
      Code05_Jump1::partition(l, r, pidx, dimension);
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
    Code05_Jump1::randSelect(l, r, mid, dimension);
    int rt = arr[mid];
    (ls[rt] = Code05_Jump1::build(l, (mid - 1), (dimension ^ 1)));
    (rs[rt] = Code05_Jump1::build((mid + 1), r, (dimension ^ 1)));
    Code05_Jump1::maintain(rt);
    Code05_Jump1::addEdge((n + rt), rt);
    if ((ls[rt] != 0)) {
      Code05_Jump1::addEdge((n + rt), (n + ls[rt]));
    }
    if ((rs[rt] != 0)) {
      Code05_Jump1::addEdge((n + rt), (n + rs[rt]));
    }
    return rt;
  }
  static void heapAdd(int d, int i) {
    if (((!vis[i]) && (dist[i] > d))) {
      (dist[i] = d);
      heap.add(Array<int>{d, i});
    }
  }
  static void jumpToRectangle(int jl, int jr, int jd, int ju, int jdist,
                              int i) {
    if ((i == 0)) {
      return;
    }
    if ((dist[(n + i)] <= jdist)) {
      return;
    }
    if (((((xmax[i] < jl) || (jr < xmin[i])) || (ymax[i] < jd)) ||
         (ju < ymin[i]))) {
      return;
    }
    if (((((jl <= xmin[i]) && (xmax[i] <= jr)) && (jd <= ymin[i])) &&
         (ymax[i] <= ju))) {
      Code05_Jump1::heapAdd(jdist, (n + i));
      return;
    }
    if (((((jl <= x[i]) && (x[i] <= jr)) && (jd <= y[i])) && (y[i] <= ju))) {
      Code05_Jump1::heapAdd(jdist, i);
    }
    Code05_Jump1::jumpToRectangle(jl, jr, jd, ju, jdist, ls[i]);
    Code05_Jump1::jumpToRectangle(jl, jr, jd, ju, jdist, rs[i]);
  }
  static void dijkstra() {
    j::fill(dist, 1, (jshl(n, 1) + 1), INF);
    (dist[1] = 0);
    heap.add(Array<int>{0, 1});
    while ((!heap.isEmpty())) {
      Array<int> cur = heap.poll();
      int d = cur[0];
      int i = cur[1];
      if ((!vis[i])) {
        (vis[i] = true);
        if ((i <= n)) {
          for (int e = headj[i]; (e > 0); (e = nextj[e])) {
            int j = toj[e];
            Code05_Jump1::jumpToRectangle(jump[j][1], jump[j][2], jump[j][3],
                                          jump[j][4], (d + jump[j][0]), root);
          }
        } else {
          for (int e = headg[i]; (e > 0); (e = nextg[e])) {
            Code05_Jump1::heapAdd(d, tog[e]);
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (w = in.nextInt());
    (h = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (x[i] = in.nextInt());
      (y[i] = in.nextInt());
      (arr[i] = i);
    }
    {
      int j = 1;
      int p = {};
      for (; (j <= m); (j++)) {
        (p = in.nextInt());
        (jump[j][0] = in.nextInt());
        (jump[j][1] = in.nextInt());
        (jump[j][2] = in.nextInt());
        (jump[j][3] = in.nextInt());
        (jump[j][4] = in.nextInt());
        Code05_Jump1::addJump(p, j);
      }
    }
    (xmin[0] = (ymin[0] = INF));
    (xmax[0] = (ymax[0] = (-INF)));
    (root = Code05_Jump1::build(1, n, 0));
    Code05_Jump1::dijkstra();
    for (int i = 2; (i <= n); (i++)) {
      out.println(dist[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Jump1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 弹跳，java版
// 一共有n个点，编号1~n，给定每个点的坐标(x, y)
// 一共有m个弹跳装置，给定每个弹跳装置的参数 p t l r d u
// 表示装置在p号点，花费t的时间，可以从p号点跳到[l, r] * [d, u]中的任意点
// 从1号点出发，可以重复经过点，也可以重复使用弹跳装置，题目保证可以到达每个点
// 打印从1号点到达2、3 .. n号点各自的最短用时
// 1 <= n <= 7 * 10^4
// 1 <= m <= 1.5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5471
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // t、l、r、d、u
        // 静态K-D树
        // 优化建图，链式前向星实现建图
        // 每个真实点拥有的弹跳装置列表，链式前向星实现列表
        // dijkstra
        // 距离、编号
                // 优化建图
                // n + rt是虚点，表示以rt为根的整棵子树
                // 虚点可以到达子树中的所有真实点
        // 1号点到i号点，出现了新距离d，尝试更新堆
                // 从1号点到当前虚点的最短距离，已经优于jdist，可以剪枝
                // 弹跳装置在当前区域之外，可以剪枝
                // 弹跳装置包括了当前区域，更新1号点到当前区域虚点的最短距离
                // 弹跳装置包括了当前点，更新1号点到当前点的最短距离
                                //
如果是真实点，可能有若干弹跳装置，但一定没有出边
                                // 如果是虚点，一定没有弹跳装置，但肯定有出边
                                        //
枚举弹跳装置，利用dist信息尽量剪枝，优化常数时间
                                        //
区域虚点通过优化建图，去往区域内所有真实点
        // 读写工具类
*/
