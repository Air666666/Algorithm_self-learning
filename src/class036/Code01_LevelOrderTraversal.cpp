// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/binary-tree-level-order-traversal/

// Ported from class036/Code01_LevelOrderTraversal.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>


// 二叉树的层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/
struct Code01_LevelOrderTraversal {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交时把方法名改为levelOrder，此方法为普通bfs，此题不推荐
	static std::vector<std::vector<int>> levelOrder1(TreeNode* root) {
		std::vector<std::vector<int>> ans;
		if (root != nullptr) {
			std::deque<TreeNode*> queue;
			std::unordered_map<TreeNode*,int> levels;
			queue.push_back(root);
			levels[root]=0;
			while (!queue.empty()) {
				TreeNode* cur = ([&](){auto p=queue.front();queue.pop_front();return p;}());
				int level = levels.at(cur);
				if (ans.size() == level) {
					ans.push_back(std::vector<int>());
				}
				ans[level].push_back(cur->val);
				if (cur->left != nullptr) {
					queue.push_back(cur->left);
					levels[cur->left]=level+1;
				}
				if (cur->right != nullptr) {
					queue.push_back(cur->right);
					levels[cur->right]=level+1;
				}
			}
		}
		return ans;
	};

	// 如果测试数据量变大了就修改这个值
	inline static int MAXN = 2001;

	inline static std::vector<TreeNode*> queue = std::vector<TreeNode*>(MAXN);

	inline static int l, r;

	// 提交时把方法名改为levelOrder，此方法为每次处理一层的优化bfs，此题推荐
	static std::vector<std::vector<int>> levelOrder2(TreeNode* root) {
		std::vector<std::vector<int>> ans;
		if (root != nullptr) {
			l = r = 0;
			queue[r++] = root;
			while (l < r) { // 队列里还有东西
				int size = r - l;
				std::vector<int> list = std::vector<int>();
				for (int i = 0; i < size; i++) {
					TreeNode* cur = queue[l++];
					list.push_back(cur->val);
					if (cur->left != nullptr) {
						queue[r++] = cur->left;
					}
					if (cur->right != nullptr) {
						queue[r++] = cur->right;
					}
				}
				ans.push_back(list);
			}
		}
		return ans;
	};

};
