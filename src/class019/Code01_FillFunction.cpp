// Ported from algorithmzuo/algorithm-journey/src/class019/Code01_FillFunction.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 展示填函数风格的测试方式
// 子矩阵的最大累加和问题，不要求会解题思路，后面的课会讲
// 测试链接 : https://www.nowcoder.com/practice/840eee05dccd4ffd8f9433ce8085946b
struct Code01_FillFunction {

	int sumOfSubMatrix(std::vector<std::vector<int>>& mat, int n) {
		return maxSumSubmatrix(mat, n, n);
	}

	// 求子矩阵的最大累加和，后面的课会讲
	static int maxSumSubmatrix(std::vector<std::vector<int>>& mat, int n, int m) {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			// 需要的辅助数组，临时动态生成就可以
			std::vector<int> arr = std::vector<int>(m);
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					arr[k] += mat[j][k];
				}
				max = std::max(max, maxSumSubarray(arr, m));
			}
		}
		return max;
	}

	// 求子数组的最大累加和，后面的课会讲
	static int maxSumSubarray(std::vector<int>& arr, int m) {
		int max = INT_MIN;
		int cur = 0;
		for (int i = 0; i < m; i++) {
			cur += arr[i];
			max = std::max(max, cur);
			cur = cur < 0 ? 0 : cur;
		}
		return max;
	}

};
