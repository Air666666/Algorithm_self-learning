// Ported from class037/Code01_LowestCommonAncestor.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 普通二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
struct Code01_LowestCommonAncestor {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交如下的方法
	static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q) {
			// 遇到空，或者p，或者q，直接返回
			return root;
		}
		TreeNode* l = lowestCommonAncestor(root->left, p, q);
		TreeNode* r = lowestCommonAncestor(root->right, p, q);
		if (l != nullptr && r != nullptr) {
			// 左树也搜到，右树也搜到，返回root
			return root;
		}
		if (l == nullptr && r == nullptr) {
			// 都没搜到返回空
			return nullptr;
		}
		// l和r一个为空，一个不为空
		// 返回不空的那个
		return l != nullptr ? l : r;
	};

};
