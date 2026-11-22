// Ported from src/class030/Code01_SwapExclusiveOr.java
#include <cstdint>
#include <iostream>
#include <vector>

// 用异或运算交换两数的值
struct Code01_SwapExclusiveOr {

	static void runDemo() {
		int a = -2323;
		int b = 10;
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		std::cout << a << "\n";
		std::cout << b << "\n";

		std::vector<int> arr = { 3, 5 };
		swap(arr, 0, 1);
		std::cout << arr[0] << "\n";
		std::cout << arr[1] << "\n";
		swap(arr, 0, 0);
		std::cout << arr[0] << "\n";
	}

	// 当i!=j，没问题，会完成交换功能
	// 当i==j，会出错
	// 所以知道这种写法即可，并不推荐
	static void swap(std::vector<int>& arr, int i, int j) {
		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[i] ^ arr[j];
		arr[i] = arr[i] ^ arr[j];
	}

};

int main(){Code01_SwapExclusiveOr::runDemo();return 0;}
