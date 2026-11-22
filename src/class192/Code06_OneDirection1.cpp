// Source: src/class192/Code06_OneDirection1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_OneDirection1 {
  inline static int MAXN = 200001;
  inline static int MAXM = 200001;
  inline static int MAXP = 20;
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
  inline static Array<int> block = make_array<int>(MAXN);
  inline static Array<int> dep = make_array<int>(MAXN);
  inline static Array<Array<int>> stjump = make_array<int>(MAXN, MAXP);
  inline static Array<bool> vis = make_array<bool>(MAXN);
  inline static Array<int> upCnt = make_array<int>(MAXN);
  inline static Array<int> downCnt = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_OneDirection1() {}
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
        Code06_OneDirection1::tarjan(v, e);
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
        Code06_OneDirection1::addEdge(ebcc1, ebcc2);
        Code06_OneDirection1::addEdge(ebcc2, ebcc1);
      }
    }
  }
  static void dfs(int u, int fa, int bid) {
    (block[u] = bid);
    (dep[u] = (dep[fa] + 1));
    (stjump[u][0] = fa);
    for (int p = 1; (p < MAXP); (p++)) {
      (stjump[u][p] = stjump[stjump[u][(p - 1)]][(p - 1)]);
    }
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code06_OneDirection1::dfs(v, u, bid);
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
  static bool check(int u, int fa) {
    (vis[u] = true);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        if ((!Code06_OneDirection1::check(v, u))) {
          return false;
        }
        (upCnt[u] += upCnt[v]);
        (downCnt[u] += downCnt[v]);
      }
    }
    return ((upCnt[u] == 0) || (downCnt[u] == 0));
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    (q = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code06_OneDirection1::addEdge(a[i], b[i]);
      Code06_OneDirection1::addEdge(b[i], a[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code06_OneDirection1::tarjan(i, 0);
      }
    }
    Code06_OneDirection1::condense();
    {
      int i = 1;
      int b = 0;
      for (; (i <= ebccCnt); (i++)) {
        if ((block[i] == 0)) {
          Code06_OneDirection1::dfs(i, 0, (++b));
        }
      }
    }
    bool ans = true;
    {
      int i = 1;
      int x = {};
      int y = {};
      int xylca = {};
      for (; (i <= q); (i++)) {
        (x = in.nextInt());
        (y = in.nextInt());
        (x = belong[x]);
        (y = belong[y]);
        if ((block[x] != block[y])) {
          (ans = false);
          break;
        }
        (xylca = Code06_OneDirection1::getLca(x, y));
        (upCnt[x]++);
        (upCnt[xylca]--);
        (downCnt[y]++);
        (downCnt[xylca]--);
      }
    }
    if (ans) {
      for (int i = 1; (i <= ebccCnt); (i++)) {
        if (((!vis[i]) && (!Code06_OneDirection1::check(i, 0)))) {
          (ans = false);
          break;
        }
      }
    }
    out.println((ans ? String(u"Yes") : String(u"No")));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_OneDirection1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 只能一个方向，java版
// 给定一张无向图，一共n个点、m条边，图上可能有多个连通区
// 给定q条要求，格式 x y : 从点x出发，要求可以去往点y
// 你必须把每条无向边变成有向边，也就是每条边确定唯一的方向
// 如果改造后能满足所有要求，打印"Yes"，如果不存在方案，打印"No"
// 1 <= n、m <= 2 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF555E
// 测试链接 : https://codeforces.com/problemset/problem/555/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
