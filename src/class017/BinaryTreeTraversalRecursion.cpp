// Ported from algorithmzuo/algorithm-journey/src/class017/BinaryTreeTraversalRecursion.java
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

// 递归序的解释
// 用递归实现二叉树的三序遍历
struct BinaryTreeTraversalRecursion {

	struct TreeNode {
		int val;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(int v) {
			val = v;
		}
	};
 static void destroy(TreeNode* p) { if(p){destroy(p->left);destroy(p->right);delete p;} }


	// 递归基本样子，用来理解递归序
	static void f(TreeNode* head) {
		if (head == nullptr) {
			return;
		}
		// 1
		f(head->left);
		// 2
		f(head->right);
		// 3
	};

	// 先序打印所有节点，递归版
	static void preOrder(TreeNode* head) {
		if (head == nullptr) {
			return;
		}
		std::cout << head->val << " ";
		preOrder(head->left);
		preOrder(head->right);
	};

	// 中序打印所有节点，递归版
	static void inOrder(TreeNode* head) {
		if (head == nullptr) {
			return;
		}
		inOrder(head->left);
		std::cout << head->val << " ";
		inOrder(head->right);
	};

	// 后序打印所有节点，递归版
	static void posOrder(TreeNode* head) {
		if (head == nullptr) {
			return;
		}
		posOrder(head->left);
		posOrder(head->right);
		std::cout << head->val << " ";
	};

	static void runDemo() {
		TreeNode* head = new TreeNode(1);
		head->left = new TreeNode(2);
		head->right = new TreeNode(3);
		head->left->left = new TreeNode(4);
		head->left->right = new TreeNode(5);
		head->right->left = new TreeNode(6);
		head->right->right = new TreeNode(7);

		preOrder(head);
		std::cout << "\n";
		std::cout << "先序遍历递归版" << "\n";

		inOrder(head);
		std::cout << "\n";
		std::cout << "中序遍历递归版" << "\n";

		posOrder(head);
		std::cout << "\n";
		std::cout << "后序遍历递归版" << "\n";

	destroy(head);
	};

};

int main(){ BinaryTreeTraversalRecursion::runDemo(); return 0; }
