// Ported from class036/Code04_DepthOfBinaryTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>

// 求二叉树的最大、最小深度
struct Code04_DepthOfBinaryTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
	static int maxDepth(TreeNode* root) {
		return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	};

	// 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			// 当前的树是空树
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr) {
			// 当前root是叶节点
			return 1;
		}
		int ldeep = INT_MAX;
		int rdeep = INT_MAX;
		if (root->left != nullptr) {
			ldeep = minDepth(root->left);
		}
		if (root->right != nullptr) {
			rdeep = minDepth(root->right);
		}
		return std::min(ldeep, rdeep) + 1;
	};

};
