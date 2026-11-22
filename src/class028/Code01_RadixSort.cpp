// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1177

// Ported from class028/Code01_RadixSort.java
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// 基数排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code01_RadixSort {

	// 可以设置进制，不一定10进制，随你设置
	inline static int BASE = 10;

	inline static int MAXN = 100001;

	inline static std::vector<long long> arr = std::vector<long long>(MAXN);

	inline static std::vector<long long> help = std::vector<long long>(MAXN);

	inline static std::vector<int> cnts = std::vector<int>(BASE);

	inline static int n;

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);if(!(std::cin>>n)||n<0||n>MAXN)return;for(int i=0;i<n;++i)std::cin>>arr[i];sort();for(int i=0;i<n;++i)std::cout<<arr[i]<<(i+1==n?'\n':' ');}

	static void sort() {
 if(n<2)return;
		// 如果会溢出，那么要改用long类型数组来排序
		// 找到数组中的最小值
		long long min = arr[0];
		for (int i = 1; i < n; i++) {
			min = std::min(min, arr[i]);
		}
		long long max = 0;
		for (int i = 0; i < n; i++) {
			// 数组中的每个数字，减去数组中的最小值，就把arr转成了非负数组
			arr[i] -= min;
			// 记录数组中的最大值
			max = std::max(max, arr[i]);
		}
		// 根据最大值在BASE进制下的位数，决定基数排序做多少轮
		radixSort(bits(max));
		// 数组中所有数都减去了最小值，所以最后不要忘了还原
		for (int i = 0; i < n; i++) {
			arr[i] += min;
		}
	};

	// 返回number在BASE进制下有几位
	static int bits(long long number) {
		int ans = 0;
		while (number > 0) {
			ans++;
			number /= BASE;
		}
		return ans;
	};

	// 基数排序核心代码
	// arr内要保证没有负数
	// m是arr中最大值在BASE进制下有几位
	static void radixSort(int bits) {
		// 理解的时候可以假设BASE = 10
		for (long long offset = 1; bits > 0; offset *= BASE, bits--) {
			std::fill(cnts.begin(),cnts.end(),0);
			for (int i = 0; i < n; i++) {
				// 数字提取某一位的技巧
				cnts[(arr[i] / offset) % BASE]++;
			}
			for (int i = 1; i < BASE; i++) {
				cnts[i] = cnts[i] + cnts[i - 1];
			}
			for (int i = n - 1; i >= 0; i--) {
				// 前缀数量分区的技巧
				// 数字提取某一位的技巧
				help[--cnts[(arr[i] / offset) % BASE]] = arr[i];
			}
			for (int i = 0; i < n; i++) {
				arr[i] = help[i];
			}
		}
	};

};

int main(){Code01_RadixSort::runDemo();return 0;}
