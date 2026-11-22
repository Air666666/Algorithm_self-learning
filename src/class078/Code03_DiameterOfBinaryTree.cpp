// Source: src/class078/Code03_DiameterOfBinaryTree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_DiameterOfBinaryTree {
  struct TreeNode;
  struct Info;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  struct Info {
    int diameter = {};
    int height = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(int a, int b) {
      (diameter = a);
      (height = b);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_DiameterOfBinaryTree() {}
  static int diameterOfBinaryTree(TreeNode *root) {
    return Code03_DiameterOfBinaryTree::f(root)->diameter;
  }
  static Info *f(TreeNode *x) {
    if ((x == nullptr)) {
      return new Info(0, 0);
    }
    Info *leftInfo = Code03_DiameterOfBinaryTree::f(x->left);
    Info *rightInfo = Code03_DiameterOfBinaryTree::f(x->right);
    int height = (jmax(leftInfo->height, rightInfo->height) + 1);
    int diameter = jmax(leftInfo->diameter, rightInfo->diameter);
    (diameter = jmax(diameter, (leftInfo->height + rightInfo->height)));
    return new Info(diameter, height);
  }
};

/* Original teaching comments:
// 二叉树的直径
// 给你一棵二叉树的根节点，返回该树的直径
// 二叉树的 直径 是指树中任意两个节点之间最长路径的长度
// 这条路径可能经过也可能不经过根节点 root
// 两节点之间路径的 长度 由它们之间边数表示
// 测试链接 : https://leetcode.cn/problems/diameter-of-binary-tree/
        // 不要提交这个类
        // 提交如下的方法
*/
