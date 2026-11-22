#include <cassert>
#include <climits>
#include "../src/class001/LanguageConversion.cpp"
#include "../src/class004/SelectBubbleInsert.cpp"
#define main binary_search_example_main
#define randomUnit findNumberRandom
#include "../src/class006/Code01_FindNumber.cpp"
#undef randomUnit
#undef main
#define main lower_bound_example_main
#define randomUnit findLeftRandom
#include "../src/class006/Code02_FindLeft.cpp"
#undef randomUnit
#undef main
#define main upper_bound_example_main
#define randomUnit findRightRandom
#include "../src/class006/Code03_FindRight.cpp"
#undef randomUnit
#undef main
#include "../src/class006/Code04_FindPeakElement.cpp"
#include "../src/class010/MergeTwoLists.cpp"
#include "../src/class011/AddTwoNumbers.cpp"
#include "../src/class012/PartitionList.cpp"
int main() {
 std::mt19937 rng(42);
 for(int t=0;t<2000;++t) {
  std::vector<int> a(rng()%80);
  for(auto& x:a)x=static_cast<int>(rng()%201)-100;
  auto expected=a;std::sort(expected.begin(),expected.end());
  for(auto f:{SelectBubbleInsert::selectionSort,SelectBubbleInsert::bubbleSort,SelectBubbleInsert::insertionSort,LanguageConversion::Solution::mergeSort,LanguageConversion::Solution::quickSort,LanguageConversion::Solution::heapSort}) {
   auto b=a; f(b); assert(b==expected);
  }
  for(int q:{INT_MIN,-100,-1,0,1,100,INT_MAX}) {
   assert(Code01_FindNumber::exist(expected,q)==std::binary_search(expected.begin(),expected.end(),q));
   auto l=std::lower_bound(expected.begin(),expected.end(),q);
   auto r=std::upper_bound(expected.begin(),expected.end(),q);
   assert(Code02_FindLeft::findLeft(expected,q)==(l==expected.end()?-1:l-expected.begin()));
   assert(Code03_FindRight::findRight(expected,q)==(r==expected.begin()?-1:r-expected.begin()-1));
  }
  if(a.empty())a.push_back(0);
  for(size_t i=1;i<a.size();++i)if(a[i]==a[i-1])++a[i];
  int k=Code04_FindPeakElement::Solution::findPeakElement(a);
  assert(k>=0 && k<static_cast<int>(a.size()));
  assert((k==0||a[k]>a[k-1])&&(k+1==static_cast<int>(a.size())||a[k]>a[k+1]));
 }
 {
  using N=MergeTwoLists::ListNode; N a(1),b(3),c(2);a.next=&b;
  N* h=MergeTwoLists::Solution::mergeTwoLists(&a,&c);
  assert(h==&a&&a.next==&c&&c.next==&b&&b.next==nullptr);
 }
 {
  using N=AddTwoNumbers::ListNode;N a(9),b(1);
  N* h=AddTwoNumbers::Solution::addTwoNumbers(&a,&b);
  assert(h->val==0&&h->next->val==1&&h->next->next==nullptr);
  delete h->next;delete h;
 }
 {
  using N=PartitionList::ListNode;N a(3),b(1),c(2);a.next=&b;b.next=&c;
  N* h=PartitionList::Solution::partition(&a,3);
  assert(h==&b&&b.next==&c&&c.next==&a&&a.next==nullptr);
 }
 std::cout<<"2000 randomized sorting/search/peak cases and linked-list checks passed\n";
}
