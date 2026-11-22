// Ported from class027/Code03_MinimumOperationsToHalveArraySum.java
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>


// 将数组和减半的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
struct Code03_MinimumOperationsToHalveArraySum {

	// 提交时把halveArray1改名为halveArray
	static int halveArray1(std::vector<int>& nums) {
		// 大根堆
		std::priority_queue<double> heap;
		double sum = 0;
		for (int num : nums) {
			heap.push((double) num);
			sum += num;
		}
		// sum，整体累加和，-> 要减少的目标！
		sum /= 2;
		int ans = 0;
		for (double minus = 0, cur; minus < sum; ans++, minus += cur) {
			cur = ([&](){auto x=heap.top();heap.pop();return x;}()) / 2;
			heap.push(cur);
		}
		return ans;
	};

	inline static int MAXN = 100001;

	inline static std::vector<long long> heap = std::vector<long long>(MAXN);

	inline static int size;

	// 提交时把halveArray2改名为halveArray
	static int halveArray2(std::vector<int>& nums) {
		size = static_cast<int>(nums.size());
		long long sum = 0;
		for (int i = size - 1; i >= 0; i--) {
			heap[i] = (long long) nums[i] << 20;
			sum += heap[i];
			heapify(i);
		}
		sum /= 2;
		int ans = 0;
		for (long long minus = 0; minus < sum; ans++) {
			heap[0] /= 2;
			minus += heap[0];
			heapify(0);
		}
		return ans;
	};

	static void heapify(int i) {
		int l = i * 2 + 1;
		while (l < size) {
			int best = l + 1 < size && heap[l + 1] > heap[l] ? l + 1 : l;
			best = heap[best] > heap[i] ? best : i;
			if (best == i) {
				break;
			}
			swap(best, i);
			i = best;
			l = i * 2 + 1;
		}
	};

	static void swap(int i, int j) {
		long long tmp = heap[i];
		heap[i] = heap[j];
		heap[j] = tmp;
	};

};
