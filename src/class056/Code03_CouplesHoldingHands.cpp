// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/couples-holding-hands/

// Source: src/class056/Code03_CouplesHoldingHands.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_CouplesHoldingHands {
  inline static int MAXN = 31;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static int sets = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_CouplesHoldingHands() {}
  static int minSwapsCouples(Array<int> row) {
    int n = row.length;
    Code03_CouplesHoldingHands::build(jdiv(n, 2));
    for (int i = 0; (i < n); (i += 2)) {
      Code03_CouplesHoldingHands::union_method(jdiv(row[i], 2),
                                               jdiv(row[(i + 1)], 2));
    }
    return (jdiv(n, 2) - sets);
  }
  static void build(int m) {
    for (int i = 0; (i < m); (i++)) {
      (father[i] = i);
    }
    (sets = m);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code03_CouplesHoldingHands::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int x, int y) {
    int fx = Code03_CouplesHoldingHands::find(x);
    int fy = Code03_CouplesHoldingHands::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      (sets--);
    }
  }
};

/* Original teaching comments:
// 情侣牵手
// n对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手
// 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的ID
// 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是
(2n-2, 2n-1)
// 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起
// 每次交换可选择任意两人，让他们站起来交换座位
// 测试链接 : https://leetcode.cn/problems/couples-holding-hands/
*/
