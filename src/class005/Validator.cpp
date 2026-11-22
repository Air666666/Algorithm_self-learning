// Ported from algorithmzuo/algorithm-journey/src/class005/Validator.java
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
namespace { double randomUnit() { static std::mt19937 gen(20261122); return std::generate_canonical<double, 53>(gen); } }

struct Validator {

	// 为了验证
	static void runTests() {
		// 随机数组最大长度
		int N = 200;
		// 随机数组每个值，在1~V之间等概率随机
		int V = 1000;
		// testTimes : 测试次数
		int testTimes = 50000;
		std::cout << "测试开始" << "\n";
		for (int i = 0; i < testTimes; i++) {
			// 随机得到一个长度，长度在[0~N-1]
			int n = (int) (randomUnit() * N);
			// 得到随机数组
			std::vector<int> arr = randomArray(n, V);
			std::vector<int> arr1 = copyArray(arr);
			std::vector<int> arr2 = copyArray(arr);
			std::vector<int> arr3 = copyArray(arr);
			selectionSort(arr1);
			bubbleSort(arr2);
			insertionSort(arr3);
			if (!sameArray(arr1, arr2) || !sameArray(arr1, arr3)) {
				std::cout << "出错了!" << "\n";
				// 当有错了
				// 打印是什么例子，出错的
				// 打印三个功能，各自排序成了什么样
				// 可能要把例子带入，每个方法，去debug！
			}
		}
		std::cout << "测试结束" << "\n";
	};

	// 为了验证
	// 得到一个随机数组，长度是n
	// 数组中每个数，都在1~v之间，随机得到
	static std::vector<int> randomArray(int n, int v) {
		std::vector<int> arr = std::vector<int>(n);
		for (int i = 0; i < n; i++) {
			// randomUnit() -> double -> [0,1)范围山的一个小数，0.37463473126、0.001231231，等概率！
			// randomUnit() * v -> double -> [0,v)一个小数，依然等概率
			// (int)(randomUnit() * v) -> int -> 0 1 2 3 ... v-1，等概率的！
			// (int) (randomUnit() * v) + 1 -> int -> 1 2 3 .... v，等概率的！
			arr[i] = (int) (randomUnit() * v) + 1;
		}
		return arr;
	};

	// 为了验证
	static std::vector<int> copyArray(std::vector<int>& arr) {
		int n = static_cast<int>(arr.size());
		std::vector<int> ans = std::vector<int>(n);
		for (int i = 0; i < n; i++) {
			ans[i] = arr[i];
		}
		return ans;
	};

	// 为了验证
	static bool sameArray(std::vector<int>& arr1, std::vector<int>& arr2) {
		int n = static_cast<int>(arr1.size());
		for (int i = 0; i < n; i++) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	};

	// 数组中交换i和j位置的数
	static void swap(std::vector<int>& arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	};

	// 选择排序
	static void selectionSort(std::vector<int>& arr) {
		if (static_cast<int>(arr.size()) < 2) {
			return;
		}
		for (int minIndex, i = 0; i < static_cast<int>(arr.size()) - 1; i++) {
			minIndex = i;
			for (int j = i + 1; j < static_cast<int>(arr.size()); j++) {
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			swap(arr, i, minIndex);
		}
	};

	// 冒泡排序
	static void bubbleSort(std::vector<int>& arr) {
		if (static_cast<int>(arr.size()) < 2) {
			return;
		}
		for (int end = static_cast<int>(arr.size()) - 1; end > 0; end--) {
			for (int i = 0; i < end; i++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr, i, i + 1);
				}
			}
		}
	};

	// 插入排序
	static void insertionSort(std::vector<int>& arr) {
		if (static_cast<int>(arr.size()) < 2) {
			return;
		}
		for (int i = 1; i < static_cast<int>(arr.size()); i++) {
			for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
				swap(arr, j, j + 1);
			}
		}
	};

};

int main() { Validator::runTests(); }
