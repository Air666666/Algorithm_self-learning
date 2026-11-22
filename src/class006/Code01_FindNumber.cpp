// Ported from algorithmzuo/algorithm-journey/src/class006/Code01_FindNumber.java
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
namespace { double randomUnit() { static std::mt19937 gen(20261122); return std::generate_canonical<double, 53>(gen); } }


// 有序数组中是否存在一个数字
struct Code01_FindNumber {

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
			if (right(arr, num) != exist(arr, num)) {
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
	static bool right(std::vector<int>& sortedArr, int num) {
		for (int cur : sortedArr) {
			if (cur == num) {
				return true;
			}
		}
		return false;
	};

	// 保证arr有序，才能用这个方法
	static bool exist(std::vector<int>& arr, int num) {
		if (static_cast<int>(arr.size()) == 0) {
			return false;
		}
		int l = 0, r = static_cast<int>(arr.size()) - 1, m = 0;
		while (l <= r) {
			m = (l + r) / 2;
			if (arr[m] == num) {
				return true;
			} else if (arr[m] > num) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return false;
	};

};

int main() { Code01_FindNumber::runTests(); }
