// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/

// Source: src/class061/Code04_CheckingExistenceOfEdgeLengthLimit.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_CheckingExistenceOfEdgeLengthLimit {
  inline static int MAXN = 100001;
  inline static Array<Array<int>> questions = make_array<int>(MAXN, 4);
  inline static Array<int> father = make_array<int>(MAXN);
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_CheckingExistenceOfEdgeLengthLimit() {}
  static Array<bool> distanceLimitedPathsExist(int n, Array<Array<int>> edges,
                                               Array<Array<int>> queries) {
    j::sort(edges, [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    int m = edges.length;
    int k = queries.length;
    for (int i = 0; (i < k); (i++)) {
      (questions[i][0] = queries[i][0]);
      (questions[i][1] = queries[i][1]);
      (questions[i][2] = queries[i][2]);
      (questions[i][3] = i);
    }
    j::sort(questions, 0, k,
            [=](Array<int> a, Array<int> b) { return (a[2] - b[2]); });
    Code04_CheckingExistenceOfEdgeLengthLimit::build(n);
    Array<bool> ans = make_array<bool>(k);
    {
      int i = 0;
      int j = 0;
      for (; (i < k); (i++)) {
        for (; ((j < m) && (edges[j][2] < questions[i][2])); (j++)) {
          Code04_CheckingExistenceOfEdgeLengthLimit::union_method(edges[j][0],
                                                                  edges[j][1]);
        }
        (ans[questions[i][3]] =
             Code04_CheckingExistenceOfEdgeLengthLimit::isSameSet(
                 questions[i][0], questions[i][1]));
      }
    }
    return ans;
  }
  static void build(int n) {
    for (int i = 0; (i < n); (i++)) {
      (father[i] = i);
    }
  }
  static int find(int i) {
    if ((i != father[i])) {
      (father[i] = Code04_CheckingExistenceOfEdgeLengthLimit::find(father[i]));
    }
    return father[i];
  }
  static bool isSameSet(int x, int y) {
    return [&]() {
      auto jleft = Code04_CheckingExistenceOfEdgeLengthLimit::find(x);
      auto jright = Code04_CheckingExistenceOfEdgeLengthLimit::find(y);
      return (jleft == jright);
    }();
  }
  static void union_method(int x, int y) {
    (father[Code04_CheckingExistenceOfEdgeLengthLimit::find(x)] =
         Code04_CheckingExistenceOfEdgeLengthLimit::find(y));
  }
};

/* Original teaching comments:
// 检查边长度限制的路径是否存在
// 给你一个 n 个点组成的无向图边集 edgeList
// 其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi
的边
// 请注意，两个点之间可能有 超过一条边 。
// 给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj]
// 你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径
// 且这条路径上的每一条边都 严格小于 limitj 。
// 请你返回一个 布尔数组 answer ，其中 answer.length == queries.length
// 当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false
// 测试链接 :
https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/
                        // i : 问题编号
                        // j : 边的编号
*/
