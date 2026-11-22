// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/path-sum-iii/

// Source: src/class078/Code07_PathSumIII.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code07_PathSumIII {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  inline static int ans = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code07_PathSumIII() {}
  static int pathSum(TreeNode *root, int sum) {
    JMap<i64, int> presum = JMap<i64, int>();
    presum.put(0LL, 1);
    (ans = 0);
    Code07_PathSumIII::f(root, sum, 0, presum);
    return ans;
  }
  static void f(TreeNode *x, int target, i64 sum, JMap<i64, int> presum) {
    if ((x != nullptr)) {
      (sum += x->val);
      (ans += presum.getOrDefault((sum - target), 0));
      presum.put(sum, (presum.getOrDefault(sum, 0) + 1));
      Code07_PathSumIII::f(x->left, target, sum, presum);
      Code07_PathSumIII::f(x->right, target, sum, presum);
      presum.put(sum, (presum.get(sum) - 1));
    }
  }
};

/* Original teaching comments:
// 路径总和 III
// 给定一个二叉树的根节点 root ，和一个整数 targetSum
// 求该二叉树里节点值之和等于 targetSum 的 路径 的数目
// 路径 不需要从根节点开始，也不需要在叶子节点结束
// 但是路径方向必须是向下的（只能从父节点到子节点）
// 测试链接 : https://leetcode.cn/problems/path-sum-iii/
        // 不要提交这个类
        // 提交如下的方法
        // sum : 从头节点出发，来到x的时候，上方累加和是多少
        //
路径必须以x作为结尾，路径累加和是target的路径数量，累加到全局变量ans上
*/
