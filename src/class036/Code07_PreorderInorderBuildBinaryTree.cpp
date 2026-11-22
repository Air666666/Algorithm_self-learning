// Ported from class036/Code07_PreorderInorderBuildBinaryTree.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <cstdint>
#include <deque>
#include <unordered_map>
#include <climits>
#include <cstdlib>
#include <vector>


// 利用先序与中序遍历序列构造二叉树
// 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
struct Code07_PreorderInorderBuildBinaryTree {

	// 不提交这个类
	struct TreeNode {
		int val = 0;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(int v) {
			val = v;
		}
	};

	// 提交如下的方法
	static TreeNode* buildTree(std::vector<int>& pre, std::vector<int>& in) {
		if (static_cast<int>(pre.size()) != static_cast<int>(in.size())) {
			return nullptr;
		}
		std::unordered_map<int,int> map;
		for (int i = 0; i < static_cast<int>(in.size()); i++) {
			map[in[i]]=i;
		}
		return f(pre, 0, static_cast<int>(pre.size()) - 1, in, 0, static_cast<int>(in.size()) - 1, map);
	};

	static TreeNode* f(std::vector<int>& pre, int l1, int r1, std::vector<int>& in, int l2, int r2, std::unordered_map<int,int>& map) {
		if (l1 > r1) {
			return nullptr;
		}
		TreeNode* head = new TreeNode(pre[l1]);
		if (l1 == r1) {
			return head;
		}
		int k = map.at(pre[l1]);
		// pre : l1(........)[.......r1]
		// in  : (l2......)k[........r2]
		// (...)是左树对应，[...]是右树的对应
		head->left = f(pre, l1 + 1, l1 + k - l2, in, l2, k - 1, map);
		head->right = f(pre, l1 + k - l2 + 1, r1, in, k + 1, r2, map);
		return head;
	};

};
