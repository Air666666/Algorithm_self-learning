// Ported from class037/Code06_TrimBinarySearchTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 修剪搜索二叉树
// 测试链接 : https://leetcode.cn/problems/trim-a-binary-search-tree/
struct Code06_TrimBinarySearchTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交以下的方法
	// [low, high]
	static TreeNode* trimBST(TreeNode* cur, int low, int high) {
		if (cur == nullptr) {
			return nullptr;
		}
		if (cur->val < low) {
			return trimBST(cur->right, low, high);
		}
		if (cur->val > high) {
			return trimBST(cur->left, low, high);
		}
		// cur在范围中
		cur->left = trimBST(cur->left, low, high);
		cur->right = trimBST(cur->right, low, high);
		return cur;
	};

};
