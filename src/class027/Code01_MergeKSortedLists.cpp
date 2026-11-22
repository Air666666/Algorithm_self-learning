// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6

// Ported from class027/Code01_MergeKSortedLists.java
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>


// 合并K个有序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6
struct Code01_MergeKSortedLists {

	// 不要提交这个类
	struct ListNode {
		int val=0;
		ListNode* next=nullptr;
	};

	// 提交以下的方法
	static ListNode* mergeKLists(std::vector<ListNode*> arr) {
		// 小根堆
		auto cmp=[](ListNode* a,ListNode* b){return a->val>b->val;};
 std::priority_queue<ListNode*,std::vector<ListNode*>,decltype(cmp)> heap(cmp);
		for (ListNode* h : arr) {
			// 遍历所有的头！
			if (h != nullptr) {
				heap.push(h);
			}
		}
		if (heap.empty()) {
			return nullptr;
		}
		// 先弹出一个节点，做总头部
		ListNode* h = ([&](){auto x=heap.top();heap.pop();return x;}());
		ListNode* pre = h;
		if (pre->next != nullptr) {
			heap.push(pre->next);
		}
		while (!heap.empty()) {
			ListNode* cur = ([&](){auto x=heap.top();heap.pop();return x;}());
			pre->next = cur;
			pre = cur;
			if (cur->next != nullptr) {
				heap.push(cur->next);
			}
		}
		return h;
	};

};
