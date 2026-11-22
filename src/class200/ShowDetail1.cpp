// Source: src/class200/ShowDetail1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct ShowDetail1 {
  inline static int MAXN = 100001;
  inline static int MAXM = 200001;
  inline static Array<int> head = make_array<int>(MAXN);
  inline static Array<int> nxt = make_array<int>(MAXM);
  inline static Array<int> to = make_array<int>(MAXM);
  inline static Array<int> weight = make_array<int>(MAXM);
  inline static int cntg = {};
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> low = make_array<int>(MAXN);
  inline static int cntd = {};
  inline static Array<int> sta = make_array<int>(MAXN);
  inline static int top = {};
  inline static Array<int> fromWeight = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  ShowDetail1() {}
  static void tarjan(int u, int preEdge) {
    (dfn[u] = (low[u] = (++cntd)));
    (sta[(++top)] = u);
    for (int e = head[u]; (e > 0); (e = nxt[e])) {
      if (((e ^ 1) == preEdge))
        continue;
      int v = to[e];
      int w = weight[e];
      if ((dfn[v] == 0)) {
        ShowDetail1::tarjan(v, e);
        (fromWeight[v] = w);
        if ((low[v] < dfn[u])) {
          (low[u] = jmin(low[u], low[v]));
        } else if ((low[v] > dfn[u])) {
          (top--);
        } else {
        }
      } else {
        if ((dfn[v] < dfn[u])) {
          (fromWeight[v] = w);
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
  }
};

/* Original teaching comments:
// 仙人掌遍历和找环的过程，java版
                                        // 发现割边，实现有关割边的处理
                                        // 发现了环，实现有关环的处理
                                // 如果发现弃边，一般什么也不做
*/
