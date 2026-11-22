// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P3250

// Source: src/class169/Code03_Network1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Network1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = 0;
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static int cntd = {};
  inline static Array<int> tree = make_array<int>(MAXN);
  inline static Array<int> eid = make_array<int>(MAXM);
  inline static Array<int> op = make_array<int>(MAXM);
  inline static Array<int> x = make_array<int>(MAXM);
  inline static Array<int> y = make_array<int>(MAXM);
  inline static Array<int> v = make_array<int>(MAXM);
  inline static int cntq = 0;
  inline static Array<int> lset = make_array<int>(MAXM);
  inline static Array<int> rset = make_array<int>(MAXM);
  inline static Array<int> ans = make_array<int>(MAXM);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Network1() {}
  static void addEdge(int u, int v) {
    (next[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    (dfn[u] = (++cntd));
    (stjump[u][0] = f);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code03_Network1::dfs1(to[e], u);
      }
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        (siz[u] += siz[to[e]]);
      }
    }
  }
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
  static void dfs2() {
    (stacksize = 0);
    Code03_Network1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_Network1::pop();
      if ((e == (-1))) {
        (fa[u] = f);
        (dep[u] = (dep[f] + 1));
        (siz[u] = 1);
        (dfn[u] = (++cntd));
        (stjump[u][0] = f);
        for (int p = 1; (p < MAXP); (p++)) {
          (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
        }
        (e = head[u]);
      } else {
        (e = next[e]);
      }
      if ((e != 0)) {
        Code03_Network1::push(u, f, e);
        if ((to[e] != f)) {
          Code03_Network1::push(to[e], u, (-1));
        }
      } else {
        for (int e = head[u]; (e != 0); (e = next[e])) {
          if ((to[e] != f)) {
            (siz[u] += siz[to[e]]);
          }
        }
      }
    }
  }
  static int lca(int a, int b) {
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
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code03_Network1::lowbit(i));
    }
  }
  static int query(int i) {
    int ret = 0;
    while ((i > 0)) {
      (ret += tree[i]);
      (i -= Code03_Network1::lowbit(i));
    }
    return ret;
  }
  static void pathAdd(int x, int y, int v) {
    int xylca = Code03_Network1::lca(x, y);
    int lcafa = fa[xylca];
    Code03_Network1::add(dfn[x], v);
    Code03_Network1::add(dfn[y], v);
    Code03_Network1::add(dfn[xylca], (-v));
    if ((lcafa != 0)) {
      Code03_Network1::add(dfn[lcafa], (-v));
    }
  }
  static int pointQuery(int x) {
    return [&]() {
      auto jleft = Code03_Network1::query(((dfn[x] + siz[x]) - 1));
      auto jright = Code03_Network1::query((dfn[x] - 1));
      return (jleft - jright);
    }();
  }
  static void compute(int el, int er, int vl, int vr) {
    if ((el > er)) {
      return;
    }
    if ((vl == vr)) {
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((op[id] == 2)) {
          (ans[y[id]] = vl);
        }
      }
    } else {
      int mid = jdiv((vl + vr), 2);
      int lsiz = 0;
      int rsiz = 0;
      int request = 0;
      for (int i = el; (i <= er); (i++)) {
        int id = eid[i];
        if ((op[id] == 0)) {
          if ((v[id] <= mid)) {
            (lset[(++lsiz)] = id);
          } else {
            Code03_Network1::pathAdd(x[id], y[id], 1);
            (request++);
            (rset[(++rsiz)] = id);
          }
        } else if ((op[id] == 1)) {
          if ((v[id] <= mid)) {
            (lset[(++lsiz)] = id);
          } else {
            Code03_Network1::pathAdd(x[id], y[id], (-1));
            (request--);
            (rset[(++rsiz)] = id);
          }
        } else {
          if ((Code03_Network1::pointQuery(x[id]) == request)) {
            (lset[(++lsiz)] = id);
          } else {
            (rset[(++rsiz)] = id);
          }
        }
      }
      for (int i = 1; (i <= lsiz); (i++)) {
        (eid[((el + i) - 1)] = lset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        (eid[(((el + lsiz) + i) - 1)] = rset[i]);
      }
      for (int i = 1; (i <= rsiz); (i++)) {
        int id = rset[i];
        if (((op[id] == 0) && (v[id] > mid))) {
          Code03_Network1::pathAdd(x[id], y[id], (-1));
        }
        if (((op[id] == 1) && (v[id] > mid))) {
          Code03_Network1::pathAdd(x[id], y[id], 1);
        }
      }
      Code03_Network1::compute(el, ((el + lsiz) - 1), vl, mid);
      Code03_Network1::compute((el + lsiz), er, (mid + 1), vr);
    }
  }
  static void prepare() {
    Code03_Network1::dfs2();
    for (int i = 1; (i <= m); (i++)) {
      if ((op[i] == 1)) {
        int pre = x[i];
        (x[i] = x[pre]);
        (y[i] = y[pre]);
        (v[i] = v[pre]);
      }
      if ((op[i] == 2)) {
        (y[i] = (++cntq));
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      (eid[i] = i);
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
        Code03_Network1::addEdge(u, v);
        Code03_Network1::addEdge(v, u);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      (op[i] = in.nextInt());
      (x[i] = in.nextInt());
      if ((op[i] == 0)) {
        (y[i] = in.nextInt());
        (v[i] = in.nextInt());
      }
    }
    Code03_Network1::prepare();
    Code03_Network1::compute(1, m, 0, INF);
    for (int i = 1; (i <= cntq); (i++)) {
      if ((ans[i] == 0)) {
        out.println((-1));
      } else {
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
  Code03_Network1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 网络，java版
// 一共有n个服务器，给定n-1条边，所有服务器连成一棵树
//
某两个服务器之间的路径上，可能接受一条请求，路径上的所有服务器都需要保存该请求的重要度
//
一共有m条操作，每条操作是如下3种类型中的一种，操作依次发生，第i条操作发生的时间为i
// 操作 0 x y v : x号服务器到y号服务器的路径上，增加了一个重要度为v的请求
// 操作 1 t     : 当初时间为t的操作，一定是增加请求的操作，现在这个请求结束了
// 操作 2 x     : 当前时间下，和x号服务器无关的所有请求中，打印最大的重要度
//
关于操作2，如果当前时间下，没有任何请求、或者所有请求都和x号服务器有关，打印-1
// 2 <= n <= 10^5    1 <= m <= 2 * 10^5    1 <= 重要度 <= 10^9
// 测试链接 : https://www.luogu.com.cn/problem/P3250
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 链式前向星
        // 树上点差分 + 树上倍增
        // 树状数组
        // 事件编号组成的数组
        // 如果op == 0，添加点x到点y，重要度为v的路径
        // 如果op == 1，删除点x到点y，重要度为v的路径
        // 如果op == 2，查询和x相关的答案，y表示问题的编号
        // 整体二分
        // 递归版，C++可以通过，java会爆栈
        // 不会改迭代版，去看讲解118，详解了从递归版改迭代版
        // dfs1的迭代版
        // 点x到点y的路径上，每个点增加v个请求数量
        // 查询和x点相关的请求数量
        // 读写工具类
*/
