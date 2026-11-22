// Ported from algorithmzuo/algorithm-journey/src/class020/GetMaxValue.java
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

// 用这个例子讲解递归如何执行
struct GetMaxValue {

	static int maxValue(std::vector<int>& arr) {
		if(arr.empty()) throw std::invalid_argument("empty array");
		return f(arr, 0, static_cast<int>(arr.size()) - 1);
	};

	// arr[l....r]范围上的最大值
	static int f(std::vector<int>& arr, int l, int r) {
		if (l >= r) {
			return arr[l];
		}
		int m = (l + r) / 2;
		int lmax = f(arr, l, m);
		int rmax = f(arr, m + 1, r);
		return std::max(lmax, rmax);
	};

	static void runDemo() {
		std::vector<int> arr = { 3, 8, 7, 6, 4, 5, 1, 2 };
		std::cout << "数组最大值 : " << maxValue(arr) << "\n";
	};
	

};

int main(){ GetMaxValue::runDemo(); return 0; }
