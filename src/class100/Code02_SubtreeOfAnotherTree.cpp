// Source: src/class100/Code02_SubtreeOfAnotherTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_SubtreeOfAnotherTree {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_SubtreeOfAnotherTree() {}
  static bool isSubtree(TreeNode *t1, TreeNode *t2) {
    if (((t1 != nullptr) && (t2 != nullptr))) {
      return ((Code02_SubtreeOfAnotherTree::same(t1, t2) ||
               Code02_SubtreeOfAnotherTree::isSubtree(t1->left, t2)) ||
              Code02_SubtreeOfAnotherTree::isSubtree(t1->right, t2));
    }
    return (t2 == nullptr);
  }
  static bool same(TreeNode *a, TreeNode *b) {
    if (((a == nullptr) && (b == nullptr))) {
      return true;
    }
    if (((a != nullptr) && (b != nullptr))) {
      return (((a->val == b->val) &&
               Code02_SubtreeOfAnotherTree::same(a->left, b->left)) &&
              Code02_SubtreeOfAnotherTree::same(a->right, b->right));
    }
    return false;
  }
  static bool isSubtree2(TreeNode *t1, TreeNode *t2) {
    if (((t1 != nullptr) && (t2 != nullptr))) {
      JList<String> s1 = JList<String>();
      JList<String> s2 = JList<String>();
      Code02_SubtreeOfAnotherTree::serial(t1, s1);
      Code02_SubtreeOfAnotherTree::serial(t2, s2);
      return (Code02_SubtreeOfAnotherTree::kmp(s1, s2) != (-1));
    }
    return (t2 == nullptr);
  }
  static void serial(TreeNode *head, JList<String> path) {
    if ((head == nullptr)) {
      path.add(nullptr);
    } else {
      path.add(j::str(head->val));
      Code02_SubtreeOfAnotherTree::serial(head->left, path);
      Code02_SubtreeOfAnotherTree::serial(head->right, path);
    }
  }
  static int kmp(JList<String> s1, JList<String> s2) {
    int n = s1.size();
    int m = s2.size();
    int x = 0;
    int y = 0;
    Array<int> next = Code02_SubtreeOfAnotherTree::nextArray(s2, m);
    while (((x < n) && (y < m))) {
      if ([&]() {
            auto jargument_0 = s1.get(x);
            auto jargument_1 = s2.get(y);
            return Code02_SubtreeOfAnotherTree::isEqual(jargument_0,
                                                        jargument_1);
          }()) {
        (x++);
        (y++);
      } else if ((y == 0)) {
        (x++);
      } else {
        (y = next[y]);
      }
    }
    return ((y == m) ? (x - y) : (-1));
  }
  static Array<int> nextArray(JList<String> s, int m) {
    if ((m == 1)) {
      return Array<int>{(-1)};
    }
    Array<int> next = make_array<int>(m);
    (next[0] = (-1));
    (next[1] = 0);
    int i = 2;
    int cn = 0;
    while ((i < next.length)) {
      if ([&]() {
            auto jargument_0 = s.get((i - 1));
            auto jargument_1 = s.get(cn);
            return Code02_SubtreeOfAnotherTree::isEqual(jargument_0,
                                                        jargument_1);
          }()) {
        (next[(i++)] = (++cn));
      } else if ((cn > 0)) {
        (cn = next[cn]);
      } else {
        (next[(i++)] = 0);
      }
    }
    return next;
  }
  static bool isEqual(String a, String b) {
    if (((a == nullptr) && (b == nullptr))) {
      return true;
    }
    if (((a != nullptr) && (b != nullptr))) {
      return a.equals(b);
    }
    return false;
  }
};

/* Original teaching comments:
// 另一棵树的子树
// 给你两棵二叉树root和subRoot
// 检验root中是否包含和subRoot具有相同结构和节点值的子树
// 如果存在，返回true
// 否则，返回false
// 测试链接 : https://leetcode.cn/problems/subtree-of-another-tree/
        // 不要提交这个类
        // 方法1
        // 暴力递归
        // 时间复杂度O(n * m)
        // 判断a和b这两棵树是否完全一样
        // 方法2
        // 二叉树先序序列化 + KMP算法匹配
        // 时间复杂度O(n + m)
        // 比对两个字符串是否相等
        // a和b可能为null
*/
