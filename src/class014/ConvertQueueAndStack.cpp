// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/implement-queue-using-stacks/
// https://leetcode.cn/problems/implement-stack-using-queues/

// Ported from algorithmzuo/algorithm-journey/src/class014/ConvertQueueAndStack.java
#include <vector>
#include <deque>


// 用栈实现队列
// 用队列实现栈
struct ConvertQueueAndStack {

	// 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
	struct MyQueue {

		std::deque<int> in;

		std::deque<int> out;

		MyQueue() {
			in = std::deque<int>();
			out = std::deque<int>();
		}

		// 倒数据
		// 从in栈，把数据倒入out栈
		// 1) out空了，才能倒数据
		// 2) 如果倒数据，in必须倒完
		void inToOut() {
			if (out.empty()) {
				while (!in.empty()) {
					out.push_back(([&](){int v=in.back(); in.pop_back(); return v;}()));
				}
			}
		}

		void push(int x) {
			in.push_back(x);
			inToOut();
		}

		int pop() {
			inToOut();
			return ([&](){int v=out.back(); out.pop_back(); return v;}());
		}

		int peek() {
			inToOut();
			return out.back();
		}

		bool empty() {
			return in.empty() && out.empty();
		}

	};

	// 测试链接 : https://leetcode.cn/problems/implement-stack-using-queues/
	struct MyStack {

		std::deque<int> queue;

		MyStack() {
			queue = std::deque<int>();
		}

		// O(n)
		void push(int x) {
			int n = queue.size();
			queue.push_back(x);
			for (int i = 0; i < n; i++) {
				queue.push_back(([&](){int v=queue.front(); queue.pop_front(); return v;}()));
			}
		}

		int pop() {
			return ([&](){int v=queue.front(); queue.pop_front(); return v;}());
		}

		int top() {
			return queue.front();
		}

		bool empty() {
			return queue.empty();
		}

	};

};
