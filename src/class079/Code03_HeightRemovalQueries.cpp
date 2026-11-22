// Source: src/class079/Code03_HeightRemovalQueries.java
// Generated from the Java AST; shared-reference arrays preserve Java mutation
// semantics.
#include "../../include/jcompat.hpp"
using namespace j;
struct Code03_HeightRemovalQueries {
  struct TreeNode;
  struct TreeNode {
    int val = {};
    TreeNode *left = {};
    TreeNode *right = {};
    String toString() const { return j::str(static_cast<const void *>(this)); }
    TreeNode() {}
  };
  inline static int MAXN = 100010;
  inline static Array<int> dfn = make_array<int>(MAXN);
  inline static Array<int> deep = make_array<int>(MAXN);
  inline static Array<int> size = make_array<int>(MAXN);
  inline static Array<int> maxl = make_array<int>(MAXN);
  inline static Array<int> maxr = make_array<int>(MAXN);
  inline static int dfnCnt = {};
  String toString() const { return j::str(static_cast<const void *>(this)); }
  Code03_HeightRemovalQueries() {}
  static Array<int> treeQueries(TreeNode *root, Array<int> queries) {
    (dfnCnt = 0);
    Code03_HeightRemovalQueries::f(root, 0);
    for (int i = 1; (i <= dfnCnt); (i++)) {
      (maxl[i] = jmax(maxl[(i - 1)], deep[i]));
    }
    (maxr[(dfnCnt + 1)] = 0);
    for (int i = dfnCnt; (i >= 1); (i--)) {
      (maxr[i] = jmax(maxr[(i + 1)], deep[i]));
    }
    int m = queries.length;
    Array<int> ans = make_array<int>(m);
    for (int i = 0; (i < m); (i++)) {
      int leftMax = maxl[(dfn[queries[i]] - 1)];
      int rightMax = maxr[(dfn[queries[i]] + size[dfn[queries[i]]])];
      (ans[i] = jmax(leftMax, rightMax));
    }
    return ans;
  }
  static void f(TreeNode *x, int k) {
    int i = (++dfnCnt);
    (dfn[x->val] = i);
    (deep[i] = k);
    (size[i] = 1);
    if ((x->left != nullptr)) {
      Code03_HeightRemovalQueries::f(x->left, (k + 1));
      (size[i] += size[dfn[x->left->val]]);
    }
    if ((x->right != nullptr)) {
      Code03_HeightRemovalQueries::f(x->right, (k + 1));
      (size[i] += size[dfn[x->right->val]]);
    }
  }
};

/* Original teaching comments:
// 移除子树后的二叉树高度
// 给你一棵 二叉树 的根节点 root ，树中有 n 个节点
// 每个节点都可以被分配一个从 1 到 n 且互不相同的值
// 另给你一个长度为 m 的数组 queries
// 你必须在树上执行 m 个 独立 的查询，其中第 i 个查询你需要执行以下操作：
// 从树中 移除 以 queries[i] 的值作为根节点的子树
// 题目所用测试用例保证 queries[i] 不等于根节点的值
// 返回一个长度为 m 的数组 answer
// 其中 answer[i] 是执行第 i 个查询后树的高度
// 注意：
// 查询之间是独立的，所以在每个查询执行后，树会回到其初始状态
// 树的高度是从根到树中某个节点的 最长简单路径中的边数
// 测试链接 :
https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/
        // 不要提交这个类
        // 提交如下的方法
        // 下标为节点的值
        // 下标为dfn序号
        // 下标为dfn序号
        // 来到x节点，从头节点到x节点经过了k条边
*/
