// Ported from class032/Code02_DesignBitsetTest.java
#include <cstdint>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

// 位图的实现
// Bitset是一种能以紧凑形式存储位的数据结构
// Bitset(int n) : 初始化n个位，所有位都是0
// void fix(int i) : 将下标i的位上的值更新为1
// void unfix(int i) : 将下标i的位上的值更新为0
// void flip() : 翻转所有位的值
// bool all() : 是否所有位都是1
// bool one() : 是否至少有一位是1
// int count() : 返回所有位中1的数量
// std::string toString() : 返回所有位的状态
struct Code02_DesignBitsetTest {

	// 测试链接 : https://leetcode-cn.com/problems/design-bitset/
	struct Bitset {
		std::vector<std::uint32_t> set;
		int size;
		int zeros;
		int ones;
		bool reverse;

		Bitset(int n) {
			set = std::vector<std::uint32_t>((static_cast<std::size_t>(n) + 31) / 32);
			size = n;
			zeros = n;
			ones = 0;
			reverse = false;
		}

		// 把i这个数字加入到位图
		void fix(int i) {
			int index = i / 32;
			int bit = i % 32;
			if (!reverse) {
				// 位图所有位的状态，维持原始含义
				// 0 : 不存在
				// 1 : 存在
				if ((set[index] & (std::uint32_t{1} << bit)) == 0) {
					zeros--;
					ones++;
					set[index] |= (std::uint32_t{1} << bit);
				}
			} else {
				// 位图所有位的状态，翻转了
				// 0 : 存在
				// 1 : 不存在
				if ((set[index] & (std::uint32_t{1} << bit)) != 0) {
					zeros--;
					ones++;
					set[index] ^= (std::uint32_t{1} << bit);
				}
			}
		}

		// 把i这个数字从位图中移除
		void unfix(int i) {
			int index = i / 32;
			int bit = i % 32;
			if (!reverse) {
				if ((set[index] & (std::uint32_t{1} << bit)) != 0) {
					ones--;
					zeros++;
					set[index] ^= (std::uint32_t{1} << bit);
				}
			} else {
				if ((set[index] & (std::uint32_t{1} << bit)) == 0) {
					ones--;
					zeros++;
					set[index] |= (std::uint32_t{1} << bit);
				}
			}
		}

		void flip() {
			reverse = !reverse;
			int tmp = zeros;
			zeros = ones;
			ones = tmp;
		}

		bool all() {
			return ones == size;
		}

		bool one() {
			return ones > 0;
		}

		int count() {
			return ones;
		}

		std::string toString() {
			std::string builder;
			std::uint32_t number; int status;
 for (int i = 0, k = 0; i < size; k++) {
				number = set[k];
				for (int j = 0; j < 32 && i < size; j++, i++) {
					status = (number >> j) & 1;
					status ^= reverse ? 1 : 0;
					builder.push_back(status?'1':'0');
				}
			}
			return builder;
		}

	};

};
