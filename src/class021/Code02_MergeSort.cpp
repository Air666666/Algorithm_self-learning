// Ported from algorithmzuo/algorithm-journey/src/class021/Code02_MergeSort.java
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

// 归并排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

struct Code02_MergeSort {

	static std::vector<int> sortArray(std::vector<int>& nums) {
		if (static_cast<int>(nums.size()) > 1) {
			// mergeSort1为递归方法
			// mergeSort2为非递归方法
			// 用哪个都可以
			// mergeSort1(nums);
			mergeSort2(nums);
		}
		return nums;
	};

	inline static int MAXN = 50001;

	inline static std::vector<int> help = std::vector<int>(MAXN);

	// 归并排序递归版
	static void mergeSort1(std::vector<int>& arr) {
		sort(arr, 0, static_cast<int>(arr.size()) - 1);
	};

	static void sort(std::vector<int>& arr, int l, int r) {
		if (l >= r) {
			return;
		}
		int m = (l + r) / 2;
		sort(arr, l, m);
		sort(arr, m + 1, r);
		merge(arr, l, m, r);
	};

	// 归并排序非递归版
	static void mergeSort2(std::vector<int>& arr) {
		int n = static_cast<int>(arr.size());
		for (int l, m, r, step = 1; step < n; step <<= 1) {
			l = 0;
			while (l < n) {
				m = l + step - 1;
				if (m + 1 >= n) {
					break;
				}
				r = std::min(l + (step << 1) - 1, n - 1);
				merge(arr, l, m, r);
				l = r + 1;
			}
		}
	};

	static void merge(std::vector<int>& arr, int l, int m, int r) {
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		while (a <= m) {
			help[i++] = arr[a++];
		}
		while (b <= r) {
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
	};

};
