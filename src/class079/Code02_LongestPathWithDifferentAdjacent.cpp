// Source: src/class079/Code02_LongestPathWithDifferentAdjacent.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_LongestPathWithDifferentAdjacent {
  struct Info;
  struct Info {
    int maxPathFromHead = {};
    int maxPath = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(int a, int b) {
      (maxPathFromHead = a);
      (maxPath = b);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_LongestPathWithDifferentAdjacent() {}
  static int longestPath(Array<int> parent, String str) {
    int n = parent.length;
    Array<jchar> s = str.toCharArray();
    JList<JList<int>> graph = JList<JList<int>>();
    for (int i = 0; (i < n); (i++)) {
      graph.add(JList<int>());
    }
    for (int i = 1; (i < n); (i++)) {
      graph.get(parent[i]).add(i);
    }
    return Code02_LongestPathWithDifferentAdjacent::f(s, graph, 0)->maxPath;
  }
  static Info *f(Array<jchar> s, JList<JList<int>> graph, int u) {
    if (graph.get(u).isEmpty()) {
      return new Info(1, 1);
    }
    int max1 = 0;
    int max2 = 0;
    int maxPath = 1;
    for (int v : graph.get(u)) {
      Info *nextInfo = Code02_LongestPathWithDifferentAdjacent::f(s, graph, v);
      (maxPath = jmax(maxPath, nextInfo->maxPath));
      if ((s[u] != s[v])) {
        if ((nextInfo->maxPathFromHead > max1)) {
          (max2 = max1);
          (max1 = nextInfo->maxPathFromHead);
        } else if ((nextInfo->maxPathFromHead > max2)) {
          (max2 = nextInfo->maxPathFromHead);
        }
      }
    }
    int maxPathFromHead = (max1 + 1);
    (maxPath = jmax(maxPath, ((max1 + max2) + 1)));
    return new Info(maxPathFromHead, maxPath);
  }
};

/* Original teaching comments:
// 相邻字符不同的最长路径
// 给你一棵 树（即一个连通、无向、无环图），根节点是节点 0
// 这棵树由编号从 0 到 n - 1 的 n 个节点组成
// 用下标从 0 开始、长度为 n 的数组 parent 来表示这棵树
// 其中 parent[i] 是节点 i 的父节点
// 由于节点 0 是根节点，所以 parent[0] == -1
// 另给你一个字符串 s ，长度也是 n ，其中 s[i] 表示分配给节点 i 的字符
// 请你找出路径上任意一对相邻节点都没有分配到相同字符的 最长路径
// 并返回该路径的长度
// 测试链接 :
https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/
                        // u节点是叶
*/
