// Ported from algorithmzuo/algorithm-journey/src/class018/BinaryTreeTraversalIteration.java
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>


// 不用递归，用迭代的方式实现二叉树的三序遍历
struct BinaryTreeTraversalIteration {

	struct TreeNode {
		int val;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(int v) {
			val = v;
		}
	};
 static void destroy(TreeNode* p) { if(p){destroy(p->left);destroy(p->right);delete p;} }
 static TreeNode* popNode(std::vector<TreeNode*>& s){auto p=s.back();s.pop_back();return p;}


	// 先序打印所有节点，非递归版
	static void preOrder(TreeNode* head) {
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			stack.push_back(head);
			while (!stack.empty()) {
				head = popNode(stack);
				std::cout << head->val << " ";
				if (head->right != nullptr) {
					stack.push_back(head->right);
				}
				if (head->left != nullptr) {
					stack.push_back(head->left);
				}
			}
			std::cout << "\n";
		}
	};

	// 中序打印所有节点，非递归版
	static void inOrder(TreeNode* head) {
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			while (!stack.empty() || head != nullptr) {
				if (head != nullptr) {
					stack.push_back(head);
					head = head->left;
				} else {
					head = popNode(stack);
					std::cout << head->val << " ";
					head = head->right;
				}
			}
			std::cout << "\n";
		}
	};

	// 后序打印所有节点，非递归版
	// 这是用两个栈的方法
	static void posOrderTwoStacks(TreeNode* head) {
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			std::vector<TreeNode*> collect;
			stack.push_back(head);
			while (!stack.empty()) {
				head = popNode(stack);
				collect.push_back(head);
				if (head->left != nullptr) {
					stack.push_back(head->left);
				}
				if (head->right != nullptr) {
					stack.push_back(head->right);
				}
			}
			while (!collect.empty()) {
				std::cout << popNode(collect)->val << " ";
			}
			std::cout << "\n";
		}
	};

	// 后序打印所有节点，非递归版
	// 这是用一个栈的方法
	static void posOrderOneStack(TreeNode* h) {
		if (h != nullptr) {
			std::vector<TreeNode*> stack;
			stack.push_back(h);
			// 如果始终没有打印过节点，h就一直是头节点
			// 一旦打印过节点，h就变成打印节点
			// 之后h的含义 : 上一次打印的节点
			while (!stack.empty()) {
				TreeNode* cur = stack.back();
				if (cur->left != nullptr && h != cur->left && h != cur->right) {
					// 有左树且左树没处理过
					stack.push_back(cur->left);
				} else if (cur->right != nullptr && h != cur->right) {
					// 有右树且右树没处理过
					stack.push_back(cur->right);
				} else {
					// 左树、右树 没有 或者 都处理过了
					std::cout << cur->val << " ";
					h = popNode(stack);
				}
			}
			std::cout << "\n";
		}
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
		std::cout << "先序遍历非递归版" << "\n";
		inOrder(head);
		std::cout << "中序遍历非递归版" << "\n";
		posOrderTwoStacks(head);
		std::cout << "后序遍历非递归版 - 2个栈实现" << "\n";
		posOrderOneStack(head);
		std::cout << "后序遍历非递归版 - 1个栈实现" << "\n";
	destroy(head);
	};

	// 用一个栈完成先序遍历
	// 测试链接 : https://leetcode.cn/problems/binary-tree-preorder-traversal/
	static std::vector<int> preorderTraversal(TreeNode* head) {
		std::vector<int> ans = std::vector<int>();
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			stack.push_back(head);
			while (!stack.empty()) {
				head = popNode(stack);
				ans.push_back(head->val);
				if (head->right != nullptr) {
					stack.push_back(head->right);
				}
				if (head->left != nullptr) {
					stack.push_back(head->left);
				}
			}
		}
		return ans;
	};

	// 用一个栈完成中序遍历
	// 测试链接 : https://leetcode.cn/problems/binary-tree-inorder-traversal/
	static std::vector<int> inorderTraversal(TreeNode* head) {
		std::vector<int> ans = std::vector<int>();
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			while (!stack.empty() || head != nullptr) {
				if (head != nullptr) {
					stack.push_back(head);
					head = head->left;
				} else {
					head = popNode(stack);
					ans.push_back(head->val);
					head = head->right;
				}
			}
		}
		return ans;
	};

	// 用两个栈完成后序遍历
	// 提交时函数名改为postorderTraversal
	// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
	static std::vector<int> postorderTraversalTwoStacks(TreeNode* head) {
		std::vector<int> ans = std::vector<int>();
		if (head != nullptr) {
			std::vector<TreeNode*> stack;
			std::vector<TreeNode*> collect;
			stack.push_back(head);
			while (!stack.empty()) {
				head = popNode(stack);
				collect.push_back(head);
				if (head->left != nullptr) {
					stack.push_back(head->left);
				}
				if (head->right != nullptr) {
					stack.push_back(head->right);
				}
			}
			while (!collect.empty()) {
				ans.push_back(popNode(collect)->val);
			}
		}
		return ans;
	};

	// 用一个栈完成后序遍历
	// 提交时函数名改为postorderTraversal
	// 测试链接 : https://leetcode.cn/problems/binary-tree-postorder-traversal/
	static std::vector<int> postorderTraversalOneStack(TreeNode* h) {
		std::vector<int> ans = std::vector<int>();
		if (h != nullptr) {
			std::vector<TreeNode*> stack;
			stack.push_back(h);
			while (!stack.empty()) {
				TreeNode* cur = stack.back();
				if (cur->left != nullptr && h != cur->left && h != cur->right) {
					stack.push_back(cur->left);
				} else if (cur->right != nullptr && h != cur->right) {
					stack.push_back(cur->right);
				} else {
					ans.push_back(cur->val);
					h = popNode(stack);
				}
			}
		}
		return ans;
	};

};

int main(){ BinaryTreeTraversalIteration::runDemo(); return 0; }
