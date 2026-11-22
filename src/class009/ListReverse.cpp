// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/reverse-linked-list/

// Source: algorithmzuo/algorithm-journey/src/class009/ListReverse.java
// Java 的对象引用也是按值传递。这里用按值传递的指针演示：
// 重设局部指针不影响调用方；通过指针修改对象会影响同一对象。
#include <iostream>
#include <vector>
struct ListReverse {
 struct Number { int val; explicit Number(int v):val(v){} };
 static void f(int a){a=0;(void)a;}
 static void g1(Number* b){b=nullptr;(void)b;}
 static void g2(Number* b){b->val=6;}
 static void g3(std::vector<int>* c){c=nullptr;(void)c;}
 static void g4(std::vector<int>* c){(*c)[0]=100;}
 struct ListNode {
  int val;ListNode* next;
  explicit ListNode(int v,ListNode* n=nullptr):val(v),next(n){}
 };
 struct Solution {
  // 反转单链表：复用原节点，不分配新节点。
  static ListNode* reverseList(ListNode* head){
   ListNode* pre=nullptr;
   while(head){ListNode* next=head->next;head->next=pre;pre=head;head=next;}
   return pre;
  }
 };
 struct DoubleListNode {
  int value;DoubleListNode* last=nullptr;DoubleListNode* next=nullptr;
  explicit DoubleListNode(int v):value(v){}
 };
 static DoubleListNode* reverseDoubleList(DoubleListNode* head){
  DoubleListNode* pre=nullptr;
  while(head){DoubleListNode* next=head->next;head->next=pre;head->last=next;pre=head;head=next;}
  return pre;
 }
 static void runDemo(){
  int a=10;f(a);std::cout<<a<<'\n';
  Number b(5);g1(&b);std::cout<<b.val<<'\n';g2(&b);std::cout<<b.val<<'\n';
  std::vector<int> c{1,2,3,4};g3(&c);std::cout<<c[0]<<'\n';g4(&c);std::cout<<c[0]<<'\n';
 }
};
int main(){ListReverse::runDemo();return 0;}
