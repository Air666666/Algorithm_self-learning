// Source: src/class167/Code04_ShortestPathQueries1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_ShortestPathQueries1 {
  inline static int MAXN = 200001;
  inline static int MAXT = 5000001;
  inline static int BIT = 29;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<Array<int>> event = make_array<int>(jshl(MAXN, 1), 4);
  inline static int eventCnt = {};
  inline static Array<int> op = make_array<int>(MAXN);
  inline static Array<int> x = make_array<int>(MAXN);
  inline static Array<int> y = make_array<int>(MAXN);
  inline static Array<int> d = make_array<int>(MAXN);
  inline static Array<int> basis = make_array<int>((BIT + 1));
  inline static Array<int> inspos = make_array<int>((BIT + 1));
  inline static int basiz = 0;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> eor = make_array<int>(MAXN);
  inline static Array<Array<int>> rollback = make_array<int>(MAXN, 2);
  inline static int opsize = 0;
  inline static Array<int> head = make_array<int>(jshl(MAXN, 2));
  inline static Array<int> next = make_array<int>(MAXT);
  inline static Array<int> tox = make_array<int>(MAXT);
  inline static Array<int> toy = make_array<int>(MAXT);
  inline static Array<int> tow = make_array<int>(MAXT);
  inline static int cnt = 0;
  inline static Array<int> ans = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_ShortestPathQueries1() {}
  static void insert(int num) {
    for (int i = BIT; (i >= 0); (i--)) {
      if ((jshr(num, i) == 1)) {
        if ((basis[i] == 0)) {
          (basis[i] = num);
          (inspos[(basiz++)] = i);
          return;
        }
        (num ^= basis[i]);
      }
    }
  }
  static int minEor(int num) {
    for (int i = BIT; (i >= 0); (i--)) {
      (num = jmin(num, (num ^ basis[i])));
    }
    return num;
  }
  static void cancel(int oldsiz) {
    while ((basiz > oldsiz)) {
      (basis[inspos[(--basiz)]] = 0);
    }
  }
  static int find(int i) {
    while ((i != father[i])) {
      (i = father[i]);
    }
    return i;
  }
  static int getEor(int i) {
    int ans = 0;
    while ((i != father[i])) {
      (ans ^= eor[i]);
      (i = father[i]);
    }
    return ans;
  }
  static bool union_method(int u, int v, int w) {
    int fu = Code04_ShortestPathQueries1::find(u);
    int fv = Code04_ShortestPathQueries1::find(v);
    (w = ([&]() {
       auto jleft = Code04_ShortestPathQueries1::getEor(u);
       auto jright = Code04_ShortestPathQueries1::getEor(v);
       return (jleft ^ jright);
     }() ^ w));
    if ((fu == fv)) {
      Code04_ShortestPathQueries1::insert(w);
      return false;
    }
    if ((siz[fu] < siz[fv])) {
      int tmp = fu;
      (fu = fv);
      (fv = tmp);
    }
    (father[fv] = fu);
    (siz[fu] += siz[fv]);
    (eor[fv] = w);
    (rollback[(++opsize)][0] = fu);
    (rollback[opsize][1] = fv);
    return true;
  }
  static void undo() {
    int fx = rollback[opsize][0];
    int fy = rollback[(opsize--)][1];
    (father[fy] = fy);
    (eor[fy] = 0);
    (siz[fx] -= siz[fy]);
  }
  static void addEdge(int i, int x, int y, int w) {
    (next[(++cnt)] = head[i]);
    (tox[cnt] = x);
    (toy[cnt] = y);
    (tow[cnt] = w);
    (head[i] = cnt);
  }
  static void add(int jobl, int jobr, int jobx, int joby, int jobw, int l,
                  int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code04_ShortestPathQueries1::addEdge(i, jobx, joby, jobw);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code04_ShortestPathQueries1::add(jobl, jobr, jobx, joby, jobw, l, mid,
                                         jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code04_ShortestPathQueries1::add(jobl, jobr, jobx, joby, jobw,
                                         (mid + 1), r, (jshl(i, 1) | 1));
      }
    }
  }
  static void dfs(int l, int r, int i) {
    int oldsiz = basiz;
    int unionCnt = 0;
    for (int e = head[i]; (e > 0); (e = next[e])) {
      if (Code04_ShortestPathQueries1::union_method(tox[e], toy[e], tow[e])) {
        (unionCnt++);
      }
    }
    if ((l == r)) {
      if ((op[l] == 3)) {
        (ans[l] = Code04_ShortestPathQueries1::minEor([&]() {
           auto jleft = Code04_ShortestPathQueries1::getEor(x[l]);
           auto jright = Code04_ShortestPathQueries1::getEor(y[l]);
           return (jleft ^ jright);
         }()));
      }
    } else {
      int mid = jshr((l + r), 1);
      Code04_ShortestPathQueries1::dfs(l, mid, jshl(i, 1));
      Code04_ShortestPathQueries1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    Code04_ShortestPathQueries1::cancel(oldsiz);
    for (int k = 1; (k <= unionCnt); (k++)) {
      Code04_ShortestPathQueries1::undo();
    }
  }
  static void prepare() {
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
      (siz[i] = 1);
    }
    j::sort(event, 1, (eventCnt + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0])
                  ? (a[0] - b[0])
                  : ((a[1] != b[1]) ? (a[1] - b[1]) : (a[2] - b[2])));
    });
    int x = {};
    int y = {};
    int start = {};
    int end = {};
    int d = {};
    {
      int l = 1;
      int r = 1;
      for (; (l <= eventCnt); (l = (++r))) {
        (x = event[l][0]);
        (y = event[l][1]);
        while (((((r + 1) <= eventCnt) && (event[(r + 1)][0] == x)) &&
                (event[(r + 1)][1] == y))) {
          (r++);
        }
        for (int i = l; (i <= r); (i += 2)) {
          (start = event[i][2]);
          (end = (((i + 1) <= r) ? (event[(i + 1)][2] - 1) : q));
          (d = event[i][3]);
          Code04_ShortestPathQueries1::add(start, end, x, y, d, 0, q, 1);
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO();
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (event[i][0] = in.nextInt());
      (event[i][1] = in.nextInt());
      (event[i][2] = 0);
      (event[i][3] = in.nextInt());
    }
    (eventCnt = m);
    (q = in.nextInt());
    for (int i = 1; (i <= q); (i++)) {
      (op[i] = in.nextInt());
      (x[i] = in.nextInt());
      (y[i] = in.nextInt());
      if ((op[i] == 1)) {
        (d[i] = in.nextInt());
      }
      if ((op[i] != 3)) {
        (event[(++eventCnt)][0] = x[i]);
        (event[eventCnt][1] = y[i]);
        (event[eventCnt][2] = i);
        (event[eventCnt][3] = d[i]);
      }
    }
    Code04_ShortestPathQueries1::prepare();
    Code04_ShortestPathQueries1::dfs(0, q, 1);
    for (int i = 1; (i <= q); (i++)) {
      if ((op[i] == 3)) {
        out.println(ans[i]);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_ShortestPathQueries1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 异或最短路，java版
// 一共有n个节点，m条边，每条边有边权
// 接下来有q条操作，每种操作是如下三种类型中的一种
// 操作 1 x y d : 原图中加入，点x到点y，权值为d的边
// 操作 2 x y   : 原图中删除，点x到点y的边
// 操作 3 x y   :
点x到点y，所有路随便走，沿途边权都异或起来，打印能取得的异或最小值
// 保证x < y，并且任意操作后，图连通、无重边、无自环，所有操作均合法
// 1 <= n、m、q <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF938G
// 测试链接 : https://codeforces.com/problemset/problem/938/G
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 端点x、端点y、时间点t、边权w
        // 操作记录下来
        // 可撤销线性基
        // 带权并查集 + 可撤销并查集
        // 时间轴线段树上的区间任务列表
        // 查询操作的答案
        // num插入线性基
        // num结合线性基，能得到的最小异或值返回
        // 线性基的撤销，让空间大小回到之前的规模
        // 可撤销并查集找集合代表点
        // 返回i到集合代表点的异或和
        // 可撤销并查集的合并，增加a和b之间，权值为w的边
        // 集合合并的过程中，还要更新eor数组
        // 更新eor的方式，参考讲解156，带权并查集
        // 并查集的撤销操作
        // 给某个线段树区间增加任务，点x到点y之间，增加权值为w的边
        // 读写工具类
*/
