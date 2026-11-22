// 原题测试 / 参考链接（保留上游原始地址）
// https://acm.hdu.edu.cn/showproblem.php?pid=2460
// http://poj.org/problem?id=3694

// Source: src/class191/Code06_Network1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Network1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
  inline static int q = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
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
  inline static Array<int> up = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<int> fa = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Network1() {}
  static void prepare() {
    (cntg = 1);
    (cntd = (top = (ebccCnt = 0)));
    for (int i = 1; (i <= n); (i++)) {
      (head[i] = (dfn[i] = (low[i] = 0)));
    }
  }
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
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
        Code06_Network1::tarjan(v, e);
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
      int ebcc1 = belong[a[i]];
      int ebcc2 = belong[b[i]];
      if ((ebcc1 != ebcc2)) {
        Code06_Network1::addEdge(ebcc1, ebcc2);
        Code06_Network1::addEdge(ebcc2, ebcc1);
      }
    }
  }
  static void dfs(int u, int f) {
    (dep[u] = (dep[f] + 1));
    (up[u] = f);
    (fa[u] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != f)) {
        Code06_Network1::dfs(v, u);
      }
    }
  }
  static int find(int i) {
    if ((i != fa[i])) {
      (fa[i] = Code06_Network1::find(fa[i]));
    }
    return fa[i];
  }
  static void union_method(int x, int y) {
    (x = Code06_Network1::find(x));
    (y = Code06_Network1::find(y));
    if ((x != y)) {
      if ((dep[x] < dep[y])) {
        (fa[y] = x);
      } else {
        (fa[x] = y);
      }
    }
  }
  static void link(int x, int y) {
    (x = Code06_Network1::find(belong[x]));
    (y = Code06_Network1::find(belong[y]));
    while ((x != y)) {
      if ((dep[x] >= dep[y])) {
        Code06_Network1::union_method(x, up[x]);
        (x = Code06_Network1::find(x));
      } else {
        Code06_Network1::union_method(y, up[y]);
        (y = Code06_Network1::find(y));
      }
      (ebccCnt--);
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = 0);
    (n = in.nextInt());
    (m = in.nextInt());
    while (((n != 0) || (m != 0))) {
      Code06_Network1::prepare();
      for (int i = 1; (i <= m); (i++)) {
        (a[i] = in.nextInt());
        (b[i] = in.nextInt());
        Code06_Network1::addEdge(a[i], b[i]);
        Code06_Network1::addEdge(b[i], a[i]);
      }
      Code06_Network1::tarjan(1, 0);
      Code06_Network1::condense();
      Code06_Network1::dfs(1, 0);
      out.println(((String(u"Case ") + (++t)) + String(u":")));
      (q = in.nextInt());
      {
        int i = 1;
        int x = {};
        int y = {};
        for (; (i <= q); (i++)) {
          (x = in.nextInt());
          (y = in.nextInt());
          Code06_Network1::link(x, y);
          out.println((ebccCnt - 1));
        }
      }
      out.println();
      (n = in.nextInt());
      (m = in.nextInt());
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_Network1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 网络，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 一共q条操作，格式 x y : 点x和点y之间新增一条边，打印此时割边的数量
// 1 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 测试链接 : https://acm.hdu.edu.cn/showproblem.php?pid=2460
// 测试链接 : http://poj.org/problem?id=3694
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
