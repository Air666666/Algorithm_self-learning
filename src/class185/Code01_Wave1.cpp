// Source: src/class185/Code01_Wave1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_Wave1 {
  inline static int MAXN = 100001;
  inline static int MAXT = 10000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<int> addTree = make_array<int>(MAXN);
  inline static Array<int> minusTree = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 4);
  inline static int u = {};
  inline static int f = {};
  inline static int t = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_Wave1() {}
  static void push(int u, int f, int t, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = t);
    (stack[stacksize][3] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (t = stack[stacksize][2]);
    (e = stack[stacksize][3]);
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code01_Wave1::dfs1(v, u);
        }
      }
    }
    {
      int ei = head[u];
      int v = {};
      for (; (ei > 0); (ei = nxt[ei])) {
        (v = to[ei]);
        if ((v != f)) {
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs2(int u, int t) {
    (top[u] = t);
    if ((son[u] == 0)) {
      return;
    }
    Code01_Wave1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_Wave1::dfs2(v, v);
        }
      }
    }
  }
  static void dfs3(int cur, int father) {
    (stacksize = 0);
    Code01_Wave1::push(cur, father, 0, (-1));
    while ((stacksize > 0)) {
      Code01_Wave1::pop();
      if ((e == (-1))) {
        (fa[u] = f);
        (dep[u] = (dep[f] + 1));
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code01_Wave1::push(u, f, 0, e);
        int v = to[e];
        if ((v != f)) {
          Code01_Wave1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if ((v != f)) {
            (siz[u] += siz[v]);
            if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
              (son[u] = v);
            }
          }
        }
      }
    }
  }
  static void dfs4(int cur, int tag) {
    (stacksize = 0);
    Code01_Wave1::push(cur, 0, tag, (-1));
    while ((stacksize > 0)) {
      Code01_Wave1::pop();
      if ((e == (-1))) {
        (top[u] = t);
        if ((son[u] == 0)) {
          continue;
        }
        Code01_Wave1::push(u, 0, t, (-2));
        Code01_Wave1::push(son[u], 0, t, (-1));
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code01_Wave1::push(u, 0, t, e);
        int v = to[e];
        if (((v != fa[u]) && (v != son[u]))) {
          Code01_Wave1::push(v, 0, v, (-1));
        }
      }
    }
  }
  static int getLca(int a, int b) {
    while ((top[a] != top[b])) {
      if ((dep[top[a]] <= dep[top[b]])) {
        (b = fa[top[b]]);
      } else {
        (a = fa[top[a]]);
      }
    }
    return ((dep[a] <= dep[b]) ? a : b);
  }
  static int getDist(int x, int y) {
    return ((dep[x] + dep[y]) - jshl(dep[Code01_Wave1::getLca(x, y)], 1));
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code01_Wave1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code01_Wave1::push(cur, fa, 0, (-1));
    while ((stacksize > 0)) {
      Code01_Wave1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code01_Wave1::push(u, f, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code01_Wave1::push(v, u, 0, (-1));
        }
      } else {
        for (int ei = head[u]; (ei > 0); (ei = nxt[ei])) {
          int v = to[ei];
          if (((v != f) && (!vis[v]))) {
            (siz[u] += siz[v]);
          }
        }
      }
    }
  }
  static int getCentroid(int u, int fa) {
    Code01_Wave1::getSize2(u, fa);
    int half = jshr(siz[u], 1);
    bool find = false;
    while ((!find)) {
      (find = true);
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((((v != fa) && (!vis[v])) && (siz[v] > half))) {
          (fa = u);
          (u = v);
          (find = false);
          break;
        }
      }
    }
    return u;
  }
  static void centroidTree(int u, int fa) {
    (centfa[u] = fa);
    (vis[u] = true);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((!vis[v])) {
        Code01_Wave1::centroidTree(Code01_Wave1::getCentroid(v, u), u);
      }
    }
  }
  static int add(int jobi, int jobv, int l, int r, int i) {
    if ((i == 0)) {
      (i = (++cntt));
    }
    if ((l == r)) {
      (sum[i] += jobv);
    } else {
      int mid = jshr((l + r), 1);
      if ((jobi <= mid)) {
        (ls[i] = Code01_Wave1::add(jobi, jobv, l, mid, ls[i]));
      } else {
        (rs[i] = Code01_Wave1::add(jobi, jobv, (mid + 1), r, rs[i]));
      }
      (sum[i] = (sum[ls[i]] + sum[rs[i]]));
    }
    return i;
  }
  static int query(int jobl, int jobr, int l, int r, int i) {
    if ((i == 0)) {
      return 0;
    }
    if (((jobl <= l) && (r <= jobr))) {
      return sum[i];
    }
    int mid = jshr((l + r), 1);
    int ans = 0;
    if ((jobl <= mid)) {
      (ans += Code01_Wave1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ans += Code01_Wave1::query(jobl, jobr, (mid + 1), r, rs[i]));
    }
    return ans;
  }
  static void add(int x, int v) {
    (addTree[x] = Code01_Wave1::add(0, v, 0, (n - 1), addTree[x]));
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code01_Wave1::getDist(x, fa);
        (addTree[fa] = Code01_Wave1::add(dist, v, 0, (n - 1), addTree[fa]));
        (minusTree[cur] =
             Code01_Wave1::add(dist, v, 0, (n - 1), minusTree[cur]));
      }
    }
  }
  static int query(int x, int k) {
    int ans = Code01_Wave1::query(0, k, 0, (n - 1), addTree[x]);
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code01_Wave1::getDist(x, fa);
        if (((k - dist) >= 0)) {
          (ans += Code01_Wave1::query(0, (k - dist), 0, (n - 1), addTree[fa]));
          (ans -=
           Code01_Wave1::query(0, (k - dist), 0, (n - 1), minusTree[cur]));
        }
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (arr[i] = in.nextInt());
    }
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code01_Wave1::addEdge(u, v);
        Code01_Wave1::addEdge(v, u);
      }
    }
    Code01_Wave1::dfs3(1, 0);
    Code01_Wave1::dfs4(1, 1);
    Code01_Wave1::centroidTree(Code01_Wave1::getCentroid(1, 0), 0);
    for (int i = 1; (i <= n); (i++)) {
      Code01_Wave1::add(i, arr[i]);
    }
    int lastAns = 0;
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        (x ^= lastAns);
        (y ^= lastAns);
        if ((op == 0)) {
          (lastAns = Code01_Wave1::query(x, y));
          out.println(lastAns);
        } else {
          Code01_Wave1::add(x, (y - arr[x]));
          (arr[x] = y);
        }
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code01_Wave1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 震波，java版
// 树上有n个点，每个点有点权，给定n-1条边，边权都是1
// 接下来有m条操作，每条操作是如下两种类型中的一种
// 操作 0 x y : 点x出发，距离<=y的所有点，打印点权累加和
// 操作 1 x y : 点x的点权变成y
// 1 <= n、m <= 10^5
// 1 <= 点权 <= 10^4
// 本题要求强制在线，得到操作参数的规则，打开测试链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P6329
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 重链剖分收集信息递归版，java会爆栈，C++不会
        // 根据重儿子剖分的递归版，java会爆栈，C++不会
        // dfs1改成迭代版
        // dfs2改成迭代版
        // 找重心需要计算子树大小的递归版，java会爆栈，C++不会
        // getSize1的迭代版
                // getSize1(u, fa);
                // dfs1(1, 0);
                // dfs2(1, 1);
        // 读写工具类
*/
