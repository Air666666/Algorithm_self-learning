// 原题测试 / 参考链接（保留上游原始地址）
// https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?

// Ported from algorithmzuo/algorithm-journey/src/class019/Code03_StaticSpace.java
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>

// 展示acm风格的测试方式
// 子矩阵的最大累加和问题，不要求会解题思路，后面的课会讲
// 每一组测试都给定数据规模
// 任何空间都提前生成好，一律都是静态空间，然后自己去复用，推荐这种方式
// 测试链接 : https://www.nowcoder.com/practice/cb82a97dcd0d48a7b1f4ee917e2c0409?
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


struct Code03_StaticSpace {

	// 题目给定的行的最大数据量
	inline static int MAXN = 201;

	// 题目给定的列的最大数据量
	inline static int MAXM = 201;

	// 申请这么大的矩阵空间，一定够用了
	// 静态的空间，不停复用
	inline static std::vector<std::vector<int>> mat = std::vector<std::vector<int>>(MAXN,std::vector<int>(MAXM));

	// 需要的所有辅助空间也提前生成
	// 静态的空间，不停复用
	inline static std::vector<int> arr = std::vector<int>(MAXM);

	// 当前测试数据行的数量是n
	// 当前测试数据列的数量是m
	// 这两个变量可以把代码运行的边界规定下来
	inline static int n, m;

	static void runDemo(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);while(std::cin>>n>>m){ if(n<1||n>MAXN||m<1||m>MAXM)return; for(int i=0;i<n;++i)for(int j=0;j<m;++j)std::cin>>mat[i][j]; std::cout<<maxSumSubmatrix()<<"\n"; }}

	// 求子矩阵的最大累加和，后面的课会讲
	static int maxSumSubmatrix() {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			// 因为之前的过程可能用过辅助数组
			// 为了让之前结果不干扰到这次运行，需要自己清空辅助数组需要用到的部分
			std::fill(arr.begin(),arr.begin()+m,0);
			for (int j = i; j < n; j++) {
				for (int k = 0; k < m; k++) {
					arr[k] += mat[j][k];
				}
				max = std::max(max, maxSumSubarray());
			}
		}
		return max;
	}

	// 求子数组的最大累加和，后面的课会讲
	static int maxSumSubarray() {
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

int main(){Code03_StaticSpace::runDemo();return 0;}
