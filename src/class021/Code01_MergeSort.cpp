// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1177

// Ported from algorithmzuo/algorithm-journey/src/class021/Code01_MergeSort.java
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>

// 归并排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code01_MergeSort {

	inline static int MAXN = 100001;

	inline static std::vector<int> arr = std::vector<int>(MAXN);

	inline static std::vector<int> help = std::vector<int>(MAXN);

	inline static int n;

	static void runDemo() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
        if (!(std::cin >> n) || n < 0 || n > MAXN) return;
        for(int i=0;i<n;++i) std::cin >> arr[i];
        mergeSort2();
        for(int i=0;i<n;++i) std::cout << arr[i] << (i+1==n?'\n':' ');
    }

	// 归并排序递归版
	// 假设l...r一共n个数
	// T(n) = 2 * T(n/2) + O(n)
	// a = 2, b = 2, c = 1
	// 根据master公式，时间复杂度O(n * logn)
	// 空间复杂度O(n)
	static void mergeSort1(int l, int r) {
		if (l >= r) {
			return;
		}
		int m = (l + r) / 2;
		mergeSort1(l, m);
		mergeSort1(m + 1, r);
		merge(l, m, r);
	};

	// 归并排序非递归版
	// 时间复杂度O(n * logn)
	// 空间复杂度O(n)
	static void mergeSort2() {
		// 一共发生O(logn)次
		for (int l, m, r, step = 1; step < n; step <<= 1) {
			// 内部分组merge，时间复杂度O(n)
			l = 0;
			while (l < n) {
				m = l + step - 1;
				if (m + 1 >= n) {
					break;
				}
				r = std::min(l + (step << 1) - 1, n - 1);
				merge(l, m, r);
				l = r + 1;
			}
		}
	};

	// l....r 一共有n个数
	// O(n)
	static void merge(int l, int m, int r) {
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		// 左侧指针、右侧指针，必有一个越界、另一个不越界
		while (a <= m) {
			help[i++] = arr[a++];
		}
		while (b <= r) {
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
	};

};

int main(){ Code01_MergeSort::runDemo(); return 0; }
