// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/reverse-nodes-in-k-group/

// Ported from class034/Code02_ReverseNodesInkGroup.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
struct Code02_ReverseNodesInkGroup {

	// 不要提交这个类
	struct ListNode {
		int val = 0;
		ListNode* next = nullptr;
	};

	// 提交如下的方法
	static ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* start = head;
		ListNode* end = teamEnd(start, k);
		if (end == nullptr) {
			return head;
		}
		// 第一组很特殊因为牵扯到换头的问题
		head = end;
		reverse(start, end);
		// 翻转之后start变成了上一组的结尾节点
		ListNode* lastTeamEnd = start;
		while (lastTeamEnd->next != nullptr) {
			start = lastTeamEnd->next;
			end = teamEnd(start, k);
			if (end == nullptr) {
				return head;
			}
			reverse(start, end);
			lastTeamEnd->next = end;
			lastTeamEnd = start;
		}
		return head;
	};

	// 当前组的开始节点是s，往下数k个找到当前组的结束节点返回
	static ListNode* teamEnd(ListNode* s, int k) {
		while (--k != 0 && s != nullptr) {
			s = s->next;
		}
		return s;
	};

	// s -> a -> b -> c -> e -> 下一组的开始节点
	// 上面的链表通过如下的reverse方法调整成 : e -> c -> b -> a -> s -> 下一组的开始节点
	static void reverse(ListNode* s, ListNode* e) {
		e = e->next;
		ListNode* pre = nullptr, *cur = s, *next = nullptr;
		while (cur != e) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		s->next = e;
	};

};
