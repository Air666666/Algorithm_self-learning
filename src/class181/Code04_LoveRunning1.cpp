// Source: src/class181/Code04_LoveRunning1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_LoveRunning1 {
  inline static int MAXN = 300001;
  inline static int MAXT = (MAXN * 50);
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> rtUp = make_array<int>(MAXN);
  inline static Array<int> rtDown = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_LoveRunning1() {}
  static void push(int u, int f, int e) {
    (ufe[stacksize][0] = u);
    (ufe[stacksize][1] = f);
    (ufe[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = ufe[stacksize][0]);
    (f = ufe[stacksize][1]);
    (e = ufe[stacksize][2]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code04_LoveRunning1::dfs1(v, u);
      }
    }
  }
  static void dfs2() {
    (stacksize = 0);
    Code04_LoveRunning1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code04_LoveRunning1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_LoveRunning1::push(u, f, e);
        if ((to[e] != f)) {
          Code04_LoveRunning1::push(to[e], u, (-1));
        }
      }
    }
  }
  static int getLca(int a, int b) {
    if ((dep[a] < dep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((dep[stjump[a][p]] >= dep[b])) {
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return a;
    }
    for (int p = (MAXP - 1); (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    return stjump[a][0];
  }
  static void up(int i) { (sum[i] = (sum[ls[i]] + sum[rs[i]])); }
  static int add(int jobi, int jobv, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
    }
    if ((l == r)) {
      (sum[rt] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code04_LoveRunning1::add(jobi, jobv, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code04_LoveRunning1::add(jobi, jobv, (mid + 1), r, rs[rt]));
      }
      Code04_LoveRunning1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (sum[t1] += sum[t2]);
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code04_LoveRunning1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code04_LoveRunning1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code04_LoveRunning1::up(t1);
    }
    return t1;
  }
  static int query(int jobi, int l, int r, int i) {
    if ((((jobi < l) || (jobi > r)) || (i == 0))) {
      return 0;
    }
    if ((l == r)) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    if ((jobi <= mid)) {
      return Code04_LoveRunning1::query(jobi, l, mid, ls[i]);
    } else {
      return Code04_LoveRunning1::query(jobi, (mid + 1), r, rs[i]);
    }
  }
  static void calc1(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code04_LoveRunning1::calc1(v, u);
        (rtUp[u] = Code04_LoveRunning1::merge(1, n, rtUp[u], rtUp[v]));
        (rtDown[u] = Code04_LoveRunning1::merge((-n), n, rtDown[u], rtDown[v]));
      }
    }
    (ans[u] = [&]() {
      auto jleft = Code04_LoveRunning1::query((dep[u] + w[u]), 1, n, rtUp[u]);
      auto jright =
          Code04_LoveRunning1::query((dep[u] - w[u]), (-n), n, rtDown[u]);
      return (jleft + jright);
    }());
  }
  static void calc2() {
    (stacksize = 0);
    Code04_LoveRunning1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code04_LoveRunning1::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_LoveRunning1::push(u, f, e);
        if ((to[e] != f)) {
          Code04_LoveRunning1::push(to[e], u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (rtUp[u] = Code04_LoveRunning1::merge(1, n, rtUp[u], rtUp[v]));
            (rtDown[u] =
                 Code04_LoveRunning1::merge((-n), n, rtDown[u], rtDown[v]));
          }
        }
        (ans[u] = [&]() {
          auto jleft =
              Code04_LoveRunning1::query((dep[u] + w[u]), 1, n, rtUp[u]);
          auto jright =
              Code04_LoveRunning1::query((dep[u] - w[u]), (-n), n, rtDown[u]);
          return (jleft + jright);
        }());
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code04_LoveRunning1::addEdge(u, v);
        Code04_LoveRunning1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      (w[i] = in.nextInt());
    }
    Code04_LoveRunning1::dfs2();
    for (int i = 1; (i <= m); (i++)) {
      int x = in.nextInt();
      int y = in.nextInt();
      int lca = Code04_LoveRunning1::getLca(x, y);
      int lcafa = stjump[lca][0];
      (rtUp[x] = Code04_LoveRunning1::add(dep[x], 1, 1, n, rtUp[x]));
      (rtUp[lcafa] = Code04_LoveRunning1::add(dep[x], (-1), 1, n, rtUp[lcafa]));
      (rtDown[y] = Code04_LoveRunning1::add(((2 * dep[lca]) - dep[x]), 1, (-n),
                                            n, rtDown[y]));
      (rtDown[lca] = Code04_LoveRunning1::add(((2 * dep[lca]) - dep[x]), (-1),
                                              (-n), n, rtDown[lca]));
    }
    Code04_LoveRunning1::calc2();
    for (int i = 1; (i <= n); (i++)) {
      out.print((ans[i] + String(u" ")));
    }
    out.println();
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_LoveRunning1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 天天爱跑步，java版
// 一共有n个点，给定n-1条边，所有节点组成一棵树
// 每个点上都有一个观察员，给出每个观察员的观测时刻w[i]
// 给出m个跑步者的路线，格式 x y : 该跑步者出发时刻为0，从x跑到y
// 任何跑步者通过任何一条边，耗时都是1秒
// 某个跑步者到达i号点的时刻 == w[i]，那么该跑步者才会被i号点的观察员观测到
// 打印i号点的观察员，能观测到多少人，一共n条打印
// 1 <= n、m、w[i] <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P1600
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 递归改迭代需要
        // 递归版，java会爆栈，C++可以通过
        // dfs1改迭代
        // 递归版，java会爆栈，C++可以通过
        // calc1改迭代
                // dfs1(1, 0);
                // calc1(1, 0);
        // 读写工具类
*/
