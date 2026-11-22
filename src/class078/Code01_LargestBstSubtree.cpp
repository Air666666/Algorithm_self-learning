// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/largest-bst-subtree/

// Source: src/class078/Code01_LargestBstSubtree.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code01_LargestBstSubtree {
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
    i64 max = {};
    i64 min = {};
    bool isBst = {};
    int maxBstSize = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(i64 a, i64 b, bool c, int d) {
      (max = a);
      (min = b);
      (isBst = c);
      (maxBstSize = d);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code01_LargestBstSubtree() {}
  static int largestBSTSubtree(TreeNode *root) {
    return Code01_LargestBstSubtree::f(root)->maxBstSize;
  }
  static Info *f(TreeNode *x) {
    if ((x == nullptr)) {
      return new Info(std::numeric_limits<i64>::min(),
                      std::numeric_limits<i64>::max(), true, 0);
    }
    Info *infol = Code01_LargestBstSubtree::f(x->left);
    Info *infor = Code01_LargestBstSubtree::f(x->right);
    i64 max = jmax(x->val, jmax(infol->max, infor->max));
    i64 min = jmin(x->val, jmin(infol->min, infor->min));
    bool isBst = (((infol->isBst && infor->isBst) && (infol->max < x->val)) &&
                  (x->val < infor->min));
    int maxBSTSize = {};
    if (isBst) {
      (maxBSTSize = ((infol->maxBstSize + infor->maxBstSize) + 1));
    } else {
      (maxBSTSize = jmax(infol->maxBstSize, infor->maxBstSize));
    }
    return new Info(max, min, isBst, maxBSTSize);
  }
};

/* Original teaching comments:
// 最大BST子树
// 给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小
// 其中，最大指的是子树节点数最多的
// 二叉搜索树（BST）中的所有节点都具备以下属性：
// 左子树的值小于其父（根）节点的值
// 右子树的值大于其父（根）节点的值
// 注意：子树必须包含其所有后代
// 测试链接 : https://leetcode.cn/problems/largest-bst-subtree/
        // 不要提交这个类
        // 提交如下的方法
                // 左 4信息
                // 右 4信息
                // x 整合出4信息返回
*/
