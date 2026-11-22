// Ported from class027/Code02_MaxCover.java
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// 最多线段重合问题
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code02_MaxCover {

	inline static int MAXN = 10001;

	inline static std::vector<std::vector<int>> line = std::vector<std::vector<int>>(MAXN,std::vector<int>(2));

	inline static int n;

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);while(std::cin>>n){if(n<0||n>MAXN)return;for(int i=0;i<n;++i)std::cin>>line[i][0]>>line[i][1];std::cout<<compute()<<"\n";}}

	static int compute() {
		// 堆的清空
		size = 0;

		// 线段一共有n条，line[0...n-1][2] : line[i][0] line[i][1], 左闭右闭
		// 所有线段，根据开始位置排序，结束位置无所谓
		// 比较器的用法
		// line [0...n) 排序 : 所有小数组，开始位置谁小谁在前
		std::sort(line.begin(),line.begin()+n,[](const auto& a,const auto& b){return a[0]<b[0];});
		int ans = 0;
		for (int i = 0; i < n; i++) {
			// i : line[i][0] line[i][1]
			while (size > 0 && heap[0] <= line[i][0]) {
				pop();
			}
			add(line[i][1]);
			ans = std::max(ans, size);
		}
		return ans;
	};

	// 小根堆，堆顶0位置
	inline static std::vector<int> heap = std::vector<int>(MAXN);

	// 堆的大小
	inline static int size;

	static void add(int x) {
		heap[size] = x;
		int i = size++;
		while (heap[i] < heap[(i - 1) / 2]) {
			swap(i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	};

	static void pop() {
		swap(0, --size);
		int i = 0, l = 1;
		while (l < size) {
			int best = l + 1 < size && heap[l + 1] < heap[l] ? l + 1 : l;
			best = heap[best] < heap[i] ? best : i;
			if (best == i) {
				break;
			}
			swap(i, best);
			i = best;
			l = i * 2 + 1;
		}
	};

	static void swap(int i, int j) {
		int tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	};

	// 也找到了leetcode测试链接
	// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/
	// 提交如下代码可以直接通过
	static int minMeetingRooms(std::vector<std::vector<int>>& meeting) {
		int n = static_cast<int>(meeting.size());
		std::sort(meeting.begin(),meeting.end(),[](const auto& a,const auto& b){return a[0]<b[0];});
		std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			while (!heap.empty() && heap.top() <= meeting[i][0]) {
				([&](){auto x=heap.top();heap.pop();return x;}());
			}
			heap.push(meeting[i][1]);
			ans = std::max(ans,static_cast<int>(heap.size()));
		}
		return ans;
	};

	// 上面的leetcode题目是会员题，需要付费
	// 如果不想开通leetcode会员，还有一个类似的题，但是注意题意，和课上讲的有细微差别
	// 课上讲的题目，认为[1,4]、[4、5]可以严丝合缝接在一起，不算有重合
	// 但是如下链接的题目，认为[1,4]、[4、5]有重合部分，也就是4
	// 除此之外再无差别
	// 测试链接 : https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/
	// 提交如下代码可以直接通过
	static int minGroups(std::vector<std::vector<int>>& meeting) {
		int n = static_cast<int>(meeting.size());
		std::sort(meeting.begin(),meeting.end(),[](const auto& a,const auto& b){return a[0]<b[0];});
		std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			// 注意这里的判断
			while (!heap.empty() && heap.top() < meeting[i][0]) {
				([&](){auto x=heap.top();heap.pop();return x;}());
			}
			heap.push(meeting[i][1]);
			ans = std::max(ans,static_cast<int>(heap.size()));
		}
		return ans;
	};

};

int main(){Code02_MaxCover::runDemo();return 0;}
