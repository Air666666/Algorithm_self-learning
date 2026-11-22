// Ported from algorithmzuo/algorithm-journey/src/class006/Code02_FindLeft.java
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
namespace { double randomUnit() { static std::mt19937 gen(20261122); return std::generate_canonical<double, 53>(gen); } }


// 有序数组中找>=num的最左位置
struct Code02_FindLeft {

	// 为了验证
	static void runTests() {
		int N = 100;
		int V = 1000;
		int testTime = 500000;
		std::cout << "测试开始" << "\n";
		for (int i = 0; i < testTime; i++) {
			int n = (int) (randomUnit() * N);
			std::vector<int> arr = randomArray(n, V);
			std::sort(arr.begin(), arr.end());
			int num = (int) (randomUnit() * V);
			if (right(arr, num) != findLeft(arr, num)) {
				std::cout << "出错了!" << "\n";
			}
		}
		std::cout << "测试结束" << "\n";
	};

	// 为了验证
	static std::vector<int> randomArray(int n, int v) {
		std::vector<int> arr = std::vector<int>(n);
		for (int i = 0; i < n; i++) {
			arr[i] = (int) (randomUnit() * v) + 1;
		}
		return arr;
	};

	// 为了验证
	// 保证arr有序，才能用这个方法
	static int right(std::vector<int>& arr, int num) {
		for (int i = 0; i < static_cast<int>(arr.size()); i++) {
			if (arr[i] >= num) {
				return i;
			}
		}
		return -1;
	};

	// 保证arr有序，才能用这个方法
	// 有序数组中找>=num的最左位置
	static int findLeft(std::vector<int>& arr, int num) {
		int l = 0, r = static_cast<int>(arr.size()) - 1, m = 0;
		int ans = -1;
		while (l <= r) {
			// m = (l + r) / 2;
			// m = l + (r - l) / 2;
			m = l + ((r - l) >> 1);
			if (arr[m] >= num) {
				ans = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return ans;
	};

};

int main() { Code02_FindLeft::runTests(); }
