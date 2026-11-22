// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/reverse-pairs/

// Ported from algorithmzuo/algorithm-journey/src/class022/Code02_ReversePairs.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 翻转对数量
// 测试链接 : https://leetcode.cn/problems/reverse-pairs/
struct Code02_ReversePairs {

	inline static int MAXN = 50001;

	inline static std::vector<int> help = std::vector<int>(MAXN);

	static int reversePairs(std::vector<int>& arr) {
		return counts(arr, 0, static_cast<int>(arr.size()) - 1);
	}

	// 统计l...r范围上，翻转对的数量，同时l...r范围统计完后变有序
	// 时间复杂度O(n * logn)
	static int counts(std::vector<int>& arr, int l, int r) {
		if (l >= r) {
			return 0;
		}
		int m = (l + r) / 2;
		return counts(arr, l, m) + counts(arr, m + 1, r) + merge(arr, l, m, r);
	}

	static int merge(std::vector<int>& arr, int l, int m, int r) {
		// 统计部分
		int ans = 0;
		for (int i = l, j = m + 1; i <= m; i++) {
			while (j <= r && (long long) arr[i] > (long long) arr[j] * 2) {
				j++;
			}
			ans += j - m - 1;
		}
		// 正常merge
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
		return ans;
	}

};
