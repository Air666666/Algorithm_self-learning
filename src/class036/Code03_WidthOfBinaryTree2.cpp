// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/maximum-width-of-binary-tree/

// Restored upstream C++: src/class036/Code03_WidthOfBinaryTree2.java
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;
// 本地编译用节点定义；在线评测已有 TreeNode 时可删除此定义。
struct TreeNode{int val;TreeNode* left=nullptr;TreeNode* right=nullptr;explicit TreeNode(int v):val(v){}};


// 二叉树的最大特殊宽度，C++版
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
// 如下实现是C++的版本，C++版本和java版本逻辑完全一样
// 提交如下代码，可以通过所有测试用例

using ULL = unsigned long long;

class Solution {
public:
   static const int MAXN = 3001;
   TreeNode* nq[MAXN];
   ULL iq[MAXN];
   int l, r;

   int widthOfBinaryTree(TreeNode* root) {
       int ans = 1;
       l = r = 0;
       nq[r] = root;
       iq[r++] = 1ULL;
       while (l < r) {
           int size = r - l;
           ans = std::max(ans, (int)(iq[r - 1] - iq[l] + 1));
           for (int i = 0; i < size; i++) {
               TreeNode* node = nq[l];
               ULL id = iq[l++];
               if (node->left != nullptr) {
                   nq[r] = node->left;
                   iq[r++] = id * 2ULL;
               }
               if (node->right != nullptr) {
                   nq[r] = node->right;
                   iq[r++] = id * 2ULL + 1ULL;
               }
           }
       }
       return ans;
   }
};
