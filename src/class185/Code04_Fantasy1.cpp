// Source: src/class185/Code04_Fantasy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Fantasy1 {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> cent = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> centfa = make_array<int>(MAXN);
  inline static Array<i64> sum = make_array<i64>(MAXN);
  inline static Array<i64> addCost = make_array<i64>(MAXN);
  inline static Array<i64> minusCost = make_array<i64>(MAXN);
  inline static Array<Array<int>> stack = make_array<int>(MAXN, 5);
  inline static int u = {};
  inline static int f = {};
  inline static int a = {};
  inline static int b = {};
  inline static int e = {};
  inline static int stacksize = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Fantasy1() {}
  static void push(int u, int f, int a, int b, int e) {
    (stack[stacksize][0] = u);
    (stack[stacksize][1] = f);
    (stack[stacksize][2] = a);
    (stack[stacksize][3] = b);
    (stack[stacksize][4] = e);
    (stacksize++);
  }
  static void pop() {
    (--stacksize);
    (u = stack[stacksize][0]);
    (f = stack[stacksize][1]);
    (a = stack[stacksize][2]);
    (b = stack[stacksize][3]);
    (e = stack[stacksize][4]);
  }
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
    (head[u] = cntg);
  }
  static void dfs1(int u, int f, int dis) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (dist[u] = dis);
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      int w = weight[e];
      if ((v != f)) {
        Code04_Fantasy1::dfs1(v, u, (dis + w));
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
    Code04_Fantasy1::dfs2(son[u], t);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((v != fa[u]) && (v != son[u]))) {
          Code04_Fantasy1::dfs2(v, v);
        }
      }
    }
  }
  static void dfs3(int cur, int father, int distance) {
    (stacksize = 0);
    Code04_Fantasy1::push(cur, father, distance, 0, (-1));
    while ((stacksize > 0)) {
      Code04_Fantasy1::pop();
      if ((e == (-1))) {
        (fa[u] = f);
        (dep[u] = (dep[f] + 1));
        (dist[u] = a);
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_Fantasy1::push(u, f, a, 0, e);
        int v = to[e];
        int w = weight[e];
        if ((v != f)) {
          Code04_Fantasy1::push(v, u, (a + w), 0, (-1));
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
    Code04_Fantasy1::push(cur, 0, 0, tag, (-1));
    while ((stacksize > 0)) {
      Code04_Fantasy1::pop();
      if ((e == (-1))) {
        (top[u] = b);
        if ((son[u] == 0)) {
          continue;
        }
        Code04_Fantasy1::push(u, 0, 0, b, (-2));
        Code04_Fantasy1::push(son[u], 0, 0, b, (-1));
        continue;
      } else if ((e == (-2))) {
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_Fantasy1::push(u, 0, 0, b, e);
        int v = to[e];
        if (((v != fa[u]) && (v != son[u]))) {
          Code04_Fantasy1::push(v, 0, 0, v, (-1));
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
    return ((dist[x] + dist[y]) - jshl(dist[Code04_Fantasy1::getLca(x, y)], 1));
  }
  static void getSize1(int u, int fa) {
    (siz[u] = 1);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if (((v != fa) && (!vis[v]))) {
        Code04_Fantasy1::getSize1(v, u);
        (siz[u] += siz[v]);
      }
    }
  }
  static void getSize2(int cur, int fa) {
    (stacksize = 0);
    Code04_Fantasy1::push(cur, fa, 0, 0, (-1));
    while ((stacksize > 0)) {
      Code04_Fantasy1::pop();
      if ((e == (-1))) {
        (siz[u] = 1);
        (e = head[u]);
      } else {
        (e = nxt[e]);
      }
      if ((e != 0)) {
        Code04_Fantasy1::push(u, f, 0, 0, e);
        int v = to[e];
        if (((v != f) && (!vis[v]))) {
          Code04_Fantasy1::push(v, u, 0, 0, (-1));
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
    Code04_Fantasy1::getSize2(u, fa);
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
        int nextCent = Code04_Fantasy1::getCentroid(v, u);
        (cent[e] = nextCent);
        Code04_Fantasy1::centroidTree(nextCent, u);
      }
    }
  }
  static void add(int x, int v) {
    (sum[x] += v);
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code04_Fantasy1::getDist(x, fa);
        (sum[fa] += v);
        (addCost[fa] += ((1LL * v) * dist));
        (minusCost[cur] += ((1LL * v) * dist));
      }
    }
  }
  static i64 query(int x) {
    i64 ans = addCost[x];
    {
      int cur = x;
      int fa = centfa[cur];
      for (; (fa > 0); (cur = fa), (fa = centfa[cur])) {
        int dist = Code04_Fantasy1::getDist(x, fa);
        (ans += addCost[fa]);
        (ans -= minusCost[cur]);
        (ans += ((sum[fa] - sum[cur]) * dist));
      }
    }
    return ans;
  }
  static i64 compute(int u) {
    i64 ans = Code04_Fantasy1::query(u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((Code04_Fantasy1::query(v) < ans)) {
        return Code04_Fantasy1::compute(cent[e]);
      }
    }
    return ans;
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
      int w = {};
      for (; (i < n); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (w = in.nextInt());
        Code04_Fantasy1::addEdge(u, v, w);
        Code04_Fantasy1::addEdge(v, u, w);
      }
    }
    Code04_Fantasy1::dfs3(1, 0, 0);
    Code04_Fantasy1::dfs4(1, 1);
    int root = Code04_Fantasy1::getCentroid(1, 0);
    Code04_Fantasy1::centroidTree(root, 0);
    {
      int i = 1;
      int x = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (x = in.nextInt());
        (v = in.nextInt());
        Code04_Fantasy1::add(x, v);
        out.println(Code04_Fantasy1::compute(root));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Fantasy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 幻想乡战略游戏，java版
// 树上有n个点，每个点的初始点权是0，给定n-1条边，每条边有边权
// 如果点x是指挥点，它指挥点y的花费 = x到y的简单路径权值和 * y的点权
// 树上存在某个最佳的指挥点，指挥所有点的总花费最小，叫做最小指挥总花费
// 一共m条操作，格式 x v : 先把x的点权增加v，然后打印此时的最小指挥总花费
// 注意参数v有可能是负数，但题目保证任何时候，点权不会出现负数
// 1 <= n、m <= 10^5
// 1 <= 边权 <= 1000
// -1000 <= v <= +1000
// 测试链接 : https://www.luogu.com.cn/problem/P3345
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 讲解118，递归函数改成迭代所需要的栈
                // getSize1(u, fa);
                // dfs1(1, 0, 0);
                // dfs2(1, 1);
        // 读写工具类
*/
