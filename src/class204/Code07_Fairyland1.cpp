// Source: src/class204/Code07_Fairyland1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Fairyland1 {
  inline static int MAXN = 300001;
  inline static int MAXT = 10000001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static int t = {};
  inline static Array<int> eu = make_array<int>(MAXN);
  inline static Array<int> ev = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> val = make_array<int>(MAXN);
  inline static Array<int> minv = make_array<int>(MAXN);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> tl = make_array<int>(MAXT);
  inline static Array<int> tr = make_array<int>(MAXT);
  inline static Array<int> num = make_array<int>(MAXT);
  inline static int cntt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Fairyland1() {}
  static void up(int x) {
    (minv[x] = jmin(val[x], jmin(minv[ls[x]], minv[rs[x]])));
  }
  static bool isroot(int x) { return ((ls[fa[x]] != x) && (rs[fa[x]] != x)); }
  static int lr(int x) { return ((ls[fa[x]] == x) ? 0 : 1); }
  static void reverse(int x) {
    if ((x != 0)) {
      int tmp = ls[x];
      (ls[x] = rs[x]);
      (rs[x] = tmp);
      (rev[x] = (!rev[x]));
    }
  }
  static void down(int x) {
    if (rev[x]) {
      Code07_Fairyland1::reverse(ls[x]);
      Code07_Fairyland1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code07_Fairyland1::lr(x) == 0)) {
      (ls[f] = rs[x]);
      if ((ls[f] != 0)) {
        (fa[ls[f]] = f);
      }
      (rs[x] = f);
    } else {
      (rs[f] = ls[x]);
      if ((rs[f] != 0)) {
        (fa[rs[f]] = f);
      }
      (ls[x] = f);
    }
    if ((!Code07_Fairyland1::isroot(f))) {
      if ((Code07_Fairyland1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code07_Fairyland1::up(f);
    Code07_Fairyland1::up(x);
  }
  static void splay(int x) {
    int size = 0;
    (sta[(++size)] = x);
    for (int y = x; (!Code07_Fairyland1::isroot(y)); (y = fa[y])) {
      (sta[(++size)] = fa[y]);
    }
    while ((size != 0)) {
      Code07_Fairyland1::down(sta[(size--)]);
    }
    while ((!Code07_Fairyland1::isroot(x))) {
      int f = fa[x];
      if ((!Code07_Fairyland1::isroot(f))) {
        if ([&]() {
              auto jleft = Code07_Fairyland1::lr(x);
              auto jright = Code07_Fairyland1::lr(f);
              return (jleft == jright);
            }()) {
          Code07_Fairyland1::rotate(f);
        } else {
          Code07_Fairyland1::rotate(x);
        }
      }
      Code07_Fairyland1::rotate(x);
    }
    Code07_Fairyland1::up(x);
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code07_Fairyland1::splay(x);
      (rs[x] = y);
      Code07_Fairyland1::up(x);
    }
  }
  static void makeroot(int x) {
    Code07_Fairyland1::access(x);
    Code07_Fairyland1::splay(x);
    Code07_Fairyland1::reverse(x);
  }
  static int findroot(int x) {
    Code07_Fairyland1::access(x);
    Code07_Fairyland1::splay(x);
    Code07_Fairyland1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code07_Fairyland1::down(x);
    }
    Code07_Fairyland1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code07_Fairyland1::makeroot(x);
    Code07_Fairyland1::access(y);
    Code07_Fairyland1::splay(y);
  }
  static void link(int x, int y) {
    Code07_Fairyland1::makeroot(x);
    if ((Code07_Fairyland1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code07_Fairyland1::makeroot(x);
    if (((((Code07_Fairyland1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code07_Fairyland1::up(x);
    }
  }
  static int pathMin(int x, int y) {
    Code07_Fairyland1::split(x, y);
    return minv[y];
  }
  static int add(int jobi, int jobv, int l, int r, int i) {
    int rt = (++cntt);
    (tl[rt] = tl[i]);
    (tr[rt] = tr[i]);
    (num[rt] = num[i]);
    if ((l == r)) {
      (num[rt] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (tl[rt] = Code07_Fairyland1::add(jobi, jobv, l, mid, tl[i]));
      } else {
        (tr[rt] = Code07_Fairyland1::add(jobi, jobv, (mid + 1), r, tr[i]));
      }
      (num[rt] = (num[tl[rt]] + num[tr[rt]]));
    }
    return rt;
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      return num[i];
    }
    int ans = 0;
    int mid = jshr((l + r), 1);
    if ((jobl <= mid)) {
      (ans += Code07_Fairyland1::query(jobl, jobr, l, mid, tl[i]));
    }
    if ((jobr > mid)) {
      (ans += Code07_Fairyland1::query(jobl, jobr, (mid + 1), r, tr[i]));
    }
    return ans;
  }
  static void prepare() {
    for (int i = 0; (i <= n); (i++)) {
      (val[i] = (minv[i] = INF));
    }
    for (int i = 1; (i <= m); (i++)) {
      (val[(n + i)] = (minv[(n + i)] = i));
    }
    for (int i = 1; (i <= m); (i++)) {
      int x = eu[i];
      int y = ev[i];
      (root[i] = root[(i - 1)]);
      if ((x != y)) {
        if ([&]() {
              auto jleft = Code07_Fairyland1::findroot(x);
              auto jright = Code07_Fairyland1::findroot(y);
              return (jleft == jright);
            }()) {
          int e = Code07_Fairyland1::pathMin(x, y);
          Code07_Fairyland1::cut(eu[e], (n + e));
          Code07_Fairyland1::cut(ev[e], (n + e));
          (root[i] = Code07_Fairyland1::add(e, (-1), 1, m, root[i]));
        }
        Code07_Fairyland1::link(x, (n + i));
        Code07_Fairyland1::link(y, (n + i));
        (root[i] = Code07_Fairyland1::add(i, 1, 1, m, root[i]));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    (t = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (eu[i] = in.nextInt());
      (ev[i] = in.nextInt());
    }
    Code07_Fairyland1::prepare();
    {
      int i = 1;
      int lastAns = 0;
      int l = {};
      int r = {};
      for (; (i <= q); (i++)) {
        (l = in.nextInt());
        (r = in.nextInt());
        if ((t > 0)) {
          (l = (jrem((l + (t * lastAns)), m) + 1));
          (r = (jrem((r + (t * lastAns)), m) + 1));
        }
        if ((l > r)) {
          int tmp = l;
          (l = r);
          (r = tmp);
        }
        (lastAns = (n - Code07_Fairyland1::query(l, r, 1, m, root[r])));
        out.println(lastAns);
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Fairyland1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 须臾幻境，java版
// 无向图中有n个点、m条无向边，边的编号是1~m
// 每条询问的格式为 l r，表示保留编号[l, r]的边，打印有多少个连通块
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 1 <= q <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5385
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 原图的点x，在LCT中编号x，权值为INF，是无效值
        // 原图的边i，在LCT中编号n+i，权值为i，是边序号
        // minv[x]表示以x为根的辅助splay，汇总最小的边序号
        // 可持久化线段树，记录每个生成的森林中，每条边是否存在
        // 查询x到y路径上编号最小的边
        // 读写工具类
*/
