// Source: src/class181/Code03_RainyDayTail1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_RainyDayTail1 {
  inline static int MAXN = 100001;
  inline static int MAXV = 100000;
  inline static int MAXT = (MAXN * 50);
  inline static int MAXP = 20;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> maxCnt = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static Array<int> ans = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_RainyDayTail1() {}
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
        Code03_RainyDayTail1::dfs1(v, u);
      }
    }
  }
  static void dfs2() {
    (stacksize = 0);
    Code03_RainyDayTail1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_RainyDayTail1::pop();
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
        Code03_RainyDayTail1::push(u, f, e);
        if ((to[e] != f)) {
          Code03_RainyDayTail1::push(to[e], u, (-1));
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
  static void up(int i) { (maxCnt[i] = jmax(maxCnt[ls[i]], maxCnt[rs[i]])); }
  static int add(int jobi, int jobv, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
    }
    if ((l == r)) {
      (maxCnt[rt] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code03_RainyDayTail1::add(jobi, jobv, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code03_RainyDayTail1::add(jobi, jobv, (mid + 1), r, rs[rt]));
      }
      Code03_RainyDayTail1::up(rt);
    }
    return rt;
  }
  static int merge(int l, int r, int t1, int t2) {
    if (((t1 == 0) || (t2 == 0))) {
      return (t1 + t2);
    }
    if ((l == r)) {
      (maxCnt[t1] += maxCnt[t2]);
    } else {
      int mid = jshr((l + r), 1);
      (ls[t1] = Code03_RainyDayTail1::merge(l, mid, ls[t1], ls[t2]));
      (rs[t1] = Code03_RainyDayTail1::merge((mid + 1), r, rs[t1], rs[t2]));
      Code03_RainyDayTail1::up(t1);
    }
    return t1;
  }
  static int query(int l, int r, int i) {
    if ((l == r)) {
      return l;
    }
    int mid = jshr((l + r), 1);
    if ((maxCnt[ls[i]] >= maxCnt[rs[i]])) {
      return Code03_RainyDayTail1::query(l, mid, ls[i]);
    } else {
      return Code03_RainyDayTail1::query((mid + 1), r, rs[i]);
    }
  }
  static void calc1(int u, int fa) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code03_RainyDayTail1::calc1(v, u);
        (root[u] = Code03_RainyDayTail1::merge(1, MAXV, root[u], root[v]));
      }
    }
    if ((maxCnt[root[u]] == 0)) {
      (ans[u] = 0);
    } else {
      (ans[u] = Code03_RainyDayTail1::query(1, MAXV, root[u]));
    }
  }
  static void calc2() {
    (stacksize = 0);
    Code03_RainyDayTail1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_RainyDayTail1::pop();
      if ((e == (-1))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_RainyDayTail1::push(u, f, e);
        if ((to[e] != f)) {
          Code03_RainyDayTail1::push(to[e], u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (root[u] = Code03_RainyDayTail1::merge(1, MAXV, root[u], root[v]));
          }
        }
        if ((maxCnt[root[u]] == 0)) {
          (ans[u] = 0);
        } else {
          (ans[u] = Code03_RainyDayTail1::query(1, MAXV, root[u]));
        }
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
        Code03_RainyDayTail1::addEdge(u, v);
        Code03_RainyDayTail1::addEdge(v, u);
      }
    }
    Code03_RainyDayTail1::dfs2();
    for (int i = 1; (i <= m); (i++)) {
      int x = in.nextInt();
      int y = in.nextInt();
      int v = in.nextInt();
      int lca = Code03_RainyDayTail1::getLca(x, y);
      int lcafa = stjump[lca][0];
      (root[x] = Code03_RainyDayTail1::add(v, 1, 1, MAXV, root[x]));
      (root[y] = Code03_RainyDayTail1::add(v, 1, 1, MAXV, root[y]));
      (root[lca] = Code03_RainyDayTail1::add(v, (-1), 1, MAXV, root[lca]));
      (root[lcafa] = Code03_RainyDayTail1::add(v, (-1), 1, MAXV, root[lcafa]));
    }
    Code03_RainyDayTail1::calc2();
    for (int i = 1; (i <= n); (i++)) {
      out.println(ans[i]);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_RainyDayTail1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 雨天的尾巴，java版
// 一共有n个节点，给定n-1条边，所有节点组成一棵树
// 给定m条路径，格式 x y v，表示x到y路径上的每个点都收到一个数字v
// 打印第i号点上，收到次数最多的数字，如果不止一种，打印值最小的数字
// 如果某节点没有收到过数字，打印0
// 一共n条打印
// 1 <= n、m、v <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P4556
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
