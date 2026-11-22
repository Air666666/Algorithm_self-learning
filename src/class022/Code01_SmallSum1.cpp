// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469

// Ported from algorithmzuo/algorithm-journey/src/class022/Code01_SmallSum1.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 小和问题，java版
// 测试链接 : https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code01_SmallSum1 {

	inline static int MAXN = 100001;

	inline static std::vector<int> arr = std::vector<int>(MAXN);

	inline static std::vector<int> help = std::vector<int>(MAXN);

	inline static int n;

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);while(std::cin>>n){ if(n<0||n>MAXN)return;for(int i=0;i<n;++i)std::cin>>arr[i];std::cout<<smallSum(0,n-1)<<"\n"; }}

	// 结果比较大，用int会溢出的，所以返回long类型
	// 特别注意溢出这个点，笔试常见坑
	// 返回arr[l...r]范围上，小和的累加和，同时请把arr[l..r]变有序
	// 时间复杂度O(n * logn)
	static long long smallSum(int l, int r) {
		if (l >= r) {
			return 0;
		}
		int m = (l + r) / 2;
		return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
	}

	// 返回跨左右产生的小和累加和，左侧有序、右侧有序，让左右两侧整体有序
	// arr[l...m] arr[m+1...r]
	static long long merge(int l, int m, int r) {
		// 统计部分
		long long ans = 0;
		long long sum = 0;
		for (int j = m + 1, i = l; j <= r; j++) {
			while (i <= m && arr[i] <= arr[j]) {
				sum += arr[i++];
			}
			ans += sum;
		}
		// 正常merge
		int i = l;
		int a = l;
		int b = m + 1;
		while (a <= m && b <= r) {
			help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
		}
		while (a <= m) {
			help[i++] = arr[a++];
		}
		while (b <= r) {
			help[i++] = arr[b++];
		}
		for (i = l; i <= r; i++) {
			arr[i] = help[i];
		}
		return ans;
	}

};

int main(){Code01_SmallSum1::runDemo();return 0;}
