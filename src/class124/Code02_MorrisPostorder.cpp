// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/binary-tree-postorder-traversal/

// Source: src/class124/Code02_MorrisPostorder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MorrisPostorder {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MorrisPostorder() {}
  static JList<int> postorderTraversal(TreeNode *head) {
    JList<int> ans = JList<int>();
    Code02_MorrisPostorder::morrisPostorder(head, ans);
    return ans;
  }
  static void morrisPostorder(TreeNode *head, JList<int> ans) {
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while ((cur != nullptr)) {
      (mostRight = cur->left);
      if ((mostRight != nullptr)) {
        while (((mostRight->right != nullptr) && (mostRight->right != cur))) {
          (mostRight = mostRight->right);
        }
        if ((mostRight->right == nullptr)) {
          (mostRight->right = cur);
          (cur = cur->left);
          continue;
        } else {
          (mostRight->right = nullptr);
          Code02_MorrisPostorder::collect(cur->left, ans);
        }
      }
      (cur = cur->right);
    }
    Code02_MorrisPostorder::collect(head, ans);
  }
  static void collect(TreeNode *head, JList<int> ans) {
    TreeNode *tail = Code02_MorrisPostorder::reverse(head);
    TreeNode *cur = tail;
    while ((cur != nullptr)) {
      ans.add(cur->val);
      (cur = cur->right);
    }
    Code02_MorrisPostorder::reverse(tail);
  }
  static TreeNode *reverse(TreeNode *from) {
    TreeNode *pre = nullptr;
    TreeNode *next = nullptr;
    while ((from != nullptr)) {
      (next = from->right);
      (from->right = pre);
      (pre = from);
      (from = next);
    }
    return pre;
  }
};

/* Original teaching comments:
// Morris遍历实现后序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
        // 不提交这个类
        // 提交如下的方法
                                // 找到左树最右节点
                                //
注意左树最右节点的右指针可能指向空，也可能指向cur
                                // 判断左树最右节点的右指针状态
        // 以head为头的子树，树的右边界逆序收集
        // 从from出发，类似单链表翻转，去翻转right指针的方向
*/
