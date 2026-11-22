// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/sort-list/

// Ported from class034/Code06_SortList.java
// 节点由调用者管理；新增副本需要调用者释放。
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

// 排序链表
// 要求时间复杂度O(n*logn)，额外空间复杂度O(1)，还要求稳定性
// 数组排序做不到，链表排序可以
// 测试链接 : https://leetcode.cn/problems/sort-list/
struct Code06_SortList {

	// 不要提交这个类
	struct ListNode {
		int val = 0;
		ListNode* next = nullptr;
	};

	// 提交如下的方法
	// 时间复杂度O(n*logn)，额外空间复杂度O(1)，有稳定性
	// 注意为了额外空间复杂度O(1)，所以不能使用递归
	// 因为mergeSort递归需要O(log n)的额外空间
	static ListNode* sortList(ListNode* head) {
		int n = 0;
		ListNode* cur = head;
		while (cur != nullptr) {
			n++;
			cur = cur->next;
		}
		// l1...r1 每组的左部分
		// l2...r2 每组的右部分
		// next 下一组的开头
		// lastTeamEnd 上一组的结尾
		ListNode* l1, *r1, *l2, *r2, *next, *lastTeamEnd;
		for (int step = 1; step < n; step <<= 1) {
			// 第一组很特殊，因为要决定整个链表的头，所以单独处理
			l1 = head;
			r1 = findEnd(l1, step);
			l2 = r1->next;
			r2 = findEnd(l2, step);
			next = r2->next;
			r1->next = nullptr;
			r2->next = nullptr;
			merge(l1, r1, l2, r2);
			head = start;
			lastTeamEnd = end;
			while (next != nullptr) {
				l1 = next;
				r1 = findEnd(l1, step);
				l2 = r1->next;
				if (l2 == nullptr) {
					lastTeamEnd->next = l1;
					break;
				}
				r2 = findEnd(l2, step);
				next = r2->next;
				r1->next = nullptr;
				r2->next = nullptr;
				merge(l1, r1, l2, r2);
				lastTeamEnd->next = start;
				lastTeamEnd = end;
			}
		}
		return head;
	};

	// 包括s在内，往下数k个节点返回
	// 如果不够，返回最后一个数到的非空节点
	static ListNode* findEnd(ListNode* s, int k) {
		while (s->next != nullptr && --k != 0) {
			s = s->next;
		}
		return s;
	};

	inline static ListNode* start;

	inline static ListNode* end;

	// l1...r1 -> nullptr : 有序的左部分
	// l2...r2 -> nullptr : 有序的右部分
	// 整体merge在一起，保证有序
	// 并且把全局变量start设置为整体的头，全局变量end设置为整体的尾
	static void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2) {
		ListNode* pre;
		if (l1->val <= l2->val) {
			start = l1;
			pre = l1;
			l1 = l1->next;
		} else {
			start = l2;
			pre = l2;
			l2 = l2->next;
		}
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val <= l2->val) {
				pre->next = l1;
				pre = l1;
				l1 = l1->next;
			} else {
				pre->next = l2;
				pre = l2;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr) {
			pre->next = l1;
			end = r1;
		} else {
			pre->next = l2;
			end = r2;
		}
	};

};
