// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/path-sum-ii/

// Ported from class037/Code03_PathSumII.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>


// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/
struct Code03_PathSumII {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交如下的方法
	static std::vector<std::vector<int>> pathSum(TreeNode* root, int aim) {
		std::vector<std::vector<int>> ans;
		if (root != nullptr) {
			std::vector<int> path = std::vector<int>();
			f(root, aim, 0, path, ans);
		}
		return ans;
	};

	static void f(TreeNode* cur, int aim, long long sum, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
		if (cur->left == nullptr && cur->right == nullptr) {
			// 叶节点
			if (cur->val + sum == aim) {
				path.push_back(cur->val);
				copy(path, ans);
				path.pop_back();
			}
		} else {
			// 不是叶节点
			path.push_back(cur->val);
			if (cur->left != nullptr) {
				f(cur->left, aim, sum + cur->val, path, ans);
			}
			if (cur->right != nullptr) {
				f(cur->right, aim, sum + cur->val, path, ans);
			}
			path.pop_back();
		}
	};

	static void copy(std::vector<int>& path, std::vector<std::vector<int>>& ans) {
		std::vector<int> copy = std::vector<int>();
		for (int num : path) {
			copy.push_back(num);
		}
		ans.push_back(copy);
	};

};
