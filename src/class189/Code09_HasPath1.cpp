// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P10944

// Source: src/class189/Code09_HasPath1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code09_HasPath1 {
  inline static int MAXN = 1001;
  inline static int MAXM = 6001;
  inline static int t = {};
  inline static int n = {};
  inline static int m = {};
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
  inline static int sccCnt = {};
  inline static Array<int> indegree = make_array<int>(MAXN);
  inline static Array<int> que = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code09_HasPath1() {}
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
        Code09_HasPath1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
      } while ((pop != u));
    }
  }
  static void condense() {
    (cntg = 0);
    for (int i = 1; (i <= sccCnt); (i++)) {
      (head[i] = 0);
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        (indegree[scc2]++);
        Code09_HasPath1::addEdge(scc1, scc2);
      }
    }
  }
  static bool topo() {
    int l = 1;
    int r = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((indegree[i] == 0)) {
        (que[(++r)] = i);
      }
    }
    while ((l <= r)) {
      int siz = ((r - l) + 1);
      if ((siz > 1)) {
        return false;
      }
      int u = que[(l++)];
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if (((--indegree[v]) == 0)) {
          (que[(++r)] = v);
        }
      }
    }
    return true;
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (t = in.nextInt());
    for (int c = 1; (c <= t); (c++)) {
      (n = in.nextInt());
      (m = in.nextInt());
      (cntg = (cntd = (sccCnt = 0)));
      for (int i = 1; (i <= n); (i++)) {
        (head[i] = (dfn[i] = (belong[i] = (indegree[i] = 0))));
      }
      for (int i = 1; (i <= m); (i++)) {
        (a[i] = in.nextInt());
        (b[i] = in.nextInt());
        Code09_HasPath1::addEdge(a[i], b[i]);
      }
      for (int i = 1; (i <= n); (i++)) {
        if ((dfn[i] == 0)) {
          Code09_HasPath1::tarjan(i);
        }
      }
      Code09_HasPath1::condense();
      bool ans = Code09_HasPath1::topo();
      out.println((ans ? String(u"Yes") : String(u"No")));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code09_HasPath1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 任意两点都有路，java版
// 给定一张n个点，m条边的有向图
// 两点u、v，不管是从u出发能到达v，还是从v出发能到达u，都叫两点间有路
// 判断这个有向图是否能做到，任意两点都有路，能打印"Yes"，不能打印"No"
// 1 <= n <= 1000
// 1 <= m <= 6000
// 测试链接 : https://www.luogu.com.cn/problem/P10944
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
