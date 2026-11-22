// Ported from class036/Code02_ZigzagLevelOrderTraversal.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>


// 二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
struct Code02_ZigzagLevelOrderTraversal {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交以下的方法
	// 用每次处理一层的优化bfs就非常容易实现
	// 如果测试数据量变大了就修改这个值
	inline static int MAXN = 2001;

	inline static std::vector<TreeNode*> queue = std::vector<TreeNode*>(MAXN);

	inline static int l, r;

	static std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
		std::vector<std::vector<int>> ans;
		if (root != nullptr) {
			l = r = 0;
			queue[r++] = root;
			// false 代表从左往右
			// true 代表从右往左
			bool reverse = false; 
			while (l < r) {
				int size = r - l;
				std::vector<int> list = std::vector<int>();
				// reverse == false, 左 -> 右， l....r-1, 收集size个
				// reverse == true,  右 -> 左， r-1....l, 收集size个
				// 左 -> 右, i = i + 1
				// 右 -> 左, i = i - 1
				for (int i = reverse ? r - 1 : l, j = reverse ? -1 : 1, k = 0; k < size; i += j, k++) {
					TreeNode* cur = queue[i];
					list.push_back(cur->val);
				}
				for (int i = 0; i < size; i++) {
					TreeNode* cur = queue[l++];
					if (cur->left != nullptr) {
						queue[r++] = cur->left;
					}
					if (cur->right != nullptr) {
						queue[r++] = cur->right;
					}
				}
				ans.push_back(list);
				reverse = !reverse;
			}
		}
		return ans;
	};

};
