// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/s5kipK/

// Source: src/class193/Code06_Recapture1.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code06_Recapture1 {
  struct Solution;
  struct Solution {
    inline static int MAXN = 100001;
    inline static int MAXM = 100001;
    inline static int n = {};
    inline static int m = {};
    inline static Array<int> head = make_array<int>(MAXN);
    inline static Array<int> nxt = make_array<int>(jshl(MAXM, 1));
    inline static Array<int> to = make_array<int>(jshl(MAXM, 1));
    inline static int cntg = {};
    inline static Array<int> dfn = make_array<int>(MAXN);
    inline static Array<int> low = make_array<int>(MAXN);
    inline static int cntd = {};
    inline static Array<int> sta = make_array<int>(MAXN);
    inline static int top = {};
    inline static Array<bool> cutVertex = make_array<bool>(MAXN);
    inline static JList<JList<int>> vbccArr = JList<JList<int>>();
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Solution() {}
    static void prepare() {
      (cntg = (cntd = (top = 0)));
      for (int i = 1; (i <= n); (i++)) {
        (head[i] = (dfn[i] = (low[i] = 0)));
        (cutVertex[i] = false);
      }
      vbccArr.clear();
    }
    static void addEdge(int u, int v) {
      (nxt[(++cntg)] = head[u]);
      (to[cntg] = v);
      (head[u] = cntg);
    }
    static void tarjan(int u, bool root) {
      (dfn[u] = (low[u] = (++cntd)));
      (sta[(++top)] = u);
      int son = 0;
      for (int e = head[u]; (e > 0); (e = nxt[e])) {
        int v = to[e];
        if ((dfn[v] == 0)) {
          (son++);
          Solution::tarjan(v, false);
          (low[u] = jmin(low[u], low[v]));
          if ((low[v] >= dfn[u])) {
            if (((!root) || (son >= 2))) {
              (cutVertex[u] = true);
            }
            JList<int> list = JList<int>();
            list.add(u);
            int pop = {};
            do {
              (pop = sta[(top--)]);
              list.add(pop);
            } while ((pop != v));
            vbccArr.add(list);
          }
        } else {
          (low[u] = jmin(low[u], dfn[v]));
        }
      }
    }
    static i64 minimumCost(Array<int> cost, Array<Array<int>> roads) {
      (n = cost.length);
      (m = roads.length);
      Solution::prepare();
      {
        int i = 0;
        int u = {};
        int v = {};
        for (; (i < m); (i++)) {
          (u = (roads[i][0] + 1));
          (v = (roads[i][1] + 1));
          Solution::addEdge(u, v);
          Solution::addEdge(v, u);
        }
      }
      Solution::tarjan(1, true);
      i64 ans = 0;
      if ((vbccArr.size() == 1)) {
        (ans = std::numeric_limits<i64>::max());
        for (int i = 0; (i < n); (i++)) {
          (ans = jmin(ans, cost[i]));
        }
      } else {
        int maxVal = std::numeric_limits<int>::min();
        for (JList<int> vbcc : vbccArr) {
          int cut = 0;
          int val = std::numeric_limits<int>::max();
          for (int cur : vbcc) {
            if (cutVertex[cur]) {
              (cut++);
            } else {
              (val = jmin(val, cost[(cur - 1)]));
            }
          }
          if ((cut == 1)) {
            (ans += val);
            (maxVal = jmax(maxVal, val));
          }
        }
        (ans -= maxVal);
      }
      return ans;
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code06_Recapture1() {}
};

/* Original teaching comments:
// 夺回据点，java版
// 一共n个据点，m条双向道路，所有据点连通在一起
// 每个据点给定点权，代表夺取这个据点需要的花费
// 当夺取某个据点之后，再夺取相邻的据点，认为没有花费
// 你可以按照任意顺序夺取所有据点，但是过程中必须保证
// 那些还没夺取的据点都在同一个连通区里，不被已经夺取的据点隔开
// 打印最小的总花费
// 1 <= n、m <= 10^5
// 1 <= 点权 <= 10^9
// 测试链接 : https://leetcode.cn/problems/s5kipK/
// 提交以下代码中的Solution类，可以通过所有测试用例
*/
