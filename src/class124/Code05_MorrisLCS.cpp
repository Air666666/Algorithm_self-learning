// Source: src/class124/Code05_MorrisLCS.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code05_MorrisLCS {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code05_MorrisLCS() {}
  static TreeNode *lowestCommonAncestor(TreeNode *head, TreeNode *o1,
                                        TreeNode *o2) {
    if (((Code05_MorrisLCS::preOrder(o1->left, o1, o2) != nullptr) ||
         (Code05_MorrisLCS::preOrder(o1->right, o1, o2) != nullptr))) {
      return o1;
    }
    if (((Code05_MorrisLCS::preOrder(o2->left, o1, o2) != nullptr) ||
         (Code05_MorrisLCS::preOrder(o2->right, o1, o2) != nullptr))) {
      return o2;
    }
    TreeNode *left = Code05_MorrisLCS::preOrder(head, o1, o2);
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    TreeNode *lca = nullptr;
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
          if ((lca == nullptr)) {
            if (Code05_MorrisLCS::rightCheck(cur->left, left)) {
              if ((Code05_MorrisLCS::preOrder(left->right, o1, o2) !=
                   nullptr)) {
                (lca = left);
              }
              (left = cur);
            }
          }
        }
      }
      (cur = cur->right);
    }
    return ((lca != nullptr) ? lca : left);
  }
  static TreeNode *preOrder(TreeNode *head, TreeNode *o1, TreeNode *o2) {
    TreeNode *cur = head;
    TreeNode *mostRight = nullptr;
    TreeNode *ans = nullptr;
    while ((cur != nullptr)) {
      (mostRight = cur->left);
      if ((mostRight != nullptr)) {
        while (((mostRight->right != nullptr) && (mostRight->right != cur))) {
          (mostRight = mostRight->right);
        }
        if ((mostRight->right == nullptr)) {
          if (((ans == nullptr) && ((cur == o1) || (cur == o2)))) {
            (ans = cur);
          }
          (mostRight->right = cur);
          (cur = cur->left);
          continue;
        } else {
          (mostRight->right = nullptr);
        }
      } else {
        if (((ans == nullptr) && ((cur == o1) || (cur == o2)))) {
          (ans = cur);
        }
      }
      (cur = cur->right);
    }
    return ans;
  }
  static bool rightCheck(TreeNode *head, TreeNode *target) {
    while ((head != nullptr)) {
      if ((head == target)) {
        return true;
      }
      (head = head->right);
    }
    return false;
  }
};

/* Original teaching comments:
// Morris遍历求两个节点的最低公共祖先
// 测试链接 :
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
        // 不提交这个类
        // 提交以下的方法
                                                //
检查left是否在cur左树的右边界上
                                                        //
检查left看看右树里是否有o2
                                                        //
为什么此时检查的是left而不是cur
                                                        //
因为cur右树上的某些右指针可能没有恢复回来
                                                        //
需要等右指针恢复回来之后检查才不出错
                                                        //
所以此时检查的是left而不是cur
                                                        // 课上已经重点图解了
                // 如果morris遍历结束了还没有收集到答案
                // 此时最后一个left还没有验证，它一定是答案
        // 以head为头的树进行先序遍历，o1和o2谁先被找到就返回谁
        // 以head为头的树遍历右边界，返回是否找到了target
*/
