// 原题测试 / 参考链接（保留上游原始地址）
// https://www.luogu.com.cn/problem/P1177

// Ported from algorithmzuo/algorithm-journey/src/class023/Code01_QuickSort.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 随机快速排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code01_QuickSort {
 static double randomUnit(){static std::mt19937 gen(20261122);return std::generate_canonical<double,53>(gen);}

	inline static int MAXN = 100001;

	inline static std::vector<int> arr = std::vector<int>(MAXN);

	inline static int n;

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);if(!(std::cin>>n)||n<0||n>MAXN)return; for(int i=0;i<n;++i)std::cin>>arr[i]; quickSort2(0,n-1); for(int i=0;i<n;++i)std::cout<<arr[i]<<(i+1==n?'\n':' ');}

	// 随机快速排序经典版(不推荐)
	// 甚至在洛谷上测试因为递归开太多层会爆栈导致出错
	static void quickSort1(int l, int r) {
		// l == r，只有一个数
		// l > r，范围不存在，不用管
		if (l >= r) {
			return;
		}
		// 随机这一下，常数时间比较大
		// 但只有这一下随机，才能在概率上把快速排序的时间复杂度收敛到O(n * logn)
		// l......r 随机选一个位置，x这个值，做划分
		int x = arr[l + (int) (randomUnit() * (r - l + 1))];
		int mid = partition1(l, r, x);
		quickSort1(l, mid - 1);
		quickSort1(mid + 1, r);
	}

	// 已知arr[l....r]范围上一定有x这个值
	// 划分数组 <=x放左边，>x放右边
	// 并且确保划分完成后<=x区域的最后一个数字是x
	static int partition1(int l, int r, int x) {
		// a : arr[l....a-1]范围是<=x的区域
		// xi : 记录在<=x的区域上任何一个x的位置，哪一个都可以
		int a = l, xi = 0;
		for (int i = l; i <= r; i++) {
			if (arr[i] <= x) {
				swap(a, i);
				if (arr[a] == x) {
					xi = a;
				}
				a++;
			}
		}
		swap(xi, a - 1);
		return a - 1;
	}

	static void swap(int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	// 随机快速排序改进版(推荐)
	// 可以通过所有测试用例
	static void quickSort2(int l, int r) {
		if (l >= r) {
			return;
		}
		// 随机这一下，常数时间比较大
		// 但只有这一下随机，才能在概率上把快速排序的时间复杂度收敛到O(n * logn)
		int x = arr[l + (int) (randomUnit() * (r - l + 1))];
		partition2(l, r, x);
		// 为了防止底层的递归过程覆盖全局变量
		// 这里用临时变量记录first、last
		int left = first;
		int right = last;
		quickSort2(l, left - 1);
		quickSort2(right + 1, r);
	}

	// 荷兰国旗问题
	inline static int first, last;

	// 已知arr[l....r]范围上一定有x这个值
	// 划分数组 <x放左边，==x放中间，>x放右边
	// 把全局变量first, last，更新成==x区域的左右边界
	static void partition2(int l, int r, int x) {
		first = l;
		last = r;
		int i = l;
		while (i <= last) {
			if (arr[i] == x) {
				i++;
			} else if (arr[i] < x) {
				swap(first++, i++);
			} else {
				swap(i, last--);
			}
		}
	}

};

int main(){Code01_QuickSort::runDemo();return 0;}
