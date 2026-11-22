// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/balanced-binary-tree/

// Ported from class037/Code04_BalancedBinaryTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 验证平衡二叉树
// 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/
struct Code04_BalancedBinaryTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交如下的方法
	inline static bool balance;

	static bool isBalanced(TreeNode* root) {
		// balance是全局变量，所有调用过程共享
		// 所以每次判断开始时，设置为true
		balance = true;
		height(root);
		return balance;
	};

	// 一旦发现不平衡，返回什么高度已经不重要了
	static int height(TreeNode* cur) {
		if (!balance || cur == nullptr) {
			return 0;
		}
		int lh = height(cur->left);
		int rh = height(cur->right);
		if (std::abs(lh - rh) > 1) {
			balance = false;
		}
		return std::max(lh, rh) + 1;
	};

};
