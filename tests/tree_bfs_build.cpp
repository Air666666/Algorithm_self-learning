#include <cassert>
#include <functional>
#include "../src/class036/Code01_LevelOrderTraversal.cpp"
#include "../src/class036/Code02_ZigzagLevelOrderTraversal.cpp"
#include "../src/class036/Code03_WidthOfBinaryTree1.cpp"
#include "../src/class036/Code04_DepthOfBinaryTree.cpp"
#include "../src/class036/Code07_PreorderInorderBuildBinaryTree.cpp"
#include "../src/class036/Code08_CompletenessOfBinaryTree.cpp"
#include "../src/class036/Code09_CountCompleteTreeNodes.cpp"
template<class N>void link(std::vector<N>&a){for(size_t i=0;i<a.size();++i){a[i].val=i;a[i].left=2*i+1<a.size()?&a[2*i+1]:nullptr;a[i].right=2*i+2<a.size()?&a[2*i+2]:nullptr;}}
template<class N>void orders(N*p,std::vector<int>&pre,std::vector<int>&in){if(p){pre.push_back(p->val);orders(p->left,pre,in);in.push_back(p->val);orders(p->right,pre,in);}}
template<class N>void release(N*p){if(p){release(p->left);release(p->right);delete p;}}
int main(){for(int n=0;n<=100;++n){
 std::vector<std::vector<int>>expected;for(int start=0,width=1;start<n;start+=width,width*=2){std::vector<int>row;for(int j=start;j<std::min(n,start+width);++j)row.push_back(j);expected.push_back(row);}
 {using C=Code01_LevelOrderTraversal;std::vector<C::TreeNode>a(n);link(a);assert(C::levelOrder1(n?&a[0]:nullptr)==expected);assert(C::levelOrder2(n?&a[0]:nullptr)==expected);}
 {using C=Code02_ZigzagLevelOrderTraversal;std::vector<C::TreeNode>a(n);link(a);auto e=expected;for(size_t i=1;i<e.size();i+=2)std::reverse(e[i].begin(),e[i].end());assert(C::zigzagLevelOrder(n?&a[0]:nullptr)==e);}
 {using C=Code03_WidthOfBinaryTree1;std::vector<C::TreeNode>a(n);link(a);int width=0;for(auto row:expected)width=std::max(width,static_cast<int>(row.size()));assert(C::widthOfBinaryTree(n?&a[0]:nullptr)==width);for(int i=0;i<n;++i){a[i].left=nullptr;a[i].right=i+1<n?&a[i+1]:nullptr;}assert(C::widthOfBinaryTree(n?&a[0]:nullptr)==(n?1:0));}
 {using C=Code04_DepthOfBinaryTree;std::vector<C::TreeNode>a(n);link(a);assert(C::maxDepth(n?&a[0]:nullptr)==static_cast<int>(expected.size()));int mind=0;for(int i=0;i<n;++i)if(2*i+1>=n){int j=i;mind=1;while(j){j=(j-1)/2;++mind;}break;}assert(C().minDepth(n?&a[0]:nullptr)==mind);}
 {using C=Code08_CompletenessOfBinaryTree;std::vector<C::TreeNode>a(n);link(a);assert(C::isCompleteTree(n?&a[0]:nullptr));if(n>1){a[0].left=nullptr;a[0].right=&a[1];assert(!C::isCompleteTree(&a[0]));}}
 {using C=Code09_CountCompleteTreeNodes;std::vector<C::TreeNode>a(n);link(a);assert(C::countNodes(n?&a[0]:nullptr)==n);}
 {using C=Code07_PreorderInorderBuildBinaryTree;std::vector<C::TreeNode>a;for(int i=0;i<n;++i)a.emplace_back(i);link(a);std::vector<int>pre,in,p2,i2;orders(n?&a[0]:nullptr,pre,in);auto h=C::buildTree(pre,in);orders(h,p2,i2);assert(pre==p2&&in==i2);release(h);}
}}
