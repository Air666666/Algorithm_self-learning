// Ported from class034/Code01_IntersectionOfTwoLinkedLists.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/
struct Code01_IntersectionOfTwoLinkedLists {

	// 提交时不要提交这个类
	struct ListNode {
		int val = 0;
		ListNode* next = nullptr;
	};

	// 提交如下的方法
	static ListNode* getIntersectionNode(ListNode* h1, ListNode* h2) {
		if (h1 == nullptr || h2 == nullptr) {
			return nullptr;
		}
		ListNode* a = h1, *b = h2;
		int diff = 0;
		while (a->next != nullptr) {
			a = a->next;
			diff++;
		}
		while (b->next != nullptr) {
			b = b->next;
			diff--;
		}
		if (a != b) {
			return nullptr;
		}
		if (diff >= 0) {
			a = h1;
			b = h2;
		} else {
			a = h2;
			b = h1;
		}
		diff = std::abs(diff);
		while (diff-- != 0) {
			a = a->next;
		}
		while (a != b) {
			a = a->next;
			b = b->next;
		}
		return a;
	};

};
