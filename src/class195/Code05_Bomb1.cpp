// Source: src/class195/Code05_Bomb1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_Bomb1 {
  inline static int MAXN = 500001;
  inline static int MAXT = (MAXN * 5);
  inline static int MAXE = (MAXN * 20);
  inline static int INF = jshl(1, 30);
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static Array<i64> location = make_array<i64>(MAXN);
  inline static Array<i64> radius = make_array<i64>(MAXN);
  inline static Array<int> a = make_array<int>(MAXE);
  inline static Array<int> b = make_array<int>(MAXE);
  inline static int cnte = {};
  inline static Array<int> head = make_array<int>(MAXT);
  inline static Array<int> nxt = make_array<int>(MAXE);
  inline static Array<int> to = make_array<int>(MAXE);
  inline static int cntg = {};
  inline static Array<int> rangel = make_array<int>(MAXT);
  inline static Array<int> ranger = make_array<int>(MAXT);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static int root = {};
  inline static int cntt = {};
  inline static Array<int> dfn = make_array<int>(MAXT);
  inline static Array<int> low = make_array<int>(MAXT);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXT);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXT);
  inline static Array<int> mostl = make_array<int>(MAXT);
  inline static Array<int> mostr = make_array<int>(MAXT);
  inline static int sccCnt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXT, 3);
  inline static int u = {};
  inline static int status = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_Bomb1() {}
  static void push(int u, int status, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = status);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (stacksize--);
    (u = stack[stacksize][0]);
    (status = stack[stacksize][1]);
    (e = stack[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void saveEdge(int u, int v) {
    (a[(++cnte)] = u);
    (b[cnte] = v);
  }
  static int lower(i64 num) {
    int l = 1;
    int r = n;
    int mid = {};
    int ans = (n + 1);
    while ((l <= r)) {
      (mid = jshr((l + r), 1));
      if ((location[mid] >= num)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static int build(int l, int r) {
    int rt = {};
    if ((l == r)) {
      (rt = l);
    } else {
      (rt = (++cntt));
      int mid = jshr((l + r), 1);
      (ls[rt] = Code05_Bomb1::build(l, mid));
      (rs[rt] = Code05_Bomb1::build((mid + 1), r));
      Code05_Bomb1::addEdge(ls[rt], rt);
      Code05_Bomb1::addEdge(rs[rt], rt);
      Code05_Bomb1::saveEdge(ls[rt], rt);
      Code05_Bomb1::saveEdge(rs[rt], rt);
    }
    (rangel[rt] = l);
    (ranger[rt] = r);
    return rt;
  }
  static void rangeToX(int jobl, int jobr, int jobx, int l, int r, int i) {
    if (((jobl <= l) && (r <= jobr))) {
      Code05_Bomb1::addEdge(i, jobx);
      Code05_Bomb1::saveEdge(i, jobx);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobl <= mid)) {
        Code05_Bomb1::rangeToX(jobl, jobr, jobx, l, mid, ls[i]);
      }
      if ((jobr > mid)) {
        Code05_Bomb1::rangeToX(jobl, jobr, jobx, (mid + 1), r, rs[i]);
      }
    }
  }
  static void tarjan1(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code05_Bomb1::tarjan1(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (mostl[sccCnt] = INF);
      (mostr[sccCnt] = (-INF));
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (mostl[sccCnt] = jmin(mostl[sccCnt], rangel[pop]));
        (mostr[sccCnt] = jmax(mostr[sccCnt], ranger[pop]));
      } while ((pop != u));
    }
  }
  static void tarjan2(int node) {
    (stacksize = 0);
    Code05_Bomb1::push(node, (-1), (-1));
    int v = {};
    while ((stacksize > 0)) {
      Code05_Bomb1::pop();
      if ((status == (-1))) {
        (dfn[u] = (low[u] = (++cntd)));
        (sta[(++top)] = u);
        (e = head[u]);
      } else {
        (v = to[e]);
        if ((status == 0)) {
          (low[u] = jmin(low[u], low[v]));
        }
        if (((status == 1) && (belong[v] == 0))) {
          (low[u] = jmin(low[u], dfn[v]));
        }
        (e = nxt[e]);
      }
      if ((e != 0)) {
        (v = to[e]);
        if ((dfn[v] == 0)) {
          Code05_Bomb1::push(u, 0, e);
          Code05_Bomb1::push(v, (-1), (-1));
        } else {
          Code05_Bomb1::push(u, 1, e);
        }
      } else {
        if ((dfn[u] == low[u])) {
          (sccCnt++);
          (mostl[sccCnt] = INF);
          (mostr[sccCnt] = (-INF));
          int pop = {};
          do {
            (pop = sta[(top--)]);
            (belong[pop] = sccCnt);
            (mostl[sccCnt] = jmin(mostl[sccCnt], rangel[pop]));
            (mostr[sccCnt] = jmax(mostr[sccCnt], ranger[pop]));
          } while ((pop != u));
        }
      }
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= cnte); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        Code05_Bomb1::addEdge(scc1, scc2);
      }
    }
  }
  static void dpOnDAG() {
    for (int u = sccCnt; (u > 0); (u--)) {
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        (mostl[v] = jmin(mostl[v], mostl[u]));
        (mostr[v] = jmax(mostr[v], mostr[u]));
      }
    }
  }
  static int query(int u) {
    int scc = belong[u];
    int num = ((mostr[scc] - mostl[scc]) + 1);
    return num;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (cntt = n);
    for (int i = 1; (i <= n); (i++)) {
      (location[i] = in.nextLong());
      (radius[i] = in.nextLong());
    }
    (root = Code05_Bomb1::build(1, n));
    for (int i = 1; (i <= n); (i++)) {
      int l = Code05_Bomb1::lower((location[i] - radius[i]));
      int r = (Code05_Bomb1::lower(((location[i] + radius[i]) + 1)) - 1);
      Code05_Bomb1::rangeToX(l, r, i, 1, n, root);
    }
    for (int i = 1; (i <= cntt); (i++)) {
      if ((dfn[i] == 0)) {
        Code05_Bomb1::tarjan2(i);
      }
    }
    Code05_Bomb1::condense();
    Code05_Bomb1::dpOnDAG();
    i64 ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      (ans = jrem((ans + ((1LL * Code05_Bomb1::query(i)) * i)), MOD));
    }
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code05_Bomb1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 炸弹，java版
// 一共有n个炸弹，所有炸弹排成一条直线，给定每个炸弹的坐标xi、爆炸半径ri
// 炸弹A引爆时，如果炸弹B在其影响范围里，那么炸弹B也会引爆，进而引发一连串的爆炸
// 炸弹i如果作为初始引爆的炸弹，最终会引爆多少个炸弹记为query(i)
// 计算i = 1 2 .. n时，i * query(i)的累加和，答案对 1000000007 取余
// 1 <= n <= 5 * 10^5
// -(10^18) <= xi <= +(10^18)，题目依次输入的坐标保证严格递增
// 0 <= ri <= 2 * 10^18
// 测试链接 : https://www.luogu.com.cn/problem/P5025
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 迭代版需要的栈，讲解118讲了递归改迭代的技巧
        // 递归版
        // 迭代版
                                // tarjan1(i);
        // 读写工具类
*/
