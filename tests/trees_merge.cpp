#include <cassert>
#include <random>
#define main tree_recursive_demo
#include "../src/class017/BinaryTreeTraversalRecursion.cpp"
#undef main
#define main tree_iterative_demo
#include "../src/class018/BinaryTreeTraversalIteration.cpp"
#undef main
#define main max_demo
#include "../src/class020/GetMaxValue.cpp"
#undef main
#define main merge_demo
#include "../src/class021/Code01_MergeSort.cpp"
#undef main
#include "../src/class021/Code02_MergeSort.cpp"
using T=BinaryTreeTraversalIteration;
void oracle(T::TreeNode* n,std::vector<int>& pre,std::vector<int>& in,std::vector<int>& post){if(!n)return;pre.push_back(n->val);oracle(n->left,pre,in,post);in.push_back(n->val);oracle(n->right,pre,in,post);post.push_back(n->val);}
int main(){
 std::mt19937 rng(43);
 for(int t=0;t<2000;++t){
  int n=rng()%100;std::vector<T::TreeNode*> nodes;for(int i=0;i<n;++i)nodes.push_back(new T::TreeNode(rng()%1000));
  for(int i=1;i<n;++i){auto p=nodes[(i-1)/2];if(i%2)p->left=nodes[i];else p->right=nodes[i];}
  auto h=n?nodes[0]:nullptr;std::vector<int>pre,in,post;oracle(h,pre,in,post);
  assert(T::preorderTraversal(h)==pre);assert(T::inorderTraversal(h)==in);assert(T::postorderTraversalOneStack(h)==post);assert(T::postorderTraversalTwoStacks(h)==post);T::destroy(h);
  std::vector<int>a(n);for(auto& x:a)x=static_cast<int>(rng()%2001)-1000;auto b=a;std::sort(b.begin(),b.end());
  if(n)assert(GetMaxValue::maxValue(a)==b.back());
  for(auto f:{Code02_MergeSort::mergeSort1,Code02_MergeSort::mergeSort2}){auto c=a;f(c);assert(c==b);}
  for(int mode=0;mode<2;++mode){Code01_MergeSort::n=n;std::copy(a.begin(),a.end(),Code01_MergeSort::arr.begin());if(mode)Code01_MergeSort::mergeSort1(0,n-1);else Code01_MergeSort::mergeSort2();assert(std::equal(b.begin(),b.end(),Code01_MergeSort::arr.begin()));}
 }
}
