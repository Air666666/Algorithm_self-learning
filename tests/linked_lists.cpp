#include <algorithm>
#include <cassert>
#include <random>
#include "../src/class034/Code01_IntersectionOfTwoLinkedLists.cpp"
#include "../src/class034/Code02_ReverseNodesInkGroup.cpp"
#include "../src/class034/Code03_CopyListWithRandomPointer.cpp"
#include "../src/class034/Code04_PalindromeLinkedList.cpp"
#include "../src/class034/Code05_LinkedListCycleII.cpp"
#include "../src/class034/Code06_SortList.cpp"
template<class N>void connect(std::vector<N>&a){for(size_t i=0;i<a.size();++i)a[i].next=i+1<a.size()?&a[i+1]:nullptr;}
int main(){std::mt19937 rng(49);
 for(int t=0;t<2000;++t){int n=rng()%70;
  {using C=Code02_ReverseNodesInkGroup;std::vector<C::ListNode>a(n);connect(a);std::vector<C::ListNode*>e;for(auto&x:a)e.push_back(&x);int k=1+rng()%10;for(int i=0;i+k<=n;i+=k)std::reverse(e.begin()+i,e.begin()+i+k);auto h=C::reverseKGroup(n?&a[0]:nullptr,k);for(auto p:e){assert(h==p);h=h->next;}assert(!h);}
  {using C=Code04_PalindromeLinkedList;std::vector<C::ListNode>a(n);connect(a);std::vector<int>v;for(auto&x:a){x.val=rng()%3;v.push_back(x.val);}bool e=std::equal(v.begin(),v.end(),v.rbegin());assert(C::isPalindrome(n?&a[0]:nullptr)==e);for(int i=0;i<n;++i)assert(a[i].next==(i+1<n?&a[i+1]:nullptr));}
  {using C=Code06_SortList;std::vector<C::ListNode>a(n);connect(a);std::vector<C::ListNode*>e;for(auto&x:a){x.val=rng()%7;e.push_back(&x);}std::stable_sort(e.begin(),e.end(),[](auto x,auto y){return x->val<y->val;});auto h=C::sortList(n?&a[0]:nullptr);for(auto p:e){assert(h==p);h=h->next;}assert(!h);}
  {using C=Code05_LinkedListCycleII;std::vector<C::ListNode>a(n);connect(a);int k=rng()%(n+1);auto entry=k<n?&a[k]:nullptr;if(n)a.back().next=entry;assert(C::detectCycle(n?&a[0]:nullptr)==entry);}
  {using C=Code03_CopyListWithRandomPointer;std::vector<C::Node>a;for(int i=0;i<n;++i)a.emplace_back(i);connect(a);std::vector<int>r;for(auto&x:a){int k=rng()%(n+1);r.push_back(k);x.random=k<n?&a[k]:nullptr;}auto h=C::copyRandomList(n?&a[0]:nullptr);std::vector<C::Node*>c;for(auto p=h;p;p=p->next)c.push_back(p);assert(c.size()==a.size());for(int i=0;i<n;++i){assert(c[i]!=&a[i]&&c[i]->val==a[i].val);assert(c[i]->random==(r[i]<n?c[r[i]]:nullptr));assert(a[i].next==(i+1<n?&a[i+1]:nullptr));assert(a[i].random==(r[i]<n?&a[r[i]]:nullptr));}for(auto p:c)delete p;}
 }
 {using C=Code01_IntersectionOfTwoLinkedLists;C::ListNode a,b,c;a.next=&c;b.next=&c;assert(C::getIntersectionNode(&a,&b)==&c);b.next=nullptr;assert(!C::getIntersectionNode(&a,&b));assert(!C::getIntersectionNode(nullptr,&a));}
}
