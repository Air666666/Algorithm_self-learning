// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/CF427C
// https://codeforces.com/problemset/problem/427/C

// Source: src/class189/Code08_Checkposts1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code08_Checkposts1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 300001;
  inline static int MOD = 1000000007;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> val = make_array<int>(MAXN);
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
  inline static Array<int> minCnt = make_array<int>(MAXN);
  inline static int sccCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code08_Checkposts1() {}
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
        Code08_Checkposts1::tarjan(v);
        (low[u] = jmin(low[u], low[v]));
      } else {
        if ((belong[v] == 0)) {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    if ((dfn[u] == low[u])) {
      (sccCnt++);
      (minVal[sccCnt] = 1000000001);
      (minCnt[sccCnt] = 0);
      int pop = {};
      do {
        (pop = sta[(top--)]);
        (belong[pop] = sccCnt);
        if ((minVal[sccCnt] > val[pop])) {
          (minVal[sccCnt] = val[pop]);
          (minCnt[sccCnt] = 1);
        } else if ((minVal[sccCnt] == val[pop])) {
          (minCnt[sccCnt]++);
        }
      } while ((pop != u));
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (n = in.nextInt());
    for (int i = 1; (i <= n); (i++)) {
      (val[i] = in.nextInt());
    }
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code08_Checkposts1::addEdge(u, v);
      }
    }
    for (int i = 1; (i <= n); (i++)) {
      if ((dfn[i] == 0)) {
        Code08_Checkposts1::tarjan(i);
      }
    }
    i64 ans1 = 0;
    i64 ans2 = 1;
    for (int i = 1; (i <= sccCnt); (i++)) {
      (ans1 += minVal[i]);
      (ans2 = jrem((ans2 * minCnt[i]), MOD));
    }
    out.println(((ans1 + String(u" ")) + ans2));
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code08_Checkposts1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 检查站，java版
// 给定一张n个点，m条边的有向图，每个点有点权
// 一个强连通分量内部，选点权最小的点，就能控制该连通分量里的所有点
// 你的目的是选择若干点之后，图上所有的点都能控制，打印最小点权和
// 打印选择点的方案数，方案数可能较大，对 1000000007 取余
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF427C
// 测试链接 : https://codeforces.com/problemset/problem/427/C
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
        // 读写工具类
*/
