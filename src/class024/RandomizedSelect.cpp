// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/kth-largest-element-in-an-array/

// Ported from algorithmzuo/algorithm-journey/src/class024/RandomizedSelect.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 无序数组中第K大的元素
// 测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/
struct RandomizedSelect {
 static double randomUnit(){static std::mt19937 gen(20261122);return std::generate_canonical<double,53>(gen);}

	// 随机选择算法，时间复杂度O(n)
	static int findKthLargest(std::vector<int>& nums, int k) {
		return randomizedSelect(nums, static_cast<int>(nums.size()) - k);
	}

	// 如果arr排序的话，在i位置的数字是什么
	static int randomizedSelect(std::vector<int>& arr, int i) {
		int ans = 0;
		for (int l = 0, r = static_cast<int>(arr.size()) - 1; l <= r;) {
			// 随机这一下，常数时间比较大
			// 但只有这一下随机，才能在概率上把时间复杂度收敛到O(n)
			partition(arr, l, r, arr[l + (int) (randomUnit() * (r - l + 1))]);
			// 因为左右两侧只需要走一侧
			// 所以不需要临时变量记录全局的first、last
			// 直接用即可
			if (i < first) {
				r = first - 1;
			} else if (i > last) {
				l = last + 1;
			} else {
				ans = arr[i];
				break;
			}
		}
		return ans;
	}

	// 荷兰国旗问题
	inline static int first, last;

	static void partition(std::vector<int>& arr, int l, int r, int x) {
		first = l;
		last = r;
		int i = l;
		while (i <= last) {
			if (arr[i] == x) {
				i++;
			} else if (arr[i] < x) {
				swap(arr, first++, i++);
			} else {
				swap(arr, i, last--);
			}
		}
	}

	static void swap(std::vector<int>& arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

};
