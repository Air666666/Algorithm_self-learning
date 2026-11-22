// Ported from algorithmzuo/algorithm-journey/src/class007/Complexity.java
// 以下保留原课程注释；Java 专属说明不代表 C++ 规则。
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>


struct Complexity {
static double randomUnit(){static std::mt19937 gen(20261122);return std::generate_canonical<double,53>(gen);}
static long long millis(){return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();}


	// 只用一个循环完成冒泡排序
	// 但这是时间复杂度O(N^2)的！
	static void bubbleSort(std::vector<int>& arr) {
		if (static_cast<int>(arr.size()) < 2) {
			return;
		}
		int n = static_cast<int>(arr.size());
		int end = n - 1, i = 0;
		while (end > 0) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
			}
			if (i < end - 1) {
				i++;
			} else {
				end--;
				i = 0;
			}
		}
	}

	static void swap(std::vector<int>& arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	static void runDemo() {
		// 随机生成长度为n
		// 值在0~v-1之间
		// 且任意相邻两数不相等的数组
		int n = 10;
		int v = 4;
		std::vector<int> arr1 = std::vector<int>(n);
		arr1[0] = (int) (randomUnit() * v);
		for (int i = 1; i < n; i++) {
			do {
				arr1[i] = (int) (randomUnit() * v);
			} while (arr1[i] == arr1[i - 1]);
		}
		for (int num : arr1) {
			std::cout << num << " ";
		}
		std::cout << "\n";
		std::cout << "=========" << "\n";

		// java中的动态数组是ArrayList
		// 各个语言中的动态数组的初始大小和实际扩容因子可能会变化，但是均摊都是O(1)
		// 课上用2作为扩容因子只是举例而已
		std::vector<int> arr2;
		arr2.push_back(5); // 0
		arr2.push_back(4); // 1
		arr2.push_back(9); // 2
		arr2[1] = 6; // arr[1]由4改成了6
		std::cout << arr2[1] << "\n";
		std::cout << "=========" << "\n";

		std::vector<int> arr = { 64, 31, 78, 0, 5, 7, 103 };
		bubbleSort(arr);
		for (int num : arr) {
			std::cout << num << " ";
		}
		std::cout << "\n";
		std::cout << "=========" << "\n";

		int N = 200000;
		long start;
		long end;
		std::cout << "测试开始" << "\n";
		start = millis();
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j += i) {
				// 这两个嵌套for循环的流程，时间复杂度为O(N * logN)
				// 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/n，也叫"调和级数"，收敛于O(logN)
				// 所以如果一个流程的表达式 : n/1 + n/2 + n/3 + ... + n/n
				// 那么这个流程时间复杂度O(N * logN)
			}
		}
		end = millis();
		std::cout << "测试结束，运行时间 : " << (end - start) << " 毫秒" << "\n";

		std::cout << "测试开始" << "\n";
		start = millis();
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				// 这两个嵌套for循环的流程，时间复杂度为O(N^2)
				// 很明显等差数列
			}
		}
		end = millis();
		std::cout << "测试结束，运行时间 : " << (end - start) << " 毫秒" << "\n";

	}

};

int main(){Complexity::runDemo();return 0;}
