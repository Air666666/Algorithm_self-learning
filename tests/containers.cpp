#include <algorithm>
#include <cassert>
#include <random>
#include "../src/class013/QueueStackAndCircularQueue.cpp"
#include "../src/class014/ConvertQueueAndStack.cpp"
#include "../src/class015/GetMinStack.cpp"
#include "../src/class016/CircularDeque.cpp"
int main(){
 std::mt19937 r(42);
 for(int cap:{0,1,2,7,30}){
  CircularDeque::MyCircularDeque1 a(cap);CircularDeque::MyCircularDeque2 b(cap);
  QueueStackAndCircularQueue::MyCircularQueue q(cap);std::deque<int> d,e;
  for(int t=0;t<10000;++t){
   int op=r()%4,v=static_cast<int>(r()%201)-100;bool ok;
   if(op<2){ok=d.size()<static_cast<unsigned>(cap);assert((op==0?a.insertFront(v):a.insertLast(v))==ok);assert((op==0?b.insertFront(v):b.insertLast(v))==ok);if(ok){if(op==0)d.push_front(v);else d.push_back(v);}}
   else{ok=!d.empty();assert((op==2?a.deleteFront():a.deleteLast())==ok);assert((op==2?b.deleteFront():b.deleteLast())==ok);if(ok){if(op==2)d.pop_front();else d.pop_back();}}
   assert(a.getFront()==(d.empty()?-1:d.front())&&b.getFront()==a.getFront());
   assert(a.getRear()==(d.empty()?-1:d.back())&&b.getRear()==a.getRear());
   if(r()%2){ok=e.size()<static_cast<unsigned>(cap);assert(q.enQueue(v)==ok);if(ok)e.push_back(v);}
   else{ok=!e.empty();assert(q.deQueue()==ok);if(ok)e.pop_front();}
   assert(q.Front()==(e.empty()?-1:e.front()));assert(q.Rear()==(e.empty()?-1:e.back()));
  }
 }
 ConvertQueueAndStack::MyQueue q;ConvertQueueAndStack::MyStack s;
 GetMinStack::MinStack1 a;GetMinStack::MinStack2 b;std::deque<int>d;std::vector<int>v;
 for(int t=0;t<10000;++t){
  if(v.empty()||r()%2){int x=r()%1000;v.push_back(x);d.push_back(x);q.push(x);s.push(x);a.push(x);b.push(x);}
  else{assert(q.pop()==d.front());d.pop_front();assert(s.pop()==v.back());v.pop_back();a.pop();b.pop();}
  assert(q.empty()==d.empty()&&s.empty()==v.empty());
  if(!v.empty()){assert(q.peek()==d.front()&&s.top()==v.back());int m=*std::min_element(v.begin(),v.end());assert(a.getMin()==m&&b.getMin()==m);assert(a.top()==v.back()&&b.top()==v.back());}
 }
}
