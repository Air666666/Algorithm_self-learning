// Ported from algorithmzuo/algorithm-journey/src/class016/CircularDeque.java
#include <vector>
#include <deque>


// 设计循环双端队列
// 测试链接 : https://leetcode.cn/problems/design-circular-deque/
struct CircularDeque {

	// 提交时把类名、构造方法改成 : MyCircularDeque
	// 其实内部就是双向链表
	// 常数操作慢，但是leetcode数据量太小了，所以看不出劣势
	struct MyCircularDeque1 {

		std::deque<int> deque = std::deque<int>();
		int size;
		int limit;

		MyCircularDeque1(int k) {
			size = 0;
			limit = k;
		}

		bool insertFront(int value) {
			if (isFull()) {
				return false;
			} else {
				deque.push_front(value);
				size++;
				return true;
			}
		}

		bool insertLast(int value) {
			if (isFull()) {
				return false;
			} else {
				deque.push_back(value);
				size++;
				return true;
			}
		}

		bool deleteFront() {
			if (isEmpty()) {
				return false;
			} else {
				size--;
				deque.pop_front();
				return true;
			}
		}

		bool deleteLast() {
			if (isEmpty()) {
				return false;
			} else {
				size--;
				deque.pop_back();
				return true;
			}
		}

		int getFront() {
			if (isEmpty()) {
				return -1;
			} else {
				return deque.front();
			}
		}

		int getRear() {
			if (isEmpty()) {
				return -1;
			} else {
				return deque.back();
			}
		}

		bool isEmpty() {
			return size == 0;
		}

		bool isFull() {
			return size == limit;
		}

	};

	// 提交时把类名、构造方法改成 : MyCircularDeque
	// 自己用数组实现，常数操作快，但是leetcode数据量太小了，看不出优势
	struct MyCircularDeque2 {

		std::vector<int> deque;
		int l, r, size, limit;

		MyCircularDeque2(int k) {
			deque = std::vector<int>(k);
			l = r = size = 0;
			limit = k;
		}

		bool insertFront(int value) {
			if (isFull()) {
				return false;
			} else {
				if (isEmpty()) {
					l = r = 0;
					deque[0] = value;
				} else {
					l = l == 0 ? (limit - 1) : (l - 1);
					deque[l] = value;
				}
				size++;
				return true;
			}
		}

		bool insertLast(int value) {
			if (isFull()) {
				return false;
			} else {
				if (isEmpty()) {
					l = r = 0;
					deque[0] = value;
				} else {
					r = r == limit - 1 ? 0 : (r + 1);
					deque[r] = value;
				}
				size++;
				return true;
			}
		}

		bool deleteFront() {
			if (isEmpty()) {
				return false;
			} else {
				l = (l == limit - 1) ? 0 : (l + 1);
				size--;
				return true;
			}
		}

		bool deleteLast() {
			if (isEmpty()) {
				return false;
			} else {
				r = r == 0 ? (limit - 1) : (r - 1);
				size--;
				return true;
			}
		}

		int getFront() {
			if (isEmpty()) {
				return -1;
			} else {
				return deque[l];
			}
		}

		int getRear() {
			if (isEmpty()) {
				return -1;
			} else {
				return deque[r];
			}
		}

		bool isEmpty() {
			return size == 0;
		}

		bool isFull() {
			return size == limit;
		}

	};

};
