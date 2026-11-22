// Ported from src/class031/Code04_LeftToRightAnd.java
#include <cstdint>
#include <iostream>
#include <vector>

// 给你两个整数 left 和 right ，表示区间 [left, right]
// 返回此区间内所有数字 & 的结果
// 包含 left 、right 端点
// 测试链接 : https://leetcode.cn/problems/bitwise-and-of-numbers-range/
struct Code04_LeftToRightAnd {

	static int rangeBitwiseAnd(int left, int right) {
		while (left < right) {
			right -= right & -right;
		}
		return right;
	}

};
