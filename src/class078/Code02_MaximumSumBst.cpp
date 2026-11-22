// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

// Source: src/class078/Code02_MaximumSumBst.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code02_MaximumSumBst {
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
    int max = {};
    int min = {};
    int sum = {};
    bool isBst = {};
    int maxBstSum = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(int a, int b, int c, bool d, int e) {
      (max = a);
      (min = b);
      (sum = c);
      (isBst = d);
      (maxBstSum = e);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code02_MaximumSumBst() {}
  static int maxSumBST(TreeNode *root) {
    return Code02_MaximumSumBst::f(root)->maxBstSum;
  }
  static Info *f(TreeNode *x) {
    if ((x == nullptr)) {
      return new Info(std::numeric_limits<int>::min(),
                      std::numeric_limits<int>::max(), 0, true, 0);
    }
    Info *infol = Code02_MaximumSumBst::f(x->left);
    Info *infor = Code02_MaximumSumBst::f(x->right);
    int max = jmax(x->val, jmax(infol->max, infor->max));
    int min = jmin(x->val, jmin(infol->min, infor->min));
    int sum = ((infol->sum + infor->sum) + x->val);
    bool isBst = (((infol->isBst && infor->isBst) && (infol->max < x->val)) &&
                  (x->val < infor->min));
    int maxBstSum = jmax(infol->maxBstSum, infor->maxBstSum);
    if (isBst) {
      (maxBstSum = jmax(maxBstSum, sum));
    }
    return new Info(max, min, sum, isBst, maxBstSum);
  }
};

/* Original teaching comments:
// 二叉搜索子树的最大键值和
// 给你一棵以 root 为根的二叉树
// 请你返回 任意 二叉搜索子树的最大键值和
// 二叉搜索树的定义如下：
// 任意节点的左子树中的键值都 小于 此节点的键值
// 任意节点的右子树中的键值都 大于 此节点的键值
// 任意节点的左子树和右子树都是二叉搜索树
// 测试链接 : https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/
        // 不要提交这个类
        // 提交如下的方法
                // 为什么这里的max和min是int类型？
                // 因为题目的数据量规定，
                // 节点值在[-4 * 10^4，4 * 10^4]范围
                // 所以int类型的最小值和最大值就够用了
                // 不需要用long类型
*/
