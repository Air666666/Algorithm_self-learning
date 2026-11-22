// Source: src/class191/Code07_RedundantPaths1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_RedundantPaths1 {
  inline static int MAXN = 5001;
  inline static int MAXM = 10001;
  inline static int n = {};
  inline static int m = {};
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
  inline static Array<int> degree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_RedundantPaths1() {}
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
        Code07_RedundantPaths1::tarjan(v, e);
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
  static int getLeaf() {
    for (int i = 1; (i <= m); (i++)) {
      int ebcc1 = belong[a[i]];
      int ebcc2 = belong[b[i]];
      if ((ebcc1 != ebcc2)) {
        (degree[ebcc1]++);
        (degree[ebcc2]++);
      }
    }
    int ans = 0;
    for (int i = 1; (i <= ebccCnt); (i++)) {
      if ((degree[i] == 1)) {
        (ans++);
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
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code07_RedundantPaths1::addEdge(a[i], b[i]);
      Code07_RedundantPaths1::addEdge(b[i], a[i]);
    }
    Code07_RedundantPaths1::tarjan(1, 0);
    int leafCnt = Code07_RedundantPaths1::getLeaf();
    out.println(jdiv((leafCnt + 1), 2));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_RedundantPaths1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 冗余路径，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 打印至少添加几条边可以让整张图变成一个边双连通分量
// 1 <= n <= 5000
// 1 <= m <= 10000
// 测试链接 : https://www.luogu.com.cn/problem/P2860
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
