// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/single-number/

// Ported from src/class030/Code04_SingleNumber.java
#include <cstdint>
#include <iostream>
#include <vector>

// 数组中1种数出现了奇数次，其他的数都出现了偶数次
// 返回出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number/
struct Code04_SingleNumber {

	static int singleNumber(std::vector<int>& nums) {
		int eor = 0;
		for (int num : nums) {
			eor ^= num;
		}
		return eor;
	}

};
