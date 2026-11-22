// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1967

// Source: src/class119/Code02_Trucking.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_Trucking {
  inline static int MAXN = 10001;
  inline static int MAXM = 50001;
  inline static int LIMIT = 21;
  inline static int power = {};
  inline static Array<Array<int>> edges = make_array<int>(MAXM, 3);
  inline static Array<int> father = make_array<int>(MAXN);
  inline static Array<bool> visited = make_array<bool>(MAXN);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXM, 1));
  inline static int cnt = {};
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, LIMIT);
  inline static Array<Array<int>> stmin = make_array<int>(MAXN, LIMIT);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_Trucking() {}
  static int log2(int n) {
    int ans = 0;
    while ((jshl(1, ans) <= jshr(n, 1))) {
      (ans++);
    }
    return ans;
  }
  static void build(int n) {
    (power = Code02_Trucking::log2(n));
    (cnt = 1);
    for (int i = 1; (i <= n); (i++)) {
      (father[i] = i);
    }
    j::fill(visited, 1, (n + 1), false);
    j::fill(head, 1, (n + 1), 0);
  }
  static void kruskal(int n, int m) {
    j::sort(edges, 1, (m + 1),
            [=](Array<int> a, Array<int> b) { return (b[2] - a[2]); });
    {
      int i = 1;
      int a = {};
      int b = {};
      int fa = {};
      int fb = {};
      for (; (i <= m); (i++)) {
        (a = edges[i][0]);
        (b = edges[i][1]);
        (fa = Code02_Trucking::find(a));
        (fb = Code02_Trucking::find(b));
        if ((fa != fb)) {
          (father[fa] = fb);
          Code02_Trucking::addEdge(a, b, edges[i][2]);
          Code02_Trucking::addEdge(b, a, edges[i][2]);
        }
      }
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code02_Trucking::find(father[i]));
    }
    return father[i];
  }
  static void addEdge(int u, int v, int w) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (weight[cnt] = w);
    (head[u] = (cnt++));
  }
  static void dfs(int u, int w, int f) {
    (visited[u] = true);
    if ((f == 0)) {
      (deep[u] = 1);
      (stjump[u][0] = u);
      (stmin[u][0] = std::numeric_limits<int>::max());
    } else {
      (deep[u] = (deep[f] + 1));
      (stjump[u][0] = f);
      (stmin[u][0] = w);
    }
    for (int p = 1; (p <= power); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
      (stmin[u][p] =
           jmin(stmin[u][(p - 1)], stmin[stjump[u][(p - 1)]][(p - 1)]));
    }
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((!visited[to[e]])) {
        Code02_Trucking::dfs(to[e], weight[e], u);
      }
    }
  }
  static int lca(int a, int b) {
    if ([&]() {
          auto jleft = Code02_Trucking::find(a);
          auto jright = Code02_Trucking::find(b);
          return (jleft != jright);
        }()) {
      return (-1);
    }
    if ((deep[a] < deep[b])) {
      int tmp = a;
      (a = b);
      (b = tmp);
    }
    int ans = std::numeric_limits<int>::max();
    for (int p = power; (p >= 0); (p--)) {
      if ((deep[stjump[a][p]] >= deep[b])) {
        (ans = jmin(ans, stmin[a][p]));
        (a = stjump[a][p]);
      }
    }
    if ((a == b)) {
      return ans;
    }
    for (int p = power; (p >= 0); (p--)) {
      if ((stjump[a][p] != stjump[b][p])) {
        (ans = jmin(ans, jmin(stmin[a][p], stmin[b][p])));
        (a = stjump[a][p]);
        (b = stjump[b][p]);
      }
    }
    (ans = jmin(ans, jmin(stmin[a][0], stmin[b][0])));
    return ans;
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    int n = static_cast<int>(in.nval);
    in.nextToken();
    int m = static_cast<int>(in.nval);
    for (int i = 1; (i <= m); (i++)) {
      in.nextToken();
      (edges[i][0] = static_cast<int>(in.nval));
      in.nextToken();
      (edges[i][1] = static_cast<int>(in.nval));
      in.nextToken();
      (edges[i][2] = static_cast<int>(in.nval));
    }
    Code02_Trucking::build(n);
    Code02_Trucking::kruskal(n, m);
    for (int i = 1; (i <= n); (i++)) {
      if ((!visited[i])) {
        Code02_Trucking::dfs(i, 0, 0);
      }
    }
    in.nextToken();
    int q = static_cast<int>(in.nval);
    {
      int i = 1;
      int a = {};
      int b = {};
      for (; (i <= q); (i++)) {
        in.nextToken();
        (a = static_cast<int>(in.nval));
        in.nextToken();
        (b = static_cast<int>(in.nval));
        out.println(Code02_Trucking::lca(a, b));
      }
    }
    out.flush();
    out.close();
    br.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code02_Trucking::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 货车运输
// 一共有n座城市，编号1 ~ n
// 一共有m条双向道路，每条道路(u, v, w)表示有一条限重为w，从u到v的双向道路
// 从一点到另一点的路途中，汽车载重不能超过每一条道路的限重
// 每条查询(a, b)表示从a到b的路线中，汽车允许的最大载重是多少
// 如果从a到b无法到达，那么认为答案是-1
// 一共有q条查询，返回答案数组
// 1 <= n <= 10^4
// 1 <= m <= 5 * 10^4
// 1 <= q <= 3 * 10^4
// 0 <= w <= 10^5
// 1 <= u, v, a, b <= n
// 测试链接 : https://www.luogu.com.cn/problem/P1967
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过
        // 并查集
        // 给的树有可能是森林，所以需要判断节点是否访问过了
        // 最大生成树建图
        // stjump[u][p] : u节点往上跳2的次方步，到达什么节点
        // stmin[u][p] : u节点往上跳2的次方步的路径中，最小的权值
*/
