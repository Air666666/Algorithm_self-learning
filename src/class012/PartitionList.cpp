// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/partition-list/

// Ported from algorithmzuo/algorithm-journey/src/class012/PartitionList.java

// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置
// 测试链接 : https://leetcode.cn/problems/partition-list/
struct PartitionList {

	// 不要提交这个类
	struct ListNode {
		int val;
		ListNode* next = nullptr;

		ListNode(int val) {
			this->val = val;
		}

		ListNode(int val, ListNode* next) {
			this->val = val;
			this->next = next;
		}
	};

	struct Solution {

		static ListNode* partition(ListNode* head, int x) {
			ListNode* leftHead = nullptr, *leftTail = nullptr; // < x的区域
			ListNode* rightHead = nullptr, *rightTail = nullptr; // >=x的区域
			ListNode* next = nullptr;
			while (head != nullptr) {
				next = head->next;
				head->next = nullptr;
				if (head->val < x) {
					if (leftHead == nullptr) {
						leftHead = head;
					} else {
						leftTail->next = head;
					}
					leftTail = head;
				} else {
					if (rightHead == nullptr) {
						rightHead = head;
					} else {
						rightTail->next = head;
					}
					rightTail = head;
				}
				head = next;
			}
			if (leftHead == nullptr) {
				return rightHead;
			}
			// < x的区域有内容！
			leftTail->next = rightHead;
			return leftHead;
		}

	};

};
