// Ported from algorithmzuo/algorithm-journey/src/class013/QueueStackAndCircularQueue.java
#include <vector>
#include <deque>


struct QueueStackAndCircularQueue {

	// 直接用java内部的实现
	// 其实内部就是双向链表，常数操作慢
	struct Queue1 {

		// java中的双向链表LinkedList
		// 单向链表就足够了
		std::deque<int> queue = std::deque<int>();

		// 调用任何方法之前，先调用这个方法来判断队列内是否有东西
		bool isEmpty() {
			return queue.empty();
		}

		// 向队列中加入num，加到尾巴
		void offer(int num) {
			queue.push_back(num);
		}

		// 从队列拿，从头拿
		int poll() {
			return ([&](){int v=queue.front(); queue.pop_front(); return v;}());
		}

		// 返回队列头的元素但是不弹出
		int peek() {
			return queue.front();
		}

		// 返回目前队列里有几个数
		int size() {
			return queue.size();
		}

	};

	// 实际刷题时更常见的写法，常数时间好
	// 如果可以确定加入操作的总次数不超过n，那么可以用
	// 一般笔试、面试都会有一个明确数据量，所以这是最常用的方式
	struct Queue2 {

		std::vector<int> queue;
		int l;
		int r;

		// 加入操作的总次数上限是多少，一定要明确
		Queue2(int n) {
			queue = std::vector<int>(n);
			l = 0;
			r = 0;
		}

		// 调用任何方法之前，先调用这个方法来判断队列内是否有东西
		bool isEmpty() {
			return l == r;
		}

		void offer(int num) {
			queue[r++] = num;
		}

		int poll() {
			return queue[l++];
		}
		// ?
		// l...r-1 r
		// [l..r)
		int head() {
			return queue[l];
		}

		int tail() {
			return queue[r - 1];
		}

		int size() {
			return r - l;
		}

	};

	// 直接用java内部的实现
	// 其实就是动态数组，不过常数时间并不好
	struct Stack1 {

		std::deque<int> stack = std::deque<int>();

		// 调用任何方法之前，先调用这个方法来判断栈内是否有东西
		bool isEmpty() {
			return stack.empty();
		}

		void push(int num) {
			stack.push_back(num);
		}

		int pop() {
			return ([&](){int v=stack.back(); stack.pop_back(); return v;}());
		}

		int peek() {
			return stack.back();
		}

		int size() {
			return stack.size();
		}

	};

	// 实际刷题时更常见的写法，常数时间好
	// 如果可以保证同时在栈里的元素个数不会超过n，那么可以用
	// 也就是发生弹出操作之后，空间可以复用
	// 一般笔试、面试都会有一个明确数据量，所以这是最常用的方式
	struct Stack2 {

		std::vector<int> stack;
		int count;

		// 同时在栈里的元素个数不会超过n
		Stack2(int n) {
			stack = std::vector<int>(n);
			count = 0;
		}

		// 调用任何方法之前，先调用这个方法来判断栈内是否有东西
		bool isEmpty() {
			return count == 0;
		}

		void push(int num) {
			stack[count++] = num;
		}

		int pop() {
			return stack[--count];
		}

		int peek() {
			return stack[count - 1];
		}

		int size() {
			return count;
		}

	};

	// 设计循环队列
	// 测试链接 : https://leetcode.cn/problems/design-circular-queue/
	struct MyCircularQueue {

		std::vector<int> queue;

		int l, r, size, limit;

		// 同时在队列里的数字个数，不要超过k
		MyCircularQueue(int k) {
			queue = std::vector<int>(k);
			l = r = size = 0;
			limit = k;
		}

		// 如果队列满了，什么也不做，返回false
		// 如果队列没满，加入value，返回true
		bool enQueue(int value) {
			if (isFull()) {
				return false;
			} else {
				queue[r] = value;
				// r++, 结束了，跳回0
				r = r == limit - 1 ? 0 : (r + 1);
				size++;
				return true;
			}
		}

		// 如果队列空了，什么也不做，返回false
		// 如果队列没空，弹出头部的数字，返回true
		bool deQueue() {
			if (isEmpty()) {
				return false;
			} else {
				// l++, 结束了，跳回0
				l = l == limit - 1 ? 0 : (l + 1);
				size--;
				return true;
			}
		}

		// 返回队列头部的数字（不弹出），如果没有数返回-1
		int Front() {
			if (isEmpty()) {
				return -1;
			} else {
				return queue[l];
			}
		}

		int Rear() {
			if (isEmpty()) {
				return -1;
			} else {
				int last = r == 0 ? (limit - 1) : (r - 1);
				return queue[last];
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
