// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?

// Ported from algorithmzuo/algorithm-journey/src/class019/Code02_SpecifyAmount.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 展示acm风格的测试方式
// 子矩阵的最大累加和问题，不要求会解题思路，后面的课会讲
// 每一组测试都给定数据规模
// 需要任何空间都动态生成，在大厂笔试或者比赛中，这种方式并不推荐
// 测试链接 : https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code02_SpecifyAmount {

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);int n,m; while(std::cin>>n>>m){ std::vector<std::vector<int>> mat(n,std::vector<int>(m)); for(auto& row:mat)for(auto& x:row)std::cin>>x; std::cout<<maxSumSubmatrix(mat,n,m)<<"\n"; }}

	// 求子矩阵的最大累加和，后面的课会讲
	static int maxSumSubmatrix(std::vector<std::vector<int>>& mat, int n, int m) {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			// 需要的辅助数组，临时动态生成
			std::vector<int> arr = std::vector<int>(m);
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					arr[k] += mat[j][k];
				}
				max = std::max(max, maxSumSubarray(arr, m));
			}
		}
		return max;
	}

	// 求子数组的最大累加和，后面的课会讲
	static int maxSumSubarray(std::vector<int>& arr, int m) {
		int max = INT_MIN;
		int cur = 0;
		for (int i = 0; i < m; i++) {
			cur += arr[i];
			max = std::max(max, cur);
			cur = cur < 0 ? 0 : cur;
		}
		return max;
	}

};

int main(){Code02_SpecifyAmount::runDemo();return 0;}
