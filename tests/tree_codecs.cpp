#include <cassert>
#include <random>
#include "../src/class036/Code05_PreorderSerializeAndDeserialize.cpp"
#include "../src/class036/Code06_LevelorderSerializeAndDeserialize.cpp"
template<class N>bool equal(N*a,N*b){return (!a||!b)?a==b:a->val==b->val&&equal(a->left,b->left)&&equal(a->right,b->right);}
template<class N>void release(N*p){if(p){release(p->left);release(p->right);delete p;}}
template<class C>void check(){std::mt19937 rng(51);typename C::Codec codec;for(int t=0;t<1000;++t){int n=rng()%100;std::vector<typename C::TreeNode>v;v.reserve(n);for(int i=0;i<n;++i)v.emplace_back(static_cast<int>(rng()%201)-100);std::vector<typename C::TreeNode**>slots;if(n){slots.push_back(&v[0].left);slots.push_back(&v[0].right);}for(int i=1;i<n;++i){int k=rng()%slots.size();*slots[k]=&v[i];slots.erase(slots.begin()+k);slots.push_back(&v[i].left);slots.push_back(&v[i].right);}auto root=n?&v[0]:nullptr;auto s=codec.serialize(root);auto copy=codec.deserialize(s);assert(equal(root,copy));assert(codec.serialize(copy)==s);release(copy);}}
int main(){check<Code05_PreorderSerializeAndDeserialize>();check<Code06_LevelorderSerializeAndDeserialize>();}
