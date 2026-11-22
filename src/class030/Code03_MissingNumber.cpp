// Ported from src/class030/Code03_MissingNumber.java
#include <cstdint>
#include <iostream>
#include <vector>

// 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/
struct Code03_MissingNumber {

	static int missingNumber(std::vector<int>& nums) {
		int eorAll = 0, eorHas = 0;
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			eorAll ^= i;
			eorHas ^= nums[i];
		}
		eorAll ^= static_cast<int>(nums.size());
		return eorAll ^ eorHas;
	}

};
