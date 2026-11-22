// Ported from algorithmzuo/algorithm-journey/src/class015/GetMinStack.java
#include <vector>
#include <deque>


// 最小栈
// 测试链接 : https://leetcode.cn/problems/min-stack/
struct GetMinStack {

	// 提交时把类名、构造方法改成MinStack
	struct MinStack1 {
		std::deque<int> data;
		std::deque<int> min;

		MinStack1() {
			data = std::deque<int>();
			min = std::deque<int>();
		}

		void push(int val) {
			data.push_back(val);
			if (min.empty() || val <= min.back()) {
				min.push_back(val);
			} else { // !min.empty() && val > min.back()
				min.push_back(min.back());
			}
		}

		void pop() {
			([&](){int v=data.back(); data.pop_back(); return v;}());
			([&](){int v=min.back(); min.pop_back(); return v;}());
		}

		int top() {
			return data.back();
		}

		int getMin() {
			return min.back();
		}
	};

	// 提交时把类名、构造方法改成MinStack
	struct MinStack2 {
		// leetcode的数据在测试时，同时在栈里的数据不超过这个值
		// 这是几次提交实验出来的，哈哈
		// 如果leetcode补测试数据了，超过这个量导致出错，就调大
		const int MAXN = 8001;

		std::vector<int> data;
		std::vector<int> min;
		int size;

		MinStack2() {
			data = std::vector<int>(MAXN);
			min = std::vector<int>(MAXN);
			size = 0;
		}

		void push(int val) {
			data[size] = val;
			if (size == 0 || val <= min[size - 1]) {
				min[size] = val;
			} else {
				min[size] = min[size - 1];
			}
			size++;
		}

		void pop() {
			size--;
		}

		int top() {
			return data[size - 1];
		}

		int getMin() {
			return min[size - 1];
		}
	};

};
