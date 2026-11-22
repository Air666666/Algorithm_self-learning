// Ported from class036/Code06_LevelorderSerializeAndDeserialize.java
// deserialize 接收 serialize 产生的有效格式；返回节点由调用者释放。
#include <deque>
#include <sstream>
#include <string>
#include <vector>


// 二叉树按层序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
struct Code06_LevelorderSerializeAndDeserialize {

	// 不提交这个类
	struct TreeNode {
		int val;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(int v) {
			val = v;
		}
	};

	// 提交这个类
	// 按层序列化
	struct Codec {
 static std::vector<std::string> split(const std::string& s){std::istringstream in(s);std::vector<std::string> v;std::string x;while(std::getline(in,x,','))v.push_back(x);return v;}

		std::string serialize(TreeNode* root) {
			std::string builder;
			if (root != nullptr) {
				builder.append(std::to_string(root->val) + ",");
				// 修改了课上代码，改用自带的队列结构
				std::deque<TreeNode*> que;
				que.push_back(root);
				while (!que.empty()) {
					root = ([&](){auto x=que.front();que.pop_front();return x;}());
					if (root->left != nullptr) {
						builder.append(std::to_string(root->left->val) + ",");
						que.push_back(root->left);
					} else {
						builder.append("#,");
					}
					if (root->right != nullptr) {
						builder.append(std::to_string(root->right->val) + ",");
						que.push_back(root->right);
					} else {
						builder.append("#,");
					}
				}
			}
			return builder;
		}

		TreeNode* deserialize(std::string data) {
			if (data.empty()) {
				return nullptr;
			}
			std::vector<std::string> nodes = split(data);
			int index = 0;
			TreeNode* root = generate(nodes[index++]);
			// 修改了课上代码，改用自带的队列结构
			std::deque<TreeNode*> que;
			que.push_back(root);
			while (!que.empty()) {
				TreeNode* cur = ([&](){auto x=que.front();que.pop_front();return x;}());
				cur->left = generate(nodes[index++]);
				cur->right = generate(nodes[index++]);
				if (cur->left != nullptr) {
					que.push_back(cur->left);
				}
				if (cur->right != nullptr) {
					que.push_back(cur->right);
				}
			}
			return root;
		}

		TreeNode* generate(std::string val) {
			return val=="#" ? nullptr : new TreeNode(std::stoi(val));
		}

	};

};
