// Source: src/class199/Code07_ShortestDistance_java_1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_ShortestDistance_java_1 {
  inline static int MAXN = 100007;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> u = make_array<int>(MAXN);
  inline static Array<int> v = make_array<int>(MAXN);
  inline static Array<int> w = make_array<int>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static int node1 = {};
  inline static int node2 = {};
  inline static int skipEdge = {};
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_ShortestDistance_java_1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void dfs1(int u) {
    (dfn[u] = (++cntd));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code07_ShortestDistance_java_1::dfs1(v);
      } else if ((dfn[u] < dfn[v])) {
        (node1 = u);
        (node2 = v);
        (skipEdge = jshr((e + 1), 1));
      }
    }
  }
  static void dfs2(int u, int f) {
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((jshr((e + 1), 1) != skipEdge) && (v != f))) {
          Code07_ShortestDistance_java_1::dfs2(v, u);
          (siz[u] += siz[v]);
          if (((son[u] == 0) || (siz[son[u]] < siz[v]))) {
            (son[u] = v);
          }
        }
      }
    }
  }
  static void dfs3(int u, int t) {
    (top[u] = t);
    (dfn[u] = (++cntd));
    if ((son[u] != 0)) {
      Code07_ShortestDistance_java_1::dfs3(son[u], t);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((((jshr((e + 1), 1) != skipEdge) && (v != fa[u])) && (v != son[u]))) {
        Code07_ShortestDistance_java_1::dfs3(v, v);
      }
    }
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= n)) {
      (tree[i] += v);
      (i += Code07_ShortestDistance_java_1::lowbit(i));
    }
  }
  static int query(int i) {
    int ans = 0;
    while ((i >= 1)) {
      (ans += tree[i]);
      (i -= Code07_ShortestDistance_java_1::lowbit(i));
    }
    return ans;
  }
  static int sum(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    return [&]() {
      auto jleft = Code07_ShortestDistance_java_1::query(r);
      auto jright = Code07_ShortestDistance_java_1::query((l - 1));
      return (jleft - jright);
    }();
  }
  static void prepare() {
    Code07_ShortestDistance_java_1::dfs1(1);
    (cntd = 0);
    Code07_ShortestDistance_java_1::dfs2(1, 0);
    Code07_ShortestDistance_java_1::dfs3(1, 1);
    for (int i = 1; (i <= n); (i++)) {
      if ((i != skipEdge)) {
        Code07_ShortestDistance_java_1::add(jmax(dfn[u[i]], dfn[v[i]]), w[i]);
      }
    }
  }
  static void setEdge(int edge, int val) {
    if ((edge != skipEdge)) {
      Code07_ShortestDistance_java_1::add(jmax(dfn[u[edge]], dfn[v[edge]]),
                                          (val - w[edge]));
    }
    (w[edge] = val);
  }
  static int jump(int x, int y) {
    int ans = 0;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] < dep[top[y]])) {
        (ans += Code07_ShortestDistance_java_1::sum(dfn[top[y]], dfn[y]));
        (y = fa[top[y]]);
      } else {
        (ans += Code07_ShortestDistance_java_1::sum(dfn[top[x]], dfn[x]));
        (x = fa[top[x]]);
      }
    }
    if ((dfn[x] < dfn[y])) {
      (ans += Code07_ShortestDistance_java_1::sum((dfn[x] + 1), dfn[y]));
    } else {
      (ans += Code07_ShortestDistance_java_1::sum((dfn[y] + 1), dfn[x]));
    }
    return ans;
  }
  static int getDistance(int x, int y) {
    int p1 = Code07_ShortestDistance_java_1::jump(x, y);
    int p2 = [&]() {
      auto jleft =
          (Code07_ShortestDistance_java_1::jump(x, node1) + w[skipEdge]);
      auto jright = Code07_ShortestDistance_java_1::jump(node2, y);
      return (jleft + jright);
    }();
    int p3 = [&]() {
      auto jleft =
          (Code07_ShortestDistance_java_1::jump(x, node2) + w[skipEdge]);
      auto jright = Code07_ShortestDistance_java_1::jump(node1, y);
      return (jleft + jright);
    }();
    return jmin(p1, jmin(p2, p3));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (u[i] = in.nextInt());
      (v[i] = in.nextInt());
      (w[i] = in.nextInt());
      Code07_ShortestDistance_java_1::addEdge(u[i], v[i]);
      Code07_ShortestDistance_java_1::addEdge(v[i], u[i]);
    }
    Code07_ShortestDistance_java_1::prepare();
    {
      int i = 1;
      int op = {};
      int x = {};
      int y = {};
      for (; (i <= m); (i++)) {
        (op = in.nextInt());
        (x = in.nextInt());
        (y = in.nextInt());
        if ((op == 1)) {
          Code07_ShortestDistance_java_1::setEdge(x, y);
        } else {
          out.println(Code07_ShortestDistance_java_1::getDistance(x, y));
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
  Code07_ShortestDistance_java_1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最短距离，巧妙的解法，java版
// 图中有n个点、n条无向边，每条边有边权，图是一棵基环树
// 一共有m条操作，每条操作是如下两种类型中的一种
// 操作 1 x y : 第x号边的边权修改为y
// 操作 2 x y : 查询点x和点y之间的最短距离
// 1 <= n <= 10^5 + 6
// 1 <= m <= 10^5
// 0 <= 边权 <= 5000
// 测试链接 : https://www.luogu.com.cn/problem/P4949
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
