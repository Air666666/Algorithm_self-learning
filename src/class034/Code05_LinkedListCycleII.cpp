// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/linked-list-cycle-ii/

// Ported from class034/Code05_LinkedListCycleII.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 返回链表的第一个入环节点
// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/
struct Code05_LinkedListCycleII {

	// 不要提交这个类
	struct ListNode {
		int val = 0;
		ListNode* next = nullptr;
	};

	// 提交如下的方法
	static ListNode* detectCycle(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
			return nullptr;
		}
		ListNode* slow = head->next;
		ListNode* fast = head->next->next;
		while (slow != fast) {
			if (fast->next == nullptr || fast->next->next == nullptr) {
				return nullptr;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	};

};
