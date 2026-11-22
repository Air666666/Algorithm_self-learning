// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P6773

// Source: src/class182/Code03_Fate1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Fate1 {
  inline static int MAXN = 500001;
  inline static int MAXT = (MAXN * 40);
  inline static int MOD = 998244353;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> root = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<i64> sum = make_array<i64>(MAXT);
  inline static Array<i64> mulLazy = make_array<i64>(MAXT);
  inline static int cntt = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> maxdep = make_array<int>(MAXN);
  inline static Array<Array<int>> ufe = make_array<int>(MAXN, 3);
  inline static int stacksize = {};
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Fate1() {}
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
  static void up(int i) { (sum[i] = jrem((sum[ls[i]] + sum[rs[i]]), MOD)); }
  static void lazy(int i, i64 v) {
    if ((i != 0)) {
      (sum[i] = jrem((sum[i] * v), MOD));
      (mulLazy[i] = jrem((mulLazy[i] * v), MOD));
    }
  }
  static void down(int i) {
    if ((mulLazy[i] != 1)) {
      Code03_Fate1::lazy(ls[i], mulLazy[i]);
      Code03_Fate1::lazy(rs[i], mulLazy[i]);
      (mulLazy[i] = 1);
    }
  }
  static int insert(int jobi, int l, int r, int i) {
    int rt = i;
    if ((rt == 0)) {
      (rt = (++cntt));
      (mulLazy[rt] = 1);
    }
    if ((l == r)) {
      (sum[rt] = 1);
    } else {
      Code03_Fate1::down(rt);
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[rt] = Code03_Fate1::insert(jobi, l, mid, ls[rt]));
      } else {
        (rs[rt] = Code03_Fate1::insert(jobi, (mid + 1), r, rs[rt]));
      }
      Code03_Fate1::up(rt);
    }
    return rt;
  }
  static i64 query(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return jrem(sum[i], MOD);
    }
    Code03_Fate1::down(i);
    int mid = jshr((l + r), 1);
    i64 ans = 0;
    if ((jobl <= mid)) {
      (ans = Code03_Fate1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ans = jrem((ans + Code03_Fate1::query(jobl, jobr, (mid + 1), r, rs[i])),
                  MOD));
    }
    return ans;
  }
  static int merge(int l, int r, int t1, int t2, i64 sum1, i64 sum2) {
    if (((t1 == 0) || (t2 == 0))) {
      if ((t1 != 0)) {
        Code03_Fate1::lazy(t1, sum2);
      }
      if ((t2 != 0)) {
        Code03_Fate1::lazy(t2, sum1);
      }
      return (t1 + t2);
    }
    if ((l == r)) {
      (sum[t1] = jrem((jrem((sum[t1] * (sum2 + sum[t2])), MOD) +
                       jrem((sum[t2] * sum1), MOD)),
                      MOD));
    } else {
      Code03_Fate1::down(t1);
      Code03_Fate1::down(t2);
      int mid = jshr((l + r), 1);
      i64 tmp1 = sum[ls[t1]];
      i64 tmp2 = sum[ls[t2]];
      (ls[t1] = Code03_Fate1::merge(l, mid, ls[t1], ls[t2], sum1, sum2));
      (rs[t1] = Code03_Fate1::merge((mid + 1), r, rs[t1], rs[t2], (sum1 + tmp1),
                                    (sum2 + tmp2)));
      Code03_Fate1::up(t1);
    }
    return t1;
  }
  static void dfs1(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code03_Fate1::dfs1(v, u);
      }
    }
  }
  static void dfs2() {
    (stacksize = 0);
    Code03_Fate1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_Fate1::pop();
      if ((e == (-1))) {
        (dep[u] = (dep[f] + 1));
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Fate1::push(u, f, e);
        if ((to[e] != f)) {
          Code03_Fate1::push(to[e], u, (-1));
        }
      }
    }
  }
  static void dp1(int u, int fa) {
    (root[u] = Code03_Fate1::insert(maxdep[u], 0, n, root[u]));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code03_Fate1::dp1(v, u);
        (root[u] = Code03_Fate1::merge(
             0, n, root[u], root[v], 0,
             Code03_Fate1::query(0, dep[u], 0, n, root[v])));
      }
    }
  }
  static void dp2() {
    (stacksize = 0);
    Code03_Fate1::push(1, 0, (-1));
    while ((stacksize > 0)) {
      Code03_Fate1::pop();
      if ((e == (-1))) {
        (root[u] = Code03_Fate1::insert(maxdep[u], 0, n, root[u]));
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code03_Fate1::push(u, f, e);
        if ((to[e] != f)) {
          Code03_Fate1::push(to[e], u, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (root[u] = Code03_Fate1::merge(
                 0, n, root[u], root[v], 0,
                 Code03_Fate1::query(0, dep[u], 0, n, root[v])));
          }
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code03_Fate1::addEdge(u, v);
        Code03_Fate1::addEdge(v, u);
      }
    }
    Code03_Fate1::dfs2();
    (m = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (maxdep[y] = jmax(maxdep[y], dep[x]));
      }
    }
    Code03_Fate1::dp2();
    i64 ans = jrem(Code03_Fate1::query(0, 0, 0, n, root[1]), MOD);
    out.println(ans);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_Fate1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 命运，java版
// 一共有n个节点，给定n-1条边，所有节点组成一棵树，规定1号节点是树头
// 给定m个点对，每个点对(x, y)，x是y的祖先节点，路径由从上到下的边组成
// 树上的每条边都要涂上白色或者黑色，完全由你决定
// 但是请保证每个点对的路径中，至少有一条黑色的边存在
// 打印给树涂色的方法数，答案对 998244353 取模
// 1 <= n、m <= 5 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P6773
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归改迭代需要的栈
        // 递归版，java会爆栈，C++可以通过
        // dfs1的迭代版
        // 递归版，java会爆栈，C++可以通过
        // dp1的迭代版
                // dfs1(1, 0);
                // dp1(1, 0);
        // 读写工具类
*/
