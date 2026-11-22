// Source: src/class189/Code04_PopularCow1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_PopularCow1 {
  inline static int MAXN = 10001;
  inline static int MAXM = 50001;
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
  inline static Array<int> sccSiz = make_array<int>(MAXN);
  inline static int sccCnt = {};
  inline static Array<int> outdegree = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_PopularCow1() {}
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
        Code04_PopularCow1::tarjan(v);
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
        (sccSiz[sccCnt]++);
      } while ((pop != u));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    (m = in.nextInt());
    for (int i = 1; (i <= m); (i++)) {
      (a[i] = in.nextInt());
      (b[i] = in.nextInt());
      Code04_PopularCow1::addEdge(a[i], b[i]);
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code04_PopularCow1::tarjan(i);
      }
    }
    for (int i = 1; (i <= m); (i++)) {
      int scc1 = belong[a[i]];
      int scc2 = belong[b[i]];
      if ((scc1 != scc2)) {
        (outdegree[scc1]++);
      }
    }
    int num = 0;
    int siz = 0;
    for (int i = 1; (i <= sccCnt); (i++)) {
      if ((outdegree[i] == 0)) {
        (num++);
        (siz = sccSiz[i]);
      }
      if ((num > 1)) {
        (siz = 0);
        break;
      }
    }
    out.println(siz);
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_PopularCow1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 受欢迎的牛，java版
// 一共有n只牛，牛和牛之间存在喜欢关系，喜欢关系是有向的
// 喜欢关系可以传递，如果a喜欢b，b喜欢c，那么a也喜欢c
// 每只牛都喜欢自己，如果某只牛被所有牛喜欢，那么这只牛是明星
// 给定m个喜欢关系，打印明星的数量
// 1 <= n <= 10^4
// 1 <= m <= 5 * 10^4
// 测试链接 : https://www.luogu.com.cn/problem/P2341
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
