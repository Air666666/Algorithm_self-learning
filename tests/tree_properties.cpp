#include <cassert>
#include <functional>
#include <random>
#include "../src/class037/Code01_LowestCommonAncestor.cpp"
#include "../src/class037/Code02_LowestCommonAncestorBinarySearch.cpp"
#include "../src/class037/Code03_PathSumII.cpp"
#include "../src/class037/Code04_BalancedBinaryTree.cpp"
#include "../src/class037/Code05_ValidateBinarySearchTree.cpp"
#include "../src/class037/Code06_TrimBinarySearchTree.cpp"
#include "../src/class037/Code07_HouseRobberIII.cpp"
template<class N>void link(std::vector<N>&a,const std::vector<int>&v){for(size_t i=0;i<a.size();++i){a[i].val=v[i];a[i].left=2*i+1<a.size()?&a[2*i+1]:nullptr;a[i].right=2*i+2<a.size()?&a[2*i+2]:nullptr;}}
template<class N>void inorder(N* p,std::vector<int>&v){if(p){inorder(p->left,v);v.push_back(p->val);inorder(p->right,v);}}
int main(){std::mt19937 rng(50);
 for(int t=0;t<2000;++t){int n=rng()%13;std::vector<int>v(n);for(auto&x:v)x=rng()%10;
 {using C=Code01_LowestCommonAncestor;std::vector<C::TreeNode>a(n);link(a,v);if(n){int i=rng()%n,j=rng()%n,x=i,y=j;while(x!=y){if(x>y)x=(x-1)/2;else y=(y-1)/2;}assert(C::lowestCommonAncestor(&a[0],&a[i],&a[j])==&a[x]);}else assert(!C::lowestCommonAncestor(nullptr,nullptr,nullptr));}
 {using C=Code03_PathSumII;std::vector<C::TreeNode>a(n);link(a,v);int aim=rng()%30;std::vector<std::vector<int>>expected;for(int i=0;i<n;++i)if(2*i+1>=n){std::vector<int>p;int sum=0;for(int j=i;;j=(j-1)/2){sum+=v[j];p.push_back(v[j]);if(!j)break;}if(sum==aim){std::reverse(p.begin(),p.end());expected.push_back(p);}}auto got=C::pathSum(n?&a[0]:nullptr,aim);std::sort(got.begin(),got.end());std::sort(expected.begin(),expected.end());assert(got==expected);}
 {using C=Code04_BalancedBinaryTree;std::vector<C::TreeNode>a(n);link(a,v);assert(C::isBalanced(n?&a[0]:nullptr));for(int i=0;i<n;++i){a[i].left=i+1<n?&a[i+1]:nullptr;a[i].right=nullptr;}assert(C::isBalanced(n?&a[0]:nullptr)==(n<=2));assert(C::isBalanced(nullptr));}
 {using C=Code05_ValidateBinarySearchTree;std::vector<C::TreeNode>a(n);link(a,v);std::vector<int>order;inorder(n?&a[0]:nullptr,order);bool ok=true;for(int i=1;i<n;++i)ok&=order[i-1]<order[i];assert(C::isValidBST1(n?&a[0]:nullptr)==ok);assert(C::isValidBST2(n?&a[0]:nullptr)==ok);}
 {using C=Code07_HouseRobberIII;std::vector<C::TreeNode>a(n);link(a,v);int best=0;for(int mask=0;mask<(1<<n);++mask){bool ok=true;int sum=0;for(int i=0;i<n;++i)if(mask>>i&1){sum+=v[i];if(i&&(mask>>((i-1)/2)&1))ok=false;}if(ok)best=std::max(best,sum);}assert(C::rob(n?&a[0]:nullptr)==best);}
 }
 {using C=Code02_LowestCommonAncestorBinarySearch;C::TreeNode a,b,c;a.val=2;b.val=1;c.val=3;a.left=&b;a.right=&c;assert(C::lowestCommonAncestor(&a,&b,&c)==&a);assert(C::lowestCommonAncestor(&a,&a,&b)==&a);}
 for(int low=-1;low<11;++low)for(int high=low;high<12;++high){using C=Code06_TrimBinarySearchTree;std::vector<C::TreeNode>a(10);for(int i=0;i<10;++i){a[i].val=i;a[i].right=i<9?&a[i+1]:nullptr;}auto h=C::trimBST(&a[0],low,high);std::vector<int>got,expected;inorder(h,got);for(int i=0;i<10;++i)if(low<=i&&i<=high)expected.push_back(i);assert(got==expected);}
}
