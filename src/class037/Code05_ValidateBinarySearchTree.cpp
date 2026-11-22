// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/validate-binary-search-tree/

// Ported from class037/Code05_ValidateBinarySearchTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/
struct Code05_ValidateBinarySearchTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交以下的方法
	inline static int MAXN = 10001;

	inline static std::vector<TreeNode*> stack = std::vector<TreeNode*>(MAXN);

	inline static int r;

	// 提交时改名为isValidBST
	static bool isValidBST1(TreeNode* head) {
		if (head == nullptr) {
			return true;
		}
		TreeNode* pre = nullptr;
		r = 0;
		while (r > 0 || head != nullptr) {
			if (head != nullptr) {
				stack[r++] = head;
				head = head->left;
			} else {
				head = stack[--r];
				if (pre != nullptr && pre->val >= head->val) {
					return false;
				}
				pre = head;
				head = head->right;
			}
		}
		return true;
	};

	inline static long long min, max;

	// 提交时改名为isValidBST
	static bool isValidBST2(TreeNode* head) {
		if (head == nullptr) {
			min = LLONG_MAX;
			max = LLONG_MIN;
			return true;
		}
		bool lok = isValidBST2(head->left);
		long long lmin = min;
		long long lmax = max;
		bool rok = isValidBST2(head->right);
		long long rmin = min;
		long long rmax = max;
		min = std::min(std::min(lmin, rmin), static_cast<long long>(head->val));
		max = std::max(std::max(lmax, rmax), static_cast<long long>(head->val));
		return lok && rok && lmax < head->val && head->val < rmin;
	};

};
