// Ported from class032/Code01_Bitset.java
#include <cstdint>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>


// 位图的实现
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// bool contains(int num)
struct Code01_Bitset {
 static double randomUnit(){static std::mt19937 gen(42);return std::generate_canonical<double,53>(gen);}

	// 位图的实现
	// 使用时num不要超过初始化的大小
	struct Bitset {
		std::vector<std::uint32_t> set;

		// n个数字 : 0~n-1
		Bitset(int n) {
			// a/b如果结果想向上取整，可以写成 : (a+b-1)/b
			// 前提是a和b都是非负数
			set = std::vector<std::uint32_t>((static_cast<std::size_t>(n) + 31) / 32);
		}

		void add(int num) {
			set[num / 32] |= std::uint32_t{1} << (num % 32);
		}

		void remove(int num) {
			set[num / 32] &= ~(std::uint32_t{1} << (num % 32));
		}

		void reverse(int num) {
			set[num / 32] ^= std::uint32_t{1} << (num % 32);
		}

		bool contains(int num) {
			return ((set[num / 32] >> (num % 32)) & 1) == 1;
		}

	};

	// 对数器测试
	static void runDemo() {
		int n = 1000;
		int testTimes = 10000;
		std::cout << "测试开始" << "\n";
		// 实现的位图结构
		Bitset bitSet(n);
		// 直接用HashSet做对比测试
		std::unordered_set<int> hashSet;
		std::cout << "调用阶段开始" << "\n";
		for (int i = 0; i < testTimes; i++) {
			double decide = randomUnit();
			// number -> 0 ~ n-1，等概率得到
			int number = (int) (randomUnit() * n);
			if (decide < 0.333) {
				bitSet.add(number);
				hashSet.insert(number);
			} else if (decide < 0.666) {
				bitSet.remove(number);
				hashSet.erase(number);
			} else {
				bitSet.reverse(number);
				if (hashSet.count(number)) {
					hashSet.erase(number);
				} else {
					hashSet.insert(number);
				}
			}
		}
		std::cout << "调用阶段结束" << "\n";
		std::cout << "验证阶段开始" << "\n";
		for (int i = 0; i < n; i++) {
			if (bitSet.contains(i) != hashSet.count(i)) {
				std::cout << "出错了!" << "\n";
			}
		}
		std::cout << "验证阶段结束" << "\n";
		std::cout << "测试结束" << "\n";
	};

};

int main(){Code01_Bitset::runDemo();return 0;}
