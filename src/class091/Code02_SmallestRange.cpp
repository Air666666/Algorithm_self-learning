// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

// Source: src/class091/Code02_SmallestRange.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SmallestRange {
  struct Node;
  struct Node {
    int v = {};
    int i = {};
    int j = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Node(int a, int b, int c) {
      (v = a);
      (i = b);
      (j = c);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SmallestRange() {}
  static Array<int> smallestRange(JList<JList<int>> nums) {
    int k = nums.size();
    JSet<Node *> set = JSet<Node *>([=](Node *a, Node *b) {
      return ((a->v != b->v) ? (a->v - b->v) : (a->i - b->i));
    });
    for (int i = 0; (i < k); (i++)) {
      set.add(new Node(nums.get(i).get(0), i, 0));
    }
    int r = std::numeric_limits<int>::max();
    int a = 0;
    int b = 0;
    Node *max = {};
    Node *min = {};
    while ((set.size() == k)) {
      (max = set.last());
      (min = set.pollFirst());
      if (((max->v - min->v) < r)) {
        (r = (max->v - min->v));
        (a = min->v);
        (b = max->v);
      }
      if (((min->j + 1) < nums.get(min->i).size())) {
        set.add(
            new Node(nums.get(min->i).get((min->j + 1)), min->i, (min->j + 1)));
      }
    }
    return Array<int>{a, b};
  }
};

/* Original teaching comments:
// 最小区间
// 你有k个非递减排列的整数列表
// 找到一个最小区间，使得k个列表中的每个列表至少有一个数包含在其中
// 测试链接 :
https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/
        // 时间复杂度O(n*logk)
        // n是数字总数，k是数组数量
                // 根据值排序
                // 为什么排序的时候i要参与
                // 因为有序表中比较相等的样本只会保留一个
                // 为了值一样的元素都保留，于是i要参与排序
                // 在有序表中的所有元素i必然都不同
*/
