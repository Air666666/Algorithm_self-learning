// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1262

// Source: src/class189/Code07_Spy1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_Spy1 {
  inline static int MAXN = 3001;
  inline static int MAXM = 8001;
  inline static int INF = 1000000001;
  inline static int n = {};
  inline static int p = {};
  inline static int m = {};
  inline static Array<int> cost = make_array<int>(MAXN);
  inline static Array<int> a = make_array<int>(MAXM);
  inline static Array<int> b = make_array<int>(MAXM);
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> belong = make_array<int>(MAXN);
  inline static Array<int> minVal = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_Spy1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      int v = to[e];
      if ((dfn[v] == 0)) {
        Code07_Spy1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (minVal[sccCnt] = INF);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        (minVal[sccCnt] = jmin(minVal[sccCnt], cost[pop]));
      } while ((pop != u));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (p = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (cost[i] = INF);
    }
    {
      int i = 1;
      int u = {};
      int c = {};
      for (; (i <= p); (i++)) {
        (u = in.nextInt());
        (c = in.nextInt());
        (cost[u] = c);
      }
    }
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code07_Spy1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if (((cost[i] != INF) && (dfn[i] == 0))) {
        Code07_Spy1::tarjan(i);
      }
    }
    bool check = true;
    int ans = 0;
    for (int i = 1; (i <= n); (i++)) {
      if ((belong[i] == 0)) {
        (check = false);
        (ans = i);
        break;
      }
    }
    if ((!check)) {
      out.println(String(u"NO"));
      out.println(ans);
    } else {
      for (int i = 1; (i <= m); (i++)) {
        int scc1 = belong[a[i]];
        int scc2 = belong[b[i]];
        if ((scc1 != scc2)) {
          (indegree[scc2]++);
        }
      }
      for (int i = 1; (i <= sccCnt); (i++)) {
        if ((indegree[i] == 0)) {
          (ans += minVal[i]);
        }
      }
      out.println(String(u"YES"));
      out.println(ans);
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code07_Spy1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 间谍网络，java版
// 一共有n个间谍，其中有p个间谍可以贿赂，给定各自的价格，剩下的间谍不能贿赂
// 然后给定m个控制关系，控制关系是单向的，也是可传递的
// 如果间谍a能控制间谍b，间谍b能控制间谍c，那么间谍a就能控制间谍c
// 当你贿赂了某个间谍，该间谍连同他能控制的所有人，都能被你控制
// 如果你不能控制所有间谍，打印"NO"，然后打印不能控制的间谍中，最小的编号
// 如果你可以控制所有间谍，打印"YES"，然后打印需要花费的最少钱数
// 1 <= n <= 3000    0 <= 各自的价格 <= 20000    1 <= m <= 8000
// 测试链接 : https://www.luogu.com.cn/problem/P1262
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
