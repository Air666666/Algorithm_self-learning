// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

// Ported from class036/Code05_PreorderSerializeAndDeserialize.java
// deserialize 接收 serialize 产生的有效格式；返回节点由调用者释放。
#include <deque>
#include <sstream>
#include <string>
#include <vector>


// 二叉树先序序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
struct Code05_PreorderSerializeAndDeserialize {

	// 不提交这个类
	struct TreeNode {
		int val;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		TreeNode(int v) {
			val = v;
		}
	};

    // 二叉树可以通过先序、后序或者按层遍历的方式序列化和反序列化
    // 但是，二叉树无法通过中序遍历的方式实现序列化和反序列化
    // 因为不同的两棵树，可能得到同样的中序序列，即便补了空位置也可能一样。
    // 比如如下两棵树
    //         __2
    //        /
    //       1
    //       和
    //       1__
    //          \
    //           2
    // 补足空位置的中序遍历结果都是{ nullptr, 1, nullptr, 2, nullptr}
	// 提交这个类
	struct Codec {
 static std::vector<std::string> split(const std::string& s){std::istringstream in(s);std::vector<std::string> v;std::string x;while(std::getline(in,x,','))v.push_back(x);return v;}

		std::string serialize(TreeNode* root) {
			std::string builder;
			f(root, builder);
			return builder;
		}

		void f(TreeNode* root, std::string& builder) {
			if (root == nullptr) {
				builder.append("#,");
			} else {
				builder.append(std::to_string(root->val) + ",");
				f(root->left, builder);
				f(root->right, builder);
			}
		}

		// leetcode增加了本题的限制
		// 不允许使用外部变量传递信息
		// 所以改用自带的队列结构
		// 消费队列中的字符串
		TreeNode* deserialize(std::string data) {
			std::deque<std::string> vals;
			for (std::string v : split(data)) {
				vals.push_back(v);
			}
			return g(vals);
		}

		TreeNode* g(std::deque<std::string>& vals) {
			std::string cur = ([&](){auto x=vals.front();vals.pop_front();return x;}());
			if (cur=="#") {
				return nullptr;
			} else {
				TreeNode* head = new TreeNode(std::stoi(cur));
				head->left = g(vals);
				head->right = g(vals);
				return head;
			}
		}

	};

};
