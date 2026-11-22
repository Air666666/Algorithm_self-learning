// Source: src/class121/Code04_Patrol.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_Patrol {
  inline static int MAXN = 100001;
  inline static int n = {};
  inline static int k = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> next = make_array<int>(jshl(MAXN, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXN, 1));
  inline static int cnt = {};
  inline static int start = {};
  inline static int end = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static Array<int> last = make_array<int>(MAXN);
  inline static int diameter1 = {};
  inline static int diameter2 = {};
  inline static Array<bool> diameterPath = make_array<bool>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_Patrol() {}
  static void build() {
    (cnt = 1);
    j::fill(head, 1, (n + 1), 0);
    (diameter1 = 0);
    (diameter2 = 0);
    j::fill(diameterPath, 1, n, false);
  }
  static void addEdge(int u, int v) {
    (next[cnt] = head[u]);
    (to[cnt] = v);
    (head[u] = (cnt++));
  }
  static void road() {
    Code04_Patrol::dfs(1, 0, 0);
    (start = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[start])) {
        (start = i);
      }
    }
    Code04_Patrol::dfs(start, 0, 0);
    (end = 1);
    for (int i = 2; (i <= n); (i++)) {
      if ((dist[i] > dist[end])) {
        (end = i);
      }
    }
    (diameter1 = dist[end]);
  }
  static void dfs(int u, int f, int w) {
    (last[u] = f);
    (dist[u] = (dist[f] + w));
    for (int e = head[u]; (e != 0); (e = next[e])) {
      if ((to[e] != f)) {
        Code04_Patrol::dfs(to[e], u, 1);
      }
    }
  }
  static void dp(int u, int f) {
    {
      int e = head[u];
      int v = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          Code04_Patrol::dp(v, u);
        }
      }
    }
    {
      int e = head[u];
      int v = {};
      int w = {};
      for (; (e != 0); (e = next[e])) {
        (v = to[e]);
        if ((v != f)) {
          (w = ((diameterPath[u] && diameterPath[v]) ? (-1) : 1));
          (diameter2 = jmax(diameter2, ((dist[u] + dist[v]) + w)));
          (dist[u] = jmax(dist[u], (dist[v] + w)));
        }
      }
    }
  }
  static void java_main(Array<String> args) {
    IO br = IO(IO(jin));
    Tokenizer in = Tokenizer(br);
    IO out = IO(IO(jout));
    in.nextToken();
    (n = static_cast<int>(in.nval));
    in.nextToken();
    (k = static_cast<int>(in.nval));
    Code04_Patrol::build();
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i < n); (i++)) {
        in.nextToken();
        (u = static_cast<int>(in.nval));
        in.nextToken();
        (v = static_cast<int>(in.nval));
        Code04_Patrol::addEdge(u, v);
        Code04_Patrol::addEdge(v, u);
      }
    }
    out.println(Code04_Patrol::compute());
    out.flush();
    out.close();
    br.close();
  }
  static int compute() {
    Code04_Patrol::road();
    if ((k == 1)) {
      return (((2 * (n - 1)) - diameter1) + 1);
    } else {
      for (int i = end; (i != 0); (i = last[i])) {
        (diameterPath[i] = true);
      }
      j::fill(dist, 1, (n + 1), 0);
      Code04_Patrol::dp(1, 0);
      return ((((2 * (n - 1)) - diameter1) - diameter2) + 2);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_Patrol::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 巡逻
// 一共n个节点，编号1~n，结构是一棵树，每条边都是双向的
// 警察局在1号点，警车每天从1号点出发，一定要走过树上所有的边，最后回到1号点
// 现在为了减少经过边的数量，你可以新建k条边，把树上任意两点直接相连
// 并且每天警车必须经过新建的道路正好一次
// 计算出最佳的新建道路的方案，返回巡逻走边数量的最小值
// 测试链接 : https://www.luogu.com.cn/problem/P3629
// 1 <= n <= 10^5
// 1 <= k <= 2
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有用例
        // 树型dp第二次求直径长度
*/
