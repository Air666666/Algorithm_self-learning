#include <cassert>
#include <random>
#define main list_demo
#include "../src/class009/ListReverse.cpp"
#undef main
#include "../src/class019/Code01_FillFunction.cpp"
#define main matrix_dynamic_demo
#include "../src/class019/Code02_SpecifyAmount.cpp"
#undef main
#define main matrix_static_demo
#include "../src/class019/Code03_StaticSpace.cpp"
#undef main
#define main small_sum_demo
#include "../src/class022/Code01_SmallSum1.cpp"
#undef main
#include "../src/class022/Code02_ReversePairs.cpp"
#define main quick_demo
#include "../src/class023/Code01_QuickSort.cpp"
#undef main
#include "../src/class023/Code02_QuickSort.cpp"
#include "../src/class024/RandomizedSelect.cpp"
#define main heap_demo
#include "../src/class025/Code01_HeapSort.cpp"
#undef main
#include "../src/class025/Code02_HeapSort.cpp"
int main(){
 std::mt19937 rng(45);
 for(int t=0;t<2000;++t){
  int n=rng()%70;std::vector<int>a(n);for(auto&x:a)x=static_cast<int>(rng()%201)-100;
  if(n&&t%7==0)a[0]=INT_MIN;if(n>1&&t%11==0)a[1]=INT_MAX;
  auto sorted=a;std::sort(sorted.begin(),sorted.end());
  for(auto f:{Code02_QuickSort::quickSort1,Code02_QuickSort::quickSort2}){auto b=a;f(b,0,n-1);assert(b==sorted);}
  for(auto f:{Code02_HeapSort::heapSort1,Code02_HeapSort::heapSort2}){auto b=a;f(b);assert(b==sorted);}
  for(int mode=0;mode<2;++mode){
   Code01_QuickSort::n=n;std::copy(a.begin(),a.end(),Code01_QuickSort::arr.begin());
   if(mode)Code01_QuickSort::quickSort1(0,n-1);else Code01_QuickSort::quickSort2(0,n-1);
   assert(std::equal(sorted.begin(),sorted.end(),Code01_QuickSort::arr.begin()));
   Code01_HeapSort::n=n;std::copy(a.begin(),a.end(),Code01_HeapSort::arr.begin());
   if(mode)Code01_HeapSort::heapSort1();else Code01_HeapSort::heapSort2();
   assert(std::equal(sorted.begin(),sorted.end(),Code01_HeapSort::arr.begin()));
  }
  long long sum=0;int pairs=0;
  for(int j=0;j<n;++j)for(int i=0;i<j;++i){if(a[i]<=a[j])sum+=a[i];if(static_cast<long long>(a[i])>2LL*a[j])++pairs;}
  auto b=a;assert(Code02_ReversePairs::reversePairs(b)==pairs);
  std::copy(a.begin(),a.end(),Code01_SmallSum1::arr.begin());assert(Code01_SmallSum1::smallSum(0,n-1)==sum);
  for(int k=1;k<=n;++k){b=a;assert(RandomizedSelect::findKthLargest(b,k)==sorted[n-k]);}
 }
 for(int t=0;t<500;++t){
  int n=1+rng()%5,m=1+rng()%5;std::vector<std::vector<int>> a(n,std::vector<int>(m));
  for(auto&row:a)for(auto&x:row)x=static_cast<int>(rng()%21)-10;
  int best=INT_MIN;
  for(int i=0;i<n;++i)for(int j=i;j<n;++j)for(int l=0;l<m;++l)for(int r=l;r<m;++r){int s=0;for(int x=i;x<=j;++x)for(int y=l;y<=r;++y)s+=a[x][y];best=std::max(best,s);}
  assert(Code01_FillFunction::maxSumSubmatrix(a,n,m)==best);assert(Code02_SpecifyAmount::maxSumSubmatrix(a,n,m)==best);
  Code03_StaticSpace::n=n;Code03_StaticSpace::m=m;for(int i=0;i<n;++i)std::copy(a[i].begin(),a[i].end(),Code03_StaticSpace::mat[i].begin());assert(Code03_StaticSpace::maxSumSubmatrix()==best);
 }
 for(int n=0;n<100;++n){
  std::vector<ListReverse::ListNode> a;std::vector<ListReverse::DoubleListNode>b;for(int i=0;i<n;++i){a.emplace_back(i);b.emplace_back(i);}
  for(int i=0;i<n;++i){a[i].next=i+1<n?&a[i+1]:nullptr;b[i].next=i+1<n?&b[i+1]:nullptr;b[i].last=i?&b[i-1]:nullptr;}
  auto h=ListReverse::Solution::reverseList(n?&a[0]:nullptr);auto k=ListReverse::reverseDoubleList(n?&b[0]:nullptr);
  for(int i=n-1;i>=0;--i){assert(h==&a[i]&&k==&b[i]);assert(k->last==(i+1<n?&b[i+1]:nullptr));h=h->next;k=k->next;}assert(!h&&!k);
 }
}
