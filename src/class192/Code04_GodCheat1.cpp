// Source: src/class192/Code04_GodCheat1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_GodCheat1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 50001;
  inline static int MAXP = 15;
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<Array<int>> edgeArr = make_array<int>(MAXM, 2);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int ebccCnt = {};
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_GodCheat1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void buildGraph() {
    j::sort(edgeArr, 1, (m + 1), [=](Array<int> a, Array<int> b) {
      return ((a[0] != b[0]) ? (a[0] - b[0]) : (a[1] - b[1]));
    });
    int k = 1;
    for (int i = 2; (i <= m); (i++)) {
      if (((edgeArr[k][0] != edgeArr[i][0]) ||
           (edgeArr[k][1] != edgeArr[i][1]))) {
        (edgeArr[(++k)][0] = edgeArr[i][0]);
        (edgeArr[k][1] = edgeArr[i][1]);
      }
    }
    for (int i = 1; (i <= k); (i++)) {
      Code04_GodCheat1::addEdge(edgeArr[i][0], edgeArr[i][1]);
      Code04_GodCheat1::addEdge(edgeArr[i][1], edgeArr[i][0]);
    }
    (m = k);
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code04_GodCheat1::tarjan(v, e);
        (low[u] = jmin(low[u], low[v]));
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
    if ((dfn[u] == low[u])) {
      (ebccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = ebccCnt);
      } while ((pop != u));
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= ebccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int ebcc1 = belong[edgeArr[i][0]];
      int ebcc2 = belong[edgeArr[i][1]];
      if ((ebcc1 != ebcc2)) {
        Code04_GodCheat1::addEdge(ebcc1, ebcc2);
        Code04_GodCheat1::addEdge(ebcc2, ebcc1);
      }
    }
  }
  static void dfs(int u, int fa) {
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code04_GodCheat1::dfs(v, u);
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
    return ((dep[x] + dep[y]) - (2 * dep[Code04_GodCheat1::getLca(x, y)]));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        (edgeArr[i][0] = jmin(u, v));
        (edgeArr[i][1] = jmax(u, v));
      }
    }
    Code04_GodCheat1::buildGraph();
    Code04_GodCheat1::tarjan(1, 0);
    Code04_GodCheat1::condense();
    Code04_GodCheat1::dfs(1, 0);
    (q = in.nextInt());
    {
      int i = 1;
      int x = {};
      int y = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (x = belong[x]);
        (y = belong[y]);
        out.println(binaryString((Code04_GodCheat1::getDist(x, y) + 1)));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_GodCheat1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 神会作弊，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通，两点间出现重边只连一次
// 边双连通分量缩点后，如果点x和点y属于同一个边双连通分量，认为两点距离是1
// 如果不属于同一个边双连通分量，距离为缩点后的树上，两点简单路径上的节点个数
// 一共有q条查询，格式 x y : 计算点x和点y的距离，打印距离的二进制形式
// 1 <= n <= 10000
// 1 <= m <= 50000
// 测试链接 : https://www.luogu.com.cn/problem/P2783
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
