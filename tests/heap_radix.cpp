#include <cassert>
#include <climits>
#include <random>
#include "../src/class027/Code01_MergeKSortedLists.cpp"
#define main cover_demo
#include "../src/class027/Code02_MaxCover.cpp"
#undef main
#include "../src/class027/Code03_MinimumOperationsToHalveArraySum.cpp"
#define main radix_demo
#include "../src/class028/Code01_RadixSort.cpp"
#undef main
#include "../src/class028/Code02_RadixSort.cpp"
int main(){std::mt19937 rng(47);
 for(int t=0;t<2000;++t){
  int n=rng()%70;std::vector<int>a(n);for(auto&x:a)x=static_cast<int>(rng()%201)-100;if(n&&t%3==0)a[0]=INT_MIN;if(n>1&&t%5==0)a[1]=INT_MAX;
  auto expect=a;std::sort(expect.begin(),expect.end());auto b=a;assert(Code02_RadixSort::sortArray(b)==expect);Code01_RadixSort::n=n;std::copy(a.begin(),a.end(),Code01_RadixSort::arr.begin());Code01_RadixSort::sort();assert(std::equal(expect.begin(),expect.end(),Code01_RadixSort::arr.begin()));
  using N=Code01_MergeKSortedLists::ListNode;std::vector<N>nodes(n);std::vector<N*>heads(4,nullptr),tails(4,nullptr);for(int i=0;i<n;++i){nodes[i].val=expect[i];int k=rng()%4;if(tails[k])tails[k]->next=&nodes[i];else heads[k]=&nodes[i];tails[k]=&nodes[i];}auto h=Code01_MergeKSortedLists::mergeKLists(heads);for(int x:expect){assert(h&&h->val==x);h=h->next;}assert(!h);
  std::vector<std::vector<int>>m(n,std::vector<int>(2));for(auto&v:m){v[0]=rng()%20;v[1]=v[0]+1+rng()%10;}int open=0,closed=0;for(int q=0;q<=60;++q){int x=0,y=0;for(auto v:m){x+=(2*v[0]<q&&q<2*v[1]);y+=(2*v[0]<=q&&q<=2*v[1]);}open=std::max(open,x);closed=std::max(closed,y);}auto c=m;assert(Code02_MaxCover::minMeetingRooms(c)==open);assert(Code02_MaxCover::minGroups(c)==closed);Code02_MaxCover::n=n;for(int i=0;i<n;++i)Code02_MaxCover::line[i]=m[i];assert(Code02_MaxCover::compute()==open);
  std::vector<int>positive(n);std::vector<double>d(n);double total=0;for(int i=0;i<n;++i){positive[i]=1+rng()%10000000;d[i]=positive[i];total+=d[i];}double reduced=0;int steps=0;while(reduced<total/2){auto it=std::max_element(d.begin(),d.end());*it/=2;reduced+=*it;++steps;}assert(Code03_MinimumOperationsToHalveArraySum::halveArray1(positive)==steps);assert(Code03_MinimumOperationsToHalveArraySum::halveArray2(positive)==steps);
 }
}
