// 来源: algorithmzuo/algorithm-journey/src/class004/SelectBubbleInsert.java
// C++17；vector 以引用传入，原地排序。
#include <vector>
#include <utility>
struct SelectBubbleInsert {
    static void swap(std::vector<int>& arr, int i, int j) {
        std::swap(arr[i], arr[j]);
    }
    // 选择排序
    static void selectionSort(std::vector<int>& arr) {
        const int n = static_cast<int>(arr.size());
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
                if (arr[j] < arr[minIndex]) minIndex = j;
            swap(arr, i, minIndex);
        }
    }
    // 冒泡排序
    static void bubbleSort(std::vector<int>& arr) {
        for (int end = static_cast<int>(arr.size()) - 1; end > 0; --end)
            for (int i = 0; i < end; ++i)
                if (arr[i] > arr[i + 1]) swap(arr, i, i + 1);
    }
    // 插入排序
    static void insertionSort(std::vector<int>& arr) {
        for (int i = 1; i < static_cast<int>(arr.size()); ++i)
            for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; --j)
                swap(arr, j, j + 1);
    }
};
