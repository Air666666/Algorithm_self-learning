// Source: src/class124/Code03_MorrisCheckBST.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_MorrisCheckBST {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_MorrisCheckBST() {}
  static bool isValidBST(TreeNode *head) {
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    TreeNode *pre = nullptr;
    bool ans = true;
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
      if (((pre != nullptr) && (pre->val >= cur->val))) {
        (ans = false);
      }
      (pre = cur);
      (cur = cur->right);
    }
    return ans;
  }
};

/* Original teaching comments:
// Morris遍历判断搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/
        // 不提交这个类
        // 提交如下的方法
                // 前一个遍历的节点
*/
