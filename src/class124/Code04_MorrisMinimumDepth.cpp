// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/

// Source: src/class124/Code04_MorrisMinimumDepth.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_MorrisMinimumDepth {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_MorrisMinimumDepth() {}
  static int minDepth(TreeNode *head) {
    if ((head == nullptr)) {
      return 0;
    }
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    int preLevel = 0;
    int rightLen = {};
    int ans = std::numeric_limits<int>::max();
    while ((cur != nullptr)) {
      (mostRight = cur->left);
      if ((mostRight != nullptr)) {
        (rightLen = 1);
        while (((mostRight->right != nullptr) && (mostRight->right != cur))) {
          (rightLen++);
          (mostRight = mostRight->right);
        }
        if ((mostRight->right == nullptr)) {
          (preLevel++);
          (mostRight->right = cur);
          (cur = cur->left);
          continue;
        } else {
          if ((mostRight->left == nullptr)) {
            (ans = jmin(ans, preLevel));
          }
          (preLevel -= rightLen);
          (mostRight->right = nullptr);
        }
      } else {
        (preLevel++);
      }
      (cur = cur->right);
    }
    (rightLen = 1);
    (cur = head);
    while ((cur->right != nullptr)) {
      (rightLen++);
      (cur = cur->right);
    }
    if ((cur->left == nullptr)) {
      (ans = jmin(ans, rightLen));
    }
    return ans;
  }
};

/* Original teaching comments:
// Morris遍历求二叉树最小高度
// 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
        // 不提交这个类
        // 提交如下的方法
                // morris遍历中，上一个节点所在的层数
                // 树的右边界长度
                // 不要忘了整棵树的最右节点
                // 整棵树的最右节点是叶节点才纳入统计
*/
