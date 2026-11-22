// Ported from algorithmzuo/algorithm-journey/src/class002/Experiment.java
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


// 一开始有100个人，每个人都有100元
// 在每一轮都做如下的事情 : 
// 每个人都必须拿出1元钱给除自己以外的其他人，给谁完全随机
// 如果某个人在这一轮的钱数为0，那么他可以不给，但是可以接收
// 发生很多很多轮之后，这100人的社会财富分布很均匀吗？
struct Experiment {
static double randomUnit(){static std::mt19937 gen(20261122);return std::generate_canonical<double,53>(gen);}


	static void runDemo() {
		std::cout << "一个社会的基尼系数是一个在0~1之间的小数" << "\n";
		std::cout << "基尼系数为0代表所有人的财富完全一样" << "\n";
		std::cout << "基尼系数为1代表有1个人掌握了全社会的财富" << "\n";
		std::cout << "基尼系数越小，代表社会财富分布越均衡；越大则代表财富分布越不均衡" << "\n";
		std::cout << "在2022年，世界各国的平均基尼系数为0.44" << "\n";
		std::cout << "目前普遍认为，当基尼系数到达 0.5 时" << "\n";
		std::cout << "就意味着社会贫富差距非常大，分布非常不均匀" << "\n";
		std::cout << "社会可能会因此陷入危机，比如大量的犯罪或者经历社会动荡" << "\n";
		std::cout << "测试开始" << "\n";
		int n = 100;
		int t = 1000000;
		std::cout << "人数 : " << n << "\n";
		std::cout << "轮数 : " << t << "\n";
		experiment(n, t);
		std::cout << "测试结束" << "\n";
	}

	// 完全按照说的来实验
	static void experiment(int n, int t) {
 if(n<2||t<0)throw std::invalid_argument("n must be >=2 and t nonnegative");
		std::vector<double> wealth = std::vector<double>(n);
		std::fill(wealth.begin(),wealth.end(),100);
		std::vector<bool> hasMoney = std::vector<bool>(n);
		for (int i = 0; i < t; i++) {
			std::fill(hasMoney.begin(),hasMoney.end(),false);
			for (int j = 0; j < n; j++) {
				if (wealth[j] > 0) {
					hasMoney[j] = true;
				}
			}
			for (int j = 0; j < n; j++) {
				if (hasMoney[j]) {
					int other = j;
					do {
						// (int) (randomUnit() * n);
						// int : 0 ~ n-1，等概率随机
						other = (int) (randomUnit() * n);
					} while (other == j);
					wealth[j]--;
					wealth[other]++;
				}
			}
		}
		std::sort(wealth.begin(),wealth.end());
		std::cout << "列出每个人的财富(贫穷到富有) : " << "\n";
		for (int i = 0; i < n; i++) {
			std::cout << (int) wealth[i] << " ";
			if (i % 10 == 9) {
				std::cout << "\n";
			}
		}
		std::cout << "\n";
		std::cout << "这个社会的基尼系数为 : " << calculateGini(wealth) << "\n";
	}

	// 计算基尼系数
	// 看代码就可以轻易知道怎么算的
	static double calculateGini(std::vector<double>& wealth) {
		double sumOfAbsoluteDifferences = 0;
		double sumOfWealth = 0;
		int n = static_cast<int>(wealth.size());
		for (int i = 0; i < n; i++) {
			sumOfWealth += wealth[i];
			for (int j = 0; j < n; j++) {
				sumOfAbsoluteDifferences += std::abs(wealth[i] - wealth[j]);
			}
		}
		return sumOfAbsoluteDifferences / (2 * n * sumOfWealth);
	}

};

int main(){Experiment::runDemo();return 0;}
