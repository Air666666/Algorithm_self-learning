// Ported from algorithmzuo/algorithm-journey/src/class004/SelectBubbleInsert.java
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

struct SelectBubbleInsert {

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
