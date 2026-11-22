// Ported from class034/Code04_PalindromeLinkedList.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 判断链表是否是回文结构
// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/
struct Code04_PalindromeLinkedList {

	// 不要提交这个类
	struct ListNode {
		int val = 0;
		ListNode* next = nullptr;
	};

	// 提交如下的方法
	static bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return true;
		}
		ListNode* slow = head, *fast = head;
		// 找中点
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// 现在中点就是slow，从中点开始往后的节点逆序
		ListNode* pre = slow;
		ListNode* cur = pre->next;
		ListNode* next = nullptr;
		pre->next = nullptr;
		while (cur != nullptr) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		// 上面的过程已经把链表调整成从左右两侧往中间指
		// head -> ... -> slow <- ... <- pre
		bool ans = true;
		ListNode* left = head;
		ListNode* right = pre;
		// left往右、right往左，每一步比对值是否一样，如果某一步不一样答案就是false
		while (left != nullptr && right != nullptr) {
			if (left->val != right->val) {
				ans = false;
				break;
			}
			left = left->next;
			right = right->next;
		}
		// 本着不坑的原则，把链表调整回原来的样子再返回判断结果
		cur = pre->next;
		pre->next = nullptr;
		next = nullptr;
		while (cur != nullptr) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return ans;
	};

};
