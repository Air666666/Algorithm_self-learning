// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10603

// Source: src/class185/Code02_Game1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Game1 {
  inline static int MAXN = 100001;
  inline static int MAXP = 18;
  inline static int MAXT = 20000001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<int> addTree = make_array<int>(MAXN);
  inline static Array<int> minusTree = make_array<int>(MAXN);
  inline static Array<int> ls = make_array<int>(MAXT);
  inline static Array<int> rs = make_array<int>(MAXT);
  inline static Array<int> sum = make_array<int>(MAXT);
  inline static int cntt = {};
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 3);
  inline static int u = {};
  inline static int f = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Game1() {}
  static void push(int u, int f, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (e = stack[stacksize][2]);
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
        Code02_Game1::dfs1(v, u);
      }
    }
  }
  static void dfs2(int cur, int fa) {
    (stacksize = 0);
    Code02_Game1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code02_Game1::pop();
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
        Code02_Game1::push(u, f, e);
        int v = to[e];
        if ((v != f)) {
          Code02_Game1::push(v, u, (-1));
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
  static int getDist(int x, int y) {
    return ((dep[x] + dep[y]) - jshl(dep[Code02_Game1::getLca(x, y)], 1));
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code02_Game1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code02_Game1::push(cur, fa, (-1));
    while ((stacksize > 0)) {
      Code02_Game1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code02_Game1::push(u, f, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code02_Game1::push(v, u, (-1));
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
    Code02_Game1::getSize2(u, fa);
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
        Code02_Game1::centroidTree(Code02_Game1::getCentroid(v, u), u);
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
        (ls[i] = Code02_Game1::add(jobi, jobv, l, mid, ls[i]));
      } else {
        (rs[i] = Code02_Game1::add(jobi, jobv, (mid + 1), r, rs[i]));
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
      (ans += Code02_Game1::query(jobl, jobr, l, mid, ls[i]));
    }
    if ((jobr > mid)) {
      (ans += Code02_Game1::query(jobl, jobr, (mid + 1), r, rs[i]));
    }
    return ans;
  }
  static void add(int x, int k, int v) {
    (addTree[x] = Code02_Game1::add(k, v, 0, (n - 1), addTree[x]));
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code02_Game1::getDist(x, fa);
        if (((k - dist) >= 0)) {
          (addTree[fa] =
               Code02_Game1::add((k - dist), v, 0, (n - 1), addTree[fa]));
          (minusTree[cur] =
               Code02_Game1::add((k - dist), v, 0, (n - 1), minusTree[cur]));
        }
      }
    }
  }
  static int query(int x) {
    int ans = Code02_Game1::query(0, (n - 1), 0, (n - 1), addTree[x]);
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code02_Game1::getDist(x, fa);
        (ans += Code02_Game1::query(dist, (n - 1), 0, (n - 1), addTree[fa]));
        (ans -= Code02_Game1::query(dist, (n - 1), 0, (n - 1), minusTree[cur]));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO();
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
        Code02_Game1::addEdge(u, v);
        Code02_Game1::addEdge(v, u);
      }
    }
    Code02_Game1::dfs2(1, 0);
    Code02_Game1::centroidTree(Code02_Game1::getCentroid(1, 0), 0);
    jchar op = {};
    int x = {};
    int k = {};
    int v = {};
    for (int i = 1; (i <= m); (i++)) {
      (op = in.nextTokenLastChar());
      if ((op == u'M')) {
        (x = in.nextInt());
        (k = in.nextInt());
        (v = in.nextInt());
        Code02_Game1::add(x, k, v);
      } else {
        (x = in.nextInt());
        out.println(Code02_Game1::query(x));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Game1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 烁烁的游戏，java版
// 树上有n个点，每个点的初始点权是0，给定n-1条边，边权都是1
// 接下来有m条操作，每条操作是如下两种类型中的一种
// 操作 M x k v : 点x出发，距离<=k的所有点，点权都加上v
// 操作 Q x     : 打印点x的点权
// 1 <= n、m <= 10^5
// -10000 <= v <= +10000
// 测试链接 : https://www.luogu.com.cn/problem/P10603
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
        // 树上倍增收集信息递归版，java会爆栈，C++不会
        // dfs1的迭代版
        // 找重心需要计算子树大小的递归版，java会爆栈，C++不会
        // getSize1的迭代版
                // getSize1(u, fa);
                // dfs1(1, 0);
        // 读写工具类
*/
