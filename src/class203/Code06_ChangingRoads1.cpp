// Source: src/class203/Code06_ChangingRoads1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_ChangingRoads1 {
  inline static int MAXN = 200001;
  inline static int MAXD = 32767;
  inline static int MAXT = 4000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> ex = make_array<int>(MAXN);
  inline static Array<int> ey = make_array<int>(MAXN);
  inline static Array<int> ew = make_array<int>(MAXN);
  inline static int cnte = {};
  inline static Array<int> head = make_array<int>(jshl(MAXD, 2));
  inline static Array<int> nxt = make_array<int>(MAXT);
  inline static Array<int> to = make_array<int>(MAXT);
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXN);
  inline static Array<int> rs = make_array<int>(MAXN);
  inline static Array<bool> rev = make_array<bool>(MAXN);
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static Array<int> maxEdge = make_array<int>(MAXN);
  inline static Array<int> rollbackEdge = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> rollbackType = make_array<int>(jshl(MAXN, 1));
  inline static int opsize = {};
  inline static i64 mstSum = 1;
  inline static Array<i64> ans = make_array<i64>(MAXD);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_ChangingRoads1() {}
  static void rangeAddEdge(int i, int e) {
    (nxt[(++cntg)] = head[i]);
    (to[cntg] = e);
    (head[i] = cntg);
  }
  static void add(int jobl, int jobr, int jobe, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code06_ChangingRoads1::rangeAddEdge(i, jobe);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code06_ChangingRoads1::add(jobl, jobr, jobe, l, mid, jshl(i, 1));
      }
      if ((jobr > mid)) {
        Code06_ChangingRoads1::add(jobl, jobr, jobe, (mid + 1), r,
                                   (jshl(i, 1) | 1));
      }
    }
  }
  static void up(int x) {
    (maxEdge[x] = ((x <= n) ? 0 : (x - n)));
    if ((ew[maxEdge[ls[x]]] > ew[maxEdge[x]])) {
      (maxEdge[x] = maxEdge[ls[x]]);
    }
    if ((ew[maxEdge[rs[x]]] > ew[maxEdge[x]])) {
      (maxEdge[x] = maxEdge[rs[x]]);
    }
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
      Code06_ChangingRoads1::reverse(ls[x]);
      Code06_ChangingRoads1::reverse(rs[x]);
      (rev[x] = false);
    }
  }
  static void rotate(int x) {
    int f = fa[x];
    int g = fa[f];
    if ((Code06_ChangingRoads1::lr(x) == 0)) {
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
    if ((!Code06_ChangingRoads1::isroot(f))) {
      if ((Code06_ChangingRoads1::lr(f) == 0)) {
        (ls[g] = x);
      } else {
        (rs[g] = x);
      }
    }
    (fa[f] = x);
    (fa[x] = g);
    Code06_ChangingRoads1::up(f);
    Code06_ChangingRoads1::up(x);
  }
  static void splay(int x) {
    int siz = 0;
    (sta[(++siz)] = x);
    for (int y = x; (!Code06_ChangingRoads1::isroot(y)); (y = fa[y])) {
      (sta[(++siz)] = fa[y]);
    }
    while ((siz != 0)) {
      Code06_ChangingRoads1::down(sta[(siz--)]);
    }
    while ((!Code06_ChangingRoads1::isroot(x))) {
      int f = fa[x];
      if ((!Code06_ChangingRoads1::isroot(f))) {
        if ([&]() {
              auto jleft = Code06_ChangingRoads1::lr(x);
              auto jright = Code06_ChangingRoads1::lr(f);
              return (jleft == jright);
            }()) {
          Code06_ChangingRoads1::rotate(f);
        } else {
          Code06_ChangingRoads1::rotate(x);
        }
      }
      Code06_ChangingRoads1::rotate(x);
    }
  }
  static void access(int x) {
    for (int y = 0; (x != 0); (y = x), (x = fa[x])) {
      Code06_ChangingRoads1::splay(x);
      (rs[x] = y);
      Code06_ChangingRoads1::up(x);
    }
  }
  static void makeroot(int x) {
    Code06_ChangingRoads1::access(x);
    Code06_ChangingRoads1::splay(x);
    Code06_ChangingRoads1::reverse(x);
  }
  static int findroot(int x) {
    Code06_ChangingRoads1::access(x);
    Code06_ChangingRoads1::splay(x);
    Code06_ChangingRoads1::down(x);
    while ((ls[x] != 0)) {
      (x = ls[x]);
      Code06_ChangingRoads1::down(x);
    }
    Code06_ChangingRoads1::splay(x);
    return x;
  }
  static void split(int x, int y) {
    Code06_ChangingRoads1::makeroot(x);
    Code06_ChangingRoads1::access(y);
    Code06_ChangingRoads1::splay(y);
  }
  static void link(int x, int y) {
    Code06_ChangingRoads1::makeroot(x);
    if ((Code06_ChangingRoads1::findroot(y) != x)) {
      (fa[x] = y);
    }
  }
  static void cut(int x, int y) {
    Code06_ChangingRoads1::makeroot(x);
    if (((((Code06_ChangingRoads1::findroot(y) == x) && (fa[y] == x)) &&
          (ls[y] == 0)) &&
         (rs[x] == y))) {
      (fa[y] = (rs[x] = 0));
      Code06_ChangingRoads1::up(x);
    }
  }
  static void backup(int edge, int type) {
    (rollbackEdge[(++opsize)] = edge);
    (rollbackType[opsize] = type);
  }
  static void addEdge(int e) {
    int x = ex[e];
    int y = ey[e];
    Code06_ChangingRoads1::makeroot(x);
    if ((Code06_ChangingRoads1::findroot(y) != x)) {
      Code06_ChangingRoads1::link(x, (n + e));
      Code06_ChangingRoads1::link(y, (n + e));
      Code06_ChangingRoads1::backup(e, 1);
      (mstSum += ew[e]);
    } else {
      Code06_ChangingRoads1::split(x, y);
      int pre = maxEdge[y];
      if ((ew[pre] > ew[e])) {
        Code06_ChangingRoads1::cut(ex[pre], (n + pre));
        Code06_ChangingRoads1::cut(ey[pre], (n + pre));
        Code06_ChangingRoads1::backup(pre, 2);
        (mstSum -= ew[pre]);
        Code06_ChangingRoads1::link(x, (n + e));
        Code06_ChangingRoads1::link(y, (n + e));
        Code06_ChangingRoads1::backup(e, 1);
        (mstSum += ew[e]);
      }
    }
  }
  static void undo() {
    int e = rollbackEdge[opsize];
    int t = rollbackType[(opsize--)];
    if ((t == 1)) {
      Code06_ChangingRoads1::cut(ex[e], (n + e));
      Code06_ChangingRoads1::cut(ey[e], (n + e));
      (mstSum -= ew[e]);
    } else {
      Code06_ChangingRoads1::link(ex[e], (n + e));
      Code06_ChangingRoads1::link(ey[e], (n + e));
      (mstSum += ew[e]);
    }
  }
  static void dfs(int l, int r, int i) {
    int tmp = opsize;
    for (int k = head[i]; (k != 0); (k = nxt[k])) {
      Code06_ChangingRoads1::addEdge(to[k]);
    }
    if ((l == r)) {
      (ans[l] = mstSum);
    } else {
      int mid = jshr((l + r), 1);
      Code06_ChangingRoads1::dfs(l, mid, jshl(i, 1));
      Code06_ChangingRoads1::dfs((mid + 1), r, (jshl(i, 1) | 1));
    }
    while ((opsize > tmp)) {
      Code06_ChangingRoads1::undo();
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    int day = (MAXD - 1);
    for (int i = 1; (i < n); (i++)) {
      (ex[(++cnte)] = in.nextInt());
      (ey[cnte] = in.nextInt());
      (ew[cnte] = in.nextInt());
      Code06_ChangingRoads1::add(1, day, cnte, 1, day, 1);
    }
    (m = in.nextInt());
    {
      int i = 1;
      int l = {};
      int r = {};
      for (; (i <= m); (i++)) {
        (ex[(++cnte)] = in.nextInt());
        (ey[cnte] = in.nextInt());
        (ew[cnte] = in.nextInt());
        (l = in.nextInt());
        (r = in.nextInt());
        Code06_ChangingRoads1::add(l, r, cnte, 1, day, 1);
      }
    }
    Code06_ChangingRoads1::dfs(1, day, 1);
    for (int i = 1; (i <= day); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_ChangingRoads1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 变化的道路，java版
// 一共n个点，n-1条无向道路，所有点组成一棵树，这些道路始终存在
// 然后给定m条变化的道路，每条变化的道路，只在第l天到第r天存在
// 道路给定权值代表费用，同一天内，一条道路在第一次经过时收费，之后免费
// 每天从1号点出发并游览所有点，要求游览结束后剩余钱数 > 0
// 打印每天出发时至少需要多少钱，也就是最少总费用+1
// 1 <= n <= 5 * 10^4
// 1 <= m <= 10^5
// 天数固定为32766，输出也固定为32766行
// 测试链接 : https://www.luogu.com.cn/problem/P4319
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 道路信息，包括初始道路和变化道路
        // 时间轴线段树，线段树区间拥有哪些道路的列表
        // 辅助splay
        // maxEdge[x]表示以x为根的辅助splay中，权值最大的边的编号
        // LCT最小生成树修改的回滚信息，用回滚栈记录
        // type == 1 : 这条边加入
        // type == 2 : 这条边删除
        // 当前最小生成树的边权和，再加1就是答案
        // 尝试把第e条边加入当前最小生成树
                        // 两端不连通，直接加入最小生成树
                        // 两端已经连通，查询路径上的最大边
                                // 删除旧边
                                // 加入新边
        // 读写工具类
*/
