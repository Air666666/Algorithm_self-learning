// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/single-number-iii/

// Ported from src/class030/Code05_DoubleNumber1.java
#include <cstdint>
#include <iostream>
#include <vector>

// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number-iii/
// 这是java版本的实现，本节课Code05_DoubleNumber2文件是C++版本的实现
struct Code05_DoubleNumber1 {

	static std::vector<int> singleNumber(std::vector<int>& nums) {
		int eor1 = 0;
		for (int num : nums) {
			// nums中有2种数a、b出现了奇数次，其他的数都出现了偶数次
			eor1 ^= num;
		}
		// eor1 : a ^ b
		// Brian Kernighan算法
		// 提取出二进制里最右侧的1
		std::uint32_t u = static_cast<std::uint32_t>(eor1);
		std::uint32_t rightOne = u & (0u-u);
		int eor2 = 0;
		for (int num : nums) {
			if ((num & rightOne) == 0) {
				eor2 ^= num;
			}
		}
		return std::vector<int> { eor2, eor1 ^ eor2 };
	}

};
