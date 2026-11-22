// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P5234

// Source: src/class192/Code03_PrisonBreak1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_PrisonBreak1 {
  inline static int MAXN = 500001;
  inline static int MAXM = 1000001;
  inline static int n = {};
  inline static int m = {};
  inline static int maxv = {};
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> c = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> weight = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static int ebccCnt = {};
  inline static Array<int> dist = make_array<int>(MAXN);
  inline static int diameter = {};
  inline static int edgeCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_PrisonBreak1() {}
  static void addEdge(int u, int v, int w) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (weight[cntg] = w);
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
        Code03_PrisonBreak1::tarjan(v, e);
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
      int w = c[i];
      if ((ebcc1 != ebcc2)) {
        Code03_PrisonBreak1::addEdge(ebcc1, ebcc2, w);
        Code03_PrisonBreak1::addEdge(ebcc2, ebcc1, w);
      }
    }
  }
  static void dpOnTree(int u, int fa, int limit) {
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((v != fa)) {
        Code03_PrisonBreak1::dpOnTree(v, u, limit);
        int w = ((weight[e] <= limit) ? 1 : 0);
        (edgeCnt += w);
        (diameter = jmax(diameter, ((dist[u] + dist[v]) + w)));
        (dist[u] = jmax(dist[u], (dist[v] + w)));
      }
    }
  }
  static bool check(int limit) {
    for (int i = 1; (i <= ebccCnt); (i++)) {
      (dist[i] = 0);
    }
    (diameter = (edgeCnt = 0));
    Code03_PrisonBreak1::dpOnTree(1, 0, limit);
    return (diameter < edgeCnt);
  }
  static int compute() {
    int l = 1;
    int r = maxv;
    int mid = {};
    int ans = (-1);
    while ((l <= r)) {
      (mid = jdiv((l + r), 2));
      if (Code03_PrisonBreak1::check(mid)) {
        (ans = mid);
        (r = (mid - 1));
      } else {
        (l = (mid + 1));
      }
    }
    return ans;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    (maxv = 0);
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      (c[i] = in.nextInt());
      Code03_PrisonBreak1::addEdge(a[i], b[i], 0);
      Code03_PrisonBreak1::addEdge(b[i], a[i], 0);
      (maxv = jmax(maxv, c[i]));
    }
    Code03_PrisonBreak1::tarjan(1, 0);
    Code03_PrisonBreak1::condense();
    out.println(Code03_PrisonBreak1::compute());
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code03_PrisonBreak1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 越狱老虎桥，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 每条边给定边权，表示破坏这条边需要花费的钱数
// 敌人可能在任意两点之间新增一条边，新增的这条边无法被破坏
// 敌人新增一条边之后，你的目标是只破坏一条边，就让图变成两个连通区
// 你不知道敌人会选择哪两个端点来新增这条边，你需要尽可能的做好准备
// 假设遭遇最差情况，打印你至少准备多少钱才能完成目标，无法完成目标打印-1
// 1 <= n <= 5 * 10^5
// 1 <= m <= 10^6
// 1 <= 边权 <= 10^5
// 测试链接 : https://www.luogu.com.cn/problem/P5234
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
