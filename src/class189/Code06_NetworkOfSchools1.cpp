// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P2812

// Source: src/class189/Code06_NetworkOfSchools1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_NetworkOfSchools1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 500001;
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
  inline static Array<int> outdegree = make_array<int>(MAXN);
  inline static Array<int> indegree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_NetworkOfSchools1() {}
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
        Code06_NetworkOfSchools1::tarjan(v);
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
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = 0);
    {
      int i = 1;
      int x = {};
      for (; (i <= n); (i++)) {
        (x = in.nextInt());
        while ((x != 0)) {
          (m++);
          (a[m] = i);
          (b[m] = x);
          Code06_NetworkOfSchools1::addEdge(a[m], b[m]);
          (x = in.nextInt());
        }
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code06_NetworkOfSchools1::tarjan(i);
      }
    }
    if ((sccCnt == 1)) {
      out.println(String(u"1"));
      out.println(String(u"0"));
    } else {
      for (int i = 1; (i <= m); (i++)) {
        int scc1 = belong[a[i]];
        int scc2 = belong[b[i]];
        if ((scc1 != scc2)) {
          (outdegree[scc1]++);
          (indegree[scc2]++);
        }
      }
      int outZero = 0;
      int inZero = 0;
      for (int i = 1; (i <= sccCnt); (i++)) {
        if ((outdegree[i] == 0)) {
          (outZero++);
        }
        if ((indegree[i] == 0)) {
          (inZero++);
        }
      }
      out.println(inZero);
      out.println(jmax(outZero, inZero));
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code06_NetworkOfSchools1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 校园网络，java版
// 一共有n个节点，m条有向边，消息只能顺着有向边传递
// 打印至少需要在几个节点投放消息，才能让所有节点，都能收到消息
// 打印至少需要添加几条边，才能让任意两个节点之间，都能传递消息
// 1 <= n <= 10^4
// 1 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2812
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
