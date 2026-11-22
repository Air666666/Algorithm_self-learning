// Source: src/class078/Code04_DistributeCoins.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code04_DistributeCoins {
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
    int cnt = {};
    int sum = {};
    int move = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    Info(int a, int b, int c) {
      (cnt = a);
      (sum = b);
      (move = c);
    }
  };
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code04_DistributeCoins() {}
  static int distributeCoins(TreeNode *root) {
    return Code04_DistributeCoins::f(root)->move;
  }
  static Info *f(TreeNode *x) {
    if ((x == nullptr)) {
      return new Info(0, 0, 0);
    }
    Info *infol = Code04_DistributeCoins::f(x->left);
    Info *infor = Code04_DistributeCoins::f(x->right);
    int cnts = ((infol->cnt + infor->cnt) + 1);
    int sums = ((infol->sum + infor->sum) + x->val);
    int moves = [&]() {
      auto jleft =
          ((infol->move + infor->move) + std::abs((infol->cnt - infol->sum)));
      auto jright = std::abs((infor->cnt - infor->sum));
      return (jleft + jright);
    }();
    return new Info(cnts, sums, moves);
  }
};

/* Original teaching comments:
// 在二叉树中分配硬币
// 给你一个有 n 个结点的二叉树的根结点 root
// 其中树中每个结点 node 都对应有 node.val 枚硬币
// 整棵树上一共有 n 枚硬币
//
在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点
// 移动可以是从父结点到子结点，或者从子结点移动到父结点
// 返回使每个结点上 只有 一枚硬币所需的 最少 移动次数
// 测试链接 : https://leetcode.cn/problems/distribute-coins-in-binary-tree/
        // 不要提交这个类
        // 提交如下的方法
*/
