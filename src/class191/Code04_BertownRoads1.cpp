// Source: src/class191/Code04_BertownRoads1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_BertownRoads1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 300001;
  inline static int n = {};
  inline static int m = {};
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
  inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static bool check = {};
  inline static Array<int> ans1 = make_array<int>(MAXM);
  inline static Array<int> ans2 = make_array<int>(MAXM);
  inline static int cnta = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_BertownRoads1() {}
  static void addEdge(int u, int v) {
    (nxt[(++cntg)] = head[u]);
    (to[cntg] = v);
    (head[u] = cntg);
  }
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge)) {
        continue;
      }
      int v = to[e];
      if (((dfn[v] == 0) || (dfn[v] < dfn[u]))) {
        (cnta++);
        (ans1[cnta] = u);
        (ans2[cnta] = v);
      }
      if ((dfn[v] == 0)) {
        Code04_BertownRoads1::tarjan(v, e);
        (low[u] = jmin(low[u], low[v]));
        if ((low[v] > dfn[u])) {
          (check = false);
        }
      } else {
        (low[u] = jmin(low[u], dfn[v]));
      }
    }
  }
  static void java_main(Array<String> args) {
    IO in = IO(jin);
    IO out = IO(IO(jout));
    (cntg = 1);
    (n = in.nextInt());
    (m = in.nextInt());
    {
      int i = 1;
      int u = {};
      int v = {};
      for (; (i <= m); (i++)) {
        (u = in.nextInt());
        (v = in.nextInt());
        Code04_BertownRoads1::addEdge(u, v);
        Code04_BertownRoads1::addEdge(v, u);
      }
    }
    (check = true);
    Code04_BertownRoads1::tarjan(1, 0);
    if ((!check)) {
      out.println(0);
    } else {
      for (int i = 1; (i <= m); (i++)) {
        out.println(((ans1[i] + String(u" ")) + ans2[i]));
      }
    }
    out.flush();
    out.close();
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Code04_BertownRoads1::java_main(Array<String>{});
  return 0;
}

/* Original teaching comments:
// 贝尔敦道路，java版
// 给定一张无向图，一共n个点、m条边，保证所有点连通
// 每条无向边需要指定一个方向，变成有向边，还要保证任意两点互相可达
// 如果不存在方案打印0，如果存在方案，打印m条有向边
// 可以任意次序打印有向边，如果方案不只一种，打印其中一种即可
// 1 <= n <= 10^5
// 1 <= m <= 3 * 10^5
// 测试链接 : https://www.luogu.com.cn/problem/CF118E
// 测试链接 : https://codeforces.com/problemset/problem/118/E
// 提交以下的code，提交时请把类名改成"Main"，可以通过所有测试用例
                        // 树边和回边需要处理，弃边不要处理
        // 读写工具类
*/
