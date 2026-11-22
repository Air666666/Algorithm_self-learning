// Source: src/class057/Code01_MostStonesRemovedWithSameRowOrColumn.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MostStonesRemovedWithSameRowOrColumn {
  inline static JMap<int, int> rowFirst = JMap<int, int>();
  inline static JMap<int, int> colFirst = JMap<int, int>();
  inline static int MAXN = 1001;
  inline static Array<int> father = make_array<int>(MAXN);
  inline static int sets = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MostStonesRemovedWithSameRowOrColumn() {}
  static void build(int n) {
    rowFirst.clear();
    colFirst.clear();
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
    }
    (sets = n);
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] =
           Code01_MostStonesRemovedWithSameRowOrColumn::find(father[i]));
    }
    return father[i];
  }
  static void union_method(int x, int y) {
    int fx = Code01_MostStonesRemovedWithSameRowOrColumn::find(x);
    int fy = Code01_MostStonesRemovedWithSameRowOrColumn::find(y);
    if ((fx != fy)) {
      (father[fx] = fy);
      (sets--);
    }
  }
  static int removeStones(Array<Array<int>> stones) {
    int n = stones.length;
    Code01_MostStonesRemovedWithSameRowOrColumn::build(n);
    for (int i = 0; (i < n); (i++)) {
      int row = stones[i][0];
      int col = stones[i][1];
      if ((!rowFirst.containsKey(row))) {
        rowFirst.put(row, i);
      } else {
        Code01_MostStonesRemovedWithSameRowOrColumn::union_method(
            i, rowFirst.get(row));
      }
      if ((!colFirst.containsKey(col))) {
        colFirst.put(col, i);
      } else {
        Code01_MostStonesRemovedWithSameRowOrColumn::union_method(
            i, colFirst.get(col));
      }
    }
    return (n - sets);
  }
};

/* Original teaching comments:
// 移除最多的同行或同列石头
// n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头
// 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头
// 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i
块石头的位置
// 返回 可以移除的石子 的最大数量。
// 测试链接 :
https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/
        // key : 某行
        // value : 第一次遇到的石头编号
*/
