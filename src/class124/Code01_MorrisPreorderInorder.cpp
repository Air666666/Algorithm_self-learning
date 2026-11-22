// Source: src/class124/Code01_MorrisPreorderInorder.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_MorrisPreorderInorder {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_MorrisPreorderInorder() {}
  static void morris(TreeNode *head) {
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
        }
      }
      (cur = cur->right);
    }
  }
  static JList<int> preorderTraversal(TreeNode *head) {
    JList<int> ans = JList<int>();
    Code01_MorrisPreorderInorder::morrisPreorder(head, ans);
    return ans;
  }
  static void morrisPreorder(TreeNode *head, JList<int> ans) {
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    while ((cur != nullptr)) {
      (mostRight = cur->left);
      if ((mostRight != nullptr)) {
        while (((mostRight->right != nullptr) && (mostRight->right != cur))) {
          (mostRight = mostRight->right);
        }
        if ((mostRight->right == nullptr)) {
          ans.add(cur->val);
          (mostRight->right = cur);
          (cur = cur->left);
          continue;
        } else {
          (mostRight->right = nullptr);
        }
      } else {
        ans.add(cur->val);
      }
      (cur = cur->right);
    }
  }
  static JList<int> inorderTraversal(TreeNode *head) {
    JList<int> ans = JList<int>();
    Code01_MorrisPreorderInorder::morrisInorder(head, ans);
    return ans;
  }
  static void morrisInorder(TreeNode *head, JList<int> ans) {
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
        }
      }
      ans.add(cur->val);
      (cur = cur->right);
    }
  }
};

/* Original teaching comments:
// Morris遍历实现先序和中序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-preorder-traversal/
// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/
        // 不提交这个类
        // Morris遍历
                                // 找到左树最右节点
                                //
注意左树最右节点的右指针可能指向空，也可能指向cur
                                // 判断左树最右节点的右指针状态
        // Morris遍历实现先序遍历
        // 测试链接 :
https://leetcode.cn/problems/binary-tree-preorder-traversal/
        // 提交preorderTraversal方法，可以直接通过
                                // 找到左树最右节点
                                //
注意左树最右节点的右指针可能指向空，也可能指向cur
                                // 判断左树最右节点的右指针状态
        // Morris遍历实现中序遍历
        // 测试链接 :
https://leetcode.cn/problems/binary-tree-inorder-traversal/
        // 提交inorderTraversal方法，可以直接通过
                                // 找到左树最右节点
                                //
注意左树最右节点的右指针可能指向空，也可能指向cur
                                // 判断左树最右节点的右指针状态
*/
