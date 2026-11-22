// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/house-robber-iii/

// Ported from class037/Code07_HouseRobberIII.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/
struct Code07_HouseRobberIII {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交如下的方法
	static int rob(TreeNode* root) {
		f(root);
		return std::max(yes, no);
	};

	// 全局变量，完成了X子树的遍历，返回之后
	// yes变成，X子树在偷头节点的情况下，最大的收益
	inline static int yes;

	// 全局变量，完成了X子树的遍历，返回之后
	// no变成，X子树在不偷头节点的情况下，最大的收益
	inline static int no;

	static void f(TreeNode* root) {
		if (root == nullptr) {
			yes = 0;
			no = 0;
		} else {
			int y = root->val;
			int n = 0;
			f(root->left);
			y += no;
			n += std::max(yes, no);
			f(root->right);
			y += no;
			n += std::max(yes, no);
			yes = y;
			no = n;
		}
	};

};
