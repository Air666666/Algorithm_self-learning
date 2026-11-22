// Source: src/class199/Code07_ShortestDistance_java_2.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_ShortestDistance_java_2 {
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
  inline static Array<int> from = make_array<int>(MAXN);
  inline static Array<bool> cycle = make_array<bool>(MAXN);
  inline static Array<int> arr = make_array<int>(MAXN);
  inline static int cnta = {};
  inline static Array<int> cycleEdgeTo = make_array<int>(MAXN);
  inline static Array<int> cycleId = make_array<int>(MAXN);
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> siz = make_array<int>(MAXN);
  inline static Array<int> son = make_array<int>(MAXN);
  inline static Array<int> top = make_array<int>(MAXN);
  inline static Array<int> tree = make_array<int>(jshl(MAXN, 1));
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_ShortestDistance_java_2() {}
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
        (from[v] = u);
        (cycleEdgeTo[jshr((e + 1), 1)] = v);
        Code07_ShortestDistance_java_2::dfs1(v);
      } else if ((dfn[u] < dfn[v])) {
        (cycleEdgeTo[jshr((e + 1), 1)] = u);
        (cycle[u] = true);
        (arr[(++cnta)] = u);
        for (int i = v; (i != u); (i = from[i])) {
          (cycle[i] = true);
          (arr[(++cnta)] = i);
        }
      }
    }
  }
  static void dfs2(int u, int f, int h) {
    (belong[u] = h);
    (fa[u] = f);
    (dep[u] = (dep[f] + 1));
    (siz[u] = 1);
    {
      int e = head[u];
      int v = {};
      for (; (e > 0); (e = nxt[e])) {
        (v = to[e]);
        if (((!cycle[v]) && (v != f))) {
          Code07_ShortestDistance_java_2::dfs2(v, u, h);
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
      Code07_ShortestDistance_java_2::dfs3(son[u], t);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((((!cycle[v]) && (v != fa[u])) && (v != son[u]))) {
        Code07_ShortestDistance_java_2::dfs3(v, v);
      }
    }
  }
  static int lowbit(int i) { return (i & (-i)); }
  static void add(int i, int v) {
    while ((i <= cntd)) {
      (tree[i] += v);
      (i += Code07_ShortestDistance_java_2::lowbit(i));
    }
  }
  static int query(int i) {
    int ans = 0;
    while ((i >= 1)) {
      (ans += tree[i]);
      (i -= Code07_ShortestDistance_java_2::lowbit(i));
    }
    return ans;
  }
  static int sum(int l, int r) {
    if ((l > r)) {
      return 0;
    }
    return [&]() {
      auto jleft = Code07_ShortestDistance_java_2::query(r);
      auto jright = Code07_ShortestDistance_java_2::query((l - 1));
      return (jleft - jright);
    }();
  }
  static int edgeToNode(int i) {
    if ((cycle[u[i]] && cycle[v[i]])) {
      return cycleId[cycleEdgeTo[i]];
    } else {
      return jmax(dfn[u[i]], dfn[v[i]]);
    }
  }
  static void prepare() {
    Code07_ShortestDistance_java_2::dfs1(1);
    (cntd = 0);
    for (int i = 1; (i <= cnta); (i++)) {
      Code07_ShortestDistance_java_2::dfs2(arr[i], 0, arr[i]);
      Code07_ShortestDistance_java_2::dfs3(arr[i], arr[i]);
    }
    for (int i = 1; (i <= cnta); (i++)) {
      (cycleId[arr[i]] = (++cntd));
    }
    for (int i = 1; (i <= n); (i++)) {
      Code07_ShortestDistance_java_2::add(
          Code07_ShortestDistance_java_2::edgeToNode(i), w[i]);
    }
  }
  static void setEdge(int edge, int val) {
    Code07_ShortestDistance_java_2::add(
        Code07_ShortestDistance_java_2::edgeToNode(edge), (val - w[edge]));
    (w[edge] = val);
  }
  static int jump(int x, int y) {
    int ans = 0;
    while ((top[x] != top[y])) {
      if ((dep[top[x]] < dep[top[y]])) {
        (ans += Code07_ShortestDistance_java_2::sum(dfn[top[y]], dfn[y]));
        (y = fa[top[y]]);
      } else {
        (ans += Code07_ShortestDistance_java_2::sum(dfn[top[x]], dfn[x]));
        (x = fa[top[x]]);
      }
    }
    if ((dfn[x] < dfn[y])) {
      (ans += Code07_ShortestDistance_java_2::sum((dfn[x] + 1), dfn[y]));
    } else {
      (ans += Code07_ShortestDistance_java_2::sum((dfn[y] + 1), dfn[x]));
    }
    return ans;
  }
  static int getDistance(int x, int y) {
    if ((belong[x] == belong[y])) {
      return Code07_ShortestDistance_java_2::jump(x, y);
    } else {
      int a = jmin(cycleId[belong[x]], cycleId[belong[y]]);
      int b = jmax(cycleId[belong[x]], cycleId[belong[y]]);
      int p1 = Code07_ShortestDistance_java_2::sum(a, (b - 1));
      int p2 = (Code07_ShortestDistance_java_2::sum((n + 1), cntd) - p1);
      return [&]() {
        auto jleft = [&]() {
          auto jleft = Code07_ShortestDistance_java_2::jump(x, belong[x]);
          auto jright = Code07_ShortestDistance_java_2::jump(y, belong[y]);
          return (jleft + jright);
        }();
        auto jright = jmin(p1, p2);
        return (jleft + jright);
      }();
    }
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
      Code07_ShortestDistance_java_2::addEdge(u[i], v[i]);
      Code07_ShortestDistance_java_2::addEdge(v[i], u[i]);
    }
    Code07_ShortestDistance_java_2::prepare();
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
          Code07_ShortestDistance_java_2::setEdge(x, y);
        } else {
          out.println(Code07_ShortestDistance_java_2::getDistance(x, y));
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
  Code07_ShortestDistance_java_2::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 最短距离，好想的解法，java版
// 图中有n个点、n条无向边，每条边有边权，图是一棵基环树
// 一共有m条操作，每条操作是如下两种类型中的一种
// 操作 1 x y : 第x号边的边权修改为y
// 操作 2 x y : 查询点x和点y之间的最短距离
// 1 <= n <= 10^5 + 6
// 1 <= m <= 10^5
// 0 <= 边权 <= 5000
// 测试链接 : https://www.luogu.com.cn/problem/P4949
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 基环树找环
        // 环上的边，确定归属，不是环上的边，这个信息没用
        // 环上的点依次分配编号，继续cntd自增获得编号
        // 记录每个节点属于哪棵分树，分树的头一定是环上节点
        // 树链剖分
        // 所有分树节点的dfn序号范围[1, n]
        // 环上节点会额外再次编号，范围[n+1, cntd]
        // 读写工具类
*/
