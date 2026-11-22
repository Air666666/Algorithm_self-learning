// Ported from class036/Code08_CompletenessOfBinaryTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>

// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
struct Code08_CompletenessOfBinaryTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交以下的方法
	// 如果测试数据量变大了就修改这个值
	inline static int MAXN = 101;

	inline static std::vector<TreeNode*> queue = std::vector<TreeNode*>(MAXN);

	inline static int l, r;

	static bool isCompleteTree(TreeNode* h) {
		if (h == nullptr) {
			return true;
		}
		l = r = 0;
		queue[r++] = h;
		// 是否遇到过左右两个孩子不双全的节点
		bool leaf = false;
		while (l < r) {
			h = queue[l++];
			if ((h->left == nullptr && h->right != nullptr) || (leaf && (h->left != nullptr || h->right != nullptr))) {
				return false;
			}
			if (h->left != nullptr) {
				queue[r++] = h->left;
			}
			if (h->right != nullptr) {
				queue[r++] = h->right;
			}
			if (h->left == nullptr || h->right == nullptr) {
				leaf = true;
			}
		}
		return true;
	};

};
