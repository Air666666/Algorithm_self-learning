// Source: src/class079/Code04_MinimumScoreAfterRemovals.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MinimumScoreAfterRemovals {
  inline static int MAXN = 1001;
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> xor_java = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MinimumScoreAfterRemovals() {}
  static int minimumScore(Array<int> nums, Array<Array<int>> edges) {
    int n = nums.length;
    JList<JList<int>> graph = JList<JList<int>>();
    for (int i = 0; (i < n); (i++)) {
      graph.add(JList<int>());
    }
    for (Array<int> edge : edges) {
      graph.get(edge[0]).add(edge[1]);
      graph.get(edge[1]).add(edge[0]);
    }
    j::fill(dfn, 0, n, 0);
    (dfnCnt = 0);
    Code04_MinimumScoreAfterRemovals::f(nums, graph, 0);
    int m = edges.length;
    int ans = std::numeric_limits<int>::max();
    {
      int i = 0;
      int a = {};
      int b = {};
      int pre = {};
      int pos = {};
      int sum1 = {};
      int sum2 = {};
      int sum3 = {};
      for (; (i < m); (i++)) {
        (a = jmax(dfn[edges[i][0]], dfn[edges[i][1]]));
        for (int j = (i + 1); (j < m); (j++)) {
          (b = jmax(dfn[edges[j][0]], dfn[edges[j][1]]));
          if ((a < b)) {
            (pre = a);
            (pos = b);
          } else {
            (pre = b);
            (pos = a);
          }
          (sum1 = xor_java[pos]);
          if ((pos < (pre + size[pre]))) {
            (sum2 = (xor_java[pre] ^ xor_java[pos]));
            (sum3 = (xor_java[1] ^ xor_java[pre]));
          } else {
            (sum2 = xor_java[pre]);
            (sum3 = ((xor_java[1] ^ sum1) ^ sum2));
          }
          (ans = jmin(ans, [&]() {
             auto jleft = jmax(jmax(sum1, sum2), sum3);
             auto jright = jmin(jmin(sum1, sum2), sum3);
             return (jleft - jright);
           }()));
        }
      }
    }
    return ans;
  }
  static void f(Array<int> nums, JList<JList<int>> graph, int u) {
    int i = (++dfnCnt);
    (dfn[u] = i);
    (xor_java[i] = nums[u]);
    (size[i] = 1);
    for (int v : graph.get(u)) {
      if ((dfn[v] == 0)) {
        Code04_MinimumScoreAfterRemovals::f(nums, graph, v);
        (xor_java[i] ^= xor_java[dfn[v]]);
        (size[i] += size[dfn[v]]);
      }
    }
  }
};

/* Original teaching comments:
// 从树中删除边的最小分数
// 存在一棵无向连通树，树中有编号从0到n-1的n个节点，以及n-1条边
// 给你一个下标从0开始的整数数组nums长度为n，其中nums[i]表示第i个节点的值
// 另给你一个二维整数数组edges长度为n-1
// 其中 edges[i] = [ai, bi] 表示树中存在一条位于节点 ai 和 bi 之间的边
//
删除树中两条不同的边以形成三个连通组件，对于一种删除边方案，定义如下步骤以计算其分数：
// 分别获取三个组件每个组件中所有节点值的异或值
// 最大 异或值和 最小 异或值的 差值 就是这种删除边方案的分数
// 返回可能的最小分数
// 测试链接 :
https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/
        // 下标为原始节点编号
        // 下标为dfn序号
        // 下标为dfn序号
                                // xor[1] : 整棵树的异或和
                                // 因为头节点是0，一定拥有最小的dfn序号1
                                // f函数调用的时候，也是从0节点开始的
        // 当前来到原始编号u，遍历u的整棵树
*/
