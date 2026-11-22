// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/critical-connections-in-a-network/

// Source: src/class191/Code02_CutEdge1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_CutEdge1 {
  struct Solution;
  struct Solution {
    inline static int MAXN = 100001;
    inline static int MAXM = 100001;
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
    inline static Array<bool> cutEdge = make_array<bool>(MAXM);
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
    static void prepare() {
      (cntg = 1);
      (cntd = 0);
      for (int i = 1; (i <= n); (i++)) {
        (head[i] = (dfn[i] = (low[i] = 0)));
      }
      for (int i = 1; (i <= m); (i++)) {
        (cutEdge[i] = false);
      }
    }
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
        if ((dfn[v] == 0)) {
          Solution::tarjan(v, e);
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] > dfn[u])) {
            (cutEdge[jshr(e, 1)] = true);
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    static JList<JList<int>>
    criticalConnections(int nodeCnt, JList<JList<int>> connections) {
      (n = nodeCnt);
      (m = connections.size());
      Solution::prepare();
      {
        int i = 1;
        int j = 0;
        for (; (i <= m); (i++), (j++)) {
          (a[i] = (connections.get(j).get(0) + 1));
          (b[i] = (connections.get(j).get(1) + 1));
          Solution::addEdge(a[i], b[i]);
          Solution::addEdge(b[i], a[i]);
        }
      }
      Solution::tarjan(1, 0);
      JList<JList<int>> ans = JList<JList<int>>();
      for (int i = 1; (i <= m); (i++)) {
        if (cutEdge[i]) {
          ans.add(j::asList((a[i] - 1), (b[i] - 1)));
        }
      }
      return ans;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_CutEdge1() {}
};

/* Original teaching comments:
// 割边模版题2，java版
// 给定一张无向图，一共n个点、m条边
// 点的编号0~n-1，保证所有点连通
// 找出图中所有的割边，返回每条割边的两个端点
// 请保证原图即使有重边和自环，答案依然正确
// 1 <= n、m <= 10^5
// 测试链接 : https://leetcode.cn/problems/critical-connections-in-a-network/
// 提交以下代码中的Solution类，可以通过所有测试用例
*/
