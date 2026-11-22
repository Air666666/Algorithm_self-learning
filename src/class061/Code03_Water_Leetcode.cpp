// Source: src/class061/Code03_Water_Leetcode.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_Water_Leetcode {
  inline static int MAXN = 10010;
  inline static Array<Array<int>> edges = make_array<int>(jshl(MAXN, 1), 3);
  inline static int cnt = {};
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_Water_Leetcode() {}
  static int minCostToSupplyWater(int n, Array<int> wells,
                                  Array<Array<int>> pipes) {
    Code03_Water_Leetcode::build(n);
    for (int i = 0; (i < n); (i++), (cnt++)) {
      (edges[cnt][0] = 0);
      (edges[cnt][1] = (i + 1));
      (edges[cnt][2] = wells[i]);
    }
    for (int i = 0; (i < pipes.length); (i++), (cnt++)) {
      (edges[cnt][0] = pipes[i][0]);
      (edges[cnt][1] = pipes[i][1]);
      (edges[cnt][2] = pipes[i][2]);
    }
    j::sort(edges, 0, cnt,
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    int ans = 0;
    for (int i = 0; (i < cnt); (i++)) {
      if (Code03_Water_Leetcode::union_method(edges[i][0], edges[i][1])) {
        (ans += edges[i][2]);
      }
    }
    return ans;
  }
  static void build(int n) {
    (cnt = 0);
    for (int i = 0; (i <= n); (i++)) {
      (father[i] = i);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_Water_Leetcode::find(father[i]));
    }
    return father[i];
  }
  static bool union_method(int x, int y) {
    int fx = Code03_Water_Leetcode::find(x);
    int fy = Code03_Water_Leetcode::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      return true;
    } else {
      return false;
    }
  }
};

/* Original teaching comments:
// 特别说明
// 本题目前变成了 Leetcode 会员题，如果不想充值会员，可以去洛谷提交
// 洛谷 P1550 是同样的题，本节课代码 Code03_Water_Luogu 就是实现
//
// 水资源分配优化
// 村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。
// 对于每个房子 i，我们有两种可选的供水方案：一种是直接在房子内建造水井
// 成本为 wells[i - 1] （注意 -1 ，因为 索引从0开始 ）
// 另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，
// 其中每个 pipes[j] = [house1j, house2j, costj]
// 代表用管道将 house1j 和 house2j连接在一起的成本。连接是双向的。
// 请返回 为所有房子都供水的最低总成本
// 测试链接 :
https://leetcode.cn/problems/optimize-water-distribution-in-a-village/
                        // wells : 100   30
                        //         0(1)  1(2)
        // 如果x和y，原本是一个集合，返回false
        // 如果x和y，不是一个集合，合并之后后返回true
*/
