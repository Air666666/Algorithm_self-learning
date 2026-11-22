// Ported from class036/Code03_WidthOfBinaryTree1.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>

// 二叉树的最大特殊宽度，java版
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
struct Code03_WidthOfBinaryTree1 {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
	};

	// 提交以下的方法
	// 用每次处理一层的优化bfs就非常容易实现
	// 如果测试数据量变大了就修改这个值
	inline static int MAXN = 3001;

	inline static std::vector<TreeNode*> nq = std::vector<TreeNode*>(MAXN);

	inline static std::vector<std::uint64_t> iq = std::vector<std::uint64_t>(MAXN);

	inline static int l, r;

	static int widthOfBinaryTree(TreeNode* root) {
		if(root==nullptr)return 0;
 int ans = 1;
		l = r = 0;
		nq[r] = root;
		iq[r++] = 1;
		while (l < r) {
			int size = r - l;
 std::uint64_t base=iq[l];
			ans = std::max(ans, (int) (iq[r - 1] - iq[l] + 1));
			for (int i = 0; i < size; i++) {
				TreeNode* node = nq[l];
				std::uint64_t id = iq[l++] - base;
				if (node->left != nullptr) {
					nq[r] = node->left;
					iq[r++] = id * 2;
				}
				if (node->right != nullptr) {
					nq[r] = node->right;
					iq[r++] = id * 2 + 1;
				}
			}
		}
		return ans;
	};

};
